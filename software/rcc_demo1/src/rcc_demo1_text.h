//_____rcc_demo1_text.h__________________________khartinger_____
// define text in English and German
#ifndef RCC_DEMO1_TEXT_H
 #define RCC_DEMO1_TEXT_H
 #include <Arduino.h>                  // String, int32_t
 //-----------(index of) connection states----------------------
 #define CON_UNKNOWN         0
 #define CON_CONNECTING      1
 #define CON_NO_WIFI         2
 #define CON_NO_MQTT         3
 #define CON_WIFI_OK         4
 #define CON_MQTT_OK         5
 #define CON_WIFI_NOT_USED   6

 //----status defines as string numbers-------------------------
 #define T1_UNDEF0           "-2"
 #define T1_UNDEF1           "-1"
 #define T1_STRIGHT          "1"
 #define T1_CURVED           "0"
 #define T1_UNKNOWN          "-9"
 #define T1_ON               "1"
 #define T1_OFF              "0"
 #define T1_NO_MQTT          "-8"
 #define T1_DPDT_0_NC        "13"
 #define T1_DPDT_1_NO        "15"

 #if LANGUAGE == 'd'
  // =========Deutsche Texte (German)===========================
  #define T_UNDEF0           "undefiniert_0?"
  #define T_UNDEF1           "undefiniert_1?"
  #define T_STRIGHT          "Gerade"
  #define T_CURVED           "Abzweig"
  #define T_UNKNOWN          "unmoeglich"
  #define T_ON               "Ein"
  #define T_OFF              "Aus"
  #define T_NO_MQTT          "Keine MQTT Steuerung!"
  const    String sConn[]={"-unknown--", "verbinden_", 
         "-No WiFi--", "-No MQTT--", "WiFi OK   ", "MQTT OK   ",
        "Ohne WiFi "};

// "---------|---------|-" line length = 21
  #define  INFOLINES_NUM     15
  #define  INFOLINES { \
   "Test von Eisenbahn-  ", \
   "Schaltbloecken mit   ", \
   "DCC - MQTT - Hand    ", \
   VERSION_99_1, \
   " Weiter: Taste IO19  ", \
   "DCC 11 Entkuppler    ", \
   "DCC 21 Zweiwegweiche ", \
   "DCC 31,32 3-Wegweiche", \
   "DCC 41 Fahrstrom 1/0 ", \
   " Weiter: Taste IO19  ", \
   "DCC 51 Blinklicht    ", \
   " ",\
   "Es folgt: IO-Expander", \
   " und Wifi-Suche      ", \
   " Weiter: Taste IO19  ", \
  }

 #else

  //==========English texts=====================================
  #ifndef LANGUAGE
   #define LANGUAGE          'e'
  #endif
  #define T_UNDEF0           "undefined_0?"
  #define T_UNDEF1           "undefined_1?"
  #define T_STRIGHT          "stright"
  #define T_CURVED           "curved"
  #define T_UNKNOWN          "impossible"
  #define T_ON               "On"
  #define T_OFF              "Off"
  #define T_NO_MQTT          "*No control via MQTT*"
  const    String sConn[]={"-unknown--", "connecting", 
         "-No WiFi--", "-No MQTT--", "WiFi OK   ", "MQTT OK   ",
        "Unused WiFi"};

// "---------|---------|-" line length = 21
  #define  INFOLINES_NUM     15
  #define  INFOLINES { \
   "Test of railway      ", \
   "switch blocks by     ", \
   "DCC - MQTT - Hand    ", \
   VERSION_99_1, \
   " Next: Button IO19   ", \
   "DCC 11 Uncoupler     ", \
   "DCC 21 2-Way-Turnout ", \
   "DCC 31,32 3wayTurnout", \
   "DCC 41 Disconn. Track", \
   " Next: Button IO19   ", \
   "DCC 51 Blink Light   ", \
   " ",\
   "Next up: IO-Expander ", \
   " and Wifi search     ", \
   " Next: Button IO19   ", \
  }
 #endif
 #endif