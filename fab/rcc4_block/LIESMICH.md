<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 2.12.2024 <a name="up"></a><br>   
<h1>Herstellung von RCC Schaltbl&ouml;cken</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung
## 1.1 Übersicht
Auf dieser Seite wird - nach einigen allgemeinen Hinweisen zu Blöcken - das Bestücken folgender Blöcke beschrieben:   
* [Block Zweiwegweiche (W2)](#x20)   
* [Block Dreiwegweiche (W3)](#x30)   
* [Block Entkuppler (1OUT)](#x40)   
* [Block Abschaltbares Gleis (2IO)](#x50)   
* [Block Zweifachumschalter (DPDT)](#x60)   

## 1.2 Aufbau von Blöcken
Schaltblöcke bestehen immer aus einer Steuerungs-(STRG-) und einer Anzeige-(LED-)Platine, die zusammengesteckt werden. Die Steuerungsplatine hat dazu zwei 8-polige Stiftleisten (nach unten gerichtet), die Anzeigeplatine 8-polige Buchsenleisten mit langen Kontakten (nach oben).   
![Zusammenstecken der Blockhälften](/images/300_assemble_block_parts.png "Zusammenstecken der Blockhälften")   
_Bild 1: Zusammenstecken der Blockteile_   

## 1.3 Pinbelegung der Blöcke
Die Stecker für die Ein- und Ausgänge sind bei allen Schaltblöcken gleich:   
* J3: 6-poliger Flachbandstecker für die Stromversorgung (senkrecht)   
* J4: 10-poliger Flachbandstecker zur Verbindung mit dem I²C-IO-Expandern   
* J5: 6-poliger Flachbandstecker zur Ansteuerung der Eisenbahn-Komponenten (Weichen etc.)   
![pinlayout_connectors](/images/300_pin_STRG.png "pinlayout_connectors")   
_Bild 2: Pinbelegung der STRG-Stecker_   

Die Belegung des Steckers J5 ist abhängig vom Schaltblock:   
![Pinlayout_J5_all](/images/200_J5_pinlayout_all2.png "Pinlayout_J5_all")   
_Bild 3: Pinbelegung der STRG-Stecker_   

## 1.4 Vorbereitung von LEDs
Damit Fertigungstoleranzen leicht ausgeglichen werden können, werden die LEDs nicht direkt auf die erforderliche Länge geschnitten, sondern eine "Feder" eingebaut. Folgende Vorgangsweise wird empfohlen:   
1. Den Anoden- (Plus-)Anschlussdraht (längerer Draht) mit rotem Permanentstift markieren.   
2. Die Anschlussdrähte der LEDs auf 25 mm Länge abschneiden.   
3. Jeden Anschluss mit 19 bis 20 mm Schrumpfschlauch (Durchmesser 1 mm) isolieren.   
4. Nach folgender Zeichung biegen:   
![LED biegen](/images/200_LED_config.png "LED biegen")   
_Bild 4: Anpassen der LEDs für die Montage_   
Zum Biegen kann man auch eine Schablone aus Karton vorbereiten, wobei man die LED am Rand des Kartons anlegt und den Anschlussdraht nach Schema biegt:   
![LED biegen2](/images/200_LED_config2.png "LED biegen2")   
_Bild 5: LED-Biegeschablone_   


## 1.5 Löten von Tastern/Schaltern auf die Lötseite einer Platine
Alle "LED"-Platinen enthalten Taster und Schalter, die zum Schluss auf die Lötseite der Platine gelötet werden. Damit sie beim Einlöten nicht herausfallen, kann man sie mit Klebeband fixieren und die Platine höher lagern. Zum Beispiel kann man sie auf die Kanten eines schmalen Einsatzes eines [RAACO Sortimentkoffers Assorter 55 A9](https://www.reichelt.de/at/de/sortimentseinsatz-a9-1-39-x-47-x-55-mm-raaco-a9-1-p29322.html?r=1) legen.

![solder_button1](/images/200_solder_button1.png "solder_button1") ![solder_button2](/images/200_solder_button2.png "solder_button2")   
_Bild 6: Löten von Tastern_   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Zweiwegweiche

## 2.1 Steuerung Zweiwegweiche   
Diese Platine dient zum Schalten einer Zweiwegweiche (Richtung Gerade - Abzweig) von Hand oder über den I²C-Bus. Der Schaltvorgang erfolgt über Relais.   

![Platine Ansteuerung Zweiwegweiche](/images/pcb_f/PCB_F_RW_5V_W2_STRG_V2.png "Platine Ansteuerung Zweiwegweiche")   
_Bild 7: Platine zur Ansteuerung einer Zweiwegweiche_   

![RW_5V_W2_STRG](/images/300_RW_5V_W2_STRG_V2.png "RW_5V_W2_STRG")   
_Bild 8: Bestückte Platine "RW_5V_W2_STRG" zum Schalten einer Weiche_   

![RW_5V_W2_STRG_circuit](/images/600_RW_5V_W2_STRG_circuit.png "RW_5V_W2_STRG_circuit")   
_Bild 9: Schaltplan der "RW_5V_W2_STRG"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
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
   

### Bestückung   
1. Diode D1 und D3   
2. Relais K1, K3   
3. Restliche Dioden D6 bis D15   
4. Transistoren Q1, Q2   
5. Widerstände R8,R9   
6. Widerstände R2,R4   
7. Widerstände R1,R3   
8. Kondensator C1   
9. Wannenstecker J1 bis J3   
10. Stiftleisten J1 und J2 NACH UNTEN anlöten!   

### Versionen
* V1 (241103): OK   
* V2 (241115): OK   

## 2.2 Zweiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Bedienen einer Zweiwegweiche (Richtung Gerade - Abzweig) und zur Anzeige der tatsächlichen Weichenstellung.   

![RW_5V_W2_LED](/images/pcb_f/PCB_F_RW_5V_W2_LED_V1.png "RW_5V_W2_LED")   
_Bild 10: Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W2_LED_F](/images/300_RW_W2_LED_F.png "RW_5V_W2_LED_F")   
_Bild 11: Bauteilseite der bestückten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W2_LED_B](/images/300_RW_W2_LED_B.png "RW_5V_W2_LED_B")   
_Bild 12: Lötseite der bestückten Platine "RW_5V_W2_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W2_LED_circuit](/images/600_RW_5V_W2_LED_circuit.png "RW_5V_W2_LED_circuit")   
_Bild 13: Schaltplan der "RW_5V_W2_LED"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D2 oder D5        | LED grün 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D1 oder D3 oder D4 oder D6 (1) | LED gelb   | LED_THT:LED_D3.0mm |   
|    6   | D1,D2,D3,D4,D5,D6 (1) | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" für LEDs |   
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

(1) Es ist sinnvoll, die 2-poligen Buchsenleisten an alle 6 LED-Positionen zu löten, auch wenn im Betrieb  nur zwei LEDs eingesetzt werden. Weiters ist das Einlöten aller Bauteile so einfacher ;)   

(2) Nur den Taster einlöten, der benötigt wird:   
    * Für oben: Taster SW1 mit LED D1 oder D4   
    * Für unten: Taster SW3 mit LED D3 oder D6   
   

### Bestückung   
1. Die zweipoligen Buchsenleisten (D1 bis D6) mit gedrehten Pins auf die _Lötseite_ des Prints löten.   

Auf die _*Bauteilseite*_ löten:   

2. Transistoren Q1 bis Q4   
3. Alle Widerstände   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   
5. Stiftleisten 2x2 Pins J3, J4   

Auf die _*Lötseite*_ löten:   

6. Taster SW1 bis SW3   
   
### Test   
1. Einstecken der LEDs, Anode = Pluspol = rot markiert immer nach außen zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_W2_LED_ auf die Steuerungsplatine _RW_5V_W2_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_W2_STRG_.   
4. Anschluss der Zweiwegweiche an Pin 1, Pin 3 und Pin 5 von J5 der Steuerungplatine _RW_5V_W2_STRG_ (siehe Bild 12 unten).   
5. Betätigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", LED 2 oder LED 5 leuchtet.   
6. Betätigen des Tasters SW1 oder SW3: Stellen der Weiche auf "Abzweig", die andere LED leuchtet.   
   
![Pinbelegung_W2-J5](/images/200_J5_pins_W2.png "Pinbelegung W2-J5")   
_Bild 14: Pinbelegung des Steckers J5 von RW_5V_W2_STRG_   

### Versionen
* V1 (241104): OK

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Dreiwegweiche

## 3.1 Steuerung Dreiwegweiche   
Diese Platine dient zum Schalten einer Dreiwegweiche (Richtung links - Mitte - rechts) von Hand oder über den I²C-Bus. Der Schaltvorgang erfolgt über Relais.   

![Platine Ansteuerung Dreiwegweiche](/images/pcb_f/PCB_F_RW_5V_W3_STRG_V3.png "Platine Ansteuerung Dreiwegweiche")   
_Bild 15: Platine zur Ansteuerung einer Dreiwegweiche_   

![RW_5V_W3_STRG](/images/300_RW_5V_W3_STRG_V3.png "RW_5V_W3_STRG")   
_Bild 16: Bestückte Platine "RW_5V_W3_STRG" zum Schalten der Weichen_   

![RW_5V_W3_STRG_circuit](/images/600_RW_5V_W3_STRG_circuit.png "RW_5V_W3_STRG_circuit")   
_Bild 17: Schaltplan der "RW_5V_W3_STRG"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
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
   

### Bestückung   
1. Relais K1 bis K4   
2. Dioden D1 bis D15   
3. Transistoren Q1, Q2, Q3   
4. Widerstände R7,R8,R9   
5. Widerstände R2,R4,R6   
6. Widerstände R1,R3,R5   
7. Kondensator C1   
8. Wannenstecker J1 bis J3   
9. Stiftleisten J1 und J2 NACH UNTEN anlöten!   

### Versionen
* V1 (240930): Keine Aufnahmebohrungen, Leiterbahn (Netz) WL+ mit V+ verbunden, Widerstände R2, R4 und R6 haben 15k&Omega; (neu 10 k&Omega;).   
* V2 (241011): Bezeichnung GND (wird durch 0V ersetzt), Haltebohrungen alt, Lage der Wannenstecker J1 bis J3 falsch, kein 100 nF-Kondensator für die Versorgungsspannung, keine Schutzschaltung (R7, R8, R9, D13, D14, D15), falls beim Microcontroller die Versorgungsspannung ausfällt.   
* V3 (241021): OK

## 3.2 Dreiwegweiche: LED-Anzeige mit Taster
Diese Platine dient zum Bedienen einer Dreiwegweiche (Richtung links - Mitte - rechts) und zur Anzeige der tatsächlichen Weichenstellung.   

![RW_5V_W3_LED](/images/pcb_f/PCB_F_RW_5V_W3_LED_V3.png "RW_5V_W3_LED")   
_Bild 18: Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W3_LED_V3](/images/300_RW_5V_W3_LED.png "RW_5V_W3_LED")   
_Bild 19: Bestückte Platine "RW_5V_W3_LED" zum Schalten und zur Anzeige der Weichenstellung_   

![RW_5V_W3_LED_circuit](/images/600_RW_5V_W3_LED_V4_circuit.png "RW_5V_W3_LED_circuit")   
_Bild 20: Schaltplan der "RW_5V_W3_LED"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
|--------|-------------------|---------------------|--------------------|   
|    3   | D1,D2,D3 (1)      | LED grün 2 mA       | LED_THT:LED_D3.0mm |   
|    6   | D1,D2,D3 (D4,D5,D6) | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" für LEDs |   
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
   
(1) Es ist sinnvoll, die 2-poligen Buchsenleisten an alle 6 LED-Positionen zu löten, auch wenn im Betrieb  nur drei LEDs eingesetzt werden, je nachdem, ob die Anzeige links oder rechts von den Schaltern sein soll.   
   
### Bestückung   
1. Die zweipoligen Buchsenleisten (D1 bis D3 und/oder D4 bis D6) mit gedrehten Pins auf die _Lötseite_ des Prints löten.   

Auf die _*Bauteilseite*_ löten:   

2. Transistoren Q1 bis Q6   
3. Alle Widerstände   
4. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   
5. Stiftleisten 2x2 Pins J3, J4   

Auf die _*Lötseite*_ löten:   

6. Taster SW1 bis SW3   
   
### Test   
1. Einstecken der LEDs, Anode = Pluspol = rot markiert immer nach außen zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_W3_LED_ auf die Steuerungsplatine _RW_5V_W3_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_W3_STRG_.   
4. Anschluss der beiden Weichenantriebe der Dreiwegweiche an Pin 1-3-5 bzw. Pin 2-4-6 von J5 der Steuerungplatine _RW_5V_W3_STRG_ (siehe Bild 19 unten).   
5. Betätigen des Tasters SW2 (Print-Mitte): Stellen der Weiche auf "Gerade", die mittlere LED links (oder rechts leuchtet.   
6. Betätigen des Tasters SW1 (oben): Stellen der Weiche auf "links", die LED rechts oben (oder links unten) leuchtet.   
7. Betätigen des Tasters SW3 (unten): Stellen der Weiche auf "rechts", die LED rechts unten (oder links oben) leuchtet.   

![Pinbelegung_W3-J5](/images/200_J5_pins_W3.png "Pinbelegung W3-J5")   
_Bild 21: Pinbelegung des Steckers J5 von RW_5V_W3_STRG_   

### Versionen
* V1 (240930): Keine Aufnahmebohrungen, VCCi2c auf J2-Pin 1 herausgeführt, Keine Jumper zum Tauschen der Funktion von SW1 mit SW3.   
* V2 (241011): Bezeichnung GND (wird durch 0V ersetzt), Haltebohrungen neu    
* V3 (241018): Bestückungsdruck: Widerstandswerte bei R5, R6 vertauscht, Versionsnummer V2 statt V3   
* V4 (2411..): OK   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Entkuppler

## 4.1 Steuerung Entkuppler   
Diese Platine dient zum Schalten der Versorgungsspannung für den Entkuppler von Hand oder über den I²C-Bus. Der Schaltvorgang erfolgt über ein Relais.   

![RW_5V_1OUT_STRG](/images/pcb_f/PCB_F_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG_V1")   
_Bild 22: Platine "RW_5V_1OUT_STRG" zum Betätigen eines Entkupplers_   

![RW_5V_1OUT_STRG](/images/300_RW_5V_1OUT_STRG_V1.png "RW_5V_1OUT_STRG")   
_Bild 23: Bestückte Platine "RW_5V_1OUT_STRG" zum Betätigen eines Entkupplers_   

![RW_5V_1OUT_STRG_circuit](/images/600_RW_5V_1OUT_STRG_circuit.png "RW_5V_1OUT_STRG_circuit")   
_Bild 24: Schaltplan der "RW_5V_1OUT_STRG"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
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
   

### Bestückung   
1. IC-Fassung   
2. Relais K1   
3. Dioden D2 bis D5   
4. Transistor Q1   
5. Kondensator C1   
6. Kondensator C2   
7. Diode D1   
8. Alle Widerstände   
9. Wannenstecker J1 bis J3   

Auf die _*Lötseite*_ löten:   
10. Stiftleisten J1 und J2 NACH UNTEN anlöten!   

### Versionen
* V1 (240930): OK

## 4.2 LED-Anzeige mit Taster zur Entkuppler-Bedienung
Diese Platine dient zur Bedienung der Schaltplatine "RW_5V_1OUT_STRG".   
Im Ruhezustand leuchtet die rote LED (D1).   
Drückt man den Taster, so leuchten die gelbe (D5) und grüne LED (D3) und J6-Pin 1 (S0) geht auf 0V.   

![RW_5V_1OUT_LED](/images//pcb_f/PCB_F_RW_5V_1OUT_LED_V2.png "RW_5V_1OUT_LED")   
_Bild 25: Platine "RW_5V_1OUT_LED" zum Schalten und zur Anzeige des gedrückten Tasters_   

Das folgende Bild zeigt die bestückte Platine "RW_5V_1OUT_LED". Auf der Unterseite sieht man Teile der gelben und roten LED sowie des gelben Knopfes des Tasters.   
![pcb RW_5V_1OUT_LED](/images/300_RW_5V_1OUT_LED.png "pcb RW_5V_1OUT_LED")   
_Bild 26: Die bestückte "RW_5V_1OUT_LED"-Platine_   

![RW_5V_1OUT_LED_circuit](/images/600_RW_5V_1OUT_LED_circuit.png "RW_5V_W3_1OUT_circuit")   
_Bild 27: Schaltplan der "RW_5V_1OUT_LED"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED grün 2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D5                | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D1,D3,D5          | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" für LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-4  | _kh_library:TO-92_Inline_Wide_custom |   
|    2   | R2,R7             | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    3   | R1,R3,<br>R5      | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical <br> _kh_library:R_Axial_P1.778mm_Vertical_kh |   
|    1   | R4                | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | R6                | 100 k&Omega;        | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | SW2               | Taster SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
   

### Bestückung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D2, D4, D6) auf die _Lötseite_ des Prints löten.   

Auf die _*Bauteilseite*_ löten:   

2. Widerstand R5 (liegend)   
3. Transistor Q1   
4. Alle anderen Widerstände   
5. Buchsenleisten J1 und J2   

Auf die _*Lötseite*_ löten:   

6. Taster SW2   
   

### Test   
1. Einstecken der LEDs, Anode = Pluspol = rot markiert immer nach außen zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_1OUT_LED_ auf die Steuerungsplatine _RW_5V_1OUT_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_1OUT_STRG_.   
4. Anschluss des Entkupplers an Pin 3 und Pin 5 von J5 der Steuerungplatine _RW_5V_1OUT_STRG_.   
5. Betätigen des Tasters: der Entkuppler sollte arbeiten.   

![Pinbelegung_1OUT-J5](/images/200_J5_pins_1OUT.png "Pinbelegung 1OUT-J5")   
_Bild 28: Pinbelegung des Steckers J5 von RW_5V_1OUT_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241102): OK   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Abschaltbares Gleis

## 5.1 Steuerung der Fahrstrom-Abschaltung   
Diese Platine dient zum Ein- und Ausschalten des Fahrstroms für ein Gleis von Hand oder über den I²C-Bus. Der Schaltvorgang erfolgt über ein Relais.   

![Platine Fahrstrom-Abschaltung](/images/pcb_f/PCB_F_RW_5V_2IO_STRG_V1.png "Platine Fahrstrom-Abschaltung")   
_Bild 29: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_STRG](/images/300_RW_5V_2IO_STRG_V1.png "RW_5V_2IO_STRG")   
_Bild 30: Bestückte Platine "300_RW_5V_2IO_STRG" zum Schalten des Fahrstroms_   

![RW_5V_2IO_STRG_circuit](/images/600_RW_5V_2IO_STRG_circuit.png "RW_5V_2IO_STRG_circuit")   
_Bild 31: Schaltplan der "RW_5V_2IO_STRG"-Platine_   

__Stückliste__   
| Anzahl | Referenz     | Wert                   | Gehäuse            |   
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
   

### Bestückung   
1. IC-Fassung 4-polig (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2 bis D4   
4. Transistor Q1   
5. Kondensator C1   
6. Kondensator C2   
7. Diode D1   
8. Alle Widerstände   
9. Wannenstecker J1 bis J3   

Auf die _*Lötseite*_ löten:   
10. Stiftleisten J1 und J2 NACH UNTEN anlöten!   

_Nicht vergessen_: Optokoppler U1 in die Fassung stecken...   

### Versionen
* V1 (240930): OK

## 5.2 LED-Anzeige mit zwei Schaltern
Diese Platine dient zur Bedienung der Schaltplatine "RW_5V_2IO_STRG".   
Im Ruhezustand (beide _*Schalter*_ nicht gedrückt) leuchtet die gelbe LED und entweder die rote oder grüne LED, je nachdem, ob der Fahrstrom über DCC oder MQTT aus- oder eingeschaltet ist.   
Wird der Schalter "AUS" betätigt, ist der Fahrstrom auf jeden Fall ausgeschaltet, bei "EIN" (ohne "AUS") ist der Fahrstrom eingeschaltet. Sind beide Schalter nicht betätigt, erfolgt die Steuerung über den I²C-Bus.   

![Platine 2-poliges Schalten](/images/pcb_f/PCB_F_RW_5V_2IO_LED_V2.png "Platine 2-poliges Schalten")   
_Bild 32: Platine zum Schalten des Fahrstroms_   

![RW_5V_2IO_LED](/images/300_RW_5V_2IO_LED.png "RW_5V_2IO_LED")   
_Bild 33: Bestückte Platine "RW_5V_2IO_LED"_   

![RW_5V_2IO_LED_circuit](/images/600_RW_5V_2IO_LED_circuit.png "RW_5V_2IO_LED_circuit")   
_Bild 34: Schaltplan der "RW_5V_2IO_LED"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
|--------|-------------------|---------------------|--------------------|   
|    1   | D1                | LED rot  2 mA       | LED_THT:LED_D3.0mm |   
|    1   | D3                | LED grün 2 mA       | LED_THT:LED_D3.0mm |   
|    3   | D4,D5,D6          | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    5   | D1,D3,D4,D5,D6    | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" für LEDs  |   
|    2   | J1,J2             | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | Q1                | Transistor BC337-4  | _kh_library:TO-92_Inline_Wide_custom |   
|    1   | R8                | 47 &Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    5   | R1,R3,R4,R5,R6    | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    1   | R2                | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    1   | R7                | 100 k&Omega;        | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | SW1,SW2           | _*Schalter*_ SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
   
### Vorbereitung   
1. Von einer langen, einreihigen Buchsenleiste 4x 2-polige Stücke abtrennen (für D1 bis D6).   
2. Die LED-Anschlüsse entsprechend Bild xx abschneiden und biegen.   

### Bestückung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D4, D5, D6) auf die _Lötseite_ des Prints löten.   

Auf die _*Bauteilseite*_ löten:   

2. Widerstand R8 (liegend)   
3. Transistor Q1   
4. Die restlichen Widerstände   
5. Buchsenleisten J1 und J2   

Auf die _*Lötseite*_ löten:   

6. __SCHALTER__ SW1, SW2   
   
### Test   
1. Einstecken der LEDs, Anode = Pluspol = rot markiert immer nach außen zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_2IO_LED_ auf die Steuerungsplatine _RW_5V_2IO_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_2IO_STRG_.   
4. Anschluss der Gleisversorgung an J5-Pin 1 (DCC+) und J5-Pin 2 (DCC-) der Steuerungplatine _RW_5V_2IO_STRG_.   
5. Anschluss des zu schaltenden Gleises an J5-Pin 5 (DCCout+) und J5-Pin 6 (DCCout-).
6. Funktionstest: wie oben beschrieben.   

![Pinbelegung_2IO-J5](/images/200_J5_pins_2IO.png "Pinbelegung 2IO-J5")   
_Bild 35: Pinbelegung des Steckers J5 von RW_5V_2IO_STRG_   

### Versionen
* V1 (241022): spiegelverkehrte Anordnung der LEDs.   
* V2 (241103): OK   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. Zweipoliger Umschalter

## 5.1 Steuerung des zweipoligen Umschalters   
Diese Platine dient zum zweipoligen Umschalten 2x Um (engl. Double Pole Double Throw, kurz DPDT) einer Spannung. Der Schaltvorgang erfolgt über ein Relais.   

![Platine DPDT](/images/pcb_f/PCB_F_RW_5V_DPDT_STRG_V1.png "Platine DPDT")   
_Bild 36: Platine zum zweipoligen Umschalten einer Spannung_   

![RW_5V_DPDT_STRG](/images/300_RW_5V_DPDT_STRG_V1.png "RW_5V_DPDT_STRG")   
_Bild 37: Bestückte Platine "300_RW_5V_DPDT_STRG" zum zweipoligen Umschalten_   

![RW_5V_DPDT_STRG_circuit](/images/600_RW_5V_DPDT_STRG_circuit.png "RW_5V_DPDT_STRG_circuit")   
_Bild 38: Schaltplan der "RW_5V_DPDT_STRG"-Platine_   

__Stückliste__   
| Anzahl | Referenz     | Wert                   | Gehäuse            |   
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
   

### Bestückung   
1. IC-Fassungen 4-polig U1, U2 (oder 2x Buchsenleiste mit 2 Pins)   
2. Relais K1   
3. Dioden D2, D3, D4, D6   
4. Transistor Q1   
5. Kondensator C1, C3   
6. Kondensator C2   
7. Diode D1, D5   
8. Alle Widerstände   
9. Wannenstecker J1 bis J3   

Auf die _*Lötseite*_ löten:   
10. Stiftleisten J1 und J2 NACH UNTEN anlöten!   

_Nicht vergessen_: Optokoppler U1, U2 in die Fassung stecken...   

### Versionen
* V1 (241124): OK

## 5.2 LED-Anzeige für zweipoligen Umschalter
Diese Platine dient zur Bedienung der Schaltplatine "RW_5V_DPDT_STRG".   
Im Ruhezustand (beide _*Schalter*_ nicht gedrückt) leuchtet die mittlere gelbe LED und entweder die rote oder grüne LED, je nachdem, ob der Umschalter über DCC oder MQTT aus- oder eingeschaltet ist (Remote-Betrieb).   
Wird der mittlere Schalter gedrückt, erfolgt die Umschaltung über den unteren, lokalen Schalter. Im nicht gedrückten Zustand dind die Kontakte "IN" und "NC" (Normally Closed) verbunden, gedrückt sind "IN" und "NO" (Normally Open).   

![Platine 2-poliges Umschalten](/images/pcb_f/PCB_F_RW_5V_DPDT_LED_V1.png "Platine 2-poliges Umschalten")   
_Bild 39: Bedien-Platine zum 2-poligen Umschalten_   

![RW_5V_DPDT_LED](/images/300_RW_5V_DPDT_LED.png "RW_5V_DPDT_LED")   
_Bild 40: Bestückte Platine "RW_5V_DPDT_LED"_   

![RW_5V_DPDT_LED_circuit](/images/600_RW_5V_DPDT_LED_circuit.png "RW_5V_DPDT_LED_circuit")   
_Bild 41: Schaltplan der "RW_5V_DPDT_LED"-Platine_   

### Stückliste   
| Anzahl | Referenz          | Wert                | Gehäuse            |   
|--------|-------------------|---------------------|--------------------|   
|    2   | D1, D3            | LED grün 2 mA       | LED_THT:LED_D3.0mm |   
|    2   | D5, D6            | LED gelb 2 mA       | LED_THT:LED_D3.0mm |   
|    4   | D1, D3, D5, D6    | Buchsenleiste 2-polig mit gedrehten Pins | "Fassung" für LEDs  |   
|    2   | J1, J2            | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    3   | R2, R4, R5        | 1 k&Omega;          | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R1, R3            | 10 k&Omega;         | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
|    2   | SW1,SW2           | _*Schalter*_ SW_Push_DPDT_8x8 | _kh_library:SW_Push_DPDT_8x8 |   
   
### Vorbereitung   
1. Von einer langen, einreihigen Buchsenleiste 4x 2-polige Stücke abtrennen (für D1, D3, D5, D6).   
2. Die LED-Anschlüsse entsprechend Bild xx abschneiden und biegen.   

### Bestückung   
1. Die zweipoligen Buchsenleisten mit gedrehten Pins (D1, D3, D5, D6) auf die _Lötseite_ des Prints löten.   

Auf die _*Bauteilseite*_ löten:   

2. Widerstand R2, R4 (liegend)   
3. Die restlichen Widerstände R1, R3, R5   
4. Buchsenleisten J1 und J2   

Auf die _*Lötseite*_ löten:   

6. __SCHALTER__ SW1, SW2   
   
### Test   
1. Einstecken der LEDs, Anode = Pluspol = rot markiert immer nach außen zum Leiterplattenrand.   
2. Aufsetzen des Prints _RW_5V_DPDT_LED_ auf die Steuerungsplatine _RW_5V_DPDT_STRG_.   
3. Anschluss der 6-poligen Stromversorgung an J3 der Steuerungsplatine _RW_5V_DPDT_STRG_.   
4. Anschluss der Eingangsspannung IN+ an J5-Pin 1 und IN- J5-Pin 2 der Steuerungplatine _RW_5V_DPDT_STRG_:   
An J3-Pin3 liegt IN+ und an J3-Pin4 liegt IN- an.   
J3-Pin5 und J3-Pin6 offen.   
5. Drücken des mittleren Schalters (für lokales Schalten):   
Unterer Schalter nicht gedrückt: An J3-Pin3 liegt IN+ und an J3-Pin4 liegt IN- an, J3-Pin5 und J3-Pin6 offen.   
Unterer Schalter gedrückt: An J3-Pin5 liegt IN+ und an J3-Pin6 liegt IN- an. J3-Pin3 und J4-Pin6 offen.   
6. Mittlerer Schalter ungedrückt: Steuerung über DCC.   
Mit dem Demoprogamm kann mit der DCC-Adresse 41 der Umschalter betätigt werden.   

![Pinbelegung_DPDT-J5](/images/200_J5_pins_DPDT.png "Pinbelegung DPDT-J5")   
_Bild 42: Pinbelegung des Steckers J5 von RW_5V_DPDT_STRG_   

### Versionen
* V1 (241124): OK   

[Zum Seitenanfang](#up)   