<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>RCC-Blocktester 2</h1><b><big>Testsystem für weitere RCC-Komponenten (Steuerblöcke)</big></b><br>  
Stand: 15.11.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

[Link zur Inhalts&uuml;bersicht](#x05)   

# Worum geht es hier?

Diese Anleitung beschreibt den Aufbau eines zweiten **Testsystems für RCC-Komponenten** (Railroad Control Components).  

Mit dem Testsystem lassen sich folgende Steuerblöcke überprüfen:  

- DCC-Fahrstromerkennung **mit** Schalten des Fahrstroms (TUI)
- DCC-Fahrstromerkennung **ohne** Schalten des Fahrstroms (UI_TVn)
- Pulsflanken-Erkennung 2-fach (PULS1)
- Set-/Reset-Pulsflanken-Erkennung mit Speicherung (PULS2)

Das Testsystem ist bereits vollständig aufgebaut und funktionsfähig. Zum Testen einer neu entwickelten oder neu gebauten Komponente wird diese einfach angeschlossen bzw. eingebaut. Anschließend lässt sich überprüfen, ob alle Funktionen weiterhin korrekt arbeiten.  

Die Frontplatte ist mit 3D-Druck erstellt, sodass die Schaltblöcke leicht ein- und ausgebaut werden können.  

![Ansicht des Blocktesters #2](./images/300_BT2_view_front.png "Ansicht des Blocktesters #2")

*Bild 1: Ansicht des Blocktesters #2*

Mit einer Größe von **31 × 22,3 cm** ist das Testsystem kompakt genug, um bequem in einer IKEA-SAMLA-Box (Artikelnummer 401.029.78) aufbewahrt zu werden.  

![Blocktester 2 in einer IKEA-Box](./images/300_BT2_view_ikea.png "Blocktester 2 in einer IKEA-Box")

*Bild 2: Blocktester in einer IKEA-Box*

## Eigenschaften des Blocktesters #2
Das folgende Bild zeigt den Blocktester #2 von oben.   

- **Oben:** Gleis mit 3D-Bahnkörper und eingebauten Sensoren (Optokoppler, Reed-Kontakte).  
- **Mitte:** Modulanschluss (Stromversorgung) links, Anschlussplatinen für die Eisenbahnkomponenten und I²C-Platinen.  
- **Unten:** Mikrocontroller mit Shields (links) und die verschiedenen Steuerblöcke daneben.  

![Ansicht Blocktester 2 oben](./images/600_BT2_view_above.png "Ansicht Blocktester 2 oben")   
_Bild 3: Blocktester #2 von oben_   

### &Uuml;bersicht &uuml;ber die System-Eigenschaften 
|                |                                                    |   
| -------------- | -------------------------------------------------- |   
| Modulgröße     | 31 x 22,3 cm², Höhe 7 cm                           |   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit Schotterbett          |   
| Gleisbild      | 2 getrennte Stromkreise, 2x Reed-Kontakt, 2x Optokoppler  |   
| Elektrischer Anschluss | 2x 25-poliger SUB-D-Stecker <br>(entsprechend NEM 908D, je 1x WEST und OST) |   
| Fahrstrom     | Analog- oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | * H&auml;ndisch direkt an der Modulvorderseite <br> * &uuml;ber DCC <br> * durch MQTT-Nachrichten (&uuml;ber WLAN) |   
| Bedienelemente mit R&uuml;ckmeldung | 1x Mikrocontroller mit OLED-Display und Taster <br> 1x Abschaltbares Gleis mit Fahrstromanzeige (Block TUI, DCC 61) <br> 1x Fahrstromanzeige (Block TU, DCC 71) <br> 1x Impulserkennung (DCC 81, DCC 82) <br> 1x Impulsspeicherung (DCC 91)  |   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   
| MQTT: IP-Adresse des Brokers (Host) | `10.1.1.1` |   
| Sonstiges | * Als Steuersoftware dient die Demo-Software `Demo2` |   

<a name="x05"></a>   

# Inhaltsverzeichnis   
* [1. Schaltung des Test-Systems](#x10)   
* [2. Aufbau des Blocktesters #2](#x20)   
* [3. Gleisbau](#x30)   
* [4. Software f&uuml;r den ESP32](#x40)   
* [5. Arbeiten mit dem Blocktester](#x50)   

[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# 1. Schaltung des Testsystems
Das Testsystem ist so aufgebaut, dass sich alle Komponenten leicht austauschen lassen. Gleichzeitig zeigt es den Einsatz der verschiedenen Add-on-Platinen.  

Das folgende Bild gibt einen Überblick über die verwendeten Komponenten:  

![&Uuml;bersicht Testsystem](./images/600_bt2_overview_circuit.png  "&Uuml;bersicht Testsystem")   
_Bild 4: &Uuml;bersichtsplan Blocktester #2_   

## Bedeutung der einzelnen Komponenten
Die folgende Liste enth&auml;lt Links zu Beschreibungen und zum Bau der Komponenten.   

`SUB25_10 ....` [Modul-Verbinder mit Netzteil](/fab/rcc1_supply/LIESMICH.md#x30)      
`uC_OLED .....` [Block OLED-Fassung mit I²C- und DCC-Shield sowie ESP32](/fab/rcc2_esp32/LIESMICH.md#x15)   

-------   

`TUI .........` [Block zum Schalten und Anzeige des Fahrstroms](/fab/rcc4_block/LIESMICH.md#x70), zB zum Erkennen, ob ein Gleis besetzt ist.  
`UI ..........` [Block zur Anzeige eines Fahrstroms](/fab/rcc6_additional_components/LIESMICH.md#x40), zB zum Erkennen, ob ein Gleis besetzt ist.  
`PULS1 .......` [Block zur Anzeige von zwei unabhängigen Impulseingängen](/fab/rcc6_additional_components/LIESMICH.md#x20).  
`PULS2 .......` [Block zur Anzeige eines Set/Reset-Impulseingangs](/fab/rcc6_additional_components/LIESMICH.md#x30).  

-------   

`10pol_PIN....` Umsetzer vom 10-poligen Flachbandkabel auf 2x4 Pin [als &auml;ltere Version `CON_10pol_PIN`](/fab/rcc5_add_ons/LIESMICH.md#x90) bzw. [als neuere Version `CON_10pol_2x4`](/fab/rcc5_add_ons/LIESMICH.md#x80)   
`CON_2x6pol-0 ` [ I²C-Verlängerungsplatine bzw. Umsetzer vom 6-poligen Flachbandkabel auf 6 Pins](/fab/rcc5_add_ons/LIESMICH.md#x70)
`CON_6pol-6 ..` [Umsetzer vom 6-poligen Flachbandkabel auf 6 Schraubklemmen](/fab/rcc5_add_ons/LIESMICH.md#x50).  
`CON_4x10pol_io16 ` [4-fach Umsetzer vom 10-poligen Flachbandkabel auf 2x4 Pin](/fab/rcc5_add_ons/LIESMICH.md#x100) zB als Ersatz von 4 Stück `10pol_PIN`.  

-------   

`i2c_20mm ....` [I²C-Halterung 20 mm](/fab/rcc3_i2c/LIESMICH.md#x20)   
`PCF8574 .....` [I²C-PCF8574-I/O-Platinen](/fab/rcc3_i2c/LIESMICH.md)   
`CON_i2c_Term.` [I²C-Platine mit Pull-up-Widerst&auml;nden](/fab/rcc3_i2c/LIESMICH.md#x60)   
`i2c_15mm ....` [I²C-Halterung 15 mm](/fab/rcc3_i2c/LIESMICH.md#x20)   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Aufbau des Blocktesters #2
## 2.1 Rahmen
- **Grundplatte**: Größe 31 x 22 cm², 10 mm-Pappelsperrholz.  
- **Frontplatte**: Größe 31 x 6 cm², 10 mm-Pappelsperrholz oder [3D-Druck (bt2_frame_front_S_Oled_3456_310mm_261107.FCStd)](./3d/fcstd/bt2_frame_front_S_Oled_3456_310mm_261107.FCStd).  
- **Seitenteile**: Größe 5 x 5 cm², 10 mm-Pappelsperrholz oder [3D-Druck (bt2_side_261107.FCStd)](./3d/fcstd/bt2_side_261107.FCStd).  
- **"Deckplatte"**: Größe 30 x 3 cm², 10 mm dicke [Acrylplatte](https://de.aliexpress.com/item/1005006407038394.html?spm=a2g0o.order_list.order_list_main.506.f9f35c5f0KKSc4&gatewayAdapt=glo2deu). So kann man die Schaltbl&ouml;cke darunter gut sehen.   

## 2.2 Frontplatte
__OLED-Anzeige__   
F&uuml;r den OLED-Mikroprozessor-Block wird ein [3D-gedruckter Rahmen (OLED_Mount_250209.3mf)](/fab/3d/LIESMICH.md#x40) verwendet.   

![OLED- und Taster-Einsatz](/images/3d/300_OLED-Mount.png "OLED- und Taster-Einsatz")   
_Bild 5: Halterung f&uuml;r die OLED-Anzeige und den Taster_   

Dieser ben&ouml;tigt eine rechteckf&ouml;rmige Aussparung der Gr&ouml;&szlig;e 80 x 43 mm². Da der Platz am Frontpanel beengt ist, betr&auml;gt der Abstand vom linken Rand nur 15 mm statt der sonst &uuml;blichen 30 mm.   

![OLED_Button_frame](./images/300_BT2_OLED_Button_frame.png "OLED_Button_frame")   
_Bild 6: Ma&szlig;e f&uuml;r die OLED-Ausnehmung in der Frontplatte_   

__Steuerbl&ouml;cke__   
> Bei _*Holzfrontplatte*_: Zum einfachen Bestimmen der Lage der Bohrungen f&uuml;r die Steuerbl&ouml;cke wird zuerst zB in __LibreOffice Draw__ die [Beschriftung](./odg/BT2_block_cover_261115.odg) entworfen. W&auml;hlt man in der Zeichnung das Raster der Blockbeschriftungen 50 mm, so kann man den ganzen Ausdruck direkt auf die Frontplatte kleben.   

> ![Blocktester2 Beschriftung](./images/300_BT2_cover.png "Blocktester2 Beschriftung")   
> _Bild 7: Beschriftungen f&uuml;r die Steuerbl&ouml;cke_   

> Nach dem Aufkleben der Beschriftung werden die L&ouml;cher gebohrt. Der Bohrdurchmesser f&uuml;r die LED-Fassungen betr&auml;gt 5,6 mm, der f&uuml;r die Taster ca. 7 mm.   

> ![Blocktester Sued](./images/300_BT2_sued_310mm.png "Blocktester_Sued")   
> _Bild 8: Ma&szlig;e f&uuml;r die Frontplatte_   

Bei 3D-Druck bzw. bei Verwendung von Steuerblöcken mit 3D-Blockpanel werden quadratische Ausnehmungen (42 x 42 mm²) benötigt.  

![Blocktester Sued](./images/300_BT2_sued_3d_310mm.png "Blocktester_Sued")   
_Bild 9: Ma&szlig;e f&uuml;r die 3D-Frontplatte_   


> __LED-Fassungen__   
> Bei _*Holzfrontplatte*_: Nach dem Bohren sind die Bohrungen zu entgraten (reinigen) und die LED-Fassungen einzupressen.   
> ![LED holder](/images/parts/200_ledholder2.png "LED holder")   
> _Bild 10: LED-Fassung_   

>__Halterungen f&uuml;r Steuerbl&ouml;cke__   
> Bei _*Holzfrontplatte*_: Als N&auml;chstes kann man die Halterungen f&uuml;r die Steuerbl&ouml;cke mit 2,6 x 8 mm Schrauben anschrauben. Der Abstand der Bl&ouml;cke von der Unterseite des Rahmens sollte 5,5 mm betragen, allerdings ist die Lage der Halterungen meist durch die LED-Fassungen bereits vorgegeben...   
> Das Anziehen der Schrauben sollte nicht zu fest erfolgen, sodass sich die Sechskant-Distanzhalter nicht nach innen biegen!   

## 2.3 Zusammenbau des Rahmens
Der Zusammenbau des Rahmens erfolgt so, wie es im _Bild 1_ zu sehen ist. Als Schrauben werden zB selbstschneidende Schrauben 3 x 25 mm verwendet.   
Das Acrylglas wird mit Doppelklebeband befestigt und/oder mit Schrauben M 2 x 20 mm.   

## 2.4 Montage der Schaltbl&ouml;cke
Schaltblöcke mit 3D-Blockpanel werden in die quadratischen Ausnehmungen gesteckt.  

> Bei _*Holzfrontplatte*_: Die Schaltbl&ouml;cke werden auf die Blockhalterungen gesteckt und mit Schrauben M2 x 20 LEICHT angeschraubt.   

## 2.5 I²C-Verbindungen
F&uuml;r das Erstellen bzw. die Verwendung der Demo-Software ist die Kenntnis der Verdrahtung zwischen Schaltbl&ouml;cken und I²C-I/O-Expandern wichtig. Diese ist auch unter [`/software/rcc_demo2`](/software/rcc_demo2/LIESMICH.md) beschrieben.   

1. DCC 61, IO-Expander Pin 0,1: Fahrstromschalter (Schaltblock TUI)   
2. DCC 71, IO-Expander Pin 2,3: Fahrstromanzeige (Schaltblock UI)   
3. DCC 81,82, IO-Expander Pin 4,5: Impulsanzeige 2-fach (Schaltblock PULS1)   
4. DCC 91, IO-Expander Pin 6,7: Impulsanzeige Set/Reset (Schaltblock PULS2)   

Die IO-Pins zur Ansteuerung und zur R&uuml;ckmeldung werden normalerweise auf die gleichen Pin-Nummern verdrahtet.   

Die Umsetzung vom 10-poligen Schaltblock-Ausgang auf Einzelpins erfolgt entweder mit einzelnen 10pol_PIN-Platinen oder dem 4-fach Umsetzer `CON_4x10pol_io16 `.  

![Blocktester2_i2c_Schaltplan](./images/480_BT2_i2c_circuit.png "Blocktester2_i2c_Schaltplan")   
_Bild 11: I²C-Verdrahtungsplan des Blocktesters #2_   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# === ..ToDo.. ===

## 3. Gleisbau
## 3.1 Montage der Gleise
Der Aufbau der Eisenbahn-Komponenten (Weichen usw.) ist beliebig, da die Gleise prim&auml;r nicht f&uuml;r einen Fahrbetrieb gedacht sind. Wichtig ist nur, dass eine Trennstelle vorgesehen wird (die kleinen roten Rechtecke im _Bild 4_ bzw. das dunkelgraue Dreieck im _Bild 12_), damit man das Abschalten des Fahrstroms testen kann. Weiters sollte man darauf achten, dass der Abstand der Parallelgleise &uuml;blicherweise 33,6 mm betr&auml;gt. Dies kann man durch Aufzeichnen der Gleislage auf der Grundplatte sicherstellen.   

![Blocktester_Gleisbild](./images/300_BT_Gleisbild.png "Blocktester_Gleisbild")   
_Bild 12: Gleisbild_   

F&uuml;r das vorgeschlagene Gleisbild werden folgende Gleise ben&ouml;tigt:    

| Anzahl | Nummer | Name | Euro/Stk | Euro |   
| :---: | :---: | :--- |  ---: |  ---: |   
| 3 | 9103 | Gerade 55, 5 mm | 4,40 | 13,20 |   
| 4 | 9104 | Gerade 27,75 mm | 4,40 | 17,60 |   
| 1 | 9112 | Entkupplungsgleis gerade (mit Antrieb) | 31,90 | 31,90 |   
| 1 | 9116 | Prellbock 57,5 mm | 8,40 | 8,40 |   
| 1 | 9136 | Bogen Radius 430mm, Winkel 15° (R4) | 4,90 | 4,90 |   
| 1 | 9157 | Dreiwegweiche | 47,80 | 47,80 |   
| 1 | 9178 | Weiche links mit stromleitendem Herzst&uuml;ck | 29,90 | 29,90 |   
| 3 | 640000 | Elektromagnetischer Weichenantrieb mit Endabschaltung | 25,60 | 76,80 |   
| 1 | 9409 | Gleisn&auml;gel 7 mm Fleischmann (oder Minitrix 66537 10 mm) | 9,90 | 9,90 |   
| 1 | 9403 | Isolierschienenverbinder | 6,90 | 6,90 |   
| 2 | 22217 | 2-poliges Anschlusskabel | 4,40 | 8,80 |   
   
Gesamtkosten 2025: ca. 255 Euro   

Die Gleise werden nur mit Gleisn&auml;geln befestigt (kein Aufkleben), damit man sie bei Bedarf abbauen und anderwertig einsetzen kann.   
An das Ende des geschalteten Gleises kann ein Zweifach-LED mit zwei Anschl&uuml;ssen und einem 2,2 k&Omega;-Widerstand in Serie gel&ouml;tet werden, damit man am Leuchten der LED gleich erkennt, ob eine Fahrspannung anliegt.   

## 3.2 Verdrahtung der Eisenbahn-Komponenten
Die Verdrahtung der Eisenbahn-Komponenten erfolgt beim Blocktester von den Bauteilen (Weichen, Entkuppler, Fahrstromanschluss) zu den entsprechenden 6-poligen Platinen. An sich k&ouml;nnte die Verdrahtung auch direkt zu den Schaltbl&ouml;cken erfolgen, aber durch die Verwendung der Add-On-Platinen wird die Verdrahtung wesentlich &uuml;bersichtlicher und einfacher.   

### Entkuppler (CON_6pol-3)
Anschluss der beiden Leitungen an Pin 3 (Masse, mittlere Schraubklemme, schwarze Leitung) und Pin 5 (braune Leitung). Zwischen die beiden Pins muss zum Vermeiden von St&ouml;rspannungen ein Kondensator (zB 100 nF/50V) geschaltet werden.   
Pin 1 bleibt frei.   

![CON_6pol_3_circuit_V1](/images/200_CON_6pol_3_V1_circuit.png "CON_6pol_3_circuit_V1")   
_Bild 13: Schaltplan der "CON_6pol_3"-Platine, Version 1 (!)_   

![Pinbelegung_1OUT-J5](/images/200_J5_pins_1OUT.png "Pinbelegung 1OUT-J5")   
_Bild 14: Pinbelegung des Steckers J5 von 1OUT (RW_5V_1OUT_STRG)_   

### Zweiwegweiche (CON_6pol-3)
Die Masse der Zweiwegweiche (schwarze Leitung) wird an Pin 3 (mittlere Schraubklemme) angeschraubt. Der Anschluss der beiden anderen Kabel h&auml;ngt davon ab, ob die Weiche &Uuml;berflur oder Unterflur montiert wird. Am besten eine Leitung an Pin 1 anschrauben und die Weiche mit dem Schaltblock W2 schalten. Passt der Schaltzustand ("Gerade" oder "Abzweig"), so schlie&szlig;t man das zweite Kabel am anderen Anschluss an, ansonsten vertauscht man die beiden braunen Kabel.   

![Pinbelegung_W2-J5](/images/200_J5_pins_W2.png "Pinbelegung W2-J5")   
_Bild 15: Pinbelegung des Steckers J5 von W2 (RW_5V_W2_STRG)_   

### Dreiwegweiche (CON_6pol-6)
Der mittlere der beiden 3-poligen Anschl&uuml;sse wird mit der R&uuml;ckleitung (schwarzes Kabel) der Weichenantriebe verbunden.   
Beim Verdrahten der Dreiwegweiche ist besonders darauf zu achten, dass die Stellung "Gerade" (= "Mitte") f&uuml;r beide Weichenantriebe an die selbe Klemme angeschraubt wird.   
Das Herausfinden der Anschl&uuml;sse erfolgt am besten durch Versuche wie bei der Zweiwegweiche:   
* zuerst herausfinden, ob die linken oder rechten drei Klemmen f&uuml;r das "Links"-Schalten der Weiche zust&auml;ndig sind   
* herausfinden, welcher der beiden Dr&auml;hte f&uuml;r das "Gerade"-Schalten des linken Weichenantriebs zust&auml;ndig ist und bei Klemme 5 oder 6 anschlie&szlig;en   
* herausfinden, welcher der beiden Dr&auml;hte f&uuml;r das "Gerade"-Schalten des rechten Weichenantriebs zust&auml;ndig ist und bei Klemme 5 oder 6 anschlie&szlig;en   
* anderen Anschluss des rechten Weichenantreibs anschlie&szlig;en.    

![CON_6pol_6_V1_circuit](/images/200_CON_6pol_6_V1_circuit.png "CON_6pol_6_V1_circuit")   
_Bild 16: Schaltplan der "CON_6pol_6"-Platine, Version 1 (!)_   

![Pinbelegung_W3-J5](/images/200_J5_pins_W3.png "Pinbelegung W3-J5")   
_Bild 17: Pinbelegung des Steckers J5 von W3 (RW_5V_W3_STRG)_   

### Abschaltbares Gleis (CON_1xIO)
An den Stecker `CON_1xIO` wird links oder rechts der Fahrstrom angeschlossen und &uuml;ber das 6-polige Kabel wird der geschaltete Fahrstrom an die mittlere Doppelklemme ausgegeben.   
Der Fahrstrom zum Gleis wird daher an das mittlere Klemmenpaar angeschlossen.   

![CON_1xIO_V1_circuit](/images/200_CON_1xIO_V1_circuit.png "CON_1xIO_V1_circuit")   
_Bild 18: Schaltplan der "CON_1xIO"-Platine_   

![Pinbelegung_2IO-J5](/images/200_J5_pins_2IO.png "Pinbelegung 2IO-J5")   
_Bild 19: Pinbelegung des Steckers J5 von 2IO (RW_5V_2IO_STRG)_   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Software f&uuml;r den ESP32
Als Software wird die Demo-Software `rcc_demo1` (siehe [/software/rcc_demo1/LIESMICH.md)](/software/rcc_demo1/LIESMICH.md) verwendet.   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Arbeiten mit dem Blocktester
## 5.1 Funktionstest des Blocktesters
Nach dem   
* Anstecken der 25-poligen Sub-D-Buchse und dem 
* Einschalten der Versorgung sollte der Blocktester hochfahren, dabei 
* das WiFi-Netzwerk `Raspi11` suchen, 
* sich - falls vorhanden - ins WiFi-Netzwerk einloggen und 
* die Stellung der Weichen &uuml;ber die Steuerblock-LEDs anzeigen.   

### Funktionstest an den Schaltbl&ouml;cken
Durch Dr&uuml;cken der Taster an den vier Schaltbl&ouml;cken k&ouml;nnen folgende Funktionen getestet werden:   
* Entkuppler: Magnet zieht an   
* Zweiwegweiche: Hin- und Herschalten   
* Dreiwegweiche: Weiche auf "Links" - "Mitte" - "Rechts" stellen   
* Abschaltbares Gleis: Fahrspannung ein- und ausschalten   

### DCC-Funktionstest
Zus&auml;tzlich zum direkten Test sollte noch ein Funktionstest mit DCC (oder MQTT) durchgef&uuml;hrt werden. Dazu ist an einem DCC-Eingabeger&auml;t (zB der Multimaus)   
* die DCC-Adresse 11 zu w&auml;hlen und der Entkuppler ein- und auszuschalten,   
* die DCC-Adresse 21 zu w&auml;hlen und die Zweiwegweiche auf "Gerade" oder "Abzweig" zu stellen,   
* die DCC-Adresse 31 zu w&auml;hlen und die Dreiwegweiche auf "Links" oder "Mitte" zu stellen,   
* die DCC-Adresse 32 zu w&auml;hlen und die Dreiwegweiche auf "Rechts" oder "Mitte" zu stellen,   
* die DCC-Adresse 41 zu w&auml;hlen und der Fahrstrom des Abstellgleises ein- und auszuschalten. Dabei ist sicherzustellen, dass die beiden Schalter "Hand-Ein" und "Hand-Aus" am Schaltblock nicht gedr&uuml;ckt sind.   
* die DCC-Adresse 51 zu w&auml;hlen, um das Blinklicht ein- und auszuschalten.   

Sollte kein DCC-Eingabeger&auml;t aber daf&uuml;r ein Netzwerk mit MQTT-Broker zur Verf&uuml;gung stehen, so kann man die Funktion auch &uuml;ber MQTT testen. Dazu muss der PC (oder Laptop) mit dem WLAN `Raspi11` verbunden und ein Kommandofenster ge&ouml;ffnet werden. Durch Befehle dieser Art k&ouml;nnen die Bl&ouml;cke angesteuert werden:   

Einschalten des Entkupplers:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/11 -m 1`   

Stellen der Zweiwegweiche auf "Gerade":   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 1`   

Stellen der Zweiwegweiche auf "Abzweig":   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 0`   

usw. 

## 5.2 Beispiel: Test eines W2-Blocks
Waren alle Tests erfolgreich, k&ouml;nnen externe Bl&ouml;cke oder andere Komponenten gepr&uuml;ft werden.   
Zum Test eines W2-Blocks (Zweiwegweiche) m&uuml;ssen einfach das 10-polige Kabel (zum/vom I²C-Bus) und das 6-polige Kabel (zur/von der Weiche) direkt vom eingebauten W2-Block abgesteckt und beim Pr&uuml;fling nebeneinander eingesteckt werden. Als Letztes wird eine der freien Buchsenstecker des 6-poligen Stromversorgungskabels am Pr&uuml;fling angeschlossen (senkrecht stehender Stecker J3).   
Der Test erfolgt wieder wie oben beschrieben (Weiche schalten mit Taster und DCC).   

![Blocktester_Test_W2_1](./images/300_BT_Test_W2_1.png "Blocktester_Test_W2_1") ![Blocktester_Test_W2_2](./images/300_BT_Test_W2_2.png "Blocktester_Test_W2_2")   
_Bild 20: Test eines W2-Blocks_   

[Zum Seitenanfang](#up)


