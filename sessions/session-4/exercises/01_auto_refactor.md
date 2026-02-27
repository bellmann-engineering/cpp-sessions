# Übung 1: auto-Refactoring

**Ziel:** Ersetzen Sie im folgenden Legacy‑Code explizite Typangaben durch `auto`, wo es sinnvoll ist. Beachten Sie dabei Referenzen und `const`-Korrektheit.

## Aufgabenstellung

Gegeben ist folgender Code im alten Stil. Refaktorisieren Sie ihn, indem Sie an geeigneten Stellen `auto` einführen.

```cpp
#include <iostream>
#include <vector>
#include <map>

int main() {
    // 1. Einfache Variablen
    int i = 42;
    double d = 3.14;
    const char* str = "Hallo";

    // 2. Iteratoren
    std::vector<int> vec = {1,2,3,4};
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // 3. Range‑basierte Schleife (manuell)
    std::map<std::string, int> table = {{"eins",1},{"zwei",2}};
    for (std::map<std::string, int>::const_iterator it = table.begin(); it != table.end(); ++it) {
        std::cout << it->first << "=" << it->second << '\n';
    }

    // 4. Lambda-Parameter (C++14)
    auto lambda = [](const std::pair<const std::string, int>& p) {
        std::cout << p.first << "->" << p.second << '\n';
    };
    for (const auto& elem : table) {
        lambda(elem);
    }

    return 0;
}
