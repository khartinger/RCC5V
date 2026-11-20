//_____rcc_demo2_text.h_________________________khartinger_____
// define text in English and German
// Last Updated: 2026-11-20
#ifndef RCC_DEMO2_TEXT_H
 #define RCC_DEMO2_TEXT_H
 #include <Arduino.h>                  // String, int32_t
#ifndef LANGUAGE
 #define LANGUAGE            'd'
#endif

 //-----------(index of) connection states----------------------
 constexpr int  CON_UNKNOWN = 0;
 constexpr int  CON_CONNECTING = 1;
 constexpr int  CON_NO_WIFI = 2;
 constexpr int  CON_NO_MQTT = 3;
 constexpr int  CON_WIFI_OK = 4;
 constexpr int  CON_MQTT_OK = 5;
 constexpr int  CON_WIFI_NOT_USED = 6;

 //----status defines as string numbers-------------------------
 constexpr char T1_UNDEF0[]    = "-2";
 constexpr char T1_UNDEF1[]    = "-1";
 constexpr char T1_STRAIGHT[]  = "1";
 constexpr char T1_CURVED[]    = "0";
 constexpr char T1_UNKNOWN[]   = "-9";
 constexpr char T1_ON[]        = "1";
 constexpr char T1_OFF[]       = "0";
 constexpr char T1_NO_MQTT[]   = "-8";
 constexpr char T1_DPDT_0_NC[] = "13";
 constexpr char T1_DPDT_1_NO[] = "15";
 constexpr char T1_TRACK_OCC[] = "20";
 constexpr char T1_TRACK_FRE[] = "21";
 constexpr char T1_TRACK__0V[] = "22";
 constexpr char T1_TRACK_00V[] = "23";
 constexpr char T1_TRACK_RST[] = "30";
 constexpr char T1_TRACK_SET[] = "31";
 constexpr char T1_TRACK_ERR[] = "99";

 #if LANGUAGE == 'd'
  // =========Deutsche Texte (German)===========================
  #define T_UNDEF0           "undefiniert_0?"
  #define T_UNDEF1           "undefiniert_1?"
  #define T_STRAIGHT          "Gerade"
  #define T_CURVED           "Abzweig"
  #define T_UNKNOWN          "unmoeglich"
  #define T_ON               "Ein"
  #define T_OFF              "Aus"
  #define T_NO_MQTT          "Keine MQTT Steuerung!"
  const    String sConn[]={"-unknown--", "verbinden_", 
         "-No WiFi--", "-No MQTT--", "WiFi OK   ", "MQTT OK   ",
        "Ohne WiFi "};

  #define T_TRACK_OCC        "Gleis besetzt"
  #define T_TRACK_FRE        "Gleis frei"
  #define T_TRACK__0V        "Keine Fahrspannung"
  #define T_TRACK_00V        "Keine Fahrspannung"
  #define T_TRACK_ERR        "Fehler"
  #define T_TRACK_RST        "Puls Reset"
  #define T_TRACK_SET        "Puls Set"

  // "---------|---------|-" line length = 21
  #define  INFOLINES_NUM     15
  #define  INFOLINES { \
  "Test #2 von RCC-  1/3", \
  "Schaltbloecken mit   ", \
  "DCC - MQTT - Hand    ", \
  VERSION_99_1, \
  " Weiter: Taste IO19  ", \
  "DCC 61 Fahrspg IO TUI", \
  "DCC 71 Fahrspganzeige", \
  "DCC 81,82 Puls1      ", \
  "DCC 91 Puls2         ", \
  " Weiter: Taste IO19  ", \
  "                  3/3", \
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
  #define T_STRAIGHT          "straight"
  #define T_CURVED           "curved"
  #define T_UNKNOWN          "impossible"
  #define T_ON               "On"
  #define T_OFF              "Off"
  #define T_NO_MQTT          "*No control via MQTT*"
  const    String sConn[]={"-unknown--", "connecting", 
         "-No WiFi--", "-No MQTT--", "WiFi OK   ", "MQTT OK   ",
        "Unused WiFi"};

  #define T_TRACK_OCC        "track occupied"
  #define T_TRACK_FRE        "track free"
  #define T_TRACK__0V        "no voltage"
  #define T_TRACK_00V        "no voltage"
  #define T_TRACK_ERR        "Error"
  #define T_TRACK_RST        "Pulse Reset"
  #define T_TRACK_SET        "Pulse Set"

// "---------|---------|-" line length = 21
  #define  INFOLINES_NUM     15
  #define  INFOLINES { \
   "Test of railway   1/3", \
   "switch blocks by     ", \
   "DCC - MQTT - Hand    ", \
   VERSION_99_1, \
   " Next: Button IO19   ", \
   "DCC 61 track volts", \
   "DCC 71 V/I indicator", \
   "DCC 81,82 Pulse1", \
   "DCC 91 Pulse2", \
   " Next: Button IO19   ", \
   "                  3/3", \
   " ",\
   "Next up: IO-Expander ", \
   " and Wifi search     ", \
   " Next: Button IO19   ", \
  }

 #endif
 #endif