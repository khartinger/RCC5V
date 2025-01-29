<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 28.11.2024 <a name="up"></a><br>   
<h1>Zusatzplatinen</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung   
Die hier beschriebenen Erg&auml;nzungsplatinen dienen zB als Halterung oder f&uuml;r das Umsetzen von Flachbandkabeln mit IDC-Steckverbindern auf Pins bzw. Schraubklemmen.   

<a name="x20"></a>   

# 2. Blockbefestigungsplatine   
Die Blockbefestigungsplatine wird auf den Rahmen eines Eisenbahnmoduls geschraubt und 
dient zur Befestigung eines Schaltblocks (f&uuml;r Weichen, Entkuppler, Fahrstromschalter). Sie enth&auml;lt Bohrungen f&uuml;r LEDs und Taster/Schalter, damit diese durch den Rahmen des Moduls hin zur Bedienseite durchgesteckt werden k&ouml;nnen.   

![Montierte Befestigungsplatine](/images/300_RW_LEER_LED.png "Befestigungsplatine montiert")   
_Bild 1: Auf einem 3D-gedruckten Rahmen montierte Befestigungsplatinen f&uuml;r Schaltbl&ouml;cke_   

![Befestigungsplatine](/images/pcb_f/PCB_F_RW_LEER_LED_V1.png "Befestigungsplatine")   
_Bild 2: Befestigungsplatine f&uuml;r Schaltbl&ouml;cke_   

_*Platinengr&ouml;&szlig;e*_: 41 x 41 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/SRW_LEER_LED_V1](/kicad/RW_LEER_LED_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz       | Wert                   | Anmerkung          |   
|--------|----------------|------------------------|--------------------|   
|    2   | J1, J2         | 8-polige Buchsenleiste mit kurzen Kontakten | zB bei [AliExpress](https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF)   |   
|    4   | H1, H2, H3, H4 | Abstandshalter M2x10+3mm Sechskant Messing M&auml;nnlich Weiblich | zB bei [Amazon](https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)  |   
|    4   | H1, H2, H3, H4 | Sechskantmuttern M2x0,4 mm | zB bei [Amazon](https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5)  |   
|    4   | S1, S2, S3, S4 | Selbstbohrende Schrauben M2,6 x 8 Edelstahl 304 Schwarzes Zink Plattiert Selbstschneidend Kreuzschlitz Pan Kopf | zB bei [Amazon](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp)  |   

### Best&uuml;ckung   
1. Einl&ouml;ten der beiden 8-poligen Buchsenleisten (mit kurzen Kontakten) bei J1 und J2.   
2. Befestigung der vier M2 HEX-Abstandshalter M2x10+3mm mit M2 Muttern.   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# 3. Verteilerplatine von 10-poligem Kabel auf Pins   
Diese Platine dient zum Verbinden des 10-poligen Schaltblockein-/ausgang-Kabels mit den PCF8574-IO-Expander-Pins. Die Pins sind in je vier Eingangs- und Ausgangssignale gruppiert. Weiters sind je zwei Anschl&uuml;sse f&uuml;r 5V und Masse vorhanden. Diese werden im Normalfall nicht ben&ouml;tigt. Als 10-poliger Wannenstecker kann sowohl die senkrechte als auch die abgewinkelte Variante verwendet werden.   

![CON_10pol_PIN](/images/200_CON_10pol_PIN.png "CON_10pol_PIN")   
_Bild 3: Die best&uuml;ckte "CON_10pol_PIN"-Platine, einmal mit geradem und einmal mit 90° gedrehtem Stecker_   

![Klemme f&uuml;r I²C-IO-Pins](/images/pcb_f/PCB_F_CON_10pol_PIN_V2.png "Klemme f&uuml;r I²C-IO-Pins")   
_Bild 4: Stifte f&uuml;r I²C-IO-Pins_   

_*Platinengr&ouml;&szlig;e*_: 33 x 15 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/CON_10pol_PIN_V2](/kicad/CON_10pol_PIN_V2)   

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
<a name="x40"></a>   

# 4. Verteilerplatine von 6-poligem Kabel auf 3 Schraubklemmen   
Diese Platine dient zum Anschluss einer Zweiwegweiche, daher sind nur die Pins 1, 3 und 5 herausgef&uuml;hrt. Die Dr&auml;hte der Weiche k&ouml;nnen direkt angeschraubt werden, wobei der mittlere Anschluss der gemeinsame R&uuml;ckleiter ist.   

![CON_6pol_3](/images/200_CON_6pol_3a.png "CON_6pol_3")   
_Bild 5: Die best&uuml;ckte "CON_6pol_3"-Platine_   

![CON_6pol_3_circuit](/images/200_CON_6pol_3_circuit.png "CON_6pol_3_circuit")   
_Bild 6: Schaltplan der "CON_6pol_3"-Platine_   

![Klemme f&uuml;r Zweiwegweiche](/images/pcb_f/PCB_F_CON_6pol_3_V1.png "Klemme f&uuml;r Zweiwegweiche")   
_Bild 7: Platine Anschlussklemme f&uuml;r Zweiwegweiche_   

_*Platinengr&ouml;&szlig;e*_: 25 x 18 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/CON_6pol_3_V1](/kicad/CON_6pol_3_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6        | Schraubklemme 3-polig (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> zB von [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   

### Best&uuml;ckung   
1. Wannenstecker J5   
2. Schraubklemme J6   

[Zum Seitenanfang](#up)   
<a name="x50"></a>   

# 5. Verteilerplatine von 6-poligem Kabel auf 6 Schraubklemmen   
Diese Platine wird z.B. zum Anschluss von Dreiwegweichen verwendet, da diese &uuml;ber zwei Weichenantriebe verf&uuml;gen. Die Pins sind gruppiert: die ersten drei Pins (Pin1, Pin3, Pin5) geh&ouml;ren zum ersten Weichenantrieb, die zweiten drei (Pin2, Pin4, Pin6) zum zweiten Antrieb.   

![CON_6pol_6](/images/200_CON_6pol_6.png "CON_6pol_6")   
_Bild 8: Die best&uuml;ckte "CON_6pol_6"-Platine_   

![CON_6pol_6_circuit](/images/200_CON_6pol_6_circuit.png "CON_6pol_6_circuit")   
_Bild 9: Schaltplan der "CON_6pol_6"-Platine_   

![Klemme f&uuml;r Dreiwegweiche](/images/pcb_f/PCB_F_CON_6pol_6_V1.png "Klemme f&uuml;r Dreiwegweiche")   
_Bild 10: Anschlussklemme f&uuml;r Dreiwegweiche_   

_*Platinengr&ouml;&szlig;e*_: 41 x 18 mm²   
_*Link zu den KiCad-Dateien*_: [/kicad/CON_6pol_6_V1](/kicad/CON_6pol_6_V1)   

### St&uuml;ckliste   
| Anzahl | Referenz  | Wert              | Geh&auml;use            |   
|--------|-----------|-------------------|--------------------|   
|    1   | J5        | Wannenstecker 6-polig (Box_02x03_P2.54_Vertical) | _kh_library:Box_02x03_P2.54mm_Vertical_kh <br> zB von [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) |   
|    2   | J6, J7    | Schraubklemme 3-polig (Screw_Terminal_01x03_P5) | _kh_library:Screw_Terminal_01x03_P5 <br> zB von [AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.63.2dc65c5fS73c6M&gatewayAdapt=glo2deu)|   

_Anmerkung_: Statt der beiden 3-poligen Schraubklemmen k&ouml;nnen auch drei 2-polige Klemmen verwendet werden...   

### Best&uuml;ckung   
1. Wannenstecker J5   
2. Schraubklemmen J6, J7   

[Zum Seitenanfang](#up)   