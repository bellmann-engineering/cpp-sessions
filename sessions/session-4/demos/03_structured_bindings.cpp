#include <iostream>
#include <tuple>
#include <map>

// Funktion, die ein Tupel zurückgibt
std::tuple<int, double, char> getTuple() {
    return {42, 3.14, 'X'};
}

struct Point {
    int x, y;
};

int main() {
    // Structured Bindings mit Tupel
    auto [i, d, c] = getTuple();
    std::cout << "i=" << i << ", d=" << d << ", c=" << c << '\n';

    // Structured Bindings mit Paar
    std::map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}};
    for (const auto& [name, age] : ages) {
        std::cout << name << " ist " << age << " Jahre alt.\n";
    }

    // Structured Bindings mit eigener Struktur
    Point p{10,20};
    auto [x, y] = p;          // Kopie
    auto& [rx, ry] = p;       // Referenz

    rx = 99;
    std::cout << "p.x=" << p.x << ", p.y=" << p.y << '\n';

    // Structured Bindings mit Array
    int arr[] = {1,2,3};
    auto [a,b,c2] = arr;      // Kopie
    auto& [ra,rb,rc] = arr;   // Referenz

    ra = 100;
    std::cout << "arr[0]=" << arr[0] << '\n';

    return 0;
}
