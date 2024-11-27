<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 27.11.2024 <a name="up"></a><br>   
<h1>Komponenten für die Stromversorgung</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Die Modulversorgung ("SUPPLY") stellt die elektrischen Mittel zur Verfügung, damit auf einem Eisenbahn-Modul Züge fahren und Weichen etc. geschaltet werden können. Dafür benötigt jedes Modul drei Dinge:   

1. eine Versorgungsspannung (Wechselspannung) zum Schalten der Eisenbahn-Komponenten (AC)   
2. eine 5V-Spannung für den Mikrocontroller und die Logik der Schaltblöcke   
3. den Fahrstrom (Leitung NN und SS mit DCC-Signal oder Gleichstrom)   

Das folgende Bild veranschaulicht diesen Zusammenhang und zeigt, welche Komponente welche Spannungen benötigt.   

![supply overview](/images/300_RCC5V_Supply_Overview.png "supply overview")   
_Bild 1: Übersicht über die Modulversorgung_   

Um den Verdrahtungsaufwand klein zu halten, werden der Mikrocontroller und die RCC-Blöcke über 6-polige Flachbandkabel versorgt. Die Pin-Belegung des 6-poligen Kabels zum Mikrocontroller ("DCC") und zu den RW-Blöcken ("POWER") zeigt das folgende Bild:   
![connector_6pol](/images/100_6pol.png "connector_6pol")   
_Bild 2: Pinbelegung der 6-poligen Wannenstecker_   

<a name="x20"></a>   

# 2. Erzeugung der 5V-Spannung   
## 2.1 Schaltung   
Die 5V-Spannung wird auf jedem Modul extra aus der Versorgungsspannung erzeugt. Dazu wird die Wechselspannung gleichgerichtet, geglättet und mit einem LM2596-DC-DC-Wandler [(bestellbar zB bei Amazon)](https://www.amazon.de/dp/B0823P6PW6?ref=ppx_yo2ov_dt_b_fed_asin_title) auf 5V heruntergewandelt.   
Das Gleichrichten und das Zur-Verfügung-Stellen der Spannungen über 6-polige Kabel erfolgen über eine einzelne Platine mit folgender Schaltung:   

![AC_5V_6pol_DCC_circuit](/images/300_AC_5V_6pol_DCC_circuit.png "AC_5V_6pol_DCC_circuit")   
_Bild 3: Schaltung der 5V-, AC- und DCC-Versorgung_   

* Über J3 kommen die Wechselspannung (AC+, AC-) und das DCC-Signal (WA, WB) auf die Platine.    
* D1, R1 und C1 bewirken die Einweg-Gleichrichtung des AC-Signals.   
* U1 stellt das DC-DC-Board dar.  
* J1 und J2 sind die 6-poligen Stecker "DCC" und "POWER".   
* Die Stecker J5 und J6 dienen nur der Vereinfachung: So muss man für die Aufnahme des DC-DC-Wandler-Boards nicht vier einzelne Buchsen auflöten, sondern kann zwei 8-polige Buchsenleisten verwenden.   

## 2.2 Die Netzteil-Trägerplatine AC_5V_supply_6pol_DCC
Die Netzteil-Platinie sieht so aus:   
![AC_5V_supply_6pol_DCC](/images/pcb_f/PCB_F_AC_5V_supply_6pol_DCC.png "AC_5V_supply_6pol_DCC")   
_Bild 4: Platine AC_5V_supply_6pol_DCC_   
_*Platinengröße*_: 63,75 x 21,55 mm²   

__Stückliste__   
| Anzahl | Referenz   | Wert                   | Gehäuse            |   
|--------|------------|------------------------|--------------------|   
|    1   | R1         | Leistungswiderstand 4,7&Omega;/5W          | Resistor_THT:R_Axial_Power_L25.0mm_W6.4mm_P27.94mm |   
|    1   | C1         | Elko 1000uF/35V        | _kh_library:CP_Radial_L20.0mm_D10.0mm_P5.08mm_Horizontal |   
|    1   | D1         | Diode 1N4007           | _kh_library:D_DO-41_SOD81_P3.81mm_Vertical_AnodeUp_kh |   
|    1   | J1, J2     | Wannenstecker 6-polig, stehend (Box_02x03_P2.54_Vertical_kh) | _kh_library:Box_02x03_P2.54mm_Vertical_kh |   
|    1   | J3, J5, J6 | Buchsenleiste 8-polig, lange Kontakte (Conn_01x08) | _kh_library:PinSocket_1x08_P2.54mm_Vertical_kh |   
|    1   | U1         | DC-DC-Wandler-Board StepDown_LM2596 | _kh_library:DCDC_StepDown_LM2596_PinsOnly |   
|    4   | U1         | 4 einzelne Pins               |   |   

__Bestückung__   
1. Leistungswiderstand R1   
2. Diode D1   
3. Buchsenleisten J3, J5, J6   
4. Wannenstecker J1, J2   
5. Elko C1   
6. Aufstecken des DC-DC-Step-Down-Wandlers LM2596   

Falls der LM2596-Board an den Ecken noch keine Pins angelötet hat: 4 einzelne Pins in die Enden von J5 und J6 stecken, das LM2596-Board aufstecken und die Pins verlöten.   

## 2.3 Inbetriebnahme der Netzteil-Trägerplatine AC_5V_supply_6pol_DCC
_*Wichtig:*_ Bei der ersten Inbetriebnahme des DC-DC-Wandlerboards muss die Ausgangsspannung am Potenziometer mit Hilfe eines Voltmeters und eines Schraubendrehers auf 5 V eingestellt werden. Das Drehen der Schraube am Potenziometer (blauer Quarder) entgegen dem Uhrzeigersinn verkleinert dabei die Ausgangsspannung.   

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
Nach NEM908D erfolgt die Verbindung von Modelleisenbahn-Modulen mit Kabeln mit 25-poligen Sub-D-Buchsen und 25-poligen Sub-D-Steckern an den Modul-Seitenteilen. Da Module unterschiedlich lang sein können, gibt es für die Modul-Stecker zwei Möglichkeiten:   
(1) Eine Platine mit zwei 25-poligen Steckern für kurze Module (z. B. 25cm oder 50 cm Länge).   
(2) Platinen mit einem 25-poligen Stecker und einer 10-poligen Schraubklemmenleiste für lange Module (z.B. 75 cm oder 100 cm Länge).   

Die Verbindungsplatinen sind so aufgebaut, dass die Netzteilplatine direkt aufgelötet werden kann. 
![bestückte Platine RW_5V_2SUB25](/images/300_RW_5V_2SUB25.png "bestückte Platine RW_5V_2SUB25")   
_Bild 6: Mit Netzteil bestückte Verbindungsplatine mit zwei 25-poligen Steckern_   



## 3.2 Platine mit zwei 25-poligen Sub-D-Steckern und Netzteil (RW_5V_2SUB25)   
Diese Platine wird zum Verbinden kurzer Module mit Längen von 25 cm oder 50 cm verwendet. Sie enthält Anschlüsse für ein 5V-Netzteil und das DCC-Steuersignal sowie Schraubklemmen für den DCC-Fahrstrom (SS, NN und SN, NS) und die Hilfsleitungen OA und OB. Die Platine ist so aufgebaut, dass sie beim Einbau in ein Modul symmetrisch zu einer Verstrebung liegen kann.   

![Platine RW_5V_2SUB25](/images/pcb_f/PCB_F_RW_5V_2SUB25_V1.png "Platine RW_5V_2SUB25")   
_Bild 7: Platine RW_5V_2SUB25_   
_*Platinengröße*_: 80 x 66 mm²   

__Stückliste__   
| Anzahl | Referenz     | Wert                   | Gehäuse            |   
|--------|--------------|------------------------|--------------------|   
|    2   | J1, J2       | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    3   | J7, J8, J9   | Schraubklemme 2-polig (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J5, J6, U1   | 5V-Netzteil-Platine     | _kh_library:AC_5V_supply_6pol_PinsOnly |   

__Bestückung__   
1. Schraubklemmen J7, J8, J9    
2. Sub-D-Stecker J1   
3. Einstecken und Verlöten der 5V-Netzteil-Platine in J5 und J6   

### Versionen
* V1 (241029): OK   

# 3.3 Platine mit 25-poligem Sub-D-Stecker, Schraubklemmen und Netzteil (RW_5V_SUB25_10)
Diese Platine wird bei längeren Modulen (Längen von 75 cm oder 100 cm) auf einer Seite verwendet. Sie enthält Anschlüsse für ein 5V-Netzteil und das DCC-Steuersignal sowie Schraubklemmen für den DCC-Fahrstrom (SS, NN und SN, NS), die Hilfsleitungen OA und OB und zusätzlich für alle Signale. Die Platine ist so aufgebaut, dass sie symmetrisch zu einer Verstrebung liegen kann.   

![Platine RW_5V_SUB25_10](/images/pcb_f/PCB_F_RW_5V_SUB25_10_V1.png "RW_5V_SUB25_10")   
_Bild 8: Platine RW_5V_SUB25_10_   
_*Platinengröße*_: 80 x 66 mm²   

__Stückliste__   
| Anzahl | Referenz     | Wert                   | Gehäuse            |   
|--------|--------------|------------------------|--------------------|   
|    1   | J1           | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    1   | J2           | Schraubklemme 10-polig oder 5x 2-polig |    |   
|    1   | J7, J8, J9   | Schraubklemme 2-polig (Screw_Terminal_01x02_P5) | _kh_library:Screw_Terminal_01x02_P5 |   
|    1   | J5, J6, U1   | 5V-Netzteil-Platine     | _kh_library:AC_5V_supply_6pol_PinsOnly |   

__Bestückung__   
1. Schraubklemmen J2, J7, J8, J9    
2. Sub-D-Stecker J1   
3. Einstecken und Verlöten der 5V-Netzteil-Platine in J5 und J6   

### Versionen
* V1 (241104): OK   

# 3.4 Platine mit 25-poligem Sub-D-Stecker und Schraubklemmen (CON_SubD_Screw10)
Diese Platine wird bei längeren Modulen (Längen von 75 cm oder 100 cm) auf einer der beiden Seiten (Ost oder West) verwendet. Sie führt lediglich die Anschlüsse des Sub-D-Steckers auf Schraubklemmen heraus.   

![Platine CON_SubD_Screw10](/images/pcb_f/PCB_F_CON_SubD_Screw10_V1.png "CON_SubD_Screw10")   
_Bild 9: Platine CON_SubD_Screw10_   
_*Platinengröße*_: 31 x 66 mm²   

__Stückliste__   
| Anzahl | Referenz     | Wert                   | Gehäuse            |   
|--------|--------------|------------------------|--------------------|   
|    1   | J1           | Sub-D-Stecker 25-polig (DB25_Plug) | _kh_library:DSUB-25_Male_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm |   
|    1   | J2           | Schraubklemme 10-polig oder 5x 2-polig |    |   

__Bestückung__   
1. Schraubklemmen J2    
2. Sub-D-Stecker J1   

### Versionen
* V1 (241104): OK   


[Zum Seitenanfang](#up)