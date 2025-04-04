<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 07.01.2025 <a name="up"></a><br>   
<h1>Gestaltung der Frontseite eines Moduls</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Einleitung
Alle Schaltbl&ouml;cke sind dazu gedacht, an der Frontseite einer Eisenbahnanlage bzw. eines Moduls montiert zu werden. Damit ist eine einheitliche Bedienung und Anzeige m&ouml;glich (siehe Bild 1 als Beispiel).   
![Beispiel Frontansicht](/images/480_front_view_module.png "Beispiel Frontansicht")   
_Bild 1: Beispiel Modul-Frontansicht (= Bedienungsseite)_   

F&uuml;r die Bedien- und Anzeigeelemente sind insgesamt 9 Positionen vorgesehen. Dabei muss nur dort gebohrt werden, wo auch wirklich ein Taster/Schalter oder eine LED vorgesehen ist. Durch Verwendung einer Abdeckung kann die Bedeutung eines Schaltblocks noch &uuml;bersichtlicher gemacht werden.   

Einen Spezialfall stellt das 1,54-Zoll-Display dar. Es dient zur Anzeige verschiedener Informationen wie   
* Name und Versionsnummer der eingebauten Software,   
* Erkl&auml;rungen zum Modul (beim Start),   
* Verwendung eines WLANs und des MQTT-Basis-Topics,   
* verwendete Komponenten und ihre DCC-Adressen.   
Informationen zum Einbau finden sich [am Ende dieses Textes](#30).

# Anordnung der Schaltbl&ouml;cke   
Schaltbl&ouml;cke haben eine Gr&ouml;&szlig;e von 41 x 41 mm² bei einer Tiefe von ca. 39 mm. Bei einem angenommenen Abstand von 9 mm zwischen den Bl&ouml;cken ergibt sich ein __Schaltblockabstand von 50 mm__.   
Geht man von einer Frontplattenh&ouml;he von 60 mm und St&auml;rke der eingelegten Gleistr&auml;gerplatte von 10 mm aus, so ergibt sich eine Einbauh&ouml;he von 50 mm. Als Abstand eines Schaltblocks zum unteren Rand der Frontplatte wird 5,5 mm (5,43 mm) angenommen.   

# Bohrpositionen   
Da Bauteile auf den Platinen oft im 1/10-Zoll-Raster plaziert sind, sind die Bohrpositionen keine ganzen Zahlen im Millimeter-System. Daher werden die Bohrpositionen gerundet, wie das Bild 2 zeigt. Die exakten Werte k&ouml;nnen zB aus dem Layout einer KiCad-Datei (zB [RW_5V_W3_STRG_V4.kicad_pcb - in KiCad &ouml;ffnen](/fab/kicad/RW_5V_W3_STRG_V4)) oder einer [Excel-Tabelle](/info/z_details/RW_Koordinaten_241124.xls) entnommen werden.   

![panel_drill_positions1](/images/300_panel_drill_positions1.png "panel_drill_positions1")   
_Bild 2: Bohrpositionen f&uuml;r die LEDs und Taster bzw. Schalter_

__Bohrdurchmesser:__   
LEDs: 5,6 mm   
Taster und Schalter: ca. 7 mm   

Zwischen den Bohrpositionen und der Bezeichnung der LEDs (D1 bis D6) bzw. Taster (SW1 bis SW3) besteht folgender Zusammenhang:   
![LED- und Schalterpositionen](/images/200_block_cover.png "LED- und Schalterpositionen")   
_Bild 3: LED- und Schalterpositionen bei einem Block (von vorne gesehen)_   

[Zum Seitenanfang](#up)
<a name="x20"></a>   

# Abdeckungen
Abdeckung helfen, die Bedeutung der LEDs und der Taster eines Schaltblocks besser zu verstehen. Sie k&ouml;nnen beliebig gestaltet werden, hier sind einige Vorschl&auml;ge.   

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
<a name="x30"></a>   

# Einbau der 1,54"-OLED-Anzeige
Beim OLED-Display sind zwei Gr&ouml;&szlig;en zu unterscheiden, die Au&szlig;enma&szlig;e (42,4 x 38 mm²) und die Gr&ouml;&szlig;e der tats&auml;chlichen Anzeigefl&auml;che (35,06 x 17,52 mm²):   

![dimension_1.54_display](/images/parts/dimensions_OLED154_4pin.png "dimension_1.54_display")   
_Bild 9: Abmessungen des 1,54"-Displays_   

Bei der Montage in eine Holz-Frontplatte reicht eine rechteckf&ouml;rmige Aussparung zB der Gr&ouml;&szlig;e 38 x 20 mm² (d.h. ca. 1,5 mm Rand um die aktive Anzeigefl&auml;che):   
![front_display](/images/300_front_display.png "front_display")   
_Bild 10: Eingebautes Display auf der Frontseite eines Moduls_   

![dimension_front_1.54_display](/images/200_dim_front_display.png "dimension_front_1.54_display")   
_Bild 11: Lage des Displays auf der Frontseite eines Moduls_   

Um die Sichtbarkeit der Anzeige zu verbessern, kann man auch auf der R&uuml;ckseite des Frontpanels die Gr&ouml;&szlig;e der Display-Printplatte 3 bis 5 mm tief ausfr&auml;sen. Aber Achtung: Die Anzeigefl&auml;che liegt nicht mittig auf der Printplatte. Der Rand nach oben betr&auml;gt ca. 8 mm, zum unteren Platinenrand ca. 12,5 mm!   
Weiters sollte neben dem Display eine Taste vorgesehen werden, mit der die angezeigten Texte quittiert werden k&ouml;nnen.   

Eine weitere M&ouml;glichkeit zur Montage des Displays und des Tasters besteht darin, eine 3D-Druck-Halterung zu erstellen.   

[Zum Seitenanfang](#up)   