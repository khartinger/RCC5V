//_____dcc_config.cpp____________________________khartinger_____
// This file generates the objects that were declared or 
// defined in the dcc_config.h file.

#include "dcc_config.h"

//______________________________________________________________
/**
 * @brief Array of all current railroad commands
 * 
 * As there should only be one active command for one 
 * component, aRcomp[] and aRcmd[] have the same size and the 
 * same index for a command.
 */
strRcmd aRcmd[RCOMP_NUM];

//______________________________________________________________
/**
 * @brief Generates the unique railroad components array
 */
strRcomp aRcomp[RCOMP_NUM] = { RCOMP_LIST };

//______________________________________________________________
/**
 * @brief Generates the unique io expander PCF8574 array
 */
 #if IOEX_NUM != 2 && IOEX_NUM != 4 && IOEX_NUM != 6 && IOEX_NUM != 8
  #error "IOEX_NUM must be 2, 4, 6 or 8"
 #endif
 #if IOEX_NUM == 2
  // ......for 2 pcf8574 boards.(IOEX_NUM must be 2)............
  PCF8574  pcf8574_out1(1,IOEX_ADDRESS1,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_1(1,IOEX_ADDRESS2,0xFF); // 8 digital IN
  PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out1, &pcf8574_in_1}; // IO expander
 #elif IOEX_NUM == 4
  // ......for 4 pcf8574 boards (IOEX_NUM must be 4)............
  PCF8574  pcf8574_out1(1,IOEX_ADDRESS1,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_1(1,IOEX_ADDRESS2,0xFF); // 8 digital IN
  PCF8574  pcf8574_out2(1,IOEX_ADDRESS3,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_2(1,IOEX_ADDRESS4,0xFF); // 8 digital IN
  PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out1, &pcf8574_in_1, 
   &pcf8574_out2, &pcf8574_in_2};
 #elif IOEX_NUM == 6
  // ......for 6 pcf8574 boards (IOEX_NUM must be 6)............
  PCF8574  pcf8574_out1(1,IOEX_ADDRESS1,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_1(1,IOEX_ADDRESS2,0xFF); // 8 digital IN
  PCF8574  pcf8574_out2(1,IOEX_ADDRESS3,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_2(1,IOEX_ADDRESS4,0xFF); // 8 digital IN
  PCF8574  pcf8574_out3(1,IOEX_ADDRESS5,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_3(1,IOEX_ADDRESS6,0xFF); // 8 digital IN
  PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out1, &pcf8574_in_1,
   &pcf8574_out2, &pcf8574_in_2, &pcf8574_out3, &pcf8574_in_3};
 #elif IOEX_NUM == 8
  // ......for 8 pcf8574 boards (IOEX_NUM must be 8)............
  PCF8574  pcf8574_out1(1,IOEX_ADDRESS1,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_1(1,IOEX_ADDRESS2,0xFF); // 8 digital IN
  PCF8574  pcf8574_out2(1,IOEX_ADDRESS3,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_2(1,IOEX_ADDRESS4,0xFF); // 8 digital IN
  PCF8574  pcf8574_out3(1,IOEX_ADDRESS5,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_3(1,IOEX_ADDRESS6,0xFF); // 8 digital IN
  PCF8574  pcf8574_out4(1,IOEX_ADDRESS7,0xFF); // 8 digital OUT
  PCF8574  pcf8574_in_4(1,IOEX_ADDRESS8,0xFF); // 8 digital IN
  PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out1, &pcf8574_in_1,
   &pcf8574_out2, &pcf8574_in_2, &pcf8574_out3, &pcf8574_in_3,
   &pcf8574_out4, &pcf8574_in_4};

 #endif