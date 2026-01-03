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
 #define T_UNDEF0           "-2"
 #define T_UNDEF1           "-1"
 #define T_STRIGHT          "1"
 #define T_CURVED           "0"
 #define T_UNKNOWN          "-9"
 #define T_ON               "1"
 #define T_OFF              "0"
 #define T_NO_MQTT          "-8"

 #if LANGUAGE == 'd'
  // =========Deutsche Texte (German)===========================
  #define TT_UNDEF0          "undefiniert_0?"
  #define TT_UNDEF1          "undefiniert_1?"
  #define TT_STRIGHT         "Gerade"
  #define TT_CURVED          "Abzweig"
  #define TT_UNKNOWN         "unmoeglich"
  #define TT_ON              "Ein"
  #define TT_OFF             "Aus"
  #define TT_NO_MQTT         "Keine MQTT Steuerung!"
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
  #define TT_UNDEF0          "undefined_0?"
  #define TT_UNDEF1          "undefined_1?"
  #define TT_STRIGHT         "stright"
  #define TT_CURVED          "curved"
  #define TT_UNKNOWN         "impossible"
  #define TT_ON              "On"
  #define TT_OFF             "Off"
  #define TT_NO_MQTT         "*No control via MQTT*"
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