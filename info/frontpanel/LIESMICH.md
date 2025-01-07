
<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 07.01.2025 <a name="up"></a><br>   
<h1>Gestaltung der Frontseite eines Moduls</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# ... To Do ...

# Einleitung
Alle Schaltblöcke sind dazu gedacht, an der Frontseite einer Eisenbahnanlage bzw. eines Moduls montiert zu werden. Damit ist eine einheitliche Bedienung und Anzeige möglich (siehe Bild 1 als Beispiel).   
![Beispiel Frontansicht](/images/480_front_view_module.png "Beispiel Frontansicht")   
_Bild 1: Beispiel Modul-Frontansicht (= Bedienungsseite)_   

Für die Bedien- und Anzeigeelemente sind insgesamt 9 Positionen vorgesehen. Dabei muss nur dort gebohrt werden, wo auch wirklich ein Taster/Schalter oder eine LED vorgesehen ist. Durch Verwendung einer Abdeckung kann die Bedeutung eines Schaltblocks noch übersichtlicher gemacht werden.   

# Anordnung der Schaltblöcke   
Schaltblöcke haben eine Größe von 41 x 41 mm² bei einer Tiefe von ca. 39 mm. Bei einem angenommenen Abstand von 9 mm zwischen den Blöcken ergibt sich ein __Schaltblockabstand von 50 mm__.   
Geht man von einer Frontplattenhöhe von 60 mm und Stärke der eingelegten Gleisträgerplatte von 10 mm aus, so ergibt sich eine Einbauhöhe von 50 mm. Als Abstand eines Schaltblocks zum unteren Rand wird 5,5 mm (5,43 mm) angenommen.   

# Bohrpositionen   
Da Bauteile auf den Platinen oft im 1/10-Zoll-Raster plaziert sind, sind die Bohrpositionen keine ganzen Zahlen im Millimeter-System. Daher werden die Bohrpositionen gerundet, wie das Bild 2 zeigt. Die exakten Werte können zB aus dem Layout einer KiCad-Datei (zB [RW_5V_W3_STRG_V4.kicad_pcb - in KiCad öffnen](/kicad/RW_5V_W3_STRG_V4)) oder einer [Excel-Tabelle](/info/z_details/RW_Koordinaten_241124.xls) entnommen werden.   

![panel_drill_positions1](/images/300_panel_drill_positions1.png "panel_drill_positions1")   
_Bild 2: Bohrpositionen für die LEDs und Taster bzw. Schalter_

__Bohrdurchmesser:__   
LEDs: 5,6 mm   
Taster und Schalter: ca. 7 mm   

Zwischen den Bohrpositionen und der Bezeichnung der LEDs (D1 bis D6) bzw. Taster (SW1 bis SW3) besteht folgender Zusammenhang:   
![LED- und Schalterpositionen](/images/200_block_cover.png "LED- und Schalterpositionen")   
_Bild 3: LED- und Schalterpositionen bei einem Block (von vorne gesehen)_   

# Abdeckungen
Abdeckung helfen, die Bedeutung der LEDs und der Taster eines Schaltblocks besser zu verstehen. Sie können beliebig gestaltet werden, hier sind einige Vorschläge.   

![cover_3way_turnout](/images/300_cover_3way_turnout.png "cover 3way turnout")   
_Bild 4: Dreiwegweiche_

![cover_2way_turnout_left](/images/300_cover_2way_turnout_left.png "cover 3way turnout left")   
_Bild 5: Linke Zweiwegweiche_

![cover_2way_turnout_right](/images/300_cover_2way_turnout_right.png "cover 3way turnout right")   
_Bild 6: Rechte Zweiwegweiche_

![cover_uncoupler](/images/300_cover_uncoupler.png "cover uncoupler")   
_Bild 7: Entkuppler_

![cover_track](/images/300_cover_track.png "cover track")   
_Bild 8: Abschaltbares Gleis_

[Zum Seitenanfang](#up)   