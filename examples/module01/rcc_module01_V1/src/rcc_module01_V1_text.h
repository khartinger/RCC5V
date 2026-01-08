//_____rcc_module01_V1_text.h____________________khartinger_____
// define text in English and German
#ifndef RCC_MODULE01_TEXT_H
 #define RCC_MODULE01_TEXT_H
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
  #define  INFOLINES_NUM     5
  #define  INFOLINES { \
   "Gleis 2 auf 1, Ladegl", \
   "DCC 11 Fahrstrom 1/0 ", \
   "DCC 12 Zweiwegweiche ", \
   VERSION_99_1, \
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
  #define  INFOLINES_NUM     5
  #define  INFOLINES { \
   "Track 2 to 1 + Loading", \
    "DCC 11 Disconn. Track", \
   "DCC 12 2-Way-Turnout ", \
   VERSION_99_1, \
   " Next: Button IO19   ", \
  }

 #endif
#endif