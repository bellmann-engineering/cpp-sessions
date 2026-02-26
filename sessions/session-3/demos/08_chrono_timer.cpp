#include <iostream>
#include <chrono>

template<class Rep, class Period>
void busy_wait(std::chrono::duration<Rep, Period> d) {
    auto start = std::chrono::steady_clock::now();
    auto end = start + d;
    while (std::chrono::steady_clock::now() < end) {
        // aktives Warten
    }
}

int main() {
    using namespace std::chrono;
    auto start = steady_clock::now();
    busy_wait(milliseconds(100));
    auto end = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);
    std::cout << "Verstrichene Zeit: " << elapsed.count() << " µs\n";
    return 0;
}
