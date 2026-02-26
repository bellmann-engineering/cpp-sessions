# Übung 2: Container-Auswahl im Embedded-Kontext

**Ziel:** Entscheiden Sie, welcher Container für gegebene Szenarien geeignet ist, und begründen Sie Ihre Wahl.

## Aufgabenstellung

Gegeben sind folgende Szenarien. Wählen Sie jeweils den passenden Container aus:  
`std::array`, `std::vector`, `std::map`, `std::string_view`, oder eine eigene Lösung (z.B. C‑Array). Begründen Sie Ihre Wahl.

1. Ein Puffer für 16 Sensormesswerte, der zyklisch überschrieben wird. Größe fest.
2. Eine Konfigurationstabelle mit 100 Einträgen, die zur Compilezeit feststeht, aber schnell nachgeschlagen werden muss.
3. Eine dynamische Liste von Fehlermeldungen, die während der Laufzeit wachsen kann.
4. Eine Funktion, die einen String entgegennimmt und nur lesend darauf zugreift – ohne Kopie.
5. Ein assoziatives Array, das zur Laufzeit befüllt wird und schnellen Zugriff benötigt (Heap erlaubt).

## Zusatzfrage
- Welche Rolle spielt die Exception‑Sicherheit bei der Container‑Wahl in Embedded‑Systemen?
