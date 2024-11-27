<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 27.11.2024 <a name="up"></a><br>   
<h1>Steuern von Modellbahn-Komponenten mit DCC, MQTT und manuell</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# &Uuml;bersicht
Dieses Repository besch&auml;ftigt sich mit der Herstellung und Verwendung von Komponenten zur Steuerung von Weichen, Entkupplern, abschaltbaren Gleisen etc. auf einer elektrischen Modelleisenbahn mittels DCC, MQTT oder manuell.   
In zahlreichen Kapiteln werden folgende Themen bearbeitet:   

__Verwendung des Systems__   
* [Beispiel-Verdrahtung einer Weiche](/use/exampleTurnout2/LIESMICH.md)   
* ...   

__Informationen rund um das System__   
* [Elektrische Verbindung von Eisenbahn-Modulen nach NEM 908D](/info/con_NEM908/LIESMICH.md)   
* ...   

__Herstellung der System-Komponenten__   
* [KiCad-Dateien der RCC-Komponenten](/kicad/LIESMICH.md)   
* [Komponenten f&uuml;r die Stromversorgung](/fab/rcc1_supply/LIESMICH.md)   
* [ESP32-Shields](/fab/rcc2_esp32/LIESMICH.md)   
* ...   

Um die in diesem Repository vorgestellten Dinge optimal nutzen zu können, sind einige Vorkenntnisse von Vorteil:   
* Löten und etwas handwerkliches Geschick   
* Compilieren und Hochladen einer Datei auf den ESP32   
* Verwendung des Open Source [Platinenlayoutprogramms KiCad](https://www.kicad.org/)   
* Optional: Verwendung eines 3D-Druckers   

# Einleitung   
Zur Ansteuerung von Weichen, Entkupplern, abschaltbaren Gleisen usw. gibt es im Modelleisenbahnbau viele M&ouml;glichkeiten. Die einfachste Form ist das direkte Schalten der Wechselspannung.   

![RCC_5V_DirectSwitching](./images/300_RCC5V_DirectSwitching1.png "RCC_5V_DirectSwitching")   
_Bild 1: Direktes Schalten von Modellbahnkomponenten (Turnout = Weiche, Uncoupler = Entkupplungsgleis, Disconnectable Track = abschaltbares Gleis)_   

Nachteile dieser Variante sind, dass es keine R&uuml;ckmeldung bez&uuml;glich des Schaltzustandes gibt und auch eine Automatisierung nicht m&ouml;glich ist.   

Die hier vorgestellte, kosteng&uuml;nstige L&ouml;sung erm&ouml;glicht das Schalten von Modellbahnkomponenten auf m&ouml;glichst viele Arten (per Hand oder &uuml;ber DCC oder &uuml;ber WLAN mit MQTT-Befehlen). In der Standardausf&uuml;hrung sind bis zu 32 digitale Aus- und Eing&auml;nge vorhanden, sodass maximal 16 Zweiwegweichen oder 10 Dreiwegweichen etc. angesteuert werden k&ouml;nnen. Diese Anzahl ist im Normalfall f&uuml;r Module ausreichend.   

# Der Systembaufbau im &Uuml;berblick   
Das Railway-Component-Control-(RCC-) Gesamtsystem besteht aus sechs Teilen:   
1. __FEED-IN__ (Einspeisung): Einspeisung ins System mit DCC und Versorgungsspannung (hier Wechselspannung) durch externe Komponenten.   
2. __SUPPLY__ (Modulversorgung): Der 25-polige Stecker mit 5V-Stromversorgung sowie dem AC- und DCC-Anschluss.   
3. __&micro;C__ (Mikrocontroller): Der Mikrocontroller, ausgestattet mit zus&auml;tzlichen Shields, dient zur Steuerung des Moduls. Es wird ein ESP32 verwendet, der auch die Kommunikation mit dem MQTT-Broker &uuml;bernimmt.  
4. __I2C__: Verbindung zwischen dem Mikrocontroller und den Bedienbl&ouml;cken (RCC-Bl&ouml;cken). Dazu werden I2C-I/O-Expander-Boards mit PCF8574 verwendet.   
5. __RCC-Block__: Das Steuerelement f&uuml;r _eine_ Modellbahnkomponente mit lokalen Bedien- und Anzeige-Elementen.   
6. Die __Modellbahnkomponenten__ wie Weichen, Entkuppler und abschaltbare Gleise.   

![RCC5V_BlockDiagram1x](./images/150_RCC5V_BlockDiagramm_1x_V2.png "RCC5V_BlockDiagram1x")   
_Bild 2: Blockschaltbild Schalten von Eisenbahnkomponenten mit 5V_   

Durch die Verwendung der I2C-I/O-Expander-Boards ist es m&ouml;glich, mehrere Komponenten anzusteuern:   
![RCC5V_BlockDiagram3x](./images/300_RCC5V_BlockDiagramm_3x_V2.png "RCC5V_BlockDiagram3x")   
_Bild 3: Blockschaltbild Schalten von mehreren Eisenbahnkomponenten mit 5V_   

# Praktischer Aufbau
Das folgende Bild zeigt den Demo-Aufbau zur Ansteuerung einer Dreiwegweiche:   
![RCC5V_Demo_Setup](./images/480_RCC5V_DemoSetup.png "RCC5V_Demo_Setup")   
_Bild 4: Demo-Aufbau eines RCC-5V-Systems_   

Ganz links erkennt man den 25-poligen Stecker mit dem 5V-Netzteil ("SUPPLY"), dahinter befindet sich der ESP32 mit einem 1,56 Zoll Display ("&micro;C"). Vorne in der Mitte sind zwei I2C-PCF8574-Boards aufgebaut ("I2C"), dahinter der RCC-Block. Rechts sieht man eine Dreiwegweiche mit zwei Fleischmann-Weichenantrieben 640000. Die elektrische Verbindung der Baugruppen erfolgt durch 6-polige Flachbandkabel und Dr&auml;hte.   

# Beispiel: Schalten einer Weiche mit dem RCC5V-System
Das folgende Bild zeigt den elektrischen Schaltplan zur Ansteuerung einer Weiche mit DCC, MQTT oder manuell. Die hellgr&uuml;nen Rechtecke stellen in KiCad 8.0 entwickelte Platinen dar, die von [PCB Way](https://www.pcbway.com/) hergestellt wurden. Dazu installiert man in KiCad einfach das PlugIn von PCB Way und die &Uuml;bertragung der f&uuml;r die Produktion erforderlichen Daten erfolgt dann per Mausklick.   

![overall_circuit_diagram](./images/768_RCC5V_OverviewCircuitDiagram_241111.png "overall circuit diagram")   
_Bild 5: Gesamtschaltung des RCC-5V-Systems_   

Das obere Drittel des Bildes zeigt die Einspeisung des DCC-Signals und der Wechselspannung ("FEED-IN"). Das DCC-Signal f&uuml;r den Fahrstrom und das digitale Schalten der Weichen wird hier mit einer alten Roco-Multimaus erzeugt, zur Wechselspannungsversorgung dient ein 230V/18V/2,9A Trafo [(z.B. BV00/026 von Conrad)](https://www.conrad.at/de/p/bv00-026-hochleistungstransformator-230-v-404288.html?refresh=true).   

Im mittleren Drittel des Bildes ist die Verbindung des 25-poligen Steckers zum Mikrocontroller (5V und DCC-Signal) und zu den RCC-Bl&ouml;cken (5V und AC-Signal) dargestellt. Der ESP32 betreibt zwei getrennte I2C-Busse, einen f&uuml;r das 1,56"-OLED-Display (mit 3,3V) und den zweiten I2C-Bus f&uuml;r die PCF8574-Boards (mit 5V).   

Im unteren Drittel des Bildes ist schlie&szlig;lich die Ansteuerung einer Zweiweg-Weiche durch einen RCC-Block dargestellt.   
Der RCC-Block erh&auml;lt vom Mikrocontroller den Schaltbefehl "Gerade" (WSA auf 0V setzen) oder "Abzweig" (WSB=0V), schaltet die Weiche und liefert den Zustand der Weiche zur&uuml;ck (WRA=5V, WRB=0V f&uuml;r "Gerade" oder WRA=0V, WRB=5V f&uuml;r "Abzweig"). Weiters enth&auml;lt der RCC-Block zwei Taster zum lokalen Schalten der Weiche und zwei LEDs zur lokalen Anzeige des Schaltzustands der Weiche.   
Man erkennt auch, dass jeder RCC-Block zum Schalten der Weiche eine 5V- und eine Wechselspannung ben&ouml;tigt.   

[Zum Seitenanfang](#up)
