# Übung 4: `std::variant` vs. `union`

**Ziel:** Ersetzen Sie eine unsichere `union` durch ein typsicheres `std::variant`.

## Aufgabenstellung

Gegeben ist folgende C‑artige Implementierung für einen Sensorwert, der entweder ein `int`, ein `float` oder ein `bool` sein kann. Der Typ wird separat gespeichert.

```c
enum DataType { TYPE_INT, TYPE_FLOAT, TYPE_BOOL };
struct SensorValue {
    DataType type;
    union {
        int i;
        float f;
        bool b;
    } data;
};
