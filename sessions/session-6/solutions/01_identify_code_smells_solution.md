# Lösung zu Übung 1 – Code-Smells identifizieren

**Probleme und Verbesserungen:**

1. `copyData`: Keine Nullpointer-Prüfung.  
   **Lösung:** `if (!src || !dst) return;` (oder Fehlercode zurückgeben).  
   In Release-Builds ohne `assert` bleibt das Problem.

2. `compute`: Division durch Null nicht abgesichert.  
   **Lösung:** `if (b == 0) return 0; // oder Fehlerbehandlung`

3. `Sensor::setValue`: Keine Wertebereichsprüfung.  
   **Lösung:** `if (v < 0 || v > 100) return; // oder assert`

**Zusatzfrage:** `assert` wird bei `-DNDEBUG` entfernt, daher sind solche Prüfungen dann nicht mehr aktiv. Für sicherheitskritische Systeme sollten eigene Laufzeitprüfungen eingebaut werden, die auch im Release erhalten bleiben.
