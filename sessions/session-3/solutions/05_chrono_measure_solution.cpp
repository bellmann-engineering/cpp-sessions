#include <iostream>
#include <chrono>

void compute() {
    volatile int dummy = 0;
    for (int i = 0; i < 1000000; ++i) dummy += i;
}

int main() {
    auto start = std::chrono::steady_clock::now();
    compute();
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Dauer: " << elapsed.count() << " µs\n";
    return 0;
}
