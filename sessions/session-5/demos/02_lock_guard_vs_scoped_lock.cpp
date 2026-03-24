// Build: g++ -std=c++17 -pthread 02_lock_guard_vs_scoped_lock.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1, m2;

// Thread 1: sperrt erst m1, dann m2
void lock_m1_then_m2() {
    std::lock_guard<std::mutex> first_lock(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> second_lock(m2);

    std::cout << "Thread 1: m1 und m2 gesperrt\n";
}

// Thread 2: sperrt erst m2, dann m1
void lock_m2_then_m1() {
    std::lock_guard<std::mutex> first_lock(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> second_lock(m1);

    std::cout << "Thread 2: m2 und m1 gesperrt\n";
}

// Sichere Variante: beide Mutexes gemeinsam sperren
void lock_both_safely() {
    std::scoped_lock lock(m1, m2);
    std::cout << "Sicher: m1 und m2 gemeinsam gesperrt\n";
}

int main() {
    // Deadlock-Gefahr:
    // std::thread t1(lock_m1_then_m2);
    // std::thread t2(lock_m2_then_m1);
    // t1.join();
    // t2.join();

    // Sichere Variante:
    std::thread t3(lock_both_safely);
    std::thread t4(lock_both_safely);
    t3.join();
    t4.join();

    return 0;
}
