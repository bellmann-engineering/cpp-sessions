#include <iostream>
#include <vector>
#include <type_traits>

struct Sensor {
    int id;
    float value;
    int& getRef() { return id; }
};

int main() {
    int a = 42;
    int& ref = a;

    decltype(a)    x = a;    // int
    decltype(ref)  y = a;    // int&
    decltype((a))  z = a;    // int& (doppelte Klammer!)

    std::cout << "x: " << typeid(x).name() << '\n';
    std::cout << "y: " << typeid(y).name() << '\n';
    std::cout << "z: " << typeid(z).name() << '\n';

    // decltype in Templates
    std::vector<int> vec;
    using IterType = decltype(vec.begin());
    std::cout << "IterType: " << typeid(IterType).name() << '\n';

    // declval – Typabfrage ohne Konstruktion
    using ElemType = decltype(*std::declval<std::vector<int>>().begin());
    std::cout << "ElemType: " << typeid(ElemType).name() << '\n';

    // decltype mit Member-Funktion
    Sensor s;
    decltype(s.getRef()) ref2 = s.id;   // int&
    ref2 = 100;
    std::cout << "s.id nach ref2: " << s.id << '\n';

    return 0;
}
