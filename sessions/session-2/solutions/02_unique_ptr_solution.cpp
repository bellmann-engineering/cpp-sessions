#include <iostream>
#include <utility>

template <typename T>
class MyUniquePtr {
private:
    T* m_ptr;

public:
    explicit MyUniquePtr(T* ptr = nullptr) : m_ptr(ptr) {}

    ~MyUniquePtr() {
        delete m_ptr;
    }

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept : m_ptr(other.m_ptr) {
        other.m_ptr = nullptr;
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    T* get() const { return m_ptr; }

    T* release() {
        T* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) {
        delete m_ptr;
        m_ptr = ptr;
    }
};

int main() {
    MyUniquePtr<int> p1(new int(42));
    std::cout << *p1 << std::endl;

    MyUniquePtr<int> p2 = std::move(p1);
    if (!p1.get()) std::cout << "p1 ist leer\n";
    std::cout << *p2 << std::endl;

    int* raw = p2.release();
    std::cout << "roher Pointer: " << *raw << std::endl;
    delete raw;

    MyUniquePtr<int> p3(new int(100));
    p3.reset(new int(200));
    std::cout << *p3 << std::endl;

    return 0;
}
