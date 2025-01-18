<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-01-05 <a name="up"></a><br>   
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
9	// Released into the public domain.
10	
11	#ifndef DCC_CONFIG_H
12	 #define DCC_CONFIG_H
13	 #include <Arduino.h>                  // String, int32_t
14	 #include "src/pcf8574/D1_class_PCF8574.h"
15	
16	//_______program version________________________________________
17	#define  VERSION_99     "2025-01-03 rcc_demo1"
18	#define  VERSION_99_1   "Version 2025-01-03"
19	
20	#define  INFOLINES_SEC  20             // time to show one page
21	
22	//_______Network and MQTT data__________________________________
23	#define  _USE_WIFI_     true
24	#define  _SSID_         "Raspi11"
25	#define  _PASS_         "12345678"
26	#define  _HOST_         "10.1.1.1"
27	#define  TOPIC_BASE     "rcc/demo1"
28	#define  TOPIC_GET      "?,help,version,ip,topicbase,eeprom,byname,bydcc"
29	#define  TOPIC_SET      "topicbase,eeprom0"
30	#define  TOPIC_SUB      ""
31	#define  TOPIC_PUB      ""
32	
33	//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
34	#define  SCREEN_TITLE   "RCC_Demo1"
35	#define  SCREEN_LINE_MAX 6
36	#define  SCREEN_LINE_LEN 21
37	
38	//_______DCCex__________________________________________________
39	#define  DCC_OFFSET     4
40	
41	//_______Hardware: IO expander PCF8574__________________________
42	#define  IOEX_NUM       2              // number of IO expander
43	PCF8574  pcf8574_out(1,0x20,0xFF);     // 8 digital OUT
44	PCF8574  pcf8574_in (1,0x21,0xFF);     // 8 digital IN
45	PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out, &pcf8574_in}; // IO expander
46	
47	//_______Definitions for railroad components____________________
48	//.......values for every railroad component....................
49	// e.g. turnout, uncoupler, disconnectable track, ...
50	#define  NO_PIN         -1   // no pin @ PCF8574 (0...7)
51	#define  RC_TYPE_UC     1    // uncoupler (Entkuppler)
52	#define  RC_TYPE_TO     2    // turnout (Weiche)
53	#define  RC_TYPE_T3     3    // 3way turnout (Dreiwegweiche)
54	#define  RC_TYPE_DT     4    // disconnectable track (Fahrstrom)
55	#define  RC_TYPE_BL     5    // blink light (Blinklicht)
56	
57	//.......All properties of a railroad component.................
58	struct strRcomp {
59	  int    type;          // RC_TYPE_TO, RC_TYPE_UC, RC_TYPE_DT
60	  String name;          // short name like T1, U1, D1, W1, E1...
61	  int    dcc;           // dcc address of the component
62	  int    outPCF;        // aIOEx index of PCF8574 output device
63	  int    outBitA;       // bit PCF8574 for turnout stright (Gerade)
64	  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
65	  int    inPCF;         // aIOEx index of PCF8574 input device
66	  int    inBitA;        // bit number at PCF8574 input stright=1
67	  int    inBitB;        // bit number at PCF8574 input curved=1
68	  int32_t msOn;         // ms on
69	  int32_t msOff;        // ms off
70	};
71	
72	//_______Railroad commands______________________________________
73	// railway components:  type,name (max 3 char),dcc,
74	//                      pIOEx-out-index,outBitA,outBitB, 
75	//                      pIOEx-in-index inBitA inBitB
76	//                      msOn,msOff
77	// railway component name max. 3 chars
78	// ------uncoupler (Entkuppler)---------------------------------
79	#define  RCOMP_1        RC_TYPE_UC,"UC", 11, EX0,PIN0,NO_PIN, EX1,PIN0,NO_PIN, 1500,0
80	// ------two way turnout (Zweiwegweiche = Standardweiche)-------
81	// Two expander pins B A to control 2way turnout (active low!)
82	// A=0: curved, B=0: stright
83	#define  RCOMP_2        RC_TYPE_TO,"T2", 21, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0
84	//-------three way turnout (Dreiwegweiche)----------------------
85	// A=0: curved, B=0: stright (@ 3 pin: middle pin=0V -> stright)
86	#define  RCOMP_3L       RC_TYPE_T3,"T3L",31, EX0,PIN3,PIN4,   EX1,PIN3,PIN4, 500,0
87	#define  RCOMP_3R       RC_TYPE_T3,"T3R",32, EX0,PIN5,PIN4,   EX1,PIN5,PIN4, 500,0
88	//-------disconnectable track (Fahrstrom)-----------------------
89	#define  RCOMP_4        RC_TYPE_DT,"DT", 41, EX0,PIN6,NO_PIN, EX1,PIN6,NO_PIN, 0,0
90	//-------blink light (Blinklicht)-------------------------------
91	#define  RCOMP_5        RC_TYPE_BL,"BL", 51, EX0,PIN7,NO_PIN, EX1,PIN7,NO_PIN, 500,500
92	
93	//.......Array of all railway components........................
94	#define  RCOMP_NUM      6
95	strRcomp aRcomp[RCOMP_NUM] = {
96	 {RCOMP_1},{RCOMP_2},{RCOMP_3L},{RCOMP_3R},{RCOMP_4},{RCOMP_5}
97	};
98	#endif
```   

## Necessary adjustments in the dcc_config.h file
The following table explains the meaning of the individual lines in the demo configuration file `dcc_config.h`. The column `Chg` (change) indicates whether the line(s) should be changed or not:   
 1 = must be changed or adapted   
 2 = line should be adjusted   
 3 = line can be changed   
 x = Do not change row(s)   

| Line    | Chg | Meaning |   
|:-------:|:---:|---------|   
| 17, 18  | 2 | Version number/modification date of the file. |   
| 20      | 3 | Number of seconds how long each info page should be displayed at startup (e.g. 20 seconds). |   
| 23      | 2 | Should a network (WLAN) be used? <br> true = ja, false = nein |   
| 24 - 26 | 2 | If a network is used: Name and password of the WLAN and IP of the computer on which the MQTT broker is running. |   
| 27      | __1__ | The basic topic under which the microcontroller sends or receives MQTT messages. |   
| 28      | x | All GET messages to which the microcontroller responds. |   
| 29      | x | All SET messages to which the microcontroller responds. |   
| 34      | 2 | Title on the OLED display. |   
| 39      | 3 | Offset of the DCC addresses, depending on the DCC transmitter (value can be 4 or 0). |   
| 42      | __1__ | Number of PCF8574 I²C I/O expander boards used (2, 4, 6 or 8).   |   
| 43 - 44 | 2 | One object for each PCF8574 board with I²C bus number (1), 7-bit I²C address (0x20, ...) and start value (usually 0xFF). |   
| 45      | __1__ | `*pIOEx[]` = Pointer array with the addresses of the PCF8574 board objects (don't forget the & sign in front of the names!). |   
| 47 - 70 | x | Definitions for the railroad components. They are only in this file for viewing or looking up. |   
| 72 - 89 | __1__ | Definition of structures for each individual railroad component. The structure of each line corresponds to the structure of lines 58 to 70.   
| 94      | __1__ | Number of railroad components. |   
| 95 - 97 | __1__ | `aRcomp[]` = Array with the structures of the individual railroad components. |   

<a name="x30"></a>   

# The text file dcc_demo1_text.h
The file `dcc_demo1_text.h` contains texts in German and English for the OLED display.   
The texts in lines 30 to 47 (German) and 70 to 85 (English) are to be adapted. In each case, 5 lines are displayed for 20 seconds (`INFOLINES_SEC`).   
The texts can also be deleted, in which case the constant `INFOLINES_NUM` must be set to 0:   
```   
#define  INFOLINES_NUM     0
```   

[Top of page](#up)
