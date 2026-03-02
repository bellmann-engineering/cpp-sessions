// Build: g++ -std=c++17 -pthread 01_mutex_basics.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex m;
int counter = 0;

void increment_without_lock() {
    for (int i = 0; i < 1000; ++i) {
        ++counter; // Data Race!
    }
}

void increment_with_lock() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(m);
        ++counter; // sicher
    }
}

int main() {
    // Data Race demonstrieren
    counter = 0;
    std::thread t1(increment_without_lock);
    std::thread t2(increment_without_lock);
    t1.join(); t2.join();
    std::cout << "Ohne Lock (Data Race, Ergebnis undefiniert): " << counter << "\n";

    // Mit Mutex
    counter = 0;
    std::thread t3(increment_with_lock);
    std::thread t4(increment_with_lock);
    t3.join(); t4.join();
    std::cout << "Mit Lock: " << counter << "\n";
    return 0;
}
