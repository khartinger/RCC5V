//_____rcc_module13_text.h__________________________khartinger_____
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
   "Modul 13:            ", \
   "Kehrschleife West    ", \
   "mit Abstellgleis     ", \
   VERSION_13_1, \
   " Weiter: Taste IO19  ", \
   "DCC 131,132 Dreiweg- ", \
   "    Weiche Einfahrt  ", \
   "DCC 133 Fahrstrom 1/0", \
   "DCC 134 Entkuppler   ", \
   " Weiter: Taste IO19  ", \
   " ",\
   "Es folgt: IO-Expander", \
   " und Wifi-Suche      ", \
   " ",\
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
   "Module 13:           ", \
   "West reversing loop  ", \
   "with siding          ", \
   VERSION_13_1, \
   " Next: Button IO19   ", \
   "DCC 131,132 3-Way-   ", \
   "    Turnout Entrance ", \
   "DCC 133 Disconn.Track", \
   "DCC 134 Uncoupler    ", \
   " Next: Button IO19   ", \
   " ",\
   "Next up: IO-Expander ", \
   " and Wifi search     ", \
   " ",\
   " Next: Button IO19   ", \
  }

 #endif
#endif