# Übung: Template-Klasse `Pair` mit Methoden

**Ziel:** Implementieren Sie eine generische Klasse `Pair<T1, T2>`, die zwei Werte verschiedener Typen speichern kann.

## Aufgabenstellung

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.

```cpp
#include <iostream>
#include <string>

template<typename T1, typename T2>
class Pair {
private:
    // TODO: Definieren Sie zwei Membervariablen:
    // first vom Typ T1
    // second vom Typ T2

public:
    // TODO: Implementieren Sie einen Konstruktor,
    // der first und second initialisiert

    // TODO: Implementieren Sie Getter:
    // getFirst()
    // getSecond()

    // TODO: Implementieren Sie eine Methode print(),
    // die beide Werte in der Form "(wert1, wert2)" ausgibt
};

int main() {
    Pair<int, double> p1(42, 3.14);
    Pair<std::string, int> p2("Alter", 30);

    p1.print();
    std::cout << std::endl;

    p2.print();
    std::cout << std::endl;

    std::cout << p1.getFirst() << std::endl;
    std::cout << p2.getSecond() << std::endl;

    return 0;
}
```

## Erweiterung

Ergänzen Sie:

* eine Methode `swap()`, die `first` und `second` vertauscht, falls beide denselben Typ haben
* eine Methode `setFirst(...)`
* eine Methode `setSecond(...)`

