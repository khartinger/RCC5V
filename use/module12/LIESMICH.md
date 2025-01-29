<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 12.1.2025 <a name="up"></a><br>   
<h1>Bau des Moduls 12 "Ausweichstelle und Abstellgleis"</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Direkter Sprung zur Inhalts&uuml;bersicht](#x05)   

# Übersicht
Diese Anleitung beschreibt den Bau eines 100 x 25 cm² großen Gleis-Moduls M12 „Ausweichstelle und Abstellgleis“. Das Modul soll folgende Eigenschaften besitzen:   

|                |                                                    |   
|----------------|----------------------------------------------------|   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit und ohne Schotterbett |   
| Gleisbild      | 1x Dreiwegweiche, 2x Zweiwegweiche, 1x Entkuppler, 3x abschaltbarer Gleisabschnitt |   
| Elektrischer Anschluss | 2x 25-poliger SUB-D-Stecker (entsprechend NEM 908D, je 1x WEST und OST) |   
| Fahrstrom     | Analog oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | * Händisch direkt an der Modulvorderseite <br> * über DCC <br> * durch MQTT-Nachrichten (über WLAN) |   
| Bedienelemente | 1x OLED-Display und Taster <br> 1x Dreiwegweiche (Block W3, DCC 121 und 122) <br> 2x Zweiwegweiche (Block W2, DCC 123 und 128) <br> 1x Entkuppler (Block 1OUT, DCC 124) <br> 3x Fahrstrom (Block 2IO, DCC 125, 126 und 127) |   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   
| MQTT: IP-Adresse des Brokers (Host) | `10.1.1.1` |   
<a name="x05"></a>   

# Inhaltsverzeichnis   
* [1. Vorbereitung - Einkauf](#x10)   
* [2. Bau des Modul-Rahmens](#x20)   
* [3. Aufbau des Gleisplans](#x30)   


[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# 1. Vorbereitung und Einkauf
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

Dunkelgraue Dreiecke stellen Gleisisolierungen dar (Isolierschuhe), braune und rote Kreise sind Fahrstromeinspeisungen.   
Das 2. Gleis von links ist ein Gleis ohne Schotterbett mit der Länge 17,2 mm (22207). Die übrigen kurzen Gleise sind Gerade (9104) mit der Länge 27,75 mm. (Im Plan schlecht lesbar.)   
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

## 1.3 Rahmen
### 1.3.1 Modulrahmen
Der 100 x 25 cm² große Modulrahmen ist 6 cm hoch und besteht aus zwei Seitenteilen ("Ost" und "West"), zwei Längsteilen ("Nord" und "Süd") sowie drei Querstreben. Die Geländeplatte wird in den Rahmen eingelegt.   
Die Teile des Rahmens können entweder aus Holz hergestellt oder mit dem 3D-Drucker gedruckt werden. Auch eine gemischte Bauweise ist möglich, zB Seitenteile und Querstreben 3D-Drucken, Längsteile aus Holz.   


### 1.3.2 Holzkauf für Modul 100 x 25 cm²
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

__Kleinteile__   
20x Schraube M3 x 30 mm Senkkopf, Kreuzschlitz, selbstschneidend (Fa. Spax 4 003530 021251)   
4x Pappelsperrholz 10 mm stark, 70 x 35 mm² für die Halterungen der Sub-D-Stecker.   
4x kleine Holzstücken 10 x 10 x 50 mm³ als zusätzliche Auflager für die Grundplatte.   

## 1.3.3 Verbrauchsmaterial
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

## 1.4 Elektronische RCC-Komponenten
### 1.4.1 Steuerung
Für die Steuerung wird der ESP32 mit den beiden Zusatzplatinen (I²C, DCC) und dem 1,54"-OLED-Display verwendet. Der Zusammenbau ist auf   
[`https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/LIESMICH.md`](/fab/rcc2_esp32/LIESMICH.md)   
beschrieben.   

### 1.4.2 Anschluss der 25-poligen Stecker
Für den Anschluss der 25-poligen Stecker und für die Stromversorgung werden folgende bestückte Leiterplatten benötigt:   
* 1x [Netzteil-Platine AC_5V_supply_6pol_DCC](/fab/rcc1_supply/LIESMICH.md#x20)   
* 1x [Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (RW_5V_SUB25_10)](/fab/rcc1_supply/LIESMICH.md#x33)   
* 1x [Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (CON_SubD_Screw10)](/fab/rcc1_supply/LIESMICH.md#x34)   

Die bestückte Netzteil-Platine muss auf die Trägerplatine `RW_5V_SUB25_10` montiert werden.   

### 1.4.3 Ansteuerung der Schaltkomponenten
Für die Ansteuerung der Schaltkomponenten werden folgende Schaltblöcke benötigt:   
* 1x [Block Dreiwegweiche (W3)](/fab/rcc4_block/LIESMICH.md#x30)   
* 2x [Block Zweiwegweiche (W2)](/fab/rcc4_block/LIESMICH.md#x20)   
* 1x [Block Entkuppler (1OUT)](/fab/rcc4_block/LIESMICH.md#x40)   
* 3x [Block Abschaltbares Gleis (2IO)](/fab/rcc4_block/LIESMICH.md#x50)   

### 1.4.4 I²C-Expander
* 4x [PCF8574 I/O-Expander](/fab/rcc0_start/LIESMICH.md#34)   

### 1.4.5 Verdrahtung
Zum Anschluss der Schaltkomponenten sinnvoll sind folgende Zusatzplatinen:   
...ToDo...

__Drähte und Leitungen__   
...ToDo...

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Bau des Modul-Rahmens   
## 2.1 Einleitung
Jedes Modul besteht aus einem Rahmen mit Querverbindungen und der Grundplatte, die die Gleise und Landschaft enthält. Zuerst sollte man den Modul-Rahmen erstellen. Das hat zwei Vorteile:   
1. Der Test, ob die Grundplatte in den Rahmen passt, kann mit der leeren Grundplatte erfolgen. Falls die Grundplatte zu groß ist, kann sie einfach zugeschnitten oder zugeschliffen werden.   
2. Beim Aufkleben der Gleise auf die Grundplatte sind an den Modulübergängen (Ost und West) bereits die Seitenteile mit den Gleisausnehmungen vorhanden. So sind die Gleise beim Aufkleben sicher an der richtigen Position.   

Das folgende Bild zeigt den Grundriss des Modulrahmens:   

![Modul-Rahmen](./images/300_module_frame.png "Modul-Rahmen")   
_Bild 4: AnyRail-Darstellung des Rahmengrundrisses mit den Außenteilen (Ra1 bis Ra4) und Querverstrebungen (Ri1, Ri2, Ri3)_

Die einzelnen Teile des Rahmens müssen vor dem Zusammenbau entspechend den nachfolgenden Beschreibungen bearbeitet werden.   

## 2.2 Seitenteile Ra1, Ra3 (West, Ost)
Die Seitenteile sind an eine (ehemalige?) Norm von n-spur.at angelehnt, wobei das Bahnkörper-Profil aber der NEM122 entspricht:   

![Modul_OstWest_1_Mitte.png](./images/300_OstWest_1_Mitte.png "Modul_OstWest_1_Mitte")   
_Bild 5: Maße für die Seitenteile Ost und West (Modulbreite 250mm, ein in der Mitte liegendes Gleis)._   

Die vier 8mm-Bohrungen dienen zum Verbinden der Module mit 8 mm-Flügelschrauben und Flügelmuttern.   
Die linken und rechten vier 2 mm-Bohrungen dienen zum Anschrauben der Nord- und Südwand. Sie müssen mit einem Kegelsenker erweitert werden, damit die Senkkopfschrauben nicht vorstehen.   
Die oberen zwei 2mm-Bohrungen dienen zum Fixieren der Gelände-Grundplatte (falls erforderlich). Auch sie müssen mit einem Kegelsenker erweitert werden, damit die Senkkopfschrauben nicht vorstehen.   
Die 60x20 mm²-Ausnehmung dient zum Durchführen des 25-poligen Sub-D-Steckers.   
Mit besonderer Vorsicht ist die Ausnehmung für das Gleis zu fertigen. Mit einer Laubsäge wird die Ausnehmung etwas zu klein ausgeschnitten und mit einer Dreiecksfeile so lange erweitert, bis ein Fleischmann-Schotterbett-Gleis gerade (klemmend) hineinpasst und auch mittig positioniert ist.   

## 2.3 Rahmenteil Ra2 (Nord)
Der Rahmenteil „Nord“ enthält lediglich dreimal zwei Bohrungen mit 2 mm Durchmesser, die wieder mit einem  Kegelsenker erweitert werden. Hier werden die Querverstrebungen verschraubt.   

![Modul_Nord_980mm](./images/300_Nord_980mm.png "Modul_Nord_980mm")   
_Bild 6: Seitenteil Nord Ra2_   

## 2.4 Seitenteil Ra4 (Süd)
Der Rahmenteil Süd enthält die Bohrungen für alle Steuerblöcke und die Querverstrebungen.   
Das Schaltbild der Dreiwegweiche W3 zeigt nach rechts (6 Bohrungen), das der ersten Zweiwegweiche W2 nach links unten (4 Bohrungen) und das des Entkupplers 1OUT nach rechts (4 Bohrungen). Es folgen die drei Schaltbilder für die Fahrstromabschaltung 2IO (7 Bohrungen) und das Schaltbild der zweiten Zweiwegweiche W2 nach rechts oben (4 Bohrungen).   

![Modul_Süd_980mm](./images/300_Sued_980mm.png "Modul_Süd_980mm")   
_Bild 7: Maße für den Rahmenteil Süd (Ra4)_   

Die genaue Lage der Bohrungen zeigt das folgende Bild:   

![Bohrposition LEDs und Taster](./images/300_drill_position_LED_button.png "Bohrposition LEDs und Taster")   
_Bild 8: Maße für die LED- und Taster-Bohrungen_   

Der Bohrdurchmesser für die LED-Fassungen beträgt 5,6 mm, der für die Taster ca. 7 mm.   

Die Aussparnugen für die OLED-Anzeige und den dazugehörigen Taster sind abhängig davon, ob man die Bauteile einzeln montiert oder einen 3D-Druck-Rahmen verwendet. Bei getrennter Montage benötigt man eine rechteckförmige Aussparung der Größe 20 x 38 mm² und eine 11,6 mm-Bohrung.   
![OLED_Button_single](./images/300_OLED_Button_single.png "OLED_Button_single")   
_Bild 9: Maße für die getrennte Montage der OLED-Anzeige und des Tasters_   

Bei Verwendung eines 3D-gedruckten Rahmens benötigt man eine rechteckförmige Aussparung der Größe 80 x 43 mm².   
![OLED_Button_frame](./images/300_OLED_Button_frame.png "OLED_Button_frame")   
_Bild 10: Maße für den Rahmen der OLED-Anzeige mit Taster_   

## 2.5 Querverstrebung Ri1 bis Ri3
Die Querverstrebungen enthalten verschiedene Durchbrüche für Kabel und zwei Bohrungen für die Halterung der 25-poligen Sub-D-Stecker.   

![Verstrebung](./images/300_Verstrebung_230mm.png "Verstrebung")   
_Bild 11: Querverstrebungen Ri1 bis Ri3_

## 2.6 Zusammenbau des Rahmens
Nachdem alle Teile des Rahmens bearbeitet wurden, kann dieser zusammengeschraubt werden.   


[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Aufbau des Gleisplans   





# ...ToDo... ================================   

[Zum Seitenanfang](#up)