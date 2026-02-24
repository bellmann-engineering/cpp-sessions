#include <iostream>
#include <cassert>
#include <cstddef>

// Version A – logisch falsch (nur lokale Pointer getauscht)
// void swap_ptr_A(int* a, int* b) { ... }

// Version B – korrekt, aber mit Prüfungen
void swap_ptr_B(int* a, int* b) {
    // Precondition: beide Zeiger sind gültig
    assert(a != nullptr && b != nullptr);
    // Zusätzliche Absicherung auch im Release (je nach Richtlinie)
    if (a == nullptr || b == nullptr) {
        // Fehlerbehandlung: z.B. return, Exception setzen, Fehlerflag
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Version C – Referenzen, immer sicher
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Vor Swap: x = " << x << ", y = " << y << std::endl;
    swap_ref(x, y);
    std::cout << "Nach Swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}
