#include <iostream>
#include <vector>
#include <typeinfo>

int main() {
    // Basis auto
    auto i = 42;                    // int
    auto d = 3.14;                  // double
    auto c = 'A';                    // char
    auto b = true;                   // bool

    std::cout << "i: " << i << " (" << typeid(i).name() << ")\n";
    std::cout << "d: " << d << " (" << typeid(d).name() << ")\n";
    std::cout << "c: " << c << " (" << typeid(c).name() << ")\n";
    std::cout << "b: " << b << " (" << typeid(b).name() << ")\n";

    // auto mit Referenzen und const
    int x = 10;
    const int& ref = x;
    auto a1 = ref;                   // int (const und Referenz entfernt)
    auto& a2 = ref;                  // const int&

    std::cout << "a1: " << a1 << " (" << typeid(a1).name() << ")\n";
    std::cout << "a2: " << a2 << " (" << typeid(a2).name() << ")\n";

    // auto in Schleifen
    std::vector<int> vec = {1,2,3,4};
    for (const auto& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // Initialisierungslisten (C++11 vs C++17)
    auto init1 {1};      // C++17: int; C++11: std::initializer_list<int>
    auto init2 = {1};    // immer std::initializer_list<int>

    std::cout << "init1: " << typeid(init1).name() << '\n';
    std::cout << "init2: " << typeid(init2).name() << '\n';

    return 0;
}
