#include <iostream>
#include <chrono>

// ---- Virtueller Ansatz ----
struct VirtualBase {
    virtual int compute(int x) const = 0;
    virtual ~VirtualBase() = default;
};

struct VirtualAdd : VirtualBase {
    int compute(int x) const override { return x + x; }
};

struct VirtualMul : VirtualBase {
    int compute(int x) const override { return x * x; }
};

// ---- CRTP Ansatz ----
template<typename Derived>
struct CrtpBase {
    int compute(int x) const {
        return static_cast<const Derived*>(this)->computeImpl(x);
    }
};

struct CrtpAdd : CrtpBase<CrtpAdd> {
    int computeImpl(int x) const { return x + x; }
};

struct CrtpMul : CrtpBase<CrtpMul> {
    int computeImpl(int x) const { return x * x; }
};

// Testfunktion
template<typename T>
void test(const T& obj, const char* name) {
    volatile int sink = 0;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        sink = obj.compute(i);
    }
    auto end = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << name << ": " << us << " µs\n";
}

int main() {
    VirtualAdd vadd;
    VirtualMul vmul;
    CrtpAdd cadd;
    CrtpMul cmul;

    test(vadd, "virtuell add");
    test(vmul, "virtuell mul");
    test(cadd, "CRTP add");
    test(cmul, "CRTP mul");

    return 0;
}
