#include <iostream>

struct NoVirtual {
    int a;
    int b;
};

struct WithVirtual {
    int a;
    int b;
    virtual void f() {}
};

int main() {
    std::cout << "Größe ohne virtuelle Funktionen: " << sizeof(NoVirtual) << " Byte\n";
    std::cout << "Größe mit virtueller Funktion:   " << sizeof(WithVirtual) << " Byte\n";
    // Erwartung: mit vptr 4/8 Byte mehr
    return 0;
}
