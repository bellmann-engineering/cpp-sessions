// Build: g++ -std=c++20 -pthread 03_jthread_stop_token.cpp

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void worker(std::stop_token st) {
    int count = 0;
    while (!st.stop_requested()) {
        std::cout << "Arbeite ... " << ++count << "\n";
        std::this_thread::sleep_for(200ms);
    }
    std::cout << "Worker gestoppt nach " << count << " Zyklen.\n";
}

int main() {
    std::jthread t(worker);
    std::this_thread::sleep_for(1s);
    t.request_stop();  // optional, passiert automatisch bei Zerstörung
    // t wird hier automatisch gejoint
    return 0;
}
