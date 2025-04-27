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