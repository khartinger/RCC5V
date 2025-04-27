@echo off
setlocal enabledelayedexpansion
echo(
echo m12_start: MQTT-Befehle fuer Startzustand von Modul 12
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module12/set/... m 0|1

REM -----(3-fach) Einfahrtsweiche West--------------------------
echo Einfahrtsweiche West: "Gerade"
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/121 -m 1
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/122 -m 1
REM -----Weiche Gleis 1-----------------------------------------
echo Weiche Gleis 1: "Gerade"
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/123 -m 1 
REM -----Entkuppler aus-----------------------------------------
echo Entkuppler Gleis 3: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/124 -m 0
REM -----Weiche Einfahrt Ost------------------------------------
echo Weiche Einfahrt Ost: "Gerade"
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/128 -m 1 
REM -----Fahrstrom Gleis 1--------------------------------------
echo Fahrstrom Gleis 1: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/125 -m 0
REM -----Fahrstrom Gleis 1A-------------------------------------
echo Fahrstrom Gleis 1A: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/129 -m 0
REM -----Fahrstrom Gleis 3--------------------------------------
echo Fahrstrom Gleis 3: aus
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/127 -m 0
REM -----Fahrstrom Gleis 2--------------------------------------
echo Fahrstrom Gleis 2: ein
mosquitto_pub -h 10.1.1.1 -t rcc/module12/set/126 -m 1
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----
