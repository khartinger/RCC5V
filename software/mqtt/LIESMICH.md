<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Letzte &Auml;nderung: 2.1.2025 <a name="up"></a><br>   
<h1>MQTT-Nachrichten für das RCC-System</h1>
<a href="README.md">==> English version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>   

# Einleitung
## MQTT-System
Ein MQTT-System besteht aus einem Server ("Broker") und verschiedenen Clients. Für die RCC-Steuerung mit MQTT wird daher ein Rechner bzw. ein Rasperrry Pi benötigt, auf dem ein Broker-Programm läuft. Als Broker wird hier [Mosquitto](https://mosquitto.org/) verwendet.   
Jeder RCC-Microcontroller arbeitet als Client.   

Die Datenübertragung erfolgt über ein WLAN (mit HTTP-Protokoll). Von diesem müssen folgende Daten bekannt sein:   
| Information | Beispiel |   
|-------------|----------|   
| IP-Adresse des Rechners, auf dem der Broker läuft | `10.1.1.1` |   
| Name des WLAN (SSID)| `Raspi11` |   
| Passwort des WLAN | `12345678` |   

## MQTT-Nachrichten
MQTT-Nachrichten bestehen aus einem Topic und einem Nachrichteninhalt ("Payload"). Topics können - ähnlich wie Dateiverzeichnisse - in Abschnitte unterteilt werden und dürfen keine Leerzeichen enthalten.   

Zur Anzeige von Nachrichten kann das Programm `mosquitto_sub` verwendet werden, das nach der Installation in einem Kommando-Fenster (in Linux oder Windows) zB folgendermaßen gestartet wird:   
`mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
_Anmerkung_: Der Rechner, auf dem das Programm gestartet wird, muss sich im selben WLAN befinden wie der Broker.   

Zum Senden von Nachrichten kann das Programm `mosquitto_pub` verwendet werden, das nach der Installation in einem Kommando-Fenster (in Linux oder Windows) zB folgendermaßen verwendet wird:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   

# MQTT-Nachrichten für das RCC-System
Grundsätzlich ist der Aufbau von MQTT-Nachrichten frei wählbar. Für das RCC-System werden die nachfolgenden Vereinbarungen getroffen.   

1. Alle Topics beginnen mit `rcc/`   
2. Als zweiter Teil des Topics folgt der Modulname (zB m01) oder "demo1"   
_Beispiele_: `rcc/m01` oder `rcc/demo1`   
3. Als dritter Teil des Topics steht die Aktion, die ausgeführt werden soll. Dabei unterscheidet man zwischen set- und get-Aktionen:   
`/set/...` Setzt den Wert einer Komponente, die im 4. Teil des Topics angegeben wird.   
`/get` Gibt in der Payload an, welche information geholt werden soll.   
4. Nur bei set-Befehlen: Name oder DCC-Adresse der Komponente, die angesprochen wird.    

### Beispiele
1. Holen der Information, welche MQTT-Befehle beim Modul `demo1` zur Verfügung stehen:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   
Die Antwort erfolgt unter dem Topic `rcc/demo1/ret/?`:   
```   
get: ?|help|version|ip|topicbase|eeprom|byname|bydcc|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
set: topicbase|eeprom0|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
sub:
pub: rcc/start/mqtt|
MQTT: ../set/w1 -m 1|g|G OR -m 0|A|a|B|b (set by name)
      ../set/11 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)
      ../get -m byname|bydcc (values of all components)
```   
2. Setzen der Weiche `T2` mit der DCC-Adresse `21` auf Modul `demo1` auf "Gerade" (1):   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 1`   
oder   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/T2 -m g`   

[Zum Seitenanfang](#up)   