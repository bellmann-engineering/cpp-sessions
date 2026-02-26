# Lösung zu Übung 2: Container-Auswahl im Embedded-Kontext

Die folgenden Lösungsvorschläge sind als Diskussionsgrundlage gedacht. Es gibt oft mehrere vertretbare Ansätze; wichtig ist die Begründung.

1. **Puffer für 16 Sensormesswerte, zyklisch, feste Größe**  
   → `std::array<int, 16>` (oder eigener Ringpuffer als Template).  
   Begründung: Keine Heap‑Allokation, Größe bekannt, Stack‑Speicherung.

2. **Konfigurationstabelle mit 100 Einträgen, Compilezeit‑fest, schnelle Suche**  
   → `std::array` oder C‑Array + binäre Suche (`std::lower_bound`).  
   Begründung: Daten statisch, keine Laufzeit‑Allokation, Suche in O(log n) akzeptabel.

3. **Dynamische Liste von Fehlermeldungen, die zur Laufzeit wachsen kann**  
   → `std::vector<std::string>` **nur wenn Heap erlaubt** und Fragmentierung beherrschbar.  
   Alternative: Ringpuffer mit fester Maximalgröße (Überlauf protokollieren).

4. **Funktion, die einen String nur lesend entgegennimmt**  
   → `std::string_view`.  
   Begründung: Keine Kopie, keine Allokation, kann auf C‑Strings und `std::string`‑Daten zeigen.

5. **Assoziatives Array, das zur Laufzeit befüllt wird**  
   → `std::map` **nur mit deterministischem Allokator** (z.B. Pool‑Allokator).  
   Alternative: Eigene Hashtabelle mit fester Größe oder `flat_map` (Boost).

**Zusatzfrage:** Exception‑Sicherheit  
In Embedded‑Systemen mit `-fno-exceptions` sind Container, die Exceptions werfen können (z.B. `std::vector::at`), problematisch. Man bevorzugt exception‑freie Schnittstellen (z.B. `reserve()` vor `push_back`, um out‑of‑memory zu vermeiden) oder verwendet Container, die keine Exceptions verwenden (z.B. `std::array`).
