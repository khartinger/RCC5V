
<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>20-polige Verbindungskabel</h1><b><big>RCC7: Flachbandkabel statt Sub-D-Kabel</big></b><br>  
Stand: 25.8.2026    &nbsp; &nbsp; &nbsp; &nbsp;
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

Für den Übergang vom 25-poligen Sub-D-Stecker auf den 20-poligen Wannenstecker gibt es drei Varianten:  

(A) Sub-D-Stecker WEST auf Wannenstecker (`CON_20_SubD_W`)  
(B) Sub-D-Stecker OST auf Wannenstecker (`CON_20_SubD_O`)  
(C) Sub-D-Stecker OST **ausgekreuzt** auf Wannenstecker (`CON_20_SubD_OX`)  

<a name="x12"></a>   

## 1.2 Sub-D-Stecker WEST auf Wannenstecker (`CON_20_SubD_W`)

### Schaltplan
![rcc7_CON_20_SubD_W_V1_circuit](/images/600_rcc7_CON_20_SubD_W_V1_circuit.png "rcc7_CON_20_SubD_W_V1_circuit")   

### Bestückung
![rcc7_CON_20_SubD_W_V1_pcb](/images/pcb_f/PCB_F_CON_20_SubD_W_V1.png "rcc7_CON_20_SubD_W_V1_pcb")   
1. Draht J3-J4  
2. Wannenstecker J5  
3. Sub-D Stecker J1  

### Versionen
* V1 (260820): OK  

<a name="x13"></a>   

## 1.3 Sub-D-Stecker OST auf Wannenstecker (`CON_20_SubD_O`)

### Schaltplan
![rcc7_CON_20_SubD_O_V1_circuit](/images/600_rcc7_CON_20_SubD_O_V1_circuit.png "rcc7_CON_20_SubD_O_V1_circuit")   

### Bestückung
![rcc7_CON_20_SubD_O_V1_pcb](/images/pcb_f/PCB_F_CON_20_SubD_O_V1.png "rcc7_CON_20_SubD_O_V1_pcb")   
1. Draht J3-J4  
2. Wannenstecker J2  
3. Sub-D Stecker J1  

### Versionen
* V1 (260820): OK  

<a name="x14"></a>   

## 1.4 Sub-D-Stecker OST ausgekreuzt auf Wannenstecker (`CON_20_SubD_OX`)

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

Für den Übergang vom 20-poligen Wannenstecker auf Schraubklemmen gibt es zwei Varianten:  

(A) Wannenstecker mit allen Schraubklemmen auf einer Seite (`CON_20_Screw10`)  
(B) Wannenstecker mit 6 und 4 Schraubklemmen (`CON_20_Screw64`)  

<a name="x22"></a>   

## 2.2 Wannenstecker mit allen Schraubklemmen auf einer Seite (`CON_20_Screw10`)  

### Schaltplan
![rcc7_CON_20_Screw10_V1_circuit](/images/600_rcc7_CON_20_Screw10_V1_circuit.png "rcc7_CON_20_Screw10_V1_circuit")   

### Bestückung
![rcc7_CON_20_Screw10_V1_pcb](/images/pcb_f/PCB_F_CON_20_Screw10_V1.png "rcc7_CON_20_Screw10_V1_pcb")   

1. Wannenstecker J1  
2. Schraubklemmen J2 bis J6  

### Versionen
* V1 (260820): OK  

<a name="x23"></a>   

## 2.3 Wannenstecker mit 6 und 4 Schraubklemmen (`CON_20_Screw64`)  

### Schaltplan
Der Schaltplan ist ähnlich wie bei `CON_20_Screw10`, lediglich bei J2 und J6 ist die Verdrahtung vertauscht.  
![rcc7_CON_20_Screw64_V1_circuit](/images/600_rcc7_CON_20_Screw64_V1_circuit.png "rcc7_CON_20_Screw64_V1_circuit")   

### Bestückung
![rcc7_CON_20_Screw64_V1_pcb](/images/pcb_f/PCB_F_CON_20_Screw64_V1.png "rcc7_CON_20_Screw64_V1_pcb")   

1. Wannenstecker J1  
2. Schraubklemmen J2 bis J6  

### Versionen
* V1 (260820): OK  

# 3. Wannenstecker mit Netzteil

## 3.1 Einleitung

Für den Wannenstecker mit Netzteil gibt es zwei Varianten:  

(A) Wannenstecker mit Netzteil (`CON_20_2x6pol`)  
(B) Zwei Wannenstecker mit Netzteil (`CON_20_2x_2x6pol`)  

<a name="x32"></a>   

## 3.2 Wannenstecker mit Netzteil (`CON_20_2x6pol`)  

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