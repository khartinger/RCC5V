//_____rcc_statemachine.h________________________khartinger_____

#pragma once

#include "src/statemachine/D1_class_Statemachine.h"

 //______________________________________________________________
//------- Duration of intervals in milliseconds ----------------
constexpr uint32_t STATE_TICK_MS      = 20;      // state delay in ms
constexpr uint32_t RESET_DELAY_MS     = 1000;    // press button 1 s
constexpr uint32_t SCREEN_REFRESH_MS  = 5200;    // refresh screen
constexpr uint32_t SHOW_SCREEN_MIN_MS = 1500;
constexpr uint32_t BLINK_MS           = 500;     // 0.5 s
//------- Duration of intervals in state steps ---------------------------
constexpr uint32_t STATE_MAX          = 3600000 / STATE_TICK_MS; // 1h
constexpr uint32_t STATES_SCREEN_REFRESH = SCREEN_REFRESH_MS / STATE_TICK_MS;
constexpr uint32_t STATES_SHOW_SCREEN_MIN = SHOW_SCREEN_MIN_MS / STATE_TICK_MS;
constexpr uint32_t STATES_BLINK = BLINK_MS / STATE_TICK_MS;
constexpr uint32_t STATES_BEFORE_RESET = RESET_DELAY_MS / STATE_TICK_MS;

//______Declaration of functions for statemachine_______________
