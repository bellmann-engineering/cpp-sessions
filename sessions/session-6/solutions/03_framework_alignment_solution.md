# Lösungshinweise zu Übung 3 – Framework-Abgleich

Hier gibt es keine „richtige“ Lösung, sondern eine Diskussionsgrundlage. Mögliche Antworten könnten sein:

- **Polymorphie:** Die Klasse `X` verwendet virtuelle Funktionen, wird aber nur selten instanziiert – die vptr-Kosten sind vernachlässigbar.
- **SOLID:** Die Klasse `Y` erfüllt mehrere Aufgaben – SRP verletzt. Besser aufteilen.
- **Alternativen:** Für die geschlossene Menge der Sensortypen könnte `std::variant` die vptr einsparen.
- **Statische Analyse:** Würde z.B. die unbenutzte Abhängigkeit in Klasse `Z` aufdecken.

Die Teams sollten ihre spezifischen Erkenntnisse teilen.
