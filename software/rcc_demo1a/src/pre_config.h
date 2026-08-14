//_____pre_config.h______________________________khartinger_____
// Define file for ESP32 railroad DCC decoder programs
// This constants are defined to make the hardware definition
// easier to read
// Created by Karl Hartinger, October 31, 2024
// Changes:
// 2026-08-14 replace #define by constexpr int
// Released into the public domain.

#ifndef PRE_CONFIG_H
 #define PRE_CONFIG_H
 // -------Expander "names"-------------------------------------
 constexpr int  EX0  = 0;    // IO-Expander Address offset 0
 constexpr int  EX1  = 1;    // IO-Expander Address offset 1
 constexpr int  EX2  = 2;    // IO-Expander Address offset 2
 constexpr int  EX3  = 3;    // IO-Expander Address offset 3
 constexpr int  EX4  = 4;    // IO-Expander Address offset 4
 constexpr int  EX5  = 5;    // IO-Expander Address offset 5
 constexpr int  EX6  = 6;    // IO-Expander Address offset 6
 constexpr int  EX7  = 7;    // IO-Expander Address offset 7
 //------pin number as "name"-----------------------------------
 constexpr int  PIN0 = 0;    // IO-Expander Pin 0
 constexpr int  PIN1 = 1;    // IO-Expander Pin 1
 constexpr int  PIN2 = 2;    // IO-Expander Pin 2
 constexpr int  PIN3 = 3;    // IO-Expander Pin 3
 constexpr int  PIN4 = 4;    // IO-Expander Pin 4
 constexpr int  PIN5 = 5;    // IO-Expander Pin 5
 constexpr int  PIN6 = 6;    // IO-Expander Pin 6
 constexpr int  PIN7 = 7;    // IO-Expander Pin 7
 
#endif