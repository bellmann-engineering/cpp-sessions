# Übung 2: Ranges Pipeline

**Ziel:** Bauen Sie mit Ranges eine Verarbeitungspipeline für eine Liste von Sensordaten.

## Aufgabenstellung

Gegeben ist eine Liste von Sensordaten (Struktur `SensorReading` mit `id` und `value`).  
Schreiben Sie eine Pipeline, die:

1. Nur gültige Werte (value > 0) durchlässt,
2. Die Werte verdoppelt,
3. Die ersten 10 Ergebnisse in einen `std::vector` sammelt.

Ergänzen Sie die fehlenden Teile (`// TODO`) im folgenden Code.

```cpp
#include <iostream>
#include <vector>
#include <ranges>

struct SensorReading {
    int id;
    float value;
};

int main() {
    std::vector<SensorReading> data = {
        {1, 3.5f}, {2, -1.0f}, {3, 4.2f}, {4, 2.0f},
        {5, 0.0f}, {6, 5.1f}, {7, -2.0f}, {8, 1.5f},
        {9, 6.0f}, {10, 3.8f}, {11, -0.5f}, {12, 2.9f}
    };

    // TODO: Pipeline mit filter, transform, take
    auto view = data
        | std::views::filter([](const auto& r) {
              // TODO: Bedingung für gültige Werte (z.B. value > 0)
              return /* TODO */;
          })
        | std::views::transform([](const auto& r) {
              // TODO: Wert transformieren (z.B. value * 2)
              return /* TODO */;
          })
        | std::views::take(10);

    // Materialisieren
    std::vector<float> result;
    for (auto val : view) {
        result.push_back(val);
    }

    for (float v : result) {
        std::cout << v << " ";
    }
    std::cout << "\n";
    return 0;
}
