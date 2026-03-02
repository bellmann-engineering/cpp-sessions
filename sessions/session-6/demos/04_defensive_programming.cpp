#include <iostream>
#include <cassert>
#include <cstdint>

// Precondition: value muss zwischen 0 und 100 liegen
void setValue(int value) {
    assert(value >= 0 && value <= 100);
    // ...
}

// Compilezeit-Prüfung
static_assert(sizeof(int) == 4, "int muss 32 Bit sein");

// Fehlerbehandlung über Rückgabewert (embedded-typisch)
bool writeRegister(volatile uint32_t* reg, uint32_t val) {
    if (!reg) return false;
    *reg = val;
    return true;
}

int main() {
    setValue(50);   // ok
    // setValue(200); // würde im Debug assert auslösen

    volatile uint32_t fake_reg = 0;
    bool ok = writeRegister(&fake_reg, 0x1234);
    std::cout << "Schreiben " << (ok ? "erfolgreich" : "fehlgeschlagen") << "\n";

    return 0;
}
