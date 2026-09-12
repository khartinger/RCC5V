<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Herstellung von RCC Schaltbl&ouml;cken</h1><b><big>RCC4: Basis-Blöcke für das RCC-System</big></b><br>  
Stand: 7.9.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>   

# 1. Einleitung
## 1.1 &Uuml;bersicht
Auf dieser Seite wird - nach einigen allgemeinen Hinweisen zu Bl&ouml;cken - das Herstellen folgender Bl&ouml;cke beschrieben:   
* [Block Zweiwegweiche (W2)](#x20)   
* [Block Dreiwegweiche (W3)](#x30)   
* [Block Entkuppler (1OUT)](#x40)   
* [Block Abschaltbares Gleis (2IO)](#x50)   
* [Block Zweifachumschalter (DPDT)](#x60)   
* [Block Abschaltbares Gleis mit Strommessung (TUI)](#x70)   

<a name="x12"></a>   

## 1.2 Aufbau von Bl&ouml;cken
Schaltbl&ouml;cke bestehen immer aus zwei Platinen: einer Steuerungs-(STRG-) und einer Anzeige-(LED-)Platine. Diese Platinen werden zusammengesteckt. Die Steuerungsplatine hat dazu zwei 8-polige Stiftleisten (nach unten gerichtet), die Anzeigeplatine 8-polige Buchsenleisten mit langen Kontakten (nach oben).   
![Zusammenstecken der Blockh&auml;lften](/images/300_assemble_block_parts.png "Zusammenstecken der Blockh&auml;lften")   
_Bild 1: Zusammenstecken der Blockteile "Steuerung" (links) und "Anzeige" (rechts)_   

<a name="x13"></a>   

## 1.3 Pinbelegung der Bl&ouml;cke
Die Stecker f&uuml;r die Ein- und Ausg&auml;nge sind bei allen Schaltbl&ouml;cken gleich:   
* J3: 6-poliger Flachbandstecker f&uuml;r die __Stromversorgung__ (senkrecht)   
* J4: 10-poliger Flachbandstecker mit den __Datenleitungen__ zur Fernsteuerung &uuml;ber DCC und MQTT.   
  Dies sind die Steuer- bzw. R&uuml;ckmeldesignale zu den I²C-IO-Expandern.   
* J5: 6-poliger Flachbandstecker mit den __Lastleitungen__ zu den Eisenbahn-Komponenten (Weichen etc.)   

![pinlayout_connectors](/images/300_pin_STRG.png "pinlayout_connectors")   
_Bild 2: Pinbelegung der STRG-Stecker_   

Die genaue Pin-Belegung der Stecker J4 (Fernsteuerung) und J5 (Eisenbahn-Komponenten) ist abh&auml;ngig von der Art des Schaltblocks:   

![Pinlayout_J4_all](/images/200_J4_pinlayout_all2.png "Pinlayout_J4_all")   
_Bild 3: Pinbelegung der STRG-Stecker J4 (Fernsteuerung)_   

![Pinlayout_J5_all](/images/200_J5_pinlayout_all2.png "Pinlayout_J5_all")   
_Bild 4: Pinbelegung der STRG-Stecker J5 (Anschluss der Eisenbahn-Komponenten)_   

<a name="x14"></a>   

## 1.4 Vorbereitung von LEDs
Die Anzeige des Zustandes jedes Blockes erfolgt durch LEDs. Damit Fertigungstoleranzen leicht ausgeglichen werden k&ouml;nnen, werden die LEDs nicht direkt auf die erforderliche L&auml;nge geschnitten, sondern eine Art "Feder" eingebaut. Dazu wird folgende Vorgangsweise empfohlen:   
1. Den Anoden- (Plus-) Anschlussdraht (l&auml;ngerer Draht) mit rotem Permanentstift markieren.   
2. Jeden Anschluss mit 19 bis 20 mm Schrumpfschlauch (Durchmesser 1 mm) isolieren.   
3. Die Anschlussdr&auml;hte der LEDs auf 26 mm L&auml;nge abschneiden.   
4. Nach folgender Zeichung biegen:   
![LED biegen](/images/200_LED_config.png "LED biegen")   
_Bild 5: Anpassen der LEDs f&uuml;r die Montage_   

Zum Biegen kann man auch eine Schablone aus Karton vorbereiten, wobei man die LED am Rand des Kartons anlegt und den Anschlussdraht nach Schema biegt:   
![LED biegen2](/images/200_LED_config2.png "LED biegen2")   
_Bild 6: LED-Biegeschablone_   

Das Bild zeigt die verschiedenen Stadien beim Vorbereiten der LEDs:   
![LED_biegen_Schritte](/images/300_LED_biegen_Schritte.png "LED_biegen_Schritte")   
_Bild 7: Die Arbeitsschritte beim Biegen der LEDs_   

<a name="x15"></a>   

## 1.5 Anordnung von LEDs und Tastern auf der LED-Platine
Das Basis-Layout der LED-Platinen ist f&uuml;r alle Bl&ouml;cke gleich. Es sind drei Positionen f&uuml;r Taster bzw. Schalter sowie sechs Positionen f&uuml;r LEDs vorgesehen:   
![LED- und Schalterpositionen](/images/300_block_cover.png "LED- und Schalterpositionen")   
_Bild 8: LED- und Schalterpositionen bei einem Block (von vorne gesehen)_   

Die Bezeichnungen f&uuml;r die LEDs (D1 bis D6) und die Taster oder Schalter (SW1 bis SW3) werden bei allen LED-Platinen gleich verwendet.   

<a name="x16"></a>   

## 1.6 L&ouml;ten von Tastern und Schaltern auf die L&ouml;tseite einer Platine
Alle "LED"-Platinen enthalten Taster und Schalter, die im letzten Arbeitsschritt auf die L&ouml;tseite der Platine gel&ouml;tet werden. Damit sie beim Einl&ouml;ten nicht herausfallen, kann man sie mit Klebeband oder Klebstoff fixieren und die Platine h&ouml;her lagern. Zum Beispiel kann man sie auf die Kanten eines schmalen Einsatzes eines [RAACO Sortimentkoffers Assorter 55 A9](https://www.reichelt.de/at/de/sortimentseinsatz-a9-1-39-x-47-x-55-mm-raaco-a9-1-p29322.html?r=1) legen.

![solder_button1](/images/200_solder_button1.png "solder_button1") ![solder_button2](/images/200_solder_button2.png "solder_button2")   
_Bild 9: L&ouml;ten von Tastern_   

[Zum Seitenanfang](#up)   

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Zweiwegweiche

## 2.1 Steuerung Zweiwegweiche   
Diese Platine dient zum Schalten einer Zweiwegweiche (Richtung "Gerade" oder "Abzweig") von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt durch zwei Relais (siehe Bild unten).   

![RW_5V_W2_STRG_circuit](/images/600_RW_5V_W2_STRG_circuit.png "RW_5V_W2_STRG_circuit")   
_Bild 10: Schaltplan der "RW_5V_W2_STRG"-Platine_   

![Platine Ansteuerung Zweiwegweiche](/images/pcb_f/PCB_F_RW_5V_W2_STRG_V2.png "Platine Ansteuerung Zweiwegweiche")   
_Bild 11: Platine zur Ansteuerung einer Zweiwegweiche_   

![RW_5V_W2_STRG](/images/300_RW_5V_W2_STRG_V2.png "RW_5V_W2_STRG")   
_Bild 12: Best&uuml;ckte Platine "RW_5V_W2_STRG" zum Schalten einer Weiche_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | C1                | 100 nF              | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|    2   | D1,D3 | Diode 1N4148 | _kh_library:D_DO-35_SOD27_P5.08mm_Vertical_AnodeUp_kh |   
|    6   | D6,D7, D11,D12, D14,D15 | Diode 1N4148 oder BAT48 | _kh_library:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp_kh |   
|    2   | J1,J2             | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5             | Wannenstecker 6-polig, stehend  | _kh_library:Box_02x03_P2.54mm_Vertical |   
|    1   | J4                | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical |   
|    2   | K1,K3             | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    2   | Q1,Q2             | Transistor BC327  | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R8,R9             | 4,7 k&Omega;      | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    2   | R2,R4             | 10 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R1,R3             | 100 k&Omega;      | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

![RW_5V_W2_STRG_parts](/images/300_RW_5V_W2_STRG_parts.png "RW_5V_W2_STRG_parts")   
_Bild 13: Bauteile der "RW_5V_W2_STRG"-Platine_   

### Best&uuml;ckung   
1. Diode D1 und D3 (liegend, 5,08 mm)   
2. Relais K1, K3   
3. Dioden D6, D7
4. Dioden D11, D12, D14, D15   
5. Transistoren Q1, Q2   
6. Widerst&auml;nde R8, R9   
7. Widerst&auml;nde R2, R4   
8. Widerst&auml;nde R1, R3   
9. Kondensator C1   
10. Wannenstecker J1 bis J3   
11. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

### Versionen
* V1 (241103): OK   
* V2 (241115): OK   

<a name="x22"></a>   

## 2.2 Zweiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Schalten einer Zweiwegweiche (mit je einem Taster f&uuml;r die Richtungswahl "Gerade" oder "Abzweig") und zur Anzeige der tats&auml;chlichen Weichenstellung. Es sind alle Taster- und LED-Positionen verdrahtet, sodass man durch die richtige Wahl von zwei Tastern und zwei LEDs alle Schaltbilder, n&auml;mlich   
* linke Weiche nach links oben,   
* linke Weiche nach rechts unten,   
* rechte Weiche nach links unten und   
* rechte Weiche nach rechs oben   

darstellen kann.   

![RW_5V_W2_LED_circuit](/images/600_RW_5V_W2_LED_circuit.png "RW_5V_W2_LED_circuit")   
_Bild 14: Schaltplan der "RW_5V_W2_LED"-Platine_   

![RW_5V_W2_LED](/images/pcb_f/PCB_F_RW_5V_W2_LED_V1.png "RW_5V_W2_LED")   
_Bild 15: Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W2_LED_F](/images/300_RW_W2_LED_F.png "RW_5V_W2_LED_F")   
_Bild 16: Bauteilseite der best&uuml;ckten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

Im folgenden Bild ist der Print f&uuml;r eine linke Weiche best&uuml;ckt, die bei der Fahrt von links nach rechts entweder "Gerade" (gr&uuml;ne LED leuchtet) oder "Abzweig" befahren werden kann (gelbe LED leuchtet).   
![RW_5V_W2_LED_B](/images/300_RW_W2_LED_B.png "RW_5V_W2_LED_B")   
_Bild 17: L&ouml;tseite der best&uuml;ckten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung._   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D2 oder D5        | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D1 oder D3 oder D4 oder D6 (1) | LED gelb 2 mA  | LED_THT:LED_D3.0mm |   
|    6   | D1,D2,D3,D4,D5,D6 (1) | Buchsenleiste 2-polig mit gedrehten Kontakten (Pins) | "Fassung" f&uuml;r LEDs |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh     |   
|    4   | Q1,Q2,Q3,Q4       | Transistor BC337-40 | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R6, <br> R12           | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | R1,<br> R7    | 47 &Omega; (100 &Omega;) | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
|    2   | R3,R9             | 1 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R5,R11            | 4,7 k&Omega;     | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R2,R8             | 47 k&Omega;      | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R4 <br> R10       | 100 k&Omega;     | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
|    1   | SW2               | Taster SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    1   | SW1 oder SW3 (2)  | Taster SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    2   | SW2, SW1 oder SW3 | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe gr&uuml;n, gelb |    

### Anmerkungen
(1) Es ist sinnvoll, die 2-poligen Buchsenleisten an alle 6 LED-Positionen zu l&ouml;ten, auch wenn im Betrieb  nur zwei LEDs eingesetzt werden. Weiters ist das Einl&ouml;ten aller Bauteile so einfacher ;)   

(2) Nur den Taster einl&ouml;ten, der ben&ouml;tigt wird:   
    * F&uuml;r oben (= rechte Weiche nach links oder linke Weiche nach rechts): Taster SW1 mit LED D1 oder D4   
    * F&uuml;r unten (= rechte Weiche nach rechts oder linke Weiche nach links): Taster SW3 mit LED D3 oder D6   

## Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 6x 2-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1/SW3 (gelb), SW2 (gr&uuml;n) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

![RW_5V_W2_LED_parts](/images/300_RW_5V_W2_LED_parts.png "RW_5V_W2_STRG_parts")   
_Bild 18: Bauteile der "RW_5V_W2_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten (D1 bis D6) mit gedrehten Pins auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Transistoren Q1 bis Q4   
3. Alle Widerst&auml;nde   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

5. Taster SW1 und SW2 ODER SW2 und SW3 (siehe Text in der Einleitung oben)   
   
<a name="x23"></a>   

## 2.3 Zusammenbau des W2-Blocks
1. Aufstecken des Steuerungsprints `RW_5V_W2_STRG` auf die Anzeigeplatine `RW_5V_W2_LED`.   
2. Aufstecken der Schalter-Kn&ouml;pfe (Mitte gr&uuml;n, au&szlig;en gelb).   
3. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
4. Falls vorhanden: Print `RW_LEER_LED` auf den Anzeigeprint stecken.   

### 2.4 Test des W2-Blocks   
Das Ersatzschaltbild einer endabgeschalteten Weiche sind zwei Spulen mit einem Umschalter. Die Spule, die gerade geschaltet wurde (WB), ist von der R&uuml;ckleitung getrennt und die andere Spule (WA) ist nun bereit, geschaltet zu werden.   

![RW_5V_W2_equivalent_circuit](/images/200_W2_equivalent_circuit.png "RW_5V_W2_equivalent_circuit")   
_Bild 19: Ersatzschaltbild Weichenantrieb_   

Das "Warten" auf den Schaltvorgang wird f&uuml;r die R&uuml;ckmeldung der Weichenstellung genutzt: In diesem Fall ist der Widerstand zwischen WA und W0 klein (nur der ohmsche Widerstand der Spule), der Widerstand zwischen WB und W0 unendlich.   
Man unterscheidet daher zwei Zust&auml;nde:   
1. den Schaltvorgang und    
2. den Ruhezustand mit der Weichenr&uuml;ckmeldung.   

### "Labor-Test" mit 5V und ohne Weichenantrieb
Das Testen der W2-Schaltblocks ohne Verwendung einer Weiche bzw. eines Weichenantriebs muss in zwei Phasen durchgef&uuml;hrt werden: Test des Schaltens (= Anlegen einer Spannung) und Test der R&uuml;ckmeldung (LED-Anzeige, R&uuml;ckmeldeleitungen).   
F&uuml;r diesen Test ben&ouml;tigt man ein 5V-Netzteil, 12 St&uuml;ck einzelne Kabel Stecker auf Buchse sowie ein Voltmeter. Die Buchsen der Leitungen k&ouml;nnen direkt auf die Stifte der 6- bzw. 10-poligen Wannenstecker gesteckt werden.   
Die Verkabelung der Versorgungsspannung gilt f&uuml;r beide Tests:   
* rot: 5 V vom Netzteil nach J3-1 (5V)   
* rot: 5 V vom Netzteil nach J3-6 (V+)   
* braun: 0 V vom Netzteil nach J3-3 (0V)   
* braun: 0 V vom Netzteil nach J3-4 (V-)   

#### Test des Schaltvorgangs eines W2-Blocks
Die Verkabelung entsprechend dem Bild durchf&uuml;hren:   
* gr&uuml;n: WA von J5-1 zum Voltmeter +   
* blau: V- von J5-3 zum Voltmeter COM (-)   
* violett: WB von J5-5 zum Voltmeter + (alternativ)   

* grau: WSB von J4-2 nach au&szlig;en   
* wei&szlig;: WSG von J4-1 nach au&szlig;en   
* schwarz: 0V (GND) von J4-5 nach au&szlig;en   


![W2 Testverkabelung](/images/300_W2_test_wiring_img.png "W2 Testverkabelung")   
_Bild 20: Verkabelung zum Testen eines W2-Blocks_   

![W2 Testverkabelung Schalten](/images/300_W2_test_wiring_switch.png "W2 Testverkabelung Schalten")   
_Bild 21: Verkabelung zum Testen des Schaltvorgangs eines W2-Blocks_   

1. Anlegen der 5V-Spannung:   
   * Beide LED leuchten.   
   * Die Spannungen an J5-1 (WA) und J5-5 (WB) sind 0 V (0,65 V).   
2. Dr&uuml;cken des mittleren, gr&uuml;nen Tasters:   
   * Beide LED leuchten.   
   * Die Spannung an J5-1 (WA) ist 5 V   
   * Die Spannung an J5-5 (WB) ist 0 V   
3. Pin J4-2 (WSB) auf 0V (J4-5): Gleiches Verhalten wie bei Punkt 2.   
4. Dr&uuml;cken des &auml;u&szlig;eren, gelben Tasters:   
   * Beide LED leuchten.   
   * Die Spannung an J5-1 (WA) ist 0 V   
   * Die Spannung an J5-5 (WB) ist ca. 4 V   
5. Pin J4-1 (WSB) auf 0V (J4-5): Gleiches Verhalten wie bei Punkt 4.   

#### Test der R&uuml;ckmeldung eines W2-Blocks
Die Verkabelung entsprechend dem Bild durchf&uuml;hren:   
* gr&uuml;n: WA von J5-1 nach au&szlig;en   
* blau: V- von J5-3 nach au&szlig;en   
* violett: WB von J5-5 nach au&szlig;en   

* gelb: WRG von J4-7 zum Voltmeter +   
* orange: WRB von J4-8 zum Voltmeter + (alternativ)   
* schwarz: 0V (GND) von J4-5 zum Voltmeter COM (-)   

![W2 Testverkabelung R&uuml;ckmeldung](/images/300_W2_test_wiring_LED.png "W2 Testverkabelung R&uuml;ckmeldung")   
_Bild 22: Verkabelung zum Testen der R&uuml;ckmeldung eines W2-Blocks_   

1. Anlegen der 5V-Spannung:   
   * Beide LED leuchten.   
   * Die Spannungen an J4-7 (WRG) und J4-8 (WRB) sind 5 V.   
2. J5-3 (V-) mit J5-1 (WA) verbinden:   
   * Nur die gelbe LED leuchtet. (Die mittlere, gr&uuml;ne LED erlischt).   
   * Die R&uuml;ckmeldeleitung J4-7 (WRG) liegt auf 0 V  (0,7 V).   
   * Die R&uuml;ckmeldeleitung J4-8 (WRB) liegt auf 5 V.   
3. J5-3 (V-) mit J5-5 (WB) verbinden:   
   * Nur die mittlere, gr&uuml;ne LED leuchtet. (Die gelbe LED erlischt).   
   * Die R&uuml;ckmeldeleitung J4-7 (WRG) liegt auf 5 V.   
   * Die R&uuml;ckmeldeleitung J4-8 (WRB) liegt auf 0 V (0,7 V).   

### Test unter realen Bedingungen
1. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_1OUT_STRG_:   
   * Beide LED leuchten.   
2. Anschluss der Zweiwegweiche an Pin 1, Pin 3 und Pin 5 von J5 der Steuerungplatine _RW_5V_W2_STRG_ .   
   * Eine der beiden LEDs leuchtet je nach Stellung der Weiche.   
3. Bet&auml;tigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", LED 2 oder LED 5 leuchtet.   
4. Bet&auml;tigen des Tasters SW1 oder SW3: Stellen der Weiche auf "Abzweig", die andere LED leuchtet.   
5. Anschluss der Steuer- und R&uuml;ckmeldeleitungen an J4:   
   * Weichensteuerung &uuml;ber DCC und MQTT ist m&ouml;glich.   

![Pinbelegung_W2-J5](/images/200_J5_pins_W2.png "Pinbelegung W2-J5")   
_Bild 23: Pinbelegung des Steckers J5 von RW_5V_W2_STRG_   

### Versionen
* V1 (241104): OK

[Zum Seitenanfang](#up)   
<a name="x30"></a>   
<a name="x31"></a>   

# 3. Dreiwegweiche

## 3.1 Steuerung Dreiwegweiche   
Diese Platine dient zum Schalten einer Dreiwegweiche (Richtung links - Mitte - rechts) von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber Relais.   

![RW_5V_W3_STRG_circuit](/images/600_RW_5V_W3_STRG_circuit.png "RW_5V_W3_STRG_circuit")   
_Bild 24: Schaltplan der "RW_5V_W3_STRG"-Platine_   

![Platine Ansteuerung Dreiwegweiche](/images/pcb_f/PCB_F_RW_5V_W3_STRG_V3.png "Platine Ansteuerung Dreiwegweiche")   
_Bild 25: Platine zur Ansteuerung einer Dreiwegweiche_   

![RW_5V_W3_STRG](/images/300_RW_5V_W3_STRG_V3.png "RW_5V_W3_STRG")   
_Bild 26: Best&uuml;ckte Platine "RW_5V_W3_STRG" zum Schalten der Weichen_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | C1                | 100 nF              | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|   14   | D1,D2,D3,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15 | Diode 1N4148 | _kh_library:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp_kh |   
|    2   | J1,J2             | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5             | Wannenstecker 6-polig, stehend  | _kh_library:Box_02x03_P2.54mm_Vertical |   
|    1   | J4                | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical |   
|    4   | K1,K2,K3,K4       | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    3   | Q1,Q2,Q3          | Transistor BC327  | _kh_library:TO-92_Inline_Wide_custom |   
|    3   | R7,R8,R9          | 4,7 k&Omega;      | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    3   | R2,R4,R6          | 10 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R1,R3,R5          | 100 k&Omega;      | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

"RW_5V_W3_STRG"-Platine mit bereits vorgebogenen Bauteilen:   
![RW_5V_W3_STRG_parts](/images/300_RW_5V_W3_STRG_parts.png "RW_5V_W3_STRG_parts")   
_Bild 27: Bauteile der "RW_5V_W3_STRG"-Platine_   

### Best&uuml;ckung   
1. Relais K1 bis K4   
2. Dioden D1 bis D15   
3. Transistoren Q1, Q2, Q3   
4. Widerst&auml;nde R7, R8, R9   
5. Widerst&auml;nde R2, R4, R6   
6. Widerst&auml;nde R1, R3, R5   
7. Kondensator C1   
8. Wannenstecker J1 bis J3   
9. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

### Versionen
* V1 (240930): Keine Aufnahmebohrungen, Leiterbahn (Netz) WL+ mit V+ verbunden, Widerst&auml;nde R2, R4 und R6 haben 15k&Omega; (neu 10 k&Omega;).   
* V2 (241011): Bezeichnung GND (wird durch 0V ersetzt), Haltebohrungen alt, Lage der Wannenstecker J1 bis J3 falsch, kein 100 nF-Kondensator f&uuml;r die Versorgungsspannung, keine Schutzschaltung (R7, R8, R9, D13, D14, D15), falls beim Microcontroller die Versorgungsspannung ausf&auml;llt.   
* V3 (241021): OK   
* V4 (241024): OK   

<a name="x32"></a>   

## 3.2 Dreiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Bedienen einer Dreiwegweiche (Richtung links - Mitte - rechts) und zur Anzeige der tats&auml;chlichen Weichenstellung.   

![RW_5V_W3_LED_circuit](/images/600_RW_5V_W3_LED_V4_circuit.png "RW_5V_W3_LED_circuit")   
_Bild 28: Schaltplan der "RW_5V_W3_LED"-Platine_   

![RW_5V_W3_LED](/images/pcb_f/PCB_F_RW_5V_W3_LED_V3.png "RW_5V_W3_LED")   
_Bild 29: Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W3_LED_V3](/images/300_RW_5V_W3_LED.png "RW_5V_W3_LED")   
_Bild 30: Best&uuml;ckte Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D2 (1)            | LED gr&uuml;n 2 mA  | LED_THT:LED_D3.0mm |   
|    2   | D1,D3 (1)         | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    6   | D1,D2,D3 (D4,D5,D6) | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh     |   
|    2   | J3,J4             | Stiftleiste 2polig  | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   
|    2   | (J3, J4)          | Jumper              |   |   
|    6   | Q1,Q2,Q3,Q4,Q5,Q6 | Transistor BC337-40 | _kh_library:TO-92_Inline_Wide_custom |   
|    3   | R6,R18 <br> R12   | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0207_L6.3mm_D2.5mm_P15.24mm_Horizontal_kh |   
|    3   | R1,R13 <br> R7    | 47 &Omega; (oder 100 &Omega;) | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    3   | R3,R9,R15         | 1 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R5,R11,R17        | 4,7 k&Omega;     | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R2,R8,R14         | 47 k&Omega;      | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R4,R16 <br> R10   | 100 k&Omega;     | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    3   | SW1,SW2,SW3       | Taster SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    3   | SW1,SW2,SW3 | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe 2x gr&uuml;n, 1x gelb |    

### Anmerkungen
(1) Es ist sinnvoll, die 2-poligen Buchsenleisten an alle 6 LED-Positionen zu l&ouml;ten, auch wenn im Betrieb  nur drei LEDs eingesetzt werden, je nachdem, ob die Anzeige links oder rechts von den Tastern sein soll.   
   
## Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 6x 2-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1, SW3 (gelb), SW2 (gr&uuml;n) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

![RW_5V_W3_LED_parts](/images/300_RW_5V_W3_LED_parts.png "RW_5V_W3_STRG_parts")   
_Bild 31: Bauteile der "RW_5V_W3_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten (D1 bis D3 und/oder D4 bis D6) mit gedrehten Pins auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Transistoren Q1 bis Q6   
3. Alle Widerst&auml;nde   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   
5. Stiftleisten 2x2 Pins J3, J4   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

6. Taster SW1 bis SW3   

7. Jumper setzen

<a name="x33"></a>   

## 3.3 Zusammenbau des W3-Blocks
1. Aufstecken des Steuerungsprints `RW_5V_W3_STRG` auf die Anzeigeplatine `RW_5V_W3_LED`.   
2. Aufstecken der Schalter-Kn&ouml;pfe (Mitte gr&uuml;n, au&szlig;en gelb).   
3. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
4. Falls vorhanden: Print `RW_LEER_LED` auf den Anzeigeprint stecken.   

### 3.4 Test des W3-Blocks   
Das Ersatzschaltbild einer endabgeschalteten Weiche sind zwei Spulen mit einem Umschalter. Siehe dazu Kapitel 2.4.   

### "Labor-Test" mit 5V und ohne Weichenantrieb
Das Testen der W3-Schaltblocks ohne Verwendung einer Weiche bzw. zweier Weichenantriebe muss in zwei Phasen durchgef&uuml;hrt werden: Test des Schaltens (= Anlegen einer Spannung) und Test der R&uuml;ckmeldung (LED-Anzeige, R&uuml;ckmeldeleitungen).   
F&uuml;r diesen Test ben&ouml;tigt man ein 5V-Netzteil, 4 St&uuml;ck einzelne Kabel Stecker auf Buchse, 5 St&uuml;ck einzelne Kabel Stecker - Stecker, ein 6-poliges Flachbandkabel, ein 10-poliges Flachbandkabel sowie ein Voltmeter.    
Die Buchsen der Leitungen k&ouml;nnen direkt auf die Stifte des 6-poligen Wannensteckers J3 gesteckt werden und dienen der Spannungsversorgung f&uuml;r beide Tests:   
* rot: 5 V vom Netzteil nach J3-1 (5V)   
* rot: 5 V vom Netzteil nach J3-6 (V+)   
* braun: 0 V vom Netzteil nach J3-3 (0V)   
* braun: 0 V vom Netzteil nach J3-4 (V-)   
Die Flachbandkabel werden an J4 (10-polig) und J5 (6-polig) abgesteckt.   

#### Test des Schaltvorgangs eines W3-Blocks
Die Verkabelung entsprechend dem Bild durchf&uuml;hren:   
* WL von J5-1 zum Voltmeter +   
* V- von J5-3 zum Voltmeter COM (-)   

![W3 Testverkabelung Schalten](/images/300_W3_test_wiring_switch.png "W3 Testverkabelung Schalten")   
_Bild 32: Verkabelung zum Testen des Schaltvorgangs eines W3-Blocks_   

1. Anlegen der 5V-Spannung:   
   * Alle drei LED leuchten.   
   * Die Spannungen an J5-1 (WL), J5-2 (WR), J5-5 (WML) und J5-6 (WMR) sind 0 V (0,65 V).   
2. Dr&uuml;cken des oberen, gelben Tasters ("Links"):   
   * Alle drei LED leuchten.   
   * Die Spannung an J5-1 (WL) und J5-6 (WMR) ist 5 V   
   * Die Spannung an J5-2 (WR) und J5-5 (WML) und ist 0 V   
   ("Kreuzweise" 5V am Stecker J5)   
3. Dr&uuml;cken des mittleren, gr&uuml;nen Tasters ("Mitte"):   
   * Alle drei LED leuchten.   
   * Die Spannung an J5-1 (WL) und J5-2 (WR) ist 0 V   
   * Die Spannung an J5-5 (WML) und J5-6 (WMR) ist 5 V   
4. Dr&uuml;cken des unteren, gelben Tasters ("Rechts"):   
   * Alle drei LED leuchten.   
   * Die Spannung an J5-1 (WL) und J5-6 (WMR) ist 0 V   
   * Die Spannung an J5-2 (WR) und J5-5 (WML) und ist 5 V   
   ("Kreuzweise" 5V am Stecker J5)   
5. Pin J4-1 (WSL) auf 0V (J4-5): Gleiches Verhalten wie beim Dr&uuml;cken des oberen, gelben Tasters ("Links"). Siehe Punkt 2.   
6. Pin J4-2 (WSM) auf 0V (J4-5): Gleiches Verhalten wie beim Dr&uuml;cken des mittleren, gr&uuml;nen Tasters ("Mitte"). Siehe Punkt 3.   
7. Pin J4-1 (WSR) auf 0V (J4-5): Gleiches Verhalten wie beim Dr&uuml;cken des unteren, gelben Tasters ("Rechts"). Siehe Punkt 4.   

#### Test der R&uuml;ckmeldung eines W2-Blocks
* WL von J5-1 zum Voltmeter +   
* V- von J5-3 zum Voltmeter COM (-)   
_Beachte_: Zur korrekten Funktion m&uuml;ssen immer zwei der drei Anschl&uuml;sse WR, WL und WM am Stecker J5 (= WML + WMR) auf 0 V liegen. Zum Verteilen der 0 V kann zB auch ein Steckbrett verwendet werden...   

![W3 Testverkabelung R&uuml;ckmeldung](/images/300_W3_test_wiring_LED.png "W3 Testverkabelung R&uuml;ckmeldung")   
_Bild 33: Verkabelung zum Testen der R&uuml;ckmeldung eines W3-Blocks_   

1. Anlegen der 5V-Spannung:   
   * Alle drei LED leuchten.   
   * Die Spannungen an J4-7 (WRL), J4-8 (WRM) und J4-9 (WRR) sind 5 V.   
2. J5-3 (V-) mit J5-2 (WR) und J5-5 (WML) verbinden:   
   * Nur die obere, gelbe LED leuchtet.   
   * Die R&uuml;ckmeldeleitung J4-7 (WRL) liegt auf 5 V.   
   * Die R&uuml;ckmeldeleitung J4-8 (WRM) liegt auf 0 V (0,7 V).   
   * Die R&uuml;ckmeldeleitung J4-9 (WRR) liegt auf 0 V (0,7 V).   
3. J5-3 (V-) mit J5-2 (WR) und J5-1 (WL) verbinden:   
   * Nur die mittlere, gr&uuml;ne LED leuchtet.   
   * Die R&uuml;ckmeldeleitung J4-7 (WRL) liegt auf 0 V (0,7 V).   
   * Die R&uuml;ckmeldeleitung J4-8 (WRM) liegt auf 5 V.   
   * Die R&uuml;ckmeldeleitung J4-9 (WRR) liegt auf 0 V (0,7 V).   
4. J5-3 (V-) mit J5-1 (WL) und J5-6 (WMR) verbinden:   
   * Nur die untere, gelbe LED leuchtet.   
   * Die R&uuml;ckmeldeleitung J4-7 (WRL) liegt auf 0 V (0,7 V).   
   * Die R&uuml;ckmeldeleitung J4-8 (WRM) liegt auf 0 V (0,7 V).   
   * Die R&uuml;ckmeldeleitung J4-9 (WRR) liegt auf 5 V.   

### Test unter realen Bedingungen
1. Anschluss des Weichenantriebs "Links" an J5-Pin 3 (V-), J5-Pin 1 (WL) und J5-Pin 5 (WML). Es muss sichergestellt sein, dass durch J5-5 die Weiche auf "Mitte" ("Gerade") gestellt wird!   
2. Anschluss des Weichenantriebs "Rechts" an J5-Pin 4 (V-), J5-Pin 2 (WR) und J5-Pin 6 (WMR). Es muss sichergestellt sein, dass durch J5-5 die Weiche auf "Mitte" ("Gerade") gestellt wird!   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_1OUT_STRG_:   
   * Eine der drei LED leuchtet, je nach Stellung der Weiche.   
4. Bet&auml;tigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", LED 2 oder LED 5 leuchtet.   
5. Bet&auml;tigen des Tasters SW1 (oben): Stellen der Weiche auf "Links", die obere LED leuchtet.   
6. Bet&auml;tigen des Tasters SW3 (unten): Stellen der Weiche auf "Rechts", die untere LED leuchtet.   
7. Anschluss der Steuer- und R&uuml;ckmeldeleitungen an J4:   
   * Weichensteuerung &uuml;ber DCC und MQTT ist m&ouml;glich.   

![Pinbelegung_W3-J5](/images/200_J5_pins_W3.png "Pinbelegung W3-J5")   
_Bild 34: Pinbelegung des Steckers J5 von RW_5V_W3_STRG_   

### Versionen
* V1 (240930): Keine Aufnahmebohrungen, VCCi2c auf J2-Pin 1 herausgef&uuml;hrt, Keine Jumper zum Tauschen der Funktion von SW1 mit SW3.   
* V2 (241011): Bezeichnung GND (wird durch 0V ersetzt), Haltebohrungen neu    
* V3 (241018): Best&uuml;ckungsdruck: Widerstandswerte bei R5, R6 vertauscht, Versionsnummer V2 statt V3   
* V4 (241124): OK   

[Zum Seitenanfang](#up)   

<a name="x40"></a>   
<a name="x41"></a>   

# 4. Entkuppler (1OUT)   

## 4.1 Steuerung des Entkupplers   
Diese Platine dient zum Schalten der Versorgungsspannung f&uuml;r den Entkuppler von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber einen Optokoppler.   

![RW_5V_1OUT_STRG_circuit](/images/600_RW_5V_1OUT_STRG_circuit.png "RW_5V_1OUT_STRG_circuit")   
_Bild 35: Schaltplan der "RW_5V_1OUT_STRG"-Platine_   

![RW_5V_1OUT_STRG](/images/pcb_f/PCB_F_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG_V1")   
_Bild 36: Platine "RW_5V_1OUT_STRG" zum Bet&auml;tigen eines Entkupplers_   

![RW_5V_1OUT_STRG](/images/300_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG")   
_Bild 37: Best&uuml;ckte Platine "RW_5V_1OUT_STRG" zum Bet&auml;tigen eines Entkupplers_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | C1                | Elko 33 &micro;F/35V       | Capacitor_THT:CP_Radial_D8.0mm_P2.50mm |   
|    1   | C2                | Kondensator 100 nF  | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|    1   | D1                | Diode 1N4007        | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
|    2   | D2,D3             | Diode 1N4148        | Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
|    2   | D4,D5             | Diode 1N4148        | _kh_library:D_DO-35_P2.0mm_Vertical_AnodeUp_kh   |   
|    2   | J1,J2             | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5             | Wannenstecker 6-polig, stehend | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
|    1   | J4                | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical_kh |   
|    1   | K1                | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    1   | Q1                | Transistor BC327-40    | _kh_library:TO-92_Inline_Wide_2.2225 |   
|    1   | U1                | Optokoppler SFH615A    | Package_DIP:DIP-4_W7.62mm |   
|    1   | U1                | Fassung 4-polig        |       |   
|    1   | R3                | 100 &Omega;  | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R4                | 1 k&Omega;   | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R5,R6             | 4,7 k&Omega; | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    1   | R2                | 10 k&Omega;  | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R1                | 100 k&Omega; | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

![RW_5V_1OUT_STRG_parts](/images/300_RW_5V_1OUT_STRG_parts.png "RW_5V_1OUT_STRG_parts")   
_Bild 38: Bauteile der "RW_5V_1OUT_STRG"-Platine (ein 4k7-Widerstand fehlt)_   

### Best&uuml;ckung   
1. IC-Fassung U1 4-polig (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2 bis D5 (1N4148)   
4. Transistor Q1 (BC327-40)  
5. Kondensator C1 (33 &micro;F)   
6. Kondensator C2 (100 nF)   
7. Diode D1 (1N4007)   
8. Alle Widerst&auml;nde   
9. Wannenstecker J1 bis J3   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
10. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

_Nicht vergessen_: Optokoppler U1 richtig herum in die Fassung stecken...   

### Versionen
* V1 (240930): OK

<a name="x42"></a>   

## 4.2 LED-Anzeige mit Taster zur Entkuppler-Bedienung
Diese Platine dient zur Bedienung der Schaltplatine "RW_5V_1OUT_STRG".   
Im Ruhezustand leuchtet die rote LED (D1).   
Dr&uuml;ckt man den Taster, so leuchten die gelbe (D5) und gr&uuml;ne LED (D3) und J6-Pin 1 (S0) geht auf 0V.   

![RW_5V_1OUT_LED_circuit](/images/600_RW_5V_1OUT_LED_circuit.png "RW_5V_W3_1OUT_circuit")   
_Bild 39: Schaltplan der "RW_5V_1OUT_LED"-Platine_   

![RW_5V_1OUT_LED](/images//pcb_f/PCB_F_RW_5V_1OUT_LED_V2.png "RW_5V_1OUT_LED")   
_Bild 40: Platine "RW_5V_1OUT_LED" zum Schalten und zur Anzeige des gedr&uuml;ckten Tasters_   

Das folgende Bild zeigt die best&uuml;ckte Platine "RW_5V_1OUT_LED". Auf der Unterseite sieht man Teile der gelben und roten LED sowie des gelben Knopfes des Tasters.   
![pcb RW_5V_1OUT_LED](/images/300_RW_5V_1OUT_LED.png "pcb RW_5V_1OUT_LED")   
_Bild 41: Die best&uuml;ckte "RW_5V_1OUT_LED"-Platine_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D5                | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D1,D3,D5          | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-40  | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R2,R7             | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R1,R3,<br>R5      | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    1   | R4                | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | R6                | 100 k&Omega;        | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | SW2               | Taster SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    1   | SW2 | Knopf f&uuml;r Taster 8x8mm, L&auml;nge 10mm, Farbe wei&szlig; |    

## Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 3x 2-polige St&uuml;cke abtrennen (f&uuml;r D1, D3, D5).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterknopf SW2 (wei&szlig;) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

![RW_5V_1OUT_LED_parts](/images/300_RW_5V_1OUT_LED_parts.png "RW_5V_1OUT_LED_parts")   
_Bild 42: Bauteile der "RW_5V_1OUT_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D5) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R5 (1 k&Omega; liegend)   
3. Transistor Q1 (BC337-40)   
4. Alle anderen Widerst&auml;nde   
5. Buchsenleisten J1 und J2   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

6. Taster SW2   
   
<a name="x43"></a>   

## 4.3 Zusammenbau des 1OUT-Blocks
1. Aufstecken des Steuerungsprints `RW_5V_1OUT_STRG` auf die Anzeigeplatine `RW_5V_1OUT_LED`.   
2. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
3. Aufstecken des Schalter-Knopfes.   
4. Falls vorhanden: Print `RW_LEER_LED` auf den Anzeigeprint stecken.   

### 4.4 Test des 1OUT-Blocks   
Der Test kann auf zwei Arten erfolgen.   

### "Labor-Test" mit 5V
F&uuml;r diesen Test ben&ouml;tigt man ein 5V-Netzteil, 9 St&uuml;ck einzelne Kabel Stecker auf Buchse sowie ein Voltmeter. Die Verkabelung entsprechend dem Bild durchf&uuml;hren, wobei die Buchsen der Leitungen direkt auf die Stifte der 6- bzw. 10-poligen Wannenstecker gesteckt werden k&ouml;nnen.   
_Zum Beispiel:_   
* rot: 5 V vom Netzteil nach J3-1 (5V)   
* rot: 5 V vom Netzteil nach J3-6 (V+)   
* braun: 0 V vom Netzteil nach J3-3 (0V)   
* braun: 0 V vom Netzteil nach J3-4 (V-)   
* gr&uuml;n: OUT+ von J5-5 zum Voltmeter +   
* blau: OUT- von J5-3 zum Voltmeter COM (-)   
* wei&szlig;: S1 von J4-1 nach au&szlig;en   
* schwarz: 0V von J4-5 nach au&szlig;en   
* gelb: R1 von J4-7 zum Voltmeter COM (-)   

![1OUT Testverkabelung](/images/300_1OUT_test_wiring.png "1OUT Testverkabelung") &nbsp; ![1OUT Testverkabelung2](/images/300_1OUT_test_wiring_img2.png "1OUT Testverkabelung2")   
_Bild 43: Verkabelung zum Testen des 1OUT-Blocks_   

Statt der beiden eingezeichneten Voltmeter kann nat&uuml;rlich auch nur eines verwendet werden.   

1. Anlegen der 5V-Spannung: Die obere, rote LED leuchtet.   
2. Den Remote-Set-Eingang S1 (Pin J4-1) mit 0V (Pin J4-5) verbinden: Das Relais schaltet, die rote LED erlischt, die gr&uuml;ne LED leuchtet.   
3. Den Taster bet&auml;tigen: Die gelbe LED und die gr&uuml;ne LED leuchten.   

* Das obere Voltmeter ("zum Entkuppler") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
* Das R&uuml;ckmeldesignal R1 (Voltmeter "R&uuml;ckmeldung") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
Das bedeutet: Kein Ausgangssignal ergibt die R&uuml;ckmeldung R1 = 0 V.   

__Im Fehlerfall__, falls die Versorgungs-(Wechsel-)spannung V+ ausf&auml;llt, leuchtet zwar die rote LED, aber beim Dr&uuml;cken des Tasters leuchten die gelbe und die rote LED. Die gr&uuml;ne LED leuchtet nicht, d.h., es gibt keine Spannung am Ausgang.   

### Test unter realen Bedingungen
1. Anschluss des Entkupplers an J5-Pin 3 (OUT-) und J5-Pin 5 (OUT+).
2. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_1OUT_STRG_.   
3. Bet&auml;tigen des Tasters: der Entkuppler sollte arbeiten.   

![Pinbelegung_1OUT-J5](/images/200_J5_pins_1OUT.png "Pinbelegung 1OUT-J5")   
_Bild 44: Pinbelegung des Steckers J5 von RW_5V_1OUT_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241102): OK   

[Zum Seitenanfang](#up)   

<a name="x50"></a>   
<a name="x51"></a>   

# 5. Abschaltbares Gleis (2IO)   

## 5.1 Steuerung der Fahrstrom-Abschaltung   
Diese Platine dient zum Ein- und Ausschalten des Fahrstroms f&uuml;r ein Gleis von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber einen Optokoppler.   

![RW_5V_2IO_STRG_circuit](/images/600_RW_5V_2IO_STRG_circuit.png "RW_5V_2IO_STRG_circuit")   
_Bild 45: Schaltplan der "RW_5V_2IO_STRG"-Platine_   

![Platine Fahrstrom-Abschaltung](/images/pcb_f/PCB_F_RW_5V_2IO_STRG_V1.png "Platine Fahrstrom-Abschaltung")   
_Bild 46: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_STRG](/images/300_RW_5V_2IO_STRG_V1.png "RW_5V_2IO_STRG")   
_Bild 47: Best&uuml;ckte Platine "300_RW_5V_2IO_STRG" zum Schalten des Fahrstroms_   

__St&uuml;ckliste__   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|--------|--------------|------------------------|--------------------|   
|    1   | C1           | Elko 33 &micro;F/35V   | Capacitor_THT:CP_Radial_D8.0mm_P2.50mm |   
|    1   | C2           | Kondensator 100 nF     | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|    1   | D1           | Diode 1N4007           | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
|    2   | D2,D3        | Diode 1N4148           | Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
|    2   | D4           | Diode 1N4148           | _kh_library:D_DO-35_P2.0mm_Vertical_AnodeUp_kh   |   
|    2   | J1,J2        | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5        | Wannenstecker 6-polig, stehend | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
|    1   | J4           | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical_kh |   
|    1   | K1           | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    1   | Q1           | Transistor BC327-40    | _kh_library:TO-92_Inline_Wide_2.2225 |   
|    1   | U1           | Optokoppler SFH615A    | Package_DIP:DIP-4_W7.62mm |   
|    1   | U1           | Fassung 4-polig (oder 2x Buchsenleiste mit 2 Pins) |       |   
|    1   | R3           | 100 &Omega;            | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R4           | 1 k&Omega;             | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R5           | 4,7 k&Omega;           | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    1   | R2           | 10 k&Omega;            | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R1           | 100 k&Omega;           | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

![RW_5V_2IO_STRG_parts](/images/300_RW_5V_2IO_STRG_parts.png "RW_5V_2IO_STRG_parts")   
_Bild 48: Bauteile der "RW_5V_2IO_STRG"-Platine_   

### Best&uuml;ckung   
1. IC-Fassung 4-polig (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2 bis D4 (1N4148)   
4. Transistor Q1 (BC327-40)   
5. Kondensator C1 (33 &micro;F)   
6. Kondensator C2 (100 nF)   
7. Diode D1 (1N4007)   
8. Alle Widerst&auml;nde   
9. Wannenstecker J1 bis J3   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
10. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

_Nicht vergessen_: Optokoppler U1 richtig herum in die Fassung stecken...   

### Versionen
* V1 (240930): OK

<a name="x52"></a>   

## 5.2 LED-Anzeige f&uuml;r Fahrstromabschaltung (2IO)
Diese Platine ist das User-Interface zur Schaltplatine "RW_5V_2IO_STRG". Sie hat zwei Schalter sowie fünf LEDs.    

![Blockpanel DisconTrack](/images/300_rcc4_Blockpanel_DisconTrack2.png "Blockpanel DisconTrack")   
_Bild 49: Bedienpanel für die Fahrstromabschaltung 2IO_   

* Im Ruhezustand sind beide _*Schalter*_ nicht gedr&uuml;ckt:  
  - 🟡 Die **mittlere, gelbe** LED leuchtet: Fernsteuerung über DCC bzw. I²C (Remote).  
  - 🔴🟢 Die **rote oder gr&uuml;ne** LED leuchtet, je nachdem, ob der Fahrstrom &uuml;ber DCC oder MQTT aus- oder eingeschaltet ist.   

* Wird der obere, rote **Schalter "AUS"** bet&auml;tigt, ist der Fahrstrom **auf jeden Fall** ausgeschaltet.  
  - 🟡 Die **obere, gelbe** LED leuchtet.  
  - 🔴 Die **rote** LED leuchtet.

* Wird der untere, grüne **Schalter "EIN"** bet&auml;tigt, hängt das Ergebnis vom oberen, roten Schalter "AUS" ab. Wenn dieser nicht betätigt ist:  
  - 🟡 Die **untere, gelbe** LED leuchtet.  
  - 🟢 Die **grüne** LED leuchtet.

#### Schaltplan

![RW_5V_2IO_LED_circuit](/images/600_RW_5V_2IO_LED_circuit.png "RW_5V_2IO_LED_circuit")   
_Bild 50: KiCad-Schaltplan der "RW_5V_2IO_LED"-Platine_   

![Platine 2-poliges Schalten](/images/pcb_f/PCB_F_RW_5V_2IO_LED_V2.png "Platine 2-poliges Schalten")   
_Bild 51: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_LED](/images/300_RW_5V_2IO_LED.png "RW_5V_2IO_LED")   
_Bild 52: Best&uuml;ckte Platine "RW_5V_2IO_LED"_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D4,D5,D6          | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    5   | D1,D3,D4,D5,D6    | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-40 | _kh_library:TO-92_Inline_Wide_custom |   
|    1   | R8                | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    5   | R1,R3,R4,R5,R6    | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R2                | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | R7                | 100 k&Omega;        | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | SW1,SW2           | _*Schalter*_ SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    2   | SW1,SW2           | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe rot, gr&uuml;n |    

### Vorbereitung   
1. Von einer langen, einreihigen Buchsenleiste 5x 2-polige St&uuml;cke abtrennen (f&uuml;r D1, D3 bis D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1 (rot), SW2 (gr&uuml;n) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

Das folgende Bild zeigt die Bauteile und die bereits vorbereiteten LEDs und Widerst&auml;nde.   
![RW_5V_2IO_LED_parts](/images/300_RW_5V_2IO_LED_parts.png "RW_5V_2IO_LED_parts")   
_Bild 53: Bauteile der "RW_5V_2IO_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D4, D5, D6) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R8 (47 &Omega;, liegend)   
3. Transistor Q1 (BC337-40)   
4. Die Widerst&auml;nde R2 (10 k&Omega;) und R7 (100 k&Omega;)   
5. Die restlichen Widerst&auml;nde R1, R3, R4, R5, R6 (1 k&Omega;)   
6. Buchsenleisten J1 und J2   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

7. __SCHALTER__ SW1, SW2 (Anleitung [siehe Kapitel 1.6](#x16))   

<a name="x53"></a>   

## 5.3 Zusammenbau des 2IO-Blocks
1. Aufstecken des Steuerungsprints `RW_5V_2IO_STRG` auf die Anzeigeplatine `RW_5V_2IO_LED`.   
2. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
3. Aufstecken der Schalter-Kn&ouml;pfe.   
4. Falls vorhanden: Print `RW_LEER_LED` auf den Anzeigeprint stecken.   

<a name="x54"></a>   

## 5.4 Test des 2IO-Blocks   
Der Test kann auf zwei Arten erfolgen.   

### "Labor-Test" mit 5V
F&uuml;r diesen Test ben&ouml;tigt man ein 5V-Netzteil, 9 St&uuml;ck einzelne Kabel Stecker auf Buchse sowie ein Voltmeter. Die Verkabelung entsprechend dem Bild durchf&uuml;hren, wobei die Buchsen der Leitungen direkt auf die Stifte der 6- bzw. 10-poligen Wannenstecker gesteckt werden k&ouml;nnen.   
_Zum Beispiel:_   
* rot: 5 V vom Netzteil nach J3-1   
* rot: 5 V vom Netzteil nach J5-1   
* braun: 0 V vom Netzteil nach J3-3   
* braun: 0 V vom Netzteil nach J5-2   
* gr&uuml;n: OUT+ von J5-5 zum Voltmeter +   
* blau: OUT- von J5-6 zum Voltmeter COM (-)   
* wei&szlig;: S1 von J4-1 nach au&szlig;en   
* schwarz: 0V von J4-5 nach au&szlig;en   
* gelb: R1 von J4-7 zum Voltmeter COM (-)   

![2IO Testverkabelung](/images/300_2IO_test_wiring.png "2IO Testverkabelung") &nbsp; ![2IO Testverkabelung2](/images/300_2IO_test_wiring_img.png "2IO Testverkabelung2")   
_Bild 54: Verkabelung zum Testen des 2IO-Blocks_   

Statt der beiden eingezeichneten Voltmeter kann nat&uuml;rlich auch nur eines verwendet werden.   

1. Beide Schalter entriegeln (nicht gedr&uuml;ckt).   
2. Anlegen der 5V-Spannung: Die mittlere gelbe LED und die rote LED leuchten.   
3. Den Remote-Set-Eingang S1 (Pin J4-1) mit 0V (Pin J4-5) verbinden: Das Relais schaltet, die rote LED erlischt, die gr&uuml;ne LED leuchtet.   
4. Den roten Schalter bet&auml;tigen: Die obere gelbe LED und die rote LED leuchten.   
5. Den roten Schalter entriegeln, den gr&uuml;nen Schalter bet&auml;tigen: Die untere gelbe LED und die gr&uuml;ne LED leuchten.   

* Das obere Voltmeter ("zum Gleis") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
* Das R&uuml;ckmeldesignal R1 (Voltmeter "R&uuml;ckmeldung") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
Das bedeutet: Kein Ausgangssignal ergibt die R&uuml;ckmeldung R1 = 0 V.   

### Test unter realen Bedingungen
1. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_2IO_STRG_.   
2. Anschluss der Gleisversorgung an J5-Pin 1 (DCC+) und J5-Pin 2 (DCC-) der Steuerungplatine _RW_5V_2IO_STRG_.   
3. Anschluss des zu schaltenden Gleises an J5-Pin 5 (DCCout+) und J5-Pin 6 (DCCout-).
4. Funktionstest: wie oben beschrieben.   

![Pinbelegung_2IO-J5](/images/200_J5_pins_2IO.png "Pinbelegung 2IO-J5")   
_Bild 55: Pinbelegung des Steckers J5 von RW_5V_2IO_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241103): OK   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   
<a name="x61"></a>   

# 6. Zweipoliger Umschalter (DPDT)   

## 6.1 Steuerung des zweipoligen Umschalters   
Diese Platine dient zum zweipoligen Umschalten 2x Um (engl. Double Pole Double Throw, kurz DPDT) einer Spannung. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber zwei Optokoppler (je einer f&uuml;r den Zustand NC = normally closed und NO = normally open).   

![RW_5V_DPDT_STRG_circuit](/images/600_RW_5V_DPDT_STRG_circuit.png "RW_5V_DPDT_STRG_circuit")   
_Bild 56: Schaltplan der "RW_5V_DPDT_STRG"-Platine_   

![Platine DPDT](/images/pcb_f/PCB_F_RW_5V_DPDT_STRG_V1.png "Platine DPDT")   
_Bild 57: Platine zum zweipoligen Umschalten einer Spannung_   

![RW_5V_DPDT_STRG](/images/300_RW_5V_DPDT_STRG_V1.png "RW_5V_DPDT_STRG")   
_Bild 58: Best&uuml;ckte Platine "RW_5V_DPDT_STRG" zum zweipoligen Umschalten_   

__St&uuml;ckliste__   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|:------:|:-------------|:-----------------------|:-------------------|   
|    2   | C1, C3       | Elko 33 &micro;F/35V   | Capacitor_THT:CP_Radial_D8.0mm_P2.50mm |   
|    1   | C2           | Kondensator 100 nF     | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|    2   | D1, D5       | Diode 1N4007           | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
|    1   | D2   | Diode 1N4148           | Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
|    3   | D3, D4, D6   | Diode 1N4148           | _kh_library:D_DO-35_P2.0mm_Vertical_AnodeUp_kh   |   
|    2   | J1,J2        | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5        | Wannenstecker 6-polig, stehend | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
|    1   | J4           | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical_kh |   
|    1   | K1           | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    1   | Q1           | Transistor BC327-40    | _kh_library:TO-92_Inline_Wide_2.2225 |   
|    2   | U1, U2       | Optokoppler SFH615A    | Package_DIP:DIP-4_W7.62mm |   
|    2   | U1, U2       | Fassung 4-polig (oder 2x Buchsenleiste mit 2 Pins) |       |   
|    2   | R3, R6       | 100 &Omega;            | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R4, R7       | 1 k&Omega;             | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R5, R8       | 4,7 k&Omega;           | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    1   | R2           | 10 k&Omega;            | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R1           | 100 k&Omega;           | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

### Best&uuml;ckung   
1. IC-Fassungen 4-polig U1, U2 (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2, D3, D4, D6   
4. Transistor Q1 (BC327-40)   
5. Kondensator C1, C3 (33 &micro;F/35V)   
6. Kondensator C2 (100 nF)   
7. Diode D1, D5 (Diode 1N4007)   
8. Alle Widerst&auml;nde   
9. Wannenstecker J3 bis J5   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
10. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

_Nicht vergessen_: Optokoppler U1, U2 richtig herum in die Fassung stecken...   

### Versionen
* V1 (241124): OK

<a name="x62"></a>   

## 6.2 LED-Anzeige f&uuml;r zweipoligen Umschalter
Diese Platine dient zum Ansteuern und Anzeigen der Zust&auml;nde der Schaltplatine "RW_5V_DPDT_STRG". Sie enth&auml;lt   
* in der Mitte der Platine einen Schalter zum Umschalten zwischen Fernsteuerung (&uuml;ber DCC oder MQTT) und lokalem Betrieb (Schalter nicht gedr&uuml;ckt)   
* unten Mitte einen Schalter zum Schalten des Relais bei lokalem Betrieb   
* eine gelbe LED links Mitte zur Anzeige eines Remote-Betriebs (LED leuchtet)   
* eine gelbe LED links unten zur Anzeige eines lokalen Betriebs (LED leuchtet)   
* eine gr&uuml;ne LED links oben zur Anzeige einer Ausgangsspannung an den Pins NC (normally closed) J5-Pin 3 f&uuml;r Vout+ und J5-Pin 4 f&uuml;r Vout-
* eine gr&uuml;ne LED links unten zur Anzeige einer Ausgangsspannung an den Pins NO (normally open) J5-Pin 5 f&uuml;r Vout+ und J5-Pin 6 f&uuml;r Vout-

![RW_5V_DPDT_LED](/images/300_DPDT_LED_front.png "RW_5V_DPDT_LED") ![RW_5V_DPDT_LED](/images/300_DPDT_LED_back.png "RW_5V_DPDT_LED")     
_Bild 59: Best&uuml;ckte Platine "RW_5V_DPDT_LED" (front und back)_   

![RW_5V_DPDT_LED_circuit](/images/600_RW_5V_DPDT_LED_circuit.png "RW_5V_DPDT_LED_circuit")   
_Bild 60: Schaltplan der "RW_5V_DPDT_LED"-Platine_   

![Platine 2-poliges Umschalten](/images/pcb_f/PCB_F_RW_5V_DPDT_LED_V1.png "Platine 2-poliges Umschalten")   
_Bild 61: Bedien-Platine zum 2-poligen Umschalten_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    2   | D1, D3            | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    2   | D5, D6            | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    4   | D1, D3, D5, D6    | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
|    2   | J1, J2            | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    3   | R2, R4, R5        | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R1, R3            | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | SW1,SW2           | _*Schalter*_ SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
|    2   | SW1,SW2           | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe schwarz, gelb |    
   
### Vorbereitung   
1. Von einer langen, einreihigen Buchsenleiste 4x 2-polige St&uuml;cke abtrennen (f&uuml;r D1, D3, D5, D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1, SW2 eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D5, D6) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R2, R4 (liegend)   
3. Die restlichen Widerst&auml;nde R1, R3, R5   
4. Buchsenleisten J1 und J2   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

6. __SCHALTER__ SW1, SW2   
   

### Test   
Die Eingangsspannung IN+ und IN- sowie die Ausgangsspannung NC ("Normally Closed") bzw. NO ("Normally Open") des DPDT-Blocks liegen am 6-poligen Stecker J5 von RW_5V_DPDT_STRG.   
![Pinbelegung_DPDT-J5](/images/200_J5_pins_DPDT.png "Pinbelegung DPDT-J5")   
_Bild 62: Pinbelegung des Steckers J5 von RW_5V_DPDT_STRG_   

1. Einstecken der LEDs: Die rot markierte Anode = Pluspol zeigt immer nach au&szlig;en zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_DPDT_LED_ auf die Steuerungsplatine _RW_5V_DPDT_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_DPDT_STRG_:   
* Ist der __*mittlere Schalter*__ nicht gedr&uuml;ckt, so leuchtet die mittlere, gelbe LED = Remote-Betrieb.   
* Ist der __*mittlere Schalter*__ gedr&uuml;ckt, so leuchtet die gelbe LED links unten = lokaler Betrieb.   
4. Anschluss einer Eingangsspannung IN+ an J5-Pin 1 und IN- J5-Pin 2 der Steuerungplatine _RW_5V_DPDT_STRG_. Ist die Eingangsspannung gr&ouml;&szlig;er als ca. 2,5 V bis 3 V, so leuchtet eine der beiden gr&uuml;nen LEDs:   
* Ist der mittlere Taster gedr&uuml;ckt ("Lokal") und der untere Taster offen, so ist das Ausgangsrelais in der Stellung NC ("Normally Closed"). Die Spannung IN+ liegt an Pin J5-3 und IN- an Pin J5-4 an und die obere gr&uuml;ne LED leuchtet. Pin J5-5 und J5-6 f&uuml;hren keine Spannung.   
* Sind beide Taster gedr&uuml;ckt, so ist das Ausgangsrelais in der Stellung NO ("Normally Open"). Die Spannung IN+ liegt an Pin J5-5 und IN- an Pin J5-6 an und die untere gr&uuml;ne LED leuchtet. Pin J5-3 und J5-4 f&uuml;hren keine Spannung.   
5. Mittlerer Schalter ungedr&uuml;ckt: Remote-Steuerung &uuml;ber DCC oder MQTT. Mit dem Demoprogamm kann mit der DCC-Adresse 41 (PCF8574-Pin 6) der Umschalter bet&auml;tigt werden und die gr&uuml;nen LEDs leuchten je nach Ausgangsspannung.   
   
_Anmerkung_: Leuchtet keine der beiden gr&uuml;nen LEDs, so liegt wahrscheinlich keine Eingangsspannung am 6-poligen Stecker J5.   

### Versionen
* V1 (241124): OK   

[Zum Seitenanfang](#up)   
<a name="x70"></a>   
<a name="x71"></a>   

# 7. Abschaltbares Gleis mit Strommessung (TUI)

## 7.1 Prinzip

Der Block **TUI** ist eine Weiterentwicklung des Blocks [Abschaltbares Gleis (2IO)](#x50).

Zusätzlich zum Ein- und Ausschalten der Fahrspannung und der dazugehörenden Anzeige wird überprüft, ob ein Fahrstrom fließt. Fließt Strom, leuchtet statt der grünen LED eine gelbe LED.

Im Gegensatz zu den oben beschriebenen Blöcken besteht der Block **TUI** aus drei Teilen:

* Zusätzliche Fahrstrom-Schalt-/Erkennungsplatine `RCC_TUI_EXT`
* Steuerungs-/Verbindungsplatine `RCC_TUI_STRG`
* Anzeigeplatine `RCC_TUI_LED`

<a name="x72"></a>   

## 7.2 Externe Platine zum Fahrstrom-Schalten und -Erkennen

### 7.2.1 Einleitung
Die Platine `RCC_TUI_EXT` kann die Fahrspannung über ein Relais **ein- und ausschalten**. Weiters erkennt sie, ob  
1. **Gleisspannung** (SCC-Fahrspannung) anliegt und ob  
2. **Fahrstrom** fließt.

Der Status wird über **LEDs angezeigt** und steht zusätzlich an **zwei digitalen Ausgängen** zur Verfügung:   
* **Gleisspannung (DCC)** liegt an: **grüne LED** leuchtet.  
* **Fahrstrom** fließt: **rote LED** leuchtet, Gleis ist **besetzt**.   

Die Stromversorgung, der digitale Eingang und die beiden digitalen Ausgänge sind über einen **6-poligen Stecker** angeschlossen.   

![UI_pin_J5](/images/200_rcc4_TUI_pin_J5.png "UI_pin_J5")   
_Bild 62: Belegung des 6-poligen Anschlusses der `RCC_TUI_EXT`-Platine_

TONn ... Set Track Voltage ON (0V) = Schalte Fahrspannung ein (0V)  
TVn ...... Track Voltage is ON (0V) = Fahrspannung ist ein (0V)   
FREn .... Track Free (0V) = Gleis frei (0V)   

<a name="x722"></a>   

### 7.2.2 Schalten der Fahrspannung
Das Schalten der Fahrspannung erfolgt mit einem monostabilen Relais IM03TS oder HFD4-3:  
![rcc4_TUI_EXT_relay](/images/300_rcc4_TUI_EXT_relay.png "rcc4_TUI_EXT_relay")   
_Bild 63: Einschalten der Fahrspannung mit Relais_

<a name="x722"></a>   

### 7.2.3 Gewinnung des Fahrstrom-Signals
Der Fahrstrom (maximal 2 A) wird durch einen Shunt in eine Spannung umgewandelt:   

![Schaltung Fahrstromsignal](/images/300_rcc4_TUI_EXT_shunt.png "Schaltung Fahrstromsignal")   
_Bild 64: Shunt zur Gewinnung des Fahr**strom**signals_

Für kleine DCC-Ströme ergibt der Laststrom einen Spannungsabfall an Rs1, für größere Ströme wird durch die Dioden eine Spannung von 0,3 V bis 0,5 V erzeugt. Durch die Antiparallelschaltung der Dioden wird die Spannung auf diesen Wert begrenzt.   
Die Widerstände Rs2 und Rs3 sorgen dafür, dass nur die Differenzspannung verstärkt wird.   

#### Maximaler und minimaler Fahrstrom   
Lokomotiven benötigen Ströme von einigen 100 mA. Der Gesamtstrom auf der Zuleitung wird durch den Booster festgelegt und ist - für N-Spur - üblicherweise 2 A (manchmal auch 3 A).   

Bei einem Widerstand Rs1 von 10 kΩ und einer Spannung U<sub>Rs1</sub> von 0,5 V ergibt sich ein erkannter Strom von   
I<sub>min</sub> = U<sub>Rs1</sub> / Rs1 = 0,5 / 10k = 50 μA.   

Somit beträgt der Strombereich, der von der Schaltung erkannt werden soll, ca. 50 μA bis zu 2 A.   

#### Grenzen für den Lastwiderstand   
Für eine DCC-Spannung von zB ±20 V ergibt ein maximaler Laststrom von 2 A einen minimalen Lastwiderstand von 10 Ω. (Leistung 40 W!)   

Um abgestellte Wagen ebenfalls zu erkennen, muss die Isolierung der Räder mit Widerstandslack (zB Uhlenbrock 40410) überbrückt werden. Der Widerstand sollte mindestens 10 kΩ betragen (keinesfalls weniger als 4 kΩ, da sonst Brandgefahr besteht). Bei einer DCC-Spannung von max. ±20V ergibt dies einen Strom von   
$\ I_{max} = U_{DCC} / R_{min} = 20 / 10k = 2 mA. $   

Maximaler Lastwiderstand bei einer DCC-Spannung von zB ±14V:   
R<sub>Lmax</sub> = (14 - 0,6) / 60μ = 220 kΩ   
Dies bedeutet, dass der Widerstandslack an einem Rad zwischen 10 kΩ und 220 kΩ groß sein soll.   

<a name="x724"></a>   

### 7.2.4 Signalverstärkung
Die vom Shunt erzeugte Spannung wird mit einem INA333-Instrumentenverstärker-Board (CJMCU-333) verstärkt. Die Verstärkung ist von 1 bis zu ca. 1000 einstellbar.    
Lässt man den Referenzpin VREF offen, so wird eine interne Referenzspannung von 3,3 V /2 = 1,65 V verwendet. Die Ausgangsspannung sollte daher eine Gleichspannung von 1,65 V sein.   

Ohne Beschaltung und ohne Last sieht ein typisches Ausgangssignal allerdings oft so aus:   
![Ausgangsspannung INA333 leer](/images/300_rcc6_ui_INA333_Uout_no_load.png "Ausgangsspannung INA333 leer")   
_Bild 65: Verstärkte Shunt-Spannung ohne Last_

Im Bild erkennt man eine Störspannung von 50 Hz mit diversen Überlagerungen.   
**Beispielwerte**   
Maximale Spannung: 2,26V   
Spitze-Spitze-Spannung: 1,46 V   
Gleichspannung zwischen den Impulsen: 1,6 V   
Pulsfrequenz: 50 Hz (alle 20 ms)   
__Anmerkung__: Vertauscht man die Eingänge DCC1 und DCC2, so wird das Signal invertiert...   

Vergrößert man mit dem Trimmer auf dem INA333-Board die Verstärkung auf den Maximalwert, so erhält man folgendes Signal:   
![Ausgangsspannung INA333 leer vmax](/images/o_rcc6_ui_INA333_Uout_no_load_vmax.png "Ausgangsspannung INA333 leer vmax")   
_Bild 66: Stark verstärkte Shunt-Spannung ohne Last_

Im Bild erkennt man, dass der Verstärker übersteuert ist (unten bei der 0V-Linie).   
**Beispielwerte**   
Maximale Spannung: 2,86V   
Spitze-Spitze-Spannung: 2,86 V   
Gleichspannung zwischen den Impulsen: 1,65 V   
Pulsfrequenz: 50 Hz (alle 20 ms)   

Beschaltet man den Ausgang des INA333 mit einem Spitzenspannungsspeicher (D3-C1) und RC-Tiefpass, so ändert sich der Ausgang des INA333 nicht (d.h. es gibt keine Rückwirkung).   
![INA333 Schaltung Ausgangsfilter](/images/300_rcc6_ui_schematic_INA333_output_filter.png "INA333 Schaltung Ausgangsfilter")   
_Bild 67: Spitzenspannungsspeicher_

Am Ausgang des Filters liegt eine Gleichspannung, die durch eine Störspannung überlagert ist (zB 0,26 mV). Die folgende Tabelle enthält einige Messwerte für die Spannung UF2.   

| Lastwiderstand <br> kΩ | UF2 <br> V |   
|:----:|:-----:|   
| unendlich | 0,755 |   
| 330k | 0,798 |   
| 220k | 0,821 |   
| 100k | 0,933 |   
|  47k | 1,042 |   
|  22k | 1,068 |   
|  10k | 1,076 |   
|   1k | 1,085 |   
| 0,1k | 1,100 |   
| 0,02k | 1,112 |   

Die grafische Darstellung der Werte zeigt, dass bei hohen Lastwiderständen der Shunt-Widerstand und bei kleinen Lastwiderständen die Shunt-Dioden für den Wert der Filterspannung verantwortlich sind.   
![INA333 Filterausgang lin](/images/300_rcc6_ui_INA333_filter_output_lin.png "INA333 Filterausgang lin")   
![INA333 Filterausgang log](/images/300_rcc6_ui_INA333_filter_output_log.png "INA333 Filterausgang log")   
_Bild 68: Spitzenspannung in Abhängigkeit vom Lastwiderstand_

<a name="x725"></a>   

### 7.2.5 Erzeugen des Frei-Signals
Da das Ausgangssignals des Filters stark verrauscht ist, erfolgt die Erzeugung des Digitalsignals in zwei Stufen:   
* In einem ersten Schritt wird die Spannung mit einem Sollwert verglichen.   
* Im zweiten Schritt wird diese Spannung UK1 mit einem Tiefpass geglättet und nochmals mit der halben Versorgungsspannung verglichen.   

==> Eine Ausgangsspannung von 0 V bedeutet, dass kein Fahrstrom fließt bzw. das Gleis nicht belegt ist.    
==> Eine Ausgangsspannung von 5 V bedeutet, dass ein Fahrstrom fließt bzw. das Gleis besetzt ist.    

Die Ausgangsspannung wird (von einem Transistor invertiert) durch eine rote LED angezeigt:  
* Rote LED ein = Fahrstrom fließt = Gleis besetzt.   
* Rote LED aus = kein Fahrstrom = Gleis frei oder kein Fahrstrom.   

![LM393 Schaltung Digitalsignal](/images/300_rcc4_ui_schematic_LM393_comparator.png "LM393 Schaltung Digitalsignal")   
_Bild 69: Schaltung zur Erzeugung des Gleis-Frei-Signals_

<a name="x726"></a>   

### 7.2.6 DCC-Spannungserkennung
Für die Gleisspannungserkennung wird das Gleissignal gleichgerichtet (1N4007), geglättet (100 &Omega;, 33 &micro;F) und einem Optokoppler zugeführt (1 k&Omega;, SFH615A). Der Optokoppler schaltet die **grüne LED** und mit T2 wird das Signal entkoppelt.   
![dcc_track_U_detection_circuit](/images/300_rcc4_track_U_detection_circuit.png "dcc_track_U_detection_circuit")   
_Bild 70: DCC-Gleis**spannungs**erkennung_

<a name="x727"></a>   

### 7.2.7 Gesamtschaltung

![RCC_TUI_EXT_V1_circuit](/images/600_RCC_TUI_EXT_V1_circuit.png "RCC_TUI_EXT_V1_circuit")   
_Bild 71: KiCad-Schaltplan der "RCC_TUI_EXT_V1"-Platine_

<a name="x728"></a>   

### 7.2.8 Bestücken der Platine
Bild der Platine `RCC_TUI_EXT_V1` zur DCC-Gleis-Spannungs-/Strom-Erkennung:   
![Platine Gleis-UI-Erkennung](/images/pcb_f/PCB_F_RCC_TUI_EXT_V1.png "Platine Gleis-UI-Erkennung")   
_Bild 72: Platine `RCC_TUI_EXT_V1` zur DCC-Gleis-Spannungs-/Strom-Erkennung_

Best&uuml;ckte Platine "`RCC_TUI_EXT_V1`"   
![Bestückte Platine RCC_TUI_EXT_V1](/images/300_RCC_TUI_EXT_V1_assembled.png "Bestückte Platine RCC_TUI_EXT_V1")   
_Bild 73: Best&uuml;ckte Platine `RCC_TUI_EXT_V1`_  

#### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|-------------------------|   
| 5 | C1, C2, C4, C7, C8 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 2 | C3, C5 | Tantal-Elko 10 &micro;F, 16 V, Raster 2,54 mm | C_L4.32mm_D3.81mm_P2.54mm_kh |   
| 1 | C6 | Elko 33 &micro;F, 35 V, Raster 2,54 mm | CP_Radial_D8.0mm_P2.50mm |   
| 2 | D1, D2 | Diode SB240 | D_DO-15_P3.81mm_Vertical_AnodeUp |   
| 1 | D3 | Diode BAT48 | D_DO-35_SOD27_P5.08mm_Horizontal_kh |   
| 1 | D5 | Diode 1N4007 | D_DO-41_SOD81_P2.54mm_Vertical_AnodeUp_rect8 |   
| 1 | D7 | Diode 1N4148 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 1 | D4 | LED rot, 3 mm, 2 mA | LED_D3.0mm |   
| 1 | D6 | LED gr&uuml;n, 3 mm, 2 mA | LED_D3.0mm |   
| 2 | D4, D6 | Buchsenleiste (gedrehte Buchsen), 2-polig (1) |   |   
| 2 | J1, J2 | Schraubklemme, 2-polig, schwarz, 5 mm | Screw_Terminal_01x02_P5 |   
| 1 | J3 | Stiftleiste 2-polig (2) | PinSocket_1x02_P2.54mm_Vertical_kh |   
| 1 | J3 | Jumper 2-polig |    |   
| 1 | J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | K1 | Monostabiles Relais IM03TS 3VDC oder HFD4/3 | Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
| 2 | K1 | Buchsenleiste (gedrehte Buchsen), 4-polig | (3)  |   
| 1 | Q1 | npn-Transistor BC337-40 | TO-92_Inline_Wide_custom |   
| 1 | Q2, Q3 | pnp-Transistor BC327-40 | TO-92_Inline_Wide_2.2225 |   
| 2 | R16, R18 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R11 | 100 &Omega;| R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 5 | R4, R8, R10, R12, R13 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R14, R15 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 4 | R2, R6, R7, R20 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | Rs1 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 3 | R1, Rs2, Rs3 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R3 | 33 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R5 | 47 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 2 | R9, R17 | 47 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R19 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | Rs4 | 220 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P10,16mm_Horizontal |   
| 1 | RV1 | 10-Gang-Trimmer 10 k&Omega; stehend | Trim_Bourns_3296W_Vertical |   
| 1 | U1 | INA333_Board | INA333-Board |   
| 2 | U1 | Buchsenleiste 4-Pin, gedrehte Pins (4) |   |   
| 2 | U1 | Stiftleiste 4-Pin, gedrehte Pins (5) |   |   
| 1 | U2 | 2-fach-Komparator LM393 | DIP-8_W7.62mm_Socket_LongPads |   
| 1 | U2 | Präzisionssockel 8 Pin (2x 4 Pin, Abstand 7,62 mm) |   |    
| 1 | U3 | Optokoppler SFH615A | DIP-4_W7.62mm |   
| 1 | U3 | Präzisionssockel 4 Pin (2x 2 Pin, Abstand 7,62 mm) |   |    

1) Fassung für Relais  

Bauteile der "RCC_TUI_EXT_V1"-Platine (Version 1):   
![rcc6_RCC_TUI_EXT_V1_parts](/images/300_rcc6_RCC_TUI_EXT_V1.png "rcc6_RCC_TUI_EXT_V1")   
_Bild 74: Bauteile der "RCC_TUI_EXT_V1"-Platine_   

#### Vorbereitung   
(1) 2x gedrehte, 2-polige Buchsen für die LEDs: Von einer (meist 40-poligen) Buchsenleiste herunterschneiden.   
(2) 1x 2-polige Stiftleiste von Stiftleiste herunterschneiden   
(3) 2x gedrehte, 4-polige Buchsen als Relais-Fassung: Von einer (meist 40-poligen) Buchsenleiste herunterschneiden.   
(4) 2x 4-polige Buchsenleiste für das INA333-Board: Von 8- bzw. 10-poligen Buchsenleisten herunterschneiden.    
(5) 2x 4-polige Stiftleisten für das INA333-Board: Beiliegende 8-polige Stiftleiste in der Mitte auseinanderschneiden.   
(6) 2x 4-polige Stiftleisten auf der Unterseite des INA333-Boards nach UNTEN anlöten (siehe Bild).   

![rcc6_INA333_Board](/images/300_rcc6_INA333_Board.png "rcc6_INA333_Board")   
_Bild 75: INA-Board mit angelöteten Stiften_  

#### Best&uuml;ckung  
1. Widerst&auml;nde R1, Rs2, Rs3 (liegend, möglichst flach, 10 k&Omega;)  
2. Widerstand R5 (liegend, 47 k&Omega;)  
3. Widerstand Rs4 (liegend, 220 k&Omega;)  
4. Diode D3 (BAT48, liegend, auf Polung achten: Kathode bei weißer Linie)  
5. Buchsenleisten 2x 4 Pin für U1 (INA333 Board)  
6. gedrehte Buchsen 2x 2 Pin für die LEDs D4, D6  
7. gedrehte Buchsen 2x 4-Pin für Relais K1 (Pin 1 und 8 etwas verbiegen)  
8. Fassungen U2 (2x 4 Pin) und U3 (2x 2 Pin, auf Einbaurichtung achten!)  
9. Kondensatoren C1, C2, C4, C7, C8 (1 &micro;F, Raster 2,54 mm)  
10. Diode D7 (1N4148, stehend, auf Polung achten: Kathode unten beim Kreis)  
11. Diode D5 (1N4007, stehend, auf Polung achten: Kathode unten beim Kreis)  
12. Tantal-Elko C3, C5 (10 &micro;F, auf + Polung achten)  
---  
13. Widerst&auml;nde R16, R18 (47 &Omega;)   
14. Widerstand R11 (100 &Omega;)   
15. Widerst&auml;nde R4, R8, R10, R12, R13 (1 k&Omega;)   
16. Widerst&auml;nde R14, R15 (4,7 k&Omega;)   
17. Widerst&auml;nde R2, R6, R7, R20, Rs1 (10 k&Omega;)   
18. Widerstand R3 (33 k&Omega;)   
19. Widerst&auml;nde R9, R17 (47 k&Omega;)   
20. Widerstand R19 (100 k&Omega;)   
---  
21. Elko C6 (Elko 33 &micro;F, auf - Polung achten)   
22. Transistor Q1 (BC337-40)   
23. Transistor Q2, Q3 (BC327-40)   
24. Stiftleiste 2-polig J3   
25. Diode D1, D2 (SB240, auf Polung achten: Kathode unten beim Kreis)   
26. Wannenstecker 6-polig J5 (auf Polung achten)   
27. Schraubklemme J1, J2 (2-polig)   
28. 10-Gang-Trimmer RV1 (10 k&Omega; stehend, Schraube in Richtung LM393)   

##### Print vervollständigen
1. ICs bestücken (LM393, SFH615A, auf richtige Polung achten!)  
2. Relais K1 bestücken  
2. INA333_Board aufstecken (mit Potenziometer zum Print-Rand)  
3. LEDs auf passende Länge kürzen (zB 10 mm) und in die Fassungen stecken (auf richtige Polung achten!)  
![rcc4_LED_Polung](/images/200_rcc4_LED_Polung.png "rcc4_LED_Polung")   


<a name="x729"></a>   

### 7.2.9 Inbetriebnahme und Test

![UI_pin_J5](/images/200_rcc4_TUI_pin_J5.png "UI_pin_J5")   
_Bild 76: Belegung des 6-poligen Anschlusses J5 der `RCC_TUI_EXT`-Platine_

1. Spannungsversorgung anlegen: +5 V an J5-Pin 4, 0 V = GND an J5-Pin 6  
   ► 🔴🟤 Die rote LED (FRE) leuchtet oder leuchtet nicht (siehe Punkt 6).   
   ► ⚫ Die grüne LED (DCC) leuchtet nicht.   

2. DCC-Spannung am Eingang der Schaltung anlegen:   
   ► ⚫ Die grüne LED (DCC) leuchtet (noch) nicht.   

3. DCC-Spannung durchschalten: GND (0 V) an Pin 5 von J5 anlegen.  
   ► 🧲 Das Relais zieht an.   
   ► 🟢 Die grüne LED (DCC) **leuchtet**.   

4. Verstärkung des INA333-Boards voll aufdrehen:   
   ► ⚙️ Potenziometer bis zum Anschlag **gegen den Uhrzeigersinn** drehen   

5. Jumper J3 aufstecken   

6. Je nach Trimmer-Stellung die Schaltschwelle einstellen:   
   * 🔴 Wenn die rote LED __leuchtet__: Trimmer __im Uhrzeigersinn__ drehen, bis die rote LED erlischt, dann etwas gegen den Uhrzeigersinn drehen, bis die rote LED wieder leuchtet. Jumper J3 abziehen: rote LED erlischt.   
   * 🟤 Wenn die rote LED __nicht leuchtet__: Trimmer __gegen den Uhrzeigersinn__ drehen, bis die rote LED zu leuchten beginnt. Jumper J3 abziehen: rote LED erlischt.   

⚠️ Der Jumper J3 dient nur zum Einstellen. Im Betrieb muss er entfernt werden.   
ℹ️ Bei optimaler Einstellung leuchtet die rote LED bereits auf, wenn man die Gleise mit dem Finger verbindet.   

#### Kontrolle der Digitalausgänge
1. Spannungsversorgung anlegen: +5 V an J5-Pin 4, 0 V = GND an J5-Pin 6  
2. Messgerät auf Spannungsmessung stellen, COM-Anschluss mit GND verbinden , V/Ω an **Pin 2** von J5 (TVn) anschließen.   
3. Funktionstest **Ausgang TVn** (Track Voltage):   
   ► DCC-Versorgung abgeschaltet oder abgeklemmt: TVn = 5 V (⚫ grüne LED aus).   
   ► DCC-Versorgung angeschlossen **und** J5-Pin 5 auf 0 V (TONn): TVn = 0,7 V (🟢 grüne LED ein).  
---  
4. Messgerät COM mit GND verbinden, V/Ω an **Pin 1** von J5 (FREn) anschließen.   
5. Funktionstest **Ausgang FREn** (Track Free):   
   ► DCC-Versorgung am ""Booster"-Eingang anschließen, J5-Pin 5 auf 0 V (TONn).  
   ► Jumper J3 offen: FREn = 0,2 V (🟤 rote LED aus),  
   ► Jumper J3 gesteckt: FREn = 5 V (🔴 rote LED leuchtet).  

⚠️ **Ruhezustand**: Bei offenem Jumper und ohne Lok (bzw. Last, Waggon) am Gleis darf die **rote LED nicht** leuchten.   

<a name="x72A"></a>   

### 7.2.10 Versionen
* V1 (260902): OK   

<a name="x73"></a>   
<a name="x731"></a>   

## 7.3 Steuerungsplatine zum Fahrstrom-Schalten und -Erkennen

### 7.3.1 Schaltung

Da die Hauptarbeit von der externen Platine übernommen wird, muss die Steuerplatine lediglich die Signale zur Anzeigeplatine weiterleiten.  
Zusätzlich werden die Datenleitungen geschützt:  
* **Eingänge** (`IONn`, `TV1n`, `FRE1n`): Diode und `100 kΩ`-Widerstand nach `+5 V`  
* **Ausgänge** (I²C-Rückmeldungen `RTVn`, `RFREn`): Diode und `4,7 kΩ`-Widerstand nach `+5 V`  

![TUI_STRG_circuit12](/images/300_rcc4_TUI_STRG_circuit12.png "TUI_STRG_circuit12") 
_Bild 77: Schutzbeschaltung der Ein- und Ausgangsleitungen_

Gesamtschaltung:  

![RCC_TUI_STRG_V1_circuit](/images/600_RCC_TUI_STRG_V1_circuit.png "RCC_TUI_STRG_V1_circuit")   
_Bild 78: KiCad-Schaltplan der `RCC_TUI_STRG_V1`-Platine_  

<a name="x732"></a>   

### 7.3.2 Bestücken der Platine

![Platine zum Fahrstrom-Schalten und -Erkennen](/images/pcb_f/PCB_F_RCC_TUI_STRG_V1.png "Platine zum Fahrstrom-Schalten und -Erkennen")   
_Bild 79: Platine `RCC_TUI_STRG_V1`_  

![Bestückte Platine RCC_TUI_STRG](/images/300_RCC_TUI_STRG_V1_assembled.png "Bestückte Platine RCC_TUI_STRG")   
_Bild 80: Bestückte Platine `RCC_TUI_STRG`_  

__St&uuml;ckliste__   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|:------:|:-------------|:-----------------------|:------------------------|   
| 1 | C1 | Kondensator 100 nF | C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
| 4 | D1, D2, D3, D4 | Schottky-Diode BAT48 | D_DO-35_P7.62mm_Horizontal_kh |   
| 1 | D5 | Schottky-Diode BAT48 | D_DO-35_P12.7mm_Horizontal_kh |   
| 2 | J1, J2 | Stiftleiste 8-polig (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_kh |   
| 2 | J3, J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | J4 | Wannenstecker 10-polig, stehend | Box_02x05_P2.54mm_Vertical_kh |   
| 1 | R1 | 100 k&Omega; | R_Axial_P5.08_Vertical_kh |   
| 2 | R2, R3 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R4, R5 | 4,7  k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | JP1 | Jumper_2_Bridged | SolderJumper-2_P1.3mm_Bridged_Pad1.0x1.5mm |   


#### Best&uuml;ckung   
1. Dioden D1 bis D5 (BAT48, liegend, auf Polung achten: Kathode bei weißer Linie)  
2. Kondensator C1 (100 nF)  
3. Widerstände R1, R2, R3 (100 k&Omega;, stehend)  
4. Widerstände R4, R5 (4,7 k&Omega;, stehend)  
5. Wannenstecker J3 bis J5   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
6. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

<a name="x733"></a>   

### 7.3.3 Test
Die Platine ist sehr einfach. Der Test erfolgt daher gemeinsam mit `RCC_TUI_LED`.

<a name="x734"></a>   

#### 7.3.4 Versionen
V1 (260905): OK

<a name="x74"></a>   
<a name="x741"></a>   

## 7.4 LED-Anzeige f&uuml;r Fahrstromabschaltung und Besetztanzeige (TUI)
### 7.4.1 Beschreibung

Diese Platine ist das User-Interface zur Schaltplatine "RW_5V_2IO_STRG". Sie hat zwei Schalter sowie sechs LEDs.    

![Blockpanel RCC_TUI_LED](/images/300_rcc4_Blockpanel_TUI_LED.png "Blockpanel RCC_TUI_LED")   
_Bild 81: Bedienpanel für die Fahrstromabschaltung und Besetztanzeige TUI_   

* Im Ruhezustand sind beide _*Schalter*_ nicht gedr&uuml;ckt:  
  - 🟡 Die **linke, mittlere, gelbe** LED leuchtet: Fernsteuerung über DCC bzw. I²C (Remote).  
  - 🔴🟠🟢 Die **rote, (rechte) gelbe oder gr&uuml;ne** LED leuchtet, je nachdem, ob der Fahrstrom &uuml;ber DCC oder MQTT aus- oder eingeschaltet ist bzw. das Gleis frei ist.   

* Wird der obere, rote **Schalter "AUS"** bet&auml;tigt, ist der Fahrstrom **auf jeden Fall** ausgeschaltet.  
  - 🟡 Die **linke, obere, gelbe** LED leuchtet.  
  - 🔴 Die **rote** LED leuchtet.

* Wird der untere, grüne **Schalter "EIN"** bet&auml;tigt, hängt das Ergebnis vom oberen, roten Schalter "AUS" ab. Wenn dieser nicht betätigt ist:  
  - 🟡 Die **linke, untere, gelbe** LED leuchtet.  
  - 🟠 Die **rechte, mittlere, gelbe** LED leuchtet, wenn das Gleis besetzt ist.   
  - 🟢 Die **grüne** LED leuchtet, wenn das Gleis frei ist.  

<a name="x742"></a>   

### 7.4.2 Schaltplan
Den Schaltplan zum Schalten der LEDs gibt es in zwei Versionen:  
* mit bipolaren Transistoren (BC337)  
* mit MOSFET (BS170)  

Mit Transistoren:   
![RCC_TUI_LED_B_circuit](/images/600_RCC_TUI_B_LED_circuit.png "RCC_TUI_LED_B_circuit")   
_Bild 82: KiCad-Schaltplan der "RCC_TUI_B_LED"-Platine mit bipolaren Transistoren_   

Mit MOSFET:  
![RCC_TUI_LED_M_circuit](/images/600_RCC_TUI_M_LED_circuit.png "RCC_TUI_LED_M_circuit")   
_Bild 83: KiCad-Schaltplan der "RCC_TUI_M_LED"-Platine mit MOSFET_   

<a name="x743"></a>   

### 7.4.3 Bestückung
Bild links: Schalten/Anzeige-Platine mit Transistoren (`RCC_TUI_B_LED_V1`), rechts mit MOSFET (`RCC_TUI_M_LED_V1`)  

![Platine zum Schalten/Anzeigen des Fahrstroms](/images/pcb_f/PCB_F_RCC_TUI_B_LED_V1.png "Platine zum Schalten/Anzeigen des Fahrstroms") ![Platine zum Schalten/Anzeigen des Fahrstroms](/images/pcb_f/PCB_F_RCC_TUI_M_LED_V1.png "Platine zum Schalten/Anzeigen des Fahrstroms")   
_Bild 84: Platinen zum Schalten und Anzeige des Fahrstroms_   

# ..ToDo.. ..ToDo..

![RCC_TUI_M_LED](/images/300_RCC_TUI_M_LED_assembled.png "RCC_TUI_M_LED")   
_Bild 85: Best&uuml;ckte Platine "RCC_TUI_M_LED"_   

#### St&uuml;ckliste MOSFET-Version   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
| 1 | C1 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 1 | D1 | LED rot, 2 mA | LED_D3.0mm_kh |   
| 4 | D2, D4, D5, D6 | LED gelb, 2 mA | LED_D3.0mm_kh |   
| 1 | D3 | LED gr&uuml;n, 2 mA  | LED_D3.0mm_kh |   
| 6 | D1,D2,D3,D4,D5,D6  | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
| 2 | J1, J2 | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_11mm_kh |   
| 4 | Q1, Q2, Q3, Q4 | n-Kanal MOSFET BS170 | TO-92_Inline_Wide_custom |   
| 1 | R16 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 1 | R17 | 47 &Omega; | R_Axial_DIN0207_L6.3mm_D2.5mm_P12.7mm_Horizontal_kh |   
| 6 | R2, R5, R9, R21, R22, R23 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R12, R15 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 3 | R4, R11, R14 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R7 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 1 | R1 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 1 | R8 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 4 | R3, R6, R10, R13 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | SW1,SW2           | _*Schalter*_ SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
| 2 | SW1,SW2           | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe rot,

#### Vorbereitung   
1. Von einer langen, einreihigen Buchsenleiste 6x 2-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1 (rot), SW2 (gr&uuml;n) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

Das folgende Bild zeigt die Bauteile und die bereits vorbereiteten LEDs und Widerst&auml;nde.   
![RCC_TUI_M_LED_parts](/images/300_RCC_TUI_M_LED_parts.png "RCC_TUI_M_LED_parts")   
_Bild 86: Bauteile der "RCC_TUI_M_LED"-Platine_   

#### Best&uuml;ckungsvorgang   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1 bis D6) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R8 (47 &Omega;, liegend)   
3. Transistor Q1 (BC337-40)   
4. Die Widerst&auml;nde R2 (10 k&Omega;) und R7 (100 k&Omega;)   
5. Die restlichen Widerst&auml;nde R1, R3, R4, R5, R6 (1 k&Omega;)   
6. Buchsenleisten J1 und J2   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

7. __SCHALTER__ SW1, SW2 (Anleitung [siehe Kapitel 1.6](#x16))   

<a name="x744"></a>   

### 7.4.4 Versionen
V1 (260905): OK  

<a name="x75"></a>   

## 7.5 Zusammenbau des TUI-Blocks
1. Aufstecken des Steuerungsprints `RCC_TUI_STRG` auf die Anzeigeplatine `RCC_TUI_LED`.   
2. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
3. Aufstecken der Schalter-Kn&ouml;pfe.   
4. Falls vorhanden: Print `RW_LEER_LED` auf den Anzeigeprint stecken.   

<a name="x76"></a>   

## 7.6 Test des TUI-Blocks   


[Zum Seitenanfang](#up)   