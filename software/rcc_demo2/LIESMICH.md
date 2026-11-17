<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>RCC Demo-Software Version 2</h1><b><big>Überblick über die Demo-Software zum Steuern von Modellbahn-Komponenten</big></b><br>  
Stand: 17.11.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>   

# 1. Einführung
Jedes Modellbahn-Modul besitzt einen eigenen **ESP32-Mikrocontroller** als zentrale Steuereinheit. Die **RCC-Demo-Software** bildet die Basis für diese Steuerung und lässt sich leicht an eigene Anforderungen anpassen.

Die Software `rcc_demo2` kann direkt mit der Hardware [Blocktester2](https://github.com/khartinger/RCC5V/blob/main/examples/blocktester2/LIESMICH.md) verwendet werden.

Diese Datei gibt einen Überblick über die RCC-Demo-Software. Weitere Informationen:  
- **[CUSTOMIZE_D.md](./CUSTOMIZE_D.md):** Anpassung der Software an eigene Anforderungen
- **[DETAILS_D.md](./DETAILS_D.md):** Technische Beschreibung der Software

<a name="TableOfContents"></a>   

## Inhaltsübersicht
* [1. Einführung](#x10)  
* [2. Kenntnisse über die Hardware](#x20)  
* [3. Software-Überblick](#x30)  
* [4. Software: Ergänzung eines Schaltblocks](#x40)   

## Unterstützte Steuerblöcke

Folgende Steuerblöcke können durch die Software angesteuert werden:   
1. Entkuppler   
2. Zweiwegweiche (mit Endabschaltung)   
3. Dreiwegweiche (mit Endabschaltung)   
4. Fahrstrom-Schalter   
5. Blinklicht   
6. Fahrstrom-Schalter mit Fahrstromerkennung  
7. Gleis-Spannung und Gleisstrom-Anzeige (UI)   
8. Pulserkennung, zweifach   
9. Pulserkennung mit zwei Eingängen (set, reset)   

Zum Verständnis der Software ist weiters eine grundsätzliche Kenntnis der Funktion der Hardware erforderlich.

<a name="x20"></a>   

# 2. Kenntnisse über die Hardware
Die Ansteuerung von Schaltblöcken durch den ESP32 erfolgt über I²C-Bus und I²C-PCF8574-I/O-Expander-Boards. Die Anzahl der Boards ist stets gerade, da immer  
* ein Board zur Ansteuerung der Komponenten (I2C-Adresse 0x20, IO-Expander #0) und   
* ein Board f&uuml;r die R&uuml;ckmeldesignale (I2C-Adresse 0x21, IO-Expander #1)   
verantwortlich ist.   

Die IO-Pins zur Ansteuerung und zur R&uuml;ckmeldung werden normalerweise auf die gleichen Pin-Nummern verdrahtet.  

Für die Software ist die Kenntnis der **Verdrahtung  zwischen Schaltbl&ouml;cken und I²C-I/O-Expandern** unbedingt erforderlich.  

## Beispiel Demo-Software 2
1. DCC 61, IO-Expander Pin 0,1: Fahrstromschalter (Schaltblock TUI)   
2. DCC 71, IO-Expander Pin 2,3: Fahrstromanzeige (Schaltblock UI)   
3. DCC 81,82, IO-Expander Pin 4,5: Impulsanzeige 2-fach (Schaltblock PULS1)   
4. DCC 91, IO-Expander Pin 6,7: Impulsanzeige Set/Reset (Schaltblock PULS2)   

![Blocktester2_i2c_Schaltplan](./images/480_BT2_i2c_circuit.png "Blocktester2_i2c_Schaltplan")   
_Bild 1: I²C-Verdrahtungsplan des Blocktesters #2_   



<a name="x30"></a>

# 3. Software-Überblick

## Funktionen der Software
* Ansteuerung von Schaltblöcken.  
* Anzeige des Schaltzustands der Komponenten auf einem 1,54"-OLED-Display.  
* Mit dem Taster am Pin IO19 (D6) kann man die einzelnen Seiten der Informationsanzeige oder das Suchen nach dem WLAN überspringen.  
* Dr&uuml;ckt man w&auml;hrend des Programmlaufs den Taster an IO19 f&uuml;r mehr als eine Sekunde, wird ein Reset ausgel&ouml;st. Dies kann zB dazu verwendet werden, um beim erneuten Hochfahren das WLAN zu aktivieren.  
* Empfang von DCC-Befehlen.  
* Empfang und Senden von MQTT-Nachrichten.  

Alle projektspezifischen Daten, wie WLAN-Zugang, MQTT-Befehle und Hardware-Eigenschaften, sind in einer Konfigurationsdatei `dcc_config.h` gespeichert.   

## Entwicklungsumgebung
Das Programm wird mit Visual Studio Code (VSC) und PlatformIO erstellt.  
Nach dem Komplieren in VSC wird das Programm in VSC auf den ESP32 übertragen.   



<a name="x40"></a>   

# 4. Software: Ergänzung eines Schaltblocks

Hier die Schritte zum Einbau einer neuen Komponente am Beispiel Pulserkennung mit zwei Eingängen (set, reset).   

## 1. Konfiguration anpassen `dcc_config.h`
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


# === ALT === ALT ===

## Konfigurationsdatei
Alle Definitionen, Konstanten, globale Variable und Objekte, die das Programm ben&ouml;tigt, werden entweder direkt in der cpp-Datei oder in einer Konfigurationsdatei definiert. Die Verteilung ist so gew&auml;hlt, dass projektspezifische Daten in der Konfigurationsdatei `dcc_config.h` stehen.   
Die Konfigurationsdatei enth&auml;lt folgende Abschnitte:   
* Netzwerk- und MQTT-Daten   
* Display-Daten   
* DCCex-Daten   
* IO-Expander PCF8574-Daten   
* Definition f&uuml;r Eisenbahn-Komponenten   
* die Eisenbahn-Komponenten selbst   
   
__Beispiel f&uuml;r eine Konfigurationsdatei:__   
```   
//_____dcc_config.h______________________________khartinger_____
// Configure file for ESP32 railroad DCC decoder
//
// Created by Karl Hartinger, April 02, 2024
// Changes:
// 2024-04-02 New
// Released into the public domain.

#ifndef DCC_CONFIG_H
 #define DCC_CONFIG_H
 #include <Arduino.h>                  // String, int32_t
 #include "src/pcf8574/D1_class_PCF8574.h"

//_______program version________________________________________
#define  VERSION_06     "2024-04-02 ESP32_06_cmd_turnout"
#define  VERSION_06_1   "Version 2024-04-02"

//_______Network and MQTT data__________________________________
#define  _USE_WIFI_     true
#define  _SSID_         "Raspi11"
#define  _PASS_         "12345678"
#define  _HOST_         "10.1.1.1"
#define  TOPIC_BASE     "turnout"
#define  TOPIC_GET      "?,help,version,ip,topicbase,eeprom"
#define  TOPIC_SET      "topicbase,eeprom0,byname,bydcc"
#define  TOPIC_SUB      ""
#define  TOPIC_PUB      ""

//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
#define  SCREEN_TITLE   "06_cmd_turnout"
#define  SCREEN_LINE_MAX 6
#define  SCREEN_LINE_LEN 21

//_______DCCex__________________________________________________
#define  DCC_OFFSET     4

//_______Hardware: IO expander PCF8574__________________________
#define  IOEX_NUM       2              // number of IO expander
PCF8574  pcf8574_out(0x20);            // 8 digital OUT
PCF8574  pcf8574_in (0x21);            // 8 digital IN
PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out, &pcf8574_in}; // IO expander

//_______Definitions for railroad components____________________
//.......values for every railroad component....................
// e.g. turnout, uncoupler, disconnectable track, ...
#define  NO_PIN         -1   // pin @ PCF8574 (0...7)
#define  RC_TYPE_TO     1    // turnout (Weiche)
#define  RC_TYPE_UC     2    // uncoupler (Entkuppler)
#define  RC_TYPE_DT     3    // disconnectable track (Fahrstrom)

//.......All properties of a railroad component.................
struct strRcomp {
  int    type;          // RC_TYPE_TO, RC_TYPE_UC, RC_TYPE_DT
  String name;          // short name like T1, U1, D1, W1, E1...
  int    dcc;           // dcc address of the component
  int    outPCF;        // aIOEx index of PCF8574 output device
  int    outBitA;       // bit PCF8574 for turnout straight (Gerade)
  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
  int    inPCF;         // aIOEx index of PCF8574 input device
  int    inBitA;        // bit number at PCF8574 input straight=1
  int    inBitB;        // bit number at PCF8574 input curved=1
};

//_______Railroad commands______________________________________
// railroad components:  type,name,dcc,
//                      pIOEx-out-index,outBitA,outBitB, 
//                      pIOEx-in-index inBitA inBitB
#define  RCOMP_1        RC_TYPE_TO,"T1",11, 0,0,1, 1,0,1
//.......Array of all railroad components........................
#define  RCOMP_MAX      1
strRcomp aRcomp[RCOMP_MAX] = {{RCOMP_1}};
#endif
```   

## Programmversion
Bei jeder &Auml;nderung am Programm sollte die Programmversion in der Konfigurationsdatei angepasst werden. `VERSION_06` sollte das Datum und den Dateinamen enthalten, `VERSION_06_1` den Text "Version" und das Datum.   
Der Inhalt von `VERSION_06` wird als Antwort auf eine MQTT-Nachricht   
`mosquitto_pub -h 10.1.1.1 -t turnout/get -m version`   
angezeigt.   
Der Inhalt von `VERSION_06_1` wird beim Start f&uuml;r eine Sekunde in der letzten Zeile des Displays angezeigt und sollte nicht l&auml;nger als 21 Zeichen (`SCREEN_LINE_LEN`) sein.   

## Netzwerk- und MQTT-Daten
Die Definition von `_USE_WIFI_` legt grunds&auml;tzlich fest, ob WLAN und MQTT verwendet werden sollen (`true` = ja). Die Definitionen von `_SSID_`, `_PASS_` und `_HOST_` stellen die Netzwerkdaten zur Verf&uuml;gung und m&uuml;ssen an das eigene Netzwerk angepasst werden:   
| Konstante  | Zweck                                                        |   
|------------|--------------------------------------------------------------|   
| `_SSID_`   | Name des Netzwerks, in das eingew&auml;hlt werden soll.           |   
| `_PASS_`   | Passwort des Netzwerks, in das eingew&auml;hlt werden soll.       |   
| `_HOST_`   | Name des Servers (oder IP-Adresse), bei dem eingew&auml;hlt werden soll.  |   

&nbsp;   
`TOPIC_BASE` ist das Basis-Topic f&uuml;r alle MQTT-Nachrichten an das Programm. Wird diese durch eine `set/topicbase`-Nachricht ge&auml;ndert, so wird immer das ge&auml;nderte Basis-Topic verwendet, da dieses dauerhaft im EEPROM gespeichert wird.   
Beim Start des ESP wird eine Nachricht mit dem Topic `info/start/mqtt` gesendet, das das verwendete Basis-Topic enth&auml;lt:   
`info/start/mqtt {"topicbase":"modul1","IP":"10.1.1.185"}`   
Weiters wird das Basis-Topic in der 3. Zeile des Displays angezeigt.   

Bedeutung der weiteren Definitionen:   
| Konstante  | Zweck                                                        |   
|------------|--------------------------------------------------------------|   
| `TOPIC_GET`  | Alle m&ouml;glichen get-Anfragen (durch Beistriche getrennt).  |   
| `TOPIC_SET`  | Alle m&ouml;glichen get-Anfragen (durch Beistriche getrennt).  |   
| `TOPIC_SUB`  | Topics, die ebenfalls empfangen werden sollen (ohne Ber&uuml;cksichtigung des Basis-Topics).  |   
| `TOPIC_PUB`  | Topics unter denen publiziert werden soll (ohne Ber&uuml;cksichtigung des Basis-Topics).  |   

## Hardware-Pins
Die Pins f&uuml;r den DCC-Eingang (18 = D5) und den Taster (19 = D6) werden in der cpp-Datei definiert und k&ouml;nnen - falls erforderlich - dort ge&auml;ndert werden.   

## Anzeige auf der seriellen Schnittstelle
Ist der Debug-Modus eingeschaltet (`#define DEBUG_06 true`) wird im seriellen Monitor der Zustand jedes States angezeigt:   
* state Nummer   
* Zeitdauer f&uuml;r die Arbeiten in diesem State    
Zus&auml;tzlich zu diesen Informationen werden weitere Meldungen ausgeben, falls sie auftreten:   
* Ankommende DCC-Befehle   
* Freigabe der Weichensteuerung (beide Pins wieder auf 1)   

## Statemachine
Wird die maximale Zeit f&uuml;r einen State &uuml;berschritten, so wird diese Zeit in den nachfolgenden States aufgeholt (aber nicht mehr als maximal 100 kurze States).   
In der cpp-Datei wird f&uuml;r die State-Maschine eine Z&auml;hlschleifenzeit von einer Stunde mit 20 ms pro Schritt festgelegt und kann bei Bedarf auch ge&auml;ndert werden.   

## OLED-Display
Die Ausgabe auf das Display erfolgt mit der Bibliothek [u8g2](https://github.com/olikraus/u8g2). Aufbauend auf diese Software ist die Klasse `Screen154` f&uuml;r eine Textausgabe in Zeilen zust&auml;ndig, sodass man sich um die Pixeladdressierung nicht k&uuml;mmern muss. Es wird der Bildschirm `screen15` verwendet, der einen Titel und 5 weitere Textzeilen zur Verf&uuml;gung stellt.   
In der Konfigurationsdatei werden der Titel (`SCREEN_TITLE`), die Anzahl der Zeilen (`SCREEN_LINE_MAX`) und der Zeichen pro Zeile (`SCREEN_LINE_LEN`) definiert.   

## DCC und DCCex Eigenschaften
Je nach verwendeten Komponenten kann es sein, dass DCC-Adressen unterschiedlich dekodiert werden. Dieser Offset kann mit der Konstanten `DCC_OFFSET` angepasst werden, wobei der Wert &uuml;blicherweise entweder 4 oder 0 sein kann.   

## PCF8574 Boards
Der Zugriff auf die I²C-Erweiterungsboards mit PCF8574 erfolgt mit Hilfe der Klasse `PCF8574`. F&uuml;r jedes verwendete Board muss in der Konfiguratinosdatei ein Objekt angelegt werden, dem im Konstruktor die I²C-Adresse &uuml;bergeben wird. Die einzelnen Objekte werden dann in einem Feld `*pIOEX[]` abgelegt, damit man sie - unabh&auml;ngig vom Namen - per Index durchlaufen kann.   
Die Anzahl der Boards muss extra mit `#define  IOEX_NUM       2` definiert werden. (Im Beispiel werden 2 Boards verwendet.)   

## Eisenbahnkomponenten
Die Eigenschaften jeder Eisenbahnkomponente (Weiche, Entkuppler, abschaltbares Gleis) werden als Struktur `strRcomp` definiert. F&uuml;r jede Komponente werden die Werte in einer `#define`-Anweisung festgelegt. Alle Komponenten werden in einem Feld `aRcomp[]` abgelegt.   
Die Anzahl der Komponenten muss extra mit `#define  RCOMP_NUM      1` definiert werden. (Im Beispiel wird eine Komponente - die Weiche T1 - verwendet.)   

[Zum Seitenanfang](#up)
