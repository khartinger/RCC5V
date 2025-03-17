<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 17.3.2025 <a name="up"></a><br>   
<h1>Komponenten f&uuml;r die Stromversorgung</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Die Modulversorgung ("SUPPLY") stellt die elektrischen Mittel zur Verf&uuml;gung, damit auf einem Eisenbahn-Modul Z&uuml;ge fahren und Weichen etc. geschaltet werden k&ouml;nnen. Daf&uuml;r ben&ouml;tigt jedes Modul drei Dinge:   

1. eine Versorgungsspannung (Wechselspannung) zum Schalten der Eisenbahn-Komponenten (AC)   
2. eine 5V-Spannung f&uuml;r den Mikrocontroller und die Logik der Schaltbl&ouml;cke   
3. den Fahrstrom (Leitung NN und SS mit DCC-Signal oder Gleichstrom)   

Das folgende Bild veranschaulicht diesen Zusammenhang und zeigt, welche Komponente welche Spannungen ben&ouml;tigt.   

![supply overview](/images/300_RCC5V_Supply_Overview.png "supply overview")   
_Bild 1: &Uuml;bersicht &uuml;ber die Modulversorgung_   

Um den Verdrahtungsaufwand klein zu halten, werden der Mikrocontroller und die RCC-Bl&ouml;cke &uuml;ber 6-polige Flachbandkabel versorgt. Die Pin-Belegung des 6-poligen Kabels zum Mikrocontroller ("DCC") und zu den RCC-Bl&ouml;cken ("POWER") zeigt das folgende Bild:   
![connector_6pol](/images/100_6pol.png "connector_6pol")   
_Bild 2: Pinbelegung der 6-poligen Wannenstecker_   

<a name="x20"></a>   

# 2. Erzeugung der 5V-Spannung   
## 2.1 Schaltung   
Die 5V-Spannung wird auf jedem Modul extra aus der Versorgungsspannung erzeugt. Dazu wird die Wechselspannung gleichgerichtet, gegl&auml;ttet und mit einem LM2596-DC-DC-Wandler [(bestellbar zB bei Amazon)](https://www.amazon.de/dp/B0823P6PW6?ref=ppx_yo2ov_dt_b_fed_asin_title) auf 5V heruntergewandelt.   
Das Gleichrichten und das Zur-Verf&uuml;gung-Stellen der Spannungen &uuml;ber 6-polige Kabel erfolgen &uuml;ber eine einzelne Platine mit folgender Schaltung:   

![AC_5V_6pol_DCC_circuit](/images/300_AC_5V_6pol_DCC_circuit.png "AC_5V_6pol_DCC_circuit")   
_Bild 3: Schaltung der 5V-, AC- und DCC-Versorgung_   

* &Uuml;ber J3 kommen die Wechselspannung (AC+, AC-) und das DCC-Signal (WA, WB) auf die Platine.    
* D1, R1 und C1 bewirken die Einweg-Gleichrichtung des AC-Signals.   
* U1 stellt das DC-DC-Board dar.  
* J1 und J2 sind die 6-poligen Stecker "DCC" und "POWER".   
* Die Stecker J5 und J6 dienen nur der Vereinfachung: So muss man f&uuml;r die Aufnahme des DC-DC-Wandler-Boards nicht vier einzelne Buchsen aufl&ouml;ten, sondern kann zwei 8-polige Buchsenleisten verwenden.   

## 2.2 Die Netzteil-Tr&auml;gerplatine AC_5V_supply_6pol_DCC
Die Netzteil-Platine sieht so aus:   
![AC_5V_supply_6pol_DCC](/images/pcb_f/PCB_F_AC_5V_supply_6pol_DCC.png "AC_5V_supply_6pol_DCC")   
_Bild 4: Platine AC_5V_supply_6pol_DCC_   

_*Platinengr&ouml;&szlig;e*_: 63,75 x 21,55 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/AC_5V_6pol_DCC_V1](/fab/kicad/AC_5V_6pol_DCC_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz   | Wert                   | Geh&auml;use            |   
|--------|------------|------------------------|--------------------|   
|    1   | R1         | Leistungswiderstand 4,7&Omega;/5W          | Resistor_THT:R_Axial_Power_L25.0mm_W6.4mm_P27.94mm |   
|    1   | C1         | Elko 1000uF/35V        | _kh_library:CP_Radial_L20.0mm_D10.0mm_P5.08mm_Horizontal |   
|    1   | D1         | Diode 1N4007           | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
|    2   | J1, J2     | Wannenstecker 6-polig, stehend (Box_02x03_P2.54_Vertical_kh) | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
|    1   | J3, J5, J6 | Buchsenleiste 8-polig, lange Kontakte (Conn_01x08) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | U1         | DC-DC-Wandler-Board StepDown_LM2596 | _kh_library:DCDC_StepDown_LM2596_PinsOnly |   
|    4   | U1         | Stiftleiste 4-polig, gerade (*) |   |   

### Best&uuml;ckung   
1. Leistungswiderstand R1   
2. Diode D1   
3. Buchsenleisten J3, J5, J6   
4. Wannenstecker J1, J2   
5. Elko C1   

(*) Falls am LM2596-Board an den Ecken noch keine Pins angel&ouml;tet sind:   
* Von der Stiftleiste vier einzelne Pins herunterschneiden.   
* 4 einzelne Pins in die Enden von J5 und J6 stecken, das LM2596-Board aufstecken und die Pins verl&ouml;ten.   
6. Aufstecken des DC-DC-Step-Down-Wandlers LM2596   

## 2.3 Inbetriebnahme der Netzteil-Tr&auml;gerplatine AC_5V_supply_6pol_DCC
_*Wichtig:*_ Bei der ersten Inbetriebnahme des DC-DC-Wandler-Boards muss die Ausgangsspannung am Potenziometer mit Hilfe eines Voltmeters und eines Schraubendrehers auf 5 V eingestellt werden. Das Drehen der Schraube am Potenziometer (blauer Quarder) entgegen dem Uhrzeigersinn verkleinert dabei die Ausgangsspannung.   

Anschluss des Trafos: Pin 4 und 6 am 6-poligen Wannenstecker J3 (POWER)   
Anschluss des Voltmeters: Pin 1 und 3 am 6-poligen Wannenstecker J3 (POWER)   

![Adjusting 5V voltage](/images/300_adjust_5V.png "Adjusting the 5V voltage")   
_Bild 5: Einstellen der 5 V-Ausgangsspannung_   

## 2.4 Versionen
* V1 (241013): OK   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Verbindung von Modulen   
# 3.1 Allgemeines   
Nach NEM908D erfolgt die Verbindung von Modelleisenbahn-Modulen durch Kabel mit 25-poligen Sub-D-Buchsen. In den Modulen befinden sich daher 25-polige Sub-D-Stecker. Da Module unterschiedlich lang sein k&ouml;nnen, gibt es f&uuml;r die Modul-Stecker-Platinen zwei M&ouml;glichkeiten:   
(1) Eine Platine mit zwei 25-poligen Steckern f&uuml;r kurze Module (z. B. 25cm oder 50 cm L&auml;nge).   
(2) Zwei Platinen mit einem 25-poligen Stecker und einer 10-poligen Schraubklemmenleiste f&uuml;r lange Module (z.B. 75 cm oder 100 cm L&auml;nge).   

Die Verbindungsplatinen sind so aufgebaut, dass die Netzteilplatine direkt aufgel&ouml;tet werden kann. 
![best&uuml;ckte Platine RW_5V_2SUB25](/images/300_RW_5V_2SUB25.png "best&uuml;ckte Platine RW_5V_2SUB25")   
_Bild 6: Mit Netzteil best&uuml;ckte Verbindungsplatine mit zwei 25-poligen Steckern_   

<a name="x32"></a>   

## 3.2 Platine mit zwei 25-poligen Sub-D-Steckern und Netzteil (RW_5V_2SUB25)   
Diese Platine wird zum Verbinden kurzer Module mit L&auml;ngen von 25 cm oder 50 cm verwendet. Sie enth&auml;lt Anschl&uuml;sse f&uuml;r ein 5V-Netzteil und das DCC-Steuersignal sowie Schraubklemmen f&uuml;r den DCC-Fahrstrom (SS, NN und SN, NS) und die Hilfsleitungen OA und OB. Die Platine ist so aufgebaut, dass sie beim Einbau in ein Modul symmetrisch zu einer Verstrebung liegen kann.   

![Platine RW_5V_2SUB25](/images/pcb_f/PCB_F_RW_5V_2SUB25_V4.png "Platine RW_5V_2SUB25")   
_Bild 7: Platine RW_5V_2SUB25_   

_*Platinengr&ouml;&szlig;e*_: 80 x 66 mm²   
_*Montagebohrungen*_: 2,5 mm, Abstand 70 mm x 60 mm   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/RW_5V_2SUB25_V4](/fab/kicad/RW_5V_2SUB25_V4)   

### St&uuml;ckliste   
| Anzahl | Referenz     | Wert                   | Geh&auml;use       |   
|--------|--------------|------------------------|--------------------|   
|    2   | J1, J2       | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    3   | J7, J8, J10  | Schraubklemme 2-polig schwarz (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J9           | Schraubklemme 2-polig gr&uuml;n (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J5, J6, U1   | 5V-Netzteil-Platine     | _kh_library:AC_5V_supply_6pol_PinsOnly |   

### Best&uuml;ckung   
1. Schraubklemmen J10, J7 und J8, J9 zusammenstecken und einl&ouml;ten    
2. Sub-D-Stecker J2   
3. Einstecken und Verl&ouml;ten der 5V-Netzteil-Platine in J5 und J6 <br> Tipp: Das Einstecken der Netzteil-Platine gelingt viel leichter, wenn man eine der beiden Stiftleisten etwas k&uuml;rzt und die damit die Stifte nacheinander einsetzen kann...    
4. Sub-D-Stecker J1   

### Versionen
* V1 (241029): OK   
* V2 (241123): OK (Leiterbahnen zwischen Bauteil- und L&ouml;tseite getauscht)   
* V3 (250120): J10 erg&auml;nzt, Bohrungen f&uuml;r U1 zu klein   
* V4 (250306): OK

<a name="x33"></a>   

# 3.3 Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (RW_5V_SUB25_10)
Diese Platine wird bei l&auml;ngeren Modulen (L&auml;ngen von 75 cm oder 100 cm) auf einer Seite verwendet. Sie enth&auml;lt Anschl&uuml;sse f&uuml;r ein 5V-Netzteil und das DCC-Steuersignal sowie Schraubklemmen f&uuml;r den DCC-Fahrstrom (SS, NN und SN, NS), die Hilfsleitungen OA und OB und zus&auml;tzlich f&uuml;r alle Signale. Die Platine ist so aufgebaut, dass sie symmetrisch zu einer Verstrebung liegen kann.   

![Platine RW_5V_SUB25_10](/images/pcb_f/PCB_F_RW_5V_SUB25_10_V3.png "RW_5V_SUB25_10")   
_Bild 8: Platine RW_5V_SUB25_10_   

_*Platinengr&ouml;&szlig;e*_: 80 x 66 mm²   
_*Montagebohrungen*_: 2,5 mm, Abstand 70 mm x 60 mm   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/RW_5V_SUB25_10_V3](/fab/kicad/RW_5V_SUB25_10_V3)   

### St&uuml;ckliste   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|--------|--------------|------------------------|--------------------|   
|    1   | J1           | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    1   | J2           | Schraubklemme 5x 2-polig (= 10-polig) <br> zB je 2-polig schwarz-gr&uuml;n-rot-gr&uuml;n-schwarz |    |   
|    3   | J7, J8, J10   | Schraubklemme 2-polig schwarz (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J9   | Schraubklemme 2-polig gr&uuml;n (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J5, J6, U1   | 5V-Netzteil-Platine     | _kh_library:AC_5V_supply_6pol_PinsOnly |   

### Best&uuml;ckung   
1. Schraubklemmen J10, J7 und J8, J9 sowie J2 zusammenstecken und einl&ouml;ten    
2. Einstecken und Verl&ouml;ten der 5V-Netzteil-Platine in J5 und J6 <br> Tipp: Das Einstecken der Netzteil-Platine gelingt viel leichter, wenn man eine der beiden Stiftleisten etwas k&uuml;rzt und die damit die Stifte nacheinander einsetzen kann...    
3. Sub-D-Stecker J1   

### Versionen
* V1 (241104): OK   
* V2 (250120): J10 erg&auml;nzt, Bohrungen f&uuml;r U1 zu klein   
* V3 (250306): OK

<a name="x34"></a>   

# 3.4 Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (CON_SubD_Screw10)
Diese Platine wird bei l&auml;ngeren Modulen (L&auml;ngen von 75 cm oder 100 cm) auf einer der beiden Seiten (Ost oder West) verwendet. Sie f&uuml;hrt lediglich die Anschl&uuml;sse des Sub-D-Steckers auf Schraubklemmen heraus.   

![Platine CON_SubD_Screw10](/images/pcb_f/PCB_F_CON_SubD_Screw10_V1.png "CON_SubD_Screw10")   
_Bild 9: Platine CON_SubD_Screw10_   

_*Platinengr&ouml;&szlig;e*_: 31 x 66 mm²   
_*Montagebohrungen*_: 2,5 mm, Abstand 21 mm x 60 mm   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_SubD_Screw10_V1](/fab/kicad/CON_SubD_Screw10_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz     | Wert                   | Geh&auml;use            |   
|--------|--------------|------------------------|--------------------|   
|    1   | J1           | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    1   | J2           | Schraubklemme 5x 2-polig (= 10-polig) |    |   

### Best&uuml;ckung   
1. Schraubklemmen J2    
2. Sub-D-Stecker J1   

### Versionen
* V1 (241104): OK   

[Zum Seitenanfang](#up)