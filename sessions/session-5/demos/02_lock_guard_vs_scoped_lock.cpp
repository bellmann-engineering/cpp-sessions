// Build: g++ -std=c++17 -pthread 02_lock_guard_vs_scoped_lock.cpp

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1, m2;

// Potentieller Deadlock: unterschiedliche Lock-Reihenfolge
void deadlock_risk() {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> lock2(m2);
    std::cout << "Thread A: beide Locks erhalten\n";
}

void deadlock_risk2() {
    std::lock_guard<std::mutex> lock2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> lock1(m1);
    std::cout << "Thread B: beide Locks erhalten\n";
}

// Lösung mit scoped_lock
void safe() {
    std::scoped_lock lock(m1, m2); // beide auf einmal
    std::cout << "Thread C: Locks sicher erworben\n";
}

int main() {
    // Deadlock-Gefahr (kommentieren Sie zum Testen ein)
    // std::thread t1(deadlock_risk);
    // std::thread t2(deadlock_risk2);
    // t1.join(); t2.join();

    // Sicher mit scoped_lock
    std::thread t3(safe);
    std::thread t4(safe);
    t3.join(); t4.join();
    return 0;
}
