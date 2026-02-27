# Übung 1: RAII für einen Puffer

**Ziel:** Implementieren Sie eine RAII-Klasse `HeapBuffer`, die einen dynamisch allozierten Speicherpuffer verwaltet.

## Aufgabenstellung

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.

```cpp
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstddef>
#include <utility>   // <-- für std::move (wichtig für den Test in main)

class HeapBuffer {
private:
    uint8_t* m_data;
    size_t m_size;

public:
    // TODO: Konstruktor – allokiert 'size' Bytes auf dem Heap
    // Precondition: size > 0
    HeapBuffer(size_t size) {
        // ...
    }

    // TODO: Destruktor – gibt den Speicher wieder frei
    ~HeapBuffer() {
        // ...
    }

    // Verboten: Kopieren (da sonst double-delete)
    HeapBuffer(const HeapBuffer&) = delete;
    HeapBuffer& operator=(const HeapBuffer&) = delete;

    // TODO: Move-Konstruktor (optional)
    HeapBuffer(HeapBuffer&& other) noexcept {
        // ...
    }

    // TODO: Move-Zuweisung (optional)
    HeapBuffer& operator=(HeapBuffer&& other) noexcept {
        // ...
    }

    void fill(uint8_t value) {
        memset(m_data, value, m_size);
    }

    void print() const {
        for (size_t i = 0; i < m_size; ++i) {
            std::cout << (int)m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    {
        HeapBuffer buffer(10);
        buffer.fill(42);
        buffer.print();
    } // Hier sollte der Destruktor aufgerufen werden

    // Test: Verschieben
    HeapBuffer buffer1(5);
    buffer1.fill(1);
    HeapBuffer buffer2 = std::move(buffer1);
    buffer2.print();

    return 0;
}
