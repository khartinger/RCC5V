<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>P20 Feed-In</h1><b><big>Modul-Einspeisung mit 20-poligen Flachbandkabeln</big></b><br>  
Stand: 7.10.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x01"></a>   

## Worum geht es?

Gemäß [NEM 908](https://github.com/khartinger/RCC5V/tree/main/info/con_NEM908/LIESMICH.md) werden Eisenbahn-Module über 10- bis 13-polige Kabel und 25-polige Sub-D-Buchsen miteinander verbunden. Die Verbindung erfolgt durch die Seitenteile der Module.

### Nachteile

* Die Kabel sind aufwendig zu löten (Sub-D-Buchsen).
* Bei Modulen, die auf einer Unterlage stehen, ist das Abstecken der Stecker schwierig, da das Modul-Innenleben ohne Anheben der Module nicht zugänglich ist.  

Aus diesem Grund wird hier eine **alternative Modulversorgung mit 20-poligen Flachbandkabeln** vorgestellt. Diese Verbindung wird im Folgenden als **„P20“** bezeichnet.  
**„P20“** ist nur für **Zweileitersysteme** geeignet, da keine Adern zur Mittelleiterversorgung vorgesehen sind. Für Dreileitersysteme müsste man das P20-System mit 26-poligen Steckern realisieren.  

<a name="TableOfContents"></a>   
##  Inhalt
1. [Flachbandkabel, Buchsen und Stecker](#x10)   
2. [P20-Boards](#x20)   

<a name="x10"></a>   
<a name="x11"></a>   


# 1. Flachbandkabel, Buchsen und Stecker

## 1.1 Pinbelegung

Jede Ader eines Flachbandkabels hat einen Querschnitt von **0,08 bis 0,09 mm² (AWG 28)** und kann mit maximal **1 A** belastet werden. Werden alle Adern gleichzeitig belastet, muss der zulässige Strom aufgrund der Erwärmung des Kabels auf etwa **0,4 bis 0,7 A pro Ader** reduziert werden.  

Im **P20-System** werden daher jeweils **zwei Adern parallel geschaltet**:

![P20_pins](/images/300_P20_Pins.png)  

_Vorteil_: Stecker kann auf die Bauteilseite **oder** Lötseite gelötet werden.  


## 1.2 Montage auf dem Modul-Rahmen
Üblicherweise werden immer zwei Wannenstecker nebeneinander parallel geschaltet. Der Pin-Abstand beträgt dabei 0,4" = 10,16 mm.  
In der Rückwand des Rahmens wird folgende Öffnung benötigt:  
![Loch Wannenstecker](/images/300_P20_frame_hole.png)  

<a name="x20"></a>   
<a name="x21"></a>   


# 2. P20-Boards

## 2.1 Modulanschlüsse
Es gibt zwei Arten:  
* 20-poliger Stecker auf Schraubklemmen  
* 20-poliger Stecker auf Netzteilplatine  

<a name="x211"></a>   

### 2.1.1 20-poliger Stecker auf Schraubklemmen
Das Board `CON_20_3x_Screw10_V1` wird verwendet, wenn das Modul keine Blöcke hat und lediglich die Fahrspannung und eventuell Licht etc. benötigt werden.  

![]()   

Der Bau ist []() beschreiben.  

<a name="x212"></a>   

### 2.1.2 20-poliger Stecker auf Netzteilplatine
Das Board `CON_20_2x_2x6pol_R_V2` erzeugt die 5V-Spannung und stellt die 6-poligen POWER- und DCC- Anschlüsse zur Verfügung. Der Fahrstrom ist auf Schraubklemmen herausgeführt.  

<a name="x22"></a>   

## 2.2 Umsetzung auf Sub-D-Stecker
Dazu gibt es zwei Varianten  
* 20-poliger Stecker auf einen Sub-D-Stecker
* 20-poliger Stecker auf zwei Sub-D-Stecker

<a name="x221"></a>   

### 2.2.1 20-poliger Stecker auf einen Sub-D-Stecker

<a name="x222"></a>   

### 2.2.2 20-poliger Stecker auf zwei Sub-D-Stecker
Diese Variante wird zB innerhalb von Modulen verwendet

[Zum Seitenanfang](#up)   