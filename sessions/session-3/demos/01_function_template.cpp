#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.14, 2.72) << std::endl;
    std::cout << max('a', 'z') << std::endl;
    std::cout << max<double>(3, 3.14) << std::endl; // erzwingt T = double -> 3 wird implizit zu 3.0 konvertiert, Vergleich erfolgt als double
    return 0;
}
