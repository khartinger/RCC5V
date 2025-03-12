<table><tr><td><img src="./images/RCC5V_Logo_96.png
"></img></td><td>
Letzte &Auml;nderung: 12.3.2025 <a name="up"></a><br>   
<h1>Umbau des Moduls 01 "Gleis 1 auf 2 mit Güterschuppen (2010)"</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Hier geht es direkt zur Inhalts&uuml;bersicht](#x05)   

# &Uuml;bersicht
Diese Anleitung beschreibt das Umrüsten der elektrischen Steuerung eines 50 x 25 cm² gro&szlig;en N-Spur-Gleis-Moduls M01 „Gleis 1 auf 2 mit Güterschuppen“ auf das RCC-System. Die Bilder zeigen das Modul mit Landschaftsgestaltung und alter DCC-Steuerung. An der Forderfront erkennt man die Bedien- und Anzeigeelemente f&uuml;r den Handbetrieb.   

![Modul M01 Landschaft](./images/300_M01_Landscape.png "Modul M01 Landschaft")   
_Bild 1: Das Modul M01 mit Landschaft_   

![Modul M01 mit alter Steuerung](./images/300_M01_Control_old.png "Modul M01 mit alter Steuerung")   
_Bild 2: Die alte Steuerung des Modules M01_   

## Eigenschaften des Moduls
|                |                                                    |   
|----------------|----------------------------------------------------|   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit Schotterbett          |   
| Gleisbild      | 1x Zweiwegweiche, <br>1x abschaltbares Gleis        |   
| Elektrischer Anschluss | 2x 25-poliger SUB-D-Stecker (entsprechend NEM 908D, je 1x WEST und OST) |   
| Fahrstrom     | Analog- oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | * H&auml;ndisch direkt an der Modulvorderseite <br> * &uuml;ber DCC <br> * durch MQTT-Nachrichten (&uuml;ber WLAN) |   
| Bedienelemente mit R&uuml;ckmeldung | 1x OLED-Display und Taster <br> 1x Zweiwegweiche (Block W2, DCC 12) <br> 1x Fahrstrom (Block 2IO, DCC 11) |   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   
| MQTT: IP-Adresse des Brokers (Host) | `10.1.1.1` |   
| Sonstiges | * Beide Weichen werden mit einem Schalter geschaltet (beide auf "Gerade" oder beide auf "Abzweig") |   

<a name="x05"></a>   

# Inhaltsverzeichnis   
* [1. Vorbereitung](#x10)   
* [2. Abbau der alten Schaltung](#x20)   
* [3. Aufbau des Gleisplans](#x30)   
* [4. Elektrische Verdrahtung des Moduls](#x40)   
* [5. Probebetrieb](#x50)   
* [6. Abschlie&szlig;ende Arbeiten](#x60)   

[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# 1. Vorbereitung
## 1.1 Bisherige DCC-Steuerung
Die bisherige DCC-Steuerung des Moduls erfolgte mit einem Uhlenbrock Schaltdecoder SD1 für das Ladegleis und einen Uhlenbrock Magnetartikeldecoder MD2 zur Weichenschaltung. Das Umschalten zwischen DCC- und Wechselstromsteuerung der Weiche erfolgte über ein 
4-poliges Umschaltrelais LZNQ403.   

## 1.2 Neue Komponenten
Für die Steuerung werden verschiedene Komponenten benötigt, wobei der Zusammenbau der Module im Verzeichnis /fab beschrieben ist.   
* SUB2525_NT: Modulverbinder mit 25-poligem Stecker auf beiden Seiten und Netzteil   
* uC_big: Mikrocontroller mit integrierter OLED-Anzeige   
* .. cm Flachband-Verbindungskabel 6-polig   
* 2IO-Block für das abschaltbare Ladegleis   
* CON_1xIO_V2: Board zum Anschluss der geschalteten Stromzuführung   
.. cm Flachband-Verbindungskabel 6-polig   
* W2-Block zur Weichensteuerung   
* CON_6pol_3_V2: Board zum Anschluss der Weichenkabel   
* .. cm Flachband-Verbindungskabel 6-polig   
* .. Stk Verbindungsdrähte Länge 25 cm, Buchse-Buchse   
* 2x PCF8574-I²C-I/O-Expander-Board   


[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Abbau der alten Steuerung
Bei Abbau der alten Schaltung ist darauf zu achten, dass alle von den Gleisen und Weichen kommenden Leitungen möglichst nicht gekürzt oder zu kurz abgeschnitten werden.   
1. Abschrauben des alten Front-Panels vom Modul   
Falls das Panel zusätzlich zu den Schrauben verleimt ist: Entweder mit einer Stichsäge die Verleimung aufschneiden oder mit Hammer und Holzbrett durch Schlagen lösen.   
2. Trennen der elektrischen Leitungen zwischen Panel und Modul   
Leitungen losschrauben oder abzwicken (siehe _Bild 2_).
3. Alle alten Komponenten aus dem Modul entfernen   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Neubau der Steuerung
## 3.1 Planung der Verkabelung
Für die Steuerung des abschaltbaren Gleises und der Weiche sind lediglich drei I/O-Leitungen der I/O-Expander erforderlich:   
* Abschaltbares Gleis: Pin 0   
* Zweiwegweiche: Pin 1 und Pin 2   

Die Verdrahtung zwischen den I/O-Boards und den Blöcken zeigt das folgende Bild.

![Modul M01 Verkabelung](./images/600_M01_wiring1.png "Modul M01 Verkabelung")   
_Bild 3: Verkabelung Modul M01_   

## 3.2 Software für den ESP32
Als Basis für die Steuersoftware im ESP32 dient die Demo-Software. Es müssen lediglich die Konfigurationsdateien angepasst werden. Eine detaillierte Beschreibung findet sich unter [/software/rcc_demo1/CUSTOMIZE_D.md](/software/rcc_demo1/CUSTOMIZE_D.md) bzw. [https://github.com/khartinger/RCC5V/blob/main/software/rcc_demo1/CUSTOMIZE_D.md](https://github.com/khartinger/RCC5V/blob/main/software/rcc_demo1/CUSTOMIZE_D.md)   

1. Kopieren der Demo-Software (Stand 18.1.12025) in ein Verzeichnis `rcc_module01_V1`   
2. Umbenennen `demo1` in `module01_V1`   

3. Anpassung der Konfigurationsdatei `dcc_config.h`   
```   
//_____dcc_config.h______________________________khartinger_____
// Configure file for ESP32 railroad DCC decoder program
// rcc_demo1
//
// Created by Karl Hartinger, November 14, 2024
// Changes:
// 2024-11-28 Change program name
// 2025-01-03 Change TOPIC_BASE
// Released into the public domain.

#ifndef DCC_CONFIG_H
 #define DCC_CONFIG_H
 #include <Arduino.h>                  // String, int32_t
 #include "src/pcf8574/D1_class_PCF8574.h"

//_______program version________________________________________
#define  VERSION_99     "2025-03-12 rcc_module01"
#define  VERSION_99_1   "Version 2025-03-12"

#define  INFOLINES_SEC  20             // time to show one page

//_______Network and MQTT data__________________________________
#define  _USE_WIFI_     true
#define  _SSID_         "Raspi11"
#define  _PASS_         "12345678"
#define  _HOST_         "10.1.1.1"
#define  TOPIC_BASE     "rcc/module01"
#define  TOPIC_GET      "?,help,version,ip,topicbase,eeprom,byname,bydcc"
#define  TOPIC_SET      "topicbase,eeprom0"
#define  TOPIC_SUB      ""
#define  TOPIC_PUB      ""

//_______1.54" display data (SSD1309, 128x64 pixel, I2C)________
#define  SCREEN_TITLE   "RCC: Modul 01"
#define  SCREEN_LINE_MAX 6
#define  SCREEN_LINE_LEN 21

//_______DCCex__________________________________________________
#define  DCC_OFFSET     4

//_______Hardware: IO expander PCF8574__________________________
#define  IOEX_NUM       2              // number of IO expander
PCF8574  pcf8574_out(1,0x20,0xFF);     // 8 digital OUT
PCF8574  pcf8574_in (1,0x21,0xFF);     // 8 digital IN
PCF8574 *pIOEx[IOEX_NUM]={&pcf8574_out, &pcf8574_in}; // IO expander

//_______Definitions for railroad components____________________
//.......values for every railroad component....................
// e.g. turnout, uncoupler, disconnectable track, ...
#define  NO_PIN         -1   // no pin @ PCF8574 (0...7)
#define  RC_TYPE_UC     1    // uncoupler (Entkuppler)
#define  RC_TYPE_TO     2    // turnout (Weiche)
#define  RC_TYPE_T3     3    // 3way turnout (Dreiwegweiche)
#define  RC_TYPE_DT     4    // disconnectable track (Fahrstrom)
#define  RC_TYPE_BL     5    // blink light (Blinklicht)

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
  int32_t msOn;         // ms on
  int32_t msOff;        // ms off
};

//_______Railroad commands______________________________________
// railway components:  type,name (max 3 char),dcc,
//                      pIOEx-out-index,outBitA,outBitB, 
//                      pIOEx-in-index inBitA inBitB
//                      msOn,msOff
// railway component name max. 3 chars
//-------disconnectable track (Fahrstrom)-----------------------
#define  RCOMP_1        RC_TYPE_DT,"DT", 11, EX0,PIN0,NO_PIN, EX1,PIN0,NO_PIN, 0,0
// ------two way turnout (Zweiwegweiche = Standardweiche)-------
// Two expander pins A B to control 2way turnout (active low!)
// A=0: curved, B=0: stright
#define  RCOMP_2        RC_TYPE_TO,"T2", 12, EX0,PIN1,PIN2,   EX1,PIN1,PIN2, 500,0

//.......Array of all railway components........................
#define  RCOMP_NUM      2
strRcomp aRcomp[RCOMP_NUM] = {
 {RCOMP_1},{RCOMP_2}
};
#endif
```   

4. Anpassung der Textdatei `rcc_module01_V1_text.h`   
```   
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
   VERSION_01_1, \
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
   VERSION_01_1, \
   " Next: Button IO19   ", \
  }

 #endif
#endif
```   

5. ESP32 an den USB anschließen und die Software hochladen.   

## 3.3 Neue Verkabelung





## 1.4 Elektronische RCC-Komponenten
### 1.4.1 Steuerung
F&uuml;r die Steuerung wird der ESP32 mit den beiden Zusatzplatinen (I²C, DCC) und dem 1,54"-OLED-Display verwendet. Der Zusammenbau ist auf   
[`https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/LIESMICH.md`](/fab/rcc2_esp32/LIESMICH.md)   
beschrieben.   

### 1.4.2 Anschluss der 25-poligen Stecker
F&uuml;r den Anschluss der 25-poligen Stecker und f&uuml;r die Stromversorgung werden folgende best&uuml;ckte Leiterplatten ben&ouml;tigt:   
* 1x [Netzteil-Platine AC_5V_supply_6pol_DCC](/fab/rcc1_supply/LIESMICH.md#x20)   
* 1x [Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (RW_5V_SUB25_10)](/fab/rcc1_supply/LIESMICH.md#x33)   
* 1x [Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (CON_SubD_Screw10)](/fab/rcc1_supply/LIESMICH.md#x34)   

Die best&uuml;ckte Netzteil-Platine muss auf die Tr&auml;gerplatine `RW_5V_SUB25_10` montiert werden.   

### 1.4.3 Ansteuerung der Schaltkomponenten
F&uuml;r die Ansteuerung der Schaltkomponenten werden folgende Schaltbl&ouml;cke ben&ouml;tigt:   
* 8x [Halterung f&uuml;r Schaltbl&ouml;cke](/fab/rcc5_add_ons/LIESMICH.md#x20)   
* 1x [Block Dreiwegweiche (W3)](/fab/rcc4_block/LIESMICH.md#x30)   
* 2x [Block Zweiwegweiche (W2)](/fab/rcc4_block/LIESMICH.md#x20)   
* 1x [Block Entkuppler (1OUT)](/fab/rcc4_block/LIESMICH.md#x40)   
* 4x [Block Abschaltbares Gleis (2IO)](/fab/rcc4_block/LIESMICH.md#x50)   

Weiters werden 30 LED-Fassungen ben&ouml;tigt.   

### 1.4.4 I²C-Expander
* 4x [PCF8574 I/O-Expander](/fab/rcc0_start/LIESMICH.md#34)   

### 1.4.5 Verdrahtung
Zum Anschluss der Schaltkomponenten sinnvoll sind folgende Zusatzplatinen:   
* 1x [`CON_2pol_141` Fahrstromverteiler](/fab/rcc5_add_ons/LIESMICH.md#x60)   
* 2x [`CON_1xIO` Fahrstromschalter einfach](/fab/rcc5_add_ons/LIESMICH.md#x70)   
* 1x [`CON_2xIO` Fahrstromschalter doppelt](/fab/rcc5_add_ons/LIESMICH.md#x80)   
* 8x [`CON_10pol_PIN` oder `CON_10pol_2x4` Umsetzer 10-poliges Kabel auf Stifte](/fab/rcc5_add_ons/LIESMICH.md#x30)   
* 3x [`CON_6pol_3` 6-poliger Stecker auf drei Schraubklemmen](/fab/rcc5_add_ons/LIESMICH.md#x40)   
* 2x [`CON_6pol_6` 6-poliger Stecker auf sechs Schraubklemmen](/fab/rcc5_add_ons/LIESMICH.md#x50)   

__Dr&auml;hte, Leitungen und Stecker__   
* ca. 4 m Volldraht 22awg (0,32 mm²) rot   
* ca. 4 m Volldraht 22awg (0,32 mm²) braun   
* ca. 3 m Flachbandkabel 6-polig   
* ca. 2 m Flachbandkabel 10-polig   
* ca. 60 cm 10-poliges Kabel 10 x 1 mm²   
* 4x 10-poliges Flachbandkabel mit Buchsen Female-Female 10 cm lang (Dupont Jumper Wire Cable)   
* 1x 10-poliges Flachbandkabel mit Buchsen Female-Female 15 cm lang (Dupont Jumper Wire Cable)   
* 2x vier Kabel Male-Female 30 cm lang (orange, gelb, gr&uuml;n, blau)   
-----   
* 28x IDC Buchsen-Stecker f&uuml;r Flachbandkabel 6-polig   
* 16x IDC Buchsen-Stecker f&uuml;r Flachbandkabel 10-polig   
* 8x L&uuml;sterklemmen   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Bau des Modul-Rahmens   
## 2.1 Einleitung
Jedes Modul besteht aus einem Rahmen mit Querverbindungen und der Grundplatte, die die Gleise und Landschaft enth&auml;lt. Zuerst sollte man den Modul-Rahmen erstellen. Das hat zwei Vorteile:   
1. Der Test, ob die Grundplatte in den Rahmen passt, kann mit der leeren Grundplatte erfolgen. Falls die Grundplatte zu gro&szlig; ist, kann sie einfach zugeschnitten oder zugeschliffen werden.   
2. Beim Aufkleben der Gleise auf die Grundplatte sind an den Modul&uuml;berg&auml;ngen (Ost und West) bereits die Seitenteile mit den Gleisausnehmungen vorhanden. So sind die Gleise beim Aufkleben sicher an der richtigen Position.   

Das folgende Bild zeigt den Grundriss des Modulrahmens:   

![Modul-Rahmen](./images/300_module_frame.png "Modul-Rahmen")   
_Bild 5: AnyRail-Darstellung des Rahmengrundrisses mit den Au&szlig;enteilen (Ra1 bis Ra4) und Querverstrebungen (Ri1, Ri2, Ri3)_

Die einzelnen Teile des Rahmens m&uuml;ssen vor dem Zusammenbau entspechend den nachfolgenden Beschreibungen bearbeitet werden.   

## 2.2 Seitenteile Ra1, Ra3 (West, Ost)
Die Seitenteile sind an eine (ehemalige?) Norm von n-spur.at angelehnt, wobei das Bahnk&ouml;rper-Profil aber der NEM122 entspricht:   

![Modul_OstWest_1_Mitte.png](./images/300_OstWest_1_Mitte.png "Modul_OstWest_1_Mitte")   
_Bild 6: Ma&szlig;e f&uuml;r die Seitenteile Ost und West (Modulbreite 250mm, ein in der Mitte liegendes Gleis)._   

* Ausgangsmaterial: Pappelsperrholzplatte 10 mm, 250 x 70 mm²   
* Die vier 8mm-Bohrungen dienen zum Verbinden der Module mit 8 mm-Fl&uuml;gelschrauben und Fl&uuml;gelmuttern.   
* Die linken und rechten vier 2 mm-Bohrungen dienen zum Anschrauben der Nord- und S&uuml;dwand. Sie m&uuml;ssen mit einem Kegelsenker erweitert werden, damit die Senkkopfschrauben nicht vorstehen.   
* Die oberen zwei 2mm-Bohrungen dienen zum Fixieren der Gel&auml;nde-Grundplatte (falls erforderlich). Auch sie m&uuml;ssen mit einem Kegelsenker erweitert werden, damit die Senkkopfschrauben nicht vorstehen.   
* Die 60x20 mm²-Ausnehmung dient zum Durchf&uuml;hren des 25-poligen Sub-D-Steckers.   

Mit besonderer Vorsicht ist die Ausnehmung f&uuml;r das Gleis zu fertigen. Mit einer Laubs&auml;ge wird die Ausnehmung etwas zu klein ausgeschnitten und mit einer Dreiecksfeile so lange erweitert, bis ein Fleischmann-Schotterbett-Gleis gerade (klemmend) hineinpasst und auch mittig positioniert ist.   

## 2.3 Rahmenteil Ra2 (Nord)
Der Rahmenteil „Nord“ enth&auml;lt lediglich dreimal zwei Bohrungen mit 2 mm Durchmesser, die wieder mit einem  Kegelsenker erweitert werden. Hier werden innen die Querverstrebungen verschraubt.   

![Modul_Nord_980mm](./images/300_Nord_980mm.png "Modul_Nord_980mm")   
_Bild 7: Seitenteil Nord Ra2_   

<a name="x24"></a>   

## 2.4 Rahmenteil Ra4 (S&uuml;d)
Der Rahmenteil S&uuml;d ist am aufw&auml;ndigsten zu fertigen, da er das Display, einen Taster und die Bohrungen f&uuml;r alle Steuerbl&ouml;cke und f&uuml;r alle Querverstrebungen enth&auml;lt. Das folgende Bild gibt einen &Uuml;berblick &uuml;ber die erforderlichen Bohrungen.   

![Modul_S&uuml;d_980mm](./images/300_Sued_980mm.png "Modul_S&uuml;d_980mm")   
_Bild 8: Ma&szlig;e f&uuml;r den Rahmenteil S&uuml;d (Ra4)_   

__OLED-Anzeige__   
Die Aussparungen f&uuml;r die OLED-Anzeige und den dazugeh&ouml;rigen Taster sind abh&auml;ngig davon, ob man die Bauteile einzeln montiert oder einen 3D-Druck-Rahmen verwendet. Bei getrennter Montage ben&ouml;tigt man eine rechteckf&ouml;rmige Aussparung der Gr&ouml;&szlig;e 20 x 38 mm² und eine 11,6 mm-Bohrung.   
![OLED_Button_single](./images/300_OLED_Button_single.png "OLED_Button_single")   
_Bild 9: Ma&szlig;e f&uuml;r die getrennte Montage der OLED-Anzeige und des Tasters_   

Bei Verwendung eines 3D-gedruckten Rahmens ben&ouml;tigt man eine rechteckf&ouml;rmige Aussparung der Gr&ouml;&szlig;e 80 x 43 mm².   
![OLED_Button_frame](./images/300_OLED_Button_frame.png "OLED_Button_frame")   
_Bild 10: Ma&szlig;e f&uuml;r den Rahmen der OLED-Anzeige mit Taster_   

__Steuerbl&ouml;cke__   
Je nach Art des Steuerelementes werden unterschiedliche Bohrungen ben&ouml;tigt. So zeigt das Symbol der Dreiwegweiche W3 nach rechts (6 Bohrungen), das der ersten Zweiwegweiche W2 nach links unten (4 Bohrungen) und das des Entkupplers 1OUT nach rechts (4 Bohrungen). Es folgen die drei Schaltsymbole f&uuml;r die Fahrstromabschaltung 2IO (7 Bohrungen) und das Schaltbild der zweiten Zweiwegweiche W2 nach rechts oben (4 Bohrungen).   
Die genaue Lage aller Bohrungen f&uuml;r einen Schaltblock zeigt das folgende Bild, wobei je nach Schaltblock-Typ nur die entsprechenden Bohrungen ben&ouml;tigt werden (!):   

![Bohrposition LEDs und Taster](./images/300_drill_position_LED_button.png "Bohrposition LEDs und Taster")   
_Bild 11: Ma&szlig;e f&uuml;r die LED- und Taster-Bohrungen_   

Der Bohrdurchmesser f&uuml;r die LED-Fassungen betr&auml;gt 5,6 mm, der f&uuml;r die Taster ca. 7 mm.   

Das einzelne Anzeichnen der Positionen der Bohrungen ben&ouml;tigt viel Zeit und genaues Arbeiten. Daher macht es Sinn, f&uuml;r die Schaltbl&ouml;cke Abdeckungen (Beschriftungen) zu entwerfen, diese auf Etikettenpapier auszudrucken und auf das Holz aufzukleben (Abstand zum unteren Rand 8 mm). Damit ist das Bohren wesentlich einfacher. Die Beschriftungen k&ouml;nnen entweder beibehalten oder entfernt werden, wenn man sie nicht m&ouml;chte. Falls die Beschriftungen zu stark durch das Bohren besch&auml;digt wurden, kann man sie auch durch neue ersetzen....   

Das folgende Bild zeigt die 40 x 42 mm gro&szlig;en Abdeckungen.   
 
![Beschriftung Bedienungselemente](./images/300_M12_cover.png "Beschriftung Bedienungselemente")   
_Bild 12: Beschriftung der Bedienungselemente f&uuml;r Modul 12_   

__LED-Fassungen__   
Nach dem Bohren sind die Bohrungen zu reinigen und die LED-Fassungen einzupressen.   

__Halterungen f&uuml;r Steuerbl&ouml;cke__   
Als N&auml;chstes kann man die Halterungen f&uuml;r die Steuerbl&ouml;cke mit 2,6 x 8 mm Schrauben anschrauben. Der Abstand der Bl&ouml;cke von der Unterseite des Rahmens sollte 5,5 mm betragen, allerdings ist die Lage der Halterungen meist durch die LED-Fassungen bereits vorgegeben...   

Die Position der Schrauben f&uuml;r die Steuerblock-Halterungen auf der Innenseite des Rahmens ist folgenderma&szlig;en festgelegt:   
![Schraubposition f&uuml;r Blockhalter](./images/300_blockholder_mountingholes.png "Schraubposition f&uuml;r Blockhalter")   
_Bild 13: Position der Schrauben f&uuml;r die Steuerblock-Halterungen_   

Den fertigen Rahmenteil S&uuml;d (ohne Fahrstromabschaltung Gleis 1A) zeigen die folgenden Bilder   
![Rahmenteil S&uuml;d Forderseite](./images/300_Frame_South_front.png "Rahmenteil S&uuml;d Forderseite")   
_Bild 14: Rahmenteil S&uuml;d Forderseite_   

![Rahmenteil S&uuml;d R&uuml;ckseite](./images/300_Frame_South_back.png "Rahmenteil S&uuml;d R&uuml;ckseite")   
_Bild 15: Rahmenteil S&uuml;d R&uuml;ckseite_   

## 2.5 Querverstrebung Ri1 bis Ri3
Die Querverstrebungen enthalten verschiedene Durchbr&uuml;che f&uuml;r Kabel und zwei Bohrungen f&uuml;r die Halterung der 25-poligen Sub-D-Stecker.   

![Verstrebung](./images/300_Verstrebung_230mm.png "Verstrebung")   
_Bild 16: Querverstrebungen Ri1 bis Ri3_

## 2.6 Halterung f&uuml;r Sub-D-Stecker
Die Halterung f&uuml;r einen SUB-D-Stecker besteht aus zwei U-f&ouml;rmigen Teilen, die links und rechts an einer Querstrebe angeschraubt werden. Die Teile k&ouml;nnen sowohl aus Holz als auch mit 3D-Druck hergestellt werden. F&uuml;r den Modul M12 werden zwei Halterungen ben&ouml;tigt.   

![Sub-D-Halterung](./images/300_bracket_sub-d.png "Sub-D-Halterung")   
_Bild 17: Ma&szlig;e der Halterung_   

In jeden U-f&ouml;rmigen Teil werden von unten zwei Kreuzschlitz-Senkkopf-Schrauben M 2,6 x 16 mm eingeschraubt und durch eine 2,5 mm Sechskantmutter gesichert. Die Schrauben dienen zum Festschrauben der Versorgungsplatine.   
Die beiden U-f&ouml;rmigen Halterungen werden mit M3 x 35 mm Schrauben und 3mm Sechskantmutter gegeneinander an einer Querstrebe verschraubt.   

![Teile der Sub-D-Halterung](./images/300_bracket_parts.png "Teile der Sub-D-Halterung")   
_Bild 18: Teile der Sub-D-Halterung_   

## 2.7 Zusammenbau des Rahmens
Nachdem alle Teile des Rahmens bearbeitet wurden, kann dieser zusammengeschraubt werden.   

![Rahmen Ansicht von unten](./images/300_M12_frame_bottom_view.png "Rahmen Ansicht von unten")   
_Bild 19: Zusammengeschraubter Rahmen, Ansicht von unten_   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Aufbau des Gleisplans   

## 3.1 Stellprobe   
Der Probeaufbau erfolgt auf der 5 mm (bzw. 4 mm) Sperrholzplatte. Dazu wird der Gleisplan im Ma&szlig;stab 1:1 auf diese gezeichnet. Das kann entweder durch Ausdruck des Gleisplans im Ma&szlig;stab 1:1 und &uuml;bertragen auf das Sperrholz erfolgen (zB mit Kohlepapier), oder durch &Uuml;bertragen der Koordinaten auf das Sperrholz und Zeichnen des Gleisplans.   
Entsprechend dem Gleisplanentwurf m&uuml;ssen die Trennstellen in jeweils beiden Schienenstr&auml;ngen hergestellt werden. Dazu werden Fleischmann 9403 Isolier-Schienenverbinder verwendet. Die bisherigen Gleisverbinder werden entfernt und durch die Isolier-Schienenverbinder ersetzt.   
Danach werden die Gleise entsprechend dem Gleisbild zusammengesteckt.   
Beim Probeaufbau sollten auch alle bahnspezifischen Bauwerke (wie Bahnhof, Bahnsteige, Verladerampe) aufgestellt werden, damit man wei&szlig;, wie der Bahnk&ouml;rper (die 5 mm bzw. 4 mm Platte) zugeschnitten werden muss.   
Schlie&szlig;lich wird mit dem l&auml;ngsten Waggon h&auml;ndisch eine Probefahrt durchgef&uuml;hrt und kontrolliert, ob alle Radien, &Uuml;berg&auml;nge etc. passen und keine Geb&auml;ude im Wege stehen.   

## 3.2 Zuschneiden und Aufkleben des Bahndamms auf die Grundplatte   
War die Stellprobe erfolgreich, folgen &Uuml;berlegungen zu den einzelnen Gel&auml;ndeh&ouml;hen.   
* An beiden Seiten des Moduls (Ost und West) ist die Gel&auml;ndeh&ouml;he null (E0). Ausgenommen davon ist der Bahndamm und das Schotterbett des Gleises, das in den Modul f&uuml;hrt.   
* Das Schotterbett liegt auf der Ebene E5 (= 5 mm Sperrholz). Der &Uuml;bergang zu Ebene E0 erfolgt &uuml;ber Schr&auml;gen mit 45 Grad.   
* Die Fleischmann-Gleise liegen auf Niveau E8. Dazu wird auf das 5 mm-Sperrholz das 3 mm hohe Schaumstoff-Gleisbett (Fa. Noch Nr. 95962 oder Kork) aufgeklebt. Der Schaumstoff d&auml;mpft auch etwas das Fahrger&auml;usch (Schallschutz).   
* Bahnhofsgeb&auml;ude, Bahnsteige oder Verladerampen stehen normalerweise auf Niveau E8. An diesen Stellen sollte man das 5 mm-Sperrholz ausschneiden und gleich 8 mm hohes Sperrholz einsetzen und nicht die H&ouml;he schichtweise aufzubauen.   
* Stra&szlig;en, die die Gleise &uuml;berqueren, haben als Oberkante E12.   

Hat man entschieden, wo welche Sperrholz-H&ouml;hen eingesetzt werden, schneidet man die entsprechenden Platten zu und klebt sie auf die Grundplatte. Dazu sollte sich die Grundplatte im Rahmen befinden, damit man den Gleisanschluss am linken und rechten Rand genau herstellen kann.   

Sollen die Weichenantriebe als Unterflurantriebe verbaut werden, m&uuml;ssen noch Aussparungen ausgeschnitten werden.   

![Ma&szlig;e der Aussparung f&uuml;r Unterflurantrieb](./images/300_turnout_cutout_right.png "Ma&szlig;e der Aussparung f&uuml;r Unterflurantrieb")   
_Bild 20: Ma&szlig;e der Aussparung f&uuml;r einen Unterflurantrieb._   

Die folgenden beiden Bilder zeigen die verschiedenen Ebenen des Gel&auml;ndes und die Aussparungen f&uuml;r die Weichen. Links vorne und rechts hinten ist das Niveau E0, in der Mitte und hinten (im Bild oben) ist 8 mm hohes Sperrholz (E8).   
![Bahndamm2](./images/300_Bahndamm2.png "Bahndamm2")   
![Bahndamm](./images/300_Bahndamm.png "Bahndamm")   
_Bild 21: Verschiedene Modul-Ebenen_

## 3.3 Bettungsk&ouml;rper (Schotterbett)
Im n&auml;chsten Schritt wird das 3 mm hohe Schaumstoff-Gleisbett (Fa. Noch Nr. 95962 oder Kork) aufgeklebt. Dies erfolgt nicht nur an Stellen, wo sp&auml;ter ein Gleis verl&auml;uft, sondern auch an Stellen, die das gleiche Niveau haben sollen, zB zwischen den Gleisen oder dort, wo sp&auml;ter der Antrieb f&uuml;r den Entkuppler hinkommt.   
Danach bohrt man mit einem 4 mm Bohrer die L&ouml;cher f&uuml;r die Fahrstromzuf&uuml;hrung. Wenn man eine 1:1 Vorlage des Gleisbildes ausgedruckt hat, so kann man diese als Bohrschablone verwenden.   
Das folgende Bild zeigt den Modul mit Schaumstoff-Bett, Ausnehmungen f&uuml;r die Weichenantriebe und die Bohrungen f&uuml;r die Fahrstromzuf&uuml;hrung.   

![Schotterbett](./images/300_Schotterbett1.png "Schotterbett")   
_Bild 22: Grundplatte mit Bahndamm, Gleisbett (schwarz), Bohrungen f&uuml;r Fahrstrom und Weichenausschnitten_   

## 3.4 Vorbereitung der Verdrahtung
### Montage der Schaltbl&ouml;cke   
Bevor die Schienen verlegt werden, sollte die Verdrahtung vorbereitet werden (damit die Gleise nicht besch&auml;digt werden). F&uuml;r ein leichteres Arbeiten entfernt man zuerst die Grundplatte vom Rahmen und montiert die Schaltbl&ouml;cke. Dazu steckt man einen Schaltblock in die Schaltblock-Halterung und schraubt ihn mit vier M2 x 20 mm Schrauben fest (Schrauben nicht zu fest anziehen!).    
![Schaltblockmontage](./images/300_Schaltblockmontage.png "Schaltblockmontage")   
_Bild 23: Anschrauben der Schaltbl&ouml;cke_   

Weiters montiert man auf die erste und dritte Querstrebe die Halterung f&uuml;r die Sub-D-Stecker. Sollte dabei eine Fahrstromzuf&uuml;hrung genau unter einer Halterung liegen, so muss man die Stromzuf&uuml;hrung nochmals bohren....   

### Montage der Anzeige und des Mikrocontrollers   
Die OLED-Anzeige und den Mikrocontroller, wie bei [Rahmenteil Ra4 (S&uuml;d)](#x24) beschrieben, in den Rahmen einsetzen.   

## Montage der I²C-I/O-Expanderplatinen
1. Segment 2: Montage von zwei I²C-PCF8574-I/O-Expanderplatinen und den Hilfsplatinen `CON_i2c_20mm`. Einstellen der Adressen 0x20 und 0x21 mit Hilfe der Jumper.   
2. Segment 3: Montage von zwei I²C-PCF8574-I/O-Expanderplatinen und den Hilfsplatinen `CON_i2c_20mm`. Einstellen der Adressen 0x22 und 0x23 mit Hilfe der Jumper.   

### Montage der Schraubklemmen   
Um die Verkabelung des Moduls &uuml;bersichtlich zu gestalten, werden 2x2 L&auml;ngslinien (Abstand vom Rand 4 cm und 5,5 cm) gezeichnet, die genau durch die Durchf&uuml;hrungen der Querverbinder f&uuml;hren. In diesem Bereich werden die Kabel gef&uuml;hrt. Nun setzt man die Grundplatte wieder in den Rahmen ein.   
F&uuml;r die Platzierung der Klemmen gilt allgemein:   
* I²C-Komponenten (zB die Prints mit 10-poligem Wannenstecker) werden in der N&auml;he der Schaltbl&ouml;cke montiert (im folgenden Bild oben zu sehen). Die Montage sollte aber nicht zu Nahe an den Schaltbl&ouml;cken erfolgen, damit man im Fehlerfall die Schaltbl&ouml;cke noch leicht abschrauben kann.   
* Fahrstromkomponenten (zB Prints mit 6-poligem Wannenstecker) auf der den Schaltbl&ouml;cken gegen&uuml;berliegenden L&auml;ngsseite ("hinten", im Bild unten) und 
* Weichenanschl&uuml;sse in der N&auml;he der Weichen.   

Das folgende Bild zeigt die montierten Klemmen.   

![M12_Verdrahtung_1](./images/300_M12_Verdrahtung1.png "M12_Verdrahtung_1")   
_Bild 24: Schraubklemmen f&uuml;r die Verdrahtung_   

#### Montage der Schraubklemmen etc. im Detail    
1. Beschriften der Bohrungen f&uuml;r die Fahrstromzuf&uuml;hrung:   
   Segment 1: GW-1, GW-2,G1A-1   
   Segment 2: E1, G2-1, G1-1   
   Segment 3: G1-2, G2-2, G3-1   
   Segment 4: GO-1, GO-2   
2. Alle Prints werden mit M2 x 10 mm Schrauben, L&uuml;sterklemmen mit M2,6 x 12 mm Schrauben angeschraubt.   
3. Die Gleise der Ein- und Ausfahrt eines Moduls werden immer direkt mit dem Fahrstrom verbunden. Mit dem Stromverteiler-Print `CON_2pol_141_V1` stehen zus&auml;tzliche Klemmen f&uuml;r die Fahrstromverteilung zur Verf&uuml;gung (Gr&uuml;ner Balken unten im 2. Segment von links)   
4. Die Prints 2x `CON_1xIO_V1` und 1x `CON_2xIO_V1` dienen dem Schalten des Fahrstroms (gemeinsam mit den Schaltbl&ouml;cken `2IO`) (unten im Bild 21).   
5. Je vier Prints `CON_10pol_PIN_V2` im Segment 2 und 3 stellen die Ein- und Ausgangspins der 10-poligen Schaltblock-Ausg&auml;nge f&uuml;r die I²C-Verdrahtung zur Verf&uuml;gung.   
6. Im Segment 2 und 3 sind je zwei PCF 8574-I/O-Prints montiert (einer f&uuml;r die Ausgangs- und einer f&uuml;r die Eingangssignale).   
7. Der Anschluss der Weichen und des Entkupplers erfolgt an Prints 3x `CON_6pol_3_V1` bzw. 1x `CON_6pol_6_V1` (f&uuml;r Dreiwegweiche).   

## 3.5 Gleisbau
### Anbringen der Stromversorgung am Gleis   
Zur Stromversorgung kann man Fleischmann 22217 Anschlu&szlig;kabel 2pol. Spur N verwenden oder man l&ouml;tet selbst Dr&auml;hte an die Gleisverbinder. Dies geht f&uuml;r Fleischmann-Schotterbett-Gleise sehr gut, w&auml;hrend die Verbinder von Gleisen ohne Schotterbett praktisch nicht l&ouml;tbar sind.   
Als Anschlussdraht verwendet man einen ca. 30 cm langen braunen Volldraht mit 0,32 mm² (22awg) f&uuml;r die n&ouml;rdliche Schiene und einen roten Draht f&uuml;r die s&uuml;dliche Schiene. Der Draht wird beidseitig ca. 6 mm abisoliert und f&uuml;r den Gleisverbinder-Anschluss hakenf&ouml;rmig gebogen, mit einer kleinen Zange etwas flachgedr&uuml;ckt und verzinnt.   
Dazu fixiert man am besten das Gleis mit einem Klebestreifen, schneidet mit einem Stanley-Messer die kleine Verbindung &uuml;ber dem Gleisverbinder heraus (damit man leichter l&ouml;ten kann ;) ), und verzinnt den Gleisverbinder. Im Bild unten sieht man rechts unten die kleine Plastikverbindung &uuml;ber dem Gleisverbinder, der rechts oben entfernt ist.   

![Loeten_Gleisanschluss1](./images/300_Loeten_Gleisanschluss1.png "Loeten_Gleisanschluss1")   
_Bild 25: Vorbereitung des Anl&ouml;tens einer Stromzuf&uuml;hrung._   

### Gleise aufkleben   
#### Vorbereitung der Weichen   
Um den Antrieb als Unterflurantrieb zu verwenden, muss man den Schalthebel der Weiche herausziehen und um 180° gedreht wieder einstecken. Danach kann der Antrieb mit der Oberseite nach unten aufgesteckt werden.   
#### Vorbereitung Stromzuf&uuml;hrung   
Verwendet man die Stromzuf&uuml;hrungskabel Fleischmann 22217, so muss man immer oberhalb der Kontaktstelle eine Bohrung setzen (4 mm), um die Kabel nach unten durchf&uuml;hren zu k&ouml;nnen.   
Bei selbst gel&ouml;teten Stromzuf&uuml;hrungen muss jeweils direkt unter jedem Gleisverbinder eine Bohrung gesetzt werden.   
#### Vorbereitung Entkupplungsgleis   
F&uuml;r den Antrieb des Entkupplungsgleises 9112 (oder 22212) muss ebenfalls eine 4 mm-Bohrung gesetzt werden.   
#### Gleise aufkleben   
Alle Kabel in die Bohrungen einf&auml;deln und nach unten ziehen, bis die Gleise etwa 5 bis 10 cm Abstand zur zuk&uuml;nftigen Position haben. Die Grundplatte etwas schr&auml;g stellen, damit die Kabel nicht geknickt werden.   
Alle Bereiche markieren, auf die kein Leim aufgetragen werden darf (oder mit Klebeband abdecken):   
* Weichenantrieb   
* Entkupplungsgleis   
* Ausgleichsgleise am linken und rechten Rand (Ost und West)   

Das Gleisbett mit Leim versehen. Dabei ist zu beachten, dass im Bereich der Weiche und des Entkupplungsgleises m&ouml;glichst wenig Leim (oder gar kein Leim) aufgebracht wird, damit kein Leim in die Antriebe gelangt und diese verklebt!   
Da die Ausgleichsgleise zur Anpassung von Abst&auml;nden an den Modulgrenzen dienen, darf in diesem Bereich ebenfalls KEIN Leim aufgebracht werden!   
Danach die Gleise fertig zusammenstecken und vorsichtig an den Kabeln ziehen, bis die Gleise auf dem Leim liegen.   
Da die beiden Ausgleichsgleise am linken und rechten Rand im Betrieb mechanisch in L&auml;ngsrichtung beansprucht werden, sollten sie mit je einem Gleisnagel zus&auml;tzlich fixiert werden. Dabei muss der Gleisnagel an der vom Rand entfernten Gleisseite eingeschlagen werden.   

Das Modul mit eingesetzter Grundplatte und Gleisen sieht folgenderma&szlig;en aus:   
![Montiertes Gleis](./images/300_Gleis_montiert1.png "Montiertes Gleis")   
_Bild 26: Rahmen mit Grundplatte und Gleisen._   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Elektrische Verdrahtung des Moduls   

## 4.1 Verdrahtung der Stromversorgung und des Fahrstroms
1. Verbinden des Anschlusses "POWER" der Versorgungsplatine `RW_5V_SUB25_10` mit den acht Schaltbl&ouml;cken mit einem 6-poligen, ca. einen Meter langen Flachbandkabel und 10 montierten Pfostenverbindern. Der erste Pfostenverbinder dient zum Anschluss an die Versorgungsplatine, der Pfostenverbinder am Ende der Leitung dient einem eventuell erforderlichem Verl&auml;ngern des Flachbandkabels bzw. zum Anschluss von 100 nF-Kondensatoren zwischen V+ und V- sowie 5V und 0V. (Der Stecker ist im _Bild 27_ rechts oben noch nicht angebracht...)   
![Abschlusskondensatoren](./images/300_powerline_2xC.png "Abschlusskondensatoren")   
_Bild 27: Abschlusskondensatoren am Ende des POWER-Kabels_   

2. Verbinden aller Fahrstromanschl&uuml;sse mit den entsprechenden Klemmen.   
3. Verbinden des Fahrstroms (NN, SS) von der Versorgungsplatine `RW_5V_SUB25_10` zu den Platinen `CON_2pol_141`, `CON_1xIO`, `CON_2xIO` sowie den L&uuml;sterklemmen GW (Gleis West) und GO (Gleis Ost).   
4. Verbinden der Anschl&uuml;sse der beiden Weichenantriebe der Dreiwegweiche mit der Platine `CON_6pol_6` (linke Weiche = Antrieb n&auml;her zu den Schaltbl&ouml;cken = Pin 1 und 3, Masse an Pin 2).   
5. Verbinden der Anschl&uuml;sse der beiden Zweiweg-Weichenantriebe mit den Platinen `CON_6pol_3` (Masse = schwarzes Kabel an Pin 2).   
6. Verbinden der Anschl&uuml;sse des Entkupplers mit der Platine `CON_6pol_3`.   
_Wichtig_: Da der Entkuppler St&ouml;rspannungen erzeugt, muss ein 100 nF-Kondensator parallel zu den Klemmen V+ und V- geschaltet werden.   
![Entst&ouml;rkondensator](./images/300_uncoupler_C.png "Entst&ouml;rkondensator")   
_Bild 28: Entst&ouml;rkondensator am Entkuppler_   

Die Verdrahtung der Stromversorgung im &Uuml;berblick:   

![Verdrahtung 1](./images/300_Verdrahtung1.png "Verdrahtung 1")   
_Bild 29: Verdrahtung Stromversorgung_   

### Erster Test der Verdrahtung   
Mit der bisherigen Verdrahtung ist es bereits m&ouml;glich, einen h&auml;ndischen Betrieb durchzuf&uuml;hren. Dabei kann vor allem der richtige Anschluss der Weichen und die Funktion aller Stromzuf&uuml;hrungen (L&ouml;tstellen) getestet werden.   
1. Anstecken eines 25-poligen Steckers mit Fahrstrom- und Wechselstromversorgung: Die LEDs der Schaltbl&ouml;cke sollten leuchten.   
2. Test der Ansteuerung der Dreiwegweiche Links-Mitte und Mitte-Rechts. Falls ein Fehler auftritt: Anschl&uuml;sse 1 und 3 vertauschen.   
2. Test der Ansteuerung der Zweiwegweichen. Stimmt die Anzeige-LED f&uuml;r Gerade und Abzweig? Schaltet die Weiche entsprechend dem Taster auf "Gerade" oder "Abzweig"? Falls nicht: Anschl&uuml;sse 1 und 3 vertauschen.   
3. Arbeitet der Entkuppler?   
4. Stimmen alle LED-Anzeigen mit der entsprechenden Hardware &uuml;berein?   
5. Fahrstrom Gleis 1, 2, 3 und 1A mit den gr&uuml;nen Tastern einschalten, Probefahrt mit einer Lokomotive &uuml;ber alle Gleise.   

## 4.2 Vorbereitung Mikrocontroller
1. Verbinden des Anschlusses "DCC" der Versorgungsplatine `RW_5V_SUB25_10` mit dem Mikrocontroller &uuml;ber ein ca. 30 cm langes, 6-poliges Kabel.   
2. Verbinden des Mikrocontrollers mit den I²C-PCF8574-I/O-Expanderplatinen mit 20 cm langen, 4-poligen Kabeln mit male-female-Steckern.   
3. Programmierung des Mikrocontrollers mit der Software `rcc_module12_V1`.   

## 4.3 Verdrahtung I²C-Bus
1. Verbinden der acht 10-poligen Stecker der Schaltbl&ouml;cke mit den 10-poligen Steckern der Platinen `CON_10pol_PIN`.   

2. Herstellung der Verbindungen zwischen den Stiftleisten der `CON_10pol_PIN`-Platinen und den I²C-PCF8574-I/O-Expanderplatinen mit 10 cm langen Leitungen female-female.    

Im Segment 2:   
   * I/O-Expander 0x20 - Pin 0 <---> Block DCC 129, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 1 <---> Block DCC 121/122, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 2 <---> Block DCC 121/122, Pin 2 - IN   
   * I/O-Expander 0x20 - Pin 3 <---> Block DCC 121/122, Pin 3 - IN   
   * I/O-Expander 0x20 - Pin 4 <---> Block DCC 123, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 5 <---> Block DCC 123, Pin 2 - IN   
   * I/O-Expander 0x20 - Pin 6 <---> Block DCC 124, Pin 1 - IN   
   -------   
   * I/O-Expander 0x21 - Pin 0 <---> Block DCC 129, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 1 <---> Block DCC 121/122, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 2 <---> Block DCC 121/122, Pin 2 - OUT   
   * I/O-Expander 0x21 - Pin 3 <---> Block DCC 121/122, Pin 3 - OUT   
   * I/O-Expander 0x21 - Pin 4 <---> Block DCC 123, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 5 <---> Block DCC 123, Pin 2 - OUT   
   * I/O-Expander 0x21 - Pin 6 <---> Block DCC 124, Pin 1 - OUT   

Im Segment 3:   
   * I/O-Expander 0x22 - Pin 0 <---> Block DCC 128, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 1 <---> Block DCC 128, Pin 2 - IN   
   * I/O-Expander 0x22 - Pin 2 <---> Block DCC 127, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 3 <---> Block DCC 126, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 4 <---> Block DCC 125, Pin 1 - IN   
   -------   
   * I/O-Expander 0x23 - Pin 0 <---> Block DCC 128, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 1 <---> Block DCC 128, Pin 2 - OUT   
   * I/O-Expander 0x23 - Pin 2 <---> Block DCC 127, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 3 <---> Block DCC 126, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 4 <---> Block DCC 125, Pin 1 - OUT   

## 4.4 Modulverbindung
Damit Module aneinandergereiht werden k&ouml;nnen m&uuml;ssen noch die 10 Schraubklemmen bei den 25-poligen Steckern miteinander verbunden werden.   
Nach NEM908D erfolgt dies so, dass die Leitungen elektrisch ausgekreuzt, aber physikalisch gerade durchverbunden werden. Das bedeutet, dass sich zB der Fahrstrom des Gleises NN auf dem West-Stecker auf dem Pin 1 und auf dem Ost-Stecker auf dem Pin 13 befindet!   
![Wiring_NEM908D](/images/300_Wiring_NEM908D.png "Wiring_NEM908D")   
_Bild 30: 25polige Sub-D Stecker auf dem Modul mit Pin-Belegung_   

[Siehe auch `/info/con_NEM908/LIESMICH.md`](/info/con_NEM908/LIESMICH.md)   

F&uuml;r die Verbindung der Pins kann zB 10-poliges Kabel verwendet werden.   

![Stecker West](./images/300_con10_west.png "Stecker West")   
_Bild 31: Verdrahtung Stecker West_   

![Stecker Ost](./images/300_con10_east.png "Stecker Ost")   
_Bild 32: Verdrahtung Stecker Ost_   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Probebetrieb
## 5.1 Modul-Start
1. MQTT-Server starten.   
2. Einen Laptop oder PC mit dem Netzwerk des MQTT-Servers verbinden und die Software `mosquitto_sub` in einem Kommando-Fesnster mit diesem Kommando starten:   
   `mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
3. Anstecken eines 25-poligen Steckers mit Fahrstrom- und Wechselstromversorgung: Die LEDs der Schaltbl&ouml;cke sollten entspechend der Hardware-Stellung richtig leuchten.   
4. Die Info-Seiten auf dem OLED mit dem neben liegenden Taster weiterschalten. Wenn alles funktioniert, erscheint auf dem OLED-Display folgende Anzeige:   
```   
  RCC Module 12     
MQTT OK    Raspi11  
rcc/module12        
G1A TWL TWR T1  E1  
Aus __  __  _/  Aus 
129 121 122 123 124 
```   

Die Anzeige der Stellung der Weichen 121 bis 123 ist abh&auml;ngig von der tats&auml;chlichen Stellung der Weichen. Die Anzeige wechselt alle 5 Sekunden weiter.   

5. Im Kommandofenster am Laptop erscheint die Startmeldung des Moduls:   
`rcc/start/mqtt {"topicbase":"rcc/module12"}`   

## 5.2 Test mit MQTT
Ein zweites Kommando-Fenster am Laptop &ouml;ffnen und folgendes eingeben:   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/get -m ?`   
Im ersten Kommando-Fenster werden die m&ouml;glichen Befehle angezeigt:   
```   
rcc/module12/get ?
rcc/module12/ret/?
get: ?|help|version|ip|topicbase|eeprom|byname|bydcc|G1A|129|TWL|121|TWR|122|T1|123|E1|124|G1|125|G2|126|G3|127|T2|128|
set: topicbase|eeprom0|G1A|129|TWL|121|TWR|122|T1|123|E1|124|G1|125|G2|126|G3|127|T2|128|
sub:
pub:
MQTT: ../set/w1 -m 1|g|G OR -m 0|A|a|B|b (set by name)
      ../set/11 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)
      ../get -m byname|bydcc (values of all components)
```   

### Beispiele f&uuml;r Schaltbefehle  
Schalten der Weiche DCC 123 auf Gerade:   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/123 -m 1`   

Schalten der Weiche DCC 123 mit Namen T1 auf Abzweig (Bogen):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/T1 -m 0`   

Einschalten des Fahrstroms im Gleis 2 (Durchfahrsgleis, DCC-Adresse 126):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/126 -m 1`   
Die Anzeige geht von "Aus" (LED rot) auf "Ein" (LED gr&uuml;n), sofern nicht einer der beiden Taster gedr&uuml;ckt ist.   

Einschalten des Entkupplers (DCC 124):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/124 -m 1`   
Der Entkuppler wird f&uuml;r 1,5 Sekunden eingeschaltet.   

## 5.3 Test mit DCC
Je nach DCC-Eingabeger&auml;t k&ouml;nnen die gleichen Aktionen wie mit MQTT durchgef&uuml;hrt werden.   
### Beispiel Roco Multi-Maus
* Weichensteuerung w&auml;hlen (Taste Lok/Weiche) ![Taste_Lok_Weiche](./images/50_taste_lok_weiche.png)   
* DCC-Adresse 123 eingeben ![Anzeige_W0123](./images/50_anzeige_W0123.png)   
* Mit den Pfeiltasten die Weiche schalten ![Pfeiltasten](./images/50_taste_pfeil.png)   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. Abschlie&szlig;ende Arbeiten   
## 6.1 Weichenabdeckungen   
F&uuml;r die Montage der Unterflur-Weichenantriebe muss die Grundplatte ausgeschnitten werden (siehe Bild 20 und 21). F&uuml;r die Landschaftsgestaltung m&uuml;ssen diese Ausschnitte jedoch gut abgedeckt werden, damit keine Schotterk&ouml;rner etc. in die Weichenantriebe gelangen. Auf dem Modul M12 werden zwei verschiedene Arten von Abdeckungen ben&ouml;tigt:   
* Drei flache Abdeckungen (ausgehend von Ebene E8)   
* Eine hohe Abdeckung f&uuml;r den rechten Antrieb der Dreiweg-Weiche (d.h. ausgehend von der Grundplatte E0)   

Bei den flachen Abdeckungen reichen die Weichenantriebe 1,5 mm &uuml;ber das Niveau E8 (Schaumstoff-Obergrenze):   
* 0,5 mm Metallplatte auf der Weichenunterseite + 0,5 mm Metall-Haltenasen + 0,5 mm H&ouml;henausgleich, falls die Weiche Oberflur montiert wird...   
Zum Abdecken des Ausschnitts kann daher eine 0,5 mm Kunststoff-Folie als Basisabdeckung sowie eine 1 mm Folie dar&uuml;ber + eine 0,5 mm Folie &uuml;ber dem Antrieb verwendet werden.   
Als Alternative ist auch 3D-gedruckte Abdeckungen m&ouml;glich, wie sie im _Bild 33_ zu sehen sind.   
![3D Weichenabdeckung](/images/300_3d_weichenabdeckung.png "3D Weichenabdeckung")   
_Bild 33: 3D-Druck-Abdeckungen der Weichenaussparungen_   

Die St&auml;rke der Abdeckungen betr&auml;gt 0,6 mm (= 3 Schichten), die Befestigung erfolgt mit Gleisn&auml;geln (0,7 mm Durchmesser). Die mittlere Abdeckung wurde mit einer Schere passend geschnitten.   

## 6.2 Bodenabdeckung   
Um die Verkabelung zu sch&uuml;tzen, kann man auch Teile des Bodens mit durchsichtigen Folien (zB mit 1 mm St&auml;rke) abdecken.   

## 6.3 Modell-Hintergrundbild   
Das Modellhintergrundbild sollte bei 25 cm Modultiefe zumindest 15,5 cm hoch sein.   

[Zum Seitenanfang](#up)
