//_____rcc_demo1a.cpp____________________________khartinger_____
// This program for an ESP32 is used to test various self-built 
// model railroad switching blocks. The blocks are controlled 
// via the I/O pins of two I²C PCF8574 I/O expanders, whereby 
// the PCF8574 with the I2C address 0x20 (IO expander #0) is 
// used for control and the PCF8574 with the I2C address 0x21 
// (IO expander #1) for feedback. The IO pins for control and 
// feedback each have the same pin number.
//
// 1. DCC 11, IO expander pin 0: Decoupler (uncoupler)
// 2. DCC 21, IO expander pin 1,2: Two-way switch 
//    (with limit switch)
// 3. DCC 31,32, IO expander pin 3,4,5: Three-way switch
//    (with limit switching)
// 4. DCC 41, IO expander pin 6: Disconnectable track
// 5. DCC 51, IO expander pin 7: Flashing light
//
// The switching status of the components is shown 
// on a 1.54” OLED display.
//
// A button on pin D6 (IO19) can be used to skip the individual
// pages of the information display or to search for the WLAN.
//
// If you press the button for one second during the program 
// run, a reset is triggered. This can be used, for example, 
// to activate the WLAN when starting up again.
//
// All project-specific data, such as WLAN access, MQTT commands
// and hardware properties, are saved in a configuration file
// `dcc_config.h`.
//
// Required hardware
// Electronic components
// 1. ESP32 D1 mini
// 2. 1x do-it-yourself board “Shield_I2C_5V_3V3”: 
//    Connection for the two I2C buses
// 3. 1x DIY board “Shield_5V_DCC_6pol”: Power supply with 5V,
//    DCC signal and connection for button on pin D6 (IO19)
// 4. 1x OLED display with SSD1309 controller (e.g. 1.54“ or
//    2.4” displays with 128x64 pixel resolution)
// 5. 2x I²C expander boards PCF8574 with the (7-bit) 
//    addresses 0x20 and 0x21
// 6. push-button on pin D6 (IO19) with pull-up resistor 
//    (e.g. 10 kOhm) to 3.3V (or a wire)   
//
// Electrical components
// The electrical components depend on what you want to test.
// Example three-way crossover:
// 1. a three-way crossover with limit switching   
// 2. self-assembly block “RW_5V_W3” consisting of the two 
//    circuit boards `RW_5V_W3_STRG` and `RW_5V_W3_LED`
//    for controlling the points with 5V   
// 3. a transformer with 16V alternating voltage (V+, V-)
// 4. a DCC source for sending turnout commands (e.g. Roco 
//    MultiMAUS with digital amplifier 10764 and 
//    power supply 10850)
// 5. a 5V power supply   
//
// Class SimpleMqtt extends class PubSubClient for easy use.
// All commands of the PubSubClient class can still be used.
// Note: When PubSubClient lib is installed,
//       delete PubSubClient files in directory src/simplemqtt
// Important: Example needs a MQTT-broker!
// Created by Karl Hartinger, November 02, 2024
// Changes:
// 2024-11-14 2-way-turnout number 1=straight <-> 2=curved changed
// 2024-11-28 Change program name
// 2025-01-03 Change TOPIC_BASE, add #define CON_...
// 2025-01-18 setup() add s2oled, prepareScreenLine4to6()
// 2025-06-18 Add "signal", DEBUG_99_SHOW_ALL
// 2026-01-08 Update ../get bydcc, byname, one value
//            Add send MQTT-message if a value has changed
//            Add ../get status, RC_TYPE_TX, RC_TYPE_DCC
// 2026-01-10 Add ../set/wlan: get wlan data from eeprom
// 2026-02-24 Add ../get mac, setWiFiHostName()
// 2026-08-15 Redesign in multi files
// Released into the public domain.

 //#define D1MINI          1              // ESP8266 D1mini +pro
#define  ESP32D1        2                   // ESP32 D1mini
#define  LANGUAGE      'd'                  // 'd' or 'e'

#include "rcc_demo1a_text.h"                // AFTER LANGUAGE
#include "pre_config.h"                     // common defines
#include "dcc_config.h"                     // hardware defines
#include <DccAccessoryDecoder.h>            // receive dcc commands
#include "src/rcc_dcc.h"                    // struct DccCommand
#include "src/rcc_hardwareaccess.h"         // IO Accesses
#include "src/rcc_display.h"                // 1.54" display
#include "src/rcc_mqtt.h"                   // MQTT get/set
#include "src/rcc_command.h"                // build commands
#include "src/rcc_statemachine.h"           // statemachine

extern Screen154    screen_;                // rcc_screen.cpp
extern Statemachine stm;                    // rcc_statemachine.cpp
extern DccCommand   lastDcc;                // rcc_dcc.cpp

// *************************************************************
// Standard Functions
// *************************************************************

//_____SETUP____________________________________________________
void setup() {
 //------Serial, just for debug---------------------------------
 if(DEBUG_99) {
  Serial.begin(115200);
  Serial.flush();
  Serial.println("\nsetup(): --Start--");
 }
 //------init---------------------------------------------------
 initHardwareAccess1(screen_);
 initDisplay1();
 initHardwareAccess2(screen_);
 // NOTE: If an expected PCF8574 is not detected, 
 //       startup is stopped until the hardware is available.
 initRccWiFi(screen_);
 //------DCC: register pin and callback routine-----------------
 DccAccessoryDecoder.begin(PIN_DCC, onAccessoryPacket);
 if(DEBUG_99) Serial.println("setup(): DccAccessoryDecoder OK");
 //------Finish setup-------------------------------------------
 if(DEBUG_99) Serial.println("setup(): --Finished--\n");
}

//_____LOOP_____________________________________________________
void loop() {
 //======(1) do at the beginning of the loop ...================
 int32_t state=stm.loopBegin();             // current state
 String s1;                                 // help value
 String sSerial=String(state);              // collect serial output
 //======(2) do, independent on the network, ...================
 DccAccessoryDecoder.loop();
 loopResetHandling(sSerial);
 loopRcmdReplaceStateNow(state, stm);
 int iRcomp_=updateInputValues();            // get input
 loopUpdateDisplay(iRcomp_, state, stm);
 //======(3) process mqtt actions===============================
 loopMqtt(sSerial);
 //======(4) do things after mqtt access========================
 s1=loopActOnRcmd(state, stm);               // 
 if(s1!="") sSerial+=" | "+s1;
 //======(5) do at the end of the loop ...======================
  if(lastDcc.address>=0 && lastDcc.address<2048) {
  sSerial+=" | DCC Adresse="+String(lastDcc.address)+" Wert="+String(lastDcc.value);
  lastDcc.address=-1;
 }
 uint32_t ms=stm.loopEnd();                   // state end
 //------print serial data--------------------------------------
 if(DEBUG_99) { sSerial+=" | "; sSerial+=String(ms);
  if(ms>STATE_TICK_MS) sSerial+=" ms-Too long!!";
  else sSerial+=" ms";
  if(DEBUG_99_SHOW_ALL) Serial.println(sSerial);
  else {
   if(sSerial.length()>14) Serial.println(sSerial);
  }
 }
}