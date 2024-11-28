<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2024-11-28 <a name="up"></a><br>   
<h1>ESP32 Shields</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction   
An “ESP32 D1 Mini” multiprocessor with 2 cores is used to control the RCC system (Railway Component Control). This has sufficient capacity to operate both the network communication and the DCC monitoring as well as two I²C buses without interference.   

![ESP32](/images/300_ESP32.png "ESP32")   
_Figure 1: ESP32 D1 Mini with listed socket connectors_   

_Note:_ The sockets shown in yellow in _Fig. 1_ are those that are also used on the D1 mini (with processor ESP 8266).   

## Functional principle
The following figure shows the basic use of the inputs and outputs on the ESP32 processor:   

![ESP32 usage](/images/300_ESP32_use.png "ESP32 usage")   
_Figure 2: Inputs and outputs used on the ESP32 D1 Mini_   

* The DCC signal is made potential-free by the optocoupler and limited to 3.3 volts.   
* The button is used to select or advance the content shown on the display.   
* The WLAN antenna is already integrated on the ESP32-D1 mini board.   
* The 1.54” display is used to display the system status and is connected to the standard I²C bus.   

The digital inputs and outputs of the RCC blocks are connected to I²C IO expander boards with PCF8574. Using these boards and the display together repeatedly leads to system malfunctions, so a second I²C bus is used for the I²C-IO expander boards. This second I²C bus is operated with 5V.   

The functions are divided between two shields (for DCC and I²C), which are plugged onto the ESP32:   

![ESP32 with shields](/images/300_ESP32_with_shields.png "ESP32 with shields")   
_Figure 3: ESP32 with shields plugged in_   

On the lower shield you can see the connection for the button (sockets on the left) and the 6-pin plug for the “DCC” cable.   
On the upper shield you can see the four connectors for the IO-I²C bus at the front and the four sockets for the standard I²C bus to the display at the top center. The red board is the 3.3V/5V converter.   
The shields are described in more detail below.   

[To the top of the page](#up)   
<a name="x20"></a>   

# 2. ESP32-Shield I²C-Bus (Shield_I2C_5V_3V3)   
This board provides two I2C buses:   
* I2C bus 1 with SCL1=IO22=D1 and SDA1=IO21=D2 and 3.3V for connecting a 1.56” OLED display.   
* I2C bus 2 with SCL2=IO16=D4 and SDA2=IO17=D3 and 5V for connecting the PCF8574 IO expanders.   
The pin assignment of the connections is selected so that a display or the IO expander board can be easily connected (pin assignment I2C-1: SDA3-SCL3-3V3-GND and I2C-2: SCL5-SDA5-GND-5V).   

![I2C shield](/images/pcb_f/PCB_F_Shield_I2C_5V_3V3_V2.png "I2C shield")   
_Figure 4: “Shield_I2C_5V_3V3” board for connecting two I2C buses_   
_*Board size*_: 26.2 x 28.5 mm²   

![Shield_I2C_5V_3V3](/images/300_Shield_I2C_5V_3V3.png "Shield_I2C_5V_3V3")   
_Figure 5: The assembled circuit board “Shield_I2C_5V_3V3”._   

![Shield_I2C_5V_3V3_circuit](/images/600_Shield_I2C_5V_3V3_circuit.png "Shield_I2C_5V_3V3_circuit")   
_Figure 6: Circuit diagram of the “Shield_I2C_5V_3V3” board_   

### Bill of materials   
| number | reference | value | use |   
|--------|--------------|------------------------|--------------------|   
| 1 | J1 | four-pin header, 90° angled (Conn_01x04_Pin) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J2 | four-pin socket connector with short contacts (Conn_01x04_Socket) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
| 1 | J3 | Level Converter Converter_2x_3V3_5V | 5V-3V 2-CH I2C IIC Logic-Level-Converter Module Bi-Directional | _kh_library:Converter_2x_3V3_5V |   
| 2 | J3 | four-pin header (straight) | |   
| 2 | U1 | Socket connector, 8-pin with long contacts | |   
   
![Shield_I2C_5V_3V3_comp](/images/300_Shield_I2C_5V_3V3_comp.png "Shield_I2C_5V_3V3_comp")   
_Figure 7: Components for the “Shield_I2C_5V_3V3” board_   

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
_Figure 8: “Shield_5V_DCC_6pol_V2” circuit board_   
_*Board size*_: 26,2 x 28,5 mm²   

![Shield_5V_DCC_6pol](/images/300_Shield_5V_DCC_6pol.png "Shield_5V_DCC_6pol")   
_Figure 9: The assembled “Shield_5V_DCC_6pol” circuit board for connecting the 5V power supply, DCC signal and button_   

![Shield_5V_DCC_6pol_circuit](/images/600_Shield_5V_DCC_6pol_circuit.png "Shield_5V_DCC_6pol_circuit")   
_Figure 10: Circuit diagram of the “Shield_5V_DCC_6pol” board_   

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
_Figure 11: Components for the “Shield_5V_DCC_6pol” board_   

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

[To the top of the page](#up)   