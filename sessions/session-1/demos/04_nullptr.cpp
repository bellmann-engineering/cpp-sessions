#include <iostream>

void overloaded(int) {
    std::cout << "int-Version\n";
}
void overloaded(char*) {
    std::cout << "char*-Version\n";
}

int main() {
    // NULL ist oft 0 – führt zur falschen Überladung
    overloaded(NULL);          // ruft int-Version auf (wenn NULL=0)
    overloaded(nullptr);       // ruft char*-Version auf

    // nullptr kann nicht in int konvertiert werden
    // int x = nullptr;        // Fehler
    int* p = nullptr;          // OK
    return 0;
}
