<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2026-01-04 <a name="up"></a><br>   
<h1>Adapt the demo program to your own needs</h1>
<a href="/software/rcc_demo1/CUSTOMIZE_D.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# Introduction
For many applications of the RCC system, it is sufficient to specify the components used and their wiring in the [configuration file `src/dcc_config.h`](#x20) and to adapt the text of the information pages at program start in the [file `src/rcc_demo1.text.h`](#x30).   
The control program `rcc_demo1.cpp` does not normally need to be changed. If you want to extend the control system, you will find a detailed description of the demo software under [/software/rcc_demo1/DETAILS_E.md](/software/rcc_demo1/DETAILS_E.md).   

<a name="x20"></a>   

## The configuration file dcc_config.h
## Overview
In the configuration file `dcc_config.h` all essential project properties are defined such as   
* Version designation of the program (e.g. the date of the last update)   
* Information on the network used (WLAN, WiFi)   
* Implemented MQTT GET and SET messages   
* Properties of the display used   
* a possible offset for DCC addresses   
* the number of I²C I/O expanders, their names, addresses and start values   
* the number of railroad components and their type, name, DCC address, expander number and pin assignment as well as switching times   

## Example demo program “dcc_demo1”   
The electrical wiring of the components in particular must be known and mapped in the configuration file. The following wiring is assumed for the demo program `dcc_demo1`:   
* 2x I²C expanders with the names `pcf8574_out` (7-bit address 0x20) and `pcf8574_in` (7-bit address 0x21), i.e. one expander board for outputs and one expander board for inputs.   
* 1x uncoupler (name “UC”, DCC address 11) on pin 0 of the I²C expander   
* 1x two-way crossover (name “T2”, DCC address 21) on pins 1 and 2 of the I²C expanders   
* 1x three-way switch (two drives with the names “T3L” and “T3R”, DCC addresses 31 and 32) on pins 3, 4 and 5 of the I²C expanders   
* 1x traction current switch (name “DT”, DCC address 41) on pin 6 of the I²C expander   
* 1x flashing light (name “BL”, DCC address 51) on pin 7 of the I²C expander   

The following _Figure 1_ illustrates this data again.   

![circuit_rcc_demo1](../../images/480_rcc_demo1_i2c_circuit.png "circuit_rcc_demo1")   
_Figure 1: Wiring of the example `rcc_demo1`_   

The listing shows the configuration file for the demo program __with line numbers__. It then explains which lines need to be adapted.   

```   
1	//_____dcc_config.h______________________________khartinger_____
2	// Configure file for ESP32 railroad DCC decoder program
3	// rcc_demo1
4	//
5	// Created by Karl Hartinger, November 14, 2024
6	// Changes:
7	// 2024-11-28 Change program name
8	// 2025-01-03 Change TOPIC_BASE
9	// 2025-06-18 Add "signal"
10	// 2026-01-04 Add RC_TYPE_TX, RC_TYPE_DD
11	// Released into the public domain.
12	
13	#ifndef DCC_CONFIG_H
14	 #define DCC_CONFIG_H
15	 #include <Arduino.h>                  // String, int32_t
16	 #include "src/pcf8574/D1_class_PCF8574.h"
17	
18	//_______program version________________________________________
19	#define  VERSION_99     "2026-01-04 rcc_demo1"
20	#define  VERSION_99_1   "Version 2026-01-04"
21	
22	#define  INFOLINES_SEC  20             // time to show one page
23	
24	//_______Network and MQTT data__________________________________
25	#define  _USE_WIFI_     true
26	#define  _SSID_         "Raspi11"
27	#define  _PASS_         "12345678"
28	#define  _HOST_         "10.1.1.1"
29	#define  TOPIC_BASE     "rcc/demo1"
30	#define  TOPIC_GET      "?,help,version,ip,signal,topicbase,eeprom,byname,bydcc,status"
31	#define  TOPIC_SET      "topicbase,eeprom0"
32	#define  TOPIC_SUB      ""
33	#define  TOPIC_PUB      ""
34	
35	//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
36	#define  SCREEN_TITLE   "RCC_Demo1"
37	#define  SCREEN_LINE_MAX 6
38	#define  SCREEN_LINE_LEN 21
39	
40	//_______DCCex__________________________________________________
41	#define  DCC_OFFSET     4
42	
43	//_______Hardware: IO expander PCF8574__________________________
44	#define  IOEX_NUM       2              // number of IO expander
45	PCF8574  pcf8574_out(1,0x20,0xFF);     // 8 digital OUT
46	PCF8574  pcf8574_in (1,0x21,0xFF);     // 8 digital IN
47	PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out, &pcf8574_in}; // IO expander
48	
49	//_______Definitions for railroad components____________________
50	//.......values for every railroad component....................
51	// e.g. turnout, uncoupler, disconnectable track, ...
52	#define  NO_PIN         -1   // no pin @ PCF8574 (0...7)
53	#define  RC_TYPE_UC     1    // uncoupler (Entkuppler)
54	#define  RC_TYPE_TO     2    // turnout (Weiche)
55	#define  RC_TYPE_T3     3    // 3way turnout (Dreiwegweiche)
56	#define  RC_TYPE_DT     4    // disconnectable track (Fahrstrom)
57	#define  RC_TYPE_TX     5    // double slip turnout/switch (Doppelkreuzungsweiche)
58	#define  RC_TYPE_DD     6    // double pole, double throw (2x UM)
59	#define  RC_TYPE_BL     9    // blink light (Blinklicht)
60	
61	//.......All properties of a railroad component.................
62	struct strRcomp {
63	  int    type;          // RC_TYPE_TO, RC_TYPE_UC, RC_TYPE_DT
64	  String name;          // short name like T1, U1, D1, W1, E1...
65	  int    dcc;           // dcc address of the component
66	  int    outPCF;        // aIOEx index of PCF8574 output device
67	  int    outBitA;       // bit PCF8574 for turnout stright (Gerade)
68	  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
69	  int    inPCF;         // aIOEx index of PCF8574 input device
70	  int    inBitA;        // bit number at PCF8574 input stright=1
71	  int    inBitB;        // bit number at PCF8574 input curved=1
72	  int32_t msOn;         // ms on
73	  int32_t msOff;        // ms off
74	};
75	
76	//_______Railroad commands______________________________________
77	// railway components:  type,name (max 3 char),dcc,
78	//                      pIOEx-out-index,outBitA,outBitB, 
79	//                      pIOEx-in-index inBitA inBitB
80	//                      msOn,msOff
81	// railway component name max. 3 chars
82	// ------uncoupler (Entkuppler)---------------------------------
83	#define  RCOMP_1        RC_TYPE_UC,"UC", 11, EX0,PIN0,NO_PIN, EX1,PIN0,NO_PIN, 1500,0
84	// ------two way turnout (Zweiwegweiche = Standardweiche)-------
85	// Two expander pins A B to control 2way turnout (active low!)
86	// A=0: curved, B=0: stright
87	#define  RCOMP_2        RC_TYPE_TO,"T2", 21, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
88	//-------three way turnout (Dreiwegweiche)----------------------
89	// A=0: curved, B=0: stright (@ 3 pin: middle pin=0V -> stright)
90	#define  RCOMP_3L       RC_TYPE_T3,"T3L",31, EX0,PIN3,PIN4,   EX1,PIN3,PIN4, 500,0
91	#define  RCOMP_3R       RC_TYPE_T3,"T3R",32, EX0,PIN5,PIN4,   EX1,PIN5,PIN4, 500,0
92	//-------disconnectable track (Fahrstrom)-----------------------
93	#define  RCOMP_4        RC_TYPE_DT,"DT", 41, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 0,0
94	//-------blink light (Blinklicht)-------------------------------
95	#define  RCOMP_5        RC_TYPE_BL,"BL", 51, EX0,PIN7,NO_PIN, EX1,NO_PIN,NO_PIN, 500,500
96	
97	//...if you want to test TX and/or DD: replace RCOMP_2/RCOMP_4..
98	//-------double slip turnout/switch (Doppelkreuzungsweiche)-----
99	//#define  RCOMP_2        RC_TYPE_TX,"TX", 21, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
100	//-------double pole, double throw (2x UM)----------------------
101	//#define  RCOMP_4        RC_TYPE_DD,"DD", 41, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 0,0
102	
103	//.......Array of all railway components........................
104	#define  RCOMP_NUM      6
105	strRcomp aRcomp[RCOMP_NUM] = {
106	 {RCOMP_1},{RCOMP_2},{RCOMP_3L},{RCOMP_3R},{RCOMP_4},{RCOMP_5}
107	};
108	#endif
```   

## Necessary adjustments in the dcc_config.h file
The following table explains the meaning of the individual lines in the demo configuration file `dcc_config.h`. The column `Chg` (change) indicates whether the line(s) should be changed or not:   
 1 = must be changed or adapted   
 2 = line should be adjusted   
 3 = line can be changed   
 x = Do not change row(s)   

| Line    | Chg | Meaning |   
|:-------:|:---:|---------|   
| 19, 20  | 2 | Version number/modification date of the file. |   
| 22      | 3 | Number of seconds how long each info page should be displayed at startup (e.g. 20 seconds). |   
| 25      | 2 | Should a network (WLAN) be used? <br> true = ja, false = nein |   
| 26 - 28 | 2 | If a network is used: Name and password of the WLAN and IP of the computer on which the MQTT broker is running. |   
| 29      | __1__ | The basic topic under which the microcontroller sends or receives MQTT messages. |   
| 30      | x | All GET messages to which the microcontroller responds. |   
| 31      | x | All SET messages to which the microcontroller responds. |   
| 36      | 2 | Title on the OLED display. |   
| 41      | 3 | Offset of the DCC addresses, depending on the DCC transmitter (value can be 4 or 0). |   
| 44      | __1__ | Number of PCF8574 I²C I/O expander boards used (2, 4, 6 or 8).   |   
| 45 - 46 | 2 | One object for each PCF8574 board with I²C bus number (1), 7-bit I²C address (0x20, ...) and start value (usually 0xFF). |   
| 47      | __1__ | `*pIOEx[]` = Pointer array with the addresses of the PCF8574 board objects (don't forget the & sign in front of the names!). |   
| 49 - 74 | x | Definitions for the railroad components. They are only in this file for viewing or looking up. |   
| 76 - 101 | __1__ | Definition of structures for each individual railroad component. The structure of each line corresponds to the structure of lines 58 to 70.   
| 104      | __1__ | Number of railroad components. |   
| 105 - 107 | __1__ | `aRcomp[]` = Array with the structures of the individual railroad components. |   

<a name="x30"></a>   

# The text file dcc_demo1_text.h
The file `dcc_demo1_text.h` contains texts in German and English for the OLED display.   
The texts in lines 30 to 47 (German) and 70 to 85 (English) are to be adapted. In each case, 5 lines are displayed for 20 seconds (`INFOLINES_SEC`).   
The texts can also be deleted, in which case the constant `INFOLINES_NUM` must be set to 0:   
```   
#define  INFOLINES_NUM     0
```   

[Top of page](#up)
