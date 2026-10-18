
<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>20-polige Verbindungskabel</h1><b><big>RCC7: Flachbandkabel statt Sub-D-Kabel</big></b><br>  
Stand: 18.10.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x01"></a>   


# Worum geht es?
Nach **NEM 908D** werden Eisenbahn-Module mit **SUB-D-25-Steckverbindern** nach DIN 41652 und Leitungen mit einem Querschnitt von mindestens **1 mm²** verbunden.

Die Herstellung dieser Kabel ist jedoch **aufwändig und zeitintensiv**.

Für wenige Module mit einer kleinen Anzahl von Zügen können auch **20-polige Flachbandkabel** verwendet werden. Bei zwei parallel geschalteten Adern mit jeweils **0,09 mm²** sollte der Strom **1,5 A nicht überschreiten**.

Dieses Kapitel beschreibt Komponenten für eine **Verdrahtung mit 20-poligen Kabeln**.

<a name="TableOfContents"></a>   
##  Inhalt
1. [Verbindung Sub-D-Stecker auf Wannenstecker `CON_20_SubD_*`](#x10)   
2. [Wannenstecker auf Schraubklemmen](#x20)   
3. [Wannenstecker mit Netzteil](#x30)   

<a name="x10"></a>   
<a name="x11"></a>   


# 1. Verbindung Sub-D-Stecker auf Wannenstecker

## 1.1 Einleitung

Für den Übergang vom 25-poligen Sub-D-Stecker auf den 20-poligen Wannenstecker gibt es vier Varianten:  

(A) **2x Sub-D-Stecker auf zwei Wannenstecker** (`PCB_F_CON_20_2x_2xSubD_V1`)  
(B) Sub-D-Stecker WEST auf Wannenstecker (`CON_20_SubD_W`)  
(C) Sub-D-Stecker OST auf Wannenstecker (`CON_20_SubD_O`)  
(D) Sub-D-Stecker OST **ausgekreuzt** auf Wannenstecker (`CON_20_SubD_OX`)  

<a name="x12"></a>   

## 1.2 2x Sub-D-Stecker auf zwei Wannenstecker

![rcc7_CON_20_2x_2xSubD_V1_assembled](/images/300_rcc7_CON_20_2x_2xSubD_V1_assembled.png "rcc7_CON_20_2x_2xSubD_V1_assembled")   

### Schaltplan
![rcc7_CON_20_2x_2xSubD_V1_circuit](/images/600_rcc7_CON_20_2x_2xSubD_V1_circuit.png "rcc7_CON_20_2x_2xSubD_V1_circuit")   

### Bestückung
![rcc7_CON_20_2x_2xSubD_W_V1_pcb](/images/pcb_f/PCB_F_CON_20_2x_2xSubD_V1.png "rcc7_CON_20_2x_2xSubD_W_V1_pcb")   

1. Wannenstecker J2, J3  
2. Sub-D Stecker J1, J4  
3. Draht J5-J6 und J7-J8  


### Versionen
* V1 (260825): OK  

<a name="x13"></a>   

## 1.3 Sub-D-Stecker WEST auf Wannenstecker (`CON_20_SubD_W`)

### Schaltplan
![rcc7_CON_20_SubD_W_V1_circuit](/images/600_rcc7_CON_20_SubD_W_V1_circuit.png "rcc7_CON_20_SubD_W_V1_circuit")   

### Bestückung
![rcc7_CON_20_SubD_W_V1_pcb](/images/pcb_f/PCB_F_CON_20_SubD_W_V1.png "rcc7_CON_20_SubD_W_V1_pcb")   

1. Draht J3-J4  
2. Wannenstecker J5  
3. Sub-D Stecker J1  

### Versionen
* V1 (260820): OK  

<a name="x14"></a>   

## 1.4 Sub-D-Stecker OST auf Wannenstecker (`CON_20_SubD_O`)

### Schaltplan
![rcc7_CON_20_SubD_O_V1_circuit](/images/600_rcc7_CON_20_SubD_O_V1_circuit.png "rcc7_CON_20_SubD_O_V1_circuit")   

### Bestückung
![rcc7_CON_20_SubD_O_V1_pcb](/images/pcb_f/PCB_F_CON_20_SubD_O_V1.png "rcc7_CON_20_SubD_O_V1_pcb")   

1. Wannenstecker J2  
2. Sub-D Stecker J1  
3. Draht J3-J4  

### Versionen
* V1 (260820): OK  

<a name="x15"></a>   

## 1.5 Sub-D-Stecker OST ausgekreuzt auf Wannenstecker (`CON_20_SubD_OX`)

### Schaltplan
Die Schaltung entspricht der OST-Schaltung, lediglich der Wannenstecker ist um 180° verdreht.  

### Bestückung
![rcc7_CON_20_SubD_OX_V1_pcb](/images/pcb_f/PCB_F_CON_20_SubD_OX_V1.png "rcc7_CON_20_SubD_OX_V1_pcb")   

1. Wannenstecker J2  
2. Sub-D Stecker J1  

### Versionen
* V1 (260820): OK  

<a name="x20"></a>   
<a name="x21"></a>   

# 2. Wannenstecker auf Schraubklemmen

## 2.1 Einleitung

Für den Übergang vom 20-poligen Wannenstecker auf Schraubklemmen gibt es drei Varianten:  
(A) **Drei Wannenstecker mit allen Schraubklemmen auf einer Seite** (`PCB_F_CON_20_3x_Screw10`)  
(B) Wannenstecker mit allen Schraubklemmen auf einer Seite (`CON_20_Screw10`)  
(C) Wannenstecker mit 6 und 4 Schraubklemmen (`CON_20_Screw64`)  


<a name="x22"></a>   

## 2.2 Drei Wannenstecker mit allen Schraubklemmen auf einer Seite (`PCB_F_CON_20_3x_Screw10`)

![rcc7_CON_20_3x_Screw10_V1_assembled](/images/300_rcc7_CON_20_3x_Screw10_V1_assembled.png "rcc7_CON_20_Screw10_V1_assembled")   


### Schaltplan
![rcc7_CON_20_3x_Screw10_V1_circuit](/images/600_rcc7_PCB_F_CON_20_3x_Screw10_V1_circuit.png "rcc7_CON_20_Screw10_V1_circuit")   

### Bestückung
![rcc7_CON_20_3x_Screw10_V1_pcb](/images/pcb_f/PCB_F_CON_20_3x_Screw10_V1_jlc.png "rcc7_CON_20_3x_Screw10_V1_pcb")   

Wird das Board auf der **Nordseite** eines Moduls verwendet, so wird es folgendermaßen bestückt:   
1. Wannenstecker J1 und J7 auf die **Lötseite** (auf Polung achten: Pin 1 und 2)  

Auf die **Bauteilseite** löten:  

2. Wannenstecker J8  
3. Schraubklemmen J2 und J6 (schwarz)  
4. Schraubklemmen J3 bis J5 (grün-rot-grün) zusammenstecken, löten  

### Versionen
* V1 (261006): OK  

<a name="x23"></a>   

## 2.3 Wannenstecker mit allen Schraubklemmen auf einer Seite (`CON_20_Screw10`)  

### Schaltplan
![rcc7_CON_20_Screw10_V1_circuit](/images/600_rcc7_CON_20_Screw10_V1_circuit.png "rcc7_CON_20_Screw10_V1_circuit")   

### Bestückung
![rcc7_CON_20_Screw10_V1_pcb](/images/pcb_f/PCB_F_CON_20_Screw10_V1.png "rcc7_CON_20_Screw10_V1_pcb")   

1. Wannenstecker J1  
2. Schraubklemmen J2 bis J6  

### Versionen
* V1 (261006): OK  

<a name="x24"></a>   

## 2.4 Wannenstecker mit 6 und 4 Schraubklemmen (`CON_20_Screw64`)  

### Schaltplan
Der Schaltplan ist ähnlich wie bei `CON_20_Screw10`, lediglich bei J2 und J6 ist die Verdrahtung vertauscht.  
![rcc7_CON_20_Screw64_V1_circuit](/images/600_rcc7_CON_20_Screw64_V1_circuit.png "rcc7_CON_20_Screw64_V1_circuit")   

### Bestückung
![rcc7_CON_20_Screw64_V1_pcb](/images/pcb_f/PCB_F_CON_20_Screw64_V1.png "rcc7_CON_20_Screw64_V1_pcb")   

1. Wannenstecker J1  
2. Schraubklemmen J2 bis J6  

### Versionen
* V1 (260820): OK  

<a name="x30"></a>   
<a name="x31"></a>   

# 3. Wannenstecker mit Netzteil

## 3.1 Einleitung

Für den Wannenstecker mit Netzteil gibt es mehrere Varianten, die sich durch die Anzahl an Wannensteckern 
(1 oder 2) und den Vorwiderstand (4,7 Ω oder PTC) unterscheiden. Die beste Version ist `CON_20_2x_2x6pol_R`, die zwei Wannenstecker hat und beide Vorwiderstandsvarianten ermöglicht.  

<a name="x32"></a>   

## 3.2 Zwei Wannenstecker mit Netzteil (`CON_20_2x_2x6pol_R`)

### Schaltplan
![rcc7_CON_20_2x_2x6pol_R_V2_circuit](/images/600_rcc7_CON_20_2x_2x6pol_R_V2_circuit.png "rcc7_CON_20_2x_2x6pol_R_V2_circuit")   

### St&uuml;ckliste   
| Anzahl | Referenz          | Wert                | Geh&auml;use            |   
|--------|-------------------|---------------------|--------------------|   
| 1 | C1 | Elko 1000 μF/35V | CP_Radial_L16.8mm_D10.0mm_P5.08mm_Horizontal_small_2 |   
| 1 | D1 | Diode 1N4007 | D_DO-41_SOD81_P12.7mm_Horizontal_kh |   
| 1 | F1 | PTC RXEF110 oder RXEF160 | Fuse_PTC_P5.08mm_D12.8mm_Horizontal_kh |   
| 1 | J1, J2 | Wannenstecker 6-polig, stehend, Raster 2,54 mm | Box_02x03_P2.54mm_Vertical_kh |   
| 2 | J4, J10 | Wannenstecker 10-polig, stehend, Raster 2.54 mm | Box_02x10_P2.54mm_Vertical_kh |   
| 2 | J5, J6 | Buchsenleiste 8-polig, kurze Kontakte| PinSocket_1x06_P2.54mm_Vertical_kh |   
| 2 | J7 | Schraubklemme 2-polig grün | Screw_Terminal_01x02_P5 |   
| 1 | J8, J9 | Schraubklemme 2-polig schwarz | Screw_Terminal_01x02_P5_8 |   
| 1 | U1 | DCDC_StepDown_LM2596 | DCDC_StepDown_LM2596_PinsOnly |   

**Anmerkungen**  
1. ENTWEDER F1 ODER R1 (Widerstand 4,7 Ω/5W) bestücken.  

## Vorbereitung
1. Schwarze Schraubklemmen J8, J9 zusammenstecken.  

### Bestückung
![rcc7_CON_20_2x_2x6pol_R_V2_pcb](/images/pcb_f/PCB_F_CON_20_2x_2x6pol_R_V2_jlc.png "rcc7_CON_20_2x_2x6pol_R_V2_pcb")   

Auf die **Lötseite** löten  

1. Wannenstecker J4 und J10 (20-polig, auf Polung achten: Pin 1 und 2)  

Auf die **Bauteilseite** löten  

2. PTC F1  
3. Diode D1 (auf Polung achten)  
4. 8-polige (!) Buchsenleisten J5 und J6  
5. 6-polige Wannenstecker J1, J2 (auf Polung achten)  
6. Schraubklemmen J7 (grün)  
7. Schraubklemmen J8, J9 (schwarz)  
8. Elko C1 (auf Polung achten)  

### Versionen
* V1 (260820): Änderungen zu V2:  
  * Schaltung: J3 entfernt, R1, J10 hinzugefügt.  
  * Layout: 6-polige Stecker gedreht.  
* V2 (261007): OK


<a name="x33"></a>   

## 3.3 Ein Wannenstecker mit Netzteil und 4,7 Ω Widerstand (`CON_20_2x6pol`)  

### Schaltplan
![rcc7_CON_20_2x6pol_V1_circuit](/images/600_rcc7_CON_20_2x6pol_V1_circuit.png "rcc7_CON_20_2x6pol_V1_circuit")   

### Bestückung
![rcc7_CON_20_2x6pol_V1_pcb](/images/pcb_f/PCB_F_CON_20_2x6pol_V1.png "rcc7_CON_20_2x6pol_V1_pcb")   

1. Wannenstacker J4 (20-polig) auf die **Lötseite** der Platine (auf Polung achten)  
2. Leistungswiderstand R1  
3. Diode D1 (auf Polung achten)  
4. 8-polige Stiftleisten J3, J5 und J6  
5. 6-polige Wannenstecker J1, J2 (auf Polung achten)  
6. Schraubklemmen J7 (grün)  
7. Schraubklemmen J8, J9 (schwarz)  
8. Elko C1  

### Versionen
* V1 (260820): Bild von J7 auf Siebdruck-Bauteilseite um 180° verdreht. Funktion OK.  
* V2 (260827): OK

<a name="x33"></a>   


[Zum Seitenanfang](#up)   