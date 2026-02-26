#include <iostream>
#include <variant>

using SensorValue = std::variant<int, float, bool>;

void setValue(SensorValue& sv, int value) { sv = value; }
void setValue(SensorValue& sv, float value) { sv = value; }
void setValue(SensorValue& sv, bool value) { sv = value; }

int main() {
    SensorValue sv;
    setValue(sv, 42);
    std::visit([](auto&& arg) { std::cout << arg << '\n'; }, sv);
    setValue(sv, 3.14f);
    std::visit([](auto&& arg) { std::cout << arg << '\n'; }, sv);
    return 0;
}
