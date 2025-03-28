<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 22.02.2025 <a name="up"></a><br>   
<h1>Erg&auml;nzungsplatinen f&uuml;r das RCC-System</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Erg&auml;nzungsplatinen sind Platinen, die f&uuml;r den Betrieb des RCC-Systems nicht unbedingt notwendig sind, allerdings die Handhabung oder Verkabelung einfacher und &uuml;bersichtlicher machen. So kann man zB die I²C-Signale eines Blocks entweder direkt am 10-poligen Wannenstecker J4 abgreifen oder aber ein 10-poliges Flachbandkabel und das Erg&auml;nzungsboard `CON_10pol_PIN` verwenden.   
Folgende Erg&auml;nzungsplatinen sind hilfreich und werden auf dieser Seite beschrieben:   
* [Halterung f&uuml;r Schaltbl&ouml;cke (RW_LEER_LED)](#x20)   
* [Fahrstromverteiler (CON_2pol_141)](#x30)   
* [Verteilerplatine von 6-poligem Kabel auf 3 Schraubklemmen (CON_6pol_3)](#x40)   
* [Verteilerplatine von 6-poligem Kabel auf 6 Schraubklemmen (CON_6pol_6)](#x50)   
* [Fahrstromschalter einfach (CON_1xIO)](#x60)   
* [Fahrstromschalter zweifach (CON_2xIO)](#x70)   
* [Verteilerplatine von 10-poligem Kabel auf Pins (CON_10pol_2x4)](#x80)   
* [Alte Verteilerplatine von 10-poligem Kabel auf Pins (CON_10pol_PIN)](#x90)   
   
<a name="x20"></a>   

# 2. Halterung f&uuml;r Schaltbl&ouml;cke (RW_LEER_LED)   
Die Halterung f&uuml;r Schaltbl&ouml;cke (Blockbefestigungsplatine) wird mit M 2,6 x 10 Schrauben auf den Rahmen eines Eisenbahnmoduls geschraubt und dient zur Befestigung eines Schaltblocks (f&uuml;r Weichen, Entkuppler, Fahrstromschalter). Sie enth&auml;lt Bohrungen f&uuml;r LEDs und Taster/Schalter, damit diese durch den Rahmen des Moduls hin zur Bedienseite durchgesteckt werden k&ouml;nnen.   
__*Wichtig:*__ Die Halterungen nicht zu fest anschrauben, d.h. nur so fest schrauben, dass sich die Sechskant-Abstandshalter nicht nach innen neigen.   

![Montierte Befestigungsplatine](/images/300_RW_LEER_LED.png "Befestigungsplatine montiert")   
_Bild 1: Auf einem 3D-gedruckten Rahmen montierte Befestigungsplatinen f&uuml;r Schaltbl&ouml;cke_   

![Befestigungsplatine](/images/pcb_f/PCB_F_RW_LEER_LED_V1.png "Befestigungsplatine")   
_Bild 2: Befestigungsplatine f&uuml;r Schaltbl&ouml;cke_   

_*Platinengr&ouml;&szlig;e*_: 41 x 41 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/SRW_LEER_LED_V1](/fab/kicad/RW_LEER_LED_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz       | Wert                   | Anmerkung          |   
|--------|----------------|------------------------|--------------------|   
|    2   | J1, J2         | 8-polige Buchsenleiste mit kurzen Kontakten | zB bei [AliExpress](https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF)   |   
|    4   | H1, H2, H3, H4 | Abstandshalter M2x10+3mm Sechskant Messing M&auml;nnlich Weiblich | zB bei [Amazon](https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)  |   
|    4   | H1, H2, H3, H4 | Sechskantmuttern M2x0,4 mm | zB bei [Amazon](https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5)  |   
|    4   | S1, S2, S3, S4 | Selbstbohrende Schrauben M2,6 x 10 Edelstahl 304 Schwarzes Zink Plattiert Selbstschneidend Kreuzschlitz Pan Kopf | zB bei [Amazon](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp)  |   

### Best&uuml;ckung   
1. Einl&ouml;ten der beiden 8-poligen Buchsenleisten (mit kurzen Kontakten) bei J1 und J2.   
2. Befestigung der vier M2 HEX-Abstandshalter M2x10+3mm mit M2 Muttern.   

### Versionen
* V1 (241022): OK   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Fahrstromverteiler `CON_2pol_141` 
Diese Platine dient zum Verteilen zweipoliger Signale wie zB des Fahrstroms.   

![CON_2pol_141](/images/200_CON_2pol_141.png "CON_2pol_141")   
_Bild 3: Die best&uuml;ckte "CON_2pol_141"-Platine_   

![CON_2pol_141_circuit](/images/200_CON_2pol_141_circuit.png "CON_2pol_141_circuit")   
_Bild 4: Schaltplan der "CON_2pol_141"-Platine_   

![Print Verteilen zweipoliger Signale](/images/pcb_f/PCB_F_CON_2pol_141_V1.png "Print Verteilen zweipoliger Signale")   
_Bild 5: Platine zum Verteilen zweipoliger Signale_   

_*Platinengr&ouml;&szlig;e*_: 57 x 21 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_2pol_141_V1](/fab/kicad/CON_2pol_141_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    6   | J1,J2,J3,J4,J5,J6 | Schraubenklemme 2polig | _kh_library:Screw_Terminal_01x02_P5 |   

### Best&uuml;ckung   
1. Schraubklemmen J1 bis J6   

### Versionen
* V1 (250117): OK   

[Zum Seitenanfang](#up)   
<a name="x40"></a>   

# 4. Verteilerplatine von 6-poligem Kabel auf 3 Schraubklemmen (CON_6pol_3)   
Diese Platine dient zum Anschluss einer Zweiwegweiche, daher sind nur die Pins 1, 3 und 5 herausgef&uuml;hrt. Die Dr&auml;hte der Weiche k&ouml;nnen direkt angeschraubt werden, wobei der mittlere Anschluss der gemeinsame R&uuml;ckleiter ist.   
Bei der Version 2 wurde der Wannenstecker umgedreht, damit das Flachbandkabel nicht verdreht werden muss. Damit dreht sich auch die Reihenfolge der Schraubklemmen-Pins um.   

![CON_6pol_3_V1](/images/200_CON_6pol_3_V1.png "CON_6pol_3_V1") &nbsp; ![CON_6pol_3_V2](/images/200_CON_6pol_3_V2.png "CON_6pol_3_V2")   
_Bild 6: Die best&uuml;ckte "CON_6pol_3"-Platine V1 (links) und V2 (rechts)_   

![CON_6pol_3_circuit_V1](/images/200_CON_6pol_3_V1_circuit.png "CON_6pol_3_circuit_V1") &nbsp; ![CON_6pol_3_circuit_V2](/images/200_CON_6pol_3_V2_circuit.png "CON_6pol_3_circuit_V2")   
_Bild 7: Schaltpl&auml;ne der "CON_6pol_3"-Platine_   

![Klemme f&uuml;r Zweiwegweiche V1](/images/pcb_f/PCB_F_CON_6pol_3_V1.png "Klemme f&uuml;r Zweiwegweiche V1") &nbsp; ![Klemme f&uuml;r Zweiwegweiche V2](/images/pcb_f/PCB_F_CON_6pol_3_V2.png "Klemme f&uuml;r Zweiwegweiche V2")   
_Bild 8: Platine Anschlussklemme f&uuml;r Zweiwegweiche V1 (links) und V2 (rechts)_   

_*Platinengr&ouml;&szlig;e*_: 25 x 18 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_6pol_3_V1](/fab/kicad/CON_6pol_3_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6        | Schraubklemme 3-polig (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> zB von [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Best&uuml;ckung   
1. Wannenstecker J5   
2. Schraubklemme J6   

### Versionen
* V1 (241104): OK, geeignet f&uuml;r 0° und 90°-Stecker, Flachbandkabel verdrehen   
* V2 (250208): OK   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Verteilerplatine von 6-poligem Kabel auf 6 Schraubklemmen (CON_6pol_6)   
Diese Platine wird z.B. zum Anschluss von Dreiwegweichen verwendet, da diese &uuml;ber zwei Weichenantriebe verf&uuml;gen. Die Pins sind gruppiert: die ersten drei Pins (Pin1, Pin3, Pin5) geh&ouml;ren zum ersten Weichenantrieb, die zweiten drei (Pin2, Pin4, Pin6) zum zweiten Antrieb.   
Bei der Version 2 wurde der Wannenstecker umgedreht, damit das Flachbandkabel nicht verdreht werden muss. Damit dreht sich auch die Reihenfolge der Schraubklemmen-Pins um.   

![CON_6pol_6_V1](/images/200_CON_6pol_6_V1.png "CON_6pol_6_V1") &nbsp; ![CON_6pol_6_V2](/images/200_CON_6pol_6_V2.png "CON_6pol_6_V2")   
_Bild 9: Die best&uuml;ckte "CON_6pol_6"-Platine V1 (links) und V2 (rechts)_   

![CON_6pol_6_V1_circuit](/images/200_CON_6pol_6_V1_circuit.png "CON_6pol_6_V1_circuit") &nbsp; ![CON_6pol_6_V2_circuit](/images/200_CON_6pol_6_V2_circuit.png "CON_6pol_6_V2_circuit")   
_Bild 10: Schaltpl&auml;ne der "CON_6pol_6"-Platine_   

![Klemme f&uuml;r Dreiwegweiche V1](/images/pcb_f/PCB_F_CON_6pol_6_V1.png "Klemme f&uuml;r Dreiwegweiche V1") &nbsp; ![Klemme f&uuml;r Dreiwegweiche V2](/images/pcb_f/PCB_F_CON_6pol_6_V2.png "Klemme f&uuml;r Dreiwegweiche V2")   
_Bild 11: Platine Anschlussklemme f&uuml;r Dreiwegweiche, V1 (links) und V2 (rechts)_   

_*Platinengr&ouml;&szlig;e*_: 41 x 18 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_6pol_6_V1](/fab/kicad/CON_6pol_6_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6, J7    | Schraubklemme 3-polig (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> zB von [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu)|   

_Anmerkung_: Statt der beiden 3-poligen Schraubklemmen k&ouml;nnen auch drei 2-polige Klemmen verwendet werden...   

### Best&uuml;ckung   
1. Wannenstecker J5   
2. Schraubklemmen J6, J7   

### Versionen
* V1 (241104): OK, geeignet f&uuml;r 0° und 90°-Stecker, Flachbandkabel verdrehen   
* V2 (250208): OK   

[Zum Seitenanfang](#up)   
<a name="x60"></a>   

# 6. Fahrstromschalter einfach (CON_1xIO)
Diese Platine vereinfacht den Anschluss eines Fahrstrom-Schaltblocks. Sie leitet den Fahrstrom zum 2IO-Block und stellt das geschaltete Fahrstromsignal an einer zweipoligen Schraubklemme zur Verf&uuml;gung.   

![CON_1xIO_V1](/images/200_CON_1xIO_V1.png "CON_1xIO_V1") &nbsp; ![CON_1xIO_V2](/images/200_CON_1xIO_V2.png "CON_1xIO_V2")   
_Bild 12: Die best&uuml;ckte "CON_1xIO"-Platine V1 (links) und V2 (rechts)_   

![CON_1xIO_V1_circuit](/images/200_CON_1xIO_V1_circuit.png "CON_1xIO_V1_circuit")   
_Bild 13: Schaltplan der "CON_1xIO"-Platine_   

![Print Fahrstromanschluss V1](/images/pcb_f/PCB_F_CON_1xIO_V1.png "Print Fahrstromanschluss V1") &nbsp; ![Print Fahrstromanschluss V2](/images/pcb_f/PCB_F_CON_1xIO_V2.png "Print Fahrstromanschluss V2")    
_Bild 14: Platine zum Anschluss des geschalteten Fahrstroms V1 (links) und V2 (rechts)_   

_*Platinengr&ouml;&szlig;e*_: 32 x 21 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_1xIO_V1](/fab/kicad/CON_1xIO_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J1        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    3   | J3,J5,J6 | Schraubenklemme 2polig | _kh_library:Screw_Terminal_01x02_P5 |   

### Best&uuml;ckung   
1. Wannenstecker J1   
2. Schraubklemmen J3, J5, J6   

### Versionen
* V1 (250117): OK, geeignet f&uuml;r 0° und 90°-Stecker, Flachbandkabel verdrehen   
* V2 (250208): OK   

[Zum Seitenanfang](#up)   
<a name="x70"></a>   

# 7. Fahrstromschalter zweifach (CON_2xIO)   
Diese Platine vereinfacht den Anschluss von Fahrstromschaltern. Sie leitet den Fahrstrom zu zwei 2IO-Bl&ouml;cken und stellt das geschaltete Stromsignal auf zwei zweipoligen Schraubklemmen zur Verf&uuml;gung.   

![CON_2xIO_V1](/images/200_CON_2xIO_V1.png "CON_2xIO_V1") &nbsp; ![CON_2xIO_V2](/images/200_CON_2xIO_V2.png "CON_2xIO_V2")   
_Bild 15: Die best&uuml;ckte "CON_2xIO"-Platine V1 (links) und V2 (rechts)_   

![CON_2xIO_circuit_V1](/images/200_CON_2xIO_V1_circuit.png "CON_2xIO_circuit_V1")   
_Bild 16: Schaltplan der "CON_2xIO"-Platine_   

![Print 2x Fahrstromanschluss V1](/images/pcb_f/PCB_F_CON_2xIO_V1.png "Print 2x Fahrstromanschluss V1") &nbsp; ![Print 2x Fahrstromanschluss V2](/images/pcb_f/PCB_F_CON_2xIO_V2.png "Print 2x Fahrstromanschluss V2")    
_Bild 17: Platinen zum Anschluss zweier geschalteten Fahrstr&ouml;me_   

_*Platinengr&ouml;&szlig;e*_: 47 x 21 mm²   
_*Link zu den KiCad-Dateien*_: [Version 1 /fab/kicad/CON_2xIO_V1](/fab/kicad/CON_2xIO_V1)   
   [Version 2 /fab/kicad/CON_2xIO_V2](/fab/kicad/CON_2xIO_V2)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    2  | J1, J2        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    4   | J3,J4,J5,J6 | Schraubenklemme 2polig | _kh_library:Screw_Terminal_01x02_P5 |   

### Best&uuml;ckung   
1. Wannenstecker J1, J2   
2. Schraubklemmen J3, J4, J5, J6   

### Versionen
* V1 (250117): OK, geeignet f&uuml;r 0° und 90°-Stecker, Flachbandkabel verdrehen   
* V2 (250208): OK   

[Zum Seitenanfang](#up)   
<a name="x80"></a>   

# 8. Verteilerplatine von 10-poligem Kabel auf Pins (CON_10pol_2x4)   
Diese Platine dient zum Umsetzen eines 10-poligen Flachbandkabels vom Schaltblock-Wannenstecker J4 auf Pins. Die Pins sind auf zwei Vierer-Gruppen aufgeteilt (Eingang und Ausgang), damit der Anschluss an die Pins der PCF8574-I/O-Expander leichter ist.   

![CON_10pol_2x4_V1](/images/300_CON_10pol_2x4_V1.png "CON_10pol_2x4_V1")   
_Bild 18: Die best&uuml;ckte Platine CON_10pol_2x4_   

![CON_10pol_2x4_V1_circuit](/images/200_CON_10pol_2x4_V1_circuit.png "CON_10pol_2x4_V1_circuit")   
_Bild 19: Schaltplan der "CON_2xIO"-Platine_   

![Print zum Verteilen der Leitungen des 10-poligen Kabels V1](/images/pcb_f/PCB_F_CON_10pol_2x4_V1.png "Print zum Verteilen der Leitungen des 10-poligen Kabels V1")   
_Bild 20: Platine zum Verteilen der Leitungen des 10-poligen Flachbandkabels von J4_   

_*Platinengr&ouml;&szlig;e*_: 30 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_10pol_2x4_V1](/fab/kicad/CON_10pol_2x4_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J1        | Wannenstecker 10-polig (Box_02x05_P2.54_Vertical) | _kh_library:Box_02x05_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J2, J3    | Stiftleiste 4-polig (Conn_01x04) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   

### Vorbereitung
* Herunterschneiden von zweimal vier Pins von einer (zB 40-poligen) geraden Stiftleiste.   

### Best&uuml;ckung   
1. Stiftleisten J2, J3   
2. Wannenstecker J1   

### Versionen
* V1 (250208): OK   

[Zum Seitenanfang](#up)   
<a name="x90"></a>   

# 9. Alte Verteilerplatine von 10-poligem Kabel auf Pins (CON_10pol_PIN)   
Diese Platine dient zum Verbinden des 10-poligen Schaltblock-Ein-/Ausgang-Kabels mit den PCF8574-IO-Expander-Pins. Die Pins sind in je vier Eingangs- und Ausgangssignale gruppiert. Weiters sind je zwei Anschl&uuml;sse f&uuml;r 5V und Masse vorhanden. Diese werden im Normalfall nicht ben&ouml;tigt. Als 10-poliger Wannenstecker kann sowohl die senkrechte als auch die abgewinkelte Variante verwendet werden.   
Statt dieser Platine sollte die Platine CON_10pol_2x4 verwendet werden, da bei dieser das 10-polige Kabel nicht verdreht werden muss.   

![CON_10pol_PIN](/images/200_CON_10pol_PIN.png "CON_10pol_PIN")   
_Bild 21: Die best&uuml;ckte "CON_10pol_PIN"-Platine, einmal mit geradem und einmal mit 90° gedrehtem Stecker_   

![Klemme f&uuml;r I²C-IO-Pins](/images/pcb_f/PCB_F_CON_10pol_PIN_V2.png "Klemme f&uuml;r I²C-IO-Pins")   
_Bild 22: Platine zum Verteilen der Leitungen des 10-poligen Flachbandkabels von J4 mit 5V/0V-Pins_   

_*Platinengr&ouml;&szlig;e*_: 33 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/fab/kicad/CON_10pol_PIN_V2](/fab/kicad/CON_10pol_PIN_V2)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J1        | Wannenstecker 10-polig (Box_02x05_P2.54_Vertical) | _kh_library:Box_02x05_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J2, J3    | Stiftleiste 4-polig (Conn_01x04) | _kh_library:PinSocket_1x04_P2.54mm_Vertical_kh |   
|    2   | J4, J5    | Stiftleiste 2-polig (Conn_01x02) | _kh_library:PinSocket_1x02_P2.54mm_Vertical_kh |   

### Best&uuml;ckung   
1. Stiftleisten J2 bis J5   
2. Wannenstecker J1   

[Zum Seitenanfang](#up)   