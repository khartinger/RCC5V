//_____rcc_demo1_________________________________khartinger_____
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
// 2024-11-14 2-way-turnout number 1=stright <-> 2=curved changed
// 2024-11-28 change program name
// Released into the public domain.

// #include <Arduino.h>
// #include "src/pcf8574/D1_class_PCF8574.h"
//#define D1MINI          1              // ESP8266 D1mini +pro
#define  ESP32D1        2                   // ESP32 D1mini
#define  DEBUG_99       true                // true OR false
#define  LANGUAGE      'd'                  // 'd' or 'e'
#include "rcc_demo1_text.h"                     // AFTER LANGUAGE
#include "pre_config.h"                     // common defines
#include "dcc_config.h"                     // hardware defines
#include <DccAccessoryDecoder.h>
#include "src/statemachine/D1_class_Statemachine.h"
#include "src/simplemqtt/D1_class_SimpleMqtt.h"
#include "src/screen154/D1_class_Screen154.h"

//_______declare method(s), if necessary________________________
String setRcompCmd(int iRcomp, int iCmdValue, String sReturn);
String actOnCmdHardware(int iCmd_, int iOutPCF_, 
                        int outBitA_, int outBitB_, int more_);
void showLine(int line_, String text_);
void showLine6WaitMaxXXs(int iSec, String line6);

//_______Global values and hardware_____________________________
#define  PIN_DCC        18                  // 18=D5
#define  PIN_BUTTON     19                  // 19=D6

//_______Global values for connection state_____________________
bool     bUseWiFi=false;
int      iConn=CON_UNKNOWN;                // WiFi unknown
int      iConnOld=CON_UNKNOWN;             // WiFi unknown

//_______Global values for updating the screen__________________
#define  NO_GROUP       -1                  // no group to show
//       buffer for lines for screen update
String   aScreenText[SCREEN_LINE_MAX];
//       sign per line: 1=normal display, -1=inverted
int      aScreenSign[SCREEN_LINE_MAX]={1,1,1,-1,1,1};
Screen154 screen_;
//-------Are info lines defined?--------------------------------
#ifdef INFOLINES
 String   infolines[INFOLINES_NUM] = INFOLINES;
#else
 #define INFOLINES_NUM  0
 String   infolines[] = {};
#endif

//_______Railroad commands______________________________________
//.......PCF8574 lines B A to control 2way turnout (active low!)
#define  CMD_NONE       -1   // no command
#define  CMD_BITA_ON    1    // set bit A=0 (inverted)
#define  CMD_BITA_OFF   2    // set bit A=1 (inverted)
#define  CMD_BIT2_ON    3    // bits BA = 00
#define  CMD_BIT2_A     4    // bits BA = 10
#define  CMD_BIT2_B     5    // bits BA = 01
#define  CMD_BIT2_OFF   6    // bits BA = 11
#define  CMD_BLINK      7    // start blink light
#define  CMD_BLINK_END  8    // stopp blink light


//.......All properties of a railroad command...................
// command: 0=out, 1=stright, 2=curved, 3=undefined (switching)
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
//.......Array of all current railway commands..................
// As there should only be one active command for one 
// component, aRcomp[] and aRcmd[] have the same size and the 
// same index for a command.
strRcmd aRcmd[RCOMP_NUM];

//_______State machine__________________________________________
#define STATE_MAX           180000     // 180000*20ms = 1 hour
#define STATE_DELAY             20     // state delay in ms
#define STATES_SCREEN_REFRESH   251     // 251*20ms=5,2s
#define STATES_SHOW_SCREEN_MIN  75     // show screen min 1.5 sec
#define STATES_BLINK            25     // 25*20ms =0,5s
#define STATES_BEFORE_RESET     50     // 25*20ms =1s
Statemachine stm(STATE_MAX, STATE_DELAY); //1..36000

//_______dcc access_____________________________________________
unsigned int dccAddress=0;             // dcc address
int dccValue=-1;                       // dcc input value

// *************************************************************
// DCC Callback Function
// *************************************************************

//_______DCC request____________________________________________
// Generate a command if the DCC address received belongs to a 
// component of the RW module.
// uses : aRcomp[]
// calls: setRcompCmd()
void onAccessoryPacket(unsigned int linearDecoderAddress, bool enabled) {
 digitalWrite(BUILTIN_LED, enabled ? 1 : 0);
 dccAddress=(int)linearDecoderAddress + DCC_OFFSET;
 dccValue=enabled ? 1 : 0;
 //------is it a DCC address for this module?-------------------
 for(int i=0; i<RCOMP_NUM; i++) {
  if(aRcomp[i].dcc==dccAddress) {
   //----railroad component found-------------------------------
   setRcompCmd(i, dccValue, "");
  }
 }
 if(DEBUG_99) {
  Serial.print("***Change in Accessory: ");
  Serial.print(dccAddress);
  Serial.print(" -> ");
  Serial.print(dccValue);
  Serial.println("***");
 }
}

// *************************************************************
// MQTT Functions
// *************************************************************

#if _USE_WIFI_ == true
 //_______MQTT communication_____________________________________
 //SimpleMqtt client("..ssid..", "..password..","mqttservername");
 //SimpleMqtt client("Raspi11", "12345678","10.1.1.1", TOPIC_BASE);
 SimpleMqtt client(String(_SSID_), String(_PASS_),
                   String(_HOST_), String(TOPIC_BASE));

//_______MQTT: inspect all subscribed incoming messages_________
void callback(char* topic, byte* payload, unsigned int length)
{
 client.callback_(topic, payload, length);  // must be called!
}

//_______Answer get requests____________________________________
// sPayload: payload to message from TOPIC_GET
// auto answer: for help (+), version, ip (can be overwritten)
// return: ret answer payload for get request
String simpleGet(String sPayload)
{
 String p1=String("");                      // help string
 sPayload.toLowerCase();                    // for easy compare
 //-------------------------------------------------------------
  if(sPayload=="help" || sPayload=="?") {
  p1 ="+MQTT: ../set/w1 -m 1|g|G OR -m 0|A|a|B|b (set by name)\r\n";
  p1+="      ../set/11 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)\r\n";
  p1+="      ../get -m byname|bydcc (values of all components)\r\n";
  return p1;
 }
 //-------------------------------------------------------------
  if(sPayload=="version") {
  p1="{\"version\":\""; p1+= String(VERSION_99); p1+="\"}";
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="ip") {
  p1="{\"ip\":\""; p1+= client.getsLocalIP(); p1+="\"}";
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="topicbase") {
  p1="{\"topicbase\":\""; p1+=client.getsTopicBase(); p1+="\"}";
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="eeprom") {
  int iResult1, iResult2;
  String s1=client.eepromReadTopicBase(iResult1);
  String s2=client.eepromReadMyData(iResult2);
  p1="{\"topicbase\":\"";
  if(iResult1>=0) p1+=s1;
  else
  {
   if(iResult1==-2) p1+="(no topic base)";
   else p1+=String("Error_#")+String(iResult1);
  }
  p1+="\",\"mydata\":\"";
  if(s2=="") p1+="(no data)";
  else p1+=s2;
  p1+="\"}";
  return p1;
 }

 //-------------------------------------------------------------
 //------is it a get command for one or all railway components?-
  if(sPayload=="byname" || sPayload=="bydcc") {
  p1="{";
  for(int i=0; i<RCOMP_NUM; i++) {
   if(i>0) p1+=",";
   if(sPayload=="byname") p1+="\"" + aRcomp[i].name + "\":\"";
   else p1+="\"" + String(aRcomp[i].dcc) + "\":\"";
   if(aRcomp[i].type==RC_TYPE_TO || aRcomp[i].type==RC_TYPE_T3) {
    switch(aRcmd[i].inValue) {
     case 0: if(aRcomp[i].type==RC_TYPE_T3) p1+=T_STRIGHT;
             else p1+=T_UNDEF0;
             break;                          // BA=00
     case 1:  p1+=T_STRIGHT;  break; // BA=01 (stright)
     case 2:  p1+=T_CURVED;   break; // BA=10 (curved)
     case 3:  p1+=T_UNDEF1;   break; // BA=11
     default: p1+=T_UNKNOWN;  break; // ?? impossible
    }
   } else {
    if(aRcomp[i].type==RC_TYPE_DT) { // discon track (fahrstrom)
     aRcmd[i].inValue ? p1+=T_ON : p1+=T_OFF;
    } else {
     if(aRcomp[i].type==RC_TYPE_UC) {
     aRcmd[i].inValue ? p1+=T_ON : p1+=T_OFF;
     } else {
      p1+=String(aRcmd[i].inValue);
     }
    }
   }
   p1+="\"";
  }
  p1+="}";
  return p1;
 }

 //------is it a get command for one railway component?---------
 for(int i=0; i<RCOMP_NUM; i++) {
  String s1=String(aRcomp[i].name);
  s1.toLowerCase();
  if(sPayload==s1 || sPayload==String(aRcomp[i].dcc)) {
   p1="{\""+aRcomp[i].name+"\":\"";
      if(aRcomp[i].type==RC_TYPE_TO || aRcomp[i].type==RC_TYPE_T3) {
    switch(aRcmd[i].inValue) {
     case 0: if(aRcomp[i].type==RC_TYPE_T3) p1+=T_STRIGHT;
             else p1+=T_UNDEF0;
             break;                          // BA=00
     case 1:  p1+=T_STRIGHT;  break; // BA=01 (stright)
     case 2:  p1+=T_CURVED;   break; // BA=10 (curved)
     case 3:  p1+=T_UNDEF1;   break; // BA=11
     default: p1+=T_UNKNOWN;  break; // ?? impossible
    }
   } else {
    if(aRcomp[i].type==RC_TYPE_DT) { // discon track (fahrstrom)
     aRcmd[i].inValue ? p1+=T_ON : p1+=T_OFF;
    } else {
     if(aRcomp[i].type==RC_TYPE_UC) {
     aRcmd[i].inValue ? p1+=T_ON : p1+=T_OFF;
     } else {
      p1+=String(aRcmd[i].inValue);
     }
    }
   }
   p1+="\"}";
   return p1;
  }
 }

 //-------------------------------------------------------------
 return String("");                         // wrong Get command
}

//_______Execute set requests___________________________________
// sTopic from TOPIC_SET, sPayload: payload to topic
// return: ret answer payload for set command
String simpleSet(String sTopic, String sPayload)
{
 String p1=String("");                      // help string
 sTopic.toLowerCase();
 sPayload.toLowerCase();                    // for easy compare
 //-------------------------------------------------------------
 if(sTopic=="topicbase") {                  // new topic base?
  client.changeTopicBase(sPayload);         // change base
  p1="{\"topicbase\":\"";                   // start json
  p1+=client.getsTopicBase();               // read new base
  p1+="\"}";                                // end json
  showLine(3, client.getsTopicBase());      // show on display
  return p1;                                // return new base
 }
 //-------------------------------------------------------------
 if(sTopic=="eeprom0") {                    // erase eeprom?
  if(sPayload=="?") {
   p1="{\"erase\":\"";                      // start json
   p1+="1=topicBase|2=myData|3=all\"}";     // end json
   return p1;                               // return erase info
  }
  p1="";
  if(sPayload=="2" || sPayload=="3" || sPayload=="all")
  {
   p1+="my data ";
   if(!client.eepromEraseMyData()) p1+="NOT ";
   p1+="deleted";                           // return answer 1
  }
  if(sPayload=="1" || sPayload=="3" || sPayload=="all")
  {
   if(p1!="") p1+=", ";
   p1+="topicbase ";
   if(!client.eepromEraseTopicBase()) p1+="NOT ";
   p1+="deleted";                           // return answer 2
  }
  p1="{\"eeprom\":\""+p1+"\"}";             // make json
  return p1;
 }
 //-------------------------------------------------------------

 //------is it a set command for a railway component?-----------
 for(int i=0; i<RCOMP_NUM; i++)
 {
  String s1=String(aRcomp[i].name);
  s1.toLowerCase();
  if(sTopic==String(aRcomp[i].dcc) || sTopic==s1) {
   int iCmdValue=-1;
   if(aRcomp[i].type==RC_TYPE_TO || aRcomp[i].type==RC_TYPE_T3) {
    if(sPayload=="0" ||  sPayload=="a" || sPayload=="b") iCmdValue=0;
    if(sPayload=="1" || sPayload=="g") iCmdValue=1;
   } else {
    if(sPayload=="0") iCmdValue=0;
    if(sPayload=="1") iCmdValue=1;
   }
   return(setRcompCmd(i, iCmdValue, sPayload));
  } // END OF if: set command for a railway component
 } // END OF for-loop
 //-------------------------------------------------------------
 return String("");                         // wrong set command
}

//_______Execute sub requests___________________________________
// sTopic from TOPIC_SUB, sPayload: payload to topic
// return: no automatic answer
void simpleSub(String sTopic, String sPayload)
{
 //-------------------------------------------------------------
}
#endif

// *************************************************************
// Display Functions
// *************************************************************

//_______Save line content, write it to display and show screen_
// line_: 0 ... SCREEN_LINE_MAX (6)
// uses: screen_, aScreenSign[], aScreenText[]
// function saves the text (in aScreenText[])
//    BUT DOES NOT change the sign of a line (invert text)
void showLine(int line_, String text_) {
 //------Save line for refeshScreen()---------------------------
 int lineAbs=line_;
 if(lineAbs<0) lineAbs=-lineAbs;
 if(lineAbs>=0 && lineAbs<=SCREEN_LINE_MAX) {
  if(lineAbs==0) aScreenText[lineAbs]=text_;
  else aScreenText[lineAbs-1]=text_;
  screen_.screen15(line_,"                     ");
  //-----Prepare line-------------------------------------------
  if(line_==0) {
   screen_.screen15Clear(0,text_,'c');       // title center, rect
  } else {
   screen_.screen15(line_,text_,'l');        // left aligned
  }
  //-----Show screen--------------------------------------------
  screen_.sendBuffer();                     // show screen
 }
}

//_______Fill the screen lines with current content_____________
// uses: aScreenText[], aRcomp[]
void prepareScreenLine4to6(int iRcompGroup) {
 String s1="";                              // help string
 aScreenText[3]="";                         // clear line 4
 aScreenText[4]="";                         // clear line 5
 aScreenText[5]="";                         // clear line 6
 int iRcStart=5*iRcompGroup;                // RComp start index
 int imax=RCOMP_NUM-iRcStart;               // last element to show
 if(imax>5) imax = 5;                       // max. 5 elements
 //------Format "On" or "Off"-----------------------------------
 String t_on  = (String(T_ON)  + "    ").substring(0,4);
 String t_off = (String(T_OFF) + "    ").substring(0,4);
 //------for max. 5 elements------------------------------------
 for(int i=0; i<imax; i++) { // for max. 5 group elements
  int iRc=iRcStart+i;
  //-----railway component name max. 3 chars + blank = 4 chars--
  aScreenText[3]+=(aRcomp[iRc].name.substring(0,3)+"    ").substring(0,4);
  //-----generate symbol or value (line 5 of screen)------------
  if(aRcomp[iRc].type==RC_TYPE_TO || aRcomp[iRc].type==RC_TYPE_T3){ // turnout
   switch(aRcmd[iRc].inValue) {
    case 0: if(aRcomp[iRc].type==RC_TYPE_T3) aScreenText[4]+="__  ";
            else aScreenText[4]+="0?  ";
            break;                          // BA=00
    case 1:  aScreenText[4]+="__  ";  break; // BA=01 (stright)
    case 2:  aScreenText[4]+="_/  ";  break; // BA=10 (curved)
    case 3:  aScreenText[4]+="1?  ";  break; // BA=11
    default: aScreenText[4]+="??  ";  break; // ?? impossible
   } // END OF switch
  } else { //......not RC_TYPE_TO or RC_TYPE_T3.................
   if(aRcomp[iRc].type==RC_TYPE_DT) { // discon track (fahrstrom)
    aRcmd[iRc].inValue ? aScreenText[4]+=t_on : aScreenText[4]+=t_off;
   } else { //.....not RC_TYPE_DT...............................
    if(aRcomp[iRc].type==RC_TYPE_UC) {
     aRcmd[iRc].inValue ? aScreenText[4]+=t_on : aScreenText[4]+=t_off;
    } else { //....not RC_TYPE_UC...............................
     if(aRcomp[iRc].type==RC_TYPE_BL) {
      if(aRcmd[iRc].iCmd==CMD_BLINK)
      {
       aScreenText[4]+="run ";
      } else {
       aScreenText[4]+="--- ";
      }
      //aRcmd[iRc].inValue ? aScreenText[4]+="1_0 " : aScreenText[4]+="0_1 ";
      //aScreenText[4]+="0|1 ";
     } else { //...not RC_TYPE_BL...............................
      aScreenText[4]+=(" "+String(aRcmd[iRc].inValue)+"   ").substring(0,4);
     } // END OF not RC_TYPE_BL
    } // END OF not RC_TYPE_UC
   } // END OF not RC_TYPE_DT
  } // END OF not RC_TYPE_TO ot RC_TYPE_T3
  //-----dcc number of railway element--------------------------
  aScreenText[5]+=(String(aRcomp[iRc].dcc)+"    ").substring(0,4);
 } // END OF for max. 5 elements
}

//_______Refresh screen to avoid damage_________________________
// uses: screen_, aScreenSign[], aScreenText[]
void refreshScreen() {
 //------Clear screen-------------------------------------------
 screen_.screen15Clear(0,aScreenText[0],'c'); // centered title
 for(int i=1; i<SCREEN_LINE_MAX; i++) { 
  screen_.screen15(aScreenSign[i]*(i+1),aScreenText[i]);
 }
 //------Show screen--------------------------------------------
 screen_.sendBuffer();                      // show screen
}

//_______Show line 4 to 6 on OLED_______________________________
// uses: screen_, aScreenSign[], aScreenText[]
void showScreenLine4to6() {
 screen_.screen15(aScreenSign[3]*4,aScreenText[3]);
 screen_.screen15(aScreenSign[4]*5,aScreenText[4]);
 screen_.screen15(aScreenSign[5]*6,aScreenText[5]);
 //------Show screen--------------------------------------------
 screen_.sendBuffer();                      // show screen
}

//_______show information on OLED at progam start_______________
// uses: INFOLINES_NUM, infolines[], showLine6WaitMaxXXs()
//       screen15Clear(), screen15()
void showInfolines() {
 if(INFOLINES_NUM<=0) return;               // nothing to show
 int iPageMax=1+int((INFOLINES_NUM-1)/5);
 //-----------for all pages-------------------------------------
 for(int iPage=0; iPage<iPageMax; iPage++) {
  if(DEBUG_99) { Serial.println("  Show Info Page "+String(1+iPage)); }
  int iStartline=iPage*5;
  int iEndline=iStartline+5;
  if(iEndline > INFOLINES_NUM) iEndline=INFOLINES_NUM;
  screen_.screen15Clear(0,SCREEN_TITLE,'c'); // centered title
  //----------prepare lines for one page------------------------
  for(int j=iStartline; j<iEndline-1; j++) {
    screen_.screen15(j+2-iPage*5,infolines[j],'l'); // left aligned
  } // END OF "prepare lines for one page"----------------------
  showLine6WaitMaxXXs(INFOLINES_SEC, infolines[iEndline-1]);
 } // END OF for all pages--------------------------------------
}

//_______wait iSec seconds or stopp display by push button______
void showLine6WaitMaxXXs(int iSec, String line6) {
 int    wait_XXs=iSec;
 int    iButton_=1;
 String s1;
 while(wait_XXs>0 && iButton_==1) { 
  s1=String(wait_XXs) + line6;
  wait_XXs--;
  screen_.screen15(-6,s1,'l');              // left aligned
  screen_.sendBuffer();                     // show screen
  int j=10;
  while(j>0 && iButton_==1)
  {
   iButton_=digitalRead(PIN_BUTTON);
   j--;
   delay(100);
  }
 }
}

// *************************************************************
// Command Functions
// *************************************************************

//_______prepare a set command for a railway component__________
// Set the values of the strRcmd structure for the selected 
// array element aRcmd[iRcomp] depending on the 
// RR component type and command value.
// Result: an array element aRcmd[iRcomp] with a valid state 
// number and an answer string e.g. for WiFi answer
// Input values:
// * iRcomp......index of railway component (0...RCOMP_NUM-1)
// * iCmdValue...command value (usually 0 or 1)
// * sReturn.....start text of return text
// Called by onAccessoryPacket(), simpleSet()
// uses: aRcomp[]
// return: answer string e.g. for WiFi answer
String setRcompCmd(int iRcomp, int iCmdValue, String sReturn) {
 if(aRcomp[iRcomp].type==RC_TYPE_TO || aRcomp[iRcomp].type==RC_TYPE_T3) {
  //...it is a turnout command (2 bits, 2cmds)................
  if(iCmdValue==0) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;
   aRcmd[iRcomp].iCmd=CMD_BIT2_A;             // turnout curved
   //aRcmd[iRcomp].stateOffset=STATES_TURNOUT_ON;
   aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/STATE_DELAY;
   aRcmd[iRcomp].iCmdOffset=CMD_BIT2_OFF;     // turnout off
   return sReturn+String(" received");
  } else {
  //. .command turnout stright?. . . . . . . . . . . . . . . .
   if(iCmdValue==1) { 
    aRcmd[iRcomp].stateToDo=STATE_NOW;
    aRcmd[iRcomp].iCmd=CMD_BIT2_B;            // turnout stright
    aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/STATE_DELAY;
    aRcmd[iRcomp].iCmdOffset=CMD_BIT2_OFF;    // turnout off
    return sReturn+String(" received");
   }
  }
 } // END OF it is a turnout command (2 bits, 2cmds)............
 if(aRcomp[iRcomp].type==RC_TYPE_UC) {
  //...it is a uncoupler command (1 bit, 2cmds).................
  if(iCmdValue==0) {                        // turn current off
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BITA_OFF;         // turn current off
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
  if(iCmdValue==1) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BITA_ON;          // turn current on
   aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/STATE_DELAY; // after some time
   aRcmd[iRcomp].iCmdOffset=CMD_BITA_OFF;   // turn current off
   return sReturn+String(" received");
  }
 } // END OF it is a uncoupler command (1 bit, 2cmds)...........

 if(aRcomp[iRcomp].type==RC_TYPE_DT) {
  //...it is a disconn track command (1 bit, 1cmd)............
  if(iCmdValue==0) {                        // turn current off
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BITA_OFF;         // turn current off
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
  if(iCmdValue==1) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BITA_ON;          // turn current on
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
 } // END OF it is a disconn track command (1 bit, 1cmd)......

 if(aRcomp[iRcomp].type==RC_TYPE_BL) {
 //...it is a blink command (1 bit, 1cmd).......................
  if(iCmdValue==0) {                        // stopp blinking
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BLINK_END;        // turn blinking off
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
  if(iCmdValue==1) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BLINK;            // turn blink on
   aRcmd[iRcomp].inValue=0;                 // 0=led on
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
 } // END OF it is a blink command (1 bit, 1cmd)................

 return sReturn+String(" - Error");
}

//_______act on a command_______________________________________
// Search the command field aRcmd[] to see whether a first or 
// second command is to be executed for the current state number.
// If yes, execute the hardware access using actOnCmdHardware()
// and the corresponding values.
// Called by loop()
// Uses:   aRcomp[] (railway components)
//         actOnCmdHardware() (aIOEx[] = PCF8574)
//         stm.add (state machine)
// Return: command string (for serial output)
//         or return "" if there was nothing to do
String actOnCmd(int32_t state) {
 String sSerial_="";
 for(int i=0; i<RCOMP_NUM; i++) { // for all railway components
  //.....is this a 1st state to do something?...................
  if(state==aRcmd[i].stateToDo) {
   int iCmd_=aRcmd[i].iCmd;
   int iOutPCF_=aRcomp[i].outPCF; 
   int outBitA_=aRcomp[i].outBitA;
   int outBitB_=aRcomp[i].outBitB;
   int inBit_ =aRcmd[i].inValue;
   if(iCmd_==CMD_BLINK_END) inBit_=1;       // LED off
   sSerial_=actOnCmdHardware(iCmd_, iOutPCF_, outBitA_, outBitB_, inBit_);
   if(iCmd_==CMD_BLINK){
    //...prepare next blink command.............................
    if(inBit_>0) {
     aRcmd[i].inValue=0;
     aRcmd[i].stateToDo=stm.add(aRcomp[i].msOff/STATE_DELAY);
    } else {
     aRcmd[i].inValue=1;
     aRcmd[i].stateToDo=stm.add(aRcomp[i].msOn/STATE_DELAY);
    }
   } else {
    //...1st part of command is done: delete it.................
    aRcmd[i].stateToDo=STATE_NONE;
    aRcmd[i].iCmd=CMD_NONE;
   }
  }
  //.....is this a 2nd state to do something?...................
  if(state==aRcmd[i].stateOffset) {
   int iCmd_=aRcmd[i].iCmdOffset;
   int iOutPCF_=aRcomp[i].outPCF; 
   int outBitA_=aRcomp[i].outBitA;
   int outBitB_=aRcomp[i].outBitB;
   sSerial_=actOnCmdHardware(iCmd_, iOutPCF_, outBitA_, outBitB_, 0);
   aRcmd[i].stateOffset=STATE_NONE;
   aRcmd[i].iCmdOffset=CMD_NONE;
  }
 }
 return sSerial_;
}

// *************************************************************
// Hardware Access Functions
// *************************************************************

//_______Update input values____________________________________
// Read the value of the input pins of all components.
// For non-blinkers, the value (0..3) is stored in the command
// array element. 
// Set iValueChanged to true if the value has changed.
// The index of the last changed element is returned
// (unless it was a blink component).
// If nothing has changed, -1 is returned.
// Uses: aRcomp[]
// Return: (last) index of Rcomp, where input value has changed
//         -1: no change (or only a blink component has changed)
int updateInputValues() {
 int iReturn=-1;                            // no changes
 //------update input values------------------------------------
 for(int i=0; i<RCOMP_NUM; i++) {           // for all components
  //.....read input values......................................
  int iBitsBA=0;                            // help value
  int iIOEx=aRcomp[i].inPCF;                // number of expander
  if(iIOEx>=0 && iIOEx<IOEX_NUM) {
   int iBit=aRcomp[i].inBitA;
   if(iBit!=NO_PIN) iBitsBA+=(*pIOEx[iIOEx]).getBit(iBit);
   iBit=aRcomp[i].inBitB;
   if(iBit!=NO_PIN) iBitsBA+=2*(*pIOEx[iIOEx]).getBit(iBit);
   //.....save input value......................................
   if(aRcmd[i].inValue!=iBitsBA) 
   {
    aRcmd[i].inValueChanged=true;
    if(aRcmd[i].iCmd!=CMD_BLINK) {
     aRcmd[i].inValue=iBitsBA;
     iReturn=i;
    }
   } else {
    aRcmd[i].inValueChanged=false;
   } // END OF save input value.................................

  } else {
   Serial.println("Error in updateInputValues(): wrong IO index!");
  }
 } // END OF update input values--------------------------------
 return iReturn;
}

//_______act on a command, Hardware_____________________________
// called by actOnCmd()
// input : iCmd_   : command number, what to do
//         iOutPCF_: index (offset) of output expander
//         outBitA_: number of output bit A
//         outBitB_: number of output bit B
//         more_   : used by blink light
// uses  : aIOEx[] (PCF8574)
// return: command string (for serial output)
//         or return "" if there was nothing to do
String actOnCmdHardware(int iCmd_, int iOutPCF_, 
                        int outBitA_, int outBitB_, int more_) {
 String sSerial_="";
 switch(iCmd_){
  case CMD_NONE:                            // No command
   sSerial_="cmd: No comnmand";
   break;
  case CMD_BITA_ON:                         // A=0 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0); // OK
    sSerial_="cmd: Pin A 0V";
   } else sSerial_="No pin A";
   break;
  case CMD_BITA_OFF:                        // A=1
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 1);
    sSerial_="cmd: Pin A 5V";
   } else sSerial_="No pin A";
   break;
  case CMD_BIT2_ON:                         // BA=00 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0);
    sSerial_="cmd: Pin A 0V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 0);
    sSerial_+="Pin B 0V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT2_A:                         // BA=10 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0);
    sSerial_="cmd: Pin A 0V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 1);
    sSerial_+="Pin B 5V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT2_B:                         // BA=01 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 1);
    sSerial_="cmd: Pin A 5V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 0);
    sSerial_+="Pin B 0V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT2_OFF:                        // BA=11 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 1);
    sSerial_="cmd: Pin A 5V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 1);
    sSerial_+="Pin B 5V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BLINK: case CMD_BLINK_END:
   (*pIOEx[iOutPCF_]).setBit(outBitA_, more_);
   sSerial_+="Blink="+String(more_);
   break;

  default:
   sSerial_+="cmd: unknown "+String(iCmd_);
   break;
 }
 if(outBitA_==3) sSerial_+="***PinA=3***";
 return sSerial_;
}

// *************************************************************
// Standard Functions
// *************************************************************

//_____SETUP____________________________________________________
void setup() {
 bool bRet;
 int button_;
 String s1="", s2="", s3="";
 //------Serial, just for debug---------------------------------
 if(DEBUG_99) {
  Serial.begin(115200);
  Serial.flush();
  Serial.println("\nsetup(): --Start--");
 }
 //------init railway commands----------------------------------
 for(int i=0; i<RCOMP_NUM; i++) {
  aRcmd[i]={RCMD_NONE};
 }
 //------hardware-----------------------------------------------
 pinMode(BUILTIN_LED, OUTPUT);              // build in led
 pinMode(PIN_BUTTON, INPUT);                // button next display
 //------use WiFi and MQTT?-------------------------------------
 bUseWiFi=(_USE_WIFI_ ? true : false);
 //------Init 1.54" display (SSD1309, 128x64 pixel)-------------
 screen_.begin();                           // start i2c
 //screen_.useCP437();                      // after screen_.begin();
 screen_.setFontText(u8g2_font_KH_cp437_6x8_mf); //
 screen_.useFontText();                     // write text
 screen_.setFontRefHeightText();            // (default)
 screen_.setFontPosTop();                   // font position
 //------show info lines, if defined----------------------------
 showLine(0, SCREEN_TITLE);                 // show title
 showInfolines();
 //------Init all 8-Bit I/O Expander PCF8574--------------------
 s2="setup(): Found I2C device at ";
 bool bfirstComp=true;
 for(int i=0; i<IOEX_NUM; i++) {
  //aIOEx[i].setInvertOutput(true);
  s1=String((*pIOEx[i]).getAddress(), 16);
  s3="Search PCF8474 0x"+s1;
  s3=s3.substring(0,SCREEN_LINE_LEN);       // max. 21 character
  showLine(3,s3);
  while (!(*pIOEx[i]).begin(bfirstComp)) {  // I2C started
   if(DEBUG_99) {
    Serial.println("Error: "+(*pIOEx[i]).getsStatus());
    Serial.print(" - Could not find PCF8574 at 0x");
    Serial.print((*pIOEx[i]).getAddress(), 16);
    Serial.println(": check wiring");
   }
   showLine(4,s1+" NOT found - Check wiring!");
   delay(5000);                             // wait 5s
  }
  bfirstComp=false;
  s2+=" 0x"+s1;                             // add address to found
  (*pIOEx[i]).setByte(0xFF);
  showLine(5,s2);                           // show found addresses
  if(DEBUG_99) { Serial.println(s2); }
 }
 showLine(4, "");                           // clear "search"-line

 //------Setup WiFi/MQTT client---------------------------------
#if _USE_WIFI_ == true
 if(bUseWiFi) {
  client.setLanguage(LANGUAGE);           //e=english,d=german
  client.setCallback(callback);              // mqtt receiver
  client.setTopicBaseDefault(TOPIC_BASE);    // topic base
  client.setWiFiWaitingTime(1000);           // set a short time (1s)
  client.setWiFiConnectingCounter(19);       // try 10s connecting
  s1="";
  for(int i=0; i<RCOMP_NUM; i++) {
   s1+=","+aRcomp[i].name;
   s1+=","+String(aRcomp[i].dcc);
  }
  client.setTopics(String(TOPIC_GET)+s1,String(TOPIC_SET)+s1,TOPIC_SUB,TOPIC_PUB);
  //client.setRetainedIndex("get",3,true);
  client.begin();                            // setup objects
  //------Show connecting procedure-----------------------------
  s1="WiFi "+String(_SSID_)+" connecting...";
  s1=s1.substring(0,SCREEN_LINE_LEN);        // max. 21 character
  screen_.screen15(2,s1);                    // line 2: begin connect
  screen_.screen15(4,"Button: skip WiFi -->");   // line4: 
  if(DEBUG_99) Serial.print("setup(): "+s1+String("\n"));
  client.connectingWiFiBegin();              // begin connecting
  int iUseWiFi=30;
  //.....waiting for WiFi connection............................
  do {
   if(digitalRead(PIN_BUTTON)==0) { iUseWiFi=0; break; }
   bRet=client.connectingWiFi();             // try to connect
   screen_.screen15Dot(3);                   // line 3: waiting dot
   iUseWiFi--;
   if(DEBUG_99) Serial.println("  Waiting for WiFi: "+String(iUseWiFi));
  } while(!bRet && iUseWiFi>0);
  //.....END OF waiting for WiFi connection.....................
  if(iUseWiFi>0) {
   if(DEBUG_99) Serial.println("setup(): FOUND WiFi " + client.getsSSID());
   //----WiFi ok (no timeout)-----------------------------------
   iConn=CON_WIFI_OK;                        // WiFi OK
   bUseWiFi=true;                            // use WiFi 
   s2="{\"topicbase\":\""+client.getsTopicBase()+"\"}";
   int iMqttReady=6;
   do {
    iMqttReady--;
    if(DEBUG_99) Serial.println("  Waiting for MQTT: "+String(iMqttReady));
    delay(500);
    client.doLoop();                          // mqtt loop
   } while (!client.isMQTTConnected() && !client.isMQTTConnectedNew() && iMqttReady>0);
   if(iMqttReady>0)
   {
    //----WiFi and MQTT OK: publish start info-------------------
    iConn=CON_MQTT_OK;                      // MQTT OK
    //client.bAllowMQTTStartInfo(false);     //NO mqtt (re)start info
    if(DEBUG_99) Serial.println("setup(): Connected to MQTT-broker: "+s2);
    client.publish_P("rcc/start/mqtt",s2.c_str(),false);
   }
   else
   {
    iConn=CON_NO_MQTT;                      // WiFi yes, MQTT no
   }
  } else {
   //----WiFi timeout-------------------------------------------
   if(DEBUG_99) Serial.println("setup(): WiFi " + client.getsSSID() + "NOT FOUND!");
   iConn=CON_NO_WIFI;                        // NO WiFi
   bUseWiFi=false;                           // don´t use WiFi
   s2=T_NO_MQTT;                             // No control via MQTT
   s2=s2.substring(0,SCREEN_LINE_LEN);       // max. 21 character
  }
  s1="WiFi "+ sConn[iConn]+ " " + String(_SSID_);
  showLine(2, s1);
  showLine(3, s2);
 }
#else
 //------Dont use WiFi anyway-----------------------------------
 iConn=CON_NO_WIFI;                        // NO WiFi
 s1=T_NO_MQTT;
 s1=s1.substring(0,SCREEN_LINE_LEN);       // max. 21 character
 showLine(2, s1);
 showLine(3, "");
#endif

 //------DCC: register pin and callback routine-----------------
 DccAccessoryDecoder.begin(PIN_DCC, onAccessoryPacket);
 if(DEBUG_99) Serial.println("setup(): DccAccessoryDecoder OK");
 //------Finish setup-------------------------------------------
 int iTemp=updateInputValues();
 if(DEBUG_99) Serial.println("setup(): --Finished--\n");
}

int32_t reset_countdown=-1;            // -1 no count down
int32_t stateNextScreenRefresh=1;
int32_t stateNextScreenMin=STATE_NONE;
int     iRcompGroupNow=-1;             // group shown now
int     iRcompGroupNext=NO_GROUP;      // next group

//_____LOOP_____________________________________________________
void loop() {
 //======(1) do at the beginning of the loop ...================
 int state=stm.loopBegin();                 // state begin
 String s1;                                 // help value
 String sSerial=String(state);              // collect serial output

 //======(2) do, independent on the network, ...================
 
 //------(2.1) button handling (reset by software)--------------
 if(digitalRead(PIN_BUTTON)==0) {
  //.....button pressed (0).....................................
  if(reset_countdown<0) reset_countdown=STATES_BEFORE_RESET;
  else reset_countdown--;
  sSerial+="Resetcounter="+String(reset_countdown);
  //.....time for reset?........................................
  if(reset_countdown==0) { // yes, time for reset
   screen_.clear();
   screen_.useFontTitle();
   screen_.drawString(50,30,String("RESET"));
   esp_restart();
  } // END OF yes, time for reset
 } else {
  //.....button not pressed (1).................................
  reset_countdown=-1;
 }

 //------(2.2) For all comp: replace STATE_NOW by current state-
 for(int i=0; i<RCOMP_NUM; i++) { // for all components
  if(aRcmd[i].stateToDo==STATE_NOW) {
   aRcmd[i].stateToDo=state;
   if(aRcmd[i].stateOffset!=STATE_NONE) {
    aRcmd[i].stateOffset=stm.add(aRcmd[i].stateOffset);
   }
  }
 } // END OF for all components

 //------(2.3) update all input values into aRcomp[]------------
 int iRcomp_=updateInputValues();            // get input

 //------(2.4) update display, if there was an input change-----
 if(iRcomp_>=0) { // yes, input changed
  int iRcompGroup_=int(iRcomp_/5);
  if(iRcompGroup_== iRcompGroupNow)
  { // change in current displayed group: show change-----------
   prepareScreenLine4to6(iRcompGroupNow);
   showScreenLine4to6();
  } else { // another group should be shown.....
   iRcompGroupNext=iRcompGroup_;
  }
 } // END OF yes, input changed

 //------(2.5) refresh screen-----------------------------------
 if(state >= stateNextScreenMin)
 { // .......screen refresh allowed.............................
  if(iRcompGroupNext != NO_GROUP) {
   prepareScreenLine4to6(iRcompGroupNext);
   refreshScreen();
   stateNextScreenRefresh=stm.add(STATES_SCREEN_REFRESH);
   stateNextScreenMin=stm.add(STATES_SHOW_SCREEN_MIN);
   iRcompGroupNext = NO_GROUP;
   if(iRcompGroupNow>0) iRcompGroupNow--;
   else iRcompGroupNow=int((RCOMP_NUM-1)/5);

  }
 } // END OF screen refresh allowed
 if(state >= stateNextScreenRefresh)
 { // .......standard screen refresh............................
  iRcompGroupNow++;
  if(5*iRcompGroupNow > RCOMP_NUM) iRcompGroupNow=0;
  prepareScreenLine4to6(iRcompGroupNow);
  refreshScreen();
  iRcompGroupNext = NO_GROUP;
  stateNextScreenRefresh=stm.add(STATES_SCREEN_REFRESH);
  stateNextScreenMin=stm.add(STATES_SHOW_SCREEN_MIN);
 } // END OF standard screen refresh

 //======(3) process mqtt actions===============================
 #if _USE_WIFI_ == true
 if(bUseWiFi) {
  client.doLoop();                          // mqtt loop
  //=====(4) do, depending on the network access, ...===========
  if(client.isWiFiConnectedNew())    iConn=CON_WIFI_OK;// "WiFi OK   ";
  if(client.isMQTTConnectedNew())    iConn=CON_MQTT_OK;// "MQTT OK   ";
  if(client.isMQTTDisconnectedNew()) iConn=CON_NO_MQTT;// "-No MQTT--";
  if(client.isWiFiDisconnectedNew()) iConn=CON_NO_WIFI;// "-No WiFi--";
 } else {
  iConn=CON_WIFI_NOT_USED;                  // "unused WiFi"
 }
 //------show WLAN-/MQTT-connection status----------------------
 if(iConn!=iConnOld) {
  iConnOld=iConn;
  sSerial+=" | "+sConn[iConn];
  showLine(2,sConn[iConn]+" "+String(_SSID_));
 }
 #endif

 //======(4) do things after mqtt access========================
 //------act on a command---------------------------------------
 s1=actOnCmd(state);
 if(s1!="") sSerial+=" | "+s1;

 //======(5) do at the end of the loop ...======================
 DccAccessoryDecoder.loop();
 if(dccAddress>=0 && dccAddress<2048) {
  sSerial+=" | DCC Adresse="+String(dccAddress)+" Wert="+String(dccValue);
  dccAddress=-1;
 }
 uint32_t ms=stm.loopEnd();                   // state end
 //------print serial data--------------------------------------
 if(DEBUG_99) {
  Serial.print(sSerial+" | "); Serial.print(ms); 
  if(ms>STATE_DELAY) Serial.println("ms-Too long!!");
  else Serial.println("ms");
 }
}