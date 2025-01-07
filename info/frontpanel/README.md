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

# Arrangement of the switch blocks   
Switching blocks have a size of 41 x 41 mm² with a depth of approx. 39 mm. Assuming a distance of 9 mm between the blocks, this results in a __switching block distance of 50 mm__.   
Assuming a front panel height of 60 mm and a thickness of the inserted track support plate of 10 mm, this results in an installation height of 50 mm. A distance of 5.5 mm (5.43 mm) is assumed between a switching block and the lower edge.   

# Drilling positions   
As components are often placed on the PCBs in 1/10-inch increments, the drilling positions are not whole numbers in the millimeter system. The drilling positions are therefore rounded, as shown in Fig. 2. The exact values can be taken from the layout of a KiCad file (e.g. [RW_5V_W3_STRG_V4.kicad_pcb - open in KiCad](/kicad/RW_5V_W3_STRG_V4)) or an [Excel spreadsheet](/info/z_details/RW_Koordinaten_241124.xls).   

![panel_drill_positions1](/images/300_panel_drill_positions1.png "panel_drill_positions1")   
_Figure 2: Drilling positions for the LEDs and buttons or switches_

Drill diameter:__   
LEDs: 5.6 mm   
Buttons and switches: approx. 7 mm   

The following relationship exists between the drilling positions and the designation of the LEDs (D1 to D6) or switches (SW1 to SW3):   
![LED and switch positions](/images/200_block_cover.png "LED and switch positions")   
_Figure 3: LED and switch positions on a block (seen from the front)_   

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

[To the top of the page](#up)   