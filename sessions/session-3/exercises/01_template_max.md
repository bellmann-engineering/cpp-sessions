# Übung 1: Template-Funktion `max` für verschiedene Typen

**Ziel:** Implementieren Sie ein Funktionstemplate `max`, das den größeren von zwei Werten zurückgibt.

## Aufgabenstellung

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.

```cpp
#include <iostream>

// TODO: Definieren Sie ein Template max, das zwei Parameter a und b vergleicht
// und den größeren zurückgibt.

int main() {
    std::cout << max(3, 7) << std::endl;          // int
    std::cout << max(3.14, 2.72) << std::endl;    // double
    std::cout << max('a', 'z') << std::endl;       // char

    // TODO: Testen Sie auch mit eigenen Typen (z.B. std::string)
    return 0;
}
