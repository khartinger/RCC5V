//_____rcc_display.h_____________________________khartinger_____

#pragma once

#include "dcc_config.h"                          // strRcomp
#include "rcc_demo1a_text.h"                     // T_ON,..
#include "rcc_hardwareaccess.h"                  // PIN_BUTTON
#include "rcc_statemachine.h"                    // STATES_SCREEN_..
#include "src/screen154/D1_class_Screen154.h"    // Screen154

#define  DISPLAY_NO_GROUP    -1                  // no group to show

//______Declaration of functions for display____________________
void initDisplay1();
void showLine(int line_, String text_);
String getSymbol4Line5(int iType, int iValue);
void prepareScreenLine4to6(int iRcompGroup);
void refreshScreen();
void showScreenLine4to6();
void showInfolines();
void showLine6WaitMaxXXs(int iSec, String line6);

void loopUpdateDisplay(int iRcomp_, int32_t state, Statemachine &stm);
