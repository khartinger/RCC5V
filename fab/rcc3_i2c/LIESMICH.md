<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 16.3.2025 <a name="up"></a><br>   
<h1>Herstellung von I²C-Platinen</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Die Anbindung der [Steuerbl&ouml;cke](/fab/rcc4_block) an den [ESP32-Mikrocontroller](/fab/rcc2_esp32) erfolgt &uuml;ber die I/O-Pins von zugekauften I²C-PCF8574-I/O-Platinen:   

![I²C-PCF8574-I/O-Prints](/images/300_pcf8574_boards.png "I²C-PCF8574-I/O-Prints")   
_Bild 1: I²C-PCF8574-I/O-Platinen_   

Mit den Jumpern kann die I²C-Adresse der Boards (im Bild links 0x20 und rechts 0x21) eingestellt werden.   

---   

Die hier beschriebenen Zusatzplatinen sind nicht unbedingt erforderlich, aber hilfreich, weil die PCF8574-Platinen zB keine Bohrungen f&uuml;r eine Befestigung haben und auch die Leitungen des I²C-Busses mit Pull-Up-Widerst&auml;nden abgeschlossen werden sollten.   
Folgende Prints sind derzeit verf&uuml;gbar:   
* [I²C-Halterung 20 mm](#x20)   
* [I²C-Halterung 40 mm](#x30)   
* [I2C-LED-Platine](#x40)   
* [I²C-Verteiler](#x50)   
* [I²C-Platine mit Pull-up-Widerst&auml;nden](#x60)   

<a name="x20"></a>   

# 2. I²C-Halterung 20 mm   
Auf den I²C-PCF8574-I/O-Platinen sind keine Befestigungsbohrungen vorgesehen. Die `CON_i2c_20mm`-Platine dient als 20 mm langes Zwischenst&uuml;ck zwischen zwei I²C-PCF8574-I/O-Platinen und hat eine Befestigungsbohrung.   

![CON_i2c_20mm_V1](/images/200_CON_i2c_20mm_V2.png "CON_i2c_20mm_V1")   
_Bild 2: Die best&uuml;ckte "CON_i2c_20mm"-Platine_   

![CON_i2c_20mm_circuit](/images/200_CON_i2c_20mm_circuit_V2.png "CON_i2c_20mm_circuit")   
_Bild 3: Schaltplan der "CON_i2c_20mm"-Platine_   

![Print i2c Halterung 20 mm](/images/pcb_f/PCB_F_CON_i2c_20mm_V2.png "Print i2c Halterung 20 mm")   
_Bild 4: Platine zum Festschrauben von I²C-Platinen_   

_*Platinengr&ouml;&szlig;e*_: 20 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_i2c_20mm_V2](/fab/kicad/CON_i2c_20mm_V2)   

## St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   |    J1     | 4-polige Stiftleiste 90° abgewinkelt | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    J2     | 4-polige Buchsenleiste mit langen Kontakten | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    C1     | 100 nF, 2,54 mm Raster |  |   

## Vorbereitung   
Die langen Kontakte der 4-poligen Buchsenleiste um 90° abbiegen.   

## Best&uuml;ckung   
Stift- und Buchsenleiste einstecken und anl&ouml;ten.    
Kondensator einl&ouml;ten.   

## Versionen
* V1 (250128): OK   
* V2 (250407): Pufferkondensator erg&auml;nzt (0,1 &mu;F ... 1 &mu;F)   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. I²C-Halterung 40 mm   
Auf den I²C-PCF8574-I/O-Platinen sind keine Befestigungsbohrungen vorgesehen. Die `CON_i2c_40mm`-Platine dient als 40 mm langes Zwischenst&uuml;ck zwischen zwei I²C-PCF8574-I/O-Platinen und hat zwei Befestigungsbohrungen.   

![CON_i2c_40mm_V1](/images/200_CON_i2c_40mm_V1.png "CON_i2c_40mm_V1")   
_Bild 5: Die best&uuml;ckte "CON_i2c_40mm"-Platine_   

![CON_i2c_20mm_circuit](/images/200_CON_i2c_20mm_circuit.png "CON_i2c_20mm_circuit")   
_Bild 6: Schaltplan der "CON_i2c_40mm"-Platine_   

![Print i2c Halterung 40 mm](/images/pcb_f/PCB_F_CON_i2c_40mm_V1.png "Print i2c Halterung 40 mm")   
_Bild 7: Platine zum Festschrauben von I²C-Platinen_   

_*Platinengr&ouml;&szlig;e*_: 40 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_i2c_40mm_V1](/fab/kicad/CON_i2c_40mm_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   |    J1     | 4-polige Stiftleiste 90° abgewinkelt | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    J2     | 4-polige Buchsenleiste mit langen Kontakten | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Vorbereitung   
Die langen Kontakte der 4-poligen Buchsenleiste um 90° abbiegen.   

### Best&uuml;ckung   
Stift- und Buchsenleiste einstecken und anl&ouml;ten.    

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. I2C-LED-Platine
Diese Platine enth&auml;lt eine LED mit Vorwiderstand und zwei Haltebohrungen. Die LED kann wahlweise auf Masse oder einen I²C-IO-Pin gelegt werden.   

![CON_i2c_LED_V1](/images/200_CON_i2c_LED_V1.png "CON_i2c_LED_V1")   
_Bild 8: Die best&uuml;ckte "CON_i2c_LED"-Platine_   

![CON_i2c_LED_circuit](/images/200_CON_i2c_LED_circuit.png "CON_i2c_LED_circuit")   
_Bild 9: Schaltplan der "CON_i2c_LED"-Platine_   

![Print i2c LED](/images/pcb_f/PCB_F_CON_i2c_LED_V1.png "Print i2c LED")   
_Bild 10: I²C-LED-Platine_   

_*Platinengr&ouml;&szlig;e*_: 30 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_i2c_LED_V1](/fab/kicad/CON_i2c_LED_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   |    D1     | LED rot 2mA       | LED_THT:LED_D3.0mm |   
|    1   |    R1     | Widerstand 680 &Omega; | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
|    1   |    J1     | 2-polige Stiftleiste | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   
|    1   |    J1     | Jumper (2-polig) |   |   
|    1   |    J2     | 4-polige Stiftleiste 90° abgewinkelt | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    J3     | 4-polige Buchsenleiste mit langen Kontakten | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Vorbereitung   
Die langen Kontakte der 4-poligen Buchsenleiste um 90° abbiegen.   

### Best&uuml;ckung   
1. Stiftleiste J2 und Buchsenleiste J3 einstecken und anl&ouml;ten   
2. rote LED D1   
3. Widerstand R1   
4. Stiftleiste J1   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. I²C-Verteiler
Die I²C-Verteilerplatine dient zum Parallelschalten mehrerer I²C-IO-Platinen, falls es Platzprobleme gibt.   

![CON_i2c_4x_V1](/images/200_CON_i2c_4x_V1.png "CON_i2c_4x_V1")   
_Bild 11: Die best&uuml;ckte "CON_i2c_4x"-Platine_   

![CON_i2c_4x_circuit](/images/200_CON_i2c_4x_circuit.png "CON_i2c_4x_circuit")   
_Bild 12: Schaltplan der "CON_i2c_4x"-Platine_   

![Print i2c 4x](/images/pcb_f/PCB_F_CON_i2c_4x_V1.png "Print i2c 4x")   
_Bild 13: 4x I²C-Platine_   

_*Platinengr&ouml;&szlig;e*_: 26 x 40 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_i2c_4x_V1](/fab/kicad/CON_i2c_4x_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    4   | J1, J2, J3, J4 | 2-polige Stiftleiste | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   
|    4   | J1, J2, J3, J4 | Jumper (2-polig) schwarz oder andere Farben |   |   
|    2   |  J5, J6   | 4-polige Stiftleiste 90° abgewinkelt | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    2   |  J7, J8   | 4-polige Buchsenleiste mit langen Kontakten | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Vorbereitung   
Die langen Kontakte der 4-poligen Buchsenleisten um 90° abbiegen.   

### Best&uuml;ckung   
1. Stiftleiste J5, J6 und Buchsenleiste J7, J8 einstecken und anl&ouml;ten   
2. Stiftleisten J1 bis J4   

Stecken der Jumper je nach Bedarf.   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. I²C-Platine mit Pull-up-Widerst&auml;nden
Dieses 20 mm lange Platine hat Platz f&uuml;r zwei 4,7 k&Omega; Widerst&auml;nde und einen Puffer-Kondensator.   

![CON_i2c_Term_V1](/images/200_CON_i2c_Term_V1.png "CON_i2c_Term_V1")   
_Bild 14: Die best&uuml;ckte "CON_i2c_Term"-Platine_   

![CON_i2c_Term_circuit](/images/200_CON_i2c_Term_circuit_V1.png "CON_i2c_Term_circuit")   
_Bild 15: Schaltplan der "CON_i2c_Term"-Platine_   

![Print i2c Term](/images/pcb_f/PCB_F_CON_i2c_Term_V1.png "Print i2c Term 20 mm") ![Print i2c Term V2](/images/pcb_f/PCB_F_CON_i2c_Term_V2.png "Print i2c Term 20 mm V2")   
_Bild 16: Platine zum Festschrauben von I²C-Platinen und Abschlusswiderst&auml;nde_   

_*Platinengr&ouml;&szlig;e*_: 20 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_i2c_Term_V1](/fab/kicad/CON_i2c_Term_V1)   

## St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   |    J1     | 4-polige Stiftleiste 90° abgewinkelt | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    J2     | 4-polige Buchsenleiste mit langen Kontakten | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   |    C1     | 100 nF, 2,54 mm Raster |  |   

## Vorbereitung   
Die langen Kontakte der 4-poligen Buchsenleiste um 90° abbiegen.   

## Best&uuml;ckung   
1. Stift- und Buchsenleiste einstecken und anl&ouml;ten.    
2. Widerst&auml;nde einl&ouml;ten.   
3. Kondensator einl&ouml;ten.   

## Versionen
* V1 (250407): OK   
* V2 (240426): R1 gestreckt, OK   

[Zum Seitenanfang](#up)   