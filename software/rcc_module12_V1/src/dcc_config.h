//_____dcc_config.h______________________________khartinger_____
// Configure file for ESP32 railroad DCC decoder program
// rcc_module12_V1
//
// Created by Karl Hartinger, February 05, 2025
// Changes:
// 2024-11-28 Change program name
// 2025-01-03 Change TOPIC_BASE
// Released into the public domain.

#ifndef DCC_CONFIG_H
 #define DCC_CONFIG_H
 #include <Arduino.h>                  // String, int32_t
 #include "src/pcf8574/D1_class_PCF8574.h"

//_______program version________________________________________
#define  VERSION_99     "2026-01-08 rcc_module12_V1"
#define  VERSION_99_1   "Version 2026-01-08"

#define  INFOLINES_SEC  20             // time to show one page

//_______Network and MQTT data__________________________________
#define  _USE_WIFI_     true
#define  _SSID_         "Raspi11"
#define  _PASS_         "12345678"
#define  _HOST_         "10.1.1.1"
#define  TOPIC_BASE     "rcc/module12"
#define  TOPIC_GET      "?,help,version,ip,signal,topicbase,eeprom,byname,bydcc,status"
#define  TOPIC_SET      "topicbase,eeprom0"
#define  TOPIC_SUB      ""
#define  TOPIC_PUB      ""

//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
#define  SCREEN_TITLE   "RCC Module 12"
#define  SCREEN_LINE_MAX 6
#define  SCREEN_LINE_LEN 21

//_______DCCex__________________________________________________
#define  DCC_OFFSET     4

//_______Hardware: IO expander PCF8574__________________________
#define  IOEX_NUM       4              // number of IO expander
PCF8574  pcf8574_0(1,0x20,0xFF);       // 8 digital OUT
PCF8574  pcf8574_1(1,0x21,0xFF);       // 8 digital IN
PCF8574  pcf8574_2(1,0x22,0xFF);       // 8 digital OUT
PCF8574  pcf8574_3(1,0x23,0xFF);       // 8 digital IN

PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_0, &pcf8574_1, &pcf8574_2, &pcf8574_3}; // IO expander

//_______Definitions for railroad components____________________
//.......values for every railroad component....................
// e.g. turnout, uncoupler, disconnectable track, ...
#define  NO_PIN         -1   // no pin @ PCF8574 (0...7)
#define  RC_TYPE_UC     1    // uncoupler (Entkuppler)
#define  RC_TYPE_TO     2    // turnout (Weiche)
#define  RC_TYPE_T3     3    // 3way turnout (Dreiwegweiche)
#define  RC_TYPE_DT     4    // disconnectable track (Fahrstrom)
#define  RC_TYPE_TX     5    // double slip turnout/switch (Doppelkreuzungsweiche)
#define  RC_TYPE_DD     6    // double pole, double throw (2x UM)
#define  RC_TYPE_BL     9    // blink light (Blinklicht)

//.......All properties of a railroad component.................
struct strRcomp {
  int    type;          // RC_TYPE_TO, RC_TYPE_UC, RC_TYPE_DT
  String name;          // short name like T1, U1, D1, W1, E1...
  int    dcc;           // dcc address of the component
  int    outPCF;        // aIOEx index of PCF8574 output device
  int    outBitA;       // bit PCF8574 for turnout stright (Gerade)
  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
  int    inPCF;         // aIOEx index of PCF8574 input device
  int    inBitA;        // bit number at PCF8574 input stright=1
  int    inBitB;        // bit number at PCF8574 input curved=1
  int32_t msOn;         // ms on
  int32_t msOff;        // ms off
};

//_______Railroad commands______________________________________
// railway components:  type,name (max 3 char),dcc,
//                      pIOEx-out-index,outBitA,outBitB, 
//                      pIOEx-in-index inBitA inBitB
//                      msOn,msOff
// railway component name max. 3 chars
//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_1        RC_TYPE_DT,"G1A", 129, EX0,PIN0,NO_PIN, EX1,PIN0,NO_PIN, 0,0
//-------three way turnout (Dreiwegweiche)----------------------
// A=0: curved, B=0: stright (@ 3 pin: middle pin=0V -> stright)
#define  RCOMP_2L       RC_TYPE_T3,"TWL",121, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
#define  RCOMP_2R       RC_TYPE_T3,"TWR",122, EX0,PIN3,PIN2,   EX1,PIN3,PIN2, 500,0
// ------two way turnout (Zweiwegweiche = Standardweiche)-------
// Two expander pins A B to control 2way turnout (active low!)
// A=0: curved, B=0: stright
#define  RCOMP_3        RC_TYPE_TO,"T1", 123, EX0,PIN4,PIN5,   EX1,PIN4,PIN5, 500,0
// ------uncoupler (Entkuppler)---------------------------------
#define  RCOMP_4        RC_TYPE_UC,"E1", 124, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 1500,0

//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_5        RC_TYPE_DT,"G1", 125, EX2,PIN4,NO_PIN, EX3,PIN4,NO_PIN, 0,0
//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_6        RC_TYPE_DT,"G2", 126, EX2,PIN3,NO_PIN, EX3,PIN3,NO_PIN, 0,0
//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_7        RC_TYPE_DT,"G3", 127, EX2,PIN2,NO_PIN, EX3,PIN2,NO_PIN, 0,0
// ------two way turnout (Zweiwegweiche = Standardweiche)-------
// Two expander pins A B to control 2way turnout (active low!)
// A=0: curved, B=0: stright
#define  RCOMP_8        RC_TYPE_TO,"T2", 128, EX2,PIN0,PIN1,   EX3,PIN0,PIN1, 500,0

//.......Array of all railway components........................
#define  RCOMP_NUM      9
strRcomp aRcomp[RCOMP_NUM] = {
 {RCOMP_1},{RCOMP_2L},{RCOMP_2R},{RCOMP_3},{RCOMP_4},{RCOMP_5},{RCOMP_6},{RCOMP_7},{RCOMP_8}
};
#endif