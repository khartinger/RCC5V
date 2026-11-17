<a name="up"></a>
<table><tr><td><img src="/images/RCC5V_Logo_96.png"></img></td><td>
<h1>Das Demo-Programm rcc_demo2 im Detail</h1><b><big>Details zur Demo-Software zum Steuern von Modellbahn-Komponenten</big></b><br>  
Stand: 17.11.2026    &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a>&nbsp; &nbsp; &nbsp; &nbsp;
<a href="README.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>   

# Einleitung
Der Quellcode des Demo-Programms `rcc_demo2` ist modular aufgebaut und besteht aus vielen Dateien:  

| Datei | Inhalt |  
| ----- | ------ |  
| `src/rcc_demo2.cpp` | Hauptprogramm mit `setup()` und `loop()` |  
| `src/rcc_demo2_text.cpp` | Texte in Deutsch und Englisch wie Startbildschirmtexte etc. |  
| `src/dcc_config.h` | Definitionen und Konstante wie DEBUG, VERSION, Netzwerkdaten, MQTT-Befehle, Expander-Adressen, Railroad-Komponenten, ... |  
| `src/pre_config.h` | Expander-Namen und Pin-Namen |  
| `src/src/dcc_config.cpp` | Objekte zu den Deklarationen in `dcc_config.h` |  
| `src/src/rcc_command` (.ccp\|.h) | Funktionen für Kommandos zu den Railroad-Komponenten |  
| `src/src/rcc_dcc` (.ccp\|.h) | Funktion zum Empfang von DCC-Nachrichten |  
| `src/src/rcc_display` (.ccp\|.h) | Funktionen zur Darstellung von Information auf der OLED-Anzeige |  
| `src/src/rcc_hardwareaccess` (.ccp\|.h) | Funktionen für den Hardware-Zugriff |  
| `src/src/rcc_mqtt` (.ccp\|.h) | Funktionen für MQTT-Nachrichten und JSON |  
| `src/src/rcc_statemachine` (.ccp\|.h) | Konstante und Objekt für die State-Maschine |  
| `src/src/cppsrc` (.ccp\|.h) | Zeichendateien (Grafikbibliothek) |  
| `src/src/csrc` (.ccp\|.h) | Zeichendateien (Grafikbibliothek) |  
| `src/src/pcf8574` (.ccp\|.h) | Klasse PCF8574 |  
| `src/src/screen154` (.ccp\|.h) | Klasse Screen154 |  
| `src/src/simplemqtt` (.ccp\|.h) | Klasse SimpleMqtt und PubSubClient |  
| `src/src/statemachine` (.ccp\|.h) | Klasse Statemachine |  



[Zum Seitenanfang](#up)
