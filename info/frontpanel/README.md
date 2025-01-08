<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-01-07 <a name="up"></a><br>   
<h1>Design of the front side of a module</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# Introduction
All switch blocks are intended to be mounted on the front of a railroad system or module. This enables uniform operation and display (see Figure 1 as an example).   
![Example front view](/images/480_front_view_module.png "Example front view")   
_Figure 1: Example module front view (= operating side)_   

A total of 9 positions are provided for the operating and display elements. Drilling is only necessary where a button/switch or LED is actually provided. By using a cover, the meaning of a switching block can be made even clearer.   

The 1.54-inch display is a special case. It is used to display various information such as   
* Name and version number of the installed software,   
* Explanations about the module (at startup),   
* Use of a WLAN and the MQTT base topic,   
* components used and their DCC addresses.   
Information on installation can be found [at the end of this text](#30).

# Arrangement of the switch blocks   
Switching blocks have a size of 41 x 41 mm² with a depth of approx. 39 mm. Assuming a distance of 9 mm between the blocks, this results in a __switching block distance of 50 mm__.   
Assuming a front panel height of 60 mm and a thickness of the inserted track support plate of 10 mm, this results in an installation height of 50 mm. A distance of 5.5 mm (5.43 mm) is assumed between a switching block and the lower edge.   

# Drilling positions   
As components are often placed on the PCBs in 1/10-inch increments, the drilling positions are not whole numbers in the millimeter system. The drilling positions are therefore rounded, as shown in Fig. 2. The exact values can be taken from the layout of a KiCad file (e.g. [RW_5V_W3_STRG_V4.kicad_pcb - open in KiCad](/kicad/RW_5V_W3_STRG_V4)) or an [Excel spreadsheet](/info/z_details/RW_Koordinaten_241124.xls).   

![panel_drill_positions1](/images/300_panel_drill_positions1.png "panel_drill_positions1")   
_Figure 2: Drilling positions for the LEDs and buttons or switches_

__Drill diameter:__   
LEDs: 5.6 mm   
Buttons and switches: approx. 7 mm   

The following relationship exists between the drilling positions and the designation of the LEDs (D1 to D6) or switches (SW1 to SW3):   
![LED and switch positions](/images/200_block_cover.png "LED and switch positions")   
_Figure 3: LED and switch positions on a block (seen from the front)_   

[To the top of the page](#up)   
<a name="x20"></a>   

# Covers
Covers help to better understand the meaning of the LEDs and buttons of a switch block. They can be designed as desired, here are some suggestions.   

![cover_3way_turnout](/images/300_cover_3way_turnout.png "cover 3way turnout")   
_Figure 4: Three-way turnout_   

![cover_2way_turnout_left](/images/300_cover_2way_turnout_left.png "cover 3way turnout left")   
_Figure 5: Left two-way turnout_   

![cover_2way_turnout_right](/images/300_cover_2way_turnout_right.png "cover 3way turnout right")   
_Figure 6: Right two-way turnout_   

![cover_uncoupler](/images/300_cover_uncoupler.png "cover uncoupler")   
_Figure 7: Uncoupler_   

![cover_track](/images/300_cover_track.png "cover track")   
_Figure 8: Disconnectable track_   

[Zum Seitenanfang](#up)
<a name="x30"></a>   

# Installation of the 1.54” OLED display
There are two different sizes of OLED display: the external dimensions (42.4 x 38 mm²) and the size of the actual display area (35.06 x 17.52 mm²):   

![dimension_1.54_display](/images/parts/dimensions_OLED154_4pin.png "dimension_1.54_display")   
_Figure 9: Dimensions of the 1.54” display_   

When mounting in a wooden front panel, a rectangular cut-out of e.g. 38 x 20 mm² (i.e. approx. 1.5 mm edge around the active display area) is sufficient:   
![front_display](/images/300_front_display.png "front_display")   
_Figure 10: Built-in display on the front of a module_   

![dimension_front_1.54_display](/images/200_dim_front_display.png "dimension_front_1.54_display")   
_Figure 11: Position of the display on the front of a module_   

To improve the visibility of the display, you can also mill out the size of the display print plate 3 to 5 mm deep on the back of the front panel. But be careful: the display surface is not centered on the print plate. The edge to the top is approx. 8 mm, to the bottom edge of the board approx. 12.5 mm!   
In addition, a button should be provided next to the display with which the displayed texts can be acknowledged.   

Another option for mounting the display and the button is to create a 3D print holder.   

[To the top of the page](#up)   