# Übung 5: Zeitmessung mit `std::chrono`

**Ziel:** Messen Sie die Ausführungszeit einer Funktion mit `std::chrono`.

## Aufgabenstellung

Gegeben ist eine Funktion `compute()`, die eine aufwändige Berechnung simuliert. Messen Sie die Dauer des Aufrufs und geben Sie sie in Mikrosekunden aus.

```cpp
#include <iostream>
#include <chrono>

void compute() {
    // Simulierte Arbeit
    volatile int dummy = 0;
    for (int i = 0; i < 1000000; ++i) {
        dummy += i;
    }
}

int main() {
    // TODO: Zeitmessung um compute() herum
    // auto start = ...
    compute();
    // auto end = ...
    // auto elapsed = ...
    // std::cout << "Dauer: " << ... << " µs\n";
    return 0;
}
