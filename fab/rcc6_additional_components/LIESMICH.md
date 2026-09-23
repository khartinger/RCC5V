<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Weitere RCC Komponenten</h1><b><big>RCC6: Optionale Komponenten für das RCC-System</big></b><br>  
Stand: 16.9.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x01"></a>   

# Worum geht es?
Dieses Verzeichnis enthält optionale Komponenten für das RCC-System (RCC = Railway Component Control). Sie ergänzen das System, sind für die eigentliche Steuerung aber nicht notwendig.   

<a name="TableOfContents"></a>   
##  Inhalt
1. [RGY-Anzeige `RCC_RGY_TVn_LED`](#x10)  
2. [Pulsflanken-Erkennung Typ 1](#x20)  
3. [Set-/Reset-Pulsflanken-Erkennung (Typ 2)](#x30)  
4. [DCC-Fahrstromerkennung **ohne** Schalten](#x40)   
5. [UI-Steuerungsplatine `RW_5V_UI_STRG`](#x50)   
---
6. [Ältere Platinen mit Gleisspannungssignal TRV = 5 V](#xold)   

<a name="x10"></a>   
<a name="x11"></a>   

# 1. RGY-Anzeige

## 1.1 Einleitung

Das Board `RCC_RGY_TVn_LED` ist eine **41 × 41 mm²** große Anzeigeplatine passend zu RCC-Blöcken.  
Sie enthält bis zu **drei parallel geschaltete rot/grün-Duo-LEDs** und optional zwei Taster.  

![rcc6_RGY_TVn_LED_Front](/images/300_rcc6_RGY_TVn_LED_assembledFront.png "rcc6_RGY_TVn_LED_Front")   

Die LEDs zeigen den Zustand der Eingangssignale **TVn** und **FREn** an.  

| TVn | FREn |   LED-Farbe   | LED | ROKn | RFR |  
|:---:|:----:|:-------------:|:---:|:---:|:---:|  
| 0 V |  0 V | Grün          | 🟢 | 0 V | 5 V |  
| 0 V |  5 V | Gelb (Orange) | 🟡 | 0 V | 0 V |  
| 5 V |  0 V | Rot           | 🔴 | 5 V | 0 V |  
| 5 V |  5 V | Rot           | 🔴 | 5 V | 0 V |  

### Bedeutung der Eingänge

- **TVn** – Gleisspannung vorhanden (*Track Voltage*, 0 V)  
- **FREn** – Gleis frei (*Track Free*, 0 V)  

Damit zeigt die Platine den Zustand eines Gleises an:  

- 🟢 **Grün:** Gleis ist frei.
- 🟡 **Gelb:** Gleis ist besetzt.
- 🔴 **Rot:** Es liegt ein Fehler vor (kein Fahrstrom etc.).

### Rückmeldesignale

Zusätzlich zur LED-Anzeige stehen zwei Rückmeldesignale zur Verfügung:  

- **ROKn** – Rückmeldung ist gültig (*Response OK* = *Response Valid*, 0 V)  
- **RFRE** – Gleis ist frei (*Response Track Free*, 5 V)  

**Anmerkung**: Das Ausgangssignal RFRE wird gegenüber FREn invertiert.   

![rcc6_RGY_TVn_LED_blockdiagram](/images/150_rcc6_RGY_TVn_LED_blockdiagram.png "rcc6_RGY_TVn_LED_blockdiagram")   

### Optionale Taster

An den Positionen **SW1** und **SW3** können optional Taster oder Schalter eingebaut werden. Diese können von einer Steuerplatine ausgewertet werden, zum Beispiel zum Testen der **SET-** und **RESET-Eingänge** einer [Pulsspeicher-Steuerungsplatine `RCC_PULS2_STRG`](#x30).

<a name="x12"></a>   

## 1.2 Schaltplan
Die RGY-Anzeige besteht aus drei Teilen:   
1. Die LED-Anzeige   
2. die Rückmeldeschaltung   
3. Zwei Taster für Testzwecke   

### Led-Anzeige
![rcc6_RGY_LED_circuit](/images/300_rcc6_RGY_LED_circuit_V2.png "rcc6_RGY_LED_circuit")   

Die Ansteuerung der Platine erfolgt über die Signale **TVn** (J1-Pin 7) und **FREn** (J1-Pin 8):   
- TVn = 5 V: Led leuchtet rot.  
  (Transistor T4 sperrt, T1 leitet → "LED rot"; T5 sperrt, T2 sperrt)  
- TVn = 5 V und FREn = 5 V: LED leuchtet gelb.  
  (T4 leitet, T3 sperrt, T1 Leitet → "LED rot"; T5 leitet, T2 leitet → "LED grün" → = rot + grün = gelb).  
- TVn = 5 V und FREn = 0 V: LED leuchtet grün.  
   (T4 leitet, T3 leitet, T1 sperrt; T5 leitet, T2 leitet → "LED grün")  

__Anmerkungen__
* Widerstand R1: 680 Ω bei drei Duo-LEDs, 1 kΩ bei einer Duo-LED   
* Widerstand R3: 3,9 kΩ bei drei Duo-LEDs, 10 kΩ bei einer Duo-LED   

### Rückmeldeschaltung
![rcc6_RGY_LED_feedback_circuit](/images/300_rcc6_RGY_LED_feedback_circuit_V2.png "rcc6_RGY_LED_feedback_circuit")   

#### OK-Rückmeldung (ROKn)

Das interne Signal **ROKi** wird für den externen Ausgang (**ROKn**) etwas aufbereitet.   

- Die Diode **D4** verhindert, dass die Duo-LED belastet wird, wenn der Transistor **T5** gesperrt ist. Gleichzeitig zieht **R10** den Ausgang **ROKn** auf **5 V**.   
- Schaltet **T5** durch, begrenzt **R9** einen möglichen Fehlerstrom von außen.   

#### Gleisfrei-Rückmeldung (RFR)

Das interne Signal **RFRi** wird mit dem Transistor **T6** invertiert und als **RFRE** ausgegeben.   

### Optionale Taster oder Schalter

Auf der Platine können an den Positionen **SW1** und **SW3** optional Taster oder Schalter eingebaut werden.  

Im Ruhezustand sind die Ausgänge **offen**.  
Beim Betätigen werden sie mit **0 V (Masse)** verbunden.  

### Gesamtschaltplan

KiCad-Schaltplan der Platine **`RCC_RGY_TVn_LED`**:   
![RCC_RGY_TVn_LED_circuit](/images/600_RCC_RGY_TVn_LED_circuit_V2.png "RCC_RGY_TVn_LED_circuit")  

Die Stromversorgung und alle Ein- und Ausgangssignale befinden sich an der Stiftleiste J1.  

<a name="x13"></a>   

## 1.3 Bestückung der Platine
Bild der Platine "`RCC_RGY_TVn_LED`" (Version 1):   
![Platine RW_5V_RGY_LED](/images/pcb_f/PCB_F_RCC_RGY_TVn_LED_V2.png "Platine RW_5V_RGY_LED")   

Best&uuml;ckte Platine "`RCC_RGY_TVn_LED`"   
![Bestückte Platine RW_5V_RGY_LED](/images/300_RCC_RGY_TVn_LED_assembled.png "Bestückte Platine RW_5V_RGY_LED")   

### St&uuml;ckliste   

| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 1 | C1 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 3 | D1, D2, D3 | Dual-LED rot-gr&uuml;n, gemeinsame Kathode | LED_D5.0mm-3 |   
| 3 | D1, D2, D3 | Buchsenleiste 3-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs |   
| 1 | D4 | Diode BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 2 | J1, J2 | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_11mm_kh |   
| 4 | Q1, Q6 | Transistor BC337-40 (npn) | TO-92_Inline_Wide_custom |   
| 2 | Q2, Q3, Q4, Q5 | Transistor BC327-40 (pnp) | TO-92_Inline_Wide_custom |   
| 1 | R1 | 680 &Omega;..1 k&Omega; (2) | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R11 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R3 | 3,9 k&Omega;..10 k&Omega; (3) | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R13 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R9 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 4 | R6, R8, R10, R12 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R7 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 2 | R2, R5 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 3 | R4, R14, R15 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | SW1, SW3 | Taster SW_Push_DPDT_8x8 | SW_Push_DPDT_8x8 |   
| 2 | SW1, SW3 | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe je nach Anwendung |    

### Anmerkungen
(1) Es ist sinnvoll, die 3-poligen Buchsenleisten an alle 3 LED-Positionen zu l&ouml;ten, auch wenn im Betrieb weniger LEDs eingesetzt werden.  
(2) Widerstand R1: **680 &Omega;** bei drei Duo-LEDs, 1 k&Omega; bei einer Duo-LED   
(3) Widerstand R3: **3,9 k&Omega;** bei drei Duo-LEDs, 10 k&Omega; bei einer Duo-LED   
   
### Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 3x 3-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D3).   
2. Die äußeren LED-Anschl&uuml;sse farblich kennzeichnen:  
   * kurzen Anschluss grün färben, mittellangen Anschluss rot  
3. Schrumpfschlauch 11 mm auf jeden LED-Anschluss aufschrumpfen  
4. LED-Anschl&uuml;sse auf 17 bis 18 mm abschneiden und Ecken biegen ("Feder", mittleren Anschluss nach vorne oder hinten). Länge dann ca. 13 mm.   
![RW_5V_DUOLED1](/images/300_RW_5V_DUOLED1.png "RW_5V_DUOLED1") 
![RW_5V_DUOLED2](/images/300_RW_5V_DUOLED2.png "RW_5V_DUOLED2")   

4. NUR wenn Taster verwendet werden: 10 mm-Tasterkn&ouml;pfe SW1, SW2 eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

Bauteile der Platine "RW_5V_RGY_LED"   
![RW_5V_RGY_LED_parts](/images/300_RW_5V_RGY_LED_parts.png "RW_5V_RGY_STRG_parts")   

### Best&uuml;ckung   
**Lötseite** (!):  

1. Die dreipoligen Buchsenleisten (D1 bis D3) mit gedrehten Pins auf die **L&ouml;tseite** des Prints l&ouml;ten.   

Auf die **Bauteilseite** l&ouml;ten:   

2. Widerstände R1, R11 und R13 (liegend, **680 &Omega;** ... 1 k&Omega;, 100 k&Omega;, 47 &Omega;)   
3. Transistoren Q1, Q6 (BC337-40)   
4. Transistoren Q2, Q3, Q4, Q5 (BC327-40)   
5. Kondensator C1 (1 &micro;F)   
6. Diode D4 (BAT48, auf Polung achten: Kathode unten beim Kreis)   
7. Widerstand R3 (**3,9 k&Omega;** ... 10 k&Omega;)   
8. Widerstand R9 (47 &Omega;)
9. Widerst&auml;nde R6, R7, R8, R10, R12 (4,7 k&Omega;, stehend)   
10. Widerst&auml;nde R2, R5 (10 k&Omega;, stehend)   
11. Widerst&auml;nde R4, R14, R15 (100 k&Omega;, stehend)   
12. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   

Optional: Auf die **L&ouml;tseite** l&ouml;ten:   

13. Taster SW1, SW3   

### Print vervollständigen
Duo-LED(s) einstecken (auf Polung achten).   

<a name="x14"></a>   

## 1.4 Test
### Vorbereitung
* 5x Kabel Stecker-Buchse (schwarz, rot, gelb, grün, violett)   
* Steckbrett zum Verteilen der 0V und 5V
* Netzgerät 5 V   
* Voltmeter (Bereich 20VDC)   

### Durchführung
Print auf die Bauteilseite legen. Alle erforderlichen Anschlüsse befinden sich an den langen Kontakten der der Buchsenleiste J1:   

![rcc6_RGY_LED_J1](/images/200_rcc6_RGY_LED_J1.png "rcc6_RGY_LED_J1")   

1. Versorgungsspannung am Steckbrett anschließen.

2. Versorgungsspannung am Board anlegen: Pin 1 mit 5V, Pin 2 mit GND verbinden:   
   ► 🔴🔴🔴 Die LEDs leuchten rot.   

3. Voltmeter an GND anschließen. Messen:  
   ► Pin 5 = ROKn = +5V  
   ► Pin 6 = RFR = 0V   

4. Pin 7 = TVn mit 0 V verbinden (active low):   
   ► 🟡🟡🟡 Die LEDs leuchten gelb (orange).   

5. Messen:  
   ► Pin 5 = ROKn = 0,9V  
   ► Pin 6 = RFRE = 0,1V  

6. Pin 8 = FREn mit 0V verbinden:   
   ► 🟢🟢🟢 Die LEDs leuchten grün.   

7. Messen:  
   ► Pin 5 = ROKn = 0,9V  
   ► Pin 6 = RFRE = 3,8V  

<a name="x15"></a>   

## 1.5 Hinweise zur Montage
Duo-LEDs mit drei Anschlüssen passen nicht in Standard-LED-Fassungen.  
Die Montage des `RCC_RGY_TVn_LED`-Boards erfolgt daher mit dem Board `RW_LEER_DUOLED`. Bei diesem sind die Bohrungen für LED2 und LED5 vergrößert.   
Steht kein `RW_LEER_DUOLED`-Board zur Verfügung, kann man auch das `RW_LEER_LED`-Board verwenden und die Bohrungen LED2 und LED5 auf 8 mm aufbohren (gleich groß wie die Bohrungen für die Taster).

![Befestigungsplatine DUOLED](/images/300_RW_LEER_DUOLED.png "Befestigungsplatine DUOLED") ![Befestigungsplatine DUOLED auf RGY_LED](/images/300_RW_LEER_DUOLED_RGY_LED.png "Befestigungsplatine DUOLED  auf RGY_LED")   


## 1.6 Versionen
* V1 (260820): OK  
* V2 (260823): OK  

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Puls-Erkennung Typ 1

## 2.1 Prinzip

Die Puls-Erkennung Typ 1 (kurz "PULS1") reagiert auf eine fallende Flanke am Eingang und erzeugt einen Puls vorgegebener Länge. Die Pulslänge ist mit einem Potenziometer zwischen Millisekunden und Sekunden einstellbar. Es sind zwei voneinander unabhängige Kanäle verfügbar.  
Bleibt ein Impulseingang länger auf 0, so bleibt auch das Ausgangssignal auf 0.  

<a name="x22"></a>   

## 2.2 Steuerung Puls-Erkennung Typ 1 (`RCC_PULS1_STRG`)

### Schaltplan
![Schaltplan RCC_PULS1_STRG](/images/600_RCC_PULS1_STRG_circuit.png "Schaltplan RCC_PULS1_STRG")  

### St&uuml;ckliste   
| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 2 | C1, C2 | 100 nF, 5,08 mm | C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
| 2 | C3, C4 | Tantal-Elko 10 &micro;F, 16 V, 2,54 mm| ELKO_L4.32mm_D3.81mm_P2.54mm_kh |   
| 3 | D1, D2, D3 | BAT48 | D_DO-35_P2.0mm_Vertical_AnodeUp_kh |   
| 7 | D4, D5, D6, D7, D8, D9, D10 | BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp_kh |   
| 2 | J1, J2 | Stiftleiste 8-polig (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_kh |   
| 2 | J3, J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | J4 | Wannenstecker 10-polig, stehend | Box_02x05_P2.54mm_Vertical_kh |   
| 2 | Q1, Q2 | npn-Transistor BC337 | TO-92_Inline_Wide_custom |   
| 2 | R7, R8 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R3 | 4,7 k&Omega;| R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 1 | R4 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 2 | R1, R5 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | R2, R6 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | RV1, RV2 | Trimmer 500 k&Omega; stehend | Trim_RM-063_Horizontal_kh |   
| 1 | U1 | CD4538  Dual Precision Monostable Multivibrator (Monoflop), retriggerbar |  |   
| 1 | U1 | IC-Fassung 16-polig, gedrehte Pins | DIP-16_W7.62mm_kh |   

### Bestückung
1. IC-Fassung U1 (auf Polung = Kerbe achten)  
2. Dioden D1 bis D10 (stehend, auf Polung achten: Kathode im weißen Kreis!)  
3. Transistoren Q1, Q2 (BC337)  
4 Tantal-Elko C3, C4 (auf Polung achten!)  
5 Trimmer RV1, RV2  
6. Alle Widerstände R1 bis R8  
7. Kondensatoren C1, C2 (100 nF)  
8. Wannenstecker J3 bis J5 (auf Polung achten!)  

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
9. Stiftleisten J1 und J2 NACH UNTEN anl&ouml;ten!   

## Versionen
* V1 (260824): OK  

<a name="x23"></a>   

## 2.3 LED-Anzeige Puls-Erkennung Typ 1 (`RCC_PULS1_LED`)

### Schaltplan
![Schaltplan RCC_PULS1_LED](/images/600_RCC_PULS1_LED_circuit.png "Schaltplan RCC_PULS1_LED")  

### St&uuml;ckliste   
| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 1 | C1 | Kondensator 100 nF | C_L4mm_D3mm_P2.54mm_kh |   
| 2 | D1, D4 | LED gelb | LED_D3.0mm |   
| 2 | D2, D5 | LED grün | LED_D3.0mm |   
| 4 | D1, D2, D4, D5 | Buchsenleiste (gedrehte Buchsen), 2-polig (1) |   |   
| 2 | J1, J2 | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_11mm_kh |   
| 2 | Q1, Q2 | npn-Transistor BC337 | TO-92_Inline_Wide_custom |   
| 1 | R5 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R10 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 3 | R1, R6, R8 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P10,16mm_Horizontal |   
| 1 | R3 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R4, R9 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R2 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 1 | R7 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   

#### Vorbereitung   
1. 4x gedrehte, 2-polige Buchsen für die LEDs: Von einer (meist 40-poligen) Buchsenleiste herunterschneiden.   
2. Die LED-Anschl&uuml;sse entsprechend [Kapitel 1.4](#x14) abschneiden und biegen.   

### Bestückung
1. Die zweipoligen Buchsenleisten (D1, D2, D4, D5) mit gedrehten Pins auf die _L&ouml;tseite_ des Prints l&ouml;ten.   

Auf die _*Bauteilseite*_ l&ouml;ten:   
2. Widerstände R1, R6, R8 (1 k&Omega; liegend, 10 mm)  
3. Widerstand R7 (100 k&Omega; liegend, 7,6 mm)  
4. Transistoren Q1, Q2 (BC337)   
5. Kindensator C1 (100 nF, 2,54 mm Raster)  
6. Widerstände R5, R10 (47 &Omega;, stehend)  
7. Widerstand R3 (1 k&Omega;, stehend)  
8. Widerstände R4, R9 (10 k&Omega;, stehend)  
9. Widerstand R2 (100 k&Omega;, stehend)  
10. Buchsenleisten J1 und J2   

### Versionen
* V1 (260824): OK  

<a name="x24"></a>   

## 2.4 Zusammenbau des PULS1-Blocks
1. Aufstecken des Steuerungsboards `RCC_PULS1_STRG` auf das Anzeigeboard `RCC_PULS1_LED`.   
2. Einstecken der LEDs. F&uuml;r alle LEDs gilt: Anode = Pluspol = rot markiert immer __nach au&szlig;en__ zum Leiterplattenrand.   
3. Falls vorhanden: Print `RW_LEER_LED` auf das Anzeigeboard stecken.   

<a name="x25"></a>   

## 2.5 Test des PULS1-Blocks
### Pinbelegung der Stecker am STRG-Board
![Pinbelegung PULS1 Stecker J4 J5](/images/200_rcc6_puls1_J4_J5.png "Pinbelegung PULS1 Stecker J4 J5")  

### Vorbereitung
(1) Stecke ein 6-poliges Flachbandkabel am **6-poligen Stecker J5-Pin 1** an und stecke am anderen Kabelende einen Stift-Stift-Draht in **Pin 1** (Reedkontakt-Eingang 1).  
   Oder: Stecke DIREKT am **6-poligen Stecker J5-Pin 1** einen Buchsen-Buchsen-Draht an.  
(2) Lege an den PULS1-Block die Versorgungsspannung an (6-poliger Stecker J3)  
   ► die beiden grünen LEDs 🟢 leuchten

### Testdurchführung
#### Puls-Eingang 1
* Verbinde J5-Pin 1 kurz mit GND an J5-Pin 5:  
  ► die linke, gelbe LED 🟡 leuchtet kurz auf.  
  Die Leuchtdauer kann mit dem Trimmer RV1 eingestellt werden.  

Bleibt der Eingang länger auf 0, so bleibt auch das Ausgangssignal so lange auf 0.  

#### Puls-Eingang 2
* Verbinde J5-Pin 2 kurz mit GND an J5-Pin 5:  
  ► die rechte, gelbe LED 🟡 leuchtet kurz auf.  
  Die Leuchtdauer kann mit dem Trimmer RV2 eingestellt werden.  

Bleibt der Eingang länger auf 0, so bleibt auch das Ausgangssignal so lange auf 0.  

#### I²C-Rückmeldung
**Kanal 1**  
* Verbinde das Voltmeter mit J4-Pin 1 (V) und J4-Pin 5 (COM = GND = 0V):  
  ► Anzeige 5 V  
* Erzeuge einen Puls am Eingang 1, d.h. verbinde J5-Pin 1 kurz mit GND an J5-Pin 5:  
  ► Anzeige 0 V, solange der Puls dauert.  

Führe den Test auch für Kanal 2 durch.  

<a name="x30"></a>   
<a name="x31"></a>   

# 3. Set-/Reset-Pulsflanken-Erkennung (Typ 2)

## 3.1 Prinzip

Die Puls-Erkennung Typ 2 (kurz "PULS2") reagiert auf fallende Flanken am SET- und RESET-Eingang. Der letzte Zustand wird gespeichert und steht auch nach einem Stromausfall zur Verfügung.  

### Eingänge

SET- und RESET-Eingang können auf 3 Arten getriggert werden:  
* 6-poliger Stecker J5  
* Taster (zB auf Platine `RCC_RGY_TVn_LED`)  
* 10-poliger Stecker J4 (I²C-Anschluss)  

![RW_5V_PULS_STRG_IN](/images/300_RW_5V_PULS_STRG_IN.png "RW_5V_PULS_STRG_IN")   

### Ausgänge

Die Pulsspeicher-Steuerungsplatine `RCC_PULS_TVn_STRG` erzeugt  
* die Steuersignale `FRE` und `TVn` für die LED-Anzeige und   
* leitet die LED-Anzeige-Rückmeldung `ROK` und `RFRE` zum I²C-Stecker J4 weiter.   

Zur Anzeige wird das Board `RCC_RGY_TVn_LED` verwendet.   

<a name="x32"></a>   
<a name="x321"></a>   

## 3.2 Steuerung Puls-Erkennung Typ 2 (`RCC_PULS2_TVn_STRG`)

### 3.2.1 Schaltplan
Die Puls-Steuerung besteht aus 5 Stufen:   
* Eingänge  
* Impulserzeugung  
* Flipflop (HEF4093)  
* H-Brücken-Treiber (DRV8833)  
* Bistabiles Relais (IM41)  

KiCad-Schaltplan der Platine "RCC_PULS2_TVn_STRG" (Version 1):   

![RCC_PULS2_TVn_STRG_circuit](/images/600_RCC_PULS2_TVn_STRG_V1_circuit.png "RCC_PULS2_TVn_STRG_circuit")   

<a name="x322"></a>   

### 3.2.2 Bestückung der Platine
Bild der Platine `RCC_PULS2_TVn_STRG` (Version 1):   
![PULS2-Platine](/images/pcb_f/PCB_F_RCC_PULS2_TVn_STRG_V1.png "PULS2-Platine")   

Best&uuml;ckte Platine "RCC_PULS2_TVn_STRG_V1"   
![RCC_PULS2_TVn_STRG bestückt1](/images/300_RCC_PULS2_TVn_STRG_V1_assembled1.png "RCC_PULS2_TVn_STRG")  

#### St&uuml;ckliste   
| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 3 | C1, C2, C4 | 100 nF, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 2 | C3, C5 | 10 nF, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 1 | C6 | Elko 10 &micro;F, 16 V, Raster 2,54 mm | ELKO_L7.88mm_D4.57mm_P2.54mm_kh |   
| 3 | D1, D2, D4 | BAT48 | D_DO-35_P1.778mm_Vertical_AnodeUp_kh |   
| 2 | D3, D6 | BAT48 | D_DO-35_SOD27_P5.08mm_Horizontal_kh |   
| 3 | D5, D8, D9 | BAT48 | D_DO-35_P2.0mm_Vertical_AnodeUp_kh |   
| 1 | D7 | BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 2 | J1, J2 | Stiftleiste 8-polig (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_Back_kh |   
| 2 | J3, J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | J4 | Wannenstecker 10-polig, stehend | Box_02x05_P2.54mm_Vertical_kh |   
| 1 | J6 | DRV8833_Board [1] | DRV8833_Board |   
| 2 | J6 | Buchsenleiste 6 Pin [2] |   |   
| 1 | J7 | Stiftleiste 2-polig (Jumper_2) [3] | PinSocket_1x02_P2.54mm_Vertical_kh |   
| 1 | J7 | Jumper (2-polig) |   |   
| 1 | K1 | Relais IM41, 3 V, 2x UM, bistabil | Relay_DPDT_AXICOM_IMSeries_Pitch5.08mm_rect_Pins |   
| 2 | R21, R24 | 100 &Omega; | R_Axial_P1.778mm_Vertical_kh |   
| 2 | R28, R29 | 100 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 4 | R22, R23, R25, R26 | 100 k&Omega; | R_Axial_P1.778mm_Vertical_kh |   
| 1 | R27 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | U1 | 4-fach NAND mit Schmitt-Trigger HEF4093B | DIP-14_W7.62mm_Socket_kh |   
| 1 | U1 | Fassung DIL 14 (2x7 Pin), gedrehte Kontakte |   |   

Bauteile der Platine `RCC_PULS2_TVn_STRG`:   
![RCC_PULS2_TVn_STRG_parts](/images/300_RCC_PULS2_TVn_STRG_parts_V1.png "RCC_PULS2_TVn_STRG_parts")   

#### Vorbereitung
[1] 1. Auf dem DRV8833_Board J6 die Verbindung bei J1 **auftrennen**.   
&nbsp; &nbsp; &nbsp;2. 2x 6polige Stiftleisten zu den Bauteilen hin anlöten.   
[2] Von einer flachen, einreihigen Buchsenleiste 2x 6-polige St&uuml;cke abtrennen (f&uuml;r J6) oder   
    zB eine DIL 14 Fassung mit Federkontakten auseinanderschneiden und 2x 6-polige St&uuml;cke abtrennen (f&uuml;r J6).   
[3] Von einer langen, einreihigen Stiftleiste 1x 2-poliges St&uuml;ck abtrennen (f&uuml;r J7).   

#### Best&uuml;ckung   
![](/images/480_RCC_PULS2_TVn_STRG_Fsilk_V1.png)  
1. Widerstand R27 (100 k&Omega;, liegend)   
2. Diode D3, D6 (BAT48, liegend, Kathode beim weißen Strich)   
3. Elko C6 (10 &micro;F, liegend, auf Polung achten!)   
4. Fassung U1 (DIL 14, auf Polung/Kerbe achten!)   
5. Buchsenleisten J6 (2x 6 Pin)   
6. **Bistabiles** Relais K1 (IM41, 3V, auf Polung achten)   
7. Diode D1, D2, D4, D5, D7, D8, D9 (BAT48, stehend, Kathode in den Kreis)   
8. Kondensatoren C3, C5 (10 nF = 103, Raster 2,54 mm, stehend)   
9. Kondensatoren C1, C2, C4 (100 nF = 104, Raster 2,54 mm, stehend)   
10. Stiftleiste J7 (2-polig)   
11. Widerst&auml;nde R21, R24, R28, R29 (100 &Omega;, stehend)   
12. Widerst&auml;nde R22, R23, R25, R26 (100 k&Omega;, stehend)   
13. Wannenstecker J1 bis J3 (auf Polung achten - Pin 1)   
14. Kondensator C2 (100 nF = 104, Raster 2,54 mm, stehend)   
15. Stiftleisten J1 und J2 **NACH UNTEN** anl&ouml;ten!   

#### Print vervollständigen
* Jumper auf Stifte J7 aufstecken.   
* 4-fach NAND HEF4093B einstecken.   
* DRV8833_Board aufstecken.   

<a name="x323"></a>   

## 3.2.3 Versionen
* V1 (260727): OK.   

<a name="x33"></a>   

## 3.3 Inbetriebnahme und Test

#### Pinbelegung des 6-poligen Steckers J5:   
![RW_5V_PULS_STRG_J5](/images/150_RW_5V_PULS_STRG_J5.png "RW_5V_PULS_STRG_J5")   

#### Pinbelegung des 10-poligen Steckers J4:   
![RW_5V_PULS_STRG_J4](/images/150_RW_5V_PULS_STRG_J4.png "RW_5V_PULS_STRG_J4")   

Der Test der Platine `RCC_PULS2_TVn_STRG` erfolgt gemeinsam mit der Platine `RCC_RGY_TVn_LED`.   

<a name="x40"></a>   
<a name="x41"></a>   

# 4. DCC-Fahrstromerkennung ohne Schalten
## 4.1 Einleitung
Die DCC-Fahrstromerkennung **ohne Schalten** besteht aus drei Platinen:  
* UI-Erkennung `dcc_track_UI_TVn_V1`  
* Steuerungsplatine (Anschlussplatine) `RCC_UI_TVn_STRG_V1`  
* Anzeigeplatine `RCC_RGY_TVn_LED_V1`  

<a name="x42"></a>   
<a name="x421"></a>   

## 4.2 UI-Erkennung `dcc_track_UI_TVn_V1` (ohne Schalten)

### 4.2.1 Funktion

Die DCC-Gleis-UI-Erkennung überwacht ein Gleis. Sie erkennt, ob  
1. **Gleisspannung** anliegt und ob  
2. **Fahrstrom** fließt.

Der Status wird über  
- **LEDs angezeigt** und steht zusätzlich an 
- **zwei digitalen Ausgängen** zur Verfügung.   

So kann man erkennen, ob ein Gleis **besetzt** ist.   

Die Stromversorgung und die beiden digitalen Ausgänge sind über einen **6-poligen Stecker** angeschlossen.   
![UI_pin_J5](/images/200_rcc6_UI_pin_J5.png "UI_pin_J5")   

TVn ... Track Voltage ON (0V) = Fahrspannung ein (0V)   
FREn ... Track Free (0V) = Gleis frei (0V)   

Die technische Funktion ist weitgehend identisch mit `RCC_TUI_EXT` (bis auf das Schalten des Fahrstroms) und ist hier beschrieben:  
[https://github.com/khartinger/RCC5V/blob/main/fab/rcc4_block/LIESMICH.md](https://github.com/khartinger/RCC5V/blob/main/fab/rcc4_block/LIESMICH.md#x72)

<a name="x422"></a>   

### 4.2.2 Gesamtschaltung

KiCad-Schaltplan der "dcc_track_UI_TVn"-Platine:   

![dcc_track_UI_TVn_V1_circuit](/images/600_dcc_track_UI_TVn_V1_circuit.png "dcc_track_UI_TVn_V1_circuit")   

<a name="x423"></a>   

### 4.2.3 Bestücken der Platine
Bild der Platine zur DCC-Gleis-Spannungs-/Strom-Erkennung (Version 2):   
![Platine Gleis-UI-Erkennung](/images/pcb_f/PCB_F_dcc_track_UI_TVn_V1.png "Platine Gleis-UI-Erkennung")   

Best&uuml;ckte Platine "dcc_track_UI_TVn_V1"   
![Bestückte Platine dcc_track_UI_TVn](/images/300_dcc_track_UI_TVn_V1_assembled.png "Bestückte Platine dcc_track_UI_TVn")   

#### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
| 5 | C1, C2, C4, C7, C8 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 2 | C3, C5 | Tantal-Elko 10 &micro;F, 16 V, Raster 2,54 mm | C_L4.32mm_D3.81mm_P2.54mm_kh |   
| 1 | C6 | Elko 33 &micro;F, 35 V, Raster 2,54 mm | CP_Radial_D8.0mm_P2.50mm |   
| 2 | D1, D2 | Diode SB240 | D_DO-15_P3.81mm_Vertical_AnodeUp |   
| 1 | D3 | Diode BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 1 | D5 | Diode 1N4007 | D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
| 1 | D4 | LED rot, 3 mm, 2 mA | LED_D3.0mm |   
| 1 | D6 | LED gr&uuml;n, 3 mm, 2 mA | LED_D3.0mm |   
| 2 | D4, D6 | gedrehte Buchsen, 2-polig |   |   
| 2 | J1, J2 | Schraubklemme, 2-polig, schwarz, 5 mm | Screw_Terminal_01x02_P5 |   
| 1 | J3 | Stiftleiste 2-polig | PinSocket_1x02_P2.54mm_Vertical_kh |   
| 1 | J3 | Jumper 2-polig |    |   
| 1 | J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | Q1 | npn-Transistor BC337-40 | TO-92_Inline_Wide_custom |   
| 1 | Q2 | pnp-Transistor BC327-40 | TO-92_Inline_Wide_custom |   
| 2 | R16, R18 | 47 &Omega;| R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R11 | 100 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 4 | R4, R8, R10, R13 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R12 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | R14, R15 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R1 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 2 | Rs2, Rs3 | 100 k&Omega; (alt: 10 k&Omega;) | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 4 | R2, R6, R7, Rs1 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R3 | 33 k&Omega; oder 22 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R5 | 47 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 2 | R9, R17 | 47 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | Rs4 | 220 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | RV1 | 10-Gang-Trimmer 10 k&Omega; stehend | Trim_Bourns_3296W_Vertical |   
| 1 | U1 | INA333_Board | INA333-Board |   
| 2 | U1 | Stiftleiste 4-Pin |   |   
| 2 | U1 | Buchsenleiste 4-Pin |   |   
| 1 | U2 | 2-fach-Komparator LM393 | DIP-8_W7.62mm_Socket_LongPads |   
| 1 | U2 | Präzisionssockel 8 Pin (2x 4 Pin, Abstand 7,62 mm) |   |    
| 1 | U3 | Optokoppler SFH615A | DIP-4_W7.62mm |   
| 1 | U3 | Präzisionssockel 4 Pin (2x 2 Pin, Abstand 7,62 mm) |   |    

Bauteile der "dcc_track_UI_TVn"-Platine (Version 1):   
![rcc6_dcc_track_UI_TVn_V1_parts](/images/300_rcc6_dcc_track_UI_TVn_V1_parts.png "rcc6_dcc_track_UI_TVn_V1_parts")   

#### Vorbereitung   
(1) 2x gedrehte, 2-polige Buchsen für die LEDs: Von einer (meist 40-poligen) Buchsenleiste herunterschneiden.  
(2) 2x 4-polige Buchsenleiste für das INA333-Board: Von 8- bzw. 10-poligen Buchsenleisten herunterschneiden.  
(3) 1x 2-polige Stiftleiste von Stiftleiste herunterschneiden (für J3)  
(4) 2x 4-polige Stiftleisten für das INA333-Board: Beiliegende 8-polige Stiftleiste in der Mitte auseinanderschneiden.  
(5) 2x 4-polige Stiftleisten auf der Unterseite des INA333-Boards nach UNTEN anlöten (siehe Bild).  

![rcc6_INA333_Board](/images/300_rcc6_INA333_Board.png "rcc6_INA333_Board")   
_Bild: INA-Board mit angelöteten Stiften_  

#### Best&uuml;ckung   
1. Widerstand R1 (liegend, möglichst flach, 10 k&Omega;)  
2. Widerst&auml;nde Rs2, Rs3 (liegend, möglichst flach, 100 k&Omega;)  
3. Widerstand R5 (liegend, 47 k&Omega;)   
4. Widerstand Rs4 (liegend, 220 k&Omega;)   
5. Diode D3 (BAT48, liegend, auf Polung achten: Kathode bei weißer Linie)   
6. Kondensatoren C1, C2, C4, C7, C8 (1 &micro;F, Raster 2,54 mm)   
7. Buchsenleisten U1 2x 4-Pin (Eventuell INA-Board kurz aufstecken, damit Abstand gut passt.)  
8. gedrehte Buchsen D4, D6 für die LEDs   
9. Fassungen U2 (2x 4 Pin) und U3 (2x 2 Pin, auf Einbaurichtung achten!)   
10. Diode D5 (1N4007, stehend, auf Polung achten: Kathode unten beim Kreis)   
11. Tantal-Elko C3, C5 (10 &micro;F, auf + Polung achten)   
---  
12. Widerst&auml;nde R16, R18 (47 &Omega;)   
13. Widerstand R11 (100 &Omega;)   
14. Widerst&auml;nde R4, R8, R10, R12, R13 (1 k&Omega;)   
15. Widerst&auml;nde R14, R15 (4,7 k&Omega;)   
16. Widerst&auml;nde R2, R6, R7, Rs1 (10 k&Omega;)   
17. Widerstand R3 (22 k&Omega; oder 33 k&Omega;)   
18. Widerst&auml;nde R9, R17 (47 k&Omega;)   
19. Elko C6 (Elko 33 &micro;F, auf - Polung achten)   
20. Transistor Q1 (BC337-40)   
21. Transistor Q2 (BC327-40)   
22. Stiftleiste 2-polig J3   
23. Diode D1, D2 (SB240, auf Polung achten: Kathode unten beim Kreis)   
---  
24. Wannenstecker 6-polig J5 (auf Polung achten)   
25. Schraubklemme J1, J2 (2-polig)   
26. 10-Gang-Trimmer RV1 (10 k&Omega; stehend, Schraube Richtung U2 LM393)   

#### Print vervollständigen
1. ICs bestücken (LM393, SFH615A, auf richtige Polung achten!)   
2. INA333_Board aufstecken (Trimmer Richtung Print-Rand)   
3. LEDs auf passende Länge kürzen (zB 10 mm) und in die Fassungen stecken (auf richtige Polung achten!)  
![rcc4_LED_Polung](/images/200_rcc4_LED_Polung.png "rcc4_LED_Polung")   

<a name="x424"></a>   

### 4.2.4 Inbetriebnahme und Test

![UI_pin_J5](/images/200_rcc6_UI_pin_J5.png "UI_pin_J5")   

1. Versorgungsspannung anlegen: +5V an Pin 4 vom 6-poligen Wannenstecker J5, 0V = GND an J5-Pin 6   
   ► ⚫ Die grüne LED leuchtet nicht.   

2. DCC-Spannung am Eingang der Schaltung anlegen:   
   ► 🟢 Die grüne LED leuchtet.   

3. Verstärkung des INA333-Boards voll aufdrehen:   
   ► ⚙️ Potenziometer **fast** bis zum Anschlag **gegen den Uhrzeigersinn** drehen   

4. Jumper J3 aufstecken   

5. Je nach Trimmer-Stellung die Schaltschwelle einstellen:   
   * 🔴 Wenn die rote LED __leuchtet__: Trimmer __im Uhrzeigersinn__ drehen, bis die rote LED erlischt, dann etwas gegen den Uhrzeigersinn drehen, bis die rote LED wieder leuchtet.  
   ► Jumper J3 abziehen: rote LED erlischt.   
   * 🟤 Wenn die rote LED __nicht leuchtet__: Trimmer __gegen den Uhrzeigersinn__ drehen, bis die rote LED zu leuchten beginnt.  
   ► Jumper J3 abziehen: rote LED erlischt.   

⚠️ Der Jumper J3 dient nur zum Einstellen. Im Betrieb muss er entfernt werden.   
ℹ️ Bei optimaler Einstellung leuchtet die rote LED bereits auf, wenn man die Gleise mit dem Finger verbindet.   

#### Kontrolle der Digitalausgänge
1. Messgerät auf Spannungsmessung stellen, COM-Anschluss mit GND verbinden, V/Ω an **Pin 2** von J5 (TVn) anschließen.   
2. Spannungsversorgung anlegen: +5 V an J5-Pin 4, 0 V = GND an J5-Pin 6  
3. Funktionstest **Ausgang TVn** (Track Voltage):   
   ► DCC-Versorgung abgeschaltet oder abgeklemmt: TVn = 5 V (⚫ grüne LED aus).   
   ► DCC-Versorgung am "Booster"-Eingang anschließen: TVn = 0,7 V (🟢 grüne LED ein).  
---  
4. Messgerät COM mit GND verbinden, V/Ω an **Pin 1** von J5 (FREn) anschließen.   
5. Funktionstest **Ausgang FREn** (Track Free):   
   ► DCC-Versorgung am "Booster"-Eingang anschließen.  
   ► Jumper J3 offen: FREn = 0,2 V (🟤 rote LED aus),  
   ► Jumper J3 gesteckt: FREn = 5 V (🔴 rote LED leuchtet).  

⚠️ **Ruhezustand**: Bei offenem Jumper und ohne Lok (bzw. Last, Waggon) am Gleis darf die **rote LED nicht** leuchten.   

<a name="x425"></a>   

### 4.2.5 Versionen
* V1 (260820): OK  

<a name="x43"></a>   
<a name="x431"></a>   

## 4.3 UI-Steuerungsplatine
### 4.3.1 Einleitung
Die UI-Steuerungsplatine `RCC_UI_TVn_STRG` dient zum Anpassen der [UI-Erkennung `dcc_track_UI_TVn_V1` (ohne Schalten)](#x42) an das RCC-Blocksystem. Sie   

* versorgt die `dcc_track_UI_TVn_V1`-Platine mit der 5V-Versorgungsspannung,   
* leitet die Steuersignale `FRE1` und `TRV1` weiter zur LED-Anzeige und   
* leitet die LED-Rückmeldesignale `ROK` und `RFRE` zum I²C-Stecker J4 weiter.   

<a name="x432"></a>   

### 4.3.2 Schaltplan
KiCad-Schaltplan der Platine "RCC_UI_TVn_STRG" (Version 1):   
![RCC_UI_TVn_STRG_circuit](/images/600_RCC_UI_TVn_STRG_circuit_V1.png "RCC_UI_TVn STRG_circuit")   

<a name="x433"></a>   

### 4.3.3 Bestückung der Platine
Bild der Anpassungsplatine `RCC_UI_TVn_STRG` (Version 1):   
![UI-Steuerungsplatine](/images/pcb_f/PCB_F_RCC_UI_TVn_STRG_V1.png "UI-Steuerungsplatine")   

Best&uuml;ckte Platine "RCC_UI_TVn_STRG"   
![RCC_UI_TVn_STRG bestückt](/images/300_RCC_UI_TVn_STRG_V1_assembled.png "RCC_UI_TVn_STRG bestückt")   

#### St&uuml;ckliste   
| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 1 | C1 | 100 nF, Raster 5,08 mm | C_Rect_L7.0mm_W2.0mm_P5.00mm_kh |   
| 2 | D1, D2 | Diode BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 2 | D3, D4 | Diode BAT48 | D_DO-35_SOD27_P5.08mm_Vertical_AnodeUp |   
| 2 | J1, J2 | Stiftleiste 8-polig (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_kh |   
| 2 | J3, J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 1 | J4 | Wannenstecker 10-polig, stehend | Box_02x05_P2.54mm_Vertical_kh |   
| 1 | R1 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 1 | R2 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical |   

Bauteile der Platine `RW_5V_UI_STRG` (C1 fehlt):   
![RW_5V_UI_STRG_parts](/images/300_RW_5V_UI_STRG_parts_V1.png "RW_5V_UI_STRG_parts")   

#### Best&uuml;ckung   
1. Diode D1, D2 (stehend, 2,54 mm, Kathode in den Kreis)   
2. Diode D3, D4 (stehend, 5,08 mm, Kathode in den Kreis)   
3. Kondensator C1 (100 nF)   
4. Widerst&auml;nde R1, R2 (stehend)   
5. Wannenstecker J1 bis J3 (auf Polung achten - Pin 1)   

Auf die _*L&ouml;tseite*_ l&ouml;ten:   
6. Stiftleisten J1 und J2 **NACH UNTEN** anl&ouml;ten!   

<a name="x435"></a>   

### 4.3.5 Inbetriebnahme und Test
Da die Platine sehr einfach aufgebaut ist, erfolgt der Test gemeinsam mit den Platinen  
* UI-Erkennung `dcc_track_UI_TVn_V1` und  
* Anzeigeplatine `RCC_RGY_TVn_LED_V1`  

Der Test ist [weiter unten](#x44) beschrieben.  

<a name="x436"></a>   

### 4.3.6 Versionen
* V1 (260820): OK   

<a name="x44"></a>   

## 4.4 Zusammenbau des UI_TVn-Blocks
1. Aufstecken des Steuerungsboards `RCC_UI_TVn_STRG` auf das Anzeigeboard `RCC_RGY_TVn_LED`.   
2. Einstecken der LEDs. Auf richtige Polung achten (rot - grün).  
3. Aufstecken der Schalter-Kn&ouml;pfe, falls gewünscht.  
4. Falls vorhanden: Print `RW_LEER_DUOLED` auf den Anzeigeprint stecken.   

<a name="x45"></a>   

## 4.5 Test
### Vorbereitung

Für den Test der DCC-Fahrstromerkennung ohne Schalten benötigt man folgendes:  

1. 1x [Einspeisung (FEED-IN)](https://github.com/khartinger/RCC5V/blob/main/LIESMICH.md#x31) und Kabel mit 2x 25-poligen SUB-D-Buchsen  

2. 1x [Modul-Stromversorgung (SUB25_10)](https://github.com/khartinger/RCC5V/blob/main/LIESMICH.md#x32)  

3. 2x 6-poliges Flachbandkabel, Länge 15 cm oder länger  

4. 4x Draht, Länge 20 cm oder länger (oder Kroko-Klemmen)  

5. Platine `dcc_track_UI_TVn`  

6. UI_TVn-Block aus Platine `RCC_UI_TVn_STRG` und aufgesteckter Anzeige-Platine `RCC_RGY_TVn_LED`  

7. Gleis und DCC-Lok  

### Verdrahtung
Die Verdrahtung erfolgt nach dem folgenden Schema:  

![RW_5V_UI_detection_test1](/images/300_RW_5V_UI_detection_test1.png "RW_5V_UI_detection_test1")   

![RW_5V_UI_detection_test2](/images/300_RW_5V_UI_detection_test2.png "RW_5V_UI_detection_test2")   
![RW_5V_UI_detection_test3](/images/300_RW_5V_UI_detection_test3.png "RW_5V_UI_detection_test3")   

1. Verbinde die Einspeisung (SUB25_10) mit der übergeordneten, nicht eingeschalteten Steuerung (SUB-D-Stecker).  
2. Verbinde den UI-TVn-Block-Stecker J3 mit dem Power-Stecker der SUB25_10 Einspeisung mit einem 6-poligen Flachbandkabel.  
3. Verbinde den UI-TVn-Block-Stecker J5 mit dem `dcc_track_UI_TVn`-Board mit einem 6-poligen Flachbandkabel.  
4. Verbinde die DCC-Gleisspannung vom SUB25_10 mit dem **BOOSTER**-Eingang des `dcc_track_UI_TVn`-Boards und mit dem Gleis, das **nicht** überwacht werden soll.  
5. Verbinde das Gleis, das überwacht werden soll, mit dem **TRACK**-Ausgang des `dcc_track_UI_TVn`-Boards.  

### Testdurchführung
1. Schalte die übergeordnete Steuerung ein:  
   ► 🟢🟢🟢 Die LEDs leuchten grün.  
2. Stelle eine Lok auf das nicht überwachte Gleis und fahre in den überwachten Bereich:  
   ► 🟡🟡🟡 Die LEDs leuchten gelb (orange).   
3. Stecke am UI-TVn-Block die Verbindung zum `dcc_track_UI_TVn`-Board ab (Stecker J3):  
   ► 🔴🔴🔴 Die LEDs leuchten rot.   




<br><br><br><hr><h1>*** ALTE VERSIONEN *** ALTE VERSIONEN ***</h1><br><br>  

<a name="xold"></a>   

# Ältere Platinen mit Gleisspannungssignal TRV = 5 V

## Einleitung

Bei der ersten Version wurde das Anliegen der Gleisspannung über **TRV = 5 V** signalisiert.  

Dadurch muss der entsprechende Ausgangspin in der Software mit **0 V** initialisiert werden. Da die übrigen Pins des PCF8574 üblicherweise mit **5 V** initialisiert werden, entsteht dadurch eine unnötige Fehlerquelle.  

<a name="xold10"></a>   
<a name="xold11"></a>   

## x.1 RGY-Anzeige

### x.1.1 Einleitung

Die Platine `RW_5V_RGY_LED` ist eine **41 × 41 mm²** große Anzeigeplatine im Format der RCC-Blöcke.  

Sie enthält bis zu **drei parallel geschaltete rot/grün-Duo-LEDs**. Die LEDs zeigen den Zustand der Eingangssignale **TRV** und **FRE** an.  

| TRV | FRE |   LED-Farbe   | # | ROK | RFR |  
|:---:|:---:|:-------------:|---|:---:|:---:|  
| 0 V | 0 V | Rot           | # | 5 V | 0 V |  
| 0 V | 5 V | Rot           | # | 5 V | 0 V |  
| 5 V | 0 V | Grün          | # | 0 V | 5 V |  
| 5 V | 5 V | Gelb (Orange) | # | 0 V | 0 V |  

**Bedeutung der Eingänge**

- **TRV** – Gleisspannung vorhanden (*Track Voltage*, 5 V)  
- **FRE** – Gleis frei (*Track Free*, 0 V)  

Damit zeigt die Platine den Zustand eines Gleises an:  

- 🟢 **Grün:** Gleis ist frei.
- 🟡 **Gelb:** Gleis ist besetzt.
- 🔴 **Rot:** Es liegt ein Fehler vor.

#### Rückmeldesignale

Zusätzlich zur LED-Anzeige stehen zwei Rückmeldesignale zur Verfügung:  

- **ROK** – Rückmeldung ist gültig (*Response OK* = *Response Valid*, 0 V)  
- **RFR** – Gleis ist frei (*Response Track Free*, 5 V)  

**Anmerkung**: Das Signal RFR wird gegenüber FRE invertiert.   

![rcc6_RGY_LED_blockdiagram](/images/300_rcc6_RGY_LED_blockdiagram.png "rcc6_RGY_LED_blockdiagram")   

#### Optionale Taster

An den Positionen **SW1** und **SW3** können optional Taster oder Schalter eingebaut werden. Sie können von einer Steuerplatine ausgewertet werden, zum Beispiel zum Testen der **SET-** und **RESET-Eingänge** einer [Pulsspeicher-Steuerungsplatine `RW_5V_PULS_STRG`](#x40).

<a name="xold12"></a>   

### x.1.2 Schaltplan
Die RGY-Anzeige besteht aus drei Teilen:   
1. Die LED-Anzeige   
2. die Rückmeldeschaltung   
3. Zwei Taster für Testzwecke   

#### Led-Anzeige
![rcc6_RGY_LED_circuit](/images/300_rcc6_RGY_LED_circuit_V1.png "rcc6_RGY_LED_circuit")   

Die Ansteuerung der Platine erfolgt über die Signale **TRV** (J1-Pin 7) und **FRE** (J1-Pin 8):   
- TRV = 0 V: Led leuchtet rot.  
  (Transistor T4 sperrt, T1 leitet → "LED rot"; T5 sperrt, T2 sperrt)  
- TRV = 5 V und FRE = 5 V: LED leuchtet gelb.  
  (T4 leitet, T3 sperrt, T1 Leitet → "LED rot"; T5 leitet, T2 leitet → "LED grün" → = rot + grün = gelb).  
- TRV = 5 V und FRE = 0 V: LED leuchtet grün.  
   (T4 leitet, T3 leitet, T1 sperrt; T5 leitet, T2 leitet → "LED grün")  

__Anmerkungen__
* Widerstand R1: 680 Ω bei drei Duo-LEDs, 1 kΩ bei einer Duo-LED   
* Widerstand R3: 3,9 kΩ bei drei Duo-LEDs, 10 kΩ bei einer Duo-LED   

#### Rückmeldeschaltung
![rcc6_RGY_LED_feedback_circuit](/images/300_rcc6_RGY_LED_feedback_circuit_V1.png "rcc6_RGY_LED_feedback_circuit")   

#### OK-Rückmeldung (ROK)

Das interne Signal **ROKi** wird für den externen Ausgang (**ROK**) etwas aufbereitet.   

- Die Diode **D4** verhindert, dass die Duo-LED belastet wird, wenn der Transistor **T5** gesperrt ist. Gleichzeitig zieht **R10** den Ausgang **ROK** auf **5 V**.   
- Schaltet **T5** durch, begrenzt **R9** einen möglichen Fehlerstrom von außen.   

#### Gleisfrei-Rückmeldung (RFR)

Das interne Signal **RFRi** wird mit dem Transistor **T6** invertiert und als **RFR** ausgegeben.   

#### Optionale Taster oder Schalter

Auf der Platine können an den Positionen **SW1** und **SW3** optional Taster oder Schalter eingebaut werden.  

Im Ruhezustand sind die Ausgänge **offen**.  
Beim Betätigen werden sie mit **0 V (Masse)** verbunden.  

#### Gesamtschaltplan

KiCad-Schaltplan der Platine **`RW_5V_RGY_LED`**:   
![RW_5V_RGY_LED_circuit](/images/600_RW_5V_RGY_LED_circuit_V1.png "RW_5V_RGY_LED_circuit")  

Die Stromversorgung und alle Ein- und Ausgangssignale befinden sich an der Stiftleiste J1.  

<a name="xold13"></a>   

### x.1.3 Bestückung der Platine
Bild der Platine "`RW_5V_RGY_LED`"" (Version 2):   
![Platine RW_5V_RGY_LED](/images/pcb_f/PCB_F_RW_5V_RGY_LED_V2.png "Platine RW_5V_RGY_LED")   

Best&uuml;ckte Platine "`RW_5V_RGY_LED`"   
![Bestückte Platine RW_5V_RGY_LED](/images/300_RW_5V_RGY_LED_assembled.png "Bestückte Platine RW_5V_RGY_LED")   

#### St&uuml;ckliste   

| Anzahl | Referenz | Wert | Geh&auml;use |   
|-----|-----|-----|-----|   
| 1 | C1 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 3 | D1, D2, D3 | Dual-LED rot-gr&uuml;n, gemeinsame Kathode | LED_D5.0mm-3 |   
| 3 | D1, D2, D3 | Buchsenleiste 3-polig mit gedrehten Pins | "Fassung" f&uuml;r LEDs |   
| 1 | D4 | Diode BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 2 | J1, J2 | Buchsenleiste 8-polig mit langen Kontakten (Conn_01x08_Pin) | PinSocket_1x08_P2.54mm_Vertical_11mm_kh |   
| 4 | Q1, Q4, Q5, Q6 | Transistor BC337-40 (npn) | TO-92_Inline_Wide_custom |   
| 2 | Q2, Q3 | Transistor BC327-40 (pnp) | TO-92_Inline_Wide_custom |   
| 1 | R1 | 680 &Omega;..1 k&Omega; (2) | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R11 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R3 | 3,9 k&Omega;..10 k&Omega; (3) | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R13 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 1 | R9 | 47 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R10, R12 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R6, R8 | 4,7 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 2 | R2, R5 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R7 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P3.81mm_Vertical_kh |   
| 3 | R4, R14, R15 | 100 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | SW1, SW2 | Taster SW_Push_DPDT_8x8 | SW_Push_DPDT_8x8 |   
| 2 | SW1, SW2 | Knopf f&uuml;r Taster/Schalter 8x8mm, L&auml;nge 10mm, Farbe je nach Anwendung |    

#### Anmerkungen
(1) Es ist sinnvoll, die 3-poligen Buchsenleisten an alle 3 LED-Positionen zu l&ouml;ten, auch wenn im Betrieb weniger LEDs eingesetzt werden.  
(2) Widerstand R1: 680 &Omega; bei drei Duo-LEDs, 1 k&Omega; bei einer Duo-LED   
(3) Widerstand R3: 3,9 k&Omega; bei drei Duo-LEDs, 10 k&Omega; bei einer Duo-LED   
   
#### Vorbereitung
1. Von einer langen, einreihigen Buchsenleiste 3x 3-polige St&uuml;cke abtrennen (f&uuml;r D1 bis D3).   
2. Die äußeren LED-Anschl&uuml;sse farblich kennzeichnen:  
   * kurzen Anschluss grün färben, mittleren Anschluss rot
3. LED-Anschl&uuml;sse auf 17 mm abschneiden und Ecken biegen ("Feder", mittleren Anschluss nach vorne oder hinten). Länge dann ca. 13 mm.   
![RW_5V_DUOLED1](/images/300_RW_5V_DUOLED1.png "RW_5V_DUOLED1") 
![RW_5V_DUOLED2](/images/300_RW_5V_DUOLED2.png "RW_5V_DUOLED2")   

4. NUR wenn Taster verwendet werden: 10 mm-Tasterkn&ouml;pfe SW1, SW2 eventuell verl&auml;ngern durch Aufkleben mit Sekundenkleber auf 7 mm-Tasterkn&ouml;pfe.   

Bauteile der Platine "RW_5V_RGY_LED"   
![RW_5V_RGY_LED_parts](/images/300_RW_5V_RGY_LED_parts.png "RW_5V_RGY_STRG_parts")   

#### Best&uuml;ckung   
**Lötseite** (!):  

1. Die dreipoligen Buchsenleisten (D1 bis D3) mit gedrehten Pins auf die **L&ouml;tseite** des Prints l&ouml;ten.   

Auf die **Bauteilseite** l&ouml;ten:   

2. Widerstände R1, R11 und R13 (liegend, 680 &Omega; ... 1 k&Omega;, 100 k&Omega;, 47 &Omega;)   
3. Transistoren Q1, Q4, Q5, Q6 (BC337-40)   
4. Transistoren Q2, Q3 (BC327-40)   
5. Kondensator C1 (1 &micro;F)   
6. Diode D4 (BAT48, auf Polung achten: Kathode unten beim Kreis)   
7. Widerstand R3 (3,9 k&Omega; ... 10 k&Omega;)   
8. Widerstand R9 (47 &Omega;)
9. Widerst&auml;nde R10, R12 (1 k&Omega;, stehend)   
10. Widerst&auml;nde R6, R8 (4,7 k&Omega;, stehend)   
11. Widerst&auml;nde R2, R5, R7 (10 k&Omega;, stehend)   
12. Widerst&auml;nde R4, R14, R15 (100 k&Omega;, stehend)   
13. Buchsenleisten 8-polig mit langen Kontakten J1 und J2   

Optional: Auf die **L&ouml;tseite** l&ouml;ten:   

14. Taster SW1, SW3   

#### Print vervollständigen
Duo-LED(s) einstecken.   

<a name="xold14"></a>   

### x.1.4 Test
### Vorbereitung
* 5x Kabel Stecker-Buchse (rot, schwarz, grün, violett, weiß)   
* Netzgerät 5 V   
* Voltmeter (Bereich 20VDC)   

#### Durchführung
Print auf die Bauteilseite legen. Alle erforderlichen Anschlüsse befinden sich an den langen Kontakten der der Buchsenleiste J1:   

![rcc6_RGY_LED_J1](/images/300_rcc6_RGY_LED_J1.png "rcc6_RGY_LED_J1")   

1. Versorgungsspannung anlegen: Pin 1 mit Netzgerät +5V, Pin 2 mit GND verbinden.   
   ► Die LEDs leuchten rot.   
2. Voltmeter an GND anschließen. Messen: Pin ROK = +5V, Pin RFR = 0V   
3. Pin TRV mit 5V verbinden.   
   ► Die LEDs leuchten gelb (orange).   
4. Messen: Pin ROK = 5V (3,5V), Pin RFR = 0V   
5. Pin FRE mit 0V verbinden.   
   ► Die LEDs leuchten grün.   
6. Messen: Pin ROK = 5V (4,3V), Pin RFR = 3,5V   

<a name="xold15"></a>   

### x.1.5 Versionen
* V1 (260704) -  Print brauchbar, aber **Änderungen** erforderlich:  
  * Siebdruckmaske: falsche Werte für R4 (10 k&Omega; statt **richtig 100 k&Omega;**) und R9 (100 k&Omega; statt **richtig 47 &Omega;**).  
  * SW2 in SW3 umbenennen.  
  * Neue Widerstandswerte: R1 = 680 &Omega; bis 1 k&Omega; (statt 1 k&Omega;), R3 = 3,9 k&Omega; bis 10 k&Omega; (statt 10 k&Omega;), R7 = 10 k&Omega; (statt 4,7 k&Omega;), R9 = 47 &Omega; (statt 10 k&Omega;), R10 = 1 k&Omega; (statt 4,7 k&Omega;), R12 = 1 k&Omega; (statt 4,7 k&Omega;)
* V2 (260712): OK   

---
<a name="xold20"></a>   
<a name="xold21"></a>   

## x.2 DCC-Gleis-Spannungs-/Strom-Erkennung
### x.2.1 Einleitung
Die DCC-Gleis-UI-Erkennung überwacht ein Gleis. Sie erkennt, ob  
1. **Gleisspannung** anliegt und ob  
2. **Fahrstrom** fließt.

Der Status wird über **LEDs angezeigt** und steht zusätzlich an **zwei digitalen Ausgängen** zur Verfügung.   
So kann man erkennen, ob ein Gleis **besetzt** ist.   

Die Stromversorgung und die beiden digitalen Ausgänge sind über einen **6-poligen Stecker** angeschlossen.   
![UI_pin_J5](/images/200_rcc6_UI_pin_J5_0.png "UI_pin_J5")   

TRV1 ... Track Voltage ON (5V) = Fahrspannung ein (5V)   
FRE1 ... Track Free (0V) = Gleis frei (0V)   

<a name="xold22"></a>   

### x.2.2 Gewinnung des Fahrstrom-Signals
Der Fahrstrom (maximal 2 A) wird durch einen Shunt in eine Spannung umgewandelt:   

![Schaltung Fahrstromsignal](/images/300_rcc6_ui_schematic_track_occupancy_detection.png "Schaltung Fahrstromsignal")   

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

<a name="xold23"></a>   

### x.2.3 Signalverstärkung
Die vom Shunt erzeugte Spannung wird mit einem INA333-Instrumentenverstärker-Board (CJMCU-333) verstärkt. Die Verstärkung ist von 1 bis zu ca. 1000 einstellbar.    
Lässt man den Referenzpin VREF offen, so wird eine interne Referenzspannung von 3,3 V /2 = 1,65 V verwendet. Die Ausgangsspannung sollte daher eine Gleichspannung von 1,65 V sein.   

Ohne Beschaltung und ohne Last sieht ein typisches Ausgangssignal allerdings oft so aus:   
![Ausgangsspannung INA333 leer](/images/300_rcc6_ui_INA333_Uout_no_load.png "Ausgangsspannung INA333 leer")   

Im Bild erkennt man eine Störspannung von 50 Hz mit diversen Überlagerungen.   
**Beispielwerte**   
Maximale Spannung: 2,26V   
Spitze-Spitze-Spannung: 1,46 V   
Gleichspannung zwischen den Impulsen: 1,6 V   
Pulsfrequenz: 50 Hz (alle 20 ms)   
__Anmerkung__: Vertauscht man die Eingänge DCC1 und DCC2, so wird das Signal invertiert...   

Vergrößert man mit dem Trimmer auf dem INA333-Board die Verstärkung auf den Maximalwert, so erhält man folgendes Signal:   
![Ausgangsspannung INA333 leer vmax](/images/o_rcc6_ui_INA333_Uout_no_load_vmax.png "Ausgangsspannung INA333 leer vmax")   

Im Bild erkennt man, dass der Verstärker übersteuert ist (unten bei der 0V-Linie).   
**Beispielwerte**   
Maximale Spannung: 2,86V   
Spitze-Spitze-Spannung: 2,86 V   
Gleichspannung zwischen den Impulsen: 1,65 V   
Pulsfrequenz: 50 Hz (alle 20 ms)   

Beschaltet man den Ausgang des INA333 mit einem Spitzenspannungsspeicher (D3-C1) und RC-Tiefpass, so ändert sich der Ausgang des INA333 nicht (d.h. es gibt keine Rückwirkung).   
![INA333 Schaltung Ausgangsfilter](/images/300_rcc6_ui_schematic_INA333_output_filter.png "INA333 Schaltung Ausgangsfilter")   

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

<a name="xold24"></a>   

### x.2.4 Erzeugen des Digitalsignals
Da das Ausgangssignals des Filters stark verrauscht ist, erfolgt die Erzeugung des Digitalsignals in zwei Stufen:   
* In einem ersten Schritt wird die Spannung mit einem Sollwert verglichen.   
* Im zweiten Schritt wird diese Spannung UK1 mit einem Tiefpass geglättet und nochmals mit der halben Versorgungsspannung verglichen.   

==> Eine Ausgangsspannung von 0 V bedeutet, dass kein Fahrstrom fließt bzw. das Gleis nicht belegt ist.    
==> Eine Ausgangsspannung von 5 V bedeutet, dass ein Fahrstrom fließt bzw. das Gleis besetzt ist.    

Die Ausgangsspannung wird (von einem Transistor invertiert) durch eine LED angezeigt:  
* LED ein = Fahrstrom fließt = Gleis besetzt.   
* LED aus = kein Fahrstrom = Gleis frei oder kein Fahrstrom.   

![LM393 Schaltung Digitalsignal](/images/300_rcc6_ui_schematic_LM393_comparator.png "LM393 Schaltung Digitalsignal")   

<a name="xold25"></a>   

### x.2.5 DCC-Spannungserkennung
Für die Gleisspannungserkennung wird das Gleissignal gleichgerichtet (1N4007), geglättet (100 &Omega;, 33 &micro;F) und einem Optokoppler zugeführt (1 k&Omega;, SFH615A). Der Optokoppler schaltet die grüne LED und das invertierte Ausgangssignal TRV.   
![dcc_track_U_detection_circuit](/images/300_rcc6_track_U_detection_circuit_V2.png "dcc_track_U_detection_circuit")   

<a name="xold26"></a>   

### x.2.6 Gesamtschaltung
KiCad-Schaltplan der "dcc_track_UI_detection"-Platine:   
![dcc_track_UI_detection_circuit](/images/600_dcc_track_UI_detection_circuit_V2a.png "dcc_track_UI_detection_circuit")   

<a name="xold27"></a>   

### x.2.7 Bestücken der Platine
Bild der Platine zur DCC-Gleis-Spannungs-/Strom-Erkennung (Version 2):   
![Platine Gleis-UI-Erkennung](/images/pcb_f/PCB_F_dcc_track_UI_detection_V2.png "Platine Gleis-UI-Erkennung")   

Best&uuml;ckte Platine "dcc_track_UI_detection"   
![Bestückte Platine dcc_track_UI_detection](/images/300_dcc_track_UI_detection_V1_assembled.png "Bestückte Platine dcc_track_UI_detection")   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
| 5 | C1, C2, C4, C7, C8 | Kondensator 1 &micro;F, 16 V, Raster 2,54 mm | C_L4mm_D3mm_P2.54mm_kh |   
| 2 | C3, C5 | Tantal-Elko 10 &micro;F, 16 V, Raster 2,54 mm | C_L4.32mm_D3.81mm_P2.54mm_kh |   
| 1 | C6 | Elko 33 &micro;F, 35 V, Raster 2,54 mm | CP_Radial_D8.0mm_P2.50mm |   
| 2 | D1, D2 | Diode SB240 | D_DO-15_P3.81mm_Vertical_AnodeUp |   
| 1 | D3 | Diode BAT48 | D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 1 | D4 | LED rot, 3 mm, 2 mA | LED_D3.0mm |   
| 1 | D5 | Diode 1N4007 | D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
| 1 | D6 | LED gr&uuml;n, 3 mm, 2 mA | LED_D3.0mm |   
| 2 | D4, D6 | gedrehte Buchsen, 2-polig |   |   
| 2 | J1, J2 | Schraubklemme, 2-polig, schwarz, 5 mm | Screw_Terminal_01x02_P5 |   
| 1 | J3 | Stiftleiste 2-polig | PinSocket_1x02_P2.54mm_Vertical_kh |   
| 1 | J3 | Jumper 2-polig |    |   
| 1 | J5 | Wannenstecker 6-polig, stehend | Box_02x03_P2.54mm_Vertical_kh |   
| 2 | Q1, Q2 | npn-Transistor BC337-40 | TO-92_Inline_Wide_custom |   
| 2 | R16, R17 | 47 &Omega;| R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R11 | 100 &Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 6 | R4, R8, R10, R12, R13, R15 | 1 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | Rs2 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal |   
| 1 | Rs3 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 5 | R1, R2, R6, R7, Rs1 | 10 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | R3 | 33 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal |   
| 3 | R5, R9, R14 | 47 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | Rs4 | 220 k&Omega; | R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | RV1 | 10-Gang-Trimmer 10 k&Omega; stehend | Trim_Bourns_3296W_Vertical |   
| 1 | U1 | INA333_Board | INA333-Board |   
| 2 | U1 | Stiftleiste 4-Pin |   |   
| 2 | U1 | Buchsenleiste 4-Pin |   |   
| 1 | U2 | 2-fach-Komparator LM393 | DIP-8_W7.62mm_Socket_LongPads |   
| 1 | U2 | Präzisionssockel 8 Pin (2x 4 Pin, Abstand 7,62 mm) |   |    
| 1 | U3 | Optokoppler SFH615A | DIP-4_W7.62mm |   
| 1 | U3 | Präzisionssockel 4 Pin (2x 2 Pin, Abstand 7,62 mm) |   |    

Bauteile der "ui_detection"-Platine (Version 1):   
![rcc6_ui_detection_parts](/images/300_rcc6_ui_detection_parts_V1.png "rcc6_ui_detection_parts")   

#### Vorbereitung   
* 2x gedrehte, 2-polige Buchsen für die LEDs: Diese von den meist 40-poligen Buchsenleisten herunterschneiden.   
* 2x 4-polige Stiftleisten für das INA333-Board: Beiliegende 8-polige Stiftleiste in der Mitte auseinanderschneiden.   
* 2x 4-polige Buchsenleiste für das INA333-Board: Von 8- bzw. 10-poligen Buchsenleisten herunterschneiden.    

#### Best&uuml;ckung   
1. Widerst&auml;nde R1, Rs2, Rs3 (liegend, möglichst flach, 10 k&Omega;)   
2. Widerstand R5 (liegend, 47 k&Omega;)   
3. Widerstand Rs4 (liegend, 220 k&Omega;)   
4. Diode D3 (BAT48, liegend, auf Polung achten: Kathode bei weißer Linie)   
5. Kondensatoren C1, C2, C4, C7, C8 (1 &micro;F, Raster 2,54 mm)   
6. Buchsenleisten U1 2x 4-Pin   
7. gedrehte Buchsen D4, D6 für die LEDs   
8. Fassungen U2 (2x 4 Pin) und U3 (2x 2 Pin, auf Einbaurichtung achten!)   
9. Diode D5 (1N4007, stehend, auf Polung achten: Kathode unten beim Kreis)   
10. Tantal-Elko C3, C5 (10 &micro;F, auf + Polung achten)   

10. Widerst&auml;nde R16, R17 (47 &Omega;)   
11. Widerstand R11 (100 &Omega;)   
12. Widerst&auml;nde R4, R8, R10, R12, R13, R15 (1 k&Omega;)   
13. Widerst&auml;nde R2, R6, R7, Rs1 (10 k&Omega;)   
14. Widerstand R3 (33 k&Omega;)   
15. Widerst&auml;nde R9, R14 (47 k&Omega;)   
16. Elko C6 (Elko 33 &micro;F, auf - Polung achten)   
17. Transistor Q1, Q2 (BC337-40)   
18. Stiftleiste 2-polig J3   
19. Diode D1, D2 (SB240, auf Polung achten: Kathode unten beim Kreis)   

21. Wannenstecker 6-polig J5 (auf Polung achten)   
22. Schraubklemme J1, J2 (2-polig)   
23. 10-Gang-Trimmer RV1 (10 k&Omega; stehend, Schraube Richtung Printmitte)   

##### Stiftleisten ans INA333_Board anlöten
Stiftleisten auf der Unterseite nach UNTEN anlöten.   

##### Print vervollständigen
1. ICs bestücken (LM393, SFH615A, auf richtige Polung achten!)   
2. INA333_Board aufstecken   
3. LEDs auf passende Länge kürzen und in die Fassungen stecken   

<a name="xold28"></a>   

### x.2.8 Inbetriebnahme und Test
1. Versorgungsspannung anlegen: 5V an Pin 3 vom 6-poligen Wannenstecker J5, GND an Pin 5 von J5   
   ► Die grüne LED leuchtet nicht.   
2. DCC-Spannung am Eingang der Schaltung anlegen:   
   ► Die grüne LED leuchtet.   
3. Verstärkung des INA333-Boards bis zum Anschlag **gegen den Uhrzeigersinn** drehen (volle Verstärkung)   
4. Jumper J3 aufstecken   
5. Je nach Trimmer-Stellung die Schaltschwelle einstellen:   
   * Wenn die rote LED __leuchtet__: Trimmer __im Uhrzeigersinn__ drehen, bis die rote LED erlischt, dann etwas gegen den Uhrzeigersinn drehen, bis die rote LED wieder leuchtet. Jumper J3 abziehen: rote LED erlischt.   
   * Wenn die rote LED __nicht leuchtet__: Trimmer __gegen den Uhrzeigersinn__ drehen, bis die rote LED zu leuchten beginnt. Jumper J3 abziehen: rote LED erlischt.   

Der Jumper J3 dient nur zum Einstellen. Im Betrieb muss er entfernt werden.   
Bei optimaler Einstellung leuchtet die rote LED bereits auf, wenn man die Gleise mit dem Finger verbindet.   

##### Kontrolle der Digitalausgänge
1. Messgerät auf Spannungsmessung stellen, den COM-Anschluss an Pin 6 vom 6-poligen Wannenstecker J5, V an Pin 2 von J5 (TRV) anschließen.   
2. DCC-Versorgung angeschlossen: TRV = 5 V (grüne LED ein), DCC-Versorgung abgeklemmt: TRV = 0 V (grüne LED aus).   
3. Messgerät mit COM an an Pin 6 vom 6-poligen Wannenstecker J5, V an Pin 1 von J5 (FRE) anschließen.   
4. DCC-Versorgung am ""Booster"-Eingang anschließen. Jumper J3 offen: FRE = 0 V (rote LED aus), Jumper J3 gesteckt: FRE = 5 V (rote LED leuchtet).   

**Ruhezustand**: Bei offenem Jumper und ohne Lok (bzw. Last, Waggon) am Gleis darf die rote LED nicht leuchten.   

<a name="xold29"></a>   

### x.2.9 Versionen
* V1 (260628) -  Verbesserungen:  
  * C8 ergänzen,
  * Testwiderstand Rs4 (220 k&Omega;) an __an SS und NN__ (statt DCC0 und DCC1) anschließen,
  * Widerstand __R14 = 47 k&Omega;__  anschreiben (statt 1 k&Omega;),   
  * Platinengröße auf 29,5 x 84 mm verkleinern.   
* V2 (260717): OK   


[Zum Seitenanfang](#up)   