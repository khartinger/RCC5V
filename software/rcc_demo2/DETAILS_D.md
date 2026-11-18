<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Das Demo-Programm rcc_demo2 im Detail</h1><b><big>Details zur Demo-Software zum Steuern von Modellbahn-Komponenten</big></b><br>  
Stand: 18.11.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>   

# 1. Übersicht über `rcc_demo2`
Der Quellcode des Demo-Programms `rcc_demo2` ist modular aufgebaut und besteht aus vielen Dateien:  

![Software demo2 overview](/images/480_sw_demo2_overview.png "Software demo2 overview")  

__*Beachte*__: Bei einem Standard-Projekt ohne spezielle Features müssen lediglich die beiden Konfigurationsdateien `rcc_config.h` und `rcc_demo2_text.h` angepasst werden. 

### Die Verzeichnisse und Dateien im Detail  
| Datei | Inhalt |  
| ----- | ------ |  
| `src/rcc_demo2.cpp` | Hauptprogramm mit `setup()` und `loop()` |  
| `src/rcc_demo2_text.cpp` | Texte in Deutsch und Englisch wie Startbildschirmtexte etc. |  
| `src/rcc_config.h` | Definitionen und Konstante wie DEBUG, VERSION, Netzwerkdaten, MQTT-Befehle, Expander-Adressen, Railroad-Komponenten, ... |  
| `src/pre_config.h` | Expander-Namen und Pin-Namen |  
| `src/src/rcc_config.cpp` | Objekte zu den Deklarationen in `rcc_config.h` |  
| `src/src/rcc_command` (.ccp\|.h) | Funktionen für Kommandos zu den Railroad-Komponenten |  
| `src/src/rcc_dcc` (.ccp\|.h) | Funktion zum Empfang von DCC-Nachrichten. Diese basiert auf der externen Bibliothek `lib_deps = https://github.com/enginorama/DccAccessoryDecoder` (siehe Datei `platformio.ini`). |  
| `src/src/rcc_display` (.ccp\|.h) | Funktionen zur Darstellung von Information auf der OLED-Anzeige |  
| `src/src/rcc_hardwareaccess` (.ccp\|.h) | Funktionen für den Hardware-Zugriff |  
| `src/src/rcc_mqtt` (.ccp\|.h) | Funktionen für MQTT-Nachrichten und JSON |  
| `src/src/rcc_statemachine` (.ccp\|.h) | Konstante und Objekt für die State-Maschine |  
| `src/src/cppsrc` (.ccp\|.h) | Zeichendateien (Grafikbibliothek) |  
| `src/src/csrc` (.ccp\|.h) | Zeichendateien (Grafikbibliothek) |  
| `src/src/pcf8574` (.ccp\|.h) | Klasse PCF8574 |  
| `src/src/screen154` (.ccp\|.h) | Klasse Screen154 |  
| `src/src/simplemqtt` (.ccp\|.h) | Klasse SimpleMqtt und PubSubClient |  
| `src/src/statemachine` (.ccp\|.h) | Klasse Statemachine |  

<a name="x05"></a>   
<a name="TableOfContents"></a>   

## Inhaltsübersicht
* [1. Übersicht über rcc_demo2](#x10)  
* [2. Konfiguration](#x20)  
* [3. Statemaschine](#x30)  
* [4. DCC-Befehle](#x40)  
* [5. RCC-Kommandos](#x50)  
* [6. Hardware-Zugriff](#x60)  
* [7. OLED-Anzeige](#x70)  
* [8. MQTT-Befehle](#x80)  
* [9. Beispiel: Ergänzung eines Schaltblocks](#x90)  

<a name="x20"></a>   

# 2. Konfiguration

<a name="x30"></a>   

# 3. Statemaschine

<a name="x40"></a>   

# 4. DCC-Befehle

<a name="x50"></a>   

# 5. RCC-Kommandos

<a name="x60"></a>   

# 6. Hardware-Zugriff

<a name="x70"></a>   

# 7. OLED-Anzeige

<a name="x80"></a>   

# 8. MQTT-Befehle

<a name="x90"></a>   

# 9. Beispiel: Ergänzung eines Schaltblocks

Hier die Schritte zum Einbau einer neuen Komponente am Beispiel Pulserkennung mit zwei Eingängen (set, reset).   

## 1. Konfiguration anpassen `rcc_config.h`
* Version, `_ESP_NAME_`, `TOPIC_BASE[]` anpassen.
* IO-Expander-Zahl erhöhen  
`#define  IOEX_NUM       4         // number of IO expander 2|4|6|8`
* __Typ des neuen Blocks definieren__  
`constexpr int  RC_TYPE_P2 = 7;    // pulse 2 inputs (reset, set)`
* Hardware-Komponente definieren, zB  
```
// ------pulse with 2 inputs (reset, set)-----------------------
// Two expander pins B | A for set | reset (active low!)
// Pulse duration: 200 ms
#define  RCOMP_6        RC_TYPE_P2,"P2", 61, EX2,PIN0,PIN1,   EX3,PIN0,PIN1, 200,0
```
* Komponenten-Array vorbereiten (zB Zweiwegweiche + Pulserkennung)  
```
//.......Preparing the Array of all railroad components..........
#define  RCOMP_NUM  2
#define  RCOMP_LIST {RCOMP_2},{RCOMP_6}
```

## 2. Texte definieren `rcc_demo2_text.h`
### 2.1 Text-Konstante
Deutsche Texte   
```  
  #define T_TRACK_OCC        "Gleis besetzt"
  #define T_TRACK_FRE        "Gleis frei"
  #define T_TRACK__0V        "Keine Fahrspannung"
  #define T_TRACK_00V        "Keine Fahrspannung"
```  

Englische Texte
```  
  #define T_TRACK_OCC        "track occupied"
  #define T_TRACK_FRE        "track free"
  #define T_TRACK__0V        "no voltage"
  #define T_TRACK_00V        "no voltage"
```  

Status Definitionen als String-Nummern:  
```
 constexpr char T1_TRACK_OCC[] = "0";
 constexpr char T1_TRACK_FRE[] = "1";
 constexpr char T1_TRACK__0V[] = "2";
 constexpr char T1_TRACK_00V[] = "3";
```


### 2.2 Infotext anpassen
Deutsch   
```  
  #define  INFOLINES_NUM     10
  #define  INFOLINES { \
  "Test von RCC-     1/2", \
  "Schaltbloecken mit   ", \
  "DCC - MQTT - Hand    ", \
  VERSION_99_1, \
  " Weiter: Taste IO19  ", \
  "DCC 21 2-Weg-Weiche  ", \
  "DCC 61 Puls2         ",\
  "Es folgt: IO-Expander", \
  " und Wifi-Suche      ", \
  " Weiter: Taste IO19  ", \
  }
```  

Englisch   
```  
  #define  INFOLINES_NUM     10
  #define  INFOLINES { \
   "Test of railway      ", \
   "switch blocks by     ", \
   "DCC - MQTT - Hand    ", \
   VERSION_99_1, \
   " Next: Button IO19   ", \
   "DCC 21 2-Way-Turnout ", \
   "DCC 61 Puls2         ", \
   "Next up: IO-Expander ", \
   " and Wifi search     ", \
   " Next: Button IO19   ", \
  }
```  

## 3. P2-Befehl einbauen `rcc_command.cpp`
```  
 if(aRcomp[iRcomp].type==RC_TYPE_P2) {
  //...it is a pulse 2 command (2 bits, 2 cmd)..................
  if(iCmdValue==0) { // 0 = reset = LED green . . . . . . . . . 
   aRcmd[iRcomp].stateToDo=STATE_NOW;
   aRcmd[iRcomp].iCmd=CMD_BIT_BA_10;             //  reset
   aRcmd[iRcomp].stateOffset==aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1; // after some time
   aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;     // ready for next pulse
   return sReturn+String(" received");
  } else 
  {
   if(iCmdValue==1) { // 1 = set = LED yellow . . . . . . . . . 
    aRcmd[iRcomp].stateToDo=STATE_NOW;
    aRcmd[iRcomp].iCmd=CMD_BIT_BA_01;            // set
    aRcmd[iRcomp].stateOffset==aRcomp[iRcomp].msOn/static_cast<int32_t>(STATE_TICK_MS);
   if(aRcmd[iRcomp].stateOffset<1) aRcmd[iRcomp].stateOffset=1; // after some time
    aRcmd[iRcomp].iCmdOffset=CMD_BIT_BA_11;    // ready for next pulse
    return sReturn+String(" received");
   }
  }
 } // END OF it is a turnout command (2 bits, 2cmds)............
```  

## 4. Textgrafik-Symbol `rcc_display.cpp`
```
  case RC_TYPE_P2: // -------pulse 2 inputs (reset, set)--------
   switch(iValue) { 
    case 0: return "OCC "; // "=0= " BA=00
    case 1: return "FRE "; // "=1= " BA=01
    case 2: return " 0V "; // "=2= " BA=10
    case 3: return "00V "; // "=3= " BA=11
    default: return ERR;    // ?? impossible
   } // END OF switch(iValue)
   break;
```

## 5. GET-Command `rcc_mqtt.cpp`
In der Funktion `getValueForComp(...)`   
```  
 if(Rcomp_.type==RC_TYPE_P2) {
  switch(Rcmd_.inValue) {
   case 0:  return byName ? T_TRACK_OCC : T1_TRACK_OCC; // BA=00
   case 1:  return byName ? T_TRACK_FRE : T1_TRACK_FRE; // BA=01
   case 2:  return byName ? T_TRACK__0V : T1_TRACK__0V; // BA=10
   case 3:  return byName ? T_TRACK_00V : T1_TRACK_00V; // BA=11
   default: return byName ? T_UNKNOWN : T1_UNKNOWN; // ?? impossible
  }
 }
```  

## 5. SET-Command `rcc_mqtt.cpp`
In der Funktion `simpleSet(...)`   
```  
 { //.......NOT a turnout command..............................
    if(aRcomp[i].type==RC_TYPE_P2)
    { //......specifically for command type PULSE 2.............
      if(sPayload=="0" || sPayload == "rst" || sPayload == "reset"
         || sPayload == "fre" || sPayload == "green") iCmdValue=0;
      if(sPayload=="1" || sPayload == "set"
         || sPayload == "occ" || sPayload == "yellow") iCmdValue=1;
    }
    else
    { //......for all other command types.......................
     if(sPayload=="0") iCmdValue=0;
     if(sPayload=="1") iCmdValue=1;
    }
```  



[Zum Seitenanfang](#up)
