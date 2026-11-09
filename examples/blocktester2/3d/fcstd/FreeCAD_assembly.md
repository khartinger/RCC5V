# FreeCAD 1.1: Zwei Körper verbinden

## Schritt 1: Neues Dokument anlegen
1. FreeCAD starten.
2. Datei → Neu auswählen.
3. Das neue Dokument speichern beispielsweise als `xx_track_ballast_261109`.

## Schritt 2: Erstes Dokument öffnen
1. FreeCAD 1.1 starten.
2. Über Datei → Öffnen die erste FCStd-Datei öffnen.
3. Prüfen, ob der erste Körper korrekt angezeigt wird.

## Schritt 3: Zweiten Gleiskörper importieren
1. Menü Datei → Öffnen wählen.
2. Die zweite FCStd-Datei öffnen.
3. Jetzt sind drei Dokumente geöffnet.

## Beide Körper in ein gemeinsames Dokument kopieren.

#...ToDo...  


4. Im zweiten Dokument den gewünschten Körper im Modellbaum markieren.
5. Strg+C drücken.
6. Zum ersten Dokument wechseln.
7. Strg+V drücken.
Jetzt sollten beide Körper im ersten Dokument vorhanden sein.

Speichere das Dokument unter einem neuen Namen, beispielsweise Gleisverbunden.FCStd.






4. Alle Körper (K1, K2, ...)  in den Arbeitsbereich von FreeCAD laden.
2. Eine Fläche des ersten Schotterbett-Körpers anklicken.
3. Strg gedrückt halten und die passende Fläche des zweiten Körpers anklicken.
4. Assembly → Create Joint bzw. das Symbol für Verbindung erstellen.
5. Fixed Joint (Starre Verbindung) auswählen.
6. Die Vorschau prüfen. Falls der zweite Körper auf der falschen Seite sitzt, die Ausrichtung umkehren (Flip).
7. OK.
Damit werden die beiden Körper flächenbündig und starr zueinander positioniert.

# FreeCAD 1.1: Zwei Körper verschmelzen
1. Assembly verlassen bzw. in den Part-Arbeitsbereich wechseln.
2. Beide Körper auswählen.
3. Part → Boolean → Union (Vereinigung) ausführen.
4. FreeCAD erzeugt daraus ein neues Objekt.
Das Ergebnis sollte im Idealfall ein einziges Solid sein.