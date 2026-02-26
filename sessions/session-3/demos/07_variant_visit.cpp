#include <iostream>
#include <variant>

int main() {
    std::variant<int, float, char> v;
    v = 42;
    std::cout << std::get<int>(v) << '\n';

    v = 3.14f;
    std::visit([](auto&& arg) {
        std::cout << arg << '\n';
    }, v);
    return 0;
}
