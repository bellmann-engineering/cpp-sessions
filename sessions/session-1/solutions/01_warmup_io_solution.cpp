#include <iostream>

int main()
{
    std::cout << "Welcome to Modern C++ (C++11) in Embedded Context.\n";

    int value = 0;
    std::cin >> value;

    const int square = value * value;
    std::cout << "The square is: " << square << "\n";

    return 0;
}
