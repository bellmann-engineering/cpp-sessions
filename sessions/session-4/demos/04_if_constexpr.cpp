#include <iostream>
#include <type_traits>

// if constexpr in Funktionen
template<typename T>
auto getValue(T t) {
    if constexpr (std::is_pointer_v<T>) {
        return *t;          // T* -> Dereferenzierung
    } else {
        return t;           // Wert direkt
    }
}

template<typename T>
void printTypeInfo(const T& t) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integraler Typ: " << t << '\n';
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Gleitkommatyp: " << t << '\n';
    } else {
        std::cout << "Anderer Typ\n";
    }
}

// if constexpr in Klassen (z.B. für verschiedene Member)
template<typename T>
class Wrapper {
    T value;
public:
    explicit Wrapper(T v) : value(v) {}

    void print() const {
        if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "String: " << value << '\n';
        } else {
            std::cout << "Wert: " << value << '\n';
        }
    }
};

int main() {
    int x = 5;
    int* px = &x;

    std::cout << getValue(x) << '\n';      // int
    std::cout << getValue(px) << '\n';     // dereferenzierter int

    printTypeInfo(10);
    printTypeInfo(3.14);
    printTypeInfo("Hallo");

    Wrapper<int> wi(100);
    wi.print();

    Wrapper<std::string> ws("Test");
    ws.print();

    return 0;
}
