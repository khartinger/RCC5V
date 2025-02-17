<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-02-17 <a name="up"></a><br>   
<h1>Construction of module 12 “passing siding and siding”</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

[Click here to go directly to the content overview](#x05)   

# Overview
These instructions describe the construction of a 100 x 25 cm² N-gauge track module M12 “passing siding and siding”. The picture shows the technically finished module without landscaping. The operating and display elements for manual operation can be seen on the front.   

![Module M12](./images/300_Gleis_montiert1.png "Module M12")   
_Figure 1: Frame with base plate and tracks._   

## Properties of the module
|                |                                                    |   
|----------------|----------------------------------------------------|   
| Track material | Fleischmann N-gauge track with and without ballast bed |   
| Track layout | 1x three-way turnout, 2x two-way turnout, 1x uncoupler, 4x disconnectable track section |   
Electrical connection | 2x 25-pin SUB-D plug (according to NEM 908D, 1x WEST and 1x EAST) |   
| Traction current | Analog or DCC mode |   
| Control of the switching components | * Manually directly on the front of the module <br> * Via DCC <br> * Via MQTT messages (via WLAN) |   
| Controls with feedback | 1x OLED display and button <br> 1x three-way turnout (block W3, DCC 121 and 122) <br> 2x two-way turnout (block W2, DCC 123 and 128) <br> 1x uncoupler (block 1OUT, DCC 124) <br> 4x traction current (block 2IO, DCC 125, 126, 127 and 129) |   
| WLAN | SSID: &nbsp; &nbsp; &nbsp; `Raspi11` <br> Password: `12345678` |   
| MQTT: IP address of the broker (host) | `10.1.1.1` |   
| Other | * Easy connection to other modules via extendable rails at the segment ends |   

<a name="x05"></a>   

# Table of contents   
* [1. Preparation - purchasing](#x10)   
* [2. Building the module frame](#x20)   
* [3. Construction of the track plan](#x30)   
* [4. Electrical wiring of the module](#x40)   
* [5. Testing](#x50)   
* [6. Completing the work](#x60)   

[To the top of the page](#up)   
<a name="x10"></a>   

# 1. Preparation and purchasing
## 1.1 Design of the track plan
### 1.1.1 General information on track plans
There are two things to consider when creating a track plan: the clearance gauge and the height of the track structure.   
The __clearance gauge__ indicates how much space (especially for long wagons) is required next to the track. This is particularly important for tight radii.   
For the radius R2, a total track width of 27 + 2 - 7 = 41 mm is required.   
![Clearance gauge](./images/300_lichtraumprofil.png "Clearance gauge")   
_Figure 2: Clearance gauge_   

The __height of the track structure__ (track body) is important for the landscape design and for multi-storey systems or tunnels. A distinction can be made between different levels.   
* E0 . . . . . Top edge of the base plate (= 6 cm above a table top). The railroad embankment and, building on this, the ballast bed are placed on this level.   
* E5 . . . . . Top edge of the embankment. The ballast bed rests on this level.   
* E8 . . . . . The model track is located on this level. Model platforms and stations are also placed here. In reality, this level does not actually exist, as it lies in the middle of the ballast bed.   
* E10 . . . . . Upper edge of the ballast bed or lower edge of the track.   
* E12 . . . . . Top edge of the track. Railroad tracks should have this level, whereby railroad crossover stations often have a kind of “ramp” or driveway because the stations are usually placed at level E8.   

![Structure of the track body](./images/300_aufbau_bahnkoerper.png "Structure of the track body")   
_Figure 3: Structure of the track body_   

In the model, the track body is made of 5 mm plywood and 3 mm foam from Noch (95962 track bed roll N) and refined with track ballast from Fleischmann (9479). With a height of 4 mm (more precisely 4.1 mm) for the Fleischmann track with ballast bed, this results in a total height of 12.1 mm.   
If 5 mm plywood is not available, you can also use 4 mm thick plywood and glue a one millimeter thick, self-adhesive cork to the underside.   
If the __width of the embankment__ is assumed to be 40 mm (top) or __50 mm__ (bottom), the width of the clearance gauge for R2 is automatically fulfilled.   
__Minimum height in the tunnel__: 46 mm (height from the lower edge of the sleeper) + 3 mm (ballast bed) + 5 mm (railroad embankment) = __54 mm__ from the base plate.   

### 1.1.2 Design of the track plan
The track plan is designed in two steps:   
* First, the track plan is designed so that it basically meets the requirements.   
* In the next step, the position of the power supply points and insulation points is determined. This may mean that, for example, tracks have to be split into two parts so that 2-pole connection cables (Fleischmann 22217) or insulating rail connectors (Fleischmann 9403) can be attached.   

The following track plan was drawn with the program [AnyRail](https://www.anyrail.com/).   
![M12 track plan](./images/300_m12_gleisplan.png "M12 track plan")   
_Figure 4: Track plan_   

Dark gray triangles represent track insulation (insulating shoes), brown and red circles are traction current feeds.   
The 2nd track from the left is a track without ballast bed with a length of 17.2 mm (22207). The other short tracks are straight (9104) with a length of 27.75 mm. (Hard to read on the plan.)   
A special feature is track 9136 with the comment “R4 9 sleepers”: Here a track 9136 is first connected to the turnout on the left and then “cut off” at an angle of 6.14° (= 9 sleepers).   

## 1.2 Buying rails - track list
The following tracks and accessories are required to build the module:   
| Quantity | Number | Name | Euro/pc | Euro |   
| :---: | :---: | :--- |  ---: |  ---: |   
| 1 | 22207 | N Fleischmann, Straight track 17,2 mm | 2,00 | 2,00 |   
| 1 | 22210 | N Fleischmann, Rerailing device, Straight track 104,2 mm | 4,20 | 4,20 |   
| 8 | 9101 | Straight track 111 mm | 4,40 | 35,20 |   
| 1 | 9102 | Straight track 57,5 mm | 4,40 | 4,40 |   
| 1 | 9103 | Straight track 55, 5 mm | 4,40 | 4,40 |   
| 9 | 9104 | Straight track | 4,40 | 39,60 |   
| 2 | 9110 | Equalizing track stright 83mm-111mm | 14,60 | 29,20 |   
| 1 | 9112 | Straight uncoupling track (with drive) | 31,90 | 31,90 |   
| 2 | 9116 | Buffer stop (Bumper) 57,5 mm | 8,40 | 16,80 |   
| 1 | 9135 | Arc radius 430mm, Winkel 30° (R4) | 4,90 | 4,90 |   
| 3 | 9136 | Arc radius 430mm, Winkel 15° (R4) | 4,90 | 14,70 |   
| 1 | 9157 | Three-way Turnout | 47,80 | 47,80 |   
| 1 | 9178 | Turnout left with current-conducting centerpiece | 29,90 | 29,90 |   
| 1 | 9179 | Turnout right with current-conducting centerpiece | 29,90 | 29,90 |   
| 4 | 640000 | Electromagnetic point machine with limit stop | 25,60 | 102,40 |   
| 1 | 9403  | Insulating rail connector | 6,90 | 6,90 |   
| 7 | 22217 | 2-pole connection cable | 4,40 | 30,80 |   

Total costs 2025: approx. 435 euros   

## 1.3 Frame
### 1.3.1 Module frame
The 100 x 25 cm² module frame is 6 cm high and consists of two side parts (“East” and “West”), two longitudinal parts (“North” and “South”) and three cross struts. The railing panel is inserted into the frame.   
The parts of the frame can either be made from wood or printed using a 3D printer. A mixed construction method is also possible, e.g. side parts and cross struts 3D printed, longitudinal parts made of wood.   

### 1.3.2 Buying wood for the 100 x 25 cm² module
It is best to buy the wood from a DIY store and have it cut to the following sizes:   

__Poplar plywood 10 mm__   
| piece | dimension | short name | use |   
|:-----:|:-------------:|:--------:|:---------------------------|   
|   1   | 980 x 230 mm² |     -    | Terrain base plate         |   
|   2   | 980 x 60 mm²  | Ra2, Ra4 | Frame outside North, South |   
|   2   | 250 x 70 mm²  | Ra1, Ra3 | Frame outside West, East   |   
|   3   | 230 x 50 mm²  | Ri1      | Frame inside               |   

__Poplar plywood 5 mm (or 4mm)__   
| Piece | Dimension | Note |   
|:-----:|:-------------:|:----------|   
|   1   | 980 x 250 mm² | Railroad embankment  |   

__Small parts__   
4x poplar plywood 10 mm thick, 70 x 35 mm² for the holders of the Sub-D connectors.   
4x small pieces of wood 10 x 10 x 50 mm³ as additional supports for the base plate.   
20x screw M3 x 30 mm countersunk head, cross recess, self-tapping (e.g. Spax 4 003530 021251)   
8x screw M 2.5 x 16 mm cross recess, countersunk head   
8x hexagon nut M 2.5 mm   
4x screw M 3 x 35 mm cross recessed, semicircular head   
4x hexagon nut M 3 mm   

## 1.3.3 Consumables
The following is required to build the module:   
| piece | number | supplier | designation |   
|:----------:|:------:|:-----------|:-----------------|   
|      1     |        | Ponal      | Wood glue Express |   
|      1     |  95962 | Noch       | Track bed roll N 730 cm long, 3,2 cm wide, 0,3 cm thick |   
|      1     |        | [Amazon](https://www.amazon.de/dp/B07S188DRJ?ref=ppx_yo2ov_dt_b_product_details&th=1) | Self-adhesive cork panel 1 mm thick, 30 x 21 cm² |   
|     28     |   |   | Countersunk head screws with cross recess 3,0 x 30mm |   

To prevent the wooden frame from becoming dusty easily, it should be varnished. For this you need:   
| piece | number | supplier | designation |   
|:----------:|:------:|:-----------|:-----------------|   
|      1     | 4002364114016 | Albrecht   | Yacht and boat varnish, colorless, high gloss |   
|      1     |   |   | Pot cleaner (dishwashing sponge) |   
|      2     |   |   | Pair of disposable gloves         |   
|      1     |   |   | Sandpaper grain size 240      |   

## 1.4 Electronic RCC components
### 1.4.1 Control unit
The ESP32 with the two additional boards (I²C, DCC) and the 1.54” OLED display are used for the control system. The assembly is described on   
[`https://github.com/khartinger/RCC5V/blob/main/fab/rcc2_esp32/README.md`](/fab/rcc2_esp32/README.md)   


### 1.4.2 Connecting the 25-pin connector
To connect the 25-pin plugs and for the power supply, you will need the following assembled circuit boards:   
* 1x [Power supply board AC_5V_supply_6pol_DCC](/fab/rcc1_supply/README.md#x20)   
* 1x [PCB with 25-pin D-sub connector, screw terminals and power supply unit (RW_5V_SUB25_10)](/fab/rcc1_supply/README.md#x33)   
* 1x [PCB with 25-pin D-sub connector and screw terminals (CON_SubD_Screw10)](/fab/rcc1_supply/README.md#x34)   

The ordered power supply board must be mounted on the `RW_5V_SUB25_10` carrier board.   

### 1.4.3 Control of the switching components
The following switching blocks are required to control the switching components:   
* 8x [Bracket for switching blocks](/fab/rcc5_add_ons/README.md#x20)   
* 1x [block three-way switch (W3)](/fab/rcc4_block/README.md#x30)   
* 2x [Two-way switch block (W2)](/fab/rcc4_block/README.md#x20)   
* 1x [decoupler block (1OUT)](/fab/rcc4_block/README.md#x40)   
* 4x [Block switchable track (2IO)](/fab/rcc4_block/README.md#x50)   

In addition, 30 LED sockets are required.   

### 1.4.4 I²C expander
* 4x [PCF8574 I/O expander](/fab/rcc0_start/README.md#34)   

### 1.4.5 Wiring
The following additional boards are useful for connecting the switching components:   
* 1x [`CON_2pol_141` traction current distributor](/fab/rcc5_add_ons/README.md#x60)   
* 2x [`CON_1xIO` single traction current switch](/fab/rcc5_add_ons/README.md#x70)   
* 1x [`CON_2xIO` traction current switch double](/fab/rcc5_add_ons/README.md#x80)   
* 8x [`CON_10pol_PIN` or `CON_10pol_2x4` converter 10-pin cable to pins](/fab/rcc5_add_ons/README.md#x30)   
* 3x [`CON_6pol_3` 6-pin plug to three screw terminals](/fab/rcc5_add_ons/README.md#x40)   
* 2x [`CON_6pol_6` 6-pin plug on six screw terminals](/fab/rcc5_add_ons/README.md#x50)   

__Wires, cables and plugs__   
* approx. 4 m solid wire 22awg (0.32 mm²) red   
* approx. 4 m solid wire 22awg (0.32 mm²) brown   
* approx. 3 m ribbon cable 6-pin   
* approx. 2 m ribbon cable 10-pole   
* approx. 60 cm 10-pole cable 10 x 1 mm²   
* 4x 10-pin ribbon cable with female-female sockets 10 cm long (Dupont Jumper Wire Cable)   
* 1x 10-pin ribbon cable with female-female sockets 15 cm long (Dupont Jumper Wire Cable)   
* 2x four male-female cables 30 cm long (orange, yellow, green, blue)   
-----   
* 28x IDC female plugs for 6-pin ribbon cable   
* 16x IDC female plugs for 10-pin ribbon cable   
* 8x power terminals   

[To the top of the page](#up)   
<a name="x20"></a>   

# 2. Construction of the module frame   
## 2.1 Introduction
Each module consists of a frame with cross connections and the base plate, which contains the tracks and landscape. The module frame should be built first. This has two advantages:   
1. the test as to whether the base plate fits into the frame can be carried out with the empty base plate. If the base plate is too large, it can simply be cut or sanded down.   
2. when gluing the tracks onto the base plate, the side parts with the track recesses are already present on the module sides (east and west). This ensures that the tracks are securely in the correct position when they are glued on.   

The following picture shows the layout of the module frame:   

![Module frame](./images/300_module_frame.png "Module frame")   
_Figure 5: AnyRail illustration of the frame layout with the outer sections (Ra1 to Ra4) and cross braces (Ri1, Ri2, Ri3)_.

The individual parts of the frame must be processed according to the following descriptions before assembly.   

## 2.2 Side parts Ra1, Ra3 (West, East)
The side parts are based on a (former?) standard from n-spur.at, but the track body profile corresponds to NEM122:   

![Modul_OstWest_1_Mitte.png](./images/300_OstWest_1_Mitte.png "Modul_OstWest_1_Mitte")   
_Figure 6: Dimensions for the east and west side parts (module width 250mm, one track in the middle)._   

* Starting material: 10 mm poplar plywood panel, 250 x 70 mm²   
* The four 8 mm holes are used to connect the modules with 8 mm wing screws and wing nuts.   
* The four 2 mm holes on the left and right are for screwing on the north and south walls. They must be widened with a countersink so that the countersunk screws do not protrude.   
* The top two 2 mm holes are used to fix the railing base plate (if necessary). They must also be widened with a countersink so that the countersunk screws do not protrude.   
* The 60x20 mm² recess is used to feed through the 25-pin Sub-D connector.   

The recess for the track must be made with particular care. The recess is cut out a little too small with a leaf saw and widened with a triangular file until a Fleischmann ballast bed track fits straight (clamped) and is also positioned in the middle.   

## 2.3 Frame part Ra2 (North)
The frame part “North” contains only three times two holes with a diameter of 2 mm, which are widened again with a countersink. The cross struts are screwed on the inside here.   

![Modul_Nord_980mm](./images/300_Nord_980mm.png "Modul_Nord_980mm")   
_Figure 7: Side section North Ra2_   

<a name="x24"></a>   

## 2.4 Frame part Ra4 (South)
The frame part South is the most complex to manufacture, as it contains the display, a button and the holes for all control panels and for all cross struts. The following picture gives an overview of the required drill holes.   

![Modul_South_980mm](./images/300_Sued_980mm.png "Modul_South_980mm")   
_Figure 8: Dimensions for the frame part South (Ra4)_   

__OLED display__   
The cut-outs for the OLED display and the associated button depend on whether the components are mounted separately or a 3D print frame is used. For separate mounting, a rectangular cut-out of 20 x 38 mm² and an 11.6 mm hole are required.   
![OLED_Button_single](./images/300_OLED_Button_single.png "OLED_Button_single")   
_Figure 9: Dimensions for the separate mounting of the OLED display and the button_   

When using a 3D-printed frame, a rectangular cut-out measuring 80 x 43 mm² is required.   
![OLED_Button_frame](./images/300_OLED_Button_frame.png "OLED_Button_frame")   
_Figure 10: Dimensions for the frame of the OLED display with button_   

__Control block__   
Different holes are required depending on the type of control element. For example, the symbol of the three-way switch W3 points to the right (6 holes), that of the first two-way switch W2 to the bottom left (4 holes) and that of the uncoupler 1OUT to the right (4 holes). This is followed by the three switching symbols for the traction current cut-off 2IO (7 holes) and the circuit diagram of the second two-way switch W2 to the top right (4 holes).   
The exact position of all holes for a switching block is shown in the following figure, whereby only the corresponding holes are required depending on the type of switching block (!):   

![Drill position LEDs and button](./images/300_drill_position_LED_button.png "Drill position LEDs and button")   
_Figure 11: Dimensions for the LED and button drill holes_   

The drilling diameter for the LED sockets is 5.6 mm, for the buttons approx. 7 mm.   

The individual marking of the positions of the drill holes requires a lot of time and precise work. It therefore makes sense to design covers (labels) for the switch panels, print them out on label paper and stick them onto the wood (distance to the lower edge 8 mm). This makes drilling much easier. The labels can either be retained or removed if you do not want them. If the labels have been damaged too much by drilling, they can also be replaced with new ones....   

The following image shows the 40 x 42 mm covers.   
 
![Labeling control elements](./images/300_M12_cover.png "Labeling control elements")   
_Figure 12: Labeling of the operating elements for module 12_   

__LED sockets__   
After drilling, the holes must be cleaned and the LED sockets pressed in.   

__Holders for control panels__   
Next, you can screw on the brackets for the control panels using 2.6 x 8 mm screws. The distance between the panels and the underside of the frame should be 5.5 mm, but the position of the brackets is usually already predetermined by the LED sockets...   

The position of the screws for the control block brackets on the inside of the frame is determined as follows:   
![Screw position for block holder](./images/300_blockholder_mountingholes.png "Screw position for block holder")   
_Figure 13: Position of the screws for the control block holders_   

The finished frame part South (without track 1A traction current cut-off) is shown in the following pictures   
![Frame part South front side](./images/300_Frame_South_front.png "Frame part South front side")   
_Figure 14: Frame part south front_   

![Frame part South back side](./images/300_Frame_South_back.png "Frame part South back side")   
_Figure 15: Frame part south back_   

## 2.5 Cross strut Ri1 to Ri3
The cross braces contain various openings for cables and two holes for holding the 25-pin Sub-D connectors.   

![Bracing](./images/300_Verstrebung_230mm.png "Bracing")   
_Figure 16: Cross bracing Ri1 to Ri3_

## 2.6 Bracket for Sub-D connector
The holder for a SUB-D connector consists of two U-shaped parts that are screwed to the left and right of a cross strut. The parts can be made from wood or with 3D printing. Two brackets are required for the M12 module.   

![Sub-D bracket](./images/300_bracket_sub-d.png "Sub-D bracket")   
_Figure 17: Dimensions of the bracket_   

Two M 2.6 x 16 mm cross-head countersunk screws are screwed into each U-shaped part from below and secured with a 2.5 mm hexagon nut. The screws are used to secure the supply board.   
The two U-shaped brackets are screwed to a cross strut using M3 x 35 mm screws and 3 mm hexagon nuts.   

![Parts of the Sub-D bracket](./images/300_bracket_parts.png "Parts of the Sub-D bracket")   
_Figure 18: Parts of the Sub-D bracket_   

## 2.7 Assembling the frame
After all parts of the frame have been processed, it can be screwed together.   

![frame bottom view](./images/300_M12_frame_bottom_view.png "frame bottom view")   
_Figure 19: Assembled frame, view from below_   

[To the top of the page](#up)   
<a name="x30"></a>   

# 3. Layout of the track plan   

## 3.1 Trial assembly   
The trial assembly is carried out on the 5 mm (or 4 mm) plywood panel. To do this, the track plan is drawn on it at a scale of 1:1. This can be done either by printing out the track plan on a 1:1 scale and transferring it to the plywood (e.g. with carbon paper), or by transferring the coordinates to the plywood and drawing the track plan.   
According to the track plan design, the separation points must be made in both rail lines. Fleischmann 9403 insulating rail connectors are used for this purpose. The existing track connectors are removed and replaced by the insulating rail connectors.   
The tracks are then joined together according to the track diagram.   
All railway-specific structures (such as station, platforms, loading ramp) should also be set up during the test assembly so that you know how the track body (the 5 mm or 4 mm plate) must be cut.   
Finally, a test run is carried out with the longest wagon and a check is made to ensure that all the radii, curves, etc. fit and that no buildings are in the way.   

## 3.2 Cutting and gluing the railroad embankment to the base plate   
If the positioning test was successful, the following considerations apply to the individual ground heights.   
* The ground level on both sides of the module (east and west) is zero (E0). Exceptions to this are the embankment and the ballast bed of the track that leads into the module.   
* The ballast bed is at level E5 (= 5 mm plywood). The transition to level E0 is made via 45 degree slopes.   
* The Fleischmann tracks are at level E8. The 3 mm high foam track bed (Noch no. 95962 or cork) is glued onto the 5 mm plywood. The foam also dampens the running gear somewhat (sound insulation).   
* Station buildings, platforms or loading ramps are normally at level E8. In these places, the 5 mm plywood should be cut out and 8 mm plywood should be used instead of building up the height in layers.   
* Roads that cross the tracks have an upper edge of E12.   

Once you have decided which plywood heights to use, cut the corresponding panels to size and glue them to the base plate. To do this, the base plate should be in the frame so that the track connection on the left and right edges can be made precisely.   

If the point machines are to be installed as underfloor machines, recesses must be cut out.   

![Dimensions of the recess for an underfloor drive](./images/300_turnout_cutout_right.png "Dimensions of the recess for an underfloor drive")   
_Figure 20: Dimensions of the recess for an underfloor drive._   

The following two pictures show the different levels of the terrain and the recesses for the points. On the left front and right rear is the level E0, in the middle and rear (in the picture above) is 8 mm high plywood (E8).   
![Railway embankment2](./images/300_Bahndamm2.png "Railway embankment2")   
![Railway embankment](./images/300_Bahndamm.png "Railway embankment")   
_Figure 21: Different module levels_   

## 3.3 Bedding body (ballast bed)
In the next step, the 3 mm high foam track bed (Noch no. 95962 or cork) is glued on. This is not only done in places where a track will later run, but also in places that should have the same level, e.g. between the tracks or where the drive for the uncoupler will later go.   
Then drill the holes for the traction current supply with a 4 mm drill bit. If you have printed out a 1:1 template of the track layout, you can use this as a drilling template.   
The following picture shows the module with foam bed, recesses for the point machines and the holes for the traction current supply.   

![Ballast bed](./images/300_Schotterbett1.png "Ballast bed")   
_Figure 22: Base plate with railroad embankment, track bed (black), holes for traction current and points cut-outs_   

## 3.4 Preparing the wiring
### Mounting the switch plates   
Before the rails are laid, the wiring should be prepared (so that the tracks are not damaged). To make work easier, first remove the base plate from the frame and fit the switch blocks. To do this, insert a shifting block into the shifting block holder and screw it tight with four M2 x 20 mm screws (do not overtighten the screws!).    
![Shift block assembly](./images/300_Schaltblockmontage.png "Shift block assembly")   
_Figure 23: Screwing on the shifting block_   

Furthermore, mount the holder for the Sub-D connectors on the first and third cross strut. If a traction current supply line is located exactly under a bracket, the power supply line must be drilled again ....   

### Mounting the display and the microcontroller   
Insert the OLED display and the microcontroller into the frame as described in [Frame part Ra4 (South)](#x24).   

## Mounting the I²C I/O expander boards
1. segment 2: Assembly of two I²C-PCF8574-I/O expander boards and the auxiliary boards `CON_i2c_20mm`. Setting the addresses 0x20 and 0x21 using the jumpers.   
2. segment 3: Assembly of two I²C-PCF8574-I/O expander boards and the auxiliary boards `CON_i2c_20mm`. Setting the addresses 0x22 and 0x23 using the jumpers.   

### Mounting the screw terminals   
In order to make the wiring of the module clear, 2x2 longitudinal lines (distance from the edge 4 cm and 5.5 cm) are drawn, which run exactly through the feed-throughs of the cross connectors. The cables are routed in this area. Now put the base plate back into the frame.   
The following generally applies to the placement of the terminals:   
* I²C components (e.g. the prints with 10-pin tub connector) are mounted close to the control panel (shown in the following picture above). However, they should not be mounted too close to the switch blocks so that the switch blocks can still be easily unscrewed in the event of a fault.   
* Traction current components (e.g. PCBs with 6-pin tub connector) on the opposite side to the switching blocks (“rear”, in the picture below) and 
* switch connections near the switches.   

The following picture shows the mounted clamps.   

![M12_wiring_1](./images/300_M12_Verdrahtung1.png "M12_wiring_1")   
_Figure 24: Screw terminals for wiring_   

#### Installation of the screw terminals etc. in detail    
1. labeling the holes for the traction current supply:   
   Segment 1: GW-1, GW-2, G1A-1   
   Segment 2: E1, G2-1, G1-1   
   Segment 3: G1-2, G2-2, G3-1   
   Segment 4: GO-1, GO-2   
2. all prints are screwed on with M2 x 10 mm screws, and the load terminals with M2.6 x 12 mm screws.   
3. the tracks of the entry and exit of a module are always connected directly to the traction current. With the power distributor print `CON_2pol_141_V1`, additional terminals are available for the traction current distribution (green bar at the bottom of the 2nd segment from the left)   
4. 2x `CON_1xIO_V1` and 1x `CON_2xIO_V1` are used to switch the traction current (together with the `2IO` switching blocks) (bottom of Fig. 21).   
5. four pins `CON_10pol_PIN_V2` each in segments 2 and 3 provide the input and output pins of the 10-pin switching block outputs for the I²C wiring.   
6. two PCF 8574 I/O prints are mounted in segments 2 and 3 (one for the output signals and one for the input signals).   
7. the points and the decoupler are connected to 3x `CON_6pol_3_V1` or 1x `CON_6pol_6_V1` (for three-way turnout).   

## 3.5 Track construction
### Attaching the power supply to the track   
You can use Fleischmann 22217 2-pole N-gauge connection cables for the power supply or you can attach wires to the track connectors yourself. This works very well for Fleischmann ballast bed tracks, whereas the connectors for tracks without a ballast bed are practically impossible to solder.   
The connecting wire used is an approx. 30 cm long brown solid wire with 0.32 mm² (22awg) for the northern track and a red wire for the southern track. Strip approx. 6 mm of insulation from both sides of the wire and bend it into a hook shape for the track connector connection, flatten it slightly with small pliers and tin it.   
The best way to do this is to fix the track with adhesive tape, cut out the small connection above the track connector with a Stanley knife (to make it easier to loosen ;) ) and tin the track connector. In the picture below you can see the small plastic connection above the track connector, which has been removed at the top right.   

![Soldering track connection 1](./images/300_Loeten_Gleisanschluss1.png "Soldering track connection 1")   
_Figure 25: Preparing the connection of a power supply line._   

### Gluing on the tracks   
#### Preparing the points   
To use the drive as an underfloor drive, pull out the switch lever of the turnout and insert it again rotated by 180°. The drive can then be plugged on with the top side facing downwards.   
#### Preparing the power supply   
If you use the Fleischmann 22217 power supply cable, you must always drill a hole (4 mm) above the contact point so that the cable can be fed downwards.   
With self-soldered power supply lines, a hole must be drilled directly under each track connector.   
#### Preparing the uncoupling track   
A 4 mm hole must also be drilled for the drive of the uncoupling track 9112 (or 22212).   
#### Glue on the tracks   
Insert all cables into the holes and pull them down until the tracks are about 5 to 10 cm away from their future position. Place the base plate at a slight angle so that the cables are not kinked.   
Mark all areas where no glue may be applied (or cover with adhesive tape):   
* Point machine   
* Uncoupling track   
* Equalizing tracks on the left and right edges (east and west)   

Apply glue to the track bed. Make sure that as little glue as possible (or no glue at all) is applied in the area of the points and the uncoupling track so that no glue gets into the drives and sticks them together!   
As the compensation tracks are used to adjust distances at the module boundaries, NO glue should be applied in this area either!   
Then plug the tracks together and carefully pull on the cables until the tracks lie on the glue.   
As the two compensating tracks on the left and right edges are mechanically stressed in the longitudinal direction during operation, they should each be additionally fixed with a track nail. The track nail must be driven in on the side of the track away from the edge.   

The module with inserted base plate and tracks looks as follows:   
![Assembled track](./images/300_Gleis_montiert1.png "Assembled track")   
_Figure 26: Frame with base plate and tracks_   

[To the top of the page](#up)   
<a name="x40"></a>   

## 4. Electrical wiring of the module   

## 4.1 Wiring the power supply and traction current
1. connect the “POWER” connection of the `RW_5V_SUB25_10` supply board to the eight switching blocks using a 6-pin ribbon cable approx. one meter long and 10 mounted post connectors. The first post connector is used to connect to the supply board, the post connector at the end of the cable is used to extend the ribbon cable if necessary or to connect 100 nF capacitors between V+ and V- as well as 5V and 0V. (The connector is not yet attached in the top right of _Fig. 27_...)   
![Terminating capacitors](./images/300_powerline_2xC.png "Terminating capacitors")   
_Figure 27: Terminating capacitors at the end of the POWER cable_   

2. connect all traction current connections to the corresponding terminals.   
3. connect the traction current (NN, SS) from the supply board `RW_5V_SUB25_10` to the boards `CON_2pol_141`, `CON_1xIO`, `CON_2xIO` and the power terminals GW (track west) and GO (track east).   
4. connect the connections of the two turnout drives of the three-way turnout to the `CON_6pol_6` circuit board (left turnout = drive closer to the switching blocks = pins 1 and 3, earth to pin 2).   
5. connect the connections of the two two-way switch drives to the `CON_6pol_3` boards (earth = black cable to pin 2).   
6. connect the connections of the decoupler to the `CON_6pol_3` board.   
Important: As the decoupler generates interference voltages, a 100 nF capacitor must be connected in parallel to the V+ and V- terminals.   
![Uncoupling capacitor](./images/300_uncoupler_C.png "Uncoupling capacitor")   
_Figure 28: Uncoupling capacitor on the uncoupler_   

The wiring of the power supply at a glance:   

![Wiring 1](./images/300_Verdrahtung1.png "Wiring 1")   
_Figure 29: Power supply wiring_   

### First test of the wiring   
With the previous wiring, it is already possible to carry out a manual operation. In particular, the correct connection of the points and the function of all power supply lines (power points) can be tested.   
1. connect a 25-pin plug with traction current and alternating current supply: The LEDs of the switching blocks should light up.   
2. test the control of the three-way switch left-center and center-right. If an error occurs: Swap connections 1 and 3.   
2. test the control of the two-way crossover. Is the indicator LED for straight and branch correct? Does the turnout switch to “straight” or “branch” according to the button? If not: Swap connections 1 and 3.   
3. is the uncoupler working?   
4. do all LED displays match the corresponding hardware?   
5. switch on the traction current for tracks 1, 2, 3 and 1A with the green buttons, test run with a locomotive over all tracks.   

## 4.2 Preparing the microcontroller
1. connect the “DCC” connection of the `RW_5V_SUB25_10` supply board to the microcontroller using an approx. 30 cm long, 6-pin cable.   
2. connect the microcontroller to the I²C-PCF8574-I/O expander boards with 20 cm long, 4-pin cables with male-female connectors.   
3. programming the microcontroller with the `rcc_module12_V1` software.   

## 4.3 Wiring the I²C bus
1. connect the eight 10-pin plugs of the switch blocks to the 10-pin plugs of the `CON_10pol_PIN` boards.   

2. making the connections between the pin headers of the `CON_10pol_PIN` boards and the I²C-PCF8574-I/O expander boards with 10 cm long female-female cables.    

In segment 2:   
   * I/O-Expander 0x20 - Pin 0 <---> Block DCC 129, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 1 <---> Block DCC 121/122, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 2 <---> Block DCC 121/122, Pin 2 - IN   
   * I/O-Expander 0x20 - Pin 3 <---> Block DCC 121/122, Pin 3 - IN   
   * I/O-Expander 0x20 - Pin 4 <---> Block DCC 123, Pin 1 - IN   
   * I/O-Expander 0x20 - Pin 5 <---> Block DCC 123, Pin 2 - IN   
   * I/O-Expander 0x20 - Pin 6 <---> Block DCC 124, Pin 1 - IN   
   -------   
   * I/O-Expander 0x21 - Pin 0 <---> Block DCC 129, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 1 <---> Block DCC 121/122, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 2 <---> Block DCC 121/122, Pin 2 - OUT   
   * I/O-Expander 0x21 - Pin 3 <---> Block DCC 121/122, Pin 3 - OUT   
   * I/O-Expander 0x21 - Pin 4 <---> Block DCC 123, Pin 1 - OUT   
   * I/O-Expander 0x21 - Pin 5 <---> Block DCC 123, Pin 2 - OUT   
   * I/O-Expander 0x21 - Pin 6 <---> Block DCC 124, Pin 1 - OUT   

In segment 3:   
   * I/O-Expander 0x22 - Pin 0 <---> Block DCC 128, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 1 <---> Block DCC 128, Pin 2 - IN   
   * I/O-Expander 0x22 - Pin 2 <---> Block DCC 127, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 3 <---> Block DCC 126, Pin 1 - IN   
   * I/O-Expander 0x22 - Pin 4 <---> Block DCC 125, Pin 1 - IN   
   -------   
   * I/O-Expander 0x23 - Pin 0 <---> Block DCC 128, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 1 <---> Block DCC 128, Pin 2 - OUT   
   * I/O-Expander 0x23 - Pin 2 <---> Block DCC 127, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 3 <---> Block DCC 126, Pin 1 - OUT   
   * I/O-Expander 0x23 - Pin 4 <---> Block DCC 125, Pin 1 - OUT   

## 4.4 Module connection
The 10 screw terminals on the 25-pin connectors must be connected to each other so that modules can be strung together.   
According to NEM908D, this is done in such a way that the lines are electrically crossed out but physically connected straight through. This means, for example, that the traction current of track NN is on pin 1 on the west connector and on pin 13 on the east connector!   
![Wiring_NEM908D](/images/300_Wiring_NEM908D.png "Wiring_NEM908D")   
_Figure 30: 25-pin Sub-D connector on the module with pin assignment_   

[See also `/info/con_NEM908/README.md`](/info/con_NEM908/README.md)   

For example, 10-pin cable can be used to connect the pins.   

![Connector West](./images/300_con10_west.png "Connector West")   
_Figure 31: Wiring connector West_   

![Plug East](./images/300_con10_east.png "Plug East")   
_Figure 32: Wiring plug east_   

[To the top of the page](#up)   
<a name="x50"></a>   

# 5. trial operation
## 5.1 Module start
1. start the MQTT server.   
2. connect a laptop or PC to the network of the MQTT server and start the `mosquitto_sub` software in a command window with this command:   
   `mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
3. plug in a 25-pin connector with traction current and alternating current supply: The LEDs of the switching blocks should light up correctly according to the hardware setting.   
4. switch the info pages on the OLED with the button next to it. If everything is working, the following message appears on the OLED display:   
```   
  RCC Module 12     
MQTT OK    Raspi11  
rcc/module12        
G1A TWL TWR T1  E1  
Aus __  __  _/  Aus 
129 121 122 123 124 
```   

The display of the position of points 121 to 123 depends on the actual position of the points. The display changes every 5 seconds.   

5. the start message of the module appears in the command window on the laptop:   
`rcc/start/mqtt {“topicbase”: “rcc/module12”}`   

## 5.2 Test with MQTT
Open a second command window on the laptop and enter the following:   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/get -m ?`   
The possible commands are displayed in the first command window:   
```   
rcc/module12/get ?
rcc/module12/ret/?
get: ?|help|version|ip|topicbase|eeprom|byname|bydcc|G1A|129|TWL|121|TWR|122|T1|123|E1|124|G1|125|G2|126|G3|127|T2|128|
set: topicbase|eeprom0|G1A|129|TWL|121|TWR|122|T1|123|E1|124|G1|125|G2|126|G3|127|T2|128|
sub:
pub:
MQTT: ../set/w1 -m 1|g|G OR -m 0|A|a|B|b (set by name)
      ../set/11 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)
      ../get -m byname|bydcc (values of all components)
```   

### Examples of switching commands  
Switching the DCC 123 turnout to straight:   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/123 -m 1`   

Switch the turnout DCC 123 with name T1 to branch (curve):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/T1 -m 0`   

Switch on the traction current in track 2 (through track, DCC address 126):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/126 -m 1`   
The display changes from “Off” (red LED) to “On” (green LED) unless one of the two buttons is pressed.   

Switching on the decoupler (DCC 124):   
`mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/124 -m 1`   
The decoupler is switched on for 1.5 seconds.   

## 5.3 Test with DCC
Depending on the DCC input device, the same actions can be carried out as with MQTT.   
### Example Roco Multi-Mouse
* Select turnout control (locomotive/turnout button) ![button_loc_turnout](./images/50_taste_lok_weiche.png)   
* Enter DCC address 123 ![Display_W0123](./images/50_anzeige_W0123.png)   
* Switch the points with the arrow keys ![Arrow keys](./images/50_taste_pfeil.png)   

[To the top of the page](#up)   
<a name="x60"></a>   

# 6. final work   
## 6.1 Turnout covers   
The base plate must be cut out for the installation of the underfloor point machines (see Fig. 20 and 21). For the landscape design, however, these cut-outs must be well covered so that no ballast grains etc. get into the point machines. Two different types of covers are required on the M12 module:   
* Three flat covers (starting from level E8)   
* One high cover for the right-hand drive of the three-way turnout (i.e. starting from base plate E0)   

With the flat covers, the turnout drives extend 1.5 mm above level E8 (upper foam limit):   
* 0.5 mm metal plate on the underside of the turnout + 0.5 mm metal retaining lugs + 0.5 mm height compensation if the turnout is mounted above ground...   
To cover the cut-out, a 0.5 mm plastic foil can therefore be used as a base cover and a 1 mm foil above + a 0.5 mm foil above the drive.   
As an alternative, 3D-printed covers are also possible, as shown in _Fig. 33_. 
![3D cover for turnout](/images/300_3d_weichenabdeckung.png "3D cover for turnout")   
_Figure 33: 3D printed covers for the turnout recesses_   

The thickness of the covers is 0.6 mm (= 3 layers) and they are attached with track nails (0.7 mm diameter). The middle cover was cut to size with scissors.   

## 6.2 Floor cover   
To protect the wiring, you can also cover parts of the floor with transparent foil (e.g. 1 mm thick).   

## 6.3 Model background image   
The model background image should be at least 15.5 cm high with a module depth of 25 cm.   

[To the top of the page](#up)   
