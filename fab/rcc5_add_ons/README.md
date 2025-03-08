<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-02-22 <a name="up"></a><br>   
<h1>Add-on boards for the RCC system</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
Supplementary boards are boards that are not absolutely necessary for the operation of the RCC system, but make handling or wiring easier and clearer. For example, you can either tap the I²C signals of a block directly at the 10-pin connector J4 or use a 10-pin ribbon cable and the extension board `CON_10pol_PIN`.   
The following add-on boards are helpful and are described on this page:     
* [Bracket for switch blocks (RW_LEER_LED)](#x20)   
* [Traction current distributor (CON_2pol_141) ](#x30)   
* [Distributor board from 6-pin cable to 3 screw terminals (CON_6pol_3)](#x40)   
* [Distributor board from 6-pin cable to 6 screw terminals (CON_6pol_6)](#x50)   
* [Traction current switch simple (CON_1xIO)](#x60)   
* [Double traction current switch (CON_2xIO)](#x70)   
* [Distributor board from 10-pin cable to pins (CON_10pol_2x4)](#x80)   
* [Old distributor board from 10-pin cable to pins (CON_10pol_PIN)](#x90)   

<a name="x20"></a>   

# 2. Bracket for switch blocks (RW_LEER_LED)   
The bracket for switch blocks (block mounting board) is screwed with M 2,6 x 10 screws onto the frame of a railroad module and is used to attach a switching block (for points, uncouplers, traction current switches). It contains holes for LEDs and buttons/switches so that these can be inserted through the frame of the module to the operating side.   

![Mounted mounting board](/images/300_RW_LEER_LED.png "Mounting board mounted")   
_Figure 1: Mounting boards for switching blocks mounted on a 3D-printed frame_   

![Mounting board](/images/pcb_f/PCB_F_RW_LEER_LED_V1.png "Mounting board")   
_Figure 2: Mounting board for switching blocks_   

_*Board size*_: 41 x 41 mm²   
_*Link to the KiCad files*_: [/fab/kicad/SRW_LEER_LED_V1](/fab/kicad/RW_LEER_LED_V1)   

### Parts list   
| Quantity | Reference | Value | Note |   
|--------|----------------|------------------------|--------------------|   
| 2 | J1, J2 | 8-pin socket connector with short contacts | e.g. for [AliExpress](https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF) |   
| 4 | H1, H2, H3, H4 | spacer M2x10+3mm hexagonal brass male female | e.g. at [Amazon](https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) |   
| 4 | H1, H2, H3, H4 | Hexagon nuts M2x0.4 mm | e.g. at [Amazon](https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5) |   
| 4 | S1, S2, S3, S4 | Self-drilling screws M2.6 x 10 stainless steel 304 Black zinc plated Self-tapping Phillips pan head | e.g. at [Amazon](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp) |   

### Assembly   
1. soldering the two 8-pin female headers (with short contacts) at J1 and J2.   
2. fasten the four M2 HEX spacers M2x10+3mm with M2 nuts.   

### Versions
* V1 (241022): OK   

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. Traction current distributor `CON_2pol_141` 
This circuit board is used to distribute two-pole signals such as traction current.   

![CON_2pol_141](/images/200_CON_2pol_141.png "CON_2pol_141")   
_Figure 3: The assembled “CON_2pol_141” circuit board_   

![CON_2pol_141_circuit](/images/200_CON_2pol_141_circuit.png "CON_2pol_141_circuit")   
_Figure 4: Circuit diagram of the “CON_2pol_141” board_   

![Print distribution of two-pole signals](/images/pcb_f/PCB_F_CON_2pol_141_V1.png "Print distribution of two-pole signals")   
_Figure 5: Board for distributing two-pole signals_   

_*Board size*_: 57 x 21 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_2pol_141_V1](/fab/kicad/CON_2pol_141_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    6   | J1,J2,J3,J4,J5,J6 | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. screw terminal J1 to J6   

### Versions
* V1 (250117): OK   

[To the top of the page](#up)   
<a name="x40"></a>   

# 4. Distributor board from 6-pin cable to 3 screw terminals (CON_6pol_3)   
This board is used to connect a two-way crossover, so only pins 1, 3 and 5 are led out. The wires of the crossover can be screwed on directly, whereby the middle connection is the common return conductor.   
In version 2, the tub connector has been reversed so that the ribbon cable does not have to be twisted. This also reverses the order of the screw terminal pins.   

![CON_6pol_3_V1](/images/200_CON_6pol_3_V1.png "CON_6pol_3_V1") &nbsp; ![CON_6pol_3_V2](/images/200_CON_6pol_3_V2.png "CON_6pol_3_V2")   
_Figure 6: The assembled “CON_6pol_3” board V1 (left) and V2 (right)_   

![CON_6pol_3_circuit_V1](/images/200_CON_6pol_3_V1_circuit.png "CON_6pol_3_circuit_V1") &nbsp; ![CON_6pol_3_circuit_V2](/images/200_CON_6pol_3_V2_circuit.png "CON_6pol_3_circuit_V2")   
_Figure 7: Circuit diagrams of the “CON_6pol_3” board_   

![Terminal for two-way turnout V1](/images/pcb_f/PCB_F_CON_6pol_3_V1.png "Terminal for two-way turnout V1") &nbsp; ![Terminal for two-way turnout V2](/images/pcb_f/PCB_F_CON_6pol_3_V2.png "Terminal for two-way turnout V2")   
_Figure 8: Circuit board connection terminal for two-way turnout V1 (left) and V2 (right)_   

_*Board size*_: 25 x 18 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_6pol_3_V1](/fab/kicad/CON_6pol_3_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | 6-pin connector (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> e.g. from  [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6        | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. tub connector J5   
2. screw terminal J6   

### Versions
* V1 (241104): OK, suitable for 0° and 90° connectors, twist ribbon cable   
* V2 (250208): OK   

[To the top of the page](#up)   
<a name="x50"></a>   

# 5. Distributor board from 6-pin cable to 6 screw terminals (CON_6pol_6)   
This board is used, for example, to connect three-way turnouts, as these have two turnout drives. The pins are grouped: the first three pins (pin1, pin3, pin5) belong to the first turnout drive, the second three (pin2, pin4, pin6) to the second drive.   
In version 2, the tub connector has been reversed so that the ribbon cable does not have to be twisted. This also reverses the order of the screw terminal pins.   

![CON_6pol_6_V1](/images/200_CON_6pol_6_V1.png "CON_6pol_6_V1") &nbsp; ![CON_6pol_6_V2](/images/200_CON_6pol_6_V2.png "CON_6pol_6_V2")   
_Figure 9: The assembled “CON_6pol_6” board V1 (left) and V2 (right)_   

![CON_6pol_6_V1_circuit](/images/200_CON_6pol_6_V1_circuit.png "CON_6pol_6_V1_circuit") &nbsp; ![CON_6pol_6_V2_circuit](/images/200_CON_6pol_6_V2_circuit.png "CON_6pol_6_V2_circuit")   
_Figure 10: Circuit diagram of the “CON_6pol_6” board_   

![Terminal for three-way turnout V1](/images/pcb_f/PCB_F_CON_6pol_6_V1.png "Terminal for three-way turnout V1") &nbsp; ![Terminal for three-way turnout V2](/images/pcb_f/PCB_F_CON_6pol_6_V2.png "Terminal for three-way turnout V2")  
_Figure 11: Circuit boards for connection terminal for three-way diverter switch, V1 (left) and V2 (right)_   

_*Board size*_: 41 x 18 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_6pol_6_V1](/fab/kicad/CON_6pol_6_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | 6-pin connector (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> e.g. from  [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6, J7     | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

Note: Instead of the two 3-pole screw terminals, three 2-pole terminals can also be used...   

### Assembly   
1. tub connector J5   
2. screw terminal J6, J7   

### Versions
* V1 (241104): OK, suitable for 0° and 90° connectors, twist ribbon cable   
* V2 (250208): OK   

[To the top of the page](#up)   
<a name="x60"></a>   

# 6. Traction current switch simple (CON_1xIO)
This circuit board simplifies the connection of a traction current switch. It conducts the traction current to the 2IO block and makes the switched current signal available on a two-pole screw terminal.   

![CON_1xIO_V1](/images/200_CON_1xIO_V1.png "CON_1xIO_V1")  &nbsp; ![CON_1xIO_V2](/images/200_CON_1xIO_V2.png "CON_1xIO_V2")   
_Figure 12: The assembled “CON_1xIO” board V1 (left) and V2 (right)_   

![CON_1xIO_V1_circuit](/images/200_CON_1xIO_V1_circuit.png "CON_1xIO_V1_circuit")   
_Figure 13: Circuit diagram of the “CON_1xIO” board_   

![Print traction current connection V1](/images/pcb_f/PCB_F_CON_1xIO_V1.png "Print traction current connection V1") &nbsp; ![Print traction current connection V2](/images/pcb_f/PCB_F_CON_1xIO_V2.png "Print traction current connection V2")   
_Figure 14: Circuit boards for connecting the switched traction current_   

_*Board size*_: 32 x 21 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_1xIO_V1](/fab/kicad/CON_1xIO_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    1   | J1        | 6-pin connector (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> e.g. from  [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    3   | J3,J5,J6 | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. tub connector J1   
2. screw terminal J3, J5, J6   

### Versions
* V1 (250117): OK, suitable for 0° and 90° connectors, twist ribbon cable   
* V2 (250208): OK   

[To the top of the page](#up)   
<a name="x70"></a>   

# 7. Traction current switch double (CON_2xIO)
This circuit board simplifies the connection of traction current switches. It conducts the traction current to two 2IO blocks and makes the switched current signal available on two two-pole screw terminals.   

![CON_2xIO_V1](/images/200_CON_2xIO_V1.png "CON_2xIO_V1") &nbsp; ![CON_2xIO_V2](/images/200_CON_2xIO_V2.png "CON_2xIO_V2")   
_Figure 15: The assembled “CON_2xIO” board V1 (left) and V2 (right)_   

![CON_2xIO_circuit](/images/200_CON_2xIO_circuit.png "CON_2xIO_circuit")   
_Figure 16: Circuit diagram of the “CON_2xIO” board_   

![Print 2x traction current connection V1](/images/pcb_f/PCB_F_CON_2xIO_V1.png "Print 2x traction current connection V1") &nbsp; ![Print 2x traction current connection V2](/images/pcb_f/PCB_F_CON_2xIO_V2.png "Print 2x traction current connection V2")   
_Figure 17: Circuit boards for connecting two switched traction currents_   

_*Board size*_: 47 x 21 mm²   
_*Link to the KiCad files*_: [Version 1: /fab/kicad/CON_2xIO_V1](/fab/kicad/CON_2xIO_V1)   
[Version 2: /fab/kicad/CON_2xIO_V2](/fab/kicad/CON_2xIO_V2)    

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    2   | J1, J2    | 6-pin connector (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> e.g. from  [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    4   | J3,J4,J5,J6 | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. tub connector J1, J2   
2. screw terminal J3, J4, J5, J6   

### Versions
* V1 (250117): OK, suitable for 0° and 90° connectors, twist ribbon cable   
* V2 (250208): OK   

[To the top of the page](#up)   
<a name="x80"></a>   

# 8. Distributor board from 10-pin cable to pins (CON_10pol_2x4)   
This board is used to convert a 10-pin ribbon cable from the J4 switch block connector to pins. The pins are divided into two groups of four (input and output) to make it easier to connect to the pins of the PCF8574 I/O expander.   

![CON_10pol_2x4_V1](/images/300_CON_10pol_2x4_V1.png "CON_10pol_2x4_V1")   
_Figure 18: The assembled CON_10pol_2x4_circuit board_   

![CON_10pol_2x4_V1_circuit](/images/200_CON_10pol_2x4_V1_circuit.png "CON_10pol_2x4_V1_circuit")   
_Figure 19: Circuit diagram of the “CON_2xIO” board_   

![Print for distributing the lines of the 10-pin cable V1](/images/pcb_f/PCB_F_CON_10pol_2x4_V1.png "Print for distributing the lines of the 10-pin cable V1")   
_Figure 20: Board for distributing the lines of the 10-pin ribbon cable from J4_   

_*Board size*_: 30 x 15 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_10pol_2x4_V1](/fab/kicad/CON_10pol_2x4_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
| 1 | J1 | 10-pin connector (Box_02x05_P2.54_Vertical) | _kh_library:Box_02x05_P2.54mm_Vertical_kh <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
| 2 | J2, J3 | pin header 4-pin (Conn_01x04) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Preparation
* Cut four pins twice from a (e.g. 40-pin) straight pin header.   

### Assembly   
1. pin headers J2 to J5   
2. tub connector J1   

### Versions
* V1 (250208): OK   

[To the top of the page](#up)   
<a name="x90"></a>   

# 9. Old Distributor board from 10-pin cable to pins (CON_10pol_PIN)   
This circuit board is used to connect the 10-pin switching block input/output cable to the PCF8574-IO expander pins. The pins are grouped into four input and four output signals. There are also two connections each for 5V and ground. These are not normally required. Both the vertical and the angled version can be used as a 10-pin connector.   
The CON_10pol_2x4 board should be used instead of this board, as the 10-pin cable does not have to be twisted.   

![CON_10pol_PIN](/images/200_CON_10pol_PIN.png "CON_10pol_PIN")   
_Figure 21: The assembled “CON_10pol_PIN” board, once with a straight connector and once with a 90° rotated connector_   

![Terminal for I²C IO pins](/images/pcb_f/PCB_F_CON_10pol_PIN_V2.png "Terminal for I²C IO pins")   
_Figure 22: Board for distributing the lines of the 10-pin ribbon cable from J4 with 5V/0V-Pins_   

_*Board size*_: 33 x 15 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_10pol_PIN_V2](/fab/kicad/CON_10pol_PIN_V2)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
| 1 | J1 | 10-pin connector (Box_02x05_P2.54_Vertical) | _kh_library:Box_02x05_P2.54mm_Vertical_kh <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
| 2 | J2, J3 | pin header 4-pin (Conn_01x04) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 2 | J4, J5 | 2-pin pin header (Conn_01x02) | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   

### Assembly   
1. pin headers J2 to J5   
2. tub connector J1   

[To the top of the page](#up)   