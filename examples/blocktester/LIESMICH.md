<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 27.3.2025 <a name="up"></a><br>   
<h1>RCC-Blocktester</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Link zur Inhalts&uuml;bersicht](#x05)   

# Worum geht es hier?
Diese Anleitung beschreibt den Aufbau eines Testsystems für RCC-Komponenten (RCC: Railroad Control Components). Damit können Zweiweg- und Dreiwegweichen sowie Entkuppler und Fahrstromabschaltungen von Gleisen getestet werden. Das Testsystem ist so aufgebaut, dass alle Funktionen bereits vorhanden sind und funktionieren. Zum Testen einer neu gebauten Komponente setzt man diese im Testsystem ein und schaut, ob das System weiter funktioniert.   

![Ansicht Blocktester 1](./images/300_BT_view_front2.png "Ansicht Blocktester 1")   
_Bild 1: Ansicht des Blocktesters von vorne oben_   

Die Größe des Testsystems ist mit 31 x 22 cm² so gewählt, dass es einfach in einer IKEA-Samla-Box 401.029.78 aufbewahrt werden kann.   

![Ansicht Blocktester IKEA](./images/300_BT_view_ikea.png "Ansicht Blocktester IKEA")   
_Bild 2: Blocktester in einer IKEA-Box_   

## Eigenschaften des Moduls
Das folgende Bild zeigt den Blocktester von oben. Man erkennt im Bild oben die Gleise mit den Weichenantrieben und den Entkuppler (links).   
In der Mitte des Bildes sieht man links den Modulanschluss (Stromversorgung), die Anschlussplatinen für die Eisenbahn-Komponenten und die I²C-Platinen.   
Unten im Bild befindeen sich links der Mikrocontroller mit den Shields und daneben die verschiedenen Steuerblöcke.   

![Ansicht Blocktester oben](./images/600_BT_view_above.png "Ansicht Blocktester oben")   
_Bild 3: Blocktester von oben_   

|                |                                                    |   
| -------------- | -------------------------------------------------- |   
| Gleismaterial  | Fleischmann Spur-N-Gleis mit Schotterbett          |   
| Gleisbild      | 1x Entkuppler <br> 1x Zweiwegweiche <br> 1x Dreiwegweiche <br> 1x Abschaltbares Gleis <br> 1x Blinklicht |   
| Elektrischer Anschluss | 2x 25-poliger SUB-D-Stecker <br>(entsprechend NEM 908D, je 1x WEST und OST) |   
| Fahrstrom     | Analog- oder DCC-Betrieb |   
| Steuerung der Schaltkomponenten | * H&auml;ndisch direkt an der Modulvorderseite <br> * &uuml;ber DCC <br> * durch MQTT-Nachrichten (&uuml;ber WLAN) |   
| Bedienelemente mit R&uuml;ckmeldung | 1x Mikrocontroller mit OLED-Display und Taster <br> 1x Entkuppler (Block 1OUT, DCC 11) <br> 1x Zweiwegweiche (Block W2, DCC 21) <br> 1x Dreiwegweiche (Block W3, DCC 31 und 32) <br> 1x Abschaltbares Gleis bzw. Fahrstrom (Block 2IO, DCC 41)<br> 1x Blinklicht (DCC 51) |   
| WLAN           | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Passwort: `12345678` |   
| MQTT: IP-Adresse des Brokers (Host) | `10.1.1.1` |   
| Sonstiges | * Als Steuersoftware dient die Demo-Software |   

<a name="x05"></a>   

# Inhaltsverzeichnis   
* [1. Schaltung des Test-Systems](#x10)   
* [2. Aufbau des Blocktesters](#x20)   
* [3. Software f&uuml;r den ESP32](#x30)   
* [4. Arbeiten mit dem Blocktester](#x40)   

[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# 1. Schaltung des Testsystems
Das Testsystem ist so aufgebaut, dass alle Komponenten leicht ausgetauscht werden können und der praktische Einsatz der verschiedenen Platinen gezeigt wird.    
Das folgende Bild gibt eine Übersicht über die eingesetzten Komponenten:   
![Übersicht Testsystem](./images/600_overview_testsystem.png  "Übersicht Testsystem")   
_Bild 3: Übersichtsplan des Testsystems_   

`SUB25_10 ....` [Modul-Verbinder mit Netzteil](/fab/rcc1_supply/LIESMICH.md#x30)      
`uC_OLED .....` [Block OLED-Fassung mit I²C- und DCC-Shield sowie ESP32](/fab/rcc2_esp32/LIESMICH.md#x15)   

`1OUT ........` [Block zur Ausgabe der Wechselspannung](/fab/rcc4_block/LIESMICH.md#x40) zB für Entkuppler   
`W2 ..........` [Block zum Schalten einer Zweiwegweiche](/fab/rcc4_block/LIESMICH.md#x20)   
`W3 ..........` [Block zum Schalten einer Dreiwegweiche](/fab/rcc4_block/LIESMICH.md#x30)   
`2IO..........` [Block zum Schalten eines abschaltbaren Gleises](/fab/rcc4_block/LIESMICH.md#x50)   

`10pol_PIN....` Umsetzer vom 10-poligen Flachbandkabel auf 2x4 Pin [als ältere Version `CON_10pol_PIN`](/fab/rcc5_add_ons/LIESMICH.md#x90) bzw. [als neuere Version `CON_10pol_2x4`](/fab/rcc5_add_ons/LIESMICH.md#x80)   
`CON_6pol-3 ..` [Umsetzer vom 6-poligen Flachbandkabel auf 3 Pins](/fab/rcc5_add_ons/LIESMICH.md#x40)   
`CON_6pol-6 ..` [Umsetzer vom 6-poligen Flachbandkabel auf 6 Pins](/fab/rcc5_add_ons/LIESMICH.md#x50)   
`CON_1xIO ....` [Umsetzer vom 6-poligen Flachbandkabel auf Schraubklemmen](/fab/rcc5_add_ons/LIESMICH.md#x60) zum einfachen Anschluss des Fahrstroms.   

`i2c_40mm ....` [I²C-Halterung 40 mm](/fab/rcc3_i2c/LIESMICH.md#x30)   
`PCF8574 .....` [I²C-PCF8574-I/O-Platinen](/fab/rcc3_i2c/LIESMICH.md)   
`i2c_LED .....` [I2C-LED-Platine](/fab/rcc3_i2c/LIESMICH.md#x40)   


# ----- ToDo... ------


[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. Aufbau des Blocktesters

![Blocktester Beschriftung](./images/300_BT_cover.png "Blocktester Beschriftung")   
_Bild ..: Beschriftungen f&uuml;r die Steuerbl&ouml;cke_   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Software f&uuml;r den ESP32

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Arbeiten mit dem Blocktester


[Zum Seitenanfang](#up)


