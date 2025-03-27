<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-03-08 <a name="up"></a><br>   
<h1>ESP32 Shields</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
The RCC system (Railway Component Control) is controlled by an “ESP32 D1 Mini” multiprocessor and additional boards. The additional boards are used to read in the DCC signal and the pushbutton and to provide the I²C buses for the display and the PCF85745 input/output expanders.   

## Overview of the additional boards
This page describes the production and assembly of the following additional boards:   
* [ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)](#x20)   
* [ESP32-Shield 5V supply, button and DCC (Shield_5V_DCC_6pol)](#x30)   
* [The extended I²C board `Shield_I2C_5V_3V3_big`](#x40)   

## The ESP32 processor
The ESP32 has two cores and therefore enough power to operate network communication and DCC monitoring as well as two I²C buses without interference.   

![ESP32](/images/300_ESP32.png "ESP32")   
_Figure 1: ESP32 D1 Mini with listed socket connectors_   

_Note:_ The sockets shown in yellow in _Fig. 1_ are those that are also used on the D1 mini (with processor ESP 8266).   

## Functional principle of the microcontroller circuit
The following figure shows the basic use of the inputs and outputs on the ESP32 processor:   

![ESP32 usage](/images/300_ESP32_use.png "ESP32 usage")   
_Figure 2: Inputs and outputs used on the ESP32 D1 Mini_   

* The DCC signal is made potential-free by the optocoupler and limited to 3.3 volts.   
* The button is used to select or advance the content shown on the display.   
* The WLAN antenna is already integrated on the ESP32-D1 mini board.   
* The 1.54” display is used to display the system status and is connected to the standard I²C bus.   

The digital inputs and outputs of the RCC blocks are connected to I²C IO expander boards with PCF8574. Using these boards and the display together repeatedly leads to system malfunctions, so a second I²C bus is used for the I²C-IO expander boards. This second I²C bus is operated with 5V.   

The functions are divided between two shields (for DCC and I²C), which are plugged onto the ESP32.   

### Single shields without OLED mounting
The following image shows the standard setup of the ESP32 with two shields in D1-mini format:   

![ESP32 with shields](/images/300_ESP32_with_shields.png "ESP32 with shields")   
_Figure 3: ESP32 with shields plugged in_   

On the lower shield you can see the connection for the button (sockets on the left) and the 6-pin plug for the “DCC” cable.   
On the upper shield you can see the four connectors for the IO-I²C bus at the front and the four sockets for the standard I²C bus to the display at the top center. The red board is the 3.3V/5V converter.   
The shields are described in more detail below.   

<a name="x15"></a>   

### Extended I²C shield
If you print a holder for the OLED display and the button with a 3D printer, you can create a unit consisting of display and microcontroller:   

![OLED and ESP32](/images/300_OLED_ESP32.png "OLED and ESP32")   
_Figure 4: OLED socket with I²C and DCC shield and ESP32 (from bottom to top)_   

In this case, the ESP32 does not have to be connected with a 4-pin cable and mounted separately on the frame.   
The extended I²C board [`Shield_I2C_5V_3V3_big` is described here](#x40).   

[To the top of the page](#up)   
<a name="x20"></a>   

# 2. ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)   
This board provides two I2C buses:   
* I2C bus 1 with SCL1=IO22=D1 and SDA1=IO21=D2 and 3.3V for connecting a 1.56” OLED display.   
* I2C bus 2 with SCL2=IO16=D4 and SDA2=IO17=D3 and 5V for connecting the PCF8574 IO expanders.   
The pin assignment of the connections is selected so that a display or the IO expander board can be easily connected (pin assignment I2C-1: SDA3-SCL3-3V3-GND and I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_V2.png "I2C shield")   
_Figure 5: “Shield_I2C_5V_3V3” board for connecting two I2C buses_   

_*Board size*_: 26.2 x 28.5 mm²   
_*Link to the KiCad files*_: [/fab/kicad/Shield_I2C_5V_3V3_V2](/fab/kicad/Shield_I2C_5V_3V3_V2)   

![Shield_I2C_5V_3V3](/images/300_Shield_I2C_5V_3V3.png "Shield_I2C_5V_3V3")   
_Figure 6: The assembled circuit board “Shield_I2C_5V_3V3”._   

![Shield_I2C_5V_3V3_circuit](/images/600_Shield_I2C_5V_3V3_circuit.png "Shield_I2C_5V_3V3_circuit")   
_Figure 7: Circuit diagram of the “Shield_I2C_5V_3V3” board_   

### Bill of materials   
| number | reference | value | use |   
|--------|--------------|------------------------|--------------------|   
| 1 | J1 | four-pin header, 90° angled (Conn_01x04_Pin) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J2 | four-pin socket connector with short contacts (Conn_01x04_Socket) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J3 | Level Converter Converter_2x_3V3_5V | 5V-3V 2-CH I2C IIC Logic-Level-Converter Module Bi-Directional | _kh_library:Converter_2x_3V3_5V |   
| 2 | J3 | four-pin header (straight) | |   
| 2 | U1 | Socket connector, 8-pin with long contacts | |   

### Preparation
* Cut down four pins from a (e.g. 40-pin) 90° angled pin header.   
* Cutting down 4 sockets from an 8-pin socket strip.   
* Attach the 4-pin male connectors, which are usually supplied with the level converter, to the level converter (see Fig. 8).   

![Shield_I2C_5V_3V3_comp](/images/300_Shield_I2C_5V_3V3_comp.png "Shield_I2C_5V_3V3_comp")   
_Figure 8: Components for the “Shield_I2C_5V_3V3” board_   

The picture clearly shows that the converter board has already been plugged into the two four-pin headers.   

### Assembly   
1. pin header J1 (90° angled)    
2. plug the two 4-pole pin headers into the converter and I2C board and extend them on both sides (converter board: components facing downwards, ensure correct polarity of the 3V/5V side)   
3. socket connectors J2 and U1   

### Versions
* V1 (241013): Labeling under the 90° pin header J1   
* V2 (241104): OK   

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. ESP32-Shield 5V supply, pushbutton and DCC (Shield_5V_DCC_6pol)
This board fulfills three tasks:   
* Connection of the 5V supply voltage (via the 6-pin connector J2).   
* Connection of the DCC signal to IO18=D5 (via the 6-pin connector J2).   
* Connection option for a push-button at IO19=D6 (via J1).   

![DCC and power shield](/images/pcb_f/PCB_F_Shield_5V_DCC_6pol.png "DCC and power shield")   
_Figure 9: “Shield_5V_DCC_6pol_V2” circuit board_   

_*Board size*_: 26,2 x 28,5 mm²   
_*Link to the KiCad files*_: [/fab/kicad/Shield_5V_DCC_6pol_V3](/fab/kicad/Shield_5V_DCC_6pol_V3)   

![Shield_5V_DCC_6pol](/images/300_Shield_5V_DCC_6pol.png "Shield_5V_DCC_6pol")   
_Figure 10: The assembled “Shield_5V_DCC_6pol” circuit board for connecting the 5V power supply, DCC signal and button_   

![Shield_5V_DCC_6pol_circuit](/images/600_Shield_5V_DCC_6pol_circuit.png "Shield_5V_DCC_6pol_circuit")   
_Figure 11: Circuit diagram of the “Shield_5V_DCC_6pol” board_   

### Bill of materials   
| number | reference | value | use |   
|--------|-----------|-------------------|--------------------|   
| 1 | C1 | Capacitor 1nF | Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm |   
| 1 | C2 | Capacitor 100nF | Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm |   
| 1 | D1 | Diode 1N4148 | Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp |   
| 1 | J1 | Pin header 2-pin 90° angled | Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical |   
| 1 | J2 | Connector 2x3 90° angled | _kh_library:Box_02x03_P2.54mm_Horizontal_mini_kh |   
| 1 | R1 | 1 k&Omega; | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical |   
| 1 | R3 | 1 k&Omega; | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | R2, R4 | 10 k&Omega; | Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical |   
| 2 | U1 | Socket connector, 8-pin with long contacts | _kh_library:WEMOS_D1_mini_kh_shield_2 |   
| 1 | U2 | Optocoupler 6N137 | Package_DIP:DIP-8_W7.62mm |   
| 1 | U2 | Socket DIL 8-pin | |   

![Shield_5V_DCC_6pol_comp](/images/300_Shield_5V_DCC_6pol_comp.png "Shield_5V_DCC_6pol_comp")   
_Figure 12: Components for the “Shield_5V_DCC_6pol” board_   

### Assembly   
1. 2-pole, angled pin header J1   
2. IC socket U2 (pay attention to polarity!)   
3. diode D1   
4. capacitors C1, C2   
5. resistors R1 to R4   
6. socket strips U1   
7. socket J1   

_Don't forget_: Insert optocoupler U2 into the socket...   

### Versions
* V1 (241013): C2 only for 2.54 mm grid   
* V2 (241108): With C2 at a distance of 5.08 mm through-hole plating instead of pin   
* V3 (241123): OK   

### Shield_5V_DCC_6pol and OLED socket
If the additional circuit board `Shield_5V_DCC_6pol` is used together with an OLED socket, the 12 mm stainless steel push-button should be mounted on it.   
1. shorten the connecting cables of the push-button to approx. 9 cm.   
2. cut two 1.5 cm long pieces of 2 mm heat-shrink tubing.   
3. push the pieces of heat-shrink tubing all the way up onto the connecting cables.   
4. cut 2 contacts from a socket strip with short contacts and tin them.   
5. solder the connecting cables to the socket strip.   
6. slide the heat-shrink tubing over the soldered joint and heat.   
7. slide the push-button into the OLED socket and screw it in place. Tighten with a 14 mm open-end wrench.   

[Stainless steel pushbutton](/images/300_pushbutton_parts.png "Stainless steel pushbutton")   
_Figure 13: Components for the stainless steel pushbutton_   

[To the top of the page](#up)   
<a name="x40"></a>   

# 4. The extended I²C board Shield_I2C_5V_3V3_big
This board provides two I²C buses:   
* __I2C bus no. 1__ with SCL1=IO22=D1 and SDA1=IO21=D2 and 3.3V for direct connection of a 1.56” OLED display.   
* __I2C bus no. 2__ with SCL2=IO16=D4 and SDA2=IO17=D3 and 5V for connecting the PCF8574 IO expander boards.   

The order of the pins for connections J4 to J6 is selected so that the display or the IO expander boards can be connected easily (pin assignment I2C-1: SDA3-SCL3-3V3-GND and I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_big_V2.png "I2C shield")   
_Figure 14: “Shield_I2C_5V_3V3_big” board for connecting the 5V and OLED I2C bus_   

Board size: 58 x 39 mm²   
_*Link to the KiCad files*_: [/fab/kicad/Shield_I2C_5V_3V3_big_V2](/fab/kicad/Shield_I2C_5V_3V3_big_V2)   

![Shield_I2C_5V_3V3_big](/images/300_Shield_I2C_5V_3V3_big.png "Shield_I2C_5V_3V3_big")   
_Figure 15: The assembled circuit board “Shield_I2C_5V_3V3_big”_   

![Shield_I2C_5V_3V3_big_circuit](/images/600_Shield_I2C_5V_3V3_big_circuit.png "Shield_I2C_5V_3V3_big_circuit")   
_Figure 16: Circuit diagram of the “Shield_I2C_5V_3V3_big” board_   

### Bill of materials   
| number | reference | value | use |   
|--------|-----------|-------------------|--------------------|   
|    2   | J5, J6 (J1)  | Four-pole, straight pin header (Conn_01x04_Pin) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J4 (J2)      | Four-pole socket strip with short contacts (Conn_01x04_Socket) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    1   | J3           | Converter_2x_3V3_5V | 5V-3V 2-CH I2C IIC Logic-Level-Converter Modul Bi-Directional | _kh_library:Converter_2x_3V3_5V |   
|    2   | J3           | Four-pole, straight pin header |   |   
|    2   | U1           | Eight-pole, straight pin header |   |   

### Note
The J1 and J2 connections are not normally equipped.   

### Preparation
* Split 8-pin pin header in the middle (= 2x 4 pins) or cut four pins twice from a (e.g. 40-pin) straight pin header.   
* Cut down 4 sockets from an e.g. 8-pin socket strip with short contacts.   
* Plug the two 4-pin pin headers (yellow), which are usually supplied with the level converter, onto the level converter board.   

![Shield_I2C_5V_3V3_big_comp](/images/300_Shield_I2C_5V_3V3_big_comp.png "Shield_I2C_5V_3V3_big_comp")   
_Figure 17: Components for the “Shield_I2C_5V_3V3_big” board_   

### Assembly   
1. plug the two yellow 4-pin headers into both the converter board and the I2C board and extend them on both sides of the component side of the print.  
   __Important__: Turn the converter board so that the components are facing downwards and the 3V and 5V connections are on the correct side!   
2. 8-pin pin headers Pin headers U1 facing downwards (on the left-hand side)   
3. 4-pin pin headers J5 and J6 downwards (on the long side), ensure vertical alignment!   
4. Move 4-pin female connector J4 to the component side, ensure vertical alignment!   
5. screw spacer bolt M2x10+3mm onto the long side   

### Versions
* V1 (240116/250116): Poor space allocation   
* V2 (250126): OK   

### Assembly   
The “Shield_I2C_5V_3V3_big” board is plugged onto the pre-assembled OLED socket with the component side (socket).   

![OLED_mount](/images/300_OLED_mount.png "OLED_mount")   
_Figure 18: pre-assembled OLED mount_   

![OLED_mount2](/images/300_OLED_mount_i2c_big.png "OLED_mount2")   
_Figure 19: “Shield_I2C_5V_3V3_big” board plugged onto OLED mount_   

The screw connection is made with M 2.6 x 8 mm screws.   

[To the top of the page](#up)   