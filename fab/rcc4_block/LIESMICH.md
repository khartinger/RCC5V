<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 23.2.2025 <a name="up"></a><br>   
<h1>Herstellung von RCC Schaltbl&ouml;cken</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung
## 1.1 &Uuml;bersicht
Auf dieser Seite wird - nach einigen allgemeinen Hinweisen zu Bl&ouml;cken - das Herstellen folgender Bl&ouml;cke beschrieben:   
* [Block Zweiwegweiche (W2)](#x20)   
* [Block Dreiwegweiche (W3)](#x30)   
* [Block Entkuppler (1OUT)](#x40)   
* [Block Abschaltbares Gleis (2IO)](#x50)   
* [Block Zweifachumschalter (DPDT)](#x60)   

## 1.2 Aufbau von Bl&ouml;cken
Schaltbl&ouml;cke bestehen immer aus zwei Platinen: einer Steuerungs-(STRG-) und einer Anzeige-(LED-)Platine. Diese Platinen werden zusammengesteckt. Die Steuerungsplatine hat dazu zwei 8-polige Stiftleisten (nach unten gerichtet), die Anzeigeplatine 8-polige Buchsenleisten mit langen Kontakten (nach oben).   
![Zusammenstecken der Blockh&auml;lften](/images/300_assemble_block_parts.png "Zusammenstecken der Blockh&auml;lften")   
_Bild 1: Zusammenstecken der Blockteile "Steuerung" (links) und "Anzeige" (rechts)_   

## 1.3 Pinbelegung der Bl&ouml;cke
Die Stecker f&uuml;r die Ein- und Ausg&auml;nge sind bei allen Schaltbl&ouml;cken gleich angeordnet:   
* J3: 6-poliger Flachbandstecker f&uuml;r die Stromversorgung (senkrecht)   
* J4: 10-poliger Flachbandstecker zur Verbindung mit dem I²C-IO-Expandern   
* J5: 6-poliger Flachbandstecker zur Ansteuerung der Eisenbahn-Komponenten (Weichen etc.)   
![pinlayout_connectors](/images/300_pin_STRG.png "pinlayout_connectors")   
_Bild 2: Pinbelegung der STRG-Stecker_   

Die Belegung des Steckers J5 ist abh&auml;ngig vom Schaltblock:   
![Pinlayout_J5_all](/images/200_J5_pinlayout_all2.png "Pinlayout_J5_all")   
_Bild 3: Pinbelegung der STRG-Stecker_   

<a name="x14"></a>   

## 1.4 Vorbereitung von LEDs
Die Anzeige des Zustandes jedes Blockes erfolgt durch LEDs. Damit Fertigungstoleranzen leicht ausgeglichen werden k&ouml;nnen, werden die LEDs nicht direkt auf die erforderliche L&auml;nge geschnitten, sondern eine Art "Feder" eingebaut. Dazu wird folgende Vorgangsweise empfohlen:   
1. Den Anoden- (Plus-) Anschlussdraht (l&auml;ngerer Draht) mit rotem Permanentstift markieren.   
2. Jeden Anschluss mit 19 bis 20 mm Schrumpfschlauch (Durchmesser 1 mm) isolieren.   
3. Die Anschlussdr&auml;hte der LEDs auf 25 mm L&auml;nge abschneiden.   
4. Nach folgender Zeichung biegen:   
![LED biegen](/images/200_LED_config.png "LED biegen")   
_Bild 4: Anpassen der LEDs f&uuml;r die Montage_   

Zum Biegen kann man auch eine Schablone aus Karton vorbereiten, wobei man die LED am Rand des Kartons anlegt und den Anschlussdraht nach Schema biegt:   
![LED biegen2](/images/200_LED_config2.png "LED biegen2")   
_Bild 5: LED-Biegeschablone_   

Das Bild zeigt die verschiedenen Stadien beim Vorbereiten der LEDs:   
![LED_biegen_Schritte](/images/300_LED_biegen_Schritte.png "LED_biegen_Schritte")   
_Bild 6: Die Arbeitsschritte beim Biegen der LEDs_   

<a name="x15"></a>   

## 1.5 Anordnung von LEDs und Tastern auf der LED-Platine
Das Basis-Layout der LED-Platinen ist für alle Bl&ouml;cke gleich. Es sind drei Positionen f&uuml;r Taster bzw. Schalter sowie sechs Positionen f&uuml;r LEDs vorgesehen:   
![LED- und Schalterpositionen](/images/300_block_cover.png "LED- und Schalterpositionen")   
_Bild 7: LED- und Schalterpositionen bei einem Block (von vorne gesehen)_   

Die Bezeichnungen f&uuml;r die LEDs (D1 bis D6) und die Taster oder Schalter (SW1 bis SW3) werden bei allen LED-Platinen gleich verwendet.   

<a name="x16"></a>   

## 1.6 L&ouml;ten von Tastern und Schaltern auf die L&ouml;tseite einer Platine
Alle "LED"-Platinen enthalten Taster und Schalter, die im letzten Arbeitsschritt auf die L&ouml;tseite der Platine gel&ouml;tet werden. Damit sie beim Einl&ouml;ten nicht herausfallen, kann man sie mit Klebeband fixieren und die Platine h&ouml;her lagern. Zum Beispiel kann man sie auf die Kanten eines schmalen Einsatzes eines [RAACO Sortimentkoffers Assorter 55 A9](https://www.reichelt.de/at/de/sortimentseinsatz-a9-1-39-x-47-x-55-mm-raaco-a9-1-p29322.html?r=1) legen.

![solder_button1](/images/200_solder_button1.png "solder_button1") ![solder_button2](/images/200_solder_button2.png "solder_button2")   
_Bild 8: L&ouml;ten von Tastern_   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Zweiwegweiche

## 2.1 Steuerung Zweiwegweiche   
Diese Platine dient zum Schalten einer Zweiwegweiche (Richtung "Gerade" oder "Abzweig") von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt durch zwei Relais (siehe Bild unten).   

![RW_5V_W2_STRG_circuit](/images/600_RW_5V_W2_STRG_circuit.png "RW_5V_W2_STRG_circuit")   
_Bild 9: Schaltplan der "RW_5V_W2_STRG"-Platine_   

Die Ansteuerung erfolgt entweder &uuml;ber die Leitungen WSA und WSB (d.h. von extern) oder mit PBA und PBB (Taster auf der W2_LED-Platine).   
* (1) PBA und PBB offen: Beide Relais sind im Ruhezustand. Die Weichenanschl&uuml;sse WA und WB sind nach WLA und WLB durchgeschaltet. Diese Leitungen f&uuml;hren zur LED-Anzeige und zeigen so den Schaltzustand der Weiche an.   
* (2) PBA auf 0V, PBB offen: Transistor Q1 schaltet durch, beide Relais ziehen an. Der Weichenanschluss WB erh&auml;lt die Schaltspannung V+ (WA bleibt offen).   
* (3) PBA offen, PBB auf 0V: Transistor Q2 schaltet durch, nur Relais K3 zieht an. Der Weichenanschluss WA erh&auml;lt die Schaltspannung V+ (WB bleibt offen).   
* (4) PBA auf 0V, PBB auf 0V: Dieser Zustand sollte nicht auftreten. Es schalten beide Transistoren durch und die Schaltung verh&auml;lt sich wie bei (2).   

![Platine Ansteuerung Zweiwegweiche](/images/pcb_f/PCB_F_RW_5V_W2_STRG_V2.png "Platine Ansteuerung Zweiwegweiche")   
_Bild 10: Platine zur Ansteuerung einer Zweiwegweiche_   

![RW_5V_W2_STRG](/images/300_RW_5V_W2_STRG_V2.png "RW_5V_W2_STRG")   
_Bild 11: Best&uuml;ckte Platine "RW_5V_W2_STRG" zum Schalten einer Weiche_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | C1                | 100 nF              | _kh_library:C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
|    8   | D1,D3,<br>D6,D7,D11,D12,D14,D15 | Diode 1N4148 | _kh_library:D_DO-35_SOD27_P5.08mm_Vertical_AnodeUp_kh <br>_kh_library:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp_kh |   
|    2   | J1,J2             | Stiftleiste 8-polig (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    2   | J3,J5             | Wannenstecker 6-polig, stehend  | _kh_library:Box_02x03_P2.54mm_Vertical |   
|    1   | J4                | Wannenstecker 10-polig, stehend | _kh_library:Box_02x05_P2.54mm_Vertical |   
|    2   | K1,K3             | Relais IM03TS (HFD4/3) | _kh_library:Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
|    2   | Q1,Q2             | Transistor BC327  | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R8,R9             | 4,7 k&Omega;      | _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    2   | R2,R4             | 10 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R1,R3             | 100 k&Omega;      | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
   

![RW_5V_W2_STRG_parts](/images/300_RW_5V_W2_STRG_parts.png "RW_5V_W2_STRG_parts")   
_Bild 12: Bauteile der "RW_5V_W2_STRG"-Platine_   

### Best&uuml;ckung   
1. Diode D1 und D3   
2. Relais K1, K3   
3. Restliche Dioden D6 bis D15   
4. Transistoren Q1, Q2   
5. Widerst&auml;nde R8, R9   
6. Widerst&auml;nde R2, R4   
7. Widerst&auml;nde R1, R3   
8. Kondensator C1   
9. Wannenstecker J1 bis J3   
10. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

### Versionen
* V1 (241103): OK   
* V2 (241115): OK   

## 2.2 Zweiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Bedienen einer Zweiwegweiche (je ein Taster f&uuml;r die Richtungswahl "Gerade" oder "Abzweig") und zur Anzeige der tats&auml;chlichen Weichenstellung. Es sind alle Taster- und LED-Positionen verdrahtet, sodass man durch die richtige Wahl von zwei Tastern und zwei LEDs alle Schaltbilder    
* linke Weiche nach links oben,   
* linke Weiche nach rechts unten,   
* rechte Weiche nach links unten und   
* rechte Weiche nach rechs oben   
darstellen kann.   

![RW_5V_W2_LED_circuit](/images/600_RW_5V_W2_LED_circuit.png "RW_5V_W2_LED_circuit")   
_Bild 11: Schaltplan der "RW_5V_W2_LED"-Platine_   

![RW_5V_W2_LED](/images/pcb_f/PCB_F_RW_5V_W2_LED_V1.png "RW_5V_W2_LED")   
_Bild 12: Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W2_LED_F](/images/300_RW_W2_LED_F.png "RW_5V_W2_LED_F")   
_Bild 13: Bauteilseite der best&uuml;ckten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

Im folgenden Bild ist der Print f&uuml;r eine linke Weiche best&uuml;ckt, die bei der Fahrt von links nach rechts entweder "Gerade" (gr&uuml;ne LED leuchtet) oder "Abzweig" befahren werden kann (gelbe LED leuchtet).   
![RW_5V_W2_LED_B](/images/300_RW_W2_LED_B.png "RW_5V_W2_LED_B")   
_Bild 14: L&ouml;tseite der best&uuml;ckten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung._   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D2 oder D5        | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D1 oder D3 oder D4 oder D6 (1) | LED gelb 2 mA  | LED_THT:LED_D3.0mm |   
|    6   | D1,D2,D3,D4,D5,D6 (1) | Buchsenleiste 2-polig mit gedrehten Kontakten (Pins) | "Fassung" f&uuml;r LEDs |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh     |   
|    4   | Q1,Q2,Q3,Q4       | Transistor BC337-40 | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R6, <br> R12           | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | R1,<br> R7    | 100 &Omega; (47 &Omega;) | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh <br> _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
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

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten (D1 bis D6) mit gedrehten Pins auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Transistoren Q1 bis Q4   
3. Alle Widerst&auml;nde   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   
5. Stiftleisten 2x2 Pins J3, J4   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

6. Taster SW1 bis SW3   
   
### Test   
1. Einstecken der LEDs. Die rot markierte Anode ist der Pluspol und wird immer nach au&szlig;en zum Leiterplattenrand hin in die Fassung gesteckt.   
2. Aufsetzen des Prints _RW_5V_W2_LED_ auf die Steuerungsplatine _RW_5V_W2_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_W2_STRG_.   
4. Anschluss der Zweiwegweiche an Pin 1, Pin 3 und Pin 5 von J5 der Steuerungplatine _RW_5V_W2_STRG_ (siehe Bild 15 unten).   
5. Bet&auml;tigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", LED 2 oder LED 5 leuchtet.   
6. Bet&auml;tigen des Tasters SW1 oder SW3: Stellen der Weiche auf "Abzweig", die andere LED leuchtet.   
   
![Pinbelegung_W2-J5](/images/200_J5_pins_W2.png "Pinbelegung W2-J5")   
_Bild 15: Pinbelegung des Steckers J5 von RW_5V_W2_STRG_   

### Versionen
* V1 (241104): OK

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Dreiwegweiche

## 3.1 Steuerung Dreiwegweiche   
Diese Platine dient zum Schalten einer Dreiwegweiche (Richtung links - Mitte - rechts) von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber Relais.   

![RW_5V_W3_STRG_circuit](/images/600_RW_5V_W3_STRG_circuit.png "RW_5V_W3_STRG_circuit")   
_Bild 16: Schaltplan der "RW_5V_W3_STRG"-Platine_   

![Platine Ansteuerung Dreiwegweiche](/images/pcb_f/PCB_F_RW_5V_W3_STRG_V3.png "Platine Ansteuerung Dreiwegweiche")   
_Bild 17: Platine zur Ansteuerung einer Dreiwegweiche_   

![RW_5V_W3_STRG](/images/300_RW_5V_W3_STRG_V3.png "RW_5V_W3_STRG")   
_Bild 18: Best&uuml;ckte Platine "RW_5V_W3_STRG" zum Schalten der Weichen_   

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

## 3.2 Dreiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Bedienen einer Dreiwegweiche (Richtung links - Mitte - rechts) und zur Anzeige der tats&auml;chlichen Weichenstellung.   

![RW_5V_W3_LED_circuit](/images/600_RW_5V_W3_LED_V4_circuit.png "RW_5V_W3_LED_circuit")   
_Bild 19: Schaltplan der "RW_5V_W3_LED"-Platine_   

![RW_5V_W3_LED](/images/pcb_f/PCB_F_RW_5V_W3_LED_V3.png "RW_5V_W3_LED")   
_Bild 20: Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W3_LED_V3](/images/300_RW_5V_W3_LED.png "RW_5V_W3_LED")   
_Bild 21: Best&uuml;ckte Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    3   | D1,D2,D3 (1)      | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
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
(1) Es ist sinnvoll, die 2-poligen Buchsenleisten an alle 6 LED-Positionen zu l&ouml;ten, auch wenn im Betrieb  nur drei LEDs eingesetzt werden, je nachdem, ob die Anzeige links oder rechts von den Schaltern sein soll.   
   
## Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 6x 2-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D6).   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   
3. 10 mm-Tasterkn&ouml;pfe SW1, SW3 (gelb), SW2 (gr&uuml;n) eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten (D1 bis D3 und/oder D4 bis D6) mit gedrehten Pins auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Transistoren Q1 bis Q6   
3. Alle Widerst&auml;nde   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   
5. Stiftleisten 2x2 Pins J3, J4   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   

6. Taster SW1 bis SW3   
   
### Test   
1. Einstecken der LEDs, rot markierte Anode = Pluspol zeigt immer nach au&szlig;en zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_W3_LED_ auf die Steuerungsplatine _RW_5V_W3_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_W3_STRG_.   
4. Anschluss der beiden Weichenantriebe der Dreiwegweiche an Pin 1-3-5 bzw. Pin 2-4-6 von J5 der Steuerungplatine _RW_5V_W3_STRG_ (siehe Bild 22 unten).   
5. Bet&auml;tigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", die mittlere LED links (oder rechts) leuchtet.   
6. Bet&auml;tigen des Tasters SW1 (oben): Stellen der Weiche auf "links", die LED rechts oben (oder links unten) leuchtet.   
7. Bet&auml;tigen des Tasters SW3 (unten): Stellen der Weiche auf "rechts", die LED rechts unten (oder links oben) leuchtet.   

![Pinbelegung_W3-J5](/images/200_J5_pins_W3.png "Pinbelegung W3-J5")   
_Bild 22: Pinbelegung des Steckers J5 von RW_5V_W3_STRG_   

### Versionen
* V1 (240930): Keine Aufnahmebohrungen, VCCi2c auf J2-Pin 1 herausgef&uuml;hrt, Keine Jumper zum Tauschen der Funktion von SW1 mit SW3.   
* V2 (241011): Bezeichnung GND (wird durch 0V ersetzt), Haltebohrungen neu    
* V3 (241018): Best&uuml;ckungsdruck: Widerstandswerte bei R5, R6 vertauscht, Versionsnummer V2 statt V3   
* V4 (241124): OK   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Entkuppler (1OUT)   

## 4.1 Steuerung des Entkupplers   
Diese Platine dient zum Schalten der Versorgungsspannung f&uuml;r den Entkuppler von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber einen Optokoppler.   

![RW_5V_1OUT_STRG_circuit](/images/600_RW_5V_1OUT_STRG_circuit.png "RW_5V_1OUT_STRG_circuit")   
_Bild 23: Schaltplan der "RW_5V_1OUT_STRG"-Platine_   

![RW_5V_1OUT_STRG](/images/pcb_f/PCB_F_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG_V1")   
_Bild 24: Platine "RW_5V_1OUT_STRG" zum Bet&auml;tigen eines Entkupplers_   

![RW_5V_1OUT_STRG](/images/300_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG")   
_Bild 25: Best&uuml;ckte Platine "RW_5V_1OUT_STRG" zum Bet&auml;tigen eines Entkupplers_   

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
_Bild 26: Bauteile der "RW_5V_1OUT_STRG"-Platine (ein 4k7-Widerstand fehlt)_   

### Best&uuml;ckung   
1. IC-Fassung U1 4-polig (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2 bis D5 (1N4148)   
4. Transistor Q1   
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

## 4.2 LED-Anzeige mit Taster zur Entkuppler-Bedienung
Diese Platine dient zur Bedienung der Schaltplatine "RW_5V_1OUT_STRG".   
Im Ruhezustand leuchtet die rote LED (D1).   
Dr&uuml;ckt man den Taster, so leuchten die gelbe (D5) und gr&uuml;ne LED (D3) und J6-Pin 1 (S0) geht auf 0V.   

![RW_5V_1OUT_LED_circuit](/images/600_RW_5V_1OUT_LED_circuit.png "RW_5V_W3_1OUT_circuit")   
_Bild 27: Schaltplan der "RW_5V_1OUT_LED"-Platine_   

![RW_5V_1OUT_LED](/images//pcb_f/PCB_F_RW_5V_1OUT_LED_V2.png "RW_5V_1OUT_LED")   
_Bild 28: Platine "RW_5V_1OUT_LED" zum Schalten und zur Anzeige des gedr&uuml;ckten Tasters_   

Das folgende Bild zeigt die best&uuml;ckte Platine "RW_5V_1OUT_LED". Auf der Unterseite sieht man Teile der gelben und roten LED sowie des gelben Knopfes des Tasters.   
![pcb RW_5V_1OUT_LED](/images/300_RW_5V_1OUT_LED.png "pcb RW_5V_1OUT_LED")   
_Bild 29: Die best&uuml;ckte "RW_5V_1OUT_LED"-Platine_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D5                | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D1,D3,D5          | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-4  | _kh_library:TO-92_Inline_Wide_custom |   
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
_Bild 30: Bauteile der "RW_5V_1OUT_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D5) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R5 (1 k&Omega; liegend)   
3. Transistor Q1   
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
_Bild 31: Verkabelung zum Testen des 1OUT-Blocks_   

Statt der beiden eingezeichneten Voltmeter kann nat&uuml;rlich auch nur eines verwendet werden.   

1. Anlegen der 5V-Spannung: Die obere, rote LED leuchtet.   
2. Den Remote-Set-Eingang S1 (Pin J4-1) mit 0V (Pin J4-5) verbinden: Das Relais schaltet, die rote LED erlischt, die gr&uuml;ne LED leuchtet.   
3. Den Taster bet&auml;tigen: Die gelbe LED und die gr&uuml;ne LED leuchten.   

* Das obere Voltmeter ("zum Entkuppler") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
* Das R&uuml;ckmeldesignal R1 (Voltmeter "R&uuml;ckmeldung") zeigt immer 5 V an, wenn die gr&uuml;ne LED leuchtet.   
Das bedeutet: Kein Ausgangssignal ergibt die R&uuml;ckmeldung R1 = 0 V.   

__Im Fehlerfall__, falls die Versorgungs-(Wechsel-)spannung V+ ausf&auml;llt, leuchtet zwar die rote LED, aber beim Dr&uuml;cken des Tasters leuchten die gelbe und die rote LED. Die gr&uuml;ne LED leuchtet nicht, d.h., es gibt keine Spannung am Ausgang.   

### Test unter realen Bedingungen
1. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_1OUT_STRG_.   
2. Anschluss des Entkupplers an J5-Pin 3 (OUT-) und J5-Pin 5 (OUT+).
3. Bet&auml;tigen des Tasters: der Entkuppler sollte arbeiten.   

![Pinbelegung_1OUT-J5](/images/200_J5_pins_1OUT.png "Pinbelegung 1OUT-J5")   
_Bild 32: Pinbelegung des Steckers J5 von RW_5V_1OUT_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241102): OK   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Abschaltbares Gleis (2IO)   

## 5.1 Steuerung der Fahrstrom-Abschaltung   
Diese Platine dient zum Ein- und Ausschalten des Fahrstroms f&uuml;r ein Gleis von Hand oder &uuml;ber den I²C-Bus. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber einen Optokoppler.   

![RW_5V_2IO_STRG_circuit](/images/600_RW_5V_2IO_STRG_circuit.png "RW_5V_2IO_STRG_circuit")   
_Bild 33: Schaltplan der "RW_5V_2IO_STRG"-Platine_   

![Platine Fahrstrom-Abschaltung](/images/pcb_f/PCB_F_RW_5V_2IO_STRG_V1.png "Platine Fahrstrom-Abschaltung")   
_Bild 34: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_STRG](/images/300_RW_5V_2IO_STRG_V1.png "RW_5V_2IO_STRG")   
_Bild 35: Best&uuml;ckte Platine "300_RW_5V_2IO_STRG" zum Schalten des Fahrstroms_   

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
_Bild 36: Bauteile der "RW_5V_2IO_STRG"-Platine_   

### Best&uuml;ckung   
1. IC-Fassung 4-polig (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2 bis D4 (1N4148)   
4. Transistor Q1   
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
Diese Platine dient zum Bedienen der Schaltplatine "RW_5V_2IO_STRG".   
Im Ruhezustand (beide _*Schalter*_ nicht gedr&uuml;ckt) leuchtet die gelbe LED und entweder die rote oder gr&uuml;ne LED, je nachdem, ob der Fahrstrom &uuml;ber DCC oder MQTT aus- oder eingeschaltet ist.   
Wird der Schalter "AUS" bet&auml;tigt, ist der Fahrstrom auf jeden Fall ausgeschaltet, bei "EIN" (ohne "AUS") ist der Fahrstrom eingeschaltet. Sind beide Schalter nicht bet&auml;tigt, erfolgt die Steuerung &uuml;ber den I²C-Bus.   

![RW_5V_2IO_LED_circuit](/images/600_RW_5V_2IO_LED_circuit.png "RW_5V_2IO_LED_circuit")   
_Bild 37: Schaltplan der "RW_5V_2IO_LED"-Platine_   

![Platine 2-poliges Schalten](/images/pcb_f/PCB_F_RW_5V_2IO_LED_V2.png "Platine 2-poliges Schalten")   
_Bild 38: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_LED](/images/300_RW_5V_2IO_LED.png "RW_5V_2IO_LED")   
_Bild 39: Best&uuml;ckte Platine "RW_5V_2IO_LED"_   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED gr&uuml;n 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D4,D5,D6          | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    5   | D1,D3,D4,D5,D6    | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-4  | _kh_library:TO-92_Inline_Wide_custom |   
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
_Bild 40: Bauteile der "RW_5V_2IO_LED"-Platine_   

### Best&uuml;ckung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D4, D5, D6) auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   

2. Widerstand R8 (liegend)   
3. Transistor Q1   
4. Die Widerst&auml;nde R2 (10 k&Omega;) und R7 (100 k&Omega;)   
5. Die restlichen Widerst&auml;nde (1 k&Omega;)   
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
_Bild 41: Verkabelung zum Testen des 2IO-Blocks_   

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
_Bild 42: Pinbelegung des Steckers J5 von RW_5V_2IO_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241103): OK   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. Zweipoliger Umschalter (DPDT)   

## 6.1 Steuerung des zweipoligen Umschalters   
Diese Platine dient zum zweipoligen Umschalten 2x Um (engl. Double Pole Double Throw, kurz DPDT) einer Spannung. Der Schaltvorgang erfolgt &uuml;ber ein Relais, die R&uuml;ckmeldung erfolgt &uuml;ber zwei Optokoppler (je einer f&uuml;r den Zustand NC = normally closed und NO = normally open).   

![RW_5V_DPDT_STRG_circuit](/images/600_RW_5V_DPDT_STRG_circuit.png "RW_5V_DPDT_STRG_circuit")   
_Bild 43: Schaltplan der "RW_5V_DPDT_STRG"-Platine_   

![Platine DPDT](/images/pcb_f/PCB_F_RW_5V_DPDT_STRG_V1.png "Platine DPDT")   
_Bild 44: Platine zum zweipoligen Umschalten einer Spannung_   

![RW_5V_DPDT_STRG](/images/300_RW_5V_DPDT_STRG_V1.png "RW_5V_DPDT_STRG")   
_Bild 45: Best&uuml;ckte Platine "300_RW_5V_DPDT_STRG" zum zweipoligen Umschalten_   

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
4. Transistor Q1   
5. Kondensator C1, C3   
6. Kondensator C2   
7. Diode D1, D5   
8. Alle Widerst&auml;nde   
9. Wannenstecker J3 bis J5   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
10. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

_Nicht vergessen_: Optokoppler U1, U2 richtig herum in die Fassung stecken...   

### Versionen
* V1 (241124): OK

## 6.2 LED-Anzeige f&uuml;r zweipoligen Umschalter
Diese Platine dient zum Ansteuern und Anzeigen der Zust&auml;nde der Schaltplatine "RW_5V_DPDT_STRG". Sie enth&auml;lt   
* in der Mitte der Platine einen Schalter zum Umschalten zwischen Fernsteuerung (&uuml;ber DCC oder MQTT) und lokalem Betrieb (Schalter nicht gedr&uuml;ckt)   
* unten Mitte einen Schalter zum Schalten des Relais bei lokalem Betrieb   
* eine gelbe LED links Mitte zur Anzeige eines Remote-Betriebs (LED leuchtet)   
* eine gelbe LED links unten zur Anzeige eines lokalen Betriebs (LED leuchtet)   
* eine gr&uuml;ne LED links oben zur Anzeige einer Ausgangsspannung an den Pins NC (normally closed) J5-Pin 3 f&uuml;r Vout+ und J5-Pin 4 f&uuml;r Vout-
* eine gr&uuml;ne LED links unten zur Anzeige einer Ausgangsspannung an den Pins NO (normally open) J5-Pin 5 f&uuml;r Vout+ und J5-Pin 6 f&uuml;r Vout-

![RW_5V_DPDT_LED](/images/300_DPDT_LED_front.png "RW_5V_DPDT_LED") ![RW_5V_DPDT_LED](/images/300_DPDT_LED_back.png "RW_5V_DPDT_LED")     
_Bild 46: Best&uuml;ckte Platine "RW_5V_DPDT_LED" (front und back)_   

![RW_5V_DPDT_LED_circuit](/images/600_RW_5V_DPDT_LED_circuit.png "RW_5V_DPDT_LED_circuit")   
_Bild 47: Schaltplan der "RW_5V_DPDT_LED"-Platine_   

![Platine 2-poliges Umschalten](/images/pcb_f/PCB_F_RW_5V_DPDT_LED_V1.png "Platine 2-poliges Umschalten")   
_Bild 48: Bedien-Platine zum 2-poligen Umschalten_   

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
_Bild 49: Pinbelegung des Steckers J5 von RW_5V_DPDT_STRG_   

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