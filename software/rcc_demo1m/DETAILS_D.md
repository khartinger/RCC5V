<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Das Demo-Programm rcc_demo1m im Detail</h1><b><big>Details zur Demo-Software zum Steuern von Modellbahn-Komponenten</big></b><br>  
Stand: 21.11.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>   

# 1. Übersicht über `rcc_demo1m`
Der Quellcode des Demo-Programms `rcc_demo1m` ist modular aufgebaut und besteht aus vielen Dateien:  

![Software demo1m overview](/images/480_sw_demo1m_overview.png "Software demo1m overview")  

ℹ️ **Beachte:** Bei einem Standard-Projekt ohne spezielle Features müssen lediglich die beiden Konfigurationsdateien `rcc_config.h` und `rcc_demo1m_text.h` angepasst werden.

### Die Verzeichnisse und Dateien im Detail  
| Datei | Inhalt |  
| ----- | ------ |  
| `src/rcc_demo1m.cpp` | Hauptprogramm mit `setup()` und `loop()` |  
| `src/rcc_demo1m_text.h` | Texte in Deutsch und Englisch wie Startbildschirmtexte etc. |
| `src/rcc_config.h` | Definitionen und Konstante wie DEBUG, VERSION, Netzwerkdaten, MQTT-Befehle, Expander-Adressen, Railroad-Komponenten, ... |  
| `src/pre_config.h` | Expander-Namen und Pin-Namen |  
| `src/src/rcc_config.cpp` | Erzeugt die Komponenten- und Kommando-Arrays sowie die PCF8574-Objekte. |
| `src/src/rcc_command.cpp` / `.h` | Erzeugt RCC-Kommandos und führt sie zum vorgesehenen State-Zeitpunkt aus. |
| `src/src/rcc_dcc.cpp` / `.h` | Empfängt DCC-Nachrichten über `DccAccessoryDecoder` und ordnet sie Komponenten zu. |
| `src/src/rcc_display.cpp` / `.h` | Aktualisiert Texte, Statussymbole und Komponentenübersicht auf dem OLED. |
| `src/src/rcc_hardwareaccess.cpp` / `.h` | Initialisiert und liest die IO-Expander, setzt Ausgänge und behandelt den Reset-Taster. |
| `src/src/rcc_mqtt.cpp` / `.h` | Verbindet WLAN und MQTT, verarbeitet GET-/SET-Anfragen und bildet Statuswerte auf JSON ab. |
| `src/src/rcc_statemachine.cpp` / `.h` | Legt das globale State-Machine-Objekt und die Zeitkonstanten fest. |
| `src/src/cppsrc` und `src/src/csrc` | Quellcode der verwendeten U8g2-Grafikbibliothek. |
| `src/src/pcf8574` | Klasse `PCF8574` für den Zugriff auf einen I²C-IO-Expander. |
| `src/src/screen154` | Klasse `Screen154` für das SSD1309-OLED. |
| `src/src/simplemqtt` | Klasse `SimpleMqtt` und MQTT-Basisimplementierung `PubSubClient`. |
| `src/src/statemachine` | Wiederverwendbare Klasse `Statemachine`. |

<a name="x05"></a>   
<a name="TableOfContents"></a>   

## Inhaltsübersicht
* [1. Übersicht über rcc_demo1m](#x10)  
* [2. Das Hauptprogramm rcc_demo1m.cpp](#x20)  
* [3. Konfiguration](#x30)  
* [4. Statemachine](#x40)  
* [5. DCC-Befehle](#x50)  
* [6. RCC-Kommandos](#x60)  
* [7. Hardware-Zugriff](#x70)  
* [8. OLED-Anzeige](#x80)  
* [9. MQTT-Befehle](#x90)  
* [10. Beispiel: Ergänzung eines Schaltblocks](#x100)  

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Das Hauptprogramm rcc_demo1m.cpp
# 2.1 Funktion
Das Hauptprogramm `rcc_demo1m.cpp` definiert den Prozessortyp (ESP32), die Anzeigesprache (Deutsch) und bindet alle Header-Dateien und extern definierte Objekte (`screen_`, `stm`, `lastDcc`) ein. Es enthält die Standard-Funktionen `setup()` und `loop()`.

<a name="x22"></a>   

## 2.2 Funktion setup()

`setup()` initialisiert die Hardware und die Kommunikationswege in dieser Reihenfolge:

1. Bei aktiviertem Debugging wird die serielle Schnittstelle mit 115200 Baud gestartet.
2. `initHardwareAccess1()` setzt die LED und den Taster-Pin und initialisiert alle Kommandoeinträge mit `RCMD_NONE`.
3. `initDisplay1()` startet das OLED, zeigt Titel und Versionsnummer und gegebenenfalls die Infoseiten aus `rcc_demo1m_text.h`.
4. `initHardwareAccess2()` initialisiert die konfigurierten PCF8574 und liest die ersten Eingangswerte ein. Ein fehlender Expander hält den Start an; die Suche wird nach jeweils fünf Sekunden wiederholt.
5. `initRccWiFi()` lädt gegebenenfalls gespeicherte WLAN-Daten, versucht WLAN und MQTT zu verbinden und zeigt den Verbindungszustand an. Der WLAN-Verbindungsversuch kann mit dem Taster übersprungen werden; das Programm läuft dann ohne MQTT weiter.
6. `DccAccessoryDecoder.begin(PIN_DCC, onAccessoryPacket)` aktiviert den DCC-Empfang am konfigurierten Eingang.

<a name="x23"></a>   

## 2.3 Funktion loop()

Jeder Durchlauf wird durch die State-Machine zeitlich begrenzt und bearbeitet die Aufgaben in fester Reihenfolge:

1. `stm.loopBegin()` liefert den aktuellen State.
2. DCC-Nachrichten werden verarbeitet. Außerdem werden der Reset-Taster geprüft, vorgemerkte `STATE_NOW`-Kommandos auf den aktuellen State gesetzt, die Expander-Eingänge eingelesen und gegebenenfalls die Anzeige aktualisiert.
3. `loopMqtt()` verarbeitet MQTT-Nachrichten und Verbindungsänderungen, sofern WLAN verwendet wird.
4. `loopActOnRcmd()` führt fällige Ausgangskommandos aus. Zeitlich begrenzte Schaltimpulse erhalten dabei einen zweiten State-Termin zum Zurücksetzen des Ausgangs.
5. `stm.loopEnd()` erhöht den State-Zähler und wartet bei Bedarf bis zum nächsten Tick. Ist der Ablauf verspätet, werden überfällige Ticks nachgeholt; der Rückstand ist auf 100 Ticks begrenzt.

📡 DCC-Befehl oder 🌐 MQTT-SET → 🧠 Kommandoverarbeitung → ⚙️ PCF8574-Ausgang

📥 PCF8574-Rückmeldung → 🖥️ OLED-Anzeige; bei aktivem MQTT zusätzlich 🌐 MQTT-Status

Debug-Ausgaben enthalten bei Bedarf den State, ausgeführte Aktionen, zuletzt empfangene DCC-Daten und die Dauer des Schleifendurchlaufs.

<a name="x30"></a>   
<a name="x31"></a>   

# 3. Konfiguration
Alle Definitionen, Konstanten, globale Variable und Objekte, die das Programm ben&ouml;tigt, werden entweder direkt in der cpp-Datei oder in einer Konfigurationsdatei definiert. Die Verteilung ist so gew&auml;hlt, dass projektspezifische Daten in der Konfigurationsdatei `rcc_config.h` stehen.   
Die Konfigurationsdatei enth&auml;lt folgende Abschnitte:   
* Netzwerk- und MQTT-Daten   
* Display-Daten   
* DCCex-Daten   
* IO-Expander PCF8574-Daten   
* Definition f&uuml;r Eisenbahn-Komponenten   
* die Eisenbahn-Komponenten selbst   
   
Weitere Infos zur Konfiguration stehen in **[CUSTOMIZE_D.md](./CUSTOMIZE_D.md):** Anpassung der Software an eigene Anforderungen   

### Komponenten- und IO-Konfiguration
`src/src/rcc_config.cpp` erzeugt aus `RCOMP_LIST` das Array `aRcomp[]` und dazu das gleich große Kommando-Array `aRcmd[]`. Der gemeinsame Index verbindet eine Komponente mit ihrem jeweils aktuellen Kommando. Eine Komponentendefinition enthält:

| Feld | Bedeutung |
| ---- | --------- |
| `type`, `name`, `dcc` | Komponententyp, Kurzname (maximal drei Zeichen) und DCC-Adresse |
| `outPCF`, `outBitA`, `outBitB` | Index des Ausgangs-Expanders und die zugehörigen Ausgangspins |
| `inPCF`, `inBitA`, `inBitB` | Index des Eingangs-Expanders und die zugehörigen Rückmeldepins |
| `msOn`, `msOff` | Einschaltdauer bzw. Aus-Dauer, insbesondere für Impulse und Blinklicht |

Die `EX0`- bis `EX7`-Konstanten sind Array-Indizes und keine I²C-Adressen. Bei der Standardkonfiguration sind Index 0 der Ausgangs-PCF8574 und Index 1 der Eingangs-PCF8574; deren I²C-Adressen sind separat in `rcc_config.h` angegeben. `NO_PIN` bedeutet, dass für das jeweilige Bit kein Pin angeschlossen ist.

> ⚠️ **Achtung:** Die PCF8574-Ausgänge sind im Allgemeinen aktiv-low: Ein gesetzter Ausgangswert `0` schaltet den angeschlossenen aktiven Eingang.

`IOEX_NUM` muss 2, 4, 6 oder 8 sein. Für jeden zusätzlichen Expander muss auch die entsprechende Objektliste in `src/src/rcc_config.cpp` vorgesehen werden. Die verwendeten Komponenten und ihre Pins müssen zu dieser Hardwarebelegung passen.

### Sprach- und Anzeigetexte
`LANGUAGE` wird in `rcc_demo1m.cpp` auf `'d'` (Deutsch) oder `'e'` (Englisch) gesetzt. `rcc_demo1m_text.h` enthält für beide Sprachen die Verbindungstexte, die lesbaren Statusbezeichnungen und die Start-Infoseiten (`INFOLINES`). Die `T1_...`-Konstanten sind sprachunabhängige Statuscodes für MQTT; in JSON werden sie als Strings übertragen. Beim Bearbeiten der Infoseiten müssen `INFOLINES_NUM` und die Anzahl der Einträge übereinstimmen. Angezeigt werden höchstens fünf Einträge je Seite, bei einer konfigurierten Zeilenlänge von 21 Zeichen.

<a name="x40"></a>   
<a name="x41"></a>   

# 4. Statemachine
## 4.1 Funktion
Das Timing des Programms wird mit einer Statemachine realisiert. Der Zähler läuft von 1 bis `STATE_MAX` und beginnt danach wieder bei 1. Mit den aktuellen Werten sind das 180.000 Ticks bzw. theoretisch eine Stunde Tickzeit. Die Tickdauer ist kein Echtzeitversprechen: Wenn die Schleife nicht verspätet ist, wartet `loopEnd()` für `STATE_TICK_MS` nach dem Schleifenende. Die reale Zyklusdauer enthält daher zusätzlich die Ausführungszeit der Schleife.

`loopEnd()` wartet mit `yield()`, wenn die Schleife samt gespeichertem Rückstand den Tick nicht überschritten hat. Dauert die Verarbeitung länger, wird nicht zusätzlich gewartet: Die Verspätung wird in nachfolgenden Schleifen reduziert. Der State-Zähler wird dabei nicht übersprungen. Der gespeicherte Rückstand ist auf 100 Ticks begrenzt; eine darüber hinausgehende Verspätung wird verworfen.

<a name="x42"></a>   

## 4.2 Header-Datei
In der Header-Datei `rcc_statemachine.h` wird das zeitliche Verhalten des Programms festgelegt:  
```
 8 |//------- Duration of intervals in milliseconds ----------------
 9 |constexpr uint32_t STATE_TICK_MS      = 20;      // state delay in ms
10 |constexpr uint32_t RESET_DELAY_MS     = 1000;    // press button 1 s
11 |constexpr uint32_t SCREEN_REFRESH_MS  = 5200;    // refresh screen
12 |constexpr uint32_t SHOW_SCREEN_MIN_MS = 1500;
13 |constexpr uint32_t BLINK_MS           = 500;     // 0.5 s
14 |//------- Duration of intervals in state steps ---------------------------
15 |constexpr uint32_t STATE_MAX          = 3600000 / STATE_TICK_MS; // 1h
16 |constexpr uint32_t STATES_BEFORE_RESET = RESET_DELAY_MS / STATE_TICK_MS;
17 |constexpr uint32_t STATES_SCREEN_REFRESH = SCREEN_REFRESH_MS / STATE_TICK_MS;
18 |constexpr uint32_t STATES_SHOW_SCREEN_MIN = SHOW_SCREEN_MIN_MS / STATE_TICK_MS;
19 |constexpr uint32_t STATES_BLINK = BLINK_MS / STATE_TICK_MS;

```
* _Zeile  9_: Dauer eines States in Millisekunden.  
* _Zeile 10_: Dauer, wie lange der Taster (IO 19 = D6) für einen Programm-Reset gedrückt werden muss (in Millisekunden).  
* _Zeile 11_: Dauer zwischen zwei Display-Refreshs (in Millisekunden), wenn es keine Zustandsänderungen gibt. Dies ist für die Lebensdauer von OLEDs wichtig.  
* _Zeile 12_: Mindestdauer, wie lange ein Bildschirm angezeigt wird, bevor auf einen anderen umgeschaltet wird (falls es eine Zustandsänderung bei einem Schaltblock gegeben hat).
* _Zeile 13_: `BLINK_MS` ist ein 500-ms-Konstantenwert; die aktuelle Blinklichtsteuerung verwendet stattdessen die pro Komponente konfigurierten Werte `msOn` und `msOff`. `STATES_BLINK` wird derzeit nicht anderweitig verwendet.
* _Zeile 15_: Maximale Statenummer, bis zu der gezählt wird. 180000 Ticks entsprechen rechnerisch einer Stunde Tickzeit; die tatsächliche Laufzeit ist wegen der Schleifenverarbeitung länger.
* _Zeile 16 bis 19_: Alle Zeiten als State-Werte für die Statemachine.  

<a name="x43"></a>   

## 4.3 cpp-Datei
Die Datei `rcc_statemachine.cpp` definiert lediglich ein Objekt der Klasse `Statemachine`:  
```
Statemachine stm(STATE_MAX, STATE_TICK_MS);  // 1 .. 180000
```

<a name="x44"></a>   

## 4.4 Hilfsklasse `Statemachine`
Im Unterverzeichnis `statemachine` wird eine Klasse `Statemachine` definiert. Diese enthält alle Methoden, die für eine Statemachine erforderlich sind wie zum Beispiel  
|  |  |
|------------------|-----|  
| `Statemachine()` | Konstruktor |  
| `loopBegin()`    | Aufruf am Beginn der loop()-Funktion. Liefert die Nummer des aktuellen States. |  
| `loopEnd()`      | Aufruf am Ende der loop()-Funktion. Erhöht den State-Zähler und liefert die Dauer des aktuellen States. |  
| `getState()`     | Liefert die Nummer des aktuellen States. |  
| `add()`          | Addiert eine Anzahl States und liefert den resultierenden State. Der Wert wird am Statebereich zyklisch umgebrochen. Die Methode ändert NICHT den Zählerstand! |
| `diff()`         | Berechnet die zyklische State-Differenz zwischen dem aktuellen Zähler und dem angegebenen Wert. |

<a name="x50"></a>   
<a name="x51"></a>   

# 5. DCC-Befehle

## 5.1 Funktion
Je nach verwendeten Komponenten kann es sein, dass DCC-Adressen unterschiedlich dekodiert werden. Dieser Offset kann mit der Konstanten `DCC_OFFSET` angepasst werden, wobei der Wert &uuml;blicherweise entweder 4 oder 0 sein kann.   

<a name="x52"></a>   

## 5.2 Header-Datei
Die Header-Datei `rcc_dcc.h` definiert eine Struktur für DCC-Kommandos  
```   
struct DccCommand
{
    uint16_t address = 0;  ///< DCC address; 0 means no address assigned.
    int value = -1;        ///< Command value: -1 = invalid, 0 = OFF, 1 = ON.
};
```   
und deklariert die Callback-Funktion zum Empfang von DCC-Nachrichten:  
`void onAccessoryPacket(unsigned int linearDecoderAddress, bool enabled);`  

<a name="x53"></a>   

## 5.3 cpp-Datei
Die Datei `rcc_dcc.cpp` erzeugt ein Objekt zur Aufnahme der letzten DCC-Nachricht (Adresse, Wert)  
`DccCommand lastDcc;`  
und definiert die DCC-Callback-Funktion.
```   
21 |void onAccessoryPacket(unsigned int linearDecoderAddress, bool enabled) {
22 | digitalWrite(BUILTIN_LED, enabled ? 1 : 0);
23 | lastDcc.address=(int)linearDecoderAddress + DCC_OFFSET;
24 | lastDcc.value=enabled ? 1 : 0;
25 | //------is it a DCC address for this module?-------------------
26 | for(int i=0; i<RCOMP_NUM; i++) {
27 |  if(aRcomp[i].dcc==lastDcc.address) {
28 |   //----railroad component found-------------------------------
29 |   setRcmd(i, lastDcc.value, "");
30 |  }
31 | }
32 |}
```   

_Zeile 22_: Zur Kontrolle: Anzeige des empfangenen DCC-Wertes durch die eingebaute LED des ESP32-Boards.  
_Zeile 23_: Adresse der Nachricht merken  
_Zeile 24_: Wert der Nachricht merken  
_Zeile 26 bis 31_: Überprüfung, ob die Nachricht zu einer Adresse einer Komponente passt. Wenn ja, wird ein RCC-Befehl erzeugt.  

Vor dem Vergleich wird `DCC_OFFSET` zur von der Decoderbibliothek gelieferten linearen Adresse addiert. Der Offset muss zum verwendeten DCC-Sender passen. Die Callback-Funktion merkt die letzte Adresse und den Wert für die Debug-Ausgabe in `loop()`; das Kommando selbst wird über `setRcmd()` zur Ausführung in der Hauptschleife vorgemerkt.

<a name="x54"></a>   

## 5.4 Einbinden der DCC-Callback-Funktion
Damit DCC-Nachrichten empfangen werden können muss eine externe Bibliothek eingebunden werden. Dies geschieht in `platformio.ini`:  
```   
[env:wemos_d1_mini32]
platform = espressif32@6.7.0
board = wemos_d1_mini32
framework = arduino
monitor_speed = 115200
lib_deps =
  bblanchon/ArduinoJson@6.21.1
  https://github.com/enginorama/DccAccessoryDecoder#ef3d884
```   

<a name="x60"></a>   
<a name="x61"></a>   

# 6. RCC-Kommandos
## 6.1 Funktion

Ein eingehender DCC- oder MQTT-Befehl wird nicht unmittelbar in der Empfangsfunktion auf die Hardware geschrieben. `setRcmd()` validiert Index und Befehlswert, trägt die Aktion in `aRcmd[]` ein und gibt eine Antwort für MQTT zurück. Der spezielle Termin `STATE_NOW` wird in der Hauptschleife durch den aktuellen State ersetzt. Dadurch werden Ausgänge zentral und zeitlich kontrolliert in `loopActOnRcmd()` geschaltet.

<a name="x62"></a>   

## 6.2 Header-Datei

`rcc_command.h` stellt `setRcmd()`, `loopRcmdReplaceStateNow()` und `loopActOnRcmd()` bereit. Die Kommandozustände selbst stehen in `strRcmd` in `rcc_config.h`: aktueller Eingangswert, Änderungsflag, Ausführungszeitpunkt sowie optional ein zweiter Ausführungszeitpunkt samt Folgebefehl.

<a name="x63"></a>   

## 6.3 cpp-Datei

`setRcmd(iRcomp, iCmdValue, sReturn)` unterstützt abhängig vom Typ folgende Abläufe:

| Typ | Wert `0` | Wert `1` |
| --- | -------- | -------- |
| `TO`, `TX`, `T3` | Schaltstellung `BA=10`, nach `msOn` zurück auf `BA=11` | Schaltstellung `BA=01`, nach `msOn` zurück auf `BA=11` |
| `UC` | Ausgang A aus (`1`) | Ausgang A für `msOn` aktiv (`0`), danach aus |
| `DT`, `DD`, `TUI` | Ausgang A aus (`1`) | Ausgang A ein (`0`) |
| `P1` | Kein Impuls (`A=1`) | Impuls auslösen (`A=0`); die Hardware setzt den Eingang selbst zurück |
| `P2` | Reset-Impuls `BA=10`, danach `BA=11` | Set-Impuls `BA=01`, danach `BA=11` |
| `UI` | `BA=01` | `BA=11` |
| `BL` | Blinkfolge beenden | Blinkfolge starten; `msOn` und `msOff` bestimmen die Phasen |

Für Impulse wird `msOn` in State-Ticks umgerechnet; Werte unter einem Tick werden auf einen Tick angehoben. Die resultierende Impulsdauer ist nominal, da die Schleifenlaufzeit zur Tickzeit hinzukommt. `loopActOnRcmd()` erledigt die Hardwarezugriffe und löscht ausgeführte Einmal-Kommandos. Beim Blinklicht wird jeweils der nächste Umschaltzeitpunkt eingetragen.

Ungültige Komponentenindizes und Werte außerhalb `0`/`1` werden mit einer Fehlerzeichenfolge zurückgewiesen. Pro Komponente ist nur ein Kommandoeintrag vorhanden; es gibt keine Warteschlange. Ein neuer Befehl für dieselbe Komponente kann daher ein noch ausstehendes Kommando überschreiben.

<a name="x70"></a>   

# 7. Hardware-Zugriff

## 7.1 Pins und IO-Expander
Der ESP32 verwendet `PIN_DCC` (GPIO 18) für den DCC-Eingang und `PIN_BUTTON` (GPIO 19) für den Taster. Der Taster ist aktiv-low und benötigt einen Pull-up auf 3,3 V. Die PCF8574-Expander werden über I²C angesprochen; deren Bus, Adressen und Anzahl sind in `rcc_config.h` und `rcc_config.cpp` festgelegt. In der aktuellen Konfiguration zeigen `EX0`/`EX1` auf den Ausgangs- und Eingangs-Expander mit den I²C-Adressen `0x20` und `0x21`. Weitere Expander werden paarweise als Ausgangs- und Eingangsexpander ergänzt.

Die Eingangsrückmeldung einer Komponente wird als zwei Bits zusammengesetzt: `inBitA` ist das niederwertige Bit A, `inBitB` das höherwertige Bit B. Damit ergibt sich der Status `BA` im Bereich 0 bis 3. Nicht vorhandene Pins (`NO_PIN`) tragen den Wert 0 bei. Änderungen werden in `aRcmd[i].inValue` gespeichert und stoßen bei aktivem MQTT einen GET für die DCC-Adresse der Komponente an.

`actOnRcmdHardware()` prüft Expanderindex und Pinnummern, bevor es einen einzelnen Pin oder die Kombination `BA` setzt. Ein ungültiger Index oder Pin wird als Fehlertext zurückgegeben. Beim Start werden die PCF8574 mit den zuvor gelesenen Ausgangsbytes initialisiert; fehlende erwartete Bausteine werden wiederholt gesucht.

## 7.2 Reset-Taster
Ein kurzer Tastendruck kann während der Start-Infoseiten zur nächsten Seite springen. Im normalen Programmablauf löst ein dauerhaft gedrückter Taster nach nominal `RESET_DELAY_MS` einen Neustart mit `esp_restart()` aus. Die tatsächliche Zeit hängt von der Schleifenlaufzeit ab. Wird der Taster vorher losgelassen, beginnt der Zähler beim nächsten Drücken erneut.

<a name="x80"></a>   

# 8. OLED-Anzeige

Das Display ist ein SSD1309 mit 128 × 64 Pixeln. `Screen154` stellt Textfunktionen bereit; `rcc_display.cpp` verwaltet zusätzlich einen Textpuffer, damit ein periodischer Refresh den vollständigen Inhalt wiederherstellen kann.

Beim Start werden Titel und Version sowie – falls in `rcc_demo1m_text.h` definiert – die Infoseiten gezeigt. Pro Seite werden bis zu fünf Infotexte ausgegeben. Die letzte Zeile bleibt maximal `SHOW_INFOPAGE_SEC` Sekunden sichtbar; der Taster beendet die Wartezeit vorzeitig.

Im Normalbetrieb zeigt die Anzeige die Verbindungsinformationen und eine Gruppe von bis zu fünf Komponenten. Die drei Komponenten-Zeilen enthalten Kurznamen, typabhängige Statussymbole und DCC-Adressen. Bei einer Statusänderung wird die betroffene Gruppe vorgemerkt; sie wird unter Beachtung der nominalen Mindestanzeigezeit `SHOW_SCREEN_MIN_MS` eingeblendet. Die Gruppen werden außerdem regelmäßig gewechselt und das Display wird nach der nominalen Periode `SCREEN_REFRESH_MS` neu geschrieben; die reale Zeit hängt von der Schleifenlaufzeit ab.

Die Symbole werden in `getSymbol4Line5()` aus Komponententyp und Rückmeldewert erzeugt. Die konkrete Zuordnung zu den vier möglichen Eingangskombinationen ist typabhängig; unbekannte Kombinationen erscheinen als Fehlerzeichen.

<a name="x90"></a>   

# 9. MQTT-Befehle

## 9.1 Themen und Ablauf
Die Basis des MQTT-Themas ist `TOPIC_BASE`. Der Client abonniert das GET-Thema sowie SET-Themen unterhalb der Basis. Eine GET-Anfrage wird mit dem Payload als Schlüssel gesendet; eine SET-Anfrage verwendet den Schlüssel im Thema:

| Zweck | Thema | Inhalt |
| ----- | ----- | ------ |
| GET | `<TOPIC_BASE>/get` | Payload ist z. B. `version`, `byname` oder eine Komponente |
| SET | `<TOPIC_BASE>/set/<schlüssel>` | Payload ist der neue Wert |
| Antwort | `<TOPIC_BASE>/ret/<schlüssel>` | Antwort auf GET bzw. SET (meist JSON; `help` als Text) |

`TOPIC_GET` und `TOPIC_SET` enthalten die allgemein verfügbaren Schlüssel. Beim Start ergänzt `initRccWiFi()` die Kurzname- und DCC-Schlüssel aller konfigurierten Komponenten. `SimpleMqtt` vergleicht GET-Payloads und SET-Themen-Suffixe zunächst exakt mit diesen Listen. Deshalb müssen diese Schlüssel genau wie konfiguriert geschrieben werden (Komponentennamen sind aktuell großgeschrieben); erst danach normalisieren `simpleGet()` und `simpleSet()` die Werte auf Kleinbuchstaben. Der MQTT-Callback merkt gültige Anfragen vor; verarbeitet und beantwortet werden sie im Hauptschleifenaufruf von `client.doLoop()`.

Die benutzerdefinierten Listen `TOPIC_SUB` und `TOPIC_PUB` sind in der aktuellen Konfiguration leer. Es gibt daher keine zusätzlichen Anwendungs-Subscribe- oder Publish-Themen aus diesen Listen.

## 9.2 GET-Abfragen
Verfügbare allgemeine GET-Payloads:

| Payload | Antwort |
| ------- | ------- |
| `?`, `help` | Hilfe und Syntaxhinweise |
| `version` | Softwareversion |
| `mac`, `ip`, `signal` | MAC-Adresse und Hostname, IP-Adresse bzw. WLAN-Signalstärke |
| `topicbase` | Aktuelle Themenbasis |
| `eeprom` | Gespeicherte Themenbasis und benutzerdefinierte EEPROM-Daten |
| `byname` | Status aller Komponenten mit Namen als JSON-Schlüssel |
| `bydcc` | Status aller Komponenten mit DCC-Adressen als JSON-Schlüssel |
| `status` | Status aller Komponenten mit DCC-Adressen und numerischen Statuscodes |
| `<name>` oder `<dcc>` | Status einer einzelnen Komponente |

Statusantworten sind JSON-Objekte. Die Werte werden als JSON-Strings serialisiert. Bei `byname` und Einzelabfragen über Namen werden grundsätzlich sprachabhängige Texte verwendet; Komponenten vom Typ `DD` und `BL` liefern jedoch auch dort numerische Statuscodes. `bydcc` und `status` liefern für alle Typen die kompakten Statuscodes aus `rcc_demo1m_text.h`. Ein Komponentenwechsel an den Eingängen stößt ebenfalls eine GET-Statusveröffentlichung für diese DCC-Adresse an.

Beispiel mit der konfigurierten Themenbasis `rcc/demo1m`: Eine GET-Anfrage mit Payload `bydcc` wird an `rcc/demo1m/get` gesendet; die Antwort erscheint auf `rcc/demo1m/ret/bydcc`. Eine SET-Anfrage für das abschaltbare Gleis mit DCC-Adresse 41 wird an `rcc/demo1m/set/41` gesendet; der Payload `1` schaltet Fahrspannung ein und die Antwort kommt auf `rcc/demo1m/ret/41`.

## 9.3 SET-Abfragen
SET-Schlüssel sind `topicbase`, `wlan`, `eeprom0` sowie Name und DCC-Adresse jeder konfigurierten Komponente.

* `topicbase`: wechselt die Themenbasis, speichert sie im EEPROM, aktualisiert bei bestehender MQTT-Verbindung die Abonnements und zeigt sie auf dem Display an. Die Themenbasis darf höchstens 47 Zeichen lang sein.
* `wlan`: speichert WLAN-Daten im Format `SSID|Passwort|IPv4-Adresse`; ein leeres Passwort ist als `SSID||IPv4-Adresse` erlaubt. Die neue Verbindung wird beim Neustart verwendet.
* `eeprom0`: `1` löscht die gespeicherte Themenbasis, `2` die benutzerdefinierten Daten, `3` bzw. `all` beides. Payload `?` liefert die Syntax.
* Komponente: der erlaubte Payload hängt vom Typ ab. Für Weichen sind `0`, `a` oder `b` der Wert 0 und `1` oder `g` der Wert 1. Für `P2` gelten unter anderem `0`/`reset`/`rst` bzw. `1`/`set`; `UI` akzeptiert `0`/`off` und `1`/`on`; die übrigen Typen verwenden im Allgemeinen `0`/`1` oder bei `P1` und `TUI` zusätzlich `off`/`on`.

Ein gültiges Komponenten-SET plant ein RCC-Kommando ein. Ungültige Werte werden mit `Error: invalid command` beantwortet. Die WLAN- und EEPROM-Operationen liefern ihr Ergebnis als JSON zurück. Nicht konfigurierte oder nicht unterstützte Themen sind nicht Teil der aktivierten GET-/SET-Liste.

## 9.4 WLAN- und MQTT-Verbindung
WLAN und Broker werden mit den Einstellungen aus `rcc_config.h` initialisiert. Gespeicherte WLAN-Daten können die Standardwerte beim Start ersetzen. Wird WLAN beim Start nicht erreicht oder mit dem Taster übersprungen, wird MQTT für diesen Programmlauf deaktiviert; DCC- und Hardwarefunktionen bleiben verfügbar. Bei erfolgreicher WLAN-Verbindung, aber nicht verfügbarem Broker, versucht die MQTT-Hilfsklasse im laufenden Betrieb erneut, die Verbindung herzustellen. Bei erfolgreicher MQTT-Verbindung veröffentlicht das Programm außerdem Startinformationen auf `rcc/start/mqtt` (Themenbasis und Signalstärke).

<a name="x100"></a>   

# 10. Beispiel: Ergänzung eines Schaltblocks

Dieses Beispiel ergänzt die bestehende Konfiguration um einen weiteren Block vom bereits unterstützten Typ `RC_TYPE_TO` (Zweiwegweiche). Der Typ, die Kommandoausführung, die Display-Symbole und die MQTT-Auswertung sind im Programm bereits implementiert.

## 10.1 IO-Expander und Komponente konfigurieren
Das Beispiel nimmt an, dass die bestehenden Expander mit Index `EX0`/`EX1` verwendet werden und ein zweites Ausgangs-/Eingangspaar hinzukommt. `EX2` und `EX3` sind Indizes in `pIOEx[]`, keine I²C-Adressen. Bei den aktiven Adressen `0x20` und `0x21` kann das zweite Paar beispielsweise `0x22` und `0x23` verwenden:

```cpp
#define IOEX_NUM       4
#define IOEX_ADDRESS3  0x24  // zweiter Ausgangs-Expander, Index EX2
#define IOEX_ADDRESS4  0x25  // zweiter Eingangs-Expander, Index EX3
```

`rcc_config.cpp` erzeugt die Expanderobjekte für `IOEX_NUM == 4`. Die PCF8574-Adressdefinitionen in `rcc_config.h` müssen trotzdem auf die tatsächlich angeschlossene Hardware abgestimmt werden.

In der aktuellen Konfiguration sind die Namen `RCOMP_1` bis `RCOMP_5` aktiv. Für eine zusätzliche Zweiwegweiche kann die folgende neue Definition verwendet werden:

```cpp
#define RCOMP_10 RC_TYPE_TO, "T2", 61, EX2, PIN0, PIN1, EX3, PIN0, PIN1, 500, 0
```

Die Parameter sind Typ, eindeutiger Kurzname, DCC-Adresse, Ausgangs-Expander und Pins A/B, Eingangs-Expander und Pins A/B sowie `msOn`/`msOff`. Für eine aktive-low-Weiche bedeutet Wert `1` `BA=01` (gerade) und Wert `0` `BA=10` (Abzweig). Nach `msOn` wird `BA=11` geschaltet.

Die Komponente muss an das Ende der vorhandenen Liste angefügt werden. Anzahl und Liste müssen übereinstimmen:

```cpp
#define RCOMP_NUM  7
#define RCOMP_LIST {RCOMP_1},{RCOMP_2},{RCOMP_3L},{RCOMP_3R},{RCOMP_4},{RCOMP_5},{RCOMP_10}
```

Bei einer eigenen Konfiguration bleiben deren vorhandene Einträge erhalten; `RCOMP_NUM` wird um eins erhöht und die neue Definition an `RCOMP_LIST` angehängt. Name, DCC-Adresse und verwendete Pins müssen eindeutig bzw. frei sein.

## 10.2 Texte und Start-Infoseiten
Für eine neue oder geänderte Komponentenbezeichnung genügt für eine vorhandene Komponente die Anpassung in `rcc_config.h`. Die Statustexte für `RC_TYPE_TO` stehen bereits in `rcc_demo1m_text.h` (`T_STRAIGHT`, `T_CURVED`, `T_UNDEF0`, `T_UNDEF1`). Bei einer zusätzlichen Komponente sollten die Start-Infoseiten in beiden Sprachzweigen um die neue DCC-Adresse ergänzt werden.

Die Start-Infoseiten werden sprachabhängig über `INFOLINES` und `INFOLINES_NUM` in `rcc_demo1m_text.h` konfiguriert. `INFOLINES_NUM` muss der Anzahl der Einträge entsprechen. Für eigene Komponenten sind die DCC-Adressen und Bezeichnungen in beiden Sprachzweigen abzugleichen. Pro Zeile stehen maximal 21 Zeichen zur Verfügung.

## 10.3 Verhalten und Darstellung
Der Typ `RC_TYPE_TO` ist bereits in `rcc_command.cpp` implementiert:

| SET-Wert | Aktion |
| -------- | ------ |
| `0` | Abzweig: `BA=10`, danach Rücksetzen auf `BA=11` |
| `1` | Gerade: `BA=01`, danach Rücksetzen auf `BA=11` |

Die Schaltdauer kommt aus `msOn` und wird mindestens auf einen State-Tick begrenzt. Für MQTT sind unter anderem `0`, `a`, `b` (Abzweig) sowie `1`, `g` (gerade) gültig. Ein neuer `RC_TYPE_TO`-Block benötigt deshalb keinen zusätzlichen Zweig in `rcc_command.cpp` oder `rcc_mqtt.cpp`.



[Zum Seitenanfang](#up)
