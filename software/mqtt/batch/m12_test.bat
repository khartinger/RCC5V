@echo off
setlocal enabledelayedexpansion
echo(
echo m12_test.bat: MQTT-Befehle zum Testen von Modul 12
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module12/set/... m 0|1
echo Anwendungsbeispiel: m12_test 3
set max_=%1%
IF {%1%} == {} ( set max_=1 )
set /a max2 = max_
REM -----(3-fach) Einfahrtsweiche West--------------------------
FOR /L %%A IN (1,1,%max2%) DO (
 echo Einfahrtsweiche West: "Links"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/121 -m 0 
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/121 -m 1
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/122 -m 1
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Rechts"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/122 -m 0 
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/121 -m 1
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/122 -m 1
 timeout 2 /nobreak > nul
)
REM -----Weiche Gleis 1-----------------------------------------
FOR /L %%A IN (1,1,%max2%) DO (
echo Weiche Gleis 1: "Abzweig"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/123 -m 0 
 timeout 2 /nobreak > nul
 echo Weiche Gleis 1: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/123 -m 1 
 timeout 2 /nobreak > nul
)
REM -----Entkuppler ein-aus-------------------------------------
echo Entkuppler Gleis 3: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/124 -m 1
timeout 1 /nobreak > nul
echo Entkuppler Gleis 3: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/124 -m 0
REM -----Weiche Einfahrt Ost------------------------------------
FOR /L %%A IN (1,1,%max2%) DO (
echo Weiche Einfahrt Ost: "Abzweig"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/128 -m 0 
 timeout 2 /nobreak > nul
 echo Weiche Einfahrt Ost: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/128 -m 1 
 timeout 2 /nobreak > nul
)

REM -----Fahrstrom Gleis 1--------------------------------------
echo Fahrstrom Gleis 1: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/125 -m 1
timeout 1 /nobreak > nul
echo Fahrstrom Gleis 1: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/125 -m 0
REM -----Fahrstrom Gleis 1A-------------------------------------
echo Fahrstrom Gleis 1A: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/129 -m 1
timeout 1 /nobreak > nul
echo Fahrstrom Gleis 1A: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/129 -m 0
REM -----Fahrstrom Gleis 3--------------------------------------
echo Fahrstrom Gleis 3: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/127 -m 1
timeout 1 /nobreak > nul
echo Fahrstrom Gleis 3: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/127 -m 0
REM -----Fahrstrom Gleis 2--------------------------------------
echo Fahrstrom Gleis 2: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/126 -m 0
timeout 1 /nobreak > nul
echo Fahrstrom Gleis 2: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/126 -m 1

REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----