//_____dcc_config.h______________________________khartinger_____
// Configure file for ESP32 railroad DCC decoder program
// rcc_demo1a
//
// Created by Karl Hartinger, November 14, 2024
// Changes:
// 2024-11-28 Change program name
// 2025-01-03 Change TOPIC_BASE
// 2025-06-18 Add "signal"
// 2026-01-08 Add RC_TYPE_TX, RC_TYPE_DD
// 2026-02-24 Add mac
// 2026-08-15 Add dcc_config.cpp, Redesign constexpr, ...
// Released into the public domain.

#ifndef DCC_CONFIG_H
 #define DCC_CONFIG_H
 #include "pre_config.h"                    // common defines
 #include <Arduino.h>                       // String, int32_t
 #include "src/pcf8574/D1_class_PCF8574.h"  // PCF8574
 #include "src/statemachine/D1_class_Statemachine.h" // STATE_NONE

//_______show debug information_________________________________
#define  DEBUG_99       true                // true OR false
#define  DEBUG_99_SHOW_ALL  false           // true OR false

//_______program version________________________________________
constexpr char VERSION_99[] = "2026-08-15 rcc_demo1a";
constexpr char VERSION_99_1[] = "Version 2026-08-15";

//_______Network data___________________________________________
#define _USE_WIFI_      true
constexpr char _SSID_[] = "Raspi11";
constexpr char _PASS_[] = "12345678";
constexpr char _HOST_[] = "10.1.1.1";
constexpr char _ESP_NAME_[] = "rccdemo1";

//_______MQTT data______________________________________________
constexpr char TOPIC_BASE[] = "rcc/demo1";
constexpr char TOPIC_GET[] = "?,help,version,mac,ip,signal,topicbase,eeprom,byname,bydcc,status";
constexpr char TOPIC_SET[] = "topicbase,wlan,eeprom0";
constexpr char TOPIC_SUB[] = "";
constexpr char TOPIC_PUB[] = "";

//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
constexpr char SCREEN_TITLE[] = "RCC_Demo1 a";
constexpr int  SCREEN_LINE_MAX = 6;
constexpr int  SCREEN_LINE_LEN = 21;
constexpr int  SHOW_INFOPAGE_SEC = 20; // time to show one page

//_______DCCex__________________________________________________
constexpr int  DCC_OFFSET = 4;

//_______Software: Railroad commands____________________________
//.......PCF8574 lines B A to control 2way turnout (active low!)
constexpr int CMD_NONE = -1;      // no command
constexpr int CMD_BIT_A_0 = 1;    // set bit A=0 (inverted)
constexpr int CMD_BIT_A_1 = 2;    // set bit A=1 (inverted)
constexpr int CMD_BIT_BA_00 = 3;  // bits BA = 00
constexpr int CMD_BIT_BA_10 = 4;  // bits BA = 10
constexpr int CMD_BIT_BA_01 = 5;  // bits BA = 01
constexpr int CMD_BIT_BA_11 = 6;  // bits BA = 11
constexpr int CMD_BLINK = 7;      // start blinking light
constexpr int CMD_BLINK_END =8;   // stop blinking light

//.......All properties of a railroad command...................
// command: 0=out, 1=straight, 2=curved, 3=undefined (switching)
struct strRcmd {
  int     iCmd;         // command - what to do (now)
  int     inValue;      // current input value
  bool    inValueChanged; // true=yes, value has changed
  int32_t stateToDo;    // in which state should command be executed?
  int32_t stateOffset;  // additional state offset value
  int     iCmdOffset;   // command - what to do @ offset state
};
//.......Default values for all railroad commands...............
#define RCMD_NONE       CMD_NONE,-1,STATE_NONE,STATE_NONE,CMD_NONE

//_______Hardware: IO expander PCF8574__________________________
// Assumption: IO boards on I2C bus #1, initial value 0xFF.
// Changes can be made in file dcc_config.cpp

// ***** CHECK this! *******************************************
#define  IOEX_NUM       2         // number of IO expander 2|4|6|8

//.......Suggested addresses....................................
#define  IOEX_ADDRESS1  0x20      // pcf8574_out #1
#define  IOEX_ADDRESS2  0x21      // pcf8574_in  #1
#define  IOEX_ADDRESS3  0x22      // pcf8574_out #2
#define  IOEX_ADDRESS4  0x23      // pcf8574_in  #2
#define  IOEX_ADDRESS5  0x24      // pcf8574_out #3
#define  IOEX_ADDRESS6  0x25      // pcf8574_in  #3
#define  IOEX_ADDRESS7  0x26      // pcf8574_out #4
#define  IOEX_ADDRESS8  0x27      // pcf8574_in  #4

//_______Definitions for railroad components____________________
//.......values for every railroad component....................
// e.g. turnout, uncoupler, disconnectable track, ...
constexpr int  NO_PIN = -1;       // no pin @ PCF8574 (0...7)
constexpr int  RC_TYPE_UC = 1;    // uncoupler (Entkuppler)
constexpr int  RC_TYPE_TO = 2;    // turnout (Weiche)
constexpr int  RC_TYPE_T3 = 3;    // 3way turnout (Dreiwegweiche)
constexpr int  RC_TYPE_DT = 4;    // disconnectable track (Fahrstrom)
constexpr int  RC_TYPE_TX = 5;    // double slip turnout/switch (Doppelkreuzungsweiche)
constexpr int  RC_TYPE_DD = 6;    // double pole, double throw (2x UM)
constexpr int  RC_TYPE_BL = 9;    // blink light (Blinklicht)

//.......All properties of a railroad component.................
struct strRcomp {
  int    type;          // RC_TYPE_TO, RC_TYPE_UC, RC_TYPE_DT
  String name;          // short name like T1, U1, D1, W1, E1...
  int    dcc;           // dcc address of the component
  int    outPCF;        // aIOEx index of PCF8574 output device
  int    outBitA;       // bit PCF8574 for turnout straight (Gerade)
  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
  int    inPCF;         // aIOEx index of PCF8574 input device
  int    inBitA;        // bit number at PCF8574 input straight=1
  int    inBitB;        // bit number at PCF8574 input curved=1
  int32_t msOn;         // ms on
  int32_t msOff;        // ms off
};

// ***** CHECK this! *******************************************
//_______Railroad components____________________________________
/**
 * @brief Definition of Railroad Components
 * 
 * railroad components: type,name (max 3 char),dcc,
 *                      pIOEx-out-index,outBitA,outBitB, 
 *                      pIOEx-in-index inBitA inBitB
 *                      msOn,msOff
 * railroad component name max. 3 chars
*/
// ------uncoupler (Entkuppler)---------------------------------
#define  RCOMP_1   RC_TYPE_UC,"UC", 11, EX0,PIN0,NO_PIN, EX1,PIN0,NO_PIN, 1500,0
// ------two way turnout (Zweiwegweiche = Standardweiche)-------
// Two expander pins A B to control 2way turnout (active low!)
// A=0: curved, B=0: straight
#define  RCOMP_2   RC_TYPE_TO,"T2", 21, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
//-------three way turnout (Dreiwegweiche)----------------------
// A=0: curved, B=0: straight (@ 3 pin: middle pin=0V -> straight)
#define  RCOMP_3L  RC_TYPE_T3,"T3L",31, EX0,PIN3,PIN4,   EX1,PIN3,PIN4, 500,0
#define  RCOMP_3R  RC_TYPE_T3,"T3R",32, EX0,PIN5,PIN4,   EX1,PIN5,PIN4, 500,0
//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_4   RC_TYPE_DT,"DT", 41, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 0,0
//-------blink light (Blinklicht)-------------------------------
#define  RCOMP_5   RC_TYPE_BL,"BL", 51, EX0,PIN7,NO_PIN, EX1,NO_PIN,NO_PIN, 500,500

//...if you want to test TX and/or DD: replace RCOMP_2/RCOMP_4..
//-------double slip turnout/switch (Doppelkreuzungsweiche)-----
//#define  RCOMP_2   RC_TYPE_TX,"TX", 21, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
//-------double pole, double throw (2x UM)----------------------
//#define  RCOMP_4   RC_TYPE_DD,"DD", 41, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 0,0

//.......Preparing the Array of all railroad components..........
#define  RCOMP_NUM  6
#define  RCOMP_LIST {RCOMP_1},{RCOMP_2},{RCOMP_3L},{RCOMP_3R},{RCOMP_4},{RCOMP_5}

#endif