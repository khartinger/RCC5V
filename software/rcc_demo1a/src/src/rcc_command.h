//_____rcc_command.h_____________________________khartinger_____

#pragma once

#include "dcc_config.h"                // strRcomp
#include "rcc_hardwareaccess.h"        // actOnRcmdHardware
#include "rcc_statemachine.h"          // STATE_TICK_MS;

 //______Declaration of functions to edit/execute commands______
String setRcmd(int iRcomp, int iCmdValue, String sReturn);
String loopActOnRcmd(int32_t state, Statemachine &stm);
void loopRcmdReplaceStateNow(int32_t state, Statemachine &stm);