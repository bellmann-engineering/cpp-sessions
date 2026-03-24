#include <memory>
#include <iostream>
#include <string>

struct Base {
    virtual void foo() const = 0;
    virtual ~Base() = default;
};

struct Impl : std::string, Base {
    void foo() const override {
        std::cout << "Impl\n";
    }
};

int main() {

    std::unique_ptr<Impl> impl = std::make_unique<Impl>();
    std::cout << "impl addr: " << impl.get() << std::endl;
    std::unique_ptr<Base> base = std::move(impl);
    std::cout << "base addr: " << base.get() << std::endl;   
    base->foo();
} // löschung