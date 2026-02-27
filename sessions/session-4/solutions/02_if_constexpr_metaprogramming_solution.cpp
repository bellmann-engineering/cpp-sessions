#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template<typename T>
void printInfo(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << value << " (integral)\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << value << " (floating point)\n";
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << '"' << value << '"' << '\n';
    } else if constexpr (std::is_same_v<T, const char*>) {
        std::cout << '"' << value << '"' << " (C-String)\n";
    } else {
        std::cout << "Unbekannter Typ\n";
    }
}

int main() {
    printInfo(42);
    printInfo(3.14);
    printInfo("Hallo");          // const char*
    printInfo(std::string("Welt"));
    printInfo(std::vector<int>{1,2,3});
    return 0;
}
