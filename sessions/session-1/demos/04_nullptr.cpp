#include <iostream>

void overloaded(int) {
    std::cout << "int-Version\n";
}
void overloaded(char*) {
    std::cout << "char*-Version\n";
}

// Eigene Definition, um das Verhalten von NULL zu demonstrieren
#define MY_NULL 0

int main() {
    // NULL ist oft 0, kann aber auch (void*)0 sein – implementierungsabhängig.
    // Um Eindeutigkeit zu schaffen, verwenden wir hier MY_NULL = 0.
    overloaded(MY_NULL);          // ruft int-Version auf (weil 0 ein int ist)
    overloaded(nullptr);          // ruft char*-Version auf

    // nullptr kann nicht implizit in int konvertiert werden
    // int x = nullptr;        // Fehler
    int* p = nullptr;          // OK
    return 0;
}
