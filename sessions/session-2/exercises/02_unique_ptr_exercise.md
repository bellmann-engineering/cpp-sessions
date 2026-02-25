# Übung 2: Eigener unique_ptr (vereinfacht)

**Ziel:** Implementieren Sie eine vereinfachte Version von `std::unique_ptr` für den Typ `int`.

## Aufgabenstellung

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.

```cpp
#include <iostream>
#include <utility>

template <typename T>
class MyUniquePtr {
private:
    T* m_ptr;

public:
    // TODO: Konstruktor – übernimmt einen rohen Pointer (Default = nullptr)
    explicit MyUniquePtr(T* ptr = nullptr) : m_ptr(ptr) {}

    // TODO: Destruktor – löscht den verwalteten Speicher
    ~MyUniquePtr() {
        // ...
    }

    // Verboten: Kopieren
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // TODO: Verschiebe-Konstruktor
    MyUniquePtr(MyUniquePtr&& other) noexcept {
        // ...
    }

    // TODO: Verschiebe-Zuweisung
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        // ...
    }

    // Dereferenzierungsoperatoren
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

    // Zugriff auf rohen Pointer
    T* get() const { return m_ptr; }

    // Gibt den Besitz auf (ohne Löschen)
    T* release() {
        T* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    // Löscht das verwaltete Objekt und setzt einen neuen Pointer
    void reset(T* ptr = nullptr) {
        delete m_ptr;
        m_ptr = ptr;
    }
};

int main() {
    // Test 1: Erstellung und Nutzung
    MyUniquePtr<int> p1(new int(42));
    std::cout << *p1 << std::endl;

    // Test 2: Verschieben
    MyUniquePtr<int> p2 = std::move(p1);
    if (!p1.get()) std::cout << "p1 ist leer\n";
    std::cout << *p2 << std::endl;

    // Test 3: release und reset
    int* raw = p2.release();
    std::cout << "roher Pointer: " << *raw << std::endl;
    delete raw;

    MyUniquePtr<int> p3(new int(100));
    p3.reset(new int(200));
    std::cout << *p3 << std::endl;

    return 0;
}
