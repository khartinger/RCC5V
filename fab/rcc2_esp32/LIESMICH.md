<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 8.3.2025 <a name="up"></a><br>   
<h1>Erweiterungen (Shields) f&uuml;r den ESP32</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Die Steuerung des RCC-Systems (Railway Component Control) erfolgt mit einem "ESP32 D1 Mini" Multiprozessor und Zusatzplatinen. Die Zusatzplatinen dienen dazu, das DCC-Signal und den Taster einzulesen sowie die I²C-Busse f&uuml;r das Display und die PCF85745-Ein-Ausgabe-Expander bereitzustellen.   

## &Uuml;bersicht &uuml;ber die Zusatzplatinen
Diese Seite beschreibt die Herstellung bzw. Best&uuml;ckung folgender Zusatzplatinen:   
* [ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)](#x20)   
* [ESP32-Shield 5V-Versorgung, Taster und DCC (Shield_5V_DCC_6pol)](#x30)   
* [Das erweiterte I²C-Board `Shield_I2C_5V_3V3_big`](#x40)   

## Der Prozessor ESP32
Der ESP32 hat zwei Kerne und damit gen&uuml;gend Leistung, um sowohl die Netzwerk-Kommunikation und die DCC-&Uuml;berwachung als auch zwei I²C-Busse st&ouml;rungsfrei zu betreiben.   

![ESP32](/images/300_ESP32.png "ESP32")   
_Bild 1: ESP32 D1 Mini mit aufgel&ouml;teten Buchsenleisten_   

_Anmerkung:_ Die in _Bild 1_ gelb dargestellten Buchsen sind diejenigen, die auch beim D1 mini (mit Prozessor ESP 8266) verwendet werden.   

## Funktionsprinzip der Mikrocontroller-Schaltung
Das folgende Bild zeigt die prinzipielle Verwendung der Ein- und Ausg&auml;nge am ESP32-Prozessor:   

![ESP32 usage](/images/300_ESP32_use.png "ESP32 usage")   
_Bild 2: Verwendete Ein- und Ausg&auml;nge am ESP32 D1 Mini_   

* Durch den Optokoppler wird das DCC-Signal potenzialfrei gemacht und auf 3,3 Volt begrenzt.   
* Der Taster dient zum Ausw&auml;hlen bzw. Weiterschalten von am Display angezeigten Inhalten.   
* Die WLAN-Antenne ist bereits auf dem ESP32-D1-Mini-Board integriert.   
* Das 1,54"-Display dient zur System-Zustandsanzeige und ist an den Standard-I²C-Bus angeschlossen.   

Die digitale Ein- und Ausg&auml;nge der RCC-Blocks sind an I²C-IO-Expander-Boards mit PCF8574 angeschlossen. Eine gemeinsame Verwendung dieser Boards und des Displays f&uuml;hrt immer wieder zu System-St&ouml;rungen, sodass f&uuml;r die I²C-IO-Expander-Boards ein zweiter I²C-Bus verwendet wird. Dieser zweite I²C-Bus wird mit 5V betrieben.   

Die Funktionen werden auf zwei Shields (f&uuml;r DCC und I²C) aufgeteilt, die auf den ESP32 aufgesteckt werden.   

### Einzel-Shields ohne OLED-Montage
Das folgende Bild zeigt den Standard-Aufbau des ESP32 mit zwei Shields im D1-mini-Format:   

![ESP32 with shields](/images/300_ESP32_with_shields.png "ESP32 with shields")   
_Bild 3: ESP32 mit aufgesteckten Shields_   

Beim unteren Shield erkennt man den Anschluss f&uuml;r den Taster (Buchsen links) sowie den 6-poligen Stecker f&uuml;r das "DCC"-Kabel.   
Beim oberen Shield sieht man vorne die vier Stecker f&uuml;r den IO-I²C-Bus und oben in der Mitte die vier Buchsen f&uuml;r den Standard-I²C-Bus zum Display. Die rote Platine ist der 3,3V/5V-Wandler.   
In nachfolgenden Kapiteln werden die Shields genauer vorgestellt.   

<a name="x15"></a>   

### Erweitertes I²C-Shield
Druckt man mit einem 3D-Drucker eine Halterung f&uuml;r das OLED-Display und den Taster, so kann man damit eine Einheit aus Anzeige und Mikrocontroller erzeugen:   

![OLED und ESP32](/images/300_OLED_ESP32.png "OLED und ESP32")   
_Bild 4: OLED-Fassung mit I²C- und DCC-Shield sowie ESP32 (von unten nach oben)_   

In diesem Fall muss der ESP32 nicht mit einem 4-poligen Kabel verbunden und extra auf dem Rahmen montiert werden.   
Das erweiterte I²C-Board [`Shield_I2C_5V_3V3_big` wird hier](#x40) beschrieben.   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# 2. ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)   
Diese Platine im D1-mini-Format stellt zwei I2C-Busse zur Verf&uuml;gung:   
* I2C-Bus 1 mit SCL1=IO22=D1 und SDA1=IO21=D2 und 3,3V zum Anschluss eines 1,56"-OLED-Displays.   
* I2C-Bus 2 mit SCL2=IO16=D4 und SDA2=IO17=D3 und 5V zum Anschluss der PCF8574-IO-Expander.   
Die Pinbelegung der Anschl&uuml;sse ist so gew&auml;hlt, dass sich ein Display bzw. die IO-Expander-Platinen leicht anschlie&szlig;en lassen (Pinbelegung I2C-1: SDA3-SCL3-3V3-GND und I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_V2.png "I2C shield")   
_Bild 5: Platine "Shield_I2C_5V_3V3" zum Anschluss zweier I2C-Busse_   

_*Platinengr&ouml;&szlig;e*_: 26,2 x 28,5 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/Shield_I2C_5V_3V3_V2](/fab/kicad/Shield_I2C_5V_3V3_V2)   

![Shield_I2C_5V_3V3](/images/300_Shield_I2C_5V_3V3.png "Shield_I2C_5V_3V3")   
_Bild 6: Die best&uuml;ckte Platine "Shield_I2C_5V_3V3"_   

![Shield_I2C_5V_3V3_circuit](/images/600_Shield_I2C_5V_3V3_circuit.png "Shield_I2C_5V_3V3_circuit")   
_Bild 7: Schaltplan der "Shield_I2C_5V_3V3"-Platine_   

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
* Aufstecken der 4-poligen Stiftleisten, welche meist mit dem Pegelwandler mitgeliefert werden, an den Pegelwandler (siehe Bild 8).   

![Shield_I2C_5V_3V3_comp](/images/300_Shield_I2C_5V_3V3_comp.png "Shield_I2C_5V_3V3_comp")   
_Bild 8: Bauteile f&uuml;r die "Shield_I2C_5V_3V3"-Platine_   

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
_Bild 9: Platine "Shield_5V_DCC_6pol_V2"_   

_*Platinengr&ouml;&szlig;e*_: 26,2 x 28,5 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/Shield_5V_DCC_6pol_V3](/fab/kicad/Shield_5V_DCC_6pol_V3)   

![Shield_5V_DCC_6pol](/images/300_Shield_5V_DCC_6pol.png "Shield_5V_DCC_6pol")   
_Bild 10: Die best&uuml;ckte Platine "Shield_5V_DCC_6pol" zum Anschluss von 5V-Spannungsversorgung, DCC-Signal und Taster_   

![Shield_5V_DCC_6pol_circuit](/images/600_Shield_5V_DCC_6pol_circuit.png "Shield_5V_DCC_6pol_circuit")   
_Bild 11: Schaltplan der "Shield_5V_DCC_6pol"-Platine_   

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
_Bild 12: Bauteile f&uuml;r die "Shield_5V_DCC_6pol"-Platine_   

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

### Shield_5V_DCC_6pol und OLED-Fassung
Wird die Zusatzplatine `Shield_5V_DCC_6pol` gemeinsam mit einer OLED-Fassung verwendet, so sollte auf dieser gleich der 12 mm Drucktaster aus Edelstahl montiert werden.   
1. Anschlussleitungen des Tasters auf ca. 9 cm k&uuml;rzen.   
2. Von einem 2 mm Schrumpfschlauch zwei 1,5 cm lange St&uuml;cke herunterschneiden.   
3. Die Schrumpfschlauch-St&uuml;cke auf die Anschlussleitungen ganz hinauf schieben.   
4. Von einer Buchsenleiste mit kurzen Kontakten 2 Kontakte herunterschneiden und verzinnen.   
5. Die Anschlussleitungen an die Buchsenleiste l&ouml;ten.   
6. Den Schrumpfschlauch &uuml;ber die L&ouml;tstelle schieben und erhitzen.   
7. Den Taster in die OLED-Fassung schieben und verschrauben. Mit einem 14-er Maul-Schl&uuml;ssel festziehen.   

![Edelstahl-Taster](/images/300_pushbutton_parts.png "Edelstahl-Taster")   
_Bild 13: Bauteile f&uuml;r den Edelstahl-Taster_   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Das erweiterte I²C-Board Shield_I2C_5V_3V3_big
Diese Platine stellt zwei I²C-Busse zur Verf&uuml;gung:   
* __I2C-Bus Nr. 1__ mit SCL1=IO22=D1 und SDA1=IO21=D2 und 3,3V zum direkten Anschluss eines 1,56"-OLED-Displays.   
* __I2C-Bus Nr. 2__ mit SCL2=IO16=D4 und SDA2=IO17=D3 und 5V zum Anschluss der PCF8574-IO-Expander-Platinen.   

Die Reihenfolge der Pins bei den Anschl&uuml;ssen J4 bis J6 ist so gew&auml;hlt, dass sich das Display bzw. die IO-Expander-Platinen leicht anschlie&szlig;en lassen (Pinbelegung I2C-1: SDA3-SCL3-3V3-GND und I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_big_V2.png "I2C shield")   
_Bild 14: Platine "Shield_I2C_5V_3V3_big" zum Anschluss des 5V- und OLED-I2C-Bus_   

_*Platinengr&ouml;&szlig;e*_: 58 x 39 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/Shield_I2C_5V_3V3_big_V2](/fab/kicad/Shield_I2C_5V_3V3_big_V2)   

![Shield_I2C_5V_3V3_big](/images/300_Shield_I2C_5V_3V3_big.png "Shield_I2C_5V_3V3_big")   
_Bild 15: Die best&uuml;ckte Platine "Shield_I2C_5V_3V3_big"_   

![Shield_I2C_5V_3V3_big_circuit](/images/600_Shield_I2C_5V_3V3_big_circuit.png "Shield_I2C_5V_3V3_big_circuit")   
_Bild 16: Schaltplan der "Shield_I2C_5V_3V3_big"-Platine_   

### St&uuml;ckliste   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|--------|--------------|------------------------|--------------------|   
|    2   | J5, J6 (J1)  | vierpolige, gerade Stiftleiste (Conn_01x04_Pin) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J4 (J2)      | vierpolige Buchsenleiste mit kurzen Kontakten (Conn_01x04_Socket) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J3           | Pegelwandler Converter_2x_3V3_5V | 5V-3V 2-CH I2C IIC Logic-Level-Converter Modul Bi-Directional | _kh_library:Converter_2x_3V3_5V |   
|    2   | J3           | vierpolige Stiftleiste (gerade) |   |   
|    2   | U1           | Stiftleiste, 8-polig |   |   

### Anmerkung
Die Anschl&uuml;sse J1 und J2 werden normalerweise nicht best&uuml;ckt.   

### Vorbereitung
* 8-polige Stiftleiste in der Mitte teilen (= 2x 4 Pins) oder Herunterschneiden von zweimal vier Pins von einer (zB 40-poligen) geraden Stiftleiste.   
* Herunterschneiden von 4 Buchsen von einer zB 8-poligen Buchsenleiste mit kurzen Kontakten.   
* Aufstecken der beiden 4-poligen Stiftleisten (gelb), welche meist mit dem Pegelwandler mitgeliefert werden, auf die Pegelwandler-Platine.   

![Shield_I2C_5V_3V3_big_comp](/images/300_Shield_I2C_5V_3V3_big_comp.png "Shield_I2C_5V_3V3_big_comp")   
_Bild 17: Bauteile f&uuml;r die "Shield_I2C_5V_3V3_big"-Platine_   

### Best&uuml;ckung   
1. Die beiden gelben 4-poligen Stiftleisten sowohl in die Konverter- als auch in in die I2C-Platine stecken und beidseitig auf der Bauteilseite des Prints verl&ouml;ten.  
   __Wichtig__: Die Konverter-Platine so drehen, dass die Bauteile nach unten zeigen und die 3V- und 5V-Anschl&uuml;sse auf der jeweils richtigen Seite sind!   
2. 8-polige Stiftleisten Stiftleisten U1 nach unten (auf L&ouml;tseite)   
3. 4-polige Stiftleisten J5 und J6 nach unten (auf L&ouml;tseite), auf senkrechte Ausrichtung achten!   
4. 4-polige Buchsenleiste J4 auf die Bauteilseite l&ouml;ten, auf senkrechte Ausrichtung achten!   
5. Abstandsbolzen M2x10+3mm auf die L&ouml;tseite schrauben   

### Versionen
* V1 (240116/250116): Schlechte Platzaufteilung   
* V2 (250126): OK   

### Montage   
Die "Shield_I2C_5V_3V3_big"-Platine wird mit der Bauteilseite (Buchse) auf die vormontierte OLED-Fassung aufgesteckt.   

![OLED_mount](/images/300_OLED_mount.png "OLED_mount")   
_Bild 18: vormontierte OLED-Fassung_   

![OLED_mount2](/images/300_OLED_mount_i2c_big.png "OLED_mount2")   
_Bild 19: "Shield_I2C_5V_3V3_big"-Platine auf OLED-Fassung aufgesteckt_   

Die Verschraubung erfolgt mit M 2,6 x 8 mm Schrauben.   

[Zum Seitenanfang](#up)   