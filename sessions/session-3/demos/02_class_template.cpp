#include <iostream>
#include <cstddef>

template <typename T, size_t N>
class RingBuffer {
    T data[N];
    size_t head = 0, tail = 0, count = 0;
public:
    bool push(const T& val) {
        if (count == N) return false;
        data[head] = val;
        head = (head + 1) % N;
        ++count;
        return true;
    }
    bool pop(T& out) {
        if (count == 0) return false;
        out = data[tail];
        tail = (tail + 1) % N;
        --count;
        return true;
    }
};

int main() {
    RingBuffer<int, 4> buf;
    buf.push(10);
    buf.push(20);
    int val;
    buf.pop(val);
    std::cout << val << std::endl;
    return 0;
}
