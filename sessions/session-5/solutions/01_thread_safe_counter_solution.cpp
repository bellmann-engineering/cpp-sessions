---
Lösungen (3 C++-Dateien)
###  `solutions/
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Counter {
private:
    int value = 0;
    mutable std::mutex m;
public:
    void increment() {
        std::lock_guard<std::mutex> lock(m);
        ++value;
    }

    int get() const {
        std::lock_guard<std::mutex> lock(m);
        return value;
    }
};

void worker(Counter& c, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        c.increment();
    }
}

int main() {
    Counter c;
    const int iterations = 10000;
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(worker, std::ref(c), iterations);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Erwartet: " << 4 * iterations << "\n";
    std::cout << "Tatsächlich: " << c.get() << "\n";
    return 0;
}
