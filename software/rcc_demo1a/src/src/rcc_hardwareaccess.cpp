//_____rcc_hardwareaccess.cpp____________________khartinger_____

#include "rcc_hardwareaccess.h"

extern SimpleMqtt client;
extern strRcomp aRcomp[RCOMP_NUM];
extern strRcmd aRcmd[RCOMP_NUM];
extern PCF8574 *pIOEx[IOEX_NUM];

//______________________________________________________________
/**
 * @brief Initializes the hardware at start of setup()
 */
void initHardwareAccess1(Screen154 &screen_) {
 //------ESP hardware-------------------------------------------
 pinMode(BUILTIN_LED, OUTPUT);              // build in led
 pinMode(PIN_BUTTON, INPUT);                // button next display
//------init railroad commands----------------------------------
 for(int i=0; i<RCOMP_NUM; i++) {
  aRcmd[i]={RCMD_NONE};
 }
}

//______________________________________________________________
/**
 * @brief Initializes the hardware at end of setup()
 */
void initHardwareAccess2(Screen154 &screen_) {
 initAllIOExpander();
 int iTemp=updateInputValues();
}

//______________________________________________________________
/**
 * @brief Reads and updates input values
 * 
 * Read the value of the input pins of all components.
 * For non-blinkers, the value (0..3) is stored in the command
 * array element aRcmd[i].inValue.
 * Set aRcmd[i].iValueChanged to true if the value has changed.
 *
 * @see Uses: aRcomp[]
 * @return (last) index of Rcomp, where input value has changed
 * or -1 if there was no change or only a blink component has changed
 */
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
   //....save input value.......................................
   if(aRcmd[i].inValue!=iBitsBA) 
   {
    aRcmd[i].inValueChanged=true;
    if(aRcmd[i].iCmd!=CMD_BLINK) 
    { // Not a BLINK command....................................
     aRcmd[i].inValue=iBitsBA;
     iReturn=i;
     //..value changed: prepare sending a mqtt message..........
     String s2=String(aRcomp[i].dcc);
     client.simpleMqttDo("get", s2, s2); // type, topic, payload
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

//______________________________________________________________
/**
 * @brief Executes the hardware access part of a command
 * 
 * @see Called by loopActOnRcmd()
 * @see Uses aIOEx[] (PCF8574)
 * @param iCmd_ command number, what to do
 * @param iOutPCF_ index (offset) of output expander
 * @param outBitA_ number of output bit A
 * @param outBitB_ number of output bit B
 * @param more_ used by blink light
 * @return command string (e.g. for serial output)
 * or return "" if there was nothing to do
 */
String actOnRcmdHardware(int iCmd_, int iOutPCF_, 
  int outBitA_, int outBitB_, int more_) {
 String sSerial_="";
 if(iOutPCF_ < 0 || iOutPCF_ >= IOEX_NUM) {
  return "Error: invalid IO expander";
 }
 switch(iCmd_){
  case CMD_NONE:                            // No command
   sSerial_="cmd: No comnmand";
   break;
  case CMD_BIT_A_0:                         // A=0 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0); // OK
    sSerial_="cmd: Pin A 0V";
   } else sSerial_="No pin A";
   break;
  case CMD_BIT_A_1:                        // A=1
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 1);
    sSerial_="cmd: Pin A 5V";
   } else sSerial_="No pin A";
   break;
  case CMD_BIT_BA_00:                         // BA=00 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0);
    sSerial_="cmd: Pin A 0V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 0);
    sSerial_+="Pin B 0V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT_BA_10:                         // BA=10 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 0);
    sSerial_="cmd: Pin A 0V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 1);
    sSerial_+="Pin B 5V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT_BA_01:                         // BA=01 (active low)
   if(outBitA_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, 1);
    sSerial_="cmd: Pin A 5V, ";
   } else sSerial_="No pin A, ";
   if(outBitB_!=NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitB_, 0);
    sSerial_+="Pin B 0V";
   } else sSerial_+="No pin B";
   break;
  case CMD_BIT_BA_11:                        // BA=11 (active low)
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
   if(outBitA_ != NO_PIN) {
    (*pIOEx[iOutPCF_]).setBit(outBitA_, more_);
    sSerial_ += "Blink=" + String(more_);
    } else {
     sSerial_ = "No pin A";
   }
   break;

  default:
   sSerial_+="cmd: unknown "+String(iCmd_);
   break;
 }
 if(outBitA_==3) sSerial_+="***PinA=3***";
 return sSerial_;
}

//______________________________________________________________
/**
 * @brief Init all 8-Bit I/O Expander PCF8574
 *
// @note If an expected PCF8574 is not detected, 
 * startup is stopped until the hardware is available.
 */
void initAllIOExpander() {
 String s1, s3;
  String s2="setup(): Found I2C device at ";
 String s2oled="I2C found ";
 bool bfirstComp=true;
 for(int i=0; i<IOEX_NUM; i++) {
  //aIOEx[i].setInvertOutput(true);
  s1=String((*pIOEx[i]).getAddress(), 16);
  s3="Search PCF8574 0x"+s1;
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
   // NOTE: If an expected PCF8574 is not detected, 
   //       startup is stopped until the hardware is available.
  }
  bfirstComp=false;
  s2+=" 0x"+s1;                             // add address to found
  s2oled+=" 0x"+s1;                         // add address to found
  if (!(*pIOEx[i]).setByte((*pIOEx[i]).getByte())) {
   Serial.println((*pIOEx[i]).getsStatus());
  }
  showLine(5,s2oled);                       // show found addresses
  if(DEBUG_99) { Serial.println(s2); }      // show found addresses
 }
 showLine(4, "");                           // clear "search"-line
}

//______________________________________________________________
/**
 * @brief Checks whether a reset is desired
 *
 * As soon as the button is pressed, a specific number of states 
 * are counted down. When the count reaches 0, the ESP32 is reset.
 * The counter value is output via the serial interface.
  * @param Serial String for output at the end of loop
 */
void loopResetHandling(String &sSerial) {
 static int32_t reset_countdown=-1;
 //------(2.1) button handling (reset by software)--------------
 if(digitalRead(PIN_BUTTON)==0) {
  //.....button pressed (0).....................................
  if(reset_countdown<0) reset_countdown=STATES_BEFORE_RESET;
  else reset_countdown--;
  sSerial+="Resetcounter="+String(reset_countdown);
  //.....time for reset?........................................
  if(reset_countdown==0) { // yes, time for reset
   esp_restart();
  } // END OF yes, time for reset
 } else {
  //.....button not pressed (1).................................
  reset_countdown=-1;
 }
}