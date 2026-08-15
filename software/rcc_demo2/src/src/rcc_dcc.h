//_____rcc_dcc.h_________________________________khartinger_____

#pragma once

#include "dcc_config.h"                // strRcomp

//______________________________________________________________
/**
 * @brief Represents a DCC command.
 *
 * Contains the DCC address and the command value.
 * A value of -1 indicates that no valid command is available.
 */
struct DccCommand
{
    uint16_t address = 0;  ///< DCC address; 0 means no address assigned.
    int value = -1;        ///< Command value: -1 = invalid, 0 = OFF, 1 = ON.
};

 //______Declaration of functions for wifi + mqtt_______________
 void onAccessoryPacket(unsigned int linearDecoderAddress, bool enabled);
