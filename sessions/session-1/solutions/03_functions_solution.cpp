#include <iostream>

void swap_ref(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Pointer-Version muss defensiv sein (nullptr möglich)
bool swap_ptr(int* a, int* b)
{
    if (a == nullptr || b == nullptr)
        return false;

    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

int main()
{
    int x = 5;
    int y = 10;

    std::cout << "Before swap_ref: x=" << x << ", y=" << y << "\n";
    swap_ref(x, y);
    std::cout << "After  swap_ref: x=" << x << ", y=" << y << "\n";

    std::cout << "Before swap_ptr: x=" << x << ", y=" << y << "\n";
    const bool ok = swap_ptr(&x, &y);
    std::cout << "After  swap_ptr: x=" << x << ", y=" << y << " (ok=" << ok << ")\n";

    return 0;
}
