#include <iostream>
#include <string>
#include <string_view>

void print(std::string_view sv) {
    for (char c : sv) std::cout << c;
    std::cout << '\n';
}

int main() {
    std::string s = "Hallo Welt";
    print(s);
    print("C-String");
    return 0;
}
