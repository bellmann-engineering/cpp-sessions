#include <iostream>
#include <string>
#include <type_traits>

template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    // Konstruktor
    Pair(T1 f, T2 s) : first(f), second(s) {}

    // Getter
    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // Setter
    void setFirst(const T1& f) {
        first = f;
    }

    void setSecond(const T2& s) {
        second = s;
    }

    // Print
    void print() const {
        std::cout << "(" << first << ", " << second << ")";
    }

    // swap nur wenn T1 == T2
    void swap() requires std::is_same_v<T1, T2>{
        //static_assert(std::is_same<T1, T2>::value, "swap() nur erlaubt wenn T1 == T2");
        T1 temp = first;
        first = second;
        second = temp;
    }
};

int main() {
    Pair<int, double> p1(42, 3.14);
    Pair<std::string, int> p2("Alter", 30);
    Pair<int, int> p3(1, 2);

    p1.print();
    std::cout << std::endl;

    p2.print();
    std::cout << std::endl;

    std::cout << p1.getFirst() << std::endl;
    std::cout << p2.getSecond() << std::endl;

    // swap funktioniert nur hier
    p3.swap();
    p3.print();
    std::cout << std::endl;

    return 0;
}
