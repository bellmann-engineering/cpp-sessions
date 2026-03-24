#include <iostream>
#include <memory>

int main() {
    auto p1 = std::make_shared<int>(42);
    std::cout << "p1 count: " << p1.use_count() << "\n";  // 1

    {
        auto p2 = p1;
        std::cout << "p1 count: " << p1.use_count() << "\n";  // 2
        std::cout << "p2 count: " << p2.use_count() << "\n";  // 2

        {
            auto p3 = p2;
            std::cout << "p1 count: " << p1.use_count() << "\n";  // 3
        } // p3 weg

        std::cout << "p1 count nach p3: " << p1.use_count() << "\n";  // 2
    } // p2 weg

    std::cout << "p1 count nach p2: " << p1.use_count() << "\n";  // 1

    p1 = nullptr;  // letzter Besitzer weg -> Speicher wird freigegeben
}