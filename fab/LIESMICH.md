<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 20.7.2025 <a name="up"></a><br>   
<h1>Bauanleitungen f&uuml;r Module, Platinen und 3D-Teile</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Hier geht es direkt zur Inhalts&uuml;bersicht](#x05)   

# &Uuml;bersicht
Das Verzeichnis `fab` (f&uuml;r "_fabrication_") ist das "Fertigungszentrum" des RCC-Systems (RCC = Railway Component Control). Es enth&auml;lt Herstellungsdaten, Bauanleitungen, Zeichnungen und Beschreibungen von Teilen, die f&uuml;r das RCC-System ben&ouml;tigt werden. Die Daten sind auf folgende Unterverzeichnisse aufgeteilt:   

<a name="x05"></a>   

* [1. 3d](#x10)   
* [2. kicad](#x20)   
* [3. odg](#x30)   
* [4. rcc0_start](#x40)   
* [5. rcc1_supply](#x50)   
* [6. rcc2_esp3](#x60)   
* [7. rcc3_i2c](#x70)   
* [8. rcc4_block](#x80)   
* [9. rcc5_add_ons](#x90)   

Der folgende Text beschreibt den Inhalt der Verzeichnisse und enth&auml;lt Links zu den entsprechenden Anleitungen.   

<a name="x10"></a>   

# 1. 3d
Dieses Verzeichnis enth&auml;lt 3mf-Dateien f&uuml;r mechanische Bauteile, die mit einem 3D-Drucker hergestellt werden k&ouml;nnen. Beispiele sind   
<a name="x10"></a>   

* [Modulseite (Ost, West)](/fab/3d/LIESMICH.md#x10)   
* [Querverstrebung](/fab/3d/LIESMICH.md#x20)   
* [Sub-D-Stecker-Halterung](/fab/3d/LIESMICH.md#x30)   
* [OLED- und Taster-Einsatz](/fab/3d/LIESMICH.md#x40)   
* [Biegelehre f&uuml;r LEDs](/fab/3d/LIESMICH.md#x50)   
* [Weichenabdeckung f&uuml;r Zweiwegweiche](/fab/3d/LIESMICH.md#x60)   
* [Flache Weichenabdeckung f&uuml;r Zweiwegweiche](/fab/3d/LIESMICH.md#x70)   
* [Weichenabdeckung f&uuml;r Dreiwegweiche](/fab/3d/LIESMICH.md#x80)   

<a name="x20"></a>   

# 2. kicad
Dieses Verzeichnis enth&auml;lt die Kicad-Projekte aller Leiterplatten mit Schaltung und Platinenlayout. Mit dem Open Source [Layoutprogramm KiCad](https://www.kicad.org/) und zB dem Plug-in "PCBWay" kann man die dazugeh&ouml;rigen Leiterplatten bei einem Leiterplattenhersteller fertigen lassen.   

<a name="x30"></a>   

# 3. odg
Dieses Verzeichnis enth&auml;lt odg-Zeichnungen f&uuml;r allgemein g&uuml;ltige Informationen. Spezielle Zeichnungen, wie zum Beispiel die Cover der Beispiele und Module, sind bei den jeweiligen Projekten abgelegt.   
Die Bildschirm-Kopien von odg-Zeichnungen sind als png-Dateien abgespeichert und werden in den Markdown (.md)-Dokumenten angezeigt.   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. rcc0_start
Dieses Verzeichnis beschreibt die Dinge, die man ben&ouml;tigt, wenn man sich f&uuml;r den Selbstbau des RCC-Systems entschlossen hat:   
* [Welche Leiterplatten ben&ouml;tige ich und wie erstelle ich sie?](/fab/rcc0_start/LIESMICH.md#x20)   
* [Welche Bauteile ben&ouml;tige ich? (Grundausstattung an Bauteilen) ](/fab/rcc0_start/LIESMICH.md#x30)   
* [Welche Zukaufteile ben&ouml;tige ich?](/fab/rcc0_start/LIESMICH.md#x34)   
* [Welches Werkzeug ben&ouml;tige ich?](/fab/rcc0_start/LIESMICH.md#x36)   

Die Herstellung der RCC-Komponenten wird dann in den anderen Unterverzeichnissen dieses Verzeichnisses beschreiben.   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. rcc1_supply
In diesem Verzeichnis wird beschrieben, wie die Bl&ouml;cke zur Energieversorgung der Eisenbahnmodule nach NEM 908 gebaut werden. Dabei werden die Eigenschaften sowie die Best&uuml;ckung der Platinen erl&auml;utert, wie zum Beispiel   
* [Netzteil-Tr&auml;gerplatine (`AC_5V_6pol_DCC`)](/fab/rcc1_supply/LIESMICH.md#x22)   
* [Platine mit zwei 25-poligen Sub-D-Steckern und Netzteil (`RW_5V_2SUB25`)](/fab/rcc1_supply/LIESMICH.md#x32)   
* [Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (`RW_5V_SUB25_10`)](/fab/rcc1_supply/LIESMICH.md#x33)    
* [Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (`CON_SubD_Screw10`)](/fab/rcc1_supply/LIESMICH.md#x34)   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. rcc2_esp32
Die Steuerung des RCC-Systems (Railway Component Control) erfolgt mit einem "ESP32 D1 Mini" Multiprozessor und Zusatzplatinen. Die Zusatzplatinen dienen dazu, das DCC-Signal und den Taster einzulesen sowie die I²C-Busse f&uuml;r das Display und die PCF85745-Ein-Ausgabe-Expander bereitzustellen.   
In diesem Verzeichnis werden die Herstellung bzw. Best&uuml;ckung folgender Platinen beschrieben:   
* [ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)](/fab/rcc2_esp32/LIESMICH.md#x20)   
* [ESP32-Shield mit 5V-Versorgung, Taster und DCC (Shield_5V_DCC_6pol)](/fab/rcc2_esp32/LIESMICH.md#x30)   
* [das erweiterte I²C-Board `Shield_I2C_5V_3V3_big`](/fab/rcc2_esp32/LIESMICH.md#x40)   

[Zum Seitenanfang](#up)   
<a name="x70"></a>   

# 7. rcc3_i2c
In diesem Verzeichnis werden die I²C-Komponenten des Systems beschrieben, wie ZB   * [I²C-PCF8574-I/O-Platinen](/fab/rcc3_i2c/LIESMICH.md#x10)   
* [I²C-Halterung 20 mm](/fab/rcc3_i2c/LIESMICH.md#x20)   
* [I2C-LED-Platine](/fab/rcc3_i2c/LIESMICH.md#x40)   
* [I²C-Platine mit Pull-up-Widerst&auml;nden](/fab/rcc3_i2c/LIESMICH.md#x60)   

[Zum Seitenanfang](#up)   
<a name="x80"></a>   

# 8. rcc4_block
Auf dieser Seite wird - nach einigen allgemeinen Hinweisen zu Bl&ouml;cken - das Herstellen folgender Bl&ouml;cke beschrieben:   
* [Block Zweiwegweiche (W2)](/fab/rcc4_block/LIESMICH.md#x20)   
* [Block Dreiwegweiche (W3)](/fab/rcc4_block/LIESMICH.md#x30)   
* [Block Entkuppler (1OUT)](/fab/rcc4_block/LIESMICH.md#x40)   
* [Block Abschaltbares Gleis (2IO)](/fab/rcc4_block/LIESMICH.md#x50)   
* [Block Zweifachumschalter (DPDT)](/fab/rcc4_block/LIESMICH.md#x60)   

[Zum Seitenanfang](#up)   
<a name="x90"></a>   

# 9. rcc5_add_ons
In diesem Verzeichnis werden die Herstellung von Zusatzplatinen beschrieben.   
Diese Erg&auml;nzungsplatinen sind Platinen, die f&uuml;r den Betrieb des RCC-Systems nicht unbedingt notwendig sind, allerdings die Handhabung oder Verkabelung einfacher und &uuml;bersichtlicher machen. So kann man zB die I²C-Signale eines Blocks entweder direkt am 10-poligen Wannenstecker J4 abgreifen oder aber ein 10-poliges Flachbandkabel und das Erg&auml;nzungsboard `CON_10pol_PIN` verwenden.   
Unter anderem werden folgende Erg&auml;nzungsplatinen beschrieben:   
* [Halterung f&uuml;r Schaltbl&ouml;cke (RW_LEER_LED)](/fab/rcc5_add_ons/LIESMICH.md#x20)   
* [Fahrstromverteiler (CON_2pol_141)](/fab/rcc5_add_ons/LIESMICH.md#x30)   
* [Verteilerplatine von 6-poligem Kabel auf 3 Schraubklemmen (CON_6pol_3)](/fab/rcc5_add_ons/LIESMICH.md#x40)   
* [Verteilerplatine von 6-poligem Kabel auf 6 Schraubklemmen (CON_6pol_6)](/fab/rcc5_add_ons/LIESMICH.md#x50)   
* [Fahrstromschalter einfach (CON_1xIO)](/fab/rcc5_add_ons/LIESMICH.md#x60)   
* [Fahrstromschalter zweifach (CON_2xIO)](/fab/rcc5_add_ons/LIESMICH.md#x70)   
* [Verteilerplatine von 10-poligem Kabel auf Pins (CON_10pol_2x4)](/fab/rcc5_add_ons/LIESMICH.md#x80)   

[Zum Seitenanfang](#up)   