# Übung 1: Code-Smells identifizieren

**Ziel:** Finden Sie Sicherheitslücken und fehlende Prüfungen im folgenden Code. Markieren Sie die Problemstellen und schlagen Sie Verbesserungen vor.

```cpp
#include <cstdint>
#include <cstring>

void copyData(const uint8_t* src, uint8_t* dst, int len) {
    // TODO: Fehlende Prüfung auf Nullpointer?
    memcpy(dst, src, len);
}

int compute(int a, int b) {
    return a / b; // TODO: Division durch Null möglich?
}

class Sensor {
    int value;
public:
    void setValue(int v) {
        value = v; // TODO: Wertebereich prüfen?
    }
    int getValue() const {
        return value;
    }
};

int main() {
    uint8_t buffer[10];
    copyData(nullptr, buffer, 10); // Absturzgefahr

    compute(10, 0); // undefiniert

    Sensor s;
    s.setValue(200); // falls Sensor nur 0–100 erlaubt
    return 0;
}
