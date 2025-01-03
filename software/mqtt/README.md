<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-01-03 <a name="up"></a><br>   
<h1>MQTT messages for the RCC system</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# Introduction
## MQTT system
A MQTT system consists of a server (“broker”) and various clients. A computer or a Rasperrry Pi running a broker program is therefore required for RCC control with MQTT. The broker used here is [Mosquitto](https://mosquitto.org/).   
Each RCC microcontroller works as a client.   

The data is transmitted via a WLAN (with HTTP protocol). The following data must be known from this:   
| Information | Example |   
|-------------|----------|   
| IP address of the computer on which the broker is running | `10.1.1.1` |   
| Name of the WLAN (SSID)| `Raspi11` |   
| Password of the WLAN | `12345678` |   

## MQTT messages
MQTT messages consist of a topic and a message content (“payload”). Topics can be divided into sections - similar to file directories - and may not contain spaces.   

To display messages, the program `mosquitto_sub` can be used, which is started after installation in a command window (in Linux or Windows), e.g. as follows:   
`mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
Note: The computer on which the program is started must be in the same WLAN as the broker.   

The program `mosquitto_pub` can be used to send messages, which is used after installation in a command window (in Linux or Windows), e.g. as follows:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   

# MQTT messages for the RCC system
In principle, the structure of MQTT messages is freely selectable. The following agreements are made for the RCC system.   

1. all topics start with `rcc/`   
2. the module name (e.g. m01) or “demo1” follows as the second part of the topic   
Examples: `rcc/m01` or `rcc/demo1`.   
3. the third part of the topic is the action that is to be executed. A distinction is made between set and get actions:   
`/set/...` Sets the value of a component that is specified in the 4th part of the topic.   
`/get` Specifies in the payload which information is to be retrieved.   
4. only for set commands: Name or DCC address of the component to be addressed.    

### Examples
1. get information on which MQTT commands are available for the `demo1` module:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   
The answer is given under the topic `rcc/demo1/ret/?`:   
```   
get: ?|help|version|ip|topicbase|eeprom|byname|bydcc|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
set: topicbase|eeprom0|UC|11|T2|21|T3L|31|T3R|32|DT|41|BL|51|
sub:
pub:
MQTT: ../set/T2 -m 1|g|G OR -m 0|A|a|B|b (set by name)
      ../set/21 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)
      ../get -m byname|bydcc (values of all components)
```   
2. set the turnout `T2` with the DCC address `21` on module `demo1` to “even” (1):   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m 1`   
or   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/T2 -m g`   

[To the top of the page](#up)   