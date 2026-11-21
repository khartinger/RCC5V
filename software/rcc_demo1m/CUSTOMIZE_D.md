<a name="up"></a>
<table><tr><td><img src="./images/RCC5V_Logo_96.png"></img></td><td>
<h1>rcc_demo1m an eigene Bedürfnisse anpassen</h1><b><big>Einfache Anleitung für die Demo-Software zur Steuerung von Modellbahn-Komponenten</big></b><br>
Stand: 21.11.2026 &nbsp; &nbsp; &nbsp; &nbsp;
<a href="#TableOfContents">→ Inhaltsverzeichnis</a> &nbsp; &nbsp; &nbsp; &nbsp;
<a href="CUSTOMIZE_E.md">→ English version</a>
</td></tr></table>

<a name="x10"></a>

# 1. Was wird angepasst?

Für die meisten Anpassungen genügen diese Dateien:

| Datei | Was wird dort eingestellt? |
| ----- | -------------------------- |
| `src/rcc_config.h` | WLAN/MQTT, Expander, DCC-Adressen und Komponenten |
| `src/rcc_demo1m_text.h` | Texte auf dem Startbildschirm und Statusbezeichnungen |

Die ausgewählte Anzeigesprache steht in `src/rcc_demo1m.cpp` (`LANGUAGE` ist `'d'` für Deutsch oder `'e'` für Englisch). Das Hauptprogramm muss für normale Konfigurationsänderungen nicht umgeschrieben werden.

Diese Anleitung erklärt die üblichen Änderungen. Für technische Hintergründe und ein vollständiges Beispiel zum Hinzufügen einer Komponente siehe [DETAILS_D.md](./DETAILS_D.md), insbesondere [Kapitel 3](./DETAILS_D.md#x30) und [Kapitel 10](./DETAILS_D.md#x100).

## Inhaltsverzeichnis

* [1. Was wird angepasst?](#x10)
* [2. In fünf Schritten zum eigenen Programm](#x20)
* [3. WLAN und MQTT einstellen](#x30)
* [4. Komponenten und Verdrahtung einstellen](#x40)
* [5. Starttexte und Sprache anpassen](#x50)
* [6. Bauen, Hochladen und testen](#x60)
* [7. Häufige Fehler](#x70)

<a name="x20"></a>

# 2. In fünf Schritten zum eigenen Programm

📋 Sichern → 🔧 Konfigurieren → 🔨 Build → ⬆️ Hochladen → ✅ Testen

1. **Sicherung anlegen:** Kopiere mindestens `src/rcc_config.h` und `src/rcc_demo1m_text.h`, bevor du etwas änderst.
2. **Verdrahtung notieren:** Halte fest, welche DCC-Adresse und welche Ein-/Ausgangspins zu jeder Komponente gehören. Verwende dazu den Schaltplan deiner Hardware.
3. **Konfiguration ändern:** Passe nur die benötigten Einstellungen in den oben genannten Dateien an. Die Beispiele in `rcc_config.h` helfen bei Komponententypen.
4. **Kompilieren:** Öffne in VS Code den Ordner `software/rcc_demo1m` als PlatformIO-Projekt und wähle die Umgebung `wemos_d1_mini32`. Führe zuerst **Build** aus.
5. **Hochladen und prüfen:** Wenn der Build erfolgreich war, lade das Programm auf den ESP32 hoch. Prüfe zuerst Anzeige, DCC-Befehle und Rückmeldungen, bevor du die Anlage wieder normal betreibst.

> ⚠️ **Wichtig:** Falsche Expander- oder Pinangaben können den falschen Ausgang schalten. Vergleiche die Softwarekonfiguration vor dem Einschalten sorgfältig mit der tatsächlichen Verdrahtung.

<a name="x30"></a>

# 3. WLAN und MQTT einstellen

Die folgenden Werte stehen im Abschnitt **Network data** und **MQTT data** in `src/rcc_config.h`:

| Einstellung | Bedeutung |
| ----------- | --------- |
| `_USE_WIFI_` | `true`: WLAN und MQTT verwenden; `false`: beides deaktivieren |
| `_SSID_` | Name des eigenen WLANs |
| `_PASS_` | Passwort des eigenen WLANs |
| `_HOST_` | Name oder IP-Adresse des MQTT-Brokers im Netzwerk |
| `_ESP_NAME_` | Netzwerkname des ESP32 |
| `TOPIC_BASE` | Basis des MQTT-Themas, zum Beispiel `rcc/demo1m` |

Der MQTT-Broker muss vom ESP32 aus erreichbar sein (meist im selben lokalen Netzwerk). `_HOST_` ist die Adresse des **MQTT-Brokers**, nicht die des ESP32. Die Standardwerte müssen für das eigene Netzwerk geprüft und angepasst werden.

> 🔒 **Passwort schützen:** WLAN-Zugangsdaten stehen im Quellcode. Veröffentliche oder teile keine Version mit deinem echten Passwort. Falls Zugangsdaten bereits in einem öffentlichen Repository gelandet sind, ändere das WLAN-Passwort.

Die MQTT-Listen `TOPIC_GET` und `TOPIC_SET` müssen für normale Komponentenänderungen in der Regel nicht angepasst werden: Namen und DCC-Adressen der konfigurierten Komponenten werden beim Start automatisch ergänzt. `TOPIC_SUB` und `TOPIC_PUB` sind für zusätzliche, fortgeschrittene MQTT-Themen gedacht.

**ℹ️ Hinweis zu gespeicherten Werten:** Ein zuvor per MQTT gespeicherter WLAN-Datensatz oder eine geänderte Themenbasis kann die Standardwerte aus `rcc_config.h` übersteuern. Details zum gespeicherten Wert und zum Zurücksetzen stehen in [Kapitel 9 der technischen Beschreibung](./DETAILS_D.md#x90).

<a name="x40"></a>

# 4. Komponenten und Verdrahtung einstellen

## 4.1 Expander verstehen

Ein PCF8574 stellt acht nummerierte Ein-/Ausgangspins (0 bis 7) bereit. In der Standardkonfiguration gibt es zwei Expander:

| Name im Programm | Zweck | Index | I²C-Adresse in der Demo |
| ---------------- | ----- | ----- | --------------------------- |
| `EX0` | Ausgänge | 0 | `0x20` |
| `EX1` | Eingänge/Rückmeldungen | 1 | `0x21` |

`EX0` und `EX1` sind **Indexnummern** im Programm, nicht die I²C-Adressen. Die I²C-Adressen müssen zu den Adress-Jumpern der angeschlossenen Boards passen und dürfen sich nicht überschneiden.

Für die Standardhardware bleibt `IOEX_NUM` auf `2`. Werden weitere Boards verwendet, muss die Anzahl paarweise auf `4`, `6` oder `8` erhöht werden. Auch die passende Expander-Adresse und die dazugehörige Verdrahtung müssen geändert werden. Die zusätzlichen Expander dürfen nicht einfach die Standardadressen `0x20` und `0x21` wiederholen. Siehe dazu [Kapitel 10 der technischen Beschreibung](./DETAILS_D.md#x100).

## 4.2 Aktive Demo-Komponenten

Die aktuelle Liste in `rcc_config.h` enthält folgende Komponenten:

| Typ und Name | DCC-Adresse | Ausgang(e) | Rückmeldung(en) |
| ------------ | ----------- | ---------- | ----------------- |
| `UC`, Entkuppler | 11 | `EX0`, Pin 0 | `EX1`, Pin 0 |
| `TO`, Zweiwegweiche | 21 | `EX0`, Pins 1 und 2 | `EX1`, Pins 1 und 2 |
| `T3L`, Dreiwegweiche links | 31 | `EX0`, Pins 3 und 4 | `EX1`, Pins 3 und 4 |
| `T3R`, Dreiwegweiche rechts | 32 | `EX0`, Pins 5 und 4 | `EX1`, Pins 5 und 4 |
| `DT`, abschaltbares Gleis | 41 | `EX0`, Pin 6 | `EX1`, Pin 6 |
| `BL`, Blinklicht | 51 | `EX0`, Pin 7 | keine |

Die Beispieldefinitionen für weitere Typen stehen ebenfalls in `rcc_config.h`; sie sind dort auskommentiert. Verwende nur einen bereits unterstützten Typ (`RC_TYPE_...`). Einen neuen Typ hinzuzufügen erfordert zusätzliche Programmierung und ist keine reine Konfigurationsänderung.

## 4.3 Eine Komponente bearbeiten oder hinzuzufügen

Eine Komponentendefinition hat immer diese Reihenfolge:

```cpp
#define RCOMP_NEU  TYP, "NAME", DCC, AUSGANGS_EXPANDER, PIN_A, PIN_B, EINGANGS_EXPANDER, PIN_A, PIN_B, MS_EIN, MS_AUS
```

Die Platzhalter müssen durch Werte ersetzt werden; die Zeile ist als Muster und nicht zum unveränderten Kopieren gedacht.

| Angabe | Bedeutung |
| ------ | --------- |
| `TYP` | Unterstützter Typ, zum Beispiel `RC_TYPE_P2` |
| `"NAME"` | Kurzer Komponentenname mit maximal drei Zeichen; wähle nach Möglichkeit einen eindeutigen Namen |
| `DCC` | DCC-Adresse; für unabhängige Komponenten eine noch nicht verwendete Adresse nehmen |
| `AUSGANGS_EXPANDER`, `PIN_A`, `PIN_B` | Expander und Ausgangspins, z. B. `EX0`, `PIN6`, `PIN7` |
| `EINGANGS_EXPANDER`, `PIN_A`, `PIN_B` | Expander und Rückmeldepins; bei nicht verwendeten Pins `NO_PIN` eintragen |
| `MS_EIN`, `MS_AUS` | Zeiten in Millisekunden; ihre Bedeutung hängt vom Typ ab |

Die PCF8574-Ausgänge der Demo werden für viele Schaltblöcke aktiv-low verwendet. Das bedeutet: Ein Signalpegel von `0` kann den angeschlossenen Eingang aktivieren. Orientiere dich am Kommentar des jeweiligen Typs und an der elektrischen Schaltung, nicht nur am Namen des Pins.

Jede aktive Komponente muss an **zwei Stellen** berücksichtigt werden:

1. Eine Definition für die Komponente anlegen oder eine vorhandene Definition anpassen.
2. Unten in `rcc_config.h` `RCOMP_NUM` auf die Anzahl der aktiven Definitionen setzen und alle diese Definitionen in `RCOMP_LIST` aufführen.

Beispiel für die derzeit sechs aktiven Komponentendefinitionen:

```cpp
#define RCOMP_NUM  6
#define RCOMP_LIST {RCOMP_1},{RCOMP_2},{RCOMP_3L},{RCOMP_3R},{RCOMP_4},{RCOMP_5}
```

Beim Hinzufügen einer Komponente muss `RCOMP_NUM` um eins erhöht und die neue Definition am Ende von `RCOMP_LIST` eingetragen werden. Beim Entfernen müssen beide Angaben angepasst werden. **Anzahl und Liste müssen exakt übereinstimmen**, sonst kann das Programm nicht korrekt gebaut werden.

Für ein konkretes Beispiel mit einem zusätzlichen Zweiwegweichen-Block siehe [Kapitel 10 der technischen Beschreibung](./DETAILS_D.md#x100).

## 4.4 DCC-Adresse passt nicht?

`DCC_OFFSET` korrigiert einen Unterschied zwischen der vom DCC-Decoder erkannten und der in der Konfiguration verwendeten Adresse. In der Demo ist der Wert `4`; je nach DCC-Zentrale kann `0` richtig sein. Ändere diesen Wert nur, wenn die angezeigte/erwartete Adresse nicht mit der Adresse deiner Zentrale übereinstimmt. Die Komponentenadresse in der Konfiguration muss danach weiterhin die von der Zentrale verwendete Adresse sein.

<a name="x50"></a>

# 5. Starttexte und Sprache anpassen

Die Datei `src/rcc_demo1m_text.h` enthält deutsche und englische Texte. Die aktive Sprache wird in `src/rcc_demo1m.cpp` mit `LANGUAGE` gewählt:

```cpp
#define LANGUAGE 'd'  // 'd' = Deutsch, 'e' = Englisch
```

Die Startseiten werden in beiden Sprachbereichen mit `INFOLINES` definiert. Wenn du sie änderst:

* passe die Texte in beiden Sprachen an;
* aktualisiere `INFOLINES_NUM` auf die Anzahl der Einträge;
* plane höchstens fünf Zeilen pro Seite und maximal 21 Zeichen pro Zeile ein;
* trage eigene Komponenten und DCC-Adressen in den Starttexten ebenfalls nach.

Um keine Startseiten anzuzeigen, setze `INFOLINES_NUM` in beiden Sprachbereichen auf `0`. Andere Status- und Verbindungstexte sind ebenfalls sprachabhängig; für eine vollständige Änderung müssen die deutschen und englischen Definitionen zusammenpassen.

<a name="x60"></a>

# 6. Bauen, Hochladen und testen

1. Speichere alle geänderten Dateien.
2. Starte in VS Code den PlatformIO-Befehl **Build** für `wemos_d1_mini32`.
3. Behebe zuerst alle gemeldeten Compilerfehler. Eine häufige Ursache ist, dass `RCOMP_NUM` und `RCOMP_LIST` nicht dieselbe Anzahl enthalten.
4. Lade den erfolgreichen Build mit **Upload** auf den ESP32.
5. Beim Start müssen die eingestellten PCF8574-Expander gefunden werden. Danach Anzeige und Rückmeldungen prüfen und jede DCC-Adresse einzeln testen.

<a name="x70"></a>

# 7. Häufige Fehler

| Beobachtung | Prüfen |
| ----------- | ------ |
| Build meldet Fehler bei `RCOMP_LIST` | Kommas, geschweifte Klammern, Makronamen sowie `RCOMP_NUM` kontrollieren |
| Start bleibt bei der Expander-Suche stehen | PCF8574-Stromversorgung, I²C-Verdrahtung und Adresse kontrollieren; das Programm wartet auf alle konfigurierten Expander |
| DCC-Befehl schaltet die falsche Komponente | DCC-Adresse und `DCC_OFFSET` prüfen |
| Ausgang schaltet den falschen Pin | `EX`-Index und Pinbelegung mit der Verdrahtung abgleichen |
| MQTT funktioniert nicht | `_USE_WIFI_`, WLAN-Daten, Broker-Adresse `_HOST_`, `TOPIC_BASE` und eventuell gespeicherte EEPROM-Werte kontrollieren |
| Statusname über MQTT ist nicht eindeutig | Einen eindeutigen kurzen Komponentennamen verwenden; DCC-Adressen müssen ebenfalls stimmen |

[Zurück zum Seitenanfang](#up)
