<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 12.1.2025 <a name="up"></a><br>   
<h1>Bau des Moduls 12 "Ausweichstelle und Abstellgleis"</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Übersicht
Diese Anleitung beschreibt den Bau eines 100 x 25 cm² großen Gleis-Moduls M12 „Ausweichstelle und Abstellgleis“. Das Modul soll folgende Eigenschaften besitzen:   

|                |                                                    |   
|----------------|----------------------------------------------------|   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit und ohne Schotterbett |   
| Gleisbild      | 1x Dreiwegweiche, 2x Zweiwegweiche, 1x Entkuppler, 3x abschaltbarer Gleisabschnitt |   
| Elektrischer Anschluss | 2x 25-poliger SUB-D-Stecker (entsprechend NEM 908D, je 1x WEST und OST) |   
| Fahrstrom     | Analog oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | * Händisch direkt an der Modulvorderseite <br> * über DCC <br> * durch MQTT-Nachrichten (über WLAN) |   
| Bedienelemente | 1x Dreiwegweiche (Block W3, DCC 121 und 122) <br> 2x Zweiwegweiche (Block W2, DCC 123 und 128) <br> 1x Entkuppler (Block 1OUT, DCC 124) <br> 3x Fahrstrom (Block 2IO, DCC 125, 126 und 127) |   
| IP-Adresse Broker (Host) | 10.1.1.1 |   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   

# Inhaltsverzeichnis   
* [1. Vorbereitung - Einkauf](#x10)   
* [2. Bau des Modul-Rahmens](#x20)   
* [3. Aufbau des Gleisplans](#x30)   


[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# 1. Vorbereitung - Einkauf
## 1.1 Entwurf des Gleisplans
### 1.1.1 Allgemeines zu Gleisplänen
Beim Erstellen eines Gleisplans sind zwei Dinge zu beachten: das Lichtraumprofil und die Höhe des Gleisaufbaus. Das Lichtraumprofil gibt an, wieviel Platz (vor allem von langen Waggons) neben dem Gleis benötigt wird und ist bei engen Radien wichtig. Die Höhe des Gleisaufbaus (Bahnkörper) ist bei mehrstöckigen Anlagen oder Tunnels wichtig.   
Für den Radius R2 benötigt man eine Gesamt-Gleisbreite von 27 + 2 · 7 = 41 mm.   
![Lichtraumprofil](./images/300_lichtraumprofil.png "Lichtraumprofil")   
_Bild 1: Lichtraumprofil_   

Der Bahnkörper wird aus 5 mm Sperrholz und 3 mm Schaumstoff der Fa. Noch (95962 Gleisbett-Rolle N) hergestellt und mit Gleisschotter der Firma Fleischmann (9479) verfeinert.   
![Aufbau Bahnk&ouml;rper](./images/300_aufbau_bahnkoerper.png "Aufbau Bahnk&ouml;rper")   
_Bild 2: Aufbau des Bahnkörpers_   

Sollte 5 mm Sperrholz nicht zur Verfügung stehen, kann man auch 4 mm Sperrholz nehmen und unterhalb ein Millimeter dicken, selbst klebenden Kork hinaufkleben.   
Wenn man die __Breite des Bahndamms__ (Planum) mit 40 mm (oben) bzw. __50 mm__ (unten) annimmt, so ist das Lichtraumprofil in der Breite automatisch erfüllt.   
__Mindesthöhe im Tunnel__: 46 mm (Höhe ab Schwellenunterkante) + 3 mm (Schotterbett) + 5 mm (Bahndamm) = __54 mm__ ab der Grundplatte.   

### 1.1.2 Entwurf des Gleisplans
Der Entwurf des Gleisplans erfolgt in zwei Schritten:   
* Zuerst wird der Gleisplan so entworfen, dass er grundsätzlich den Anforderungen entspricht.   
* Im nächsten Schritt wird die Lage der Stromversorgungsstellen und Isolationsstellen festgelegt. Das kann dazu führen, dass zB Gleise in zwei Teile zerlegt werden müssen, damit man 2-polige Anschlusskabel (Fleischmann 22217) oder Isolierschienenverbinder (Fleischmann 9403) anbringen kann.   

Der folgende Gleisplan wurde mit dem Programm [AnyRail](https://www.anyrail.com/) gezeichnet.   
![M12 Gleisplan](./images/300_m12_gleisplan.png "M12 Gleisplan")   
_Bild 3: Gleisplan_   

Das 2. Gleis von links ist ein Gleis ohne Schotterbett mit der Länge 17,2 mm (22207). Die übrigen kurzen Gleise sind Gerade (9104) mit der Länge 27,75 mm. (Im Plan nicht gut lesbar.)   
Eine Besonderheit stellt das Gleis 9136 mit dem Kommentar "R4 9 Schwellen" dar: Hier wird ein Gleis 9136 zuerst links mit der Weiche verbunden und danach bei einem Winkel von 6,14° (= 9 Schwellen) "abgeschnitten".   

## 1.2 Schienenkauf - Stückliste
Zum Bau des Moduls werden folgende Gleise und Zubehör benötigt:   
| Anzahl | Nummer | Name | Euro/Stk | Euro |   
| :---: | :---: | :--- |  ---: |  ---: |   
| 1 | 22207 |  N Fleischmann, Gerade 17,2 mm | 2,00 | 2,00 |   
| 1 | 22210 | N Fleischmann, Aufgleisgerät gerade, 104,2 mm | 4,20 | 4,20 |   
| 8 | 9101 | Gerade 111 mm | 4,40 | 35,20 |   
| 1 | 9102 | Gerade 57,5 mm | 4,40 | 4,40 |   
| 1 | 9103 | Gerade 55, 5 mm | 4,40 | 4,40 |   
| 9 | 9104 | Gerade | 4,40 | 39,60 |   
| 2 | 9110 | Ausgleichsgleis gerade 83mm-111mm | 14,60 | 29,20 |   
| 1 | 9112 | Entkupplungsgleis gerade (mit Antrieb) | 31,90 | 31,90 |   
| 2 | 9116 | Prellbock 57,5 mm | 8,40 | 16,80 |   
| 1 | 9135 | Bogen Radius 430mm, Winkel 30° (R4) | 4,90 | 4,90 |   
| 3 | 9136 | Bogen Radius 430mm, Winkel 15° (R4) | 4,90 | 14,70 |   
| 1 | 9157 | Dreiwegweiche | 47,80 | 47,80 |   
| 1 | 9178 | Weiche links mit stromleitendem Herzstück | 29,90 | 29,90 |   
| 1 | 9179 | Weiche rechts mit stromleitendem Herzstück | 29,90 | 29,90 |   
| 4 | 640000 | Elektromagnetischer Weichenantrieb mit Endabschaltung | 25,60 | 102,40 |   
| 1 | 9403 | Isolierschienenverbinder | 6,90 | 6,90 |   
| 7 | 22217 | 2-poliges Anschlusskabel | 4,40 | 30,80 |   
   
Gesamtkosten 2025: ca. 435 Euro   

## 1.3 Holzkauf für Modul 100 x 25 cm²
Das Holz besorgt man sich am besten bei einem Baumarkt und lässt es gleich auf die folgenden Größen zuschneiden:   

__Pappelsperrholz 10 mm__   
| St&uuml;ck | Abmessung     | Kurz     | Verwendung             |   
|:-----:|:-------------:|:--------:|:-----------------------|   
|   1   | 980 x 230 mm² |     -    | Gelände-Grundplatte    |   
|   2   | 980 x 60 mm²  | Ra2, Ra4 | Rahmen außen Nord, Süd |   
|   2   | 250 x 70 mm²  | Ra1, Ra3 | Rahmen außen West, Ost |   
|   3   | 230 x 50 mm²  | Ri1      | Rahmen innen           |   

__Pappelsperrholz 5 mm (oder 4 mm)__   
| St&uuml;ck | Abmessung     | Anmerkung |   
|:-----:|:-------------:|:----------|   
|   1   | 980 x 250 mm² | Bahndamm  |   

Eventuell als zusätzliche Auflager für die Grundplatte: 4 kleine Holzstücken 10 x 10 x 50 mm³.   

## 1.4 Verbrauchsmaterial
Zum Bau des Moduls wird noch folgendes benötigt:   
| St&uuml;ck | Nummer | Lieferant  | Bezeichnung      |   
|:----------:|:------:|:-----------|:-----------------|   
|      1     |        | Ponal      | Holzleim Express |   
|      1     |  95962 | Noch       | Gleisbett-Rolle N 730 cm lang, 3,2 cm breit, 0,3 cm stark |   
|      1     |        | [Amazon](https://www.amazon.de/dp/B07S188DRJ?ref=ppx_yo2ov_dt_b_product_details&th=1) | Selbstklebende Korkplatte 1 mm dick, 30 x 21 cm² |   
|     28     |   |   | Senkkopfschrauben mit Kreuzschlitz 3,0 x 30mm |   

Damit der Holzrahmen nicht so leicht verstaubt, sollte er lackiert werden. Dazu benötigt man:   
| St&uuml;ck | Nummer | Lieferant  | Bezeichnung      |   
|:----------:|:------:|:-----------|:-----------------|   
|      1     | 4002364114016 | Albrecht   | Yacht- und Bootslack, farblos, hochglänzend |   
|      1     |   |   | Topfreiniger (Abwasch-Schwamm) |   
|      2     |   |   | Paar Einmal-Handschuhe         |   
|      1     |   |   | Schleifpapier Körnung 240      |   

## 1.5 Elektronische RCC-Komponenten
### 1.5.1 Steuerung
Für die Steuerung wird der ESP32 mit den beiden Zusatzplatinen (I²C, DCC) und dem 1,54"-OLED-Display verwendet. Der Zusammenbau ist auf   
[`https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/LIESMICH.md`](/fab/rcc2_esp32/LIESMICH.md)   
beschrieben.   

### 1.5.2 25-polige Stecker
Für den Anschluss der 25-poligen Stecker und für die Stromversorgung werden folgende bestückte Leiterplatten benötigt:   
* 1x [Netzteil-Platine AC_5V_supply_6pol_DCC](/fab/rcc1_supply/LIESMICH.md#x20)   
* 1x [Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (RW_5V_SUB25_10)](/fab/rcc1_supply/LIESMICH.md#x33)   
* 1x [Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (CON_SubD_Screw10)](/fab/rcc1_supply/LIESMICH.md#x34)   

Die bestückte Netzteil-Platine muss auf die Trägerplatine `RW_5V_SUB25_10` montiert werden.   

### 1.5.3 Ansteuerung der Schaltkomponenten
Für die Ansteuerung der Schaltkomponenten werden folgende Schaltblöcke benötigt:   
* 1x [Block Dreiwegweiche (W3)](/fab/rcc4_block/LIESMICH.md#x30)   
* 2x [Block Zweiwegweiche (W2)](/fab/rcc4_block/LIESMICH.md#x20)   
* 1x [Block Entkuppler (1OUT)](/fab/rcc4_block/LIESMICH.md#x40)   
* 3x [Block Abschaltbares Gleis (2IO)](/fab/rcc4_block/LIESMICH.md#x50)   

### 1.5.4 Verdrahtung
Zum Anschluss der Schaltkomponenten sinnvoll sind folgende Zusatzplatinen:   
...ToDo...

__Drähte und Leitungen__   
...ToDo...

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Bau des Modul-Rahmens   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Aufbau des Gleisplans   





# ...ToDo... ================================   

[Zum Seitenanfang](#up)