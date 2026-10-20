//_____rcc_dcc.cpp_______________________________khartinger_____

#include "rcc_dcc.h"

extern strRcomp  aRcomp[RCOMP_NUM];    // railroad components
extern String setRcmd(int iRcomp, int iCmdValue, String sReturn);

DccCommand lastDcc;

//______________________________________________________________
/**
 * @brief Callback function for DCC request
 * Generates a command if the DCC address received belongs to a 
 * component of the RCC module.
 *
 * @param linearDecoderAddress DCC address of railroad component
 * @param enabled Received DCC value: true (-> 1) or false (-> 0)
 * @see uses: aRcomp[]
 * @see calls: setRcmd()
 */
void onAccessoryPacket(unsigned int linearDecoderAddress, bool enabled) {
 digitalWrite(BUILTIN_LED, enabled ? 1 : 0);
 lastDcc.address=(int)linearDecoderAddress + DCC_OFFSET;
 lastDcc.value=enabled ? 1 : 0;
 //------is it a DCC address for this module?-------------------
 for(int i=0; i<RCOMP_NUM; i++) {
  if(aRcomp[i].dcc==lastDcc.address) {
   //----railroad component found-------------------------------
   setRcmd(i, lastDcc.value, "");
  }
 }
 if(DEBUG_99) {
  Serial.print("***Change in Accessory: ");
  Serial.print(lastDcc.address);
  Serial.print(" -> ");
  Serial.print(lastDcc.value);
  Serial.println("***");
 }
}
