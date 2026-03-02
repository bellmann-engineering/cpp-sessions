// Build: g++ -std=c++20 05_ranges_intro.cpp

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // Klassischer Stil
    std::vector<int> even;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even),
                 [](int x){ return x % 2 == 0; });
    std::vector<int> squares;
    std::transform(even.begin(), even.end(), std::back_inserter(squares),
                   [](int x){ return x * x; });
    std::cout << "Klassisch: ";
    for (int x : squares) std::cout << x << " ";
    std::cout << "\n";

    // Mit Ranges (View + manuelle Materialisierung)
    auto view = v
        | std::views::filter([](int x){ return x % 2 == 0; })
        | std::views::transform([](int x){ return x * x; });

    std::vector<int> result;
    for (int x : view) result.push_back(x);
    std::cout << "Ranges:     ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
