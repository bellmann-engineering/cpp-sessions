// Build: g++ -std=c++20 04_format_printf_compare.cpp

#include <iostream>
#include <format>
#include <cstdio>

int main() {
    int value = 42;

    // printf (nicht typsicher, aber schnell)
    std::printf("printf: %d\n", value);

    // cout (typsicher, aber umständlich formatiert)
    std::cout << "cout: " << value << std::endl;

    // std::format (typsicher und elegant)
    std::cout << std::format("format: {}\n", value);

    return 0;
}
