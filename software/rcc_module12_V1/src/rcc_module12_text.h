//_____rcc_module12_V1_text.h____________________khartinger_____
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
  #define  INFOLINES_NUM     20
  #define  INFOLINES { \
   "Modul 12:            ", \
   "Ausweichstelle und   ", \
   "Abstellgleis         ", \
   VERSION_99_1, \
   " Weiter: Taste IO19  ", \
   \
   "DCC-Adressen      1/3", \
   "121 3-Wegweiche Links", \
   "122 3-Wegweiche Recht", \
   "123 Weiche Gleis 1A  ", \
   " Weiter: Taste IO19  ", \
   \
   "DCC-Adressen      2/3", \
   "124 Entkuppler Gleis3", \
   "125 Fahrstrom Gleis 1", \
   "126 Fahrstrom Gleis 2", \
   " Weiter: Taste IO19  ", \
   \
   "DCC-Adressen      3/3", \
   "127 Fahrstrom Gleis 3", \
   "128 Weiche W2 Ost   ", \
   "129 Fahrstrom Gleis1A", \
   " Weiter: Taste IO19  " \
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

 #define  INFOLINES_NUM     20
  #define  INFOLINES { \
   "Module 12:           ", \
   "passing siding and   ", \
   "siding               ", \
   VERSION_99_1, \
   " Next: Button IO19   ", \
   \
   "DCC-Addresses     1/3", \
   "121 3way-Turnout left", \
   "122 3way-Turnout righ", \
   "123 Turnout Track 1A ", \
   " Next: Button IO19   ", \
   \
   "DCC-Addresses     2/3", \
   "124 Uncoupler Track 3", \
   "125 Current Track 1  ", \
   "126 Current Track 2  ", \
   " Next: Button IO19   ", \
   \
   "DCC-Addresses     3/3", \
   "127 Current Track 3  ", \
   "128 Turnout W2 East  ", \
   "129 Current Track 1A ", \
   " Next: Button IO19   ", \
   }
  }
 #endif
#endif