#include <iostream>
#include <chrono>
#include <thread>

class Task {
public:
    void execute() {
        std::cout << "Task running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
};

template<typename T>
class LoggingMixin : public T {
public:
    void execute() {
        std::cout << "[LOG] start" << std::endl;
        T::execute();
        std::cout << "[LOG] end" << std::endl;
    }
};

template<typename T>
class TimingMixin : public T {
public:
    void execute() {
        auto start = std::chrono::steady_clock::now();
        T::execute();
        auto end = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "[TIME] " << duration.count() << " ms" << std::endl;
    }
};

int main() {
    LoggingMixin<TimingMixin<Task>> t;
    t.execute();

    return 0;
}