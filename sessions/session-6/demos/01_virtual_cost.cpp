#include <iostream>

struct NoVirtual {
    int a;
    int b;
    void f() {}              // nicht virtuell, keine Größenänderung
};

struct WithVirtual {
    int a;
    int b;
    virtual void f() {}      // virtuell, typischerweise vptr im Objekt
};

int main() {
    std::cout << "NoVirtual:   " << sizeof(NoVirtual) << " Byte\n";
    std::cout << "WithVirtual: " << sizeof(WithVirtual) << " Byte\n";
}
