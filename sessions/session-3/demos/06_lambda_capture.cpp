#include <iostream>

int main() {
    int faktor = 2;
    auto verdopple = [faktor](int x) { return x * faktor; };
    std::cout << verdopple(5) << '\n';

    int sum = 0;
    auto accu = [&sum](int x) { sum += x; };
    accu(10);
    accu(20);
    std::cout << sum << '\n';
    return 0;
}
