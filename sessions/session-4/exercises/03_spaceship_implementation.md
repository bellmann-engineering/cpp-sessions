# Übung 3: `<=>` implementieren

**Ziel:** Definieren Sie für eine Klasse `Version` den Raumschiffoperator (`<=>`), so dass automatisch alle sechs Vergleichsoperatoren generiert werden.

## Aufgabenstellung

Gegeben ist eine Klasse `Version`, die aus drei Ganzzahlen (major, minor, patch) besteht. Implementieren Sie den `<=>`-Operator so, dass Versionsnummern lexikografisch verglichen werden (zuerst major, dann minor, dann patch). Verwenden Sie `default` für die automatische Generierung der anderen Operatoren.

```cpp
#include <iostream>
#include <compare>

class Version {
public:
    int major, minor, patch;

    // TODO: Konstruktor
    // TODO: operator<=>
};

int main() {
    Version v1{1,2,0};
    Version v2{1,3,0};
    Version v3{1,2,3};

    std::cout << std::boolalpha;
    std::cout << "v1 < v2 : " << (v1 < v2) << '\n';
    std::cout << "v1 == v3: " << (v1 == v3) << '\n';
    std::cout << "v1 <= v3: " << (v1 <= v3) << '\n';
    std::cout << "v2 > v3 : " << (v2 > v3) << '\n';

    return 0;
}
