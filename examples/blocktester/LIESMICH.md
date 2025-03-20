<table><tr><td><img src="./images/RCC5V_Logo_96.png
"></img></td><td>
Letzte &Auml;nderung: 20.3.2025 <a name="up"></a><br>   
<h1>Blocktester</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Link zur Inhalts&uuml;bersicht](#x05)   

# Worum geht es hier?
Diese Anleitung zeigt die Verwendung verschiedener Komponenten eines RCC-Systems (RCC: Railroad Control Components). Der Aufbau des Systems ist so gestaltet, dass Blöcke durch andere (gleichartige) ersetzt und so ihre Funktionsfähigkeit in einem funktionierenden Gesamtsystem getestet werden können.   

![Ansicht Blocktester 1](./images/300_BT_view_front2.png "Ansicht Blocktester 1")   
_Bild 1: Ansicht des Blocktesters von vorne oben_   

Die Größe des Systems ist mit 31 x 22 cm² so bemessen, dass es einfach in einer IKEA-Samla-Box 401.029.78 aufbewahrt werden kann.   

![Ansicht Blocktester IKEA](./images/300_BT_view_ikea.png "Ansicht Blocktester IKEA")   
_Bild 2: Blocktester in einer IKEA-Box_   

## Eigenschaften des Moduls
Das folgende Bild zeigt den Blocktester von oben. Man erkennt im Bild oben die Gleise mit den Weichenantrieben und dem Entkuppler, in der Mitte den Modulanschluss, die Anschlussplatinen für die Eisenbahn-Komponenten, die I²C-Platinen sowie unten den Mikrocontroller mit Shields und die Steuerblöcke (jeweils von links nach rechts).   

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
| Sonstiges | * Steuersoftware ist die Demo-Software |   

<a name="x05"></a>   

# Inhaltsverzeichnis   
* [1. Systemübersicht](#x10)   
* [2. Aufbau des Blocktesters](#x20)   
* [3. Software f&uuml;r den ESP32](#x30)   
* [4. Arbeiten mit dem Blocktester](#x40)   

[Zum Seitenanfang](#up)   
<a name="x10"></a>   

# ----- ToDo... ------

# 1. Systemübersicht




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


