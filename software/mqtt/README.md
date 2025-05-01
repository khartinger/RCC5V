<table><tr><td><img src="../../images/RCC5V_Logo_96.png"></img></td><td>
Last modified: 2025-05-01 <a name="up"></a><br>   
<h1>MQTT messages for the RCC system</h1>
<a href="LIESMICH.md">==> Deutsche Version</a>&nbsp; &nbsp; &nbsp; 
</td></tr></table>    

# 1. Introduction
## 1.1 MQTT system
A MQTT system consists of a server (“broker”) and various clients. A computer or a Rasperrry Pi running a broker program is therefore required for RCC control with MQTT. The broker used here is [Mosquitto](https://mosquitto.org/).   
Each RCC microcontroller works as a client.   

The data is transmitted via a WLAN (with HTTP protocol). The following data must be known from this:   
| Information | Example |   
|-------------|----------|   
| IP address of the computer on which the broker is running | `10.1.1.1` |   
| Name of the WLAN (SSID)| `Raspi11` |   
| Password of the WLAN | `12345678` |   

## 1.2 MQTT messages
MQTT messages consist of a topic and a message content (“payload”). Topics can be divided into sections - similar to file directories - and may not contain spaces.   

To display messages, the program `mosquitto_sub` can be used, which is started after installation in a command window (in Linux or Windows), e.g. as follows:   
`mosquitto_sub -h 10.1.1.1 -t rcc/# -v`   
Note: The computer on which the program is started must be in the same WLAN as the broker.   

The program `mosquitto_pub` can be used to send messages, which is used after installation in a command window (in Linux or Windows), e.g. as follows:   
`mosquitto_pub -h 10.1.1.1 -t rcc/demo1/get -m ?`   

[To the top of the page](#up)   
<a name="x20"></a>   

# 2. MQTT messages for the RCC system
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
<a name="x30"></a>   

# 3. Automatic execution of MQTT command sequences
## 3.1 General
To execute several MQTT commands in succession, you simply need to write them to an executable file. Since executable files are a matter for the operating system, the creation of these files is different.   

## 3.2 Automatic command sequences under Windows
To create executable text files under Windows, it is sufficient to create a 
file with the extension `.bat`.   

### Example
Create a file on a Windows computer that executes the following commands on the demo system:   
* Set the two-way turnout (DCC address 21) to branch   
* Three-way turnout (DCC 31 and 32) to straight line   
* Set traction current (DCC 41) to on   
* Flashing light (DCC 51) on   

#### Solution
Create a file `rcc_demo1_start.bat` with the following content:   
```   
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m a
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/31 -m g
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/41 -m 1
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/51 -m 1
```   
For the sake of simplicity: Save the file `rcc_demo1_start.bat` in the directory from which `mosquitto_pub` is normally started.   

#### Test
* Start the demo system and check whether the system is connected to the MQTT broker (line 2 should read `MQTT ok Raspi11`)   
* Connect the PC or laptop to the network of the MQTT broker (MQTT server)   
* Start the batch file in a command window:   
`rcc_demo1_start`   

Switches, traction current and flashing light should be set according to the specification.   

## 3.3 Automatic command sequences under Linux
Under Linux, a shell file must be created and marked as “executable”.   

### Example
Create a file on a Linux computer that executes the following commands on the demo system:   
* Set the two-way switch (DCC address 21) to even   
* Three-way turnout (DCC 31 and 32) to “Left” (DCC 31)   
* Set traction current (DCC 41) to on   
* Flashing light (DCC 51) on   
A Raspberry Pi, for example, can be used as a Linux computer, which is accessed with putty.   

#### Solution
1. create a file `rcc_demo1_start.sh`:   
   `nano rcc_demo1_start.sh`   
2. enter the file content:   
```   
#!/bin/bash
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/21 -m g
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/31 -m a
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/41 -m 1
mosquitto_pub -h 10.1.1.1 -t rcc/demo1/set/51 -m 1
```   
3. save and exit the file with `<strg>o <enter> <strg>x`.   
4. make the file executable with   
   `chmod 777 rcc_demo1_start.sh`   

#### Test
* Start the demo system and check whether the system is connected to the MQTT broker (line 2 should read `MQTT ok     Raspi11`)   
* Connect to the Linux computer (e.g. with putty) and start the batch file in the command window:   
`./rcc_demo1_start.sh`   

# 4. Examples
The directory `software/mqtt/batch` contains numerous examples of (Windows) batch files for testing the components of modules or for setting the start values of modules. As a rule, one pass through the module is enabled.   
The following example describes the testing (multiple switching) of the points of module 14.   

## 4.1 Switch test
The Windows batch file `m14_test.bat` switches the switch with the DCC address `141` on module `module14` several times. The number of toggles can be specified as a parameter. If no parameter is specified, switching takes place once.   
* Application example: `m14_test 3` 
 The turnout is switched three times to branch and straight.
### Source code
```   
@echo off
setlocal enabledelayedexpansion
echo(
echo m14_test.bat: MQTT-Befehle zum Testen von Modul 14
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module14/set/... m 0|1
echo Anwendungsbeispiel: m14_test 3
set max_=%1%
IF {%1%} == {} ( set max_=1 )
set /a max2 = max_
REM -----Weiche-------------------------------------------------
FOR /L %%A IN (1,1,%max2%) DO (
echo Weiche "Abzweig"
 mosquitto_pub -h 10.1.1.1 -t rcc/module14/set/141 -m 0 
 timeout 2 /nobreak > nul
 echo Weiche "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module14/set/141 -m 1 
 timeout 2 /nobreak > nul
)
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----
```   

[To the top of the page](#up)   