<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-02-15 <a name="up"></a><br>   
<h1>Additional boards</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
The supplementary boards described here are used, for example, as a holder or for transferring ribbon cables with IDC connectors to pins or screw terminals.   

<a name="x20"></a>   

# 2 Block mounting board   
The block mounting board is screwed onto the frame of a railroad module and 
is used to attach a switching block (for points, uncouplers, traction current switches). It contains holes for LEDs and buttons/switches so that these can be inserted through the frame of the module to the operating side.   

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
| 4 | S1, S2, S3, S4 | Self-drilling screws M2.6 x 8 stainless steel 304 Black zinc plated Self-tapping Phillips pan head | e.g. at [Amazon](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp) |   

### Assembly   
1. soldering the two 8-pin female headers (with short contacts) at J1 and J2.   
2. fasten the four M2 HEX spacers M2x10+3mm with M2 nuts.   

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. distributor board from 10-pin cable to pins   
This board is used to connect the 10-pin switching block input/output cable to the PCF8574-IO expander pins. The pins are grouped into four input and four output signals. There are also two connections each for 5V and ground. These are not normally required. Both the vertical and the angled version can be used as a 10-pin connector.   

![CON_10pol_PIN](/images/200_CON_10pol_PIN.png "CON_10pol_PIN")   
_Figure 3: The assembled “CON_10pol_PIN” board, once with a straight connector and once with a 90° rotated connector_   

![Terminal for I²C IO pins](/images/pcb_f/PCB_F_CON_10pol_PIN_V2.png "Terminal for I²C IO pins")   
_Figure 4: Pins for I²C IO pins_   

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
<a name="x40"></a>   

# 4. distributor board from 6-pin cable to 3 screw terminals   
This board is used to connect a two-way crossover, so only pins 1, 3 and 5 are led out. The wires of the crossover can be screwed on directly, whereby the middle connection is the common return conductor.   

![CON_6pol_3](/images/200_CON_6pol_3a.png "CON_6pol_3")   
_Figure 5: The assembled “CON_6pol_3” board_   

![CON_6pol_3_circuit](/images/200_CON_6pol_3_circuit.png "CON_6pol_3_circuit")   
_Figure 6: Circuit diagram of the “CON_6pol_3” board_   

![Terminal for two-way turnout](/images/pcb_f/PCB_F_CON_6pol_3_V1.png "Terminal for two-way turnout")   
_Figure 7: Circuit board connection terminal for two-way turnout_   

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

[To the top of the page](#up)   
<a name="x50"></a>   

# 5. distributor board from 6-pin cable to 6 screw terminals   
This board is used, for example, to connect three-way turnouts, as these have two turnout drives. The pins are grouped: the first three pins (pin1, pin3, pin5) belong to the first turnout drive, the second three (pin2, pin4, pin6) to the second drive.   

![CON_6pol_6](/images/200_CON_6pol_6.png "CON_6pol_6")   
_Figure 8: The assembled “CON_6pol_6” board_   

![CON_6pol_6_circuit](/images/200_CON_6pol_6_circuit.png "CON_6pol_6_circuit")   
_Figure 9: Circuit diagram of the “CON_6pol_6” board_   

![Terminal for three-way turnout](/images/pcb_f/PCB_F_CON_6pol_6_V1.png "Terminal for three-way turnout")   
_Figure 10: Connection terminal for three-way diverter switch_   

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

[To the top of the page](#up)   
<a name="x60"></a>   

# 6. `CON_2pol_141` Traction current distributor
This circuit board is used to distribute two-pole signals such as traction current.   

![CON_2pol_141](/images/200_CON_2pol_141.png "CON_2pol_141")   
_Figure 11: The assembled “CON_2pol_141” circuit board_   

![CON_2pol_141_circuit](/images/200_CON_2pol_141_circuit.png "CON_2pol_141_circuit")   
_Figure 12: Circuit diagram of the “CON_2pol_141” board_   

![Print distribution of two-pole signals](/images/pcb_f/PCB_F_CON_2pol_141_V1.png "Print distribution of two-pole signals")   
_Figure 13: Board for distributing two-pole signals_   

_*Board size*_: 57 x 21 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_2pol_141_V1](/fab/kicad/CON_2pol_141_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    6   | J1,J2,J3,J4,J5,J6 | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. screw terminal J1 to J6   

[To the top of the page](#up)   
<a name="x70"></a>   

# 7. `CON_1xIO` Traction current switch simple
This circuit board simplifies the connection of a traction current switch. It conducts the traction current to the 2IO block and makes the switched current signal available on a two-pole screw terminal.   

![CON_1xIO](/images/200_CON_1xIO.png "CON_1xIO")   
_F_igure 14: The assembled “CON_1xIO” board_   

![CON_1xIO_circuit](/images/200_CON_1xIO_circuit.png "CON_1xIO_circuit")   
_Figure 15: Circuit diagram of the “CON_1xIO” board_   

![Print traction current connection](/images/pcb_f/PCB_F_CON_1xIO_V1.png "Print traction current connection")   
_Figure 16: Circuit board for connecting the switched traction current_   

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

[To the top of the page](#up)   
<a name="x80"></a>   

# 8. `CON_2xIO` Double traction current switch
This circuit board simplifies the connection of traction current switches. It conducts the traction current to two 2IO blocks and makes the switched current signal available on two two-pole screw terminals.   

![CON_2xIO](/images/200_CON_2xIO.png "CON_2xIO")   
_Figure 17: The assembled “CON_2xIO” board_   

![CON_2xIO_circuit](/images/200_CON_2xIO_circuit.png "CON_2xIO_circuit")   
_Figure 18: Circuit diagram of the “CON_2xIO” board_   

![Print 2x traction current connection](/images/pcb_f/PCB_F_CON_2xIO_V1.png "Print 2x traction current connection")   
_Figure 19: Circuit board for connecting two switched traction currents_   

_*Board size*_: 47 x 21 mm²   
_*Link to the KiCad files*_: [/fab/kicad/CON_2xIO_V1](/fab/kicad/CON_2xIO_V1)   

### Bill of materials
| Quantity | Reference | Value | Note, Footprint |   
|--------|-----------|-------------------|--------------------|   
|    2   | J1, J2    | 6-pin connector (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> e.g. from  [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    4   | J3,J4,J5,J6 | Screw terminal 3-pole (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> e.g. from [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Assembly   
1. tub connector J1, J2   
2. screw terminal J3, J4, J5, J6   

[To the top of the page](#up)   