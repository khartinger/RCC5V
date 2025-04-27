@echo off
setlocal enabledelayedexpansion
echo(
echo m11_start: MQTT-Befehle fuer Startzustand von Modul 11
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module11/set/... m 0|1

REM -----Abzweigung Tanklager: Fahrstrom aus--------------------
echo Abzweigung Tanklager: Fahrstrom aus
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/112 -m 0
timeout 1 /nobreak > nul
REM -----Weiche zum Tanklager auf Gerade------------------------
echo Weiche "Gerade"
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/111 -m 1 
timeout 2 /nobreak > nul
REM -----Entkuppler aus-----------------------------------------
echo Entkuppler aus
mosquitto_pub -h 10.1.1.1 -t rcc/module11/set/113 -m 0
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----