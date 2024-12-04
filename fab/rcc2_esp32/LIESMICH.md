<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 28.11.2024 <a name="up"></a><br>   
<h1>Erweiterungen (Shields) f&uuml;r den ESP32</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Zur Steuerung des RCC-Systems (Railway Component Control) wird ein "ESP32 D1 Mini" Multiprozessor mit 2 Kernen verwendet. Dieser hat gen&uuml;gend Kapazit&auml;t, um sowohl die Netzwerk-Kommunikation und die DCC-&Uuml;berwachung als auch zwei I²C-Busse st&ouml;rungsfrei zu betreiben.   

![ESP32](/images/300_ESP32.png "ESP32")   
_Bild 1: ESP32 D1 Mini mit aufgel&ouml;teten Buchsenleisten_   

_Anmerkung:_ Die in _Bild 1_ gelb dargestellten Buchsen sind diejenigen, die auch beim D1 mini (mit Prozessor ESP 8266) verwendet werden.   

## Funktionsprinzip
Das folgende Bild zeigt die prinzipielle Verwendung der Ein- und Ausg&auml;nge am ESP32-Prozessor:   

![ESP32 usage](/images/300_ESP32_use.png "ESP32 usage")   
_Bild 2: Verwendete Ein- und Ausg&auml;nge am ESP32 D1 Mini_   

* Durch den Optokoppler wird das DCC-Signal potenzialfrei gemacht und auf 3,3 Volt begrenzt.   
* Der Taster dient zum Ausw&auml;hlen bzw. Weiterschalten von am Display angezeigten Inhalten.   
* Die WLAN-Antenne ist bereits auf dem ESP32-D1-Mini-Board integriert.   
* Das 1,54"-Display dient zur System-Zustandsanzeige und ist an den Standard-I²C-Bus angeschlossen.   

Die digitale Ein- und Ausg&auml;nge der RCC-Blocks sind an I²C-IO-Expander-Boards mit PCF8574 angeschlossen. Eine gemeinsame Verwendung dieser Boards und des Displays f&uuml;hrt immer wieder zu System-St&ouml;rungen, sodass f&uuml;r die I²C-IO-Expander-Boards ein zweiter I²C-Bus verwendet wird. Dieser zweite I²C-Bus wird mit 5V betrieben.   

Die Funktionen werden auf zwei Shields (f&uuml;r DCC und I²C) aufgeteilt, die auf den ESP32 aufgesteckt werden:   

![ESP32 with shields](/images/300_ESP32_with_shields.png "ESP32 with shields")   
_Bild 3: ESP32 mit aufgesteckten Shields_   

Beim unteren Shield erkennt man den Anschluss f&uuml;r den Taster (Buchsen links) sowie den 6-poligen Stecker f&uuml;r das "DCC"-Kabel.   
Beim oberen Shield sieht man vorne die vier Stecker f&uuml;r den IO-I²C-Bus und oben in der Mitte die vier Buchsen f&uuml;r den Standard-I²C-Bus zum Display. Die rote Platine ist der 3,3V/5V-Wandler.   
Nachfolgend werden die Shields genauer vorgestellt.   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)   
Diese Platine stellt zwei I2C-Busse zur Verf&uuml;gung:   
* I2C-Bus 1 mit SCL1=IO22=D1 und SDA1=IO21=D2 und 3,3V zum Anschluss eines 1,56"-OLED-Displays.   
* I2C-Bus 2 mit SCL2=IO16=D4 und SDA2=IO17=D3 und 5V zum Anschluss der PCF8574-IO-Expander.   
Die Pinbelegung der Anschl&uuml;sse ist so gew&auml;hlt, dass sich ein Display bzw. die IO-Expander-Platine leicht anschlie&szlig;en l&auml;sst (Pinbelegung I2C-1: SDA3-SCL3-3V3-GND und I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_V2.png "I2C shield")   
_Bild 4: Platine "Shield_I2C_5V_3V3" zum Anschluss zweier I2C-Busse_   

_*Platinengr&ouml;&szlig;e*_: 26,2 x 28,5 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/Shield_I2C_5V_3V3_V2](/kicad/Shield_I2C_5V_3V3_V2)   

![Shield_I2C_5V_3V3](/images/300_Shield_I2C_5V_3V3.png "Shield_I2C_5V_3V3")   
_Bild 5: Die best&uuml;ckte Platine "Shield_I2C_5V_3V3"_   

![Shield_I2C_5V_3V3_circuit](/images/600_Shield_I2C_5V_3V3_circuit.png "Shield_I2C_5V_3V3_circuit")   
_Bild 6: Schaltplan der "Shield_I2C_5V_3V3"-Platine_   

### St&uuml;ckliste   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|--------|--------------|------------------------|--------------------|   
|    1   | J1           | vierpolige Stiftleiste, 90° abgewinkelt (Conn_01x04_Pin) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J2           | vierpolige Buchsenleiste mit kurzen Kontakten (Conn_01x04_Socket) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J3           | Pegelwandler Converter_2x_3V3_5V | 5V-3V 2-CH I2C IIC Logic-Level-Converter Modul Bi-Directional | _kh_library:Converter_2x_3V3_5V |   
|    2   | J3           | vierpolige Stiftleiste (gerade) |   |   
|    2   | U1           | Buchsenleiste, 8-polig mit langen Kontakten |   |   
   

### Vorbereitung
* Herunterschneiden von vier Pins von einer (zB 40-poligen) 90° abgewinkelten Stiftleiste.   
* Herunterschneiden von 4 Buchsen von einer 8-poligen Buchsenleiste.   
* Aufstecken der 4-poligen Stiftleisten, welche meist mit dem Pegelwandler mitgeliefert werden, an den Pegelwandler (siehe Bild 7).   

![Shield_I2C_5V_3V3_comp](/images/300_Shield_I2C_5V_3V3_comp.png "Shield_I2C_5V_3V3_comp")   
_Bild 7: Bauteile f&uuml;r die "Shield_I2C_5V_3V3"-Platine_   

Auf dem Bild erkennt man deutlich, dass die Converter-Platine bereits auf die beiden vierpoligen Stiftleisten gesteckt wurde.   

### Best&uuml;ckung   
1. Stiftleiste J1 (90° abgewinkelt)    
2. Die beiden 4poligen Stiftleisten in die Konverter- und I2C-Platine stecken und beidseitig verl&ouml;ten (Konverter-Platine: Bauteile nach unten, auf richtige Polung der 3V/5V-Seite achten)   
3. Buchsenleisten J2 und U1   

### Versionen
* V1 (241013): Beschriftung unter der 90°-Stiftleiste J1   
* V2 (241104): OK   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. ESP32-Shield 5V-Versorgung, Taster und DCC (Shield_5V_DCC_6pol)
Diese Platine erf&uuml;llt drei Aufgaben:   
* Anschluss der 5V-Versorgungsspannung (&uuml;ber den 6-poligen Stecker J2).   
* Anschluss des DCC-Signals an IO18=D5 (&uuml;ber den 6-poligen Stecker J2).   
* Anschlussm&ouml;glichkeit f&uuml;r einen Taster an IO19=D6 (&uuml;ber J1).   

![DCC and power shield](/images/pcb_f/PCB_F_Shield_5V_DCC_6pol.png "DCC and power shield")   
_Bild 8: Platine "Shield_5V_DCC_6pol_V2"_   

_*Platinengr&ouml;&szlig;e*_: 26,2 x 28,5 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/Shield_5V_DCC_6pol_V3](/kicad/Shield_5V_DCC_6pol_V3)   

![Shield_5V_DCC_6pol](/images/300_Shield_5V_DCC_6pol.png "Shield_5V_DCC_6pol")   
_Bild 9: Die best&uuml;ckte Platine "Shield_5V_DCC_6pol" zum Anschluss von 5V-Spannungsversorgung, DCC-Signal und Taster_   

![Shield_5V_DCC_6pol_circuit](/images/600_Shield_5V_DCC_6pol_circuit.png "Shield_5V_DCC_6pol_circuit")   
_Bild 10: Schaltplan der "Shield_5V_DCC_6pol"-Platine_   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | C1        | Kondensator 1nF   | Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm |   
|    1   | C2        | Kondensator 100nF | Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm |   
|    1   | D1        | Diode 1N4148      | Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
|    1   | J1        | Stiftleiste 2-polig 90° abgewinkelt | Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical |   
|    1   | J2        | Wannenstecker 2x3 90° abgewinkelt | _kh_library:Box_02x03_P2.54mm_Horizontal_mini_kh |   
|    1   | R1        | 1 k&Omega;        | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical |   
|    1   | R3        | 1 k&Omega;        | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | R2, R4    | 10 k&Omega;       | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
|    2   | U1        | Buchsenleiste, 8-polig mit langen Kontakten | _kh_library:WEMOS_D1_mini_kh_shield_2 |   
|    1   | U2        | Optokoppler 6N137   | Package_DIP:DIP-8_W7.62mm |   
|    1   | U2        | Fassung DIL 8-polig |   |   

![Shield_5V_DCC_6pol_comp](/images/300_Shield_5V_DCC_6pol_comp.png "Shield_5V_DCC_6pol_comp")   
_Bild 11: Bauteile f&uuml;r die "Shield_5V_DCC_6pol"-Platine_   

### Best&uuml;ckung   
1. 2-polige, abgewinkelte Stiftleiste J1   
2. IC-Fassung U2 (auf Polung achten!)   
3. Diode D1   
4. Kondensatoren C1, C2   
5. Widerst&auml;nde R1 bis R4   
6. Buchsenleisten U1   
7. Buchse J1   

_Nicht vergessen_: Optokoppler U2 in die Fassung stecken...   

### Versionen
* V1 (241013): C2 nur f&uuml;r 2,54 mm-Raster   
* V2 (241108): Bei C2 im Abstand 5,08 mm Durchkontaktierung statt Pin   
* V3 (241123): OK   

[Zum Seitenanfang](#up)   