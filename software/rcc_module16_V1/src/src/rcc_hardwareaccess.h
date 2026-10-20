//_____rcc_hardwareaccess.h______________________khartinger_____

#pragma once

#include "dcc_config.h"                          // strRcomp
#include "src/pcf8574/D1_class_PCF8574.h"        // PCF8574
#include "src/simplemqtt/D1_class_SimpleMqtt.h"  // SimpleMqtt
#include "src/screen154/D1_class_Screen154.h"    // Screen154
#include "rcc_statemachine.h"                    // STATES_BEFORE_RESET

extern void showLine(int line_, String text_);   // rcc_display

//______________________________________________________________
/**
 * @brief Global ESP32 hardware values
 * 
 */
 #define PIN_DCC        18             // 18=D5
 #define PIN_BUTTON     19             // 19=D6

//______Declaration of functions with hardware access___________
void initHardwareAccess1(Screen154 &screen_);
void initHardwareAccess2(Screen154 &screen_);
int updateInputValues();
String actOnRcmdHardware(int iCmd_, int iOutPCF_, int outBitA_, int outBitB_, int more_);
void initAllIOExpander();
void loopResetHandling(String &sSerial);
