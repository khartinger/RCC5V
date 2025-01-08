<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2024-11-27 <a name="up"></a><br>   
<h1>How do I start the RCC project?</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# Introduction
If I have decided to build the control system for my model railroad components myself, this requires some time and money. Both hardware and software prerequisites must be created.   
### Hardware
To build the RCC components, [circuit boards](#x20) and a kind of [“basic equipment of components”](#x30) are required. How to do this is described below.   
### Software
In terms of software, the open source [layout program KiCad](https://www.kicad.org/) with the "PCBWay” plug-in and Visual Studio Code with the "PlatformIO” plug-in are required.   
With the help of KiCad, the PCB layouts can be adapted to your own requirements or simply produced by professional PCB manufacturers such as PCBWay.   
Visual Studio Code is required to adapt the control software to your own needs and to load it onto the ESP32.   

[To the top of the page](#up)   
<a name="x20"></a>   

# PCBs for RCC components   
## Which PCBs do I need?
Which PCBs you need naturally depends on the application. However, some PCBs are required in any case.   

### Always required circuit boards
The two shields for the ESP32 are always required   
* [/kicad/Shield_5V_DCC_6pol_V3](/kicad/Shield_5V_DCC_6pol_V3)   
* [/kicad/Shield_I2C_5V_3V3_V2](/kicad/Shield_I2C_5V_3V3_V2)   

and the rectifier board for generating the 5V:   
* [/kicad/AC_5V_6pol_DCC_V1](/kicad/AC_5V_6pol_DCC_V1)   

The mounting board is also useful:   
* [/kicad/RW_LEER_LED_V1](/kicad/RW_LEER_LED_V1)   

The auxiliary boards for connecting the switch(es) and the inputs and outputs of the PCF8574 are practical, but could also be bypassed by connecting the lines directly to the blocks.
* [/kicad/CON_10pol_PIN_V2](/kicad/CON_10pol_PIN_V2)   
* [/kicad/CON_6pol_3_V1](/kicad/CON_6pol_3_V1) for two-way switch   
* [/kicad/CON_6pol_6_V1](/kicad/CON_6pol_6_V1) for three-way switch   

### Power or module supply
A distinction is made here,   
* whether the supply is via a 25-pin cable or not and   
* how long the module is.   

For short modules (up to 50 cm) with 25-pin cable:
* [/kicad/RW_5V_2SUB25_V2](/kicad/RW_5V_2SUB25_V2)   

For long modules (longer than 50 cm) with 25-pin cable:
* [/kicad/RW_5V_SUB25_10_V1](/kicad/RW_5V_SUB25_10_V1)   
* [/kicad/CON_SubD_Screw10_V1](/kicad/CON_SubD_Screw10_V1)   

If you do not use 25-pin SubD connectors, the AC voltage can be connected directly to the rectifier board and the DCC signal directly to the DCC connector of the "Shield_5V_DCC_6pol_V3” board.   

### Printed circuit boards for RCC blocks
RCC blocks always consist of two circuit boards: one for the controller (CTRL) and one for the buttons, switches and LED display (LED).   

If you want to switch __two-way switches__, you need the boards   
* [/kicad/RW_5V_W2_STRG_V2](/kicad/RW_5V_W2_STRG_V2)   
* [/kicad/RW_5V_W2_LED_V2](/kicad/RW_5V_W2_LED_V2)   

If you want to switch __three-way switches__, you need the boards   
* [/kicad/RW_5V_W3_STRG_V4](/kicad/RW_5V_W3_STRG_V4)   
* [/kicad/RW_5V_W3_LED_V4](/kicad/RW_5V_W3_LED_V4)   

If you want to switch tracks on and off, you need the boards   
* [/kicad/RW_5V_2IO_STRG_V1](/kicad/RW_5V_2IO_STRG_V1)   
* [/kicad/RW_5V_2IO_LED_V2](/kicad/RW_5V_2IO_LED_V2)   

If you want to operate decouplers, you need the boards   
* [/kicad/RW_5V_1OUT_STRG_V1](/kicad/RW_5V_1OUT_STRG_V1)   
* [/kicad/RW_5V_1OUT_LED_V2](/kicad/RW_5V_1OUT_LED_V2)   

## Procedure for creating the printed circuit boards
The following procedure makes sense:   
1. install the open source [layout program KiCad](https://www.kicad.org/) with the "PCBWay” plug-in.   
2. create the required PCBs   
The KiCad files [required to produce the PCB](/kicad) are available for each component in the /kicad directory. The PCBs are double-sided, plated through and designed with screen printing on both sides. If you want to manufacture the PCBs yourself, appropriate adjustments are required.   
If, on the other hand, you want to have the PCBs manufactured by PCBWay, for example, the following procedure makes sense:   

1. load the KiCad project into KiCad (get it from the /kikad directory)   
2. start the PCB editor (or click on *.kicad_pcb file)   
3. click on the PCBWay icon: the PCB data is sent to [https://www.pcbway.com](https://www.pcbway.com) and the company's website opens in the browser.   
4. after a short time, the front and back of the PCB are displayed in the browser. Since the costs for 5 or 10 pieces are currently (December 2024) the same, you should change the number of pieces to 10 pcs under "Quantity (single):”.   
5. by clicking on the "Save to cart” button, the data is transferred to the shopping cart and automatically checked by PCBWay.   
6. the KiCad project can now be closed and the next project can be started. These steps are repeated until the data of all PCBs are in the PCBWay shopping cart.   
7. once all the PCBs have been checked, select the shipping method and pay for the goods. If you are in a hurry, you can choose "DHL Express” as the transport company, which is not very cheap but is fast, reliable and the parcel tracking is great.   

[To the top of the page](#up)   
<a name="x30"></a>   

# Basic equipment of components   
Both mechanical and electronic components are required to manufacture the RCC components. Links to Amazon and AliExpress are listed below, although it is often the case with these sales platforms that the suppliers' websites listed are often no longer available after some time.   
Many of the components, such as screws, are sold in larger packs, so it is usually sufficient to buy one pack.   
The quantities given below are sufficient to build _one_ module with several blocks.   
The prices given are for information only and were valid in December 2024 (without Black Friday etc.).   

## Mechanical components

| Image | Quantity | Parts/Pack | Description | approx. Euro | Source |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   
| ![spacers_M2x10](/images/parts/200_spacers_M2x10.png "spacers_M2x10") | 1 | 60 | Spacers M2x10+3mm hexagon, brass, male - female | 12,91 |[Amazon](https://www.amazon.de/gp/product/B0BXDHL2YP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) |   
| ![hexagon_nut](/images/parts/200_hexagon_nut_M2.png "hexagon_nut") | 1 | 200 | Hexagon nuts M2x0.4 mm | 7.04 | [Amazon](https://www.amazon.de/sourcing-map-Kohlenstoff-Hexagonal-Silbert%C3%B6ne/dp/B07J3CNWNH?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XV7AI5VJHRNO&dib=eyJ2IjoiMSJ9.MHtsj7g4rQQHzcEBoDSBTefFXlBpLiPak-77Ew8DQdnch54LTfQom_Svg_2BIso3QxatpAXNGjuD_TT8uikaPVO2vq_IzIqDBOCyX_QfxDATecIY9QkDAz6IUOnvZA_RSCDw_3kbhgHFVZ1MLUZNX6gsIAtxGrU_nRcfKAt-VyjIQrtZtglmInq7OQayV2_GSyy3EAzNJhSf2FRx0JTuB3SJDEX1nLEjR_1xIk_G5d-xxm34Aa2N-QFYcTqkUv6zk1FQvrPmimDPScbvLf-zL8ezOEqI5DSUhTjka0Lap6o.uVzu6mRNlGns069q_PKQHMF7v7nZeAUiJ6ZofHofMrY&dib_tag=se&keywords=Mutter+M2&nsdOptOutParam=true&qid=1732790211&sprefix=mutter+m2%2Caps%2C137&sr=8-5) |   
| ![cross-head_screw](/images/parts/200_cross-head_screw_M2x20.png "cross-head_screw") | 1 | 100 | M2 x 20 cross-head screws, 304 stainless steel, metric machine screw, bolt | 11.09 |[Amazon](https://www.amazon.de/dp/B07QH9KHMG?ref=ppx_yo2ov_dt_b_fed_asin_title) |   
| ![self-drilling_screw_M2.6x8](/images/parts/200_self-drilling_screw_M2.6x8.png "self-drilling_screw_M2.6x8") | 1 | 100 | Self-drilling screws M2.6 x 8 stainless steel 304 Black Zinc Plated Self-tapping Phillips Pan head | 7.75 |[Amazon](https://www.amazon.de/dp/B0CR8CBDTX?psc=1&smid=A14R2UVD1VQLGA&ref_=chk_typ_imgToDp) |   
| ![self-drilling_screw_M2x4](/images/parts/200_self-drilling_screw_M2x4.png "self-drilling_screw_M2x4") | 1 | 40 (400) | Self-drilling Screws M2 x 4 Phillips Pan Head (Box) | 9.78 | [Amazon](https://www.amazon.de/dp/B07HHWZQH7?ref=ppx_yo2ov_dt_b_fed_asin_title) |   
| ![LED holder](/images/parts/300_ledholder.png "LED holder") | 1 | 20 | LED socket 3mm, chrome brass, protruding bezel, 6 mm diameter, screw plate mounting | 12.98 | [AliExpress Daier_Store](https://de.aliexpress.com/item/1005007180033606.html?spm=a2g0o.order_list.order_list_main.33.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   
| ![switch_cap](/images/parts/300_switch_cap.png "switch_cap") | 1 | 7x10 | Knob for button/switch 8x8mm, length 10mm, 7 different colors | 1.92 | [AliExpress Ali_CanHui](https://de.aliexpress.com/item/1005001524633998.html?spm=a2g0o.order_list.order_list_main.193.40f55c5f5h69eX&gatewayAdapt=glo2deu) |   
| | 1 | 100 | Knob for button/switch 8x8mm, length 7mm, different colors | 2,17 | [AliExpress TEJIATE_Store](https://de.aliexpress.com/item/4000504035520.html?spm=a2g0o.order_list.order_list_main.322.40f55c5f5h69eX&gatewayAdapt=glo2deu) |   

## Electrical components

| Image | Quantity | Parts/Pack | Description | approx. Euro | Source |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   
| ![Taster_12mm](/images/parts/200_taster_12mm.png "Taster_12mm") | 1 | 5 | Waterproof push button stainless steel button ON OFF 12mm 2A/12V/24V/125V/250V with wire (protruding) | 8,05 | [Amazon](https://www.amazon.de/dp/B08L49F7DV?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) |
| ![pushbutton_8x8](/images/parts/200_switch_8x8.png "pushbutton_8x8") | 1 | 10 | Micropushbutton (DPDT), Unlock 8x8mm | 6,12 | [AliExpress BXV_computer chipset_Store](https://de.aliexpress.com/item/1005006962539948.html?spm=a2g0o.order_list.order_list_main.78.40f55c5f5h69eX&gatewayAdapt=glo2deu) |
| ![switch_8x8](/images/parts/200_switch_8x8.png "switch_8x8") | 1 | 10 | Microswitch (DPDT), Locking 8x8mm | 6,02 | [AliExpress BXV_computer chipset_Store](https://de.aliexpress.com/item/1005006962539948.html?spm=a2g0o.order_list.order_list_main.78.40f55c5f5h69eX&gatewayAdapt=glo2deu) |
| ![PCB_Screw_Connector_2P](/images/parts/300_PCB_Screw_Connector_2P.png "PCB_Screw_Connector_2P") | 1 | 50 | Screw terminals for printed circuit board, 2-pole, black or blue, 5,0 mm | 12,36 |[AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu) |
| ![PCB_Screw_Connector_3P](/images/parts/300_PCB_Screw_Connector_3P.png "PCB_Screw_Connector_3P") | 1 | 50 <br> 30 | Screw terminals for printed circuit board, 3-pole, black or blue, 5,0 mm |   15,16 <br> 7,04 |[AliExpress](https://de.aliexpress.com/item/1005007145396958.html?spm=a2g0o.order_list.order_list_main.102.f9f35c5fko3NNE&gatewayAdapt=glo2deu) <br> [Amazon](https://www.amazon.de/dp/B071GMT7ZZ?ref=ppx_yo2ov_dt_b_fed_asin_title) |
| ![socket_strip_short](/images/parts/300_socket_strip_short.png "socket_strip_short") | 1 | 10 | 8-pin socket strip with short contacts | 1,88 | [AliExpress](https://de.aliexpress.com/item/1005005488898046.html?spm=a2g0o.productlist.main.9.669btr3dtr3d6w&algo_pvid=65fd6970-3b51-4d0e-940c-e7cddb3caf78&aem_p4p_detail=202411290703446772873239296340000289000&algo_exp_id=65fd6970-3b51-4d0e-940c-e7cddb3caf78-4&pdp_npi=4%40dis%21EUR%211.88%211.60%21%21%211.94%211.65%21%40211b613917328926243906031e2cec%2112000033281493435%21sea%21AT%21738334575%21X&curPageLogUid=lXR8wevtzrac&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202411290703446772873239296340000289000_4) |   
| ![socket_strip_long](/images/parts/300_socket_strip_long.png "socket_strip_long") | 1 | 100 | 8-pin socket strip with long contacts (11 mm) | 8,37 |[AliExpress](https://www.aliexpress.com/item/32723472575.html?spm=a2g0o.order_list.order_list_main.4.f9f31802e55QVF) |   
| ![socket_strip_long_yellow](/images/parts/300_socket_strip_long_yellow.png "socket_strip_long_yellow") | 1 | 10 | 8-pin (or 10-pin) socket strip with long contacts (11 mm), yellow | 3,95 |[AliExpress excellence electronic](https://de.aliexpress.com/item/4001180247614.html?spm=a2g0o.order_list.order_list_main.389.40f55c5f5h69eX&gatewayAdapt=glo2deu) |   
| ![pin_strip_0](/images/parts/200_pin_strip_0.png "pin_strip_0") | 1 | 10 | 40-pin straight pin header 2,54 mm | 2,34 | [AliExpress](https://de.aliexpress.com/item/32973181162.html?spm=a2g0o.order_list.order_list_main.81.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   
| ![pin_header_90](/images/parts/300_pin_header_90.png "pin_header_90") | 1 | 20 | 40-pin pin header right angled (90°) 2,54 mm, __R1__ Type B6, extra long | 6,37 | [AliExpress E-Simpo Store](https://de.aliexpress.com/item/32887929634.html?spm=a2g0o.order_list.order_list_main.619.40f55c5f5h69eX&gatewayAdapt=glo2deu) |   
| ![socket strip 40pol](/images/parts/300_socket_strip_40.png "socket strip 40pol") | 1 | 5 | single-row 40-pin socket strip with turned contacts 2,54 mm| 8,10 <br> 7,66 | [AliExpress](https://de.aliexpress.com/item/1005006755553448.html?spm=a2g0o.order_list.order_list_main.76.f9f35c5fKqYn54&gatewayAdapt=glo2deu) <br> [Amazon](https://www.amazon.de/Ticfox-Rundloch-Buchsenleiste-Einreihig-Connector/dp/B09JP7HT1W?crid=KCL2BL46EJ95&dib=eyJ2IjoiMSJ9.nbUkl4qyuinX7hE-a8LcquMPk1QLUzYjPJ70d4AkmiPUl3Ju3rnFtbvXyzVvBPyNHLa4AiL75eBADZROfXs_9sUf-s8_Y0LTKmp8s8TflpffgDAlN-drG5xkk9aniAwBS-8Ue4OEn6Ahh-IXpPQEn3iXIL40590cUrzxjgr_2uNbK3qrnCyUBx2Y4JAN7wNvjtpEUD5EIUEnkj13xEvOf7JBDHfgMeinlMuqTVtTVrDX_bMWm2QwsMGg6TuQ4VBFkQ2NHrysFJTldYEQq--_6Me0_rZWEiNiYln0h6QWm8I.QGfp3YQSldAnlv2GmR06YT6Y3Jlmb97lomWP6EsKcfo&dib_tag=se&keywords=buchsenleiste+2+54+trennbar&nsdOptOutParam=true&qid=1733129938&sprefix=buchsenleiste+2%2C54%2Caps%2C99&sr=8-6)|   
| ![box_connector_6_90°](/images/parts/300_box_connector_6_90.png "box_connector_6_90°") | 1 | 10 | Box connector 6-pin (2x3), right head angled (90°) | 1,21 | [AliExpress Danteqi Connectors Store](https://de.aliexpress.com/item/1005007473702559.html?spm=a2g0o.order_list.order_list_main.146.79f05c5fj4G1yR&gatewayAdapt=glo2deu) |   
| ![box_connector_6](/images/parts/300_box_connector_6.png "box_connector_6") | 2 | 10 <br> 20 | 6-pin (2x3) box connector, vertical | 6,05 <br> 10,68 | [AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) <br> [Amazon](https://www.amazon.de/dp/B0BGRMLJD7?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)|   
| ![box_connector_10](/images/parts/300_box_connector_10.png "box_connector_10") | 1 | 10 <br> 20 | 10-pin (2x5) box connector, vertical | 6,15 <br> 11,09 |[AliExpress](https://de.aliexpress.com/item/1005006804603387.html?spm=a2g0o.order_list.order_list_main.130.2dc65c5fS73c6M&gatewayAdapt=glo2deu) <br> [Amazon](https://www.amazon.de/dp/B0BGRM9GZP?ref=ppx_yo2ov_dt_b_fed_asin_title) |    
| ![socket_ribbon_cablec_connector_6pol](/images/parts/300_socket_ribbon_cablec_connector_6a.png "socket_ribbon_cablec_connector_6pol") | 2 | 10 | IDC socket connector for ribbon cable 6-pin | 2,98 | [AliExpress](https://de.aliexpress.com/item/1005002804645942.html?spm=a2g0o.order_list.order_list_main.165.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   
| ![socket_ribbon_cablec_connector_10pol](/images/parts/300_socket_ribbon_cablec_connector_10.png "socket_ribbon_cablec_connector_10pol") | 1 | 10 | IDC socket connector for ribbon cable 10-pin | 2,86 | [AliExpress](https://de.aliexpress.com/item/1005002804645942.html?spm=a2g0o.order_list.order_list_main.165.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   
| ![subD-25_plug_90°](/images/parts/300_subD-25_plug_90.png "subD-25 plug 90°") | 1 | 5 | SubD connector 25-pin, angled | 4,49 | [AliExpress](https://de.aliexpress.com/item/1005003119025143.html?spm=a2g0o.order_list.order_list_main.177.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   
| ![IC4](/images/parts/300_IC4.png "IC4") | 1 | 50 | IC socket 4-pin with turned sockets | 4,68 | [AliExpress](https://de.aliexpress.com/item/1005003652148420.html?spm=a2g0o.productlist.main.1.7c52I0v0I0v0cU&algo_pvid=944cbd2e-7acc-4457-9e4f-fbcceda1d0a0&algo_exp_id=944cbd2e-7acc-4457-9e4f-fbcceda1d0a0-0&pdp_npi=4%40dis%21EUR%214.68%214.35%21%21%214.81%214.47%21%40210385a817331341448998686eda30%2112000026657542931%21sea%21AT%21738334575%21X&curPageLogUid=wU9ZgQgX5eGi&utparam-url=scene%3Asearch%7Cquery_from%3A) |   
| ![IC8](/images/parts/300_IC8.png "IC8") | 1 | 10 | IC socket 8-pin with turned sockets | 1,89 | [AliExpress](https://de.aliexpress.com/item/1005007246586839.html?spm=a2g0o.order_list.order_list_main.195.f9f35c5fKqYn54&gatewayAdapt=glo2deu) |   

## Electronic components

| Image | Quantity | Parts/Pack | Description | approx. Euro | Source |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   
| ![ESP32](/images/parts/300_ESP32.png "ESP32") | 1 | 1 | ESP32 D1 mini with CH9102X drive Type-C | 12,05 | [AliExpress](https://de.aliexpress.com/item/1005005972627549.html?spm=a2g0o.order_list.order_list_main.408.f9f35c5fI5TZhl&gatewayAdapt=glo2deu) |   


## Purchased parts

| Image | Quantity | Parts/Pack | Description | approx. Euro | Source |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   

## Miscellaneous

| Image | Quantity | Parts/Pack | Description | approx. Euro | Source |   
|:---- |:------:|:----------:|:----------- | --------:|:------ |   


## Tools
Soldering station, small needle-nose pliers, small side cutters, small screwdriver, snap-off blade knife ("Stanley knife", cutter knife), vice.
Drill, jigsaw, drill bits (5.6 mm, 8 mm, 11.6 mm).

# Manufacturing the components
Once you have both the circuit boards and the components available - after a certain amount of waiting - it's time to manufacture the components. This is described on the following pages:
* [Components for the power supply: `/fab/rcc1_supply/README.md`](/fab/rcc1_supply/LIESMICH.md)
* [Extensions (shields) for the ESP32: `/fab/rcc2_esp32/README.md`](/fab/rcc2_esp32/LIESMICH.md)
* [RCC Blocks: `/fab/rcc4_block/LIESMICH.md`](/fab/rcc4_block/README.md)
* [Additional boards: `/fab/rcc5_add_ons/LIESMICH.md`](/fab/rcc5_add_ons/README.md)

[To the top of the page](#up)   