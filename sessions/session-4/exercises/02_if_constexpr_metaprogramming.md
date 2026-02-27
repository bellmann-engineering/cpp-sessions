# Übung 2: if constexpr Metaprogrammierung

**Ziel:** Implementieren Sie eine Funktion `printInfo`, die für verschiedene Typen unterschiedliche Ausgaben erzeugt – und zwar mit `if constexpr` zur Compilezeit.

## Aufgabenstellung

Schreiben Sie eine Template‑Funktion `printInfo`, die:
- für integrale Typen den Wert und die Nachricht " (integral)" ausgibt,
- für Fließkommatypen den Wert und " (floating point)" ausgibt,
- für `std::string` den Inhalt in Anführungszeichen ausgibt,
- für alle anderen Typen eine Meldung "Unbekannter Typ" ausgibt.

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`).

```cpp
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
void printInfo(const T& value) {
    // TODO: if constexpr für die verschiedenen Kategorien
}

int main() {
    printInfo(42);
    printInfo(3.14);
    printInfo("Hallo");          // Achtung: const char*, nicht std::string!
    printInfo(std::string("Welt"));
    printInfo(std::vector<int>{1,2,3}); // Test für anderen Typ
    return 0;
}
