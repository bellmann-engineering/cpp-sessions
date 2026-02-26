### 📄 `solutions/01_template_max_solution.cpp`
```cpp
#include <iostream>
#include <string>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.14, 2.72) << std::endl;
    std::cout << max('a', 'z') << std::endl;

    std::string s1 = "Apfel", s2 = "Banane";
    std::cout << max(s1, s2) << std::endl;

    // max(3, 3.14)  // Fehler: unterschiedliche Typen
    return 0;
}
