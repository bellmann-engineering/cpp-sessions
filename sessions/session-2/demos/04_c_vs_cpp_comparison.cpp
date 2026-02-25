#include <iostream>
#include <memory>
#include <cstdlib>

void c_style() {
    int* p = (int*)malloc(sizeof(int));
    if (!p) return;
    *p = 42;
    std::cout << "C: " << *p << std::endl;
    free(p);
}

void cpp_style() {
    auto p = std::make_unique<int>(42);
    std::cout << "C++: " << *p << std::endl;
}

int main() {
    c_style();
    cpp_style();
    return 0;
}
