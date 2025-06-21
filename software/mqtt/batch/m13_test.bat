@echo off
setlocal enabledelayedexpansion
echo(
echo m13test.bat: MQTT-Befehle zum Testen von Modul 13
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module13/set/... m 0|1
echo Anwendungsbeispiel: m13_test 3
set max_=%1%
IF {%1%} == {} ( set max_=2 )
set /a max2 = max_
REM -----(3-fach) Einfahrtsweiche-------------------------------
FOR /L %%A IN (1,1,%max2%) DO (
 echo Einfahrtsweiche West: "Links"
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/131 -m 0 
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/131 -m 1
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/132 -m 1
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Rechts"
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/132 -m 0 
 timeout 2 /nobreak > nul
 echo Einfahrtsweiche West: "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/131 -m 1
 mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/132 -m 1
 timeout 2 /nobreak > nul
)
REM -----Entkuppler ein-aus-------------------------------------
echo Entkuppler: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/134 -m 1
timeout 1 /nobreak > nul
echo Entkuppler: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/134 -m 0
REM -----Fahrstrom Gleis 1--------------------------------------
timeout 1 /nobreak > nul
echo Fahrstrom Abstellgleis: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/133 -m 1
timeout 2 /nobreak > nul
echo Fahrstrom Abstellgleis: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/133 -m 0

REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----