//_____rcc_command.cpp___________________________khartinger_____

#include "rcc_command.h"

extern strRcomp  aRcomp[RCOMP_NUM];    // railroad components
extern strRcmd   aRcmd[RCOMP_NUM];     // railroad commands

//______________________________________________________________
/**
 * @brief Create a railroad command for a railroad component
 * 
 * Set the values of the strRcmd structure for the selected 
 * array element aRcmd[iRcomp] depending on the 
 * railroad component type and command value.
 * Result: an array element aRcmd[iRcomp] with a valid state 
 * number and an answer string e.g. for WiFi answer
 *
 * aRcomp[] array of railroad components (max. RCOMP_NUM).
 * aRcmd[]  Array of railroad commands associated with the 
 * components. Each component has exactly one command entry
 * with the same index.
 * 
 * @see uses: aRcomp[], aRcmd[]
 * @see Called by onAccessoryPacket(), simpleSet()
 * @param iRcomp index of railroad component (0...RCOMP_NUM-1)
 * @param iCmdValue command value (usually 0 or 1)
 * @param sReturn start text of return text
 * @return String answer string e.g. for WiFi answer
 */

String setRcmd(int iRcomp, int iCmdValue, String sReturn) {
 if(aRcomp[iRcomp].type==RC_TYPE_TO || aRcomp[iRcomp].type==RC_TYPE_TX 
    || aRcomp[iRcomp].type==RC_TYPE_T3) {
  //...it is a turnout command (2 bits, 2cmds)................
  if(iCmdValue==0) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;
   aRcmd[iRcomp].iCmd=CMD_BIT_BA_10;             // turnout curved
   aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1;
   aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;     // turnout off
   return sReturn+String(" received");
  } else {
  //. .command turnout straight?. . . . . . . . . . . . . . . .
   if(iCmdValue==1) { 
    aRcmd[iRcomp].stateToDo=STATE_NOW;
    aRcmd[iRcomp].iCmd=CMD_BIT_BA_01;            // turnout straight
    aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
    if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1;
    aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;    // turnout off
    return sReturn+String(" received");
   }
  }
 } // END OF it is a turnout command (2 bits, 2cmds)............
 if(aRcomp[iRcomp].type==RC_TYPE_UC) {
  //...it is a uncoupler command (1 bit, 2cmds).................
  if(iCmdValue==0) {                        // turn current off
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BIT_A_1;         // turn current off
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
  if(iCmdValue==1) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BIT_A_0;          // turn current on
   aRcmd[iRcomp].stateOffset=aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1; // after some time
   aRcmd[iRcomp].iCmdOffset=CMD_BIT_A_1;   // turn current off
   return sReturn+String(" received");
  }
 } // END OF it is a uncoupler command (1 bit, 2cmds)...........

 if(aRcomp[iRcomp].type==RC_TYPE_DT || aRcomp[iRcomp].type==RC_TYPE_DD) {
  //...it is a disconn track command (1 bit, 1cmd)............
  if(iCmdValue==0) {                        // turn current off
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BIT_A_1;         // turn current off
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
  if(iCmdValue==1) {
   aRcmd[iRcomp].stateToDo=STATE_NOW;       // now...
   aRcmd[iRcomp].iCmd=CMD_BIT_A_0;          // turn current on
   aRcmd[iRcomp].stateOffset=STATE_NONE;    // no state to do
   aRcmd[iRcomp].iCmdOffset=CMD_NONE;       // nothing to do
   return sReturn+String(" received");
  }
 } // END OF it is a disconn track command (1 bit, 1cmd)......

 if(aRcomp[iRcomp].type==RC_TYPE_P2) {
  //...it is a pulse 2 command (2 bits, 2 cmd)..................
  if(iCmdValue==0) { // 0 = reset = LED green . . . . . . . . . 
   aRcmd[iRcomp].stateToDo=STATE_NOW;
   aRcmd[iRcomp].iCmd=CMD_BIT_BA_10;             //  reset
   aRcmd[iRcomp].stateOffset==aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1; // after some time
   aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;     // ready for next pulse
   return sReturn+String(" received");
  } else 
  {
   if(iCmdValue==1) { // 1 = set = LED yellow . . . . . . . . . 
    aRcmd[iRcomp].stateToDo=STATE_NOW;
    aRcmd[iRcomp].iCmd=CMD_BIT_BA_01;            // set
    aRcmd[iRcomp].stateOffset==aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1; // after some time
    aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;    // ready for next pulse
    return sReturn+String(" received");
   }
  }
 } // END OF it is a turnout command (2 bits, 2cmds)............

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

//______________________________________________________________
/**
 * @brief Checks whether a command should be executed
 * 
 * Search the entire command field aRcmd[] to see whether a 
 * first or second command is to be executed for the current
 * state number.
 * If yes, execute the hardware access using loopActOnRcmd()
 * and the corresponding values.
 * @see Uses: aRcomp[] (railroad components), 
 * loopActOnRcmd() (aIOEx[] = PCF8574), 
 * stm.add (state machine)
 * @see Called by loop()
 * @param state Current state number
 * @return command string (e.g. for serial output) 
 * or "" if there was nothing to do
 */
String loopActOnRcmd(int32_t state, Statemachine &stm) {
 String sSerial_="";
 for(int i=0; i<RCOMP_NUM; i++) { // for all railroad components
  //.....is this a 1st state to do something?...................
  if(state==aRcmd[i].stateToDo) {
   int iCmd_=aRcmd[i].iCmd;
   int iOutPCF_=aRcomp[i].outPCF; 
   int outBitA_=aRcomp[i].outBitA;
   int outBitB_=aRcomp[i].outBitB;
   int inBit_ =aRcmd[i].inValue;
   if(iCmd_==CMD_BLINK_END) inBit_=1;       // LED off
   sSerial_=actOnRcmdHardware(iCmd_, iOutPCF_, outBitA_, outBitB_, inBit_);
   if(iCmd_==CMD_BLINK){
    //...prepare next blink command.............................
    if(inBit_>0) {
     aRcmd[i].inValue=0;
     aRcmd[i].stateToDo=stm.add(aRcomp[i].msOff/STATE_TICK_MS);
    } else {
     aRcmd[i].inValue=1;
     aRcmd[i].stateToDo=stm.add(aRcomp[i].msOn/STATE_TICK_MS);
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
   sSerial_=actOnRcmdHardware(iCmd_, iOutPCF_, outBitA_, outBitB_, 0);
   aRcmd[i].stateOffset=STATE_NONE;
   aRcmd[i].iCmdOffset=CMD_NONE;
  }
 }
 return sSerial_;
}

//______________________________________________________________
/**
 * @brief Checks whether a command should be executed
 * 
 */
void loopRcmdReplaceStateNow(int32_t state, Statemachine &stm) {
 //------For all comp: replace STATE_NOW by current state-------
 for(int i=0; i<RCOMP_NUM; i++) { // for all components
  if(aRcmd[i].stateToDo==STATE_NOW) {
   aRcmd[i].stateToDo=state;
   if(aRcmd[i].stateOffset!=STATE_NONE) {
    aRcmd[i].stateOffset=stm.add(aRcmd[i].stateOffset);
   }
  }
 } // END OF for all components

}
