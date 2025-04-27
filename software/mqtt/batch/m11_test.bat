@echo off
setlocal enabledelayedexpansion
echo(
echo m11_test.bat: MQTT-Befehle zum Testen von Modul 11
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module11/set/... m 0|1
echo Anwendungsbeispiel: m11_test 3
set max_=%1%
IF {%1%} == {} ( set max_=1 )
set /a max2 = max_
REM -----Abzweigung Tanklager: Fahrstrom ein--------------------
echo Fahrstrom aus
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/112 -m 0
timeout 1 /nobreak > nul
echo Fahrstrom ein
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/112 -m 1
REM -----Weiche zum Tanklager-----------------------------------
FOR /L %%A IN (1,1,%max2%) DO (
echo Weiche "Abzweig"
 mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/111 -m 0 
 timeout 2 /nobreak > nul
 echo Weiche "Gerade"
 mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/111 -m 1 
 timeout 2 /nobreak > nul
)
REM -----Entkuppler ein-aus-------------------------------------
echo Entkuppler ein
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/113 -m 1
timeout 1 /nobreak > nul
echo Entkuppler aus
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/113 -m 0
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----