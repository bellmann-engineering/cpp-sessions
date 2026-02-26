#include <iostream>
#include <vector>
#include <array>

int main() {
    std::array<int, 5> arr = {1,2,3,4,5};
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> vec = {1,2,3};
    vec.push_back(4);
    for (int x : vec) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
