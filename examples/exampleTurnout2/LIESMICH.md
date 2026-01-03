<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 3.1.2026 <a name="up"></a><br>   
<h1>Beispiel: Verdrahtung einer Zweiweg-Weiche</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Worum geht es hier?
Diese Anleitung beschreibt Schritt f&uuml;r Schritt die Entstehung des RCC-Systems zum Schalten einer Zweiweg-Weiche. Die Weiche wird durch einen elektrischen Weichenantrieb mit Endabschaltung gestellt (zB. Fleischmann 640000).  
Zu Beginn wird die Weiche direkt mit Wechselstrom aus einem Trafo geschaltet und danach werden der Reihe nach weitere Komponenten eingebaut, bis das Gesamtsystem fertig ist.   

Insgesamt gibt es folgende M&ouml;glichkeiten zum Schalten der Weiche:   
1. [Direktes Schalten der Weiche mit Wechselstrom](#x10)   
2. [Schalten der Weiche mit dem Schaltblock W2](#x20)   
3. [Schalten der Weiche von Hand und Anzeige des Schaltzustands auf dem Display](#x23)   
4. [Schalten der Weiche mit DCC-Befehlen](#x50)   
5. [Schalten der Weiche mit MQTT-Befehlen](#x60)   

<a name="x10"></a>   
<a name="x20"></a>   

# 1. Direktes Schalten der Weiche mit Wechselstrom

## 1.1 Direktes Verbindung der Weiche mit dem Trafo
Beim direkten Schalten einer Weiche mit Wechselstrom wird die Wechselspannung an einen Anschluss eine Spule der Weiche und an den R&uuml;ckleiter gelegt. Da die Anschlussdr&auml;hte der Weiche empfindlich sind, werden sie direkt an eine Hilfsplatine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40) geschraubt. Diese Platine dient im Weiteren als Verbindung der Weichenanschl&uuml;sse zum RCC-System.   

Das Schalten erfolgt durch Verbinden von Pin 1 oder Pin 5 mit Wechselspannung. Der R&uuml;ckleiter liegt fix an Pin 3.   
![W2_Direct_Switching1](./images/300_W2_DirectSwitching1.png "W2_Direct_Switching1")   
_Bild 1: Schaltplan zu "Direktes Schalten einer Zweiwegweiche"_   

#### Praktischer Aufbau
F&uuml;r den praktischen Aufbau werden folgende Mittel ben&ouml;tigt:   
1. Zweiwegweiche mit elektrischem Antrieb mit Endabschaltung, zB Fleischmann-Weiche 9170 und Antrieb 640000   
2. Modellbahn-Trafo mit Wechselspannungsausgang, zB Conrad BV00/026 oder Roco 0903 usw.   
3. Zwei Leitungen Stift-Buchse (L&auml;nge egal zB 30 cm)   
4. Eigenbau-Hilfsplatine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40)    

![W2_Direct_Switching2](./images/480_W2_DirectSwitching2.png "W2_Direct_Switching2")   
_Bild 2: Direktes Schalten einer Zweiwegweiche_   

[Zum Seitenanfang](#up)   

<a name="x12"></a>   

## 1.2 Direktes Schalten und Einspeisen der Wechselspannung &uuml;ber Sub-D-Stecker
In der [Norm NEM 908D](/info/con_NEM908/LIESMICH.md) wird die Verbindung von Eisenbahnmodulen durch 25-polige Sub-D-Stecker und Buchsen beschreiben. Daher ist es naheliegend, auch hier die Versorgungsspannung der Weiche &uuml;ber ein 25-poliges Buchsenkabel zuzuf&uuml;hren.   
Das folgenden Bilder zeigen die Verwendung des [25-poligen Steckers mit 5V-Netzteil](/fab/rcc1_supply/LIESMICH.md#x30) zum Einspeisen der Wechselspannung:   

![W2_Sub-D_1](./images/480_W2_Sub-D_1.png "W2_Sub-D_1")   
_Bild 3: Schaltplan zum Einspeisen der Wechselspannung &uuml;ber Sub-D-Stecker_   

Als Alternative zum Kabel mit Schraubklemmen und 25-poliger Sub-D-Buchse kann man auch die Platine [`CON_SubD_Screw10`](/fab/rcc1_supply/LIESMICH.md#x34) und ein 25-poliges Kabel mit beidseitigen Buchsen verwenden. In diesem Fall schaut der Schaltplan folgenderma&szlig;en aus:   

![W2_Sub-D_V2](./images/480_W2_Sub-D_V2a.png "W2_Sub-D_V2")   
_Bild 4: Schaltplan zum Einspeisen der Wechselspannung &uuml;ber Sub-D-Stecker - Version 2_   

### Praktischer Aufbau
F&uuml;r den praktischen Aufbau werden folgende Mittel ben&ouml;tigt:   
1. Zweiwegweiche mit elektrischem Antrieb mit Endabschaltung, zB Fleischmann-Weiche 9170 und Antrieb 640000   
2. Modellbahn-Trafo mit Wechselspannungsausgang, zB Conrad BV00/026 oder Roco 0903 usw.   
3. Zwei Leitungen Stift-Buchse (L&auml;nge egal zB 30 cm)   
4. Eigenbau-Hilfsplatine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40)    
5. Eigenbau-Platine [`RW_5V_SUB25_10`](/fab/rcc5_add_ons/LIESMICH.md#x40)    
6. Zwei Leitungen Stift-Stift (L&auml;nge egal zB 15 cm) zum Anschluss des Trafos am Zuleitungskabel   
7. 10-poliges Zuleitungskabel mit 8- (oder 10-) poliger Schraubklemme und 25-poliger Sub-D-Buchse   

![W2_Sub-D_2](./images/480_W2_Sub-D_2.png "W2_Sub-D_2")   
_Bild 5: Einspeisen der Wechselspannung &uuml;ber Sub-D-Stecker_   

Im _Bild 5_ ist links ein (10-poliges) graues Testkabel mit Schraubklemmen und 25-poliger Buchse (silber) zu sehen. Dieses ist an die Platine [`RW_5V_SUB25_10`](/fab/rcc1_supply/LIESMICH.md#x33) mit Sub-D-Stecker, Klemmenleiste und 5V-Netzteil angesteckt. Die zweipolige, rote Schraubklemme in der Klemmenreihe stellt die Wechselspannung f&uuml;r die Weiche zur Verf&uuml;gung.   

[Zum Seitenanfang](#up)   

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Schalten der Weiche mit dem Schaltblock W2

## 2.1 Der Schaltblock W2
Zum Ansteuern von Zweiweg-Weichen wird der [Schaltblock W2](/fab/rcc4_block/LIESMICH.md#x20) verwendet. Dieser besteht aus der Steuerungsplatine [`RW_5V_W2_STRG`](/fab/rcc4_block/LIESMICH.md#x20) und der Bedienplatine [`RW_5V_W2_LED`](/fab/rcc4_block/LIESMICH.md#x22). Der Zusammenbau und der Test des W2-Blocks ist unter [https://github.com/khartinger/RCC5V/blob/main/fab/rcc4_block/LIESMICH.md#x23](https://github.com/khartinger/RCC5V/blob/main/fab/rcc4_block/LIESMICH.md#x23) beschrieben.   
Als Stromversorgung werden 5V und die Wechselspannung zum Schalten der Weiche ben&ouml;tigt. Diese werden von der `RW_5V_SUB25_10`-Platine &uuml;ber ein 6-poliges Kabel zur Verf&uuml;gung gestellt und auf der R&uuml;ckseite des W2-Blocks am J3-Stecker angesteckt. Die Weiche wird am J5-Ausgang angeschlossen.   
![J3-J5 Pinlayout](./images/300_W2_J3-J5_Pinlayout1.png "J3-J5 Pinlayout")   
_Bild 6: Pinbelegung der Stecker des W2-Blocks_   

Der Anschluss des Weichenantriebs am W2-Block __ist nicht eindeutig!__. Er ist anh&auml;ngig davon, ob der Antrieb &Uuml;ber- oder Unterflur verwendet wird. Aus diesem Grund haben die beiden Spulenanschl&uuml;sse des Antriebs auch die gleiche, braune Farbe. Die Masseleitung ist schwarz (J5 - Pin 3).   

<a name="x22"></a>   

## 2.2 Anschluss des W2-Blocks
### Ben&ouml;tigte Betriebsmittel
Das folgende Bild zeigt den gesamten Schaltplan mit dem Anschluss des W2-Blocks:   
![W2_Block1](./images/480_W2_block1.png "W2_Block1")   
_Bild 7: Schaltplan zum Anschlie&szlig;en eines W2-Blocks_   

Wie im _Bild 7_ zu sehen ist, werden folgende Betriebsmittel ben&ouml;tigt:   
  1. Modellbahn-Trafo mit Wechselspannungsausgang, zB Conrad BV00/026 oder Roco 0903 usw.   
  2. Zwei Leitungen Stift-Stift (L&auml;nge egal zB 15 cm) zum Anschluss des Trafos am Zuleitungskabel   
  3. 10-poliges Zuleitungskabel mit 8- (oder 10-) poliger Schraubklemme und 25-poliger Sub-D-Buchse   
  4. Eigenbau-Stromversorgungsplatine [`RW_5V_SUB25_10`](/fab/rcc5_add_ons/LIESMICH.md#x40)    
  5. [Schaltblock W2](/fab/rcc4_block/LIESMICH.md#x20)   
  6. Eigenbau-Hilfsplatine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40)    
  7. Zweiwegweiche mit elektrischem Antrieb mit Endabschaltung, zB Fleischmann-Weiche 9170 und Antrieb 640000   
  8. Flachbandkabel 6-polig, ca. 30 cm   
  9. Flachbandkabel 6-polig, ca. 11 cm   

### Anschluss der Stromversorgung am W2-Block
* Zur Stromversorgung wird der J3-Stecker des W2-Weichenblocks mit einem 30 cm langen, 6-poligen Flachbandkabel mit dem POWER-Stecker der `RW_5V_SUB25_10`-Platine verbunden. &Uuml;ber dieses Kabel wird sowohl die 5V- als auch die Wechselspannung zum Schalten der Weiche &uuml;bertragen.   

### Anschluss des Weichenantriebs
* Der J5-Ausgang des W2-Blocks wird &uuml;ber ein 6-poliges Flachbandkabel mit der Hilfsplatine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40) verbunden.   
Die Dr&auml;hte des Weichanantriebs werden an der Schraubklemme `CON_6pol_3` befestigt:   
* schwarze Masseleitung in der Mitte   
* die beiden braunen Leitungen daneben (Reihenfolge egal)   

Das folgende Bild zeigt den praktischen Aufbau der Weichenansteuerung mit W2-Block:   
![W2_Block2](./images/480_W2_block2.png "W2_Block")   
_Bild 8: Praktischer Anschluss eines W2-Blocks_   

Das folgende Bild zeigt die Anschl&uuml;sse des W2-Blocks von der R&uuml;ckseite. Das Versorgungskabel (unten) kann zu weiteren Bl&ouml;cken gef&uuml;hrt werden.   
![R&uuml;ckseite W2_Block2](./images/300_W2_block2_back.png "R&uuml;ckseite W2_Block")   
_Bild 9: R&uuml;ckseite des W2-Blocks_   

<a name="x23"></a>   

## 2.3 Test
### Anzeige der Weichenstellung
Nach dem Einschalten der Versorgungsspannung leuchtet entweder die mittlere, gr&uuml;ne LED (f&uuml;r "Gerade") oder die obere, gelbe LED (f&uuml;r "Abzweig"). Stimmt die Anzeige NICHT mit der tats&auml;chlichen Weichenstellung &uuml;berein, so m&uuml;ssen die braunen Leitungen an der Schraubklemme `CON_6pol_3` vertauscht werden (Pin 1 mit Pin 5).   
### Stellen der Weiche mit den W2-Block-Tasten
Ist der Trafo eingeschaltet, so kann durch Dr&uuml;cken der Tasten am W2-Block die Weiche gestellt werden. Die LEDs auf dem W2-Block zeigen die aktuelle Weichenstellung an.   
### Stellen der Weiche von Hand
Auch das Stellen der Weiche von Hand ist m&ouml;glich. In diesem Fall &auml;ndert sich ebenfalls die Anzeige auf dem W2-Block.   

[Zum Seitenanfang](#up)   

<a name="x30"></a>   
<a name="x31"></a>   

# 3. Weichensteuerung durch den Mikrocontroller
## 3.1 Vorbereitung des Mikrocontrollers
Als __Hardware__ f&uuml;r die Mikrocontroller-Steuerung wird ein ESP32 mit DCC- und I²C-Shield sowie einem 1,54-Zoll-Display verwendet. Der Zusammenbau ist unter [https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/LIESMICH.md](https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/LIESMICH.md) beschrieben.   

Als __Software__ kann die [Demo-Software](/software/rcc_demo1/LIESMICH.md) verwendet werden. Auch wenn nur die Zweiwegweiche mit der DCC-Adresse 21 angeschlossen wird, so funktioniert die Steuerung trotzdem.   

### Arbeitsschritte
1. Programmieren des ESP32   
2. Zusammenbauen der Steuerungs-Hardware (ESP32, DCC-Shield, I²C-Shield und 1,54-Zoll-Display zusammenstecken)   
3. Verbinden des DCC-Anschlusses des [DCC-Shields](/fab/rcc2_esp32/LIESMICH.md#x30) &uuml;ber ein 6-poliges Kabel mit dem DCC-Steckers der Versorgungsplatine [`RW_5V_SUB25_10`](/fab/rcc1_supply/LIESMICH.md#x33)   
4. Einschalten des Trafos: Der ESP32 f&auml;hrt hoch. Die Zwischenbildschirme k&ouml;nnen durch kurzes Bed&uuml;hren der beiden Dr&auml;hte (IO19 gegen Masse) &uuml;bersprungen werden.   

_Ergebnis:_   
Bei der &Uuml;berpr&uuml;fung des I²C-Busses stoppt der Mikrocontroller mit der Fehlermeldung "Search PCF8574 0x20 - 20 NOT found - Check wiring!", da noch keine I²C-PCF8574-I/O-Platinen angeschlossen sind, die die Verbindung zur Weichensteuerung darstellen.   

Das folgende Bild zeigt die uC-Steuerung und die Weichensteuerung noch ohne Verbindung &uuml;ber die I²C-PCF8574-I/O-Platinen.   

![ESP32 mit W2-Block](./images/480_W2_ESP32_1.png "ESP32 mit W2-Block")    
_Bild 10: Anschluss des ESP32 an die Versorgungsplatine_   

[Zum Seitenanfang](#up)   

<a name="x40"></a>   

# 4. Verbindung der Mikrocontroller-Steuerung mit dem W2-Block
Die Verbindung zwischen der Mikrocontroller-Steuerung und dem W2-Block erfolgt &uuml;ber [I²C-PCF8574-I/O-Platinen](/fab/rcc3_i2c/LIESMICH.md). Diese sind mit dem Mikrocontroller &uuml;ber den I²C-Bus und mit dem W2-Block &uuml;ber 2x2 Datenleitungen verbunden. Zwei der Leitungen dienen zum Stellen der Weiche und zwei zur R&uuml;ckmeldung des Schaltzustands. Die Datenleitungen k&ouml;nnten direkt am J4-Stecker des W2-Blocks angesteckt werden, jedoch ist es &uuml;bersichtlicher, wenn man als "Zwischenstecker" die Platine [`CON_10pol_PIN`](/fab/rcc5_add_ons/LIESMICH.md#x90) verwendet.   
__Wichtig__: Der Anschluss Datenleitungen muss so erfolgen, wie es im ESP32-Programm definiert ist. Bei Verwendnug der `rcc_demo1`-Software ist die Zweiwegweiche an die Pins P1 und P2 der PCF8574-Expander anzuschlie&szlig;en:   
* I²C-Adresse 0x40-Pin P1 - CON_10pol_PIN-IN1: Steuerleitung WSA zur Weiche (rot)   
* I²C-Adresse 0x40-Pin P2 - CON_10pol_PIN-IN2: Steuerleitung WSB zur Weiche (orange)   
* I²C-Adresse 0x41-Pin P1 - CON_10pol_PIN-OUT1: R&uuml;ckmeldeleitung WRA von der Weiche (rot)   
* I²C-Adresse 0x41-Pin P2 - CON_10pol_PIN-OUT2: R&uuml;ckmeldeleitung WRB von der Weiche (orange)   

Die Farbe der Verbindungsleitungen ist an sich egal, aber die Verwendung der gleichen Farbcodierung wie bei Flachbandkabel ist sinnvoll:   
* PCF8574-Pin P0 = Leitung 1: braun   
* PCF8574-Pin P1 = Leitung 2: rot   
* PCF8574-Pin P2 = Leitung 3: orange   
* PCF8574-Pin P3 = Leitung 4: gelb   
* PCF8574-Pin P4 = Leitung 5: gr&uuml;n   
* PCF8574-Pin P5 = Leitung 6: blau   
* PCF8574-Pin P6 = Leitung 7: violett   
* PCF8574-Pin P7 = Leitung 8: grau   

Das folgende Bild zeigt die Gesamtschaltung zur Ansteuerung einer Modellbahnweiche:   

![Gesamtschaltung Weichensteuerung](./images/600_W2_circuit1.png "Gesamtschaltung Weichensteuerung")   
_Bild 11: Gesamtschaltung der Weichensteuerung_

PCF8574-I/O-Platinen haben keine Befestigungsbohrungen, daher muss man sie entweder mit Doppelklebeband festkleben oder die Hilfsplatinen [`CON_I2C_20mm`](/fab/rcc3_i2c/LIESMICH.md#x20) und/oder [`CON_I2C_Term`](/fab/rcc3_i2c/LIESMICH.md#x60) verwenden. Diese Platinen verl&auml;ngern einfach den I²C-Bus, haben eine 2,2 mm-Bohrung und einen 100 nF-Kondensator zur Stabilisierung der 5V-Spannung. Die Platine `CON_I2C_Term` enth&auml;lt weiters zwei I²C-Abschlusswiderst&auml;nde.    

Das folgende Bild zeigt den Aufbau der gesamten Weichensteuerung.   

![Aufbau Weichensteuerung](./images/480_W2_structure2.png "Aufbau Weichensteuerung")   
_Bild 12: Gesamtaufbau der Weichensteuerung_

## Test des I²C-Anschlusses
### Schalten der Weiche von Hand
* Trafo einschalten und warten bis der ESP32 hochgefahren ist. Die Zwischenbildschirme k&ouml;nnen durch kurzes Bed&uuml;hren der beiden Dr&auml;hte (IO19 gegen Masse) &uuml;bersprungen werden.   
* &Auml;ndert man die Weichenstellung mit dem Schieber auf dem Weichenantrieb, so &auml;ndert sich die Anzeige bei T2 (DCC 21) von `__` (Gerade) auf `_/` (Abzweig) und umgekehrt.   

### Schalten der Weiche mit den Tasten des W2-Blocks
* Trafo einschalten und warten bis der ESP32 hochgefahren ist. Die Zwischenbildschirme k&ouml;nnen durch kurzes Bed&uuml;hren der beiden Dr&auml;hte (IO19 gegen Masse) &uuml;bersprungen werden.   
* Dr&uuml;ckt man den mittleren (gr&uuml;nen) Taster, so wird die Weiche auf Gerade gestellt.   
* Dr&uuml;ckt man den oberen (gelben) Taster, so wird die Weiche auf Abzweig gestellt.   
* Die Stellung der Weiche ist wieder in der Anzeige bei T2 (DCC 21) ersichtlich   
(`__` = Gerade, `_/` = Abzweig).   

<a name="x50"></a>   

# 5. Schalten der Weiche mit DCC-Befehlen

## 5.3 Schalten der Weiche mit DCC-Befehlen
Zum Schalten mit DCC-Befehlen wird eine DCC-Zentrale ben&ouml;tigt. Eine einfache M&ouml;glichkeit ist die Verwendung der MultiMaus von Roco. Die DCC-Zentrale besteht dabei aus folgenden Teilen:   
* Roco Netzteil 10850   
* Roco Master/Booster 10764   
* Roco MultiMaus   

Das folgende Bild zeigt die um die DCC-Ansteuerung erweiterte Gesamtschaltung.   
![Schaltung DCC-Roco](./images/600_W2_roco1.png "Schaltung DCC Roco")   
_Bild 13: Gesamtschaltung mit Roco-Steuerung_

Zum Schalten der Weiche mit DCC-Befehlen stellt man mit der Lok/Weiche-Taste ![Taste_Lok_Weiche](./images/50_taste_lok_weiche.png) die Weichenadresse auf 21 ein und dr&uuml;ckt die Tasten f&uuml;r Gerade und Abzweig ![Pfeiltasten](./images/50_taste_pfeil.png).   

<a name="x60"></a>   

## 6. Schalten der Weiche mit MQTT-Befehlen
Zum Schalten der Weiche mit MQTT-Befehlen muss auf einem Rechner oder Raspperry Pi der Mosquitto-Broker laufen und &uuml;ber WLAN erreichbar sein.    
| Annahmen:      |                                                    |   
|----------------|----------------------------------------------------|   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   
| MQTT: IP-Adresse des Brokers (Host) | `10.1.1.1` |   

Befindet man sich im Netzwerk mit dem Broker und ist `mosquitto_pub` auf dem Rechner oder Raspberry installiert, so kann man &uuml;ber ein Kommando-Fenster die Weiche schalten, zB.   
Schalten der Weiche auf "Gerade":   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 1`   
Schalten auf "Abzweig":   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 0`   

[Zum Seitenanfang](#up)   