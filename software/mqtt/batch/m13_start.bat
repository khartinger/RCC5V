@echo off
setlocal enabledelayedexpansion
echo(
echo m13_start: MQTT-Befehle fuer Startzustand von Modul 13
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module13/set/... m 0|1

REM -----(3-fach) Einfahrtsweiche-------------------------------
echo Einfahrtsweiche: "Rechts"
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/132 -m 0
REM -----Entkuppler aus-----------------------------------------
echo Entkuppler: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/134 -m 0
REM -----Fahrstrom Abstellgleis---------------------------------
echo Fahrstrom Abstellgleis: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module13/set/133 -m 0
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----
