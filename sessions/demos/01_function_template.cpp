#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.14, 2.72) << std::endl;
    std::cout << max('a', 'z') << std::endl;
    return 0;
}
