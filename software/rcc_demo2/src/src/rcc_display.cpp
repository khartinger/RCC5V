//_____rcc_display.cpp___________________________khartinger_____

#include "rcc_display.h"
extern strRcomp    aRcomp[RCOMP_NUM];  // railroad components
extern strRcmd     aRcmd[RCOMP_NUM];   // railroad commands

//______________________________________________________________
/**
 * @brief Global memory for updating the screen
 */
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

//______________________________________________________________
/**
 * @brief Init 1.54" display (SSD1309, 128x64 pixel)
 * 
 */
void initDisplay1() {
 screen_.begin();                           // start i2c
 //screen_.useCP437();                      // after screen_.begin();
 screen_.setFontText(u8g2_font_KH_cp437_6x8_mf); //
 screen_.useFontText();                     // write text
 screen_.setFontRefHeightText();            // (default)
 screen_.setFontPosTop();                   // font position
 //------show info lines, if defined----------------------------
 showLine(0, SCREEN_TITLE);                 // show title
 showLine(3, VERSION_99_1);                 // show version
 delay(1000);                               // wait a little
 showInfolines();
}

//______________________________________________________________
/**
 * @brief Save line content, write it to display and show screen
 *
 * Saves the given text and displays it on the screen.
 * Function saves the text in aScreenText[], but 
 * DOES NOT change the sign of a line (invert text).
 *
 * @param line_ line number 0 to SCREEN_LINE_MAX (e.g. 6)
 * @param text_ text to be saved and displayed
 * @see uses: screen_, aScreenSign[], aScreenText[]
 */
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

//______________________________________________________________
/**
 * Creates a text symbol for the LED display on line 5
 *
 * @param iType type of railroad component
 * @param iValue (input) value of railroad component
 * @return 4-char-symbol as String, "??? " on Error
 */
String getSymbol4Line5(int iType, int iValue)
{
  const String ERR="??? ";
  switch(iType)
 {
  case RC_TYPE_T3: // -------3-way-turnout (Dreiwegweiche)------
   switch(iValue) { 
    case 0:  return "__  "; // BA=00
    case 1:  return "_/  "; // BA=01 (straight)
    case 2:  return "__  "; // BA=10 (curved)
    case 3:  return "1?  "; // BA=11
    default: return ERR;    // ?? impossible
   } // END OF switch(iValue)
   break;
  case RC_TYPE_TO: // -------2-way-turnout (Weiche)-------------
   switch(iValue) { 
    case 0:  return "0?  "; // BA=00
    case 1:  return "__  "; // BA=01 (straight)
    case 2:  return "_/  "; // BA=10 (curved)
    case 3:  return "1?  "; // BA=11
    default: return ERR;    // ?? impossible
   } // END OF switch(iValue)
   break;
  case RC_TYPE_TX: // -------double slip turnout/switch (Doppelkreuzungsweiche)
   switch(iValue) { 
    case 0:  return "0?  "; // BA=00
    case 1:  return "_X_ "; // BA=01 (straight)
    case 2:  return ")(  "; // BA=10 (curved)
    case 3:  return "1?  "; // BA=11
    default: return ERR;    // ?? impossible
   } // END OF switch(iValue)
   break;
  case RC_TYPE_DT: // -------disconnectable track (Fahrstrom)---
   if(iValue != 0) return (String(T_ON)  + "    ").substring(0,4);
   return (String(T_OFF)  + "    ").substring(0,4);
   break;
  case RC_TYPE_DD: // -------double pole, double throw (2x UM)--
   if(iValue != 0) return "1-5 ";
   return "1-3 ";
   break;
  case RC_TYPE_UC: // -------uncoupler (Entkuppler)-------------
   if(iValue != 0) return (String(T_ON)  + "    ").substring(0,4);
   return (String(T_OFF)  + "    ").substring(0,4);
   break;
  case RC_TYPE_P2: // -------pulse 2 inputs (reset, set)--------
   switch(iValue) { 
    case 0: return "OCC "; // "=0= " BA=00
    case 1: return "FRE "; // "=1= " BA=01
    case 2: return " 0V "; // "=2= " BA=10
    case 3: return "00V "; // "=3= " BA=11
    default: return ERR;    // ?? impossible
   } // END OF switch(iValue)
   break;
  case RC_TYPE_BL: // -------blink light (Blinklicht)-----------
   if(iValue==CMD_BLINK) return "run ";
   return "--- ";
   break;
   default: break;
 }
 return "????";
}

//______________________________________________________________
/**
 * Fill the screen lines with current content
 *
 * @param iRcompGroup Group of components (max. 5 items) to be displayed
 * @see uses: aScreenText[], aRcomp[]
*/
void prepareScreenLine4to6(int iRcompGroup) {
 String s1="";                              // help string
 aScreenText[3]="";                         // clear line 4
 aScreenText[4]="";                         // clear line 5
 aScreenText[5]="";                         // clear line 6
 int iRcStart=5*iRcompGroup;                // RComp start index
 int imax=RCOMP_NUM-iRcStart;               // last element to show
 if(imax>5) imax = 5;                       // max. 5 elements
 //------for max. 5 elements------------------------------------
 for(int i=0; i<imax; i++) { // for max. 5 group elements
  int iRc=iRcStart+i;
  //-----railroad component name max. 3 chars + blank = 4 chars--
  aScreenText[3]+=(aRcomp[iRc].name.substring(0,3)+"    ").substring(0,4);
  int iValue=aRcmd[iRc].inValue;
  if(aRcomp[iRc].type==RC_TYPE_BL) iValue=aRcmd[iRc].iCmd;
  aScreenText[4]+=getSymbol4Line5(aRcomp[iRc].type, iValue);
  //-----dcc number of railroad element--------------------------
  aScreenText[5]+=(String(aRcomp[iRc].dcc)+"    ").substring(0,4);
 } // END OF for max. 5 elements
}

//______________________________________________________________
/**
 * Refresh the screen periodically to prevent damage
 *
 * @see uses: screen_, aScreenSign[], aScreenText[]
*/
void refreshScreen() {
 //------Clear screen-------------------------------------------
 screen_.screen15Clear(0,aScreenText[0],'c'); // centered title
 for(int i=1; i<SCREEN_LINE_MAX; i++) { 
  screen_.screen15(aScreenSign[i]*(i+1),aScreenText[i]);
 }
 //------Show screen--------------------------------------------
 screen_.sendBuffer();                      // show screen
}

//______________________________________________________________
/**
 * @brief Shows line 4 to 6 on OLED
 *
 * @see uses: screen_, aScreenSign[], aScreenText[]
*/
void showScreenLine4to6() {
 screen_.screen15(aScreenSign[3]*4,aScreenText[3]);
 screen_.screen15(aScreenSign[4]*5,aScreenText[4]);
 screen_.screen15(aScreenSign[5]*6,aScreenText[5]);
 //------Show screen--------------------------------------------
 screen_.sendBuffer();                      // show screen
}

//______________________________________________________________
/**
 * @brief Shows information on OLED at progam start.
 * 
 * The information is contained in the array `infolines[]` 
 * (file `rcc_demo2_text.h`).
 *
 * @see uses: INFOLINES_NUM, infolines[], showLine6WaitMaxXXs(),
 * screen15Clear(), screen15()
 */
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
  showLine6WaitMaxXXs(SHOW_INFOPAGE_SEC, infolines[iEndline-1]);
 } // END OF for all pages--------------------------------------
}

//______________________________________________________________
/**
 * 
 * @brief Displays line 6 for a maximum of iSec seconds. 
 *
 * You can stop the display by pressing the PIN_BUTTON. 
 *
 * @param iSec (Maximum) number of seconds for the display
 * @param line6 Line displaying the remaining seconds plus 
 * the previous content of line 6 (inverted)
 * @see uses: screen_, digitalRead()
*/
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

//______________________________________________________________
/**
 * @brief update display
 * 
 * If the status of a component changes (iRcomp_>=0), the 
 * display group for that component is determined and the value 
 * is displayed.
 * The system then checks whether it is time for a refresh and,
 * if so, performs the refresh.
 */
void loopUpdateDisplay(int iRcomp_, int32_t state, Statemachine &stm) {
 static int32_t stateNextScreenRefresh=1;
 static int32_t stateNextScreenMin=STATE_NONE;
 static int     iRcompGroupNow=-1;                // group shown now
 static int     iRcompGroupNext=DISPLAY_NO_GROUP; // next group

  //------(2.4) update display, if there was an input change-----
 if(iRcomp_>=0) { // yes, input changed
  //.....prepare display........................................
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
  if(iRcompGroupNext != DISPLAY_NO_GROUP) {
   prepareScreenLine4to6(iRcompGroupNext);
   refreshScreen();
   stateNextScreenRefresh=stm.add(STATES_SCREEN_REFRESH);
   stateNextScreenMin=stm.add(STATES_SHOW_SCREEN_MIN);
   iRcompGroupNow=iRcompGroupNext;
   iRcompGroupNext = DISPLAY_NO_GROUP;
  }
 } // END OF screen refresh allowed
 if(state >= stateNextScreenRefresh)
 { // .......standard screen refresh............................
  iRcompGroupNow++;
  if(5*iRcompGroupNow >= RCOMP_NUM) iRcompGroupNow=0;
  prepareScreenLine4to6(iRcompGroupNow);
  refreshScreen();
  iRcompGroupNext = DISPLAY_NO_GROUP;
  stateNextScreenRefresh=stm.add(STATES_SCREEN_REFRESH);
  stateNextScreenMin=stm.add(STATES_SHOW_SCREEN_MIN);
 } // END OF standard screen refresh

}
