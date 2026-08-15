//_____rcc_mqtt.h________________________________khartinger_____

#pragma once

 #include "dcc_config.h"                         // strRcomp
 #include "rcc_demo1a_text.h"                    // T1_ON,...
 #include "rcc_hardwareaccess.h"                 // PIN_BUTTON
 #include "src/simplemqtt/D1_class_SimpleMqtt.h" // SimpleMqtt
 #include "src/screen154/D1_class_Screen154.h"   // Screen154

//______Declaration of functions for wifi + mqtt_______________
bool   initRccWiFi(Screen154 &screen_);
bool   isValidIPv4(const String &ip);
bool   validateWlanString(const String &s);

String simpleGet(String sPayload);
String simpleSet(String sTopic, String sPayload);
void simpleSub(String sTopic, String sPayload);

void loopMqtt(String &sSerial);

String getValueForComp(strRcomp Rcomp_, strRcmd Rcmd_, bool byName);
void addJson(String &sJson, const String &sKey, const String &sValue);
String jsonEscape(const String &s);