<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 28.11.2024 <a name="up"></a><br>   
<h1>Wie starte ich das RCC-Projekt?</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Einleitung
Wenn ich mich dazu entschlossen habe, selbst die Steuerung meiner Modellbahn-Komponenten zu bauen, ist dazu etwas Zeit und Geld erforderlich. Es müssen sowohl Hardware- als auch 
Software-Voraussetzungen geschaffen werden.   
### Hardware
Für den Bau der RCC-Komponenten sind [Leiterplatten](#x20) ist eine Art ["Grundausstattung an Bauteilen"](#x30) erforderlich. Wie man dazu kommt, ist weiter unten beschrieben.   
### Software
An Software wird das Open Source [Layoutprogramm KiCad](https://www.kicad.org/) mit dem Plug-in "PCBWay" und Visual Studio Code mit dem Plugin "PlatformIO" benötigt.   
Mit Hilfe von KiCad können die Leiterplatten-Layouts an eigene Bedürfnisse angepasst bzw. einfach durch professionelle Leiterplattenhersteller wie zB die Firma PCBWay hergestellt werden.   
Visual Studio Code ist erforderlich, um die Steuersoftware an die eigenen Bedürfnisse anzupassen und auf den ESP32 zu laden.   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# Leiterplatten für RCC-Komponenten   
## Welche Leiterplatten benötige ich?
Welche Leiterplatten man benötigt, ist naturgemäß abhängig vom Anwendungsfall. Einige Platinen benötigt man aber auf jeden Fall.   

### Immer erforderliche Platinen
Immer erforderlich sind die beiden Shields für den ESP32,   
* [/kicad/Shield_5V_DCC_6pol_V3](/kicad/Shield_5V_DCC_6pol_V3)   
* [/kicad/Shield_I2C_5V_3V3_V2](/kicad/Shield_I2C_5V_3V3_V2)   
und die Gleichrichterplatine zur Erzeugung der 5V:   
* [/kicad/AC_5V_6pol_DCC_V1](/kicad/AC_5V_6pol_DCC_V1)   

Weiters sinnvoll ist die Halterungsplatine:   
* [/kicad/RW_LEER_LED_V1](/kicad/RW_LEER_LED_V1)   

Die Hilfsplatinen zum Anschließen der Weiche(n) und der Ein- und Ausgänge der PCF8574 sind praktisch, könnten aber auch durch das direkte Anstecken der Leitungen an den Blöcken umgangen werden.
* [/kicad/CON_10pol_PIN_V2](/kicad/CON_10pol_PIN_V2)   
* [/kicad/CON_6pol_3_V1](/kicad/CON_6pol_3_V1) für Zwei-Weg-Weiche   
* [/kicad/CON_6pol_6_V1](/kicad/CON_6pol_6_V1) für Drei-Weg-Weiche   

### Strom- bzw. Modulversorgung
Hier muss man zwischen der Versorgung mit oder ohne ein 25-poliges Kabel und über die Länge des Moduls unterscheiden.   
Für kurze Module (bis 50 cm) mit 25-poligem Kabel:
* [/kicad/RW_5V_2SUB25_V2](/kicad/RW_5V_2SUB25_V2)   
Für lange Module (länger als 50 cm) mit 25-poligem Kabel:
* [/kicad/RW_5V_SUB25_10_V1](/kicad/RW_5V_SUB25_10_V1)   
* [/kicad/CON_SubD_Screw10_V1](/kicad/CON_SubD_Screw10_V1)   

Verwendet man keine 25-poligen SubD-Stecker, kann die Wechselspannung direkt an die Gleichrichterplatine und das DCC-Signal direkt an den DCC-Stecker der "Shield_5V_DCC_6pol_V3"-Platine angeschlossen werden.   

### Leiterplatten für RCC-Blöcke
RCC-Blöcke bestehen immer aus zwei Platinen: eine für die Steuerung (STRG) und eine für die Taster, Schalter und LED-Anzeige (LED).   

Möchte man __Zwei-Weg-Weichen__ schalten, so benötigt man die Platinen   
* [/kicad/RW_5V_W2_STRG_V2](/kicad/RW_5V_W2_STRG_V2)   
* [/kicad/RW_5V_W2_LED_V2](/kicad/RW_5V_W2_LED_V2)   

Möchte man __Drei-Weg-Weichen__ schalten, so benötigt man die Platinen   
* [/kicad/RW_5V_W3_STRG_V4](/kicad/RW_5V_W3_STRG_V4)   
* [/kicad/RW_5V_W3_LED_V4](/kicad/RW_5V_W3_LED_V4)   

Möchte man Gleise ein- und abschalten, so benötigt man die Platinen   
* [/kicad/RW_5V_2IO_STRG_V1](/kicad/RW_5V_2IO_STRG_V1)   
* [/kicad/RW_5V_2IO_LED_V2](/kicad/RW_5V_2IO_LED_V2)   

Möchte man Entkuppler betreiben, so benötigt man die Platinen   
* [/kicad/RW_5V_1OUT_STRG_V1](/kicad/RW_5V_1OUT_STRG_V1)   
* [/kicad/RW_5V_1OUT_LED_V2](/kicad/RW_5V_1OUT_LED_V2)   

## Vorgangsweise zur Erstellung der Leiterplatten
Folgende Vorgangsweise ist sinnvoll:   
1. Installation des Open Source [Layoutprogramm KiCad](https://www.kicad.org/) mit dem Plug-in "PCBWay".   
2. Herstellen der benötigten Leiterplatten   
Für jede Komponente gibt es im Verzeichnis /kicad die zur Herstellung der Leiterplatte [erforderlichen KiCad-Dateien](/kicad). Die Leiterplatten sind zweiseitig, durchkontaktiert und mit Siebdruck auf beiden Seiten entworfen. Möchte man die Leiterplatten selbst herstellen, sind entsprechende Anpassungen erforderlich.   
Möchte man die Leiterplatten dagegen zB von der Firma PCBWay fertigen lassen, ist folgende Vorgangsweise sinnvoll:   

1. Laden des KiCad-Projekts in KiCad (aus dem Verzeichnis /kikad holen)   
2. Starten des Leiterplatteneditors (oder Mausklick auf *.kicad_pcb-Datei)   
3. Mausklick auf das Icon PCBWay: Es werden die Leiterplatten-Daten an [https://www.pcbway.com](https://www.pcbway.com) geschickt und die Webseite der Firma öffnet sich im Browser.   
4. Nach kurzer Zeit werden im Browser die Vorder- und Rückseite der Leiterplatte angezeigt. Da die Kosten für 5 oder 10 Stück derzeit (Dezember 2024) gleich sind, sollte man bei "Quantity (single):" die Stückzahl auf 10 pcs ausbessern.   
5. Durch Anklicken der Schaltfläche "Save to cart" werden die Daten in den Warenkorb übertragen und durch die Firma PCBWay automatisch überprüft.   
6. Das KiCad-Projekt kann jetzt geschlossen werden und das nächste Projekt gestartet werden. Diese Schritte wiederholt man so lange, bis sich die Daten aller Leiterplatten im Warenkorb der Firma PCBWay befinden.   
7. Sind alle Leiterplatten überprüft, wählt man die Versandart und bezahlt die Ware. Hat man es eilig, kann man als Transportunternehmen "DHL Express" wählen, das ist zwar nicht sehr billig aber schnell, zuverlässig und die Paketverfolgung ist super.   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# Grundausstattung an Bauteilen   
Für die Herstellung der RCC-Komponenten werden sowohl mechanische als auch elektronische Bauteile benötigt. Im folgenden werden vor allem Links zu Amazon und AliExpress angeführt, obwohl es gerade bei diesen Verkaufsplattformen des öfteren vorkommt, dass die angeführten Seiten von Lieferanten nach einiger Zeit oft nicht mehr verfügbar sind.   
Viele der Bauteile, wie zB Schrauben, werden in größeren Gebinden verkauft, hier reicht es oft, ein Stück zu kaufen.  

## Mechanische Bauteile

| Anzahl | Stück | Bezeichnung | Quelle |   
| ------ | ----- | ----------- | ------ |   
|    

## Elektrische Bauteile



# Fertigen der Komponenten
Hat man - nach einiger Wartezeit - sowohl die Leiterplatten als auch die Bauteile zur Verfügung, geht es an das Herstellen der Komponenten.   


[Zum Seitenanfang](#up)   