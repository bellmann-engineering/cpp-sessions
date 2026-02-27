#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// in g++ mit -std=c++20 flag komplieren

// Legacy-Code (C++98/03 ähnlich)
int legacyMax(int a, int b) {
    return (a > b) ? a : b;
}

void legacyExample() {
    std::vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(1);
    v.push_back(5);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

// Modernes C++ (C++17/20)
auto modernMax(auto a, auto b) {
    return (a > b) ? a : b;
}

void modernExample() {
    std::vector v = {3,1,4,1,5};   // CTAD
    for (const auto& val : v) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    legacyExample();
    modernExample();

    std::cout << "legacyMax(5,7): " << legacyMax(5,7) << '\n';
    std::cout << "modernMax(5,7): " << modernMax(5,7) << '\n';

    return 0;
}
