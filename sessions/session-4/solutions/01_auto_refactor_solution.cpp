#include <iostream>
#include <vector>
#include <map>

int main() {
    // 1. Einfache Variablen
    auto i = 42;
    auto d = 3.14;
    auto str = "Hallo";   // const char*

    // 2. Iteratoren
    std::vector<int> vec = {1,2,3,4};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // 3. Range‑basierte Schleife (manuell)
    std::map<std::string, int> table = {{"eins",1},{"zwei",2}};
    for (auto it = table.cbegin(); it != table.cend(); ++it) {
        std::cout << it->first << "=" << it->second << '\n';
    }

    // 4. Lambda-Parameter (C++14) – hier bleibt das Lambda unverändert,
    //    aber der Aufruf in der Schleife kann vereinfacht werden.
    auto lambda = [](const auto& p) {
        std::cout << p.first << "->" << p.second << '\n';
    };
    for (const auto& elem : table) {
        lambda(elem);
    }

    return 0;
}
