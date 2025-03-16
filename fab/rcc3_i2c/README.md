<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-03-16 <a name="up"></a><br>   
<h1>Manufacturing of i2c boards</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
The [control blocks](/fab/rcc4_block) are connected to the [ESP32 microcontroller](/fab/rcc2_esp32) via the I/O pins of purchased I²C PCF8574 I/O boards:   

![I²C-PCF8574-I/O-Prints](/images/300_pcf8574_boards.png "I²C-PCF8574-I/O-Prints")   
_Figure 1: I²C-PCF8574-I/O-Prints_   

The jumpers can be used to set the I²C address of the boards (0x20 on the left and 0x21 on the right in the picture).   

---   

The additional boards described here are not absolutely necessary, but are helpful because the PCF8574 boards do not have any holes for mounting, for example.   
The following prints are currently available:   
* [I²C holder 20 mm](#x20)   
* [I²C holder 40 mm](#x30)   
* [I2C LED board](#x40)   
* [I²C distributor](#x50)   

<a name="x20"></a>   

# 2. I²C holder 20 mm   
No mounting holes are provided on the I²C-PCF8574-I/O boards. The `CON_i2c_20mm` board serves as a 20 mm long intermediate piece between two I²C-PCF8574-I/O boards and has a mounting hole.   

![CON_i2c_20mm_V1](/images/200_CON_i2c_20mm_V1.png "CON_i2c_20mm_V1")   
_Figure 2: The assembled “CON_i2c_20mm” circuit board_   

![CON_i2c_20mm_circuit](/images/200_CON_i2c_20mm_circuit.png "CON_i2c_20mm_circuit")   
_Figure 3: Circuit diagram of the “CON_i2c_20mm” board_   

![Print i2c bracket 20 mm](/images/pcb_f/PCB_F_CON_i2c_20mm_V1.png "Print i2c bracket 20 mm")   
_Figure 4: Board for screwing down I²C boards_   

_*Board size*_: 20 x 15 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_i2c_20mm_V1](/fab/kicad/CON_i2c_20mm_V1)   

### Bill Of Materials   
| Quantity | Reference | Value | Use |   
|--------|-----------|-------------------|--------------------|   
| 1 | J1 | 4-pin pin header angled 90° | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J2 | 4-pin female connector with long contacts | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Preparation   
Bend the long contacts of the 4-pin socket strip by 90°.   

### Assembly   
Insert and solder the pin and socket strips.    

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. I²C holder 40 mm   
No mounting holes are provided on the I²C-PCF8574-I/O boards. The `CON_i2c_40mm` board serves as a 40 mm long intermediate piece between two I²C-PCF8574-I/O boards and has two mounting holes.   

![CON_i2c_40mm_V1](/images/200_CON_i2c_40mm_V1.png "CON_i2c_40mm_V1")   
_Figure 5: The assembled “CON_i2c_40mm” circuit board_   

![CON_i2c_20mm_circuit](/images/200_CON_i2c_20mm_circuit.png "CON_i2c_20mm_circuit")   
_Figure 6: Circuit diagram of the “CON_i2c_40mm” board_   

![Print i2c bracket 40 mm](/images/pcb_f/PCB_F_CON_i2c_40mm_V1.png "Print i2c bracket 40 mm")   
_Figure 7: Board for screwing down I²C boards_   

_*Board size*_: 40 x 15 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_i2c_40mm_V1](/fab/kicad/CON_i2c_40mm_V1)   

### Bill Of Materials   
| Quantity | Reference | Value | Use |   
|--------|-----------|-------------------|--------------------|   
| 1 | J1 | 4-pin pin header angled 90° | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J2 | 4-pin female connector with long contacts | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Preparation   
Bend the long contacts of the 4-pin socket strip by 90°.   

### Assembly   
Insert and solder the pin and socket strips.    

[To the top of the page](#up)   
<a name="x40"></a>   

# 4. I2C LED
This circuit board contains an LED with series resistor and two mounting holes. The LED can be connected to either ground or an I²C IO pin.   

![CON_i2c_LED_V1](/images/200_CON_i2c_LED_V1.png "CON_i2c_LED_V1")   
_Figure 8: The assembled “CON_i2c_LED” board_   

![CON_i2c_LED_circuit](/images/200_CON_i2c_LED_circuit.png "CON_i2c_LED_circuit")   
_Figure 9: Circuit diagram of the “CON_i2c_LED” board_   

![Print i2c LED](/images/pcb_f/PCB_F_CON_i2c_LED_V1.png "Print i2c LED")   
_Figure 10: I²C LED board_   

_*Board size*_: 30 x 15 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_i2c_LED_V1](/fab/kicad/CON_i2c_LED_V1)   

### Bill Of Materials   
| Quantity | Reference | Value | Use |   
|--------|-----------|-------------------|--------------------|   
| 1 | D1 | LED red 2mA | LED_THT:LED_D3.0mm |   
| 1 | R1 | Resistor 680 &Omega; | _kh_library:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical_kh |   
| 1 | J1 | 2-pin male connector | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   
| 1 | J1 | Jumper (2-pin) | |   
| 1 | J2 | 4-pin pin header angled 90° | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J3 | 4-pin female connector with long contacts | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Preparation   
Bend the long contacts of the 4-pin socket strip by 90°.   

### Assembly   
1. plug in and solder pin header J2 and socket connector J3   
2. red LED D1   
3. resistor R1   
4. pin header J1   

[To the top of the page](#up)   
<a name="x50"></a>   

# 5. I²C distributor
The I²C distributor board is used to connect several I²C IO boards in parallel if there are space problems.   

![CON_i2c_4x_V1](/images/200_CON_i2c_4x_V1.png "CON_i2c_4x_V1")   
_Figure 11: The assembled “CON_i2c_4x” board_   

![CON_i2c_4x_circuit](/images/200_CON_i2c_4x_circuit.png "CON_i2c_4x_circuit")   
_Figure 12: Circuit diagram of the “CON_i2c_4x” board_   

![Print i2c 4x](/images/pcb_f/PCB_F_CON_i2c_4x_V1.png "Print i2c 4x")   
_Figure 13: 4x I²C board_   

_*Board size*_: 26 x 40 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_i2c_4x_V1](/fab/kicad/CON_i2c_4x_V1)   

### Parts list   
| number | reference | value | use |   
|--------|-----------|-------------------|--------------------|   
| 4 | J1, J2, J3, J4 | 2-pin header | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   
| 4 | J1, J2, J3, J4 | Jumper (2-pin) black or other colors | |   
| 2 | J5, J6 | 4-pin pin header angled 90° | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 2 | J7, J8 | 4-pin female connector with long contacts | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Preparation   
Bend the long contacts of the 4-pin socket strips by 90°.   

### Assembly   
1. insert and solder pin header J5, J6 and socket connector J7, J8   
2. pin headers J1 to J4   

Insert the jumpers as required.   

[To the top of the page](#up)   