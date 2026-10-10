<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Modul 15: Minimodul P20-Sub-D-Einspeisung</h1><b><big>Modul mit Einspeisung über Flachbandkabel oder Sub-D-Stecker</big></b><br>  
Stand: 10.10.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x01"></a>   

# Worum geht es?
**Modul 15** ist ein gerades, nur **25 cm × 25 cm** großes Modul ohne Elektronik und Schaltblöcke. Es ermöglicht die Einspeisung des Fahrstroms sowohl über den 25-poligen Sub-D-Stecker als auch über den 20-poligen Flachbandstecker **„P20“**.  

![Modul M15](./images/300_M15_Gleis_montiert1.png "Modul M15")   
_Bild: Rahmen mit Grundplatte und Gleisen._   

<a name="TableOfContents"></a>   
##  Inhalt
1. [Vorbereitung und Einkauf](#x10)  
2. [Rahmenbau](#x20)  
3. [Gleisbau](#x30)  
4. [Elektrik](#x40)  

## Eigenschaften des Moduls
|                |                                                    |   
|----------------|----------------------------------------------------|   
| Modulgröße     | 25 x 25 cm²                                        |   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit und ohne Schotterbett |   
| Gleisbild      | 1x Ausgleichsgleis, 2x 55,5 mm, 1x 45,5 mm |   
| Elektrischer Anschluss | * 2x 25-poliger SUB-D-Stecker (entsprechend NEM 908D, je 1x WEST und OST)   <br>* 2x 20-poliger Wannenstecker (auf der Rückseite) |   
| Fahrstrom     | Analog- oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | - |   
| Bedienelemente mit R&uuml;ckmeldung | - |   
| WLAN           | - |   
| MQTT: IP-Adresse des Brokers (Host) | - |    
| Sonstiges | * Einfaches Verbinden mit anderen Modulen durch ein ausziehbares Gleis am Segment-Ende |   

<a name="x10"></a>   
<a name="x11"></a>   

# 1. Vorbereitung und Einkauf

## 1.1 Schienenkauf
### 1.1.1 Entwurf des Gleisplans

Auf der Westseite befindet sich ein ausziehbares Gleis, das das Verbinden mit anderen Modulen erleichtert.  
Da die Modullänge von 25 cm nicht mit den Standardgleislängen von Fleischmann erreicht werden kann, muss ein gerades Gleis (z. B. 9103) auf **45,5 mm** gekürzt werden.  
Der folgende Gleisplan wurde mit [AnyRail](https://www.anyrail.com/) erstellt.  

![M15 Gleisplan](./images/300_m15_gleisplan.png "M15 Gleisplan")  
_Bild: Gleisplan Modul 15_  

Die braunen und roten Kreise markieren die Fahrstromeinspeisungen.  

### 1.1.2 Schienenkauf - St&uuml;ckliste
Zum Bau des Moduls werden folgende Gleise und Zubeh&ouml;r ben&ouml;tigt:   
| Anzahl | Nummer | Name | Euro/Stk | Euro |   
| :---: | :---: | :--- |  ---: |  ---: |   
| 1 | 9110 | Ausgleichsgleis gerade 83mm-111mm | 14,60 | 14,60 |   
| 3 | 9103 | Gerade 55, 5 mm | 4,40 | 13,20 |   

Gesamtkosten 2025: ca. 27,80 Euro   

<a name="x12"></a>   

## 1.2 Rahmen
### 1.2.1 Modulrahmen
Der 25 x 25 cm² gro&szlig;e Modulrahmen ist 6 cm hoch und besteht aus zwei Seitenteilen ("Ost" und "West") und zwei L&auml;ngsteilen ("Nord" und "S&uuml;d") ohne Querstreben. Die Gel&auml;ndeplatte wird in den Rahmen eingelegt.   
Die Teile des Rahmens k&ouml;nnen entweder aus Holz hergestellt oder mit dem 3D-Drucker gedruckt werden. Auch eine gemischte Bauweise ist m&ouml;glich, zB Seitenteile 3D-Drucken, L&auml;ngsteile aus Holz.   

### 1.2.2 Holz-Rahmen

#### Pappelsperrholz 10 mm
| St&uuml;ck | Abmessung     | Kurzbezeichnung | Verwendung             |   
|:-----:|:-------------:|:--------:|:-----------------------|   
|   1   | 230 x 230 mm² |     -    | Gel&auml;nde-Grundplatte    |   
|   2   | 230 x 60 mm²  | Ra2, Ra4 | Rahmen au&szlig;en Nord, S&uuml;d |   
|   2   | 250 x 70 mm²  | Ra1, Ra3 | Rahmen au&szlig;en West, Ost |   

#### Pappelsperrholz 5 mm (oder 4 mm)
| St&uuml;ck | Abmessung     | Anmerkung |   
|:-----:|:-------------:|:----------|   
|   1   | 50 x 250 mm² | Bahndamm  |   

#### Holzrahmen: Kleinteile
4x Pappelsperrholz 10 mm stark, 70 x 35 mm² f&uuml;r die Halterungen der Sub-D-Stecker.   
4x kleine Holzst&uuml;cken 10 x 10 x 50 mm³ als zus&auml;tzliche Auflager f&uuml;r die Grundplatte. 

#### Holzrahmen: Verbrauchsmaterial
| St&uuml;ck | Nummer | Lieferant  | Bezeichnung      |   
|:----------:|:------:|:-----------|:-----------------|   
|      1     |        | Ponal      | Holzleim Express |   
|      1     |  95962 | Noch       | Gleisbett-Rolle N 730 cm lang, 3,2 cm breit, 0,3 cm stark |   
|      1     |        | [Amazon](https://www.amazon.de/dp/B07S188DRJ?ref=ppx_yo2ov_dt_b_product_details&th=1) | Selbstklebende Korkplatte 1 mm dick, 30 x 21 cm² |   
|     28     |   |   | Senkkopfschrauben mit Kreuzschlitz 3,0 x 30mm |   
|      1     | 4002364114016 | Albrecht   | Yacht- und Bootslack, farblos, hochgl&auml;nzend |   
|      1     |   |   | Topfreiniger (Abwasch-Schwamm) |   
|      2     |   |   | Paar Einmal-Handschuhe         |   
|      1     |   |   | Schleifpapier K&ouml;rnung 240      |   

### 1.2.3 3D-Rahmen
2x Seitenteile: [`Rahmen_SeiteEingleisig_260906`]()  
1x Längsteil Nord: [``]()  
1x Längsteil Süd: [``]()  

Die Gelände-Grundplatte sollte aus Holz sein.

#### Pappelsperrholz 10 mm
| St&uuml;ck | Abmessung     | Kurzbezeichnung | Verwendung             |   
|:-----:|:-------------:|:--------:|:-----------------------|   
|   1   | 230 x 230 mm² |     -    | Gel&auml;nde-Grundplatte    |   


### 1.2.4 Kleinteile
8x Schraube M3 x 30 mm Senkkopf, Kreuzschlitz, selbstschneidend [``]()  (zB Fa. Spax 4 003530 021251)   

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Rahmenbau

## 2.1 Einleitung
Der Rahmen besteht aus vier Teilen:  

2x Seitenteil ``  
1x Vorderteil `Rahmen_Front_S__230mm_260408`  
1x Rückteil

[Zum Seitenanfang](#up)   