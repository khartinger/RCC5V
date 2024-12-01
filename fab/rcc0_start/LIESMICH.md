<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 28.11.2024 <a name="up"></a><br>   
<h1>Wie starte ich das RCC-Projekt?</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Einleitung
Wenn ich mich dazu entschlossen habe, selbst die Steuerung meiner Modellbahn-Komponenten zu bauen, ist dazu etwas Zeit und Geld erforderlich. Es müssen sowohl Hardware- als auch 
Software-Voraussetzungen geschaffen werden.   
### Hardware
Für den Bau der RCC-Komponenten sind [Leiterplatten](#x20) und eine Art ["Grundausstattung an Bauteilen"](#x30) erforderlich. Wie man dazu kommt, ist weiter unten beschrieben.   
### Software
An Software wird das Open Source [Layoutprogramm KiCad](https://www.kicad.org/) mit dem Plug-in "PCBWay" und Visual Studio Code mit dem Plugin "PlatformIO" benötigt.   
Mit Hilfe von KiCad können die Leiterplatten-Layouts an eigene Bedürfnisse angepasst bzw. einfach durch professionelle Leiterplattenhersteller wie zB die Firma PCBWay hergestellt werden.   
Visual Studio Code ist erforderlich, um die Steuersoftware an die eigenen Bedürfnisse anzupassen und auf den ESP32 zu laden.   

[Zum Seitenanfang](#up)   
<a name="x20"></a>   

# Leiterplatten für RCC-Komponenten   
## Welche Leiterplatten benötige ich?
Welche Leiterplatten man benötigt, ist naturgemäß abhängig vom Anwendungsfall. Einige Platinen benötigt man aber auf jeden Fall.   

### Immer erforderliche Platinen
Immer erforderlich sind die beiden Shields für den ESP32   
* [/kicad/Shield_5V_DCC_6pol_V3](/kicad/Shield_5V_DCC_6pol_V3)   
* [/kicad/Shield_I2C_5V_3V3_V2](/kicad/Shield_I2C_5V_3V3_V2)   

und die Gleichrichterplatine zur Erzeugung der 5V:   
* [/kicad/AC_5V_6pol_DCC_V1](/kicad/AC_5V_6pol_DCC_V1)   

Weiters sinnvoll ist die Halterungsplatine:   
* [/kicad/RW_LEER_LED_V1](/kicad/RW_LEER_LED_V1)   

Die Hilfsplatinen zum Anschließen der Weiche(n) und der Ein- und Ausgänge der PCF8574 sind praktisch, könnten aber auch durch das direkte Anstecken der Leitungen an den Blöcken umgangen werden.
* [/kicad/CON_10pol_PIN_V2](/kicad/CON_10pol_PIN_V2)   
* [/kicad/CON_6pol_3_V1](/kicad/CON_6pol_3_V1) für Zwei-Weg-Weiche   
* [/kicad/CON_6pol_6_V1](/kicad/CON_6pol_6_V1) für Drei-Weg-Weiche   

### Strom- bzw. Modulversorgung
Hier muss man zwischen der Versorgung mit oder ohne ein 25-poliges Kabel und über die Länge des Moduls unterscheiden.   
Für kurze Module (bis 50 cm) mit 25-poligem Kabel:
* [/kicad/RW_5V_2SUB25_V2](/kicad/RW_5V_2SUB25_V2)   

Für lange Module (länger als 50 cm) mit 25-poligem Kabel:
* [/kicad/RW_5V_SUB25_10_V1](/kicad/RW_5V_SUB25_10_V1)   
* [/kicad/CON_SubD_Screw10_V1](/kicad/CON_SubD_Screw10_V1)   

Verwendet man keine 25-poligen SubD-Stecker, kann die Wechselspannung direkt an die Gleichrichterplatine und das DCC-Signal direkt an den DCC-Stecker der "Shield_5V_DCC_6pol_V3"-Platine angeschlossen werden.   

### Leiterplatten für RCC-Blöcke
RCC-Blöcke bestehen immer aus zwei Platinen: eine für die Steuerung (STRG) und eine für die Taster, Schalter und LED-Anzeige (LED).   

Möchte man __Zwei-Weg-Weichen__ schalten, so benötigt man die Platinen   
* [/kicad/RW_5V_W2_STRG_V2](/kicad/RW_5V_W2_STRG_V2)   
* [/kicad/RW_5V_W2_LED_V2](/kicad/RW_5V_W2_LED_V2)   

Möchte man __Drei-Weg-Weichen__ schalten, so benötigt man die Platinen   
* [/kicad/RW_5V_W3_STRG_V4](/kicad/RW_5V_W3_STRG_V4)   
* [/kicad/RW_5V_W3_LED_V4](/kicad/RW_5V_W3_LED_V4)   

Möchte man Gleise ein- und abschalten, so benötigt man die Platinen   
* [/kicad/RW_5V_2IO_STRG_V1](/kicad/RW_5V_2IO_STRG_V1)   
* [/kicad/RW_5V_2IO_LED_V2](/kicad/RW_5V_2IO_LED_V2)   

Möchte man Entkuppler betreiben, so benötigt man die Platinen   
* [/kicad/RW_5V_1OUT_STRG_V1](/kicad/RW_5V_1OUT_STRG_V1)   
* [/kicad/RW_5V_1OUT_LED_V2](/kicad/RW_5V_1OUT_LED_V2)   

## Vorgangsweise zur Erstellung der Leiterplatten
Folgende Vorgangsweise ist sinnvoll:   
1. Installation des Open Source [Layoutprogramm KiCad](https://www.kicad.org/) mit dem Plug-in "PCBWay".   
2. Herstellen der benötigten Leiterplatten   
Für jede Komponente gibt es im Verzeichnis /kicad die zur Herstellung der Leiterplatte [erforderlichen KiCad-Dateien](/kicad). Die Leiterplatten sind zweiseitig, durchkontaktiert und mit Siebdruck auf beiden Seiten entworfen. Möchte man die Leiterplatten selbst herstellen, sind entsprechende Anpassungen erforderlich.   
Möchte man die Leiterplatten dagegen zB von der Firma PCBWay fertigen lassen, ist folgende Vorgangsweise sinnvoll:   

1. Laden des KiCad-Projekts in KiCad (aus dem Verzeichnis /kikad holen)   
2. Starten des Leiterplatteneditors (oder Mausklick auf *.kicad_pcb-Datei)   
3. Mausklick auf das Icon PCBWay: Es werden die Leiterplatten-Daten an [https://www.pcbway.com](https://www.pcbway.com) geschickt und die Webseite der Firma öffnet sich im Browser.   
4. Nach kurzer Zeit werden im Browser die Vorder- und Rückseite der Leiterplatte angezeigt. Da die Kosten für 5 oder 10 Stück derzeit (Dezember 2024) gleich sind, sollte man bei "Quantity (single):" die Stückzahl auf 10 pcs ausbessern.   
5. Durch Anklicken der Schaltfläche "Save to cart" werden die Daten in den Warenkorb übertragen und durch die Firma PCBWay automatisch überprüft.   
6. Das KiCad-Projekt kann jetzt geschlossen werden und das nächste Projekt gestartet werden. Diese Schritte wiederholt man so lange, bis sich die Daten aller Leiterplatten im Warenkorb der Firma PCBWay befinden.   
7. Sind alle Leiterplatten überprüft, wählt man die Versandart und bezahlt die Ware. Hat man es eilig, kann man als Transportunternehmen "DHL Express" wählen, das ist zwar nicht sehr billig aber schnell, zuverlässig und die Paketverfolgung ist super.   

[Zum Seitenanfang](#up)   
<a name="x30"></a>   

# Grundausstattung an Bauteilen   
Für die Herstellung der RCC-Komponenten werden sowohl mechanische als auch elektronische Bauteile benötigt. Im folgenden werden vor allem Links zu Amazon und AliExpress angeführt, obwohl es gerade bei diesen Verkaufsplattformen des öfteren vorkommt, dass die angeführten Seiten von Lieferanten nach einiger Zeit oft nicht mehr verfügbar sind.   
Viele der Bauteile, wie zB Schrauben, werden in größeren Gebinden verkauft, hier reicht es meist, ein Stück zu kaufen.   
Die unten angegebenen Mengen reichen für den Bau _eines_ Moduls mit mehreren Blöcken.   
Die angegebenen Preise dienen nur der Information und waren im Dezember 2024 gültig (ohne Black Friday etc.).   

## Mechanische Bauteile

| Anzahl | Stück/Pkg | Bezeichnung | Quelle | ca. Euro |   
| ------ | --------- | ----------- | ------ | -------- |   
|    1   |     60    | Abstandshalter M2x10+3mm Sechskant Messing M&auml;nnlich Weiblich | [https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1](https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) |  12,91 |   
|    1   |    200    | Sechskantmuttern M2x0,4 mm | [https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5](https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5) |   7,04 |   
|    1   |   100   | M2 x 20 Kreuzschlitz-Schrauben, 304 Edelstahl, metrische Maschinenschraube, Bolzen | [https://www.amazon.de/dp/B07QH9KHMG?ref=ppx_yo2ov_dt_b_fed_asin_title](https://www.amazon.de/dp/B07QH9KHMG?ref=ppx_yo2ov_dt_b_fed_asin_title) | 11,09 |   
|    1   |   100   | Selbstbohrende Schrauben M2,6 x 8 Edelstahl 304 Schwarzes Zink Plattiert Selbstschneidend Kreuzschlitz Pan Kopf | [https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp) |   7,75 |   

## Elektrische Bauteile

| Anzahl | Stück/Pkg | Bezeichnung | Quelle | ca. Euro |   
| ------ | --------- | ----------- | ------ | -------- |   
|    1   |   50   | Schraubklemmen für Leiterplatte, 2-polig, schwarz oder blau, 5,0 mm | [https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu) |  12,36 |   
|    1   |   50 <br> 30  | Schraubklemmen für Leiterplatte, 3-polig, schwarz oder blau, 5,0 mm | [https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu) <br> [https://www.amazon.de/dp/B071GMT7ZZ?ref=ppx_yo2ov_dt_b_fed_asin_title](https://www.amazon.de/dp/B071GMT7ZZ?ref=ppx_yo2ov_dt_b_fed_asin_title) |  15,16 <br> 7,04 |   
|    1   |   10   | 8-polige Buchsenleiste mit kurzen Kontakten | [https://de.aliexpress.com/item/1005005488898046.html?spm=a2g0o.productlist.main.9.669btr3dtr3d6w&algo_pvid=65fd6970-3b51-4d0e-940c-e7cddb3caf78&aem_p4p_detail=202411290703446772873239296340000289000&algo_exp_id=65fd6970-3b51-4d0e-940c-e7cddb3caf78-4&pdp_npi=4%40dis%21EUR%211.88%211.60%21%21%211.94%211.65%21%40211b613917328926243906031e2cec%2112000033281493435%21sea%21AT%21738334575%21X&curPageLogUid=lXR8wevtzrac&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202411290703446772873239296340000289000_4](https://de.aliexpress.com/item/1005005488898046.html?spm=a2g0o.productlist.main.9.669btr3dtr3d6w&algo_pvid=65fd6970-3b51-4d0e-940c-e7cddb3caf78&aem_p4p_detail=202411290703446772873239296340000289000&algo_exp_id=65fd6970-3b51-4d0e-940c-e7cddb3caf78-4&pdp_npi=4%40dis%21EUR%211.88%211.60%21%21%211.94%211.65%21%40211b613917328926243906031e2cec%2112000033281493435%21sea%21AT%21738334575%21X&curPageLogUid=lXR8wevtzrac&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202411290703446772873239296340000289000_4) |   1,88 |   
|    1   |  100   | 8-polige Buchsenleiste mit langen Kontakten (11 mm) | [https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF](https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF) |   8,37 |   
|    1   | 10 <br> 20 | Wannenstecker 6-polig (2x3), senkrecht | [https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) <br> [https://www.amazon.de/dp/B0BGRMLJD7?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1](https://www.amazon.de/dp/B0BGRMLJD7?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)|   6,05 <br> 10,68 |   
|    1   | 10 <br> 20 | Wannenstecker 10-polig (2x5), senkrecht | [https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) <br> [https://www.amazon.de/dp/B0BGRM9GZP?ref=ppx_yo2ov_dt_b_fed_asin_title](https://www.amazon.de/dp/B0BGRM9GZP?ref=ppx_yo2ov_dt_b_fed_asin_title) |   6,15 <br> 11,09 |   


SubD-Stecker 25-polig, abgewinkelt
Fassung mit gedrehten Buchsen 4-polig
Fassung mit gedrehten Buchsen 8-polig

## Elektronische Bauteile
ESP32


## Zukaufteile
| Bild | Anzahl | Stück /Pkg | Bezeichnung | ca. Euro | Quelle |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   
| ![DC-DC-Converter](/images/parts/96_dc_dc_converter.png "DC-DC-Converter") | 1 | 5 | DC-DC-Wandler-Board StepDown_LM2596 | 9,56 | [Amazon](https://www.amazon.de/dp/B0823P6PW6?ref=ppx_yo2ov_dt_b_fed_asin_title) |    
| ![I2C-Logic-Level-Converter](/images/parts/96_i2c_logic_level_converter.png "I2C-Logic-Level-Converter") | 1 | 1 | 5V-3V Dual Channel I2C IIC Logic-Level-Converter Modul Bi-Directional | 0,28 | [AliExpress](https://de.aliexpress.com/item/32903662283.html?spm=a2g0o.order_list.order_list_main.25.681e5c5fkWDadk&gatewayAdapt=glo2deu) |   

## Sonstiges
| Bild | Anzahl | Stück /Pkg | Bezeichnung | ca. Euro | Quelle |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   
| ![solder wire](/images/parts/300_solderwire1.png "solder wire ")  | 1 | 1 | Lötzinn, Bleifreies Lot mit Kolophonium Kern (Sn99 Ag0,3 Cu0,7/0,8mm,50g) | 11,09 | [Amazon](https://www.amazon.de/dp/B07Z7JQ4SX?ref=ppx_yo2ov_dt_b_fed_asin_title) |   
| ![Flat Ribbon Cable 6pol](/images/parts/300_flatRibbonCable_6pol.png "Flat Ribbon Cable 6pol")  | 1 | 5m | Flachbandkabel 6-polig, farbig | 4,80 | [AliExpress](https://de.aliexpress.com/item/1005005382567357.html?spm=a2g0o.order_list.order_list_main.236.63df5c5fSSD4mY&gatewayAdapt=glo2deu) |   
| ![Flat Ribbon Cable 10pol](/images/parts/300_flatRibbonCable_10pol.png "Flat Ribbon Cable 10pol") | 1 | 5m | Flachbandkabel 10-polig, farbig | 5,82 | [AliExpress](https://de.aliexpress.com/item/1005005382567357.html?spm=a2g0o.order_list.order_list_main.236.63df5c5fSSD4mY&gatewayAdapt=glo2deu) |   


# Fertigen der Komponenten
Hat man - nach einiger Wartezeit - sowohl die Leiterplatten als auch die Bauteile zur Verfügung, geht es an das Herstellen der Komponenten:   
* [Komponenten für die Stromversorgung](/fab/rcc1_supply/LIESMICH.md)   
* [Erweiterungen (Shields) für den ESP32](/fab/rcc2_esp32/LIESMICH.md)   
* [RCC Blocks](/fab/rcc4_block/LIESMICH.md)   
* [Zusatzplatinen](/fab/rcc5_add_ons/LIESMICH.md)   

[Zum Seitenanfang](#up)   