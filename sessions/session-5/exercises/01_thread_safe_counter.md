# Übung 1: Thread‑sicherer Zähler

**Ziel:** Implementieren Sie einen Zähler, der von mehreren Threads parallel inkrementiert werden kann – ohne Datenverlust.

## Aufgabenstellung

Gegeben ist eine unvollständige Klasse `Counter`. Ergänzen Sie die fehlenden Teile (`// TODO`) so, dass die Klasse thread‑sicher wird. Verwenden Sie `std::mutex` und `std::lock_guard`.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Counter {
private:
    int value = 0;
    mutable std::mutex m;   // mutable, damit es in const-Methoden verwendet werden kann
public:
    // TODO: Methode increment() – sicher inkrementieren
    void increment() {
        // ...
    }

    int get() const {
        // TODO: get implementieren (auch schützen!)
        // ...
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

    // 4 Threads starten
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
