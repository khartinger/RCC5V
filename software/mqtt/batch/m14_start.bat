@echo off
setlocal enabledelayedexpansion
echo(
echo m14_start: MQTT-Befehle fuer Startzustand von Modul 14
REM Aufrufe wie mosquitto_pub -t 10.1.1.1 -t rcc/module14/set/... m 0|1

REM -----Weiche-------------------------------------------------
echo Weiche "Gerade"
mosquitto_pub -h 10.1.1.1 -t rcc/module14/set/141 -m 1 
timeout 2 /nobreak > nul
mosquitto_pub -h 10.1.1.1 -t rcc/module14/set/141 -m 1
REM -----FERTIG!------------------------------------------------
echo ---Fertig!-----