<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 5.1.2025 <a name="up"></a><br>   
<h1>&Uuml;berblick &uuml;ber die Demo-Software zum Steuern von Modellbahn-Komponenten mit DCC, MQTT und manuell</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Ziel
Dieses Programm f&uuml;r einen ESP32 dient zum Testen von verschiedenen, selbst gebauten Modelleisenbahn-Schaltbl&ouml;cken. Die Bl&ouml;cke werden &uuml;ber die I/O-Pins zweier I²C-PCF8574-I/O-Expander angesteuert, wobei der PCF8574 mit der I2C-Adresse 0x20 (IO-Expander #0) zur Ansteuerung und der PCF8574 mit der I2C-Adresse 0x21 (IO-Expander #1) f&uuml;r die R&uuml;ckmeldung dient. Die IO-Pins zur Ansteuerung und zur R&uuml;ckmeldung haben jeweils die gleiche Pin-Nummer.   

Folgende Bl&ouml;cke sind in der Software definiert:  
1. DCC 11, IO-Expander Pin 0: Entkuppler   
2. DCC 21, IO-Expander Pin 1,2: Zweiwegweiche (mit Endabschaltung)   
3. DCC 31,32, IO-Expander Pin 3,4,5: Dreiwegweiche (mit Endabschaltung)   
4. DCC 41, IO-Expander Pin 6: Fahrstrom   
5. DCC 51, IO-Expander Pin 7: Blinklicht   

Der Schaltzustand der Komponenten wird auf einem 1,54"-OLED-Display angezeigt.   

Mit Hilfe eines Tasters am Pin IO19 (D6) kann man die einzelnen Seiten der Informationsanzeige oder das Suchen nach dem WLAN &uuml;berspringen.   

Dr&uuml;ckt man w&auml;hrend des Programmlaufs den Taster an IO19 f&uuml;r eine Sekunde, wird ein Reset ausgel&ouml;st. Dies kann zB dazu verwendet werden, um beim erneuten Hochfahren das WLAN zu aktivieren.   

Alle projektspezifischen Daten, wie WLAN-Zugang, MQTT-Befehle und Hardware-Eigenschaften, werden in einer Konfigurationsdatei `dcc_config.h` gespeichert.   

# Erforderliche Hardware
## Elektronische Bauteile   
1. ESP32 D1 mini   
2. 1x Selbstbau-Board "Shield_I2C_5V_3V3": Anschluss f&uuml;r die beiden I2C-Busse   
3. 1x Selbstbau-Board "Shield_5V_DCC_6pol": Stromversorgung mit 5V, DCC-Signal und Anschluss f&uuml;r Taster an Pin D6 (IO19)   
4. 1x OLED-Display mit SSD1309 controller (zB 1,54" oder 2,4" Display mit 128x64 Pixel Aufl&ouml;sung)   
5. 2x I²C-Expander-Boards PCF8574 mit den (7-Bit-)Adressen 0x20 und 0x21   
6. Taster am Pin D6 (IO19) mit Pullup-Widerstand (zB 10 kOhm) nach 3,3V (oder ein Draht)   

## Elektrische Bauteile
Die ben&ouml;tigten elektrischen Bauteile sind abh&auml;ngig davon, was man testen will.    
__Beispiel Zweiwegweiche:__   
1. Eine Zweiweg-Weiche mit Endabschaltung   
2. Selbstbau-Block "RW_5V_W2" bestehend aus den beiden Platinen `RW_5V_W2_STRG` und `RW_5V_W2_LED` und den LEDs zur Ansteuerung der Weiche mit 5V   
3. Ein Trafo mit 16V Wechselspannung (V+, V-)   
4. Eine 5V-Stromversorgung   
5. Eine DCC-Quelle zum Senden von Weichenbefehlen (zB Roco MultiMAUS mit Digitalverst&auml;rker 10764 und Netzteil 10850)   
6. Ein WLAN-Server (zB Raspberry Pi) mit installiertem MQTT-Broker   

Sind der Trafo (Punkt 3.) und die DCC-Quelle (Punkt 5.) an einem 25-poligen Kabel nach NEM908D angeschlossen, so kann die Selbstbau-Platine "CON_SubD_Screw10_V1" (mit aufgesteckter Platine "AC_5V_6pol_DCC_V1" und LM2596-DC-DC-Wandler zur Erzeugung der 5V-Spannung) zur Versorgung des Test-Aufbaus verwendet werden. (Siehe Bild 1)   

## Verkabelung
1. Anstecken von zwei Dr&auml;hten (oder einem Taster) an den IO19-Anschl&uuml;ssen des Shields "Shield_5V_DCC_6pol"   
2. Zusammenstecken der beiden I²C-Expander-Boards PCF8574 mit den (7-Bit-)Adressen 0x20 und 0x21   
3. Verbinden der I²C-Expander-Boards mit der 4-poligen Stiftleiste am "Shield_I2C_5V_3V3" mit vier Kabeln   
4. Verbinden des 6-poligen Steckers des "Shield_5V_DCC_6pol"-Shields mit dem DCC-Stecker an der "CON_SubD_Screw10_V1"-Platine   
5. Verbinden des 6-poligen Power-Steckers des "RW_5V_W2"-Blocks mit dem "POWER"-Stecker an der "CON_SubD_Screw10_V1"-Platine   
6. Verbinden der Weichendr&auml;hte mit den Klemmen auf der "CON_6pol_3"-Platine   
7. Verbinden der "CON_6pol_3"-Platine mit dem 6-poligen Ausgang des "RW_5V_W2"-Blocks   
8. Verbinden des 10-poligen Steckers des "RW_5V_W2"-Blocks mit der "CON_10pol_PIN"-Platine   
9. Verbinden "CON_10pol_PIN"-Pin 1 (IN1) mit PCF8574-0-Pin 2 (OUT)   
10. Verbinden "CON_10pol_PIN"-Pin 2 (IN2) mit PCF8574-0-Pin 3 (OUT)   
11. Verbinden "CON_10pol_PIN"-Pin 7 (OUT1) mit PCF8574-1-Pin 2 (IN)   
12. Verbinden "CON_10pol_PIN"-Pin 8 (OUT2) mit PCF8574-1-Pin 3 (IN)   
13. Anstecken des 25-poligen Kabels an die "CON_SubD_Screw10_V1"-Platine

# Erforderliche Software


# Test 
## Direktes Schalten
## DCC
## MQTT


********************************
= - = - = - = - = - = - = - = - = - = - = - = - = - = - = -   
Ab hier: ToDo....

## Verkabelung
1. 1x Flachbandkabel Stecker-Buchse 2polig: PCF8574-0x20 Pin 0 und 1 mit U5_W-Platinen Pin WSA und WSB verbinden   
2. 1x Flachbandkabel Stecker-Buchse 2polig: PCF8574-0x21 Pin 0 und 1 mit U5_W-Platinen Pin WRA und WRB verbinden   
3. 1x Flachbandkabel Stecker-Buchse 2polig f&uuml;r die Stromversorgung vom PCF8574-Ausgang zu den U5_W-Platinen   
4. 1x Flachbandkabel Stecker-Stecker 2polig f&uuml;r den Anschluss der 18V-Wechselspannung an den U5_W-Platinen   
5. 1x Flachbandkabel Stecker-Stecker als Taster an IO19 gegen Masse   
6. 1x Flachbandkabel Stecker-Stecker f&uuml;r das DCC-Signal   

![Test_5V_W](./images/300_test_5V_W_DCC_240402.png "Test_5V_W")   
_Bild 1: Testanordnung 5V_W-Weichensteuerung mit DCC-Signal_   

# Kurzanleitung
1. Die Weiche an die U5_W-Platinen anschlie&szlig;en (Leitungen WA, W0, WB).   
2. Die U5_W-Platinen mit den I²C-Expander-Boards PCF8574 verbinden (Leitungen WSA, WSB, WRA, WRB).   
3. Den Ausgang der DCC-Quelle an das Selbstbau-Board DCC_3V3 anschlie&szlig;en.   
4. An die U5_W-Platinen die Versorgungsspannung anschlie&szlig;en (5V, 0V von den Expander-Boards).   
5. An die U5_W-Platinen die Schaltspannung anschlie&szlig;en (V+ und V-).   
6. Programm `ESP32_06_cmd_turnout_V1.cpp` compilieren und auf den ESP32 D1 mini hochladen.   
   
Nach dem Programmstart sucht der ESP32 nach dem WLAN, dessen Daten in der Konfigurationsdatei `dcc_config.h` stehen. Durch Dr&uuml;cken des Tasters IO19 (bzw. verbindet man IO19 kurz mit GND) kann man die WLAN-Suche abbrechen.   
   
## Steuerung per DCC
Stellt man bei der ROCO Multimaus die DCC_Adresse 11 ein, so kann man die Weiche steuern.   

## Steuern per MQTT
Zum Steuern der Weiche &uuml;ber MQTT muss auf dem Rechner (bzw. Raspierry Pi) mit der IP 10.1.1.1 ein MQTT-Broker (zB `mosquitto`) laufen. Zum Senden der MQTT-Nachrichten an die Weiche kann man zB das Konsolen-Programm `mosquitto_pub` verwenden.   
War das Verbinden mit dem WLAN und MQTT-Broker erfolgreich, so kann die Weiche durch folgende Befehle auf "Gerade" gestellt werden:   
`mosquitto_pub -h 10.1.1.1 -t turnout/set/T1 -m 1`   
oder   
`mosquitto_pub -h 10.1.1.1 -t turnout/set/11 -m g`   
Das Stellen auf "Abzweig" erfolgt zB durch   
`mosquitto_pub -h 10.1.1.1 -t turnout/set/T1 -m 0`   

# Schaltung (Verdrahtung)
Die Verdrahtung erfolgt nach folgendem Schema:   
![Wiring_5V_W_DCC](./images/300_test_5V_W_turnout_dcc_wiring_240402.png "Wiring_5V_W_DCC")   
_Bild 2: Verdrahtung der 5V_W-Weichensteuerung mit DCC_ 

# Programmdetails

## Entwicklungsumgebung
Das Programm wurde in Visual Studio Code und PlatformIO erstellt.   

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
  int    outBitA;       // bit PCF8574 for turnout stright (Gerade)
  int    outBitB;       // bit PCF8574 for turnout curved (Abzweig)
  int    inPCF;         // aIOEx index of PCF8574 input device
  int    inBitA;        // bit number at PCF8574 input stright=1
  int    inBitB;        // bit number at PCF8574 input curved=1
};

//_______Railroad commands______________________________________
// railway components:  type,name,dcc,
//                      pIOEx-out-index,outBitA,outBitB, 
//                      pIOEx-in-index inBitA inBitB
#define  RCOMP_1        RC_TYPE_TO,"T1",11, 0,0,1, 1,0,1
//.......Array of all railway components........................
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
