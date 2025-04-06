<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 6.4.2025 <a name="up"></a><br>   
<h1>MQTT-Nachrichten f&uuml;r das RCC-System</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# 1. Einleitung
## 1.1 MQTT-System
Ein MQTT-System besteht aus einem Server ("Broker") und verschiedenen Clients. F&uuml;r die RCC-Steuerung mit MQTT wird daher ein Rechner bzw. ein Rasperrry Pi ben&ouml;tigt, auf dem ein Broker-Programm l&auml;uft. Als Broker wird hier [Mosquitto](https://mosquitto.org/) verwendet.   
Jeder RCC-Microcontroller arbeitet als Client.   

Die Daten&uuml;bertragung erfolgt &uuml;ber ein WLAN (mit HTTP-Protokoll). Von diesem m&uuml;ssen folgende Daten bekannt sein:   
| Information | Beispiel |   
|-------------|----------|   
| IP-Adresse des Rechners, auf dem der Broker l&auml;uft | `10.1.1.1` |   
| Name des WLAN (SSID)| `Raspi11` |   
| Passwort des WLAN | `12345678` |   

## 1.2 MQTT-Nachrichten
MQTT-Nachrichten bestehen aus einem Topic und einem Nachrichteninhalt ("Payload"). Topics k&ouml;nnen - &auml;hnlich wie Dateiverzeichnisse - in Abschnitte unterteilt werden und d&uuml;rfen keine Leerzeichen enthalten.   

Zur Anzeige von Nachrichten kann das Programm `mosquitto_sub` verwendet werden, das nach der Installation in einem Kommando-Fenster (in Linux oder Windows) zB folgenderma&szlig;en gestartet wird:   
`mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
_Anmerkung_: Der Rechner, auf dem das Programm gestartet wird, muss sich im selben WLAN befinden wie der Broker.   

Zum Senden von Nachrichten kann das Programm `mosquitto_pub` verwendet werden, das nach der Installation in einem Kommando-Fenster (in Linux oder Windows) zB folgenderma&szlig;en verwendet wird:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   

[Zum Seitenanfang](#up)
<a name="x20"></a>   

# 2. MQTT-Nachrichten f&uuml;r das RCC-System
Grunds&auml;tzlich ist der Aufbau von MQTT-Nachrichten frei w&auml;hlbar. F&uuml;r das RCC-System werden die nachfolgenden Vereinbarungen getroffen.   

1. Alle Topics beginnen mit `rcc/`   
2. Als zweiter Teil des Topics folgt der Modulname (zB m01) oder "demo1"   
_Beispiele_: `rcc/m01` oder `rcc/demo1`   
3. Als dritter Teil des Topics steht die Aktion, die ausgef&uuml;hrt werden soll. Dabei unterscheidet man zwischen set- und get-Aktionen:   
`/set/...` Setzt den Wert einer Komponente, die im 4. Teil des Topics angegeben wird.   
`/get` Gibt in der Payload an, welche Information geholt werden soll.   
4. Nur bei set-Befehlen: Name oder DCC-Adresse der Komponente, die angesprochen wird.    

### Beispiele
1. Holen der Information, welche MQTT-Befehle beim Modul `demo1` zur Verf&uuml;gung stehen:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   
Die Antwort erfolgt unter dem Topic `rcc/demo1/ret/?`:   
```   
get: ?|help|version|ip|topicbase|eeprom|byname|bydcc|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
set: topicbase|eeprom0|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
sub:
pub:
MQTT: ../set/T2 -m 1|g|G OR -m 0|A|a|B|b (set by name)
      ../set/21 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)
      ../get -m byname|bydcc (values of all components)
```   
2. Setzen der Weiche `T2` mit der DCC-Adresse `21` auf Modul `demo1` auf "Gerade" (1):   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 1`   
oder   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/T2 -m g`   

[Zum Seitenanfang](#up)
<a name="x30"></a>   

# 3. Automatisches Ausf&uuml;hren von MQTT-Befehlsfolgen
## 3.1 Allgemeines
Zum Ausf&uuml;hren mehrerer MQTT-Befehle nacheinander muss man diese lediglich in eine ausf&uuml;hrbare Datei schreiben. Da ausf&uuml;hrbare Dateien Sache des Betriebssystems sind, ist die Erstellung dieser Dateien unterschiedlich.   

## 3.2 Automatische Befehlsfolgen unter Windows
Um ausf&uuml;hrbare Text-Dateien unter Windows zu erstellen reicht es, eine 
Datei mit der Endung `.bat` zu erzeugen.   

### Beispiel
Erstelle auf einem Windows-Rechner eine Datei, die auf dem Demo-System folgende Befehle ausf&uuml;hrt:   
* Stellen der Zweiwegweiche (DCC-Adresse 21) auf Abzweig   
* Dreiwegweiche (DCC 31 und 32) auf Gerade   
* Fahrstrom (DCC 41) auf ein   
* Blinklicht (DCC 51) ein   

#### L&ouml;sung
Erstellen einer Datei `rcc_demo1_start.bat` mit folgendem Inhalt:   
```   
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m a
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/31 -m g
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/41 -m 1
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/51 -m 1
```   
Der Einfachheit halber: Abspeichern der Datei `rcc_demo1_start.bat` in das Verzeichnis, aus dem heraus sonst `mosquitto_pub` gestartet wird.   

#### Test
* Demo-System starten und kontrollieren, ob das System mit dem MQTT-Broker verbunden ist (in Zeile 2 sollte `MQTT ok     Raspi11` stehen)   
* PC oder Laptop mit dem Netzwerk des MQTT-Brokers (MQTT-Servers) verbinden   
* In einem Kommando-Fenster die Batch-Datei starten:   
`rcc_demo1_start`   

Weichen, Fahrstrom und Blinklicht sollten entsprechend der Angabe gestellt werden.   

## 3.3 Automatische Befehlsfolgen unter Linux
Unter Linux muss eine Shell-Datei erstellt und diese als "ausf&uuml;hrbar" gekennzeichnet werden.   

### Beispiel
Erstelle auf einem Linux-Rechner eine Datei, die auf dem Demo-System folgende Befehle ausf&uuml;hrt:   
* Stellen der Zweiwegweiche (DCC-Adresse 21) auf Gerade   
* Dreiwegweiche (DCC 31 und 32) auf "Links" (DCC 31)   
* Fahrstrom (DCC 41) auf ein   
* Blinklicht (DCC 51) ein   
Als Linux-Rechner kann zB ein Raspberry Pi dienen, auf dem mit putty zugegriffen wird.   

#### L&ouml;sung
1. Erstellen einer Datei `rcc_demo1_start.sh`:   
   `nano rcc_demo1_start.sh`   
2. Datei-Inhalt eingeben:   
```   
#!/bin/bash
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m g
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/31 -m a
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/41 -m 1
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/51 -m 1
```   
3. Datei speichern und beenden mit `<strg>o <enter> <strg>x`   
4. Datei ausf&uuml;hrbar machen mit   
   `chmod 777 rcc_demo1_start.sh`   

#### Test
* Demo-System starten und kontrollieren, ob das System mit dem MQTT-Broker verbunden ist (in Zeile 2 sollte `MQTT ok     Raspi11` stehen)   
* Mit dem Linux-Rechner verbinden (zB mit putty) und im Kommando-Fenster die Batch-Datei starten:   
`./rcc_demo1_start.sh`   

# 4. Beispiele
## 4.1 Weichentest
Die folgende Windows-Batch-Datei `dcc141.bat` schaltet die Weiche mit der DCC-Adresse `141` auf Modul `module14` mehrmals um. Die Anzahl der Hin- und Her-Schaltungen kann als Parameter angegeben werden. Wird kein Parameter angegeben, wird viermal umgeschaltet.   
* Anwendungsbeispiel: `dcc141 5`   
   Die Weiche wird fünfmal auf Abzweig und Gerade geschaltet.   
### Quellcode   
```   
@echo off
setlocal enabledelayedexpansion
REM echo dcc141.bat: Mehrmaliger Aufruf von mosquitto_pub -t 10.1.1.1 -t rcc/module14/set/141 -m 0|1
REM echo Anwendungsbeispiel: repeat 3
set max_=%1%
IF {%1%} == {} ( set max_=4 )
set /a max2 = 2*max_
set dir_=0
set /a dir_=1-%dir_%
FOR /L %%A IN (1,1,%max2%) DO (
 set /a dir_=1 - !dir_!
 echo mosquitto_pub -t 10.1.1.1 -t rcc/module14/set/141 -m !dir_! 
 mosquitto_pub -h 10.1.1.1 -t rcc/module14/set/141 -m !dir_! 
 if !dir_!==0 (
  REM ---wait 1,5 sec--------
  ping 127.0.0.1 -n 2 >nul
  >nul ping 127.0.0.1 -n 1 -w 500
 ) else (
  REM ---wait 3 sec----------
  timeout 3 /nobreak > nul
 ) 
)
```   

[Zum Seitenanfang](#up)   