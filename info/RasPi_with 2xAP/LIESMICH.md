<table><tr><td><img src="./images/Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 22.2.2026 <a name="up"></a><br>   
<h1>WLAN f&uuml;r RasPi mit vielen ESP32</h1>
<a href="#TableOfContents">==> Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp;  &nbsp; 
<a href="m4h04_RasPi_WLAN_e.md">==> English version</a>
</td></tr></table>   

# Einleitung
Ein Raspberry Pi (RasPi) kann wegen seiner beschr&auml;nkten Kapazit&auml;ten &uuml;ber sein WLAN etwa sieben ESP32 gleichzeitig bedienen. Das ist oft genug, allerdings möchte man manchmal weitere ESP32 betreiben, die zus&auml;tzlich noch &uuml;ber einen grö&szlig;eren Bereich verstreut sind.   
Dieses Dokument beschreibt den Aufbau eines WLANs f&uuml;r etwa 30 bis 100 ESPs in folgenden Abschnitten:   

<a name="TableOfContents"></a>   

* [Verwendete Hardware](#x01)   
* [Anforderungen an das WLAN ESP](#x02)   
* [Verkabelung](#x10)   
* [Raspberry Pi konfigurieren](#x20)   
* [TP-Link EAP610 konfigurieren](#x30)   
* [Test & Feinschliff](#x40)   

<a name="x01"></a>   

## Hardware
Als __Hardware__ wird verwendet:   
* 1x YuanLey Gigabit PoE Switch   
* 2x TP‑Link EAP610 AX1800 Wi‑Fi 6 Access Point   
* 1x RasPi   
* 2x LAN Kabel cat6A
```   
   Raspberry Pi   ~  ~  ~  WLAN Internet
 (DHCP + MQTT)
      |
YuanLey PoE Switch
   |          |
EAP610 #1   EAP610 #2
 ~  ~  ~    ~  ~  ~  ~  ~  WLAN ESP
```   
_Bild 1: &Uuml;bersicht &uuml;ber die Hardware-Verdrahtung_   

Im _Bild 1_ sieht man, dass es zwei getrennt Netzwerke gibt:   
* Ein WLAN f&uuml;r die ESP32   
* Ein WLAN-Anschluss am Raspberry Pi f&uuml;r Wartungsarbeiten etc.   

<a name="x02"></a>   

## Anforderungen an das WLAN ESP  
1. Das Raspberry Pi erzeugt kein WLAN, sondern arbeitet nur noch als    
   * Router / DHCP-Server   
   * Ausf&uuml;hrender f&uuml;r Applikationslogik (MQTT, Steuerung etc.)   
2. Das Raspberry Pi ist f&uuml;r Software-Updates etc. &uuml;ber WLAN erreichbar   
3. Die ESP-WLAN-Arbeit machen ausschlie&szlig;lich die beiden EAP610   

__Netzwerk Daten__   
* Raspi WLAN-IP `192.168.1.2`   
* Raspi LAN-IP `10.1.1.1`   

* ESP-WLAN: SSID = `Raspi11`, Passwort `12345678`   
* ESP-WLAN-IP-Adressen von `10.1.1.100` bis `10.1.1.199` (&uuml;ber DHCP vom RasPi)  

<a name="x10"></a>   

# Schritt 1 – Verkabelung (vor Konfiguration!)
Die Verkabelung muss vor der Konfiguration der EAP610 erfolgen, da diesen eine IP-Adresse zugewiesen werden muss (per DHCP).   
## 1. Raspberry Pi
* LAN-Port → normaler LAN-Port am YuanLey-Switch   

## 2. TP-Link EAP610
* Beide Accesspoints (TP-Link EAP610) jeweils an einen PoE-Port des Switches anschlie&szlig;en.   
__Anmerkung:__   
Dank PoE (= Power over Ethernet) sind keine Netzteile f&uuml;r die APs nötig.   

==> Jetzt alles einschalten.

<a name="x20"></a>   

# Schritt 2 – Raspberry Pi konfigurieren
## 2.1 WLAN am Raspberry Pi bearbeiten
Das WLAN am Raspberry Pi wird nur noch sicherheitshalber f&uuml;r Wartungsarbeiten etc. benötigt. Die Einstellungen können in der grafischen Oberfl&auml;che oder &uuml;ber die Konsole vorgenommen werden.   
In der Konsole eingeben:   
```   
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```   
Inhalt der Datei:   
```   
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=AT

network={
        ssid="MeinWlanName"
        psk="MeinWlanPasswort"
        key_mgmt=WPA-PSK
}
```   

## 2.2 Statische IP f&uuml;r den Pi setzen
F&uuml;r das RasPi wuss eine statische IP vergeben werden, damit die ESP32 auf den MQTT-Server zugreifen können. Dazu muss man die DHCP-Konfigurationsdatei öffnen:
```   
sudo nano /etc/dhcpcd.conf
```   
Einf&uuml;gen:
```   
interface eth0
static ip_address=10.1.1.1/24
```   
Speichern und beenden durch &lt;Strg&gt;o &lt;Enter&gt; &lt;Strg&gt; x   

Reboot:
```   
sudo reboot
```   
Nach dem Hochfahren kann man zur Kontrolle die IPs des RasPis anzeigen:   
```   
ifconfig
```   
Ergebnis   
```   
eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.1.1.1  netmask 255.255.255.0  broadcast 10.1.1.255

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0

wlan0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.1.2  netmask 255.255.248.0  broadcast 192.168.1.255
```   
Man erkennt:   
* Der LAN-Anschluss ist unter IP `10.1.1.1` erreichbar.   
* Dem RasPi wurde vom externen DHCP-Server die IP `192.168.1.2` zugewiesen.   

## 2.3 DHCP-Server auf dem Pi (falls noch nicht vorhanden)
Konfigurationsdatei öffnen:   
```   
sudo nano /etc/dnsmasq.conf
```   
Beispiel-Konfiguration:   
```   
# _______/etc/dnsmasq.conf______________________________________
interface=eth0              # Use interface eth0
no-dhcp-interface=wlan0     # no dhcp for wlan0
dhcp-range=interface:eth0,10.1.1.100,10.1.1.199,24h
# Assign IP addresses in this range with 24 hour lease time
dhcp-option=option:dns-Server,10.1.1.1 # DNS
```   
Restart:   
```   
sudo systemctl restart dnsmasq
```   
==> Jetzt verteilt der Pi IPs an alle ESP32.

<a name="x30"></a>   

# Schritt 3 – TP-Link EAP610 konfigurieren
## 3.1 Zugriff auf den ersten AP
Anleitung: https://www.omadanetworks.com/de/support/faq/4097/   

Laut Anleitung ist ein Zugriff auf den EAP610 mit dem Brower &uuml;ber die Adressen `https://tplinkeap.net`, `https://omadaeap.net` oder `https://192.168.0.254` möglich. Arbeitet im LAN/WLAN aber ein DHCP-Server, so ist die IP-Adresse des EAP610 meist eine andere. Diese kann entweder am DHCP-Server (zB FRITZ!Box) oder am RasPi angezeigt werden durch   
```   
cat /var/lib/misc/dnsmasq.leases
1771772936 10:5a:95:f5:80:0e 10.1.1.176 EAP610-...
```   
### Ersteinrichtung durchf&uuml;hren
Verbinden mit dem Netzwerk `Raspi11` und im Browser die EAP610-IP eingeben, zB   
```   
https://10.1.1.176
```   
Eingabe von Administrator-Namen (zB `admin`) und Passwort (zB `passwort`). Diese Daten dienen dem Zugriff auf den EAP610 und haben nichts mit dem Netzwerk zu tun!   
Eingabe der Netzwerk-Basisdaten:   
```   
2.4GHz [/] Enable
SSID:     Raspi11
Passwort: 12345678

5GHz [ ] Enable
```   

### Weitere Einstellungen
* Sicherheit: WPA2-PSK (nicht WPA3!)   
* Wireless - Wireless Settings - Wireless Mode: 802.11n only (statt 802.11b/g/n/ax mixed)   
* Wireless - Wireless Settings - Channel Width: 20 MHz (statt Auto, Kanalbreite)   
* Wireless - Wireless Settings - Channel: Auto (oder besser AP #1: Kanal 1, AP #2 Kanal 6 oder 11)   
* Wireless - Wireless Settings - TX-Power (EIRP): 20 (oder besser 15 statt Max!)   

[Save]   

### Client-Limits & Features
Deaktivieren:   
❌ Band Steering   
❌ Fast Roaming (802.11r)   
❌ Airtime Fairness (bei IoT oft problematisch)   
❌ Load Balancing   
👉 ESP32 m&ouml;gen simple WLANs.   

## 3.2 Zweiten EAP610 identisch konfigurieren
WICHTIG:   
* Gleiche SSID   
* Gleiches Passwort   
* Gleiche Sicherheit   
* Anderer Kanal (1 / 6 / 11)   

➡️ So verteilen sich die ESP32 automatisch.

<a name="x40"></a>   

# Schritt 4 – Test & Feinschliff
## 4.1 Test mit wenigen ESP32   
5–10 ESP32 einschalten.   
Pr&uuml;fen:   
* Bekommen sie IPs?   
* Bleiben sie verbunden?   

Eine Liste der Ger&auml;te, die vom RasPi eine IP erhalten haben, kann man im Konsolenfenster folgenderma&szlig;en anzeigen:   
```   
cat /var/lib/misc/dnsmasq.leases
```   
Ergebnis zB:   
```   
1771845018 10:5a:xx:xx:xx:xx 10.1.1.117 EAP610-10-5A-xx-xx-xx-xx 01:10:5a:xx:xx:xx:xx
1771845022 10:5a:xx:xx:xx:xx 10.1.1.176 EAP610-10-5A-xx-xx-xx-xx 01:10:5a:xx:xx:xx:xx
1771845013 fc:b4:xx:xx:xx:xx 10.1.1.180 esp32-xxxxxx 01:fc:b4:xx:xx:xx:xx
...
```   

Möchte man die aktuell mit einem Access-Point verbundenen Ger&auml;te anzeigen, so muss man sich am Access-Point (EAP610) anmelden. Die IP-Adresse eines EAP610 erh&auml;lt man mit dem Befehl oben. (zB `10.1.1.117` und `10.1.1.176`)   
Verbinden mit dem Netzwerk `Raspi11` und im Browser die EAP610-IP eingeben, zB `10.1.1.117`. Danach Eingabe von Administrator-Namen (zB `admin`) und Passwort (zB `passwort`).   
Unter "Status - Client" erh&auml;lt man eine Liste der verbundenen Ger&auml;te.   

## 4.2 Hochfahren auf 30 ESP32
In Gruppen einschalten.   
Beobachte im AP:   
* Clients pro AP (~15–20 ideal)   

[Zum Seitenanfang](#up)