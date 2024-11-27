<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 27.11.2024 <a name="up"></a><br>   
<h1>Erweiterungen (Shields) für den ESP32</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Zur Steuerung des RCC-Systems (Railway Component Control) wird ein "ESP32 D1 Mini" Multiprozessor mit 2 Kernen verwendet. Dieser hat genügend Kapazität, um sowohl die Netzwerk-Kommunikation und die DCC-Überwachung als auch zwei I²C-Busse störungsfrei zu betreiben.   

![ESP32](/images/300_ESP32.png "ESP32")   
_Bild 1: ESP32 D1 Mini mit aufgelöteten Buchsenleisten_   

_Anmerkung:_ Die in _Bild 1_ gelb dargestellten Buchsen sind diejenigen, die auch beim D1 mini (mit Prozessor ESP 8266) verwendet werden.   

## Funktionsprinzip
Das folgende Bild zeigt die prinzipielle Verwendung der Ein- und Ausgänge am ESP32-Prozessor:   
![ESP32 usage](/images/300_ESP32_use.png "ESP32 usage")   
_Bild 2: Verwendete Ein- und Ausgänge am ESP32 D1 Mini_   

* Durch den Optokoppler wird das DCC-Signal potenzialfrei gemacht und auf 3,3 Volt begrenzt.   
* Der Taster dient zum Auswählen bzw. Weiterschalten von am Display angezeigten Inhalten.   
* Die WLAN-Antenne ist bereits auf dem ESP32-D1-Mini-Board integriert.   
* Das 1,54"-Display dient zur System-Zustandsanzeige und ist an den Standard-I²C-Bus angeschlossen.   

Die digitale Ein- und Ausgänge der RCC-Blocks sind an I²C-IO-Expander-Boards mit PCF8574 angeschlossen. Eine gemeinsame Verwendung dieser Boards und des Displays führt immer wieder zu System-Störungen, sodass für die I²C-IO-Expander-Boards ein zweiter I²C-Bus verwendet wird. Dieser zweite I²C-Bus wird mit 5V betrieben.   

Die Funktionen werden auf zwei Shields (für DCC und I²C) aufgeteilt, die auf den ESP32 aufgesteckt werden:   

![ESP32 with shields](/images/300_ESP32_with_shields.png "ESP32 with shields")   
_Bild 3: ESP32 mit aufgesteckten Shields_   

Beim unteren Shield erkennt man den Anschluss für den Taster (Buchsen links) sowie den 6-poligen Stecker für das "POWER"-Kabel.   
Beim oberen Shield sieht man vorne die vier Stecker für den IO-I²C-Bus und oben in der Mitte die vier Buchsen für den Standard-I²C-Bus zum Display. Die rote Platine ist der 3,3V/5V-Wandler.   
Nachfolgend werden die Shields genauer vorgestellt.   

<a name="x20"></a>   

# ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)   



# ... To Do ...

[Zum Seitenanfang](#up)   