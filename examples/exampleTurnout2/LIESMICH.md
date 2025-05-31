<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 27.11.2024 <a name="up"></a><br>   
<h1>Beispiel-Verdrahtung einer Weiche</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Worum geht es hier?
Diese Anleitung beschreibt Schritt für Schritt die Entstehung des RCC-Systems zum Schalten einer Weiche. Die Weiche wird durch einen elektrischen Weichenantrieb mit Endabschaltung gestellt (zB. Fleischmann 640000).  
Zu Beginn wird die Weiche direkt mit Wechselstrom aus einem Trafo geschaltet und danach werden der Reihe nach weitere Komponenten eingebaut, bis das Gesamtsystem fertig ist.   

# 1. Direktes Schalten der Weiche mit Wechselstrom
Beim direkten Schalten einer Weiche mit Wechselstrom wird die Wechselspannung an einen Anschluss eine Spule der Weiche und an den Rückleiter gelegt. Da die Anschlussdrähte der Weiche empfindlich sind, werden sie direkt an eine Platine [`CON_6pol_3`](/fab/rcc5_add_ons/LIESMICH.md#x40) geschraubt. Diese Platine dient im Weiteren als Verbindung der Weichenanschlüsse zum RCC-System.   

Das Schalten erfolgt durch Verbinden von Pin 1 oder Pin 5 mit Wechselspannung. Der Rückleiter liegt fix an Pin 3.   
![W2_Direct_Switching1](./images/300_W2_DirectSwitching1.png "W2_Direct_Switching1")   
_Bild 1: Schaltplan zu "Direktes Schalten einer Zweiwegweiche"_   

![W2_Direct_Switching2](./images/480_W2_DirectSwitching2.png "W2_Direct_Switching2")   
_Bild 2: Direktes Schalten einer Zweiwegweiche_   

# 2. Einspeisen der Wechselspannung über Sub-D-Stecker
In der [Norm NEM 908D](/info/con_NEM908/LIESMICH.md) wird die Verbindung von Eisenbahnmodulen durch 25-polige Sub-D-Stecker und Buchsen beschreiben. Daher ist es naheliegend, auch hier die Versorgungsspannung der Weiche über ein 25-poliges Buchsenkabel zuzuführen.   
Das folgende Bild zeigt die Verwendung des [25-poligen Steckers mit 5V-Netzteil](/fab/rcc1_supply/LIESMICH.md#x30) zum Einspeisen der Wechselspannung:   

![W2_Sub-D_1](./images/480_W2_Sub-D_1.png "W2_Sub-D_1")   
_Bild 3: Schaltplan zum Einspeisen der Wechselspannung über Sub-D-Stecker_   

![W2_Sub-D_2](./images/480_W2_Sub-D_2.png "W2_Sub-D_2")   
_Bild 4: Einspeisen der Wechselspannung über Sub-D-Stecker_   

Im _Bild 4_ ist links ein (10-poliges) graues Testkabel mit Schraubklemmen und 25-poliger Buchse (silber) zu sehen. Dieses ist die Platine mit Sub-D-Stecker und 5V-Netzteil angesteckt. Die zweipolige, rote Schraubklemme in der Klemmenreihe stellt die Wechselspannung für die Weiche zur Verfügung.   



# ... To Do ...

[Zum Seitenanfang](#up)   