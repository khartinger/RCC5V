<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-03-06 <a name="up"></a><br>   
<h1>Components for the power supply</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
The module supply (“SUPPLY”) provides the electrical means so that trains can run and points etc. can be switched on a railroad module. Each module requires three things for this:   

1. a supply voltage (AC voltage) for switching the railroad components (AC)   
2. a 5V voltage for the microcontroller and the logic of the switching blocks   
3. the traction current (line NN and SS with DCC signal or direct current)   

The following figure illustrates this connection and shows which components require which voltages.   

![supply overview](/images/300_RCC5V_Supply_Overview.png "supply overview")   
_Figure 1: Overview of the module supply_   

To keep the wiring effort to a minimum, the microcontroller and the RCC blocks are supplied via 6-pin ribbon cables. The pin assignment of the 6-pin cable to the microcontroller (“DCC”) and to the RCC blocks (“POWER”) is shown in the following figure:   
![connector_6pol](/images/100_6pol.png "connector_6pol")   
_Figure 2: Pin assignment of the 6-pin connector_   

<a name="x20"></a>   

# 2. Generation of the 5V voltage   
## 2.1 Circuit   
The 5V voltage is generated separately on each module from the supply voltage. To do this, the AC voltage is rectified, smoothed and converted down to 5V using an LM2596 DC-DC converter [(can be ordered from Amazon, for example)](https://www.amazon.de/dp/B0823P6PW6?ref=ppx_yo2ov_dt_b_fed_asin_title).   
The rectification and provision of the voltages via 6-pin cables is carried out via a single circuit board with the following circuit:   

![AC_5V_6pol_DCC_circuit](/images/300_AC_5V_6pol_DCC_circuit.png "AC_5V_6pol_DCC_circuit")   
_Figure 3: Circuit of the 5V, AC and DCC supply_   

* The AC voltage (AC+, AC-) and the DCC signal (WA, WB) are supplied to the board via J3.    
* D1, R1 and C1 effect the one-way rectification of the AC signal.   
* U1 represents the DC-DC board.  
* J1 and J2 are the 6-pin “DCC” and “POWER” connectors.   
* The connectors J5 and J6 are for simplification purposes only: This means that you do not have to use four individual sockets to connect the DC-DC converter board, but can use two 8-pin socket strips.   

## 2.2 The AC_5V_supply_6pol_DCC power supply board
The power supply board looks like this:   
![AC_5V_supply_6pol_DCC](/images/pcb_f/PCB_F_AC_5V_supply_6pol_DCC.png "AC_5V_supply_6pol_DCC")   
_Figure 4: Circuit board AC_5V_supply_6pol_DCC_   

_*Board size*_: 63.75 x 21.55 mm²   
_*Link to the KiCad files*_: [/fab/kicad/AC_5V_6pol_DCC_V1](/fab/kicad/AC_5V_6pol_DCC_V1)   

### Bill of materials   
| Quantity | Reference | Value | Footprint |   
|--------|------------|------------------------|--------------------|   
| 1 | R1 | Power resistor 4.7&Omega;/5W | Resistor_THT:R_Axial_Power_L25.0mm_W6.4mm_P27.94mm |   
| 1 | C1 | electrolytic capacitor 1000uF/35V | _kh_library:CP_Radial_L20.0mm_D10.0mm_P5.08mm_Horizontal |   
| 1 | D1 | Diode 1N4007 | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
| 2 | J1, J2 | 6-pin tub connector, vertical (Box_02x03_P2.54_Vertical_kh) | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
| 1 | J3, J5, J6 | 8-pin socket strip, long contacts (Conn_01x08) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
| 1 | U1 | DC-DC converter board StepDown_LM2596 | _kh_library:DCDC_StepDown_LM2596_PinsOnly |   
| 4 | U1 | 4 single pins | |   

### Assembly   
1. power resistor R1   
2. diode D1   
3. socket connectors J3, J5, J6   
4. socket connectors J1, J2   
5. electrolytic capacitor C1   

(*) If there are no pins connected to the corners of the LM2596 board:   
* Cut four individual pins from the pin header.   
* Insert 4 individual pins into the ends of J5 and J6, plug on the LM2596 board and leave the pins.   
6. plugging on the DC-DC step-down converter LM2596   

## 2.3 Commissioning the power supply driver board AC_5V_supply_6pol_DCC
_*Important:*_ When commissioning the DC-DC converter board for the first time, the output voltage on the potentiometer must be set to 5 V using a voltmeter and a screwdriver. Turning the screw on the potentiometer (blue quadrant) counterclockwise reduces the output voltage.   

Connection of the transformer: Pin 4 and 6 on the 6-pin connector J3 (POWER)   
Connection of the voltmeter: Pin 1 and 3 on the 6-pin connector J3 (POWER)   

![Adjusting 5V voltage](/images/300_adjust_5V.png "Adjusting the 5V voltage")   
_Figure 5: Adjusting the 5 V output voltage_   

## 2.4 Versions
* V1 (241013): OK   

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. connection of modules   
# 3.1 General   
According to NEM908D, model railroad modules are connected using cables with 25-pin Sub-D sockets. The modules therefore contain 25-pin Sub-D plugs. As modules can be of different lengths, there are two options for the module connector boards:   
(1) One board with two 25-pin connectors for short modules (e.g. 25 cm or 50 cm long).   
(2) Two circuit boards with a 25-pin plug and a 10-pin screw terminal strip for long modules (e.g. 75 cm or 100 cm long).   

The connection boards are designed so that the power supply board can be connected directly. 
![best&uuml;ckte PCB RW_5V_2SUB25](/images/300_RW_5V_2SUB25.png "best&uuml;ckte PCB RW_5V_2SUB25")   
_Figure 6: Connection board equipped with power supply unit with two 25-pin connectors_   

<a name="x32"></a>   

## 3.2 Board with two 25-pin D-sub connectors and power supply unit (RW_5V_2SUB25)   
This board is used to connect short modules with lengths of 25 cm or 50 cm. It contains connections for a 5V power supply unit and the DCC control signal as well as screw terminals for the DCC traction current (SS, NN and SN, NS) and the auxiliary lines OA and OB. The circuit board is designed so that it can be positioned symmetrically to a strut when installed in a module.   

![PCB RW_5V_2SUB25](/images/pcb_f/PCB_F_RW_5V_2SUB25_V4.png "PCB RW_5V_2SUB25")   
_Figure 7: Circuit board RW_5V_2SUB25_   

_*Board size*_: 80 x 66 mm²   
_*Mounting holes*_: 2.5 mm, distance 70 mm x 60 mm   
_*Link to the KiCad files*_: [/fab/kicad/RW_5V_2SUB25_V4](/fab/kicad/RW_5V_2SUB25_V4)   

### Bill of materials   
| Quantity | Reference | Value | Footprint |   
|--------|--------------|------------------------|--------------------|   
| 2 | J1, J2 | Sub-D connector 25-pin (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
| 3 | J7, J8, J10 | Screw terminal 2-pole black (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
| 1 | J9 | Screw terminal 2-pole green (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
| 1 | J5, J6, U1 | 5V power supply board | _kh_library:AC_5V_supply_6pol_PinsOnly |   

### Assembly   
1. screw terminals J10, J7 and J8, J9 plug together and solder   
2. sub-D connector J2   
3. plugging and unplugging the 5V power supply board into J5 and J6   
4. sub-D connector J1   

### Versions
* V1 (241029): OK   
* V2 (241123): OK (tracks swapped between component and power supply side)   
* V3 (250120): J10 added, holes for U1 too small   
* V4 (250306): OK

<a name="x33"></a>   

## 3.3 PCB with 25-pin D-sub connector, screw terminals and power supply unit (RW_5V_SUB25_10)
This board is used for longer modules (lengths of 75 cm or 100 cm) on one side. It contains connections for a 5V power supply unit and the DCC control signal as well as screw terminals for the DCC traction current (SS, NN and SN, NS), the auxiliary lines OA and OB and additionally for all signals. The board is designed so that it can be positioned symmetrically to a strut.   

![Platine RW_5V_SUB25_10](/images/pcb_f/PCB_F_RW_5V_SUB25_10_V1.png "RW_5V_SUB25_10")   
_Figure 8: Circuit board RW_5V_SUB25_10_   

_*Board size*_: 80 x 66 mm²   
_*Mounting holes*_: 2.5 mm, distance 70 mm x 60 mm   
_*Link to the KiCad files*_: [/fab/kicad/RW_5V_SUB25_10_V1](/fab/kicad/RW_5V_SUB25_10_V1)   

### Bill of Materials   
| Quantity | Reference | Value | Footprint |   
|--------|--------------|------------------------|--------------------|   
| 1 | J1 | Sub-D connector 25-pin (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
| 1 | J2 | Screw terminal 10-pin or 5x 2-pin | |   
| 1 | J7, J8, J9 | Screw terminal 2-pole (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
| 1 | J5, J6, U1 | 5V power supply board | _kh_library:AC_5V_supply_6pol_PinsOnly |   

### Assembly   
1. screw terminals J2, J7, J8, J9    
2. sub-D connector J1   
3. plugging and unplugging the 5V power supply board into J5 and J6   

### Versions
* V1 (241104): OK   
* V2 (250120): J10 added, holes for U1 too small   
* V3 (250306): OK

<a name="x34"></a>   

## 3.4 PCB with 25-pin D-sub connector and screw terminals (CON_SubD_Screw10)
This circuit board is used for longer modules (lengths of 75 cm or 100 cm) on one of the two sides (east or west). It only leads out the connections of the Sub-D connector to screw terminals.   

![Board CON_SubD_Screw10](/images/pcb_f/PCB_F_CON_SubD_Screw10_V1.png "CON_SubD_Screw10")   
_Figure 9: Board CON_SubD_Screw10_   

_*Board size*_: 31 x 66 mm²   
_*Mounting holes*_: 2.5 mm, distance 21 mm x 60 mm   
_*Link to the KiCad files*_: [/fab/kicad/CON_SubD_Screw10_V1](/fab/kicad/CON_SubD_Screw10_V1)   

### Bill of materials   
| Quantity | Reference | Value | Footprint |   
|--------|--------------|------------------------|--------------------|   
| 1 | J1 | Sub-D connector 25-pin (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
| 1 | J2 | Screw terminal 10-pin or 5x 2-pin | |   

### Assembly   
1. screw terminals J2    
2. sub-D connector J1   

### Versions
* V1 (241104): OK   

[To the top of the page](#up)   