
---

## 🔧 Lösungen

### `solutions/01_raii_buffer_solution.cpp`
```cpp
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstddef>
#include <utility>   // für std::move

class HeapBuffer {
private:
    uint8_t* m_data;
    size_t m_size;

public:
    // Konstruktor
    HeapBuffer(size_t size) : m_size(size) {
        m_data = new uint8_t[size];
    }

    // Destruktor
    ~HeapBuffer() {
        delete[] m_data;
    }

    // Kopieren verboten
    HeapBuffer(const HeapBuffer&) = delete;
    HeapBuffer& operator=(const HeapBuffer&) = delete;

    // Verschiebe-Konstruktor
    HeapBuffer(HeapBuffer&& other) noexcept
        : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // Verschiebe-Zuweisung
    HeapBuffer& operator=(HeapBuffer&& other) noexcept {
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            m_size = other.m_size;
            other.m_data = nullptr;
            other.m_size = 0;
        }
        return *this;
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
    }

    HeapBuffer buffer1(5);
    buffer1.fill(1);
    HeapBuffer buffer2 = std::move(buffer1);
    buffer2.print();

    return 0;
}
