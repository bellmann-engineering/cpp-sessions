#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource erstellt\n"; }
    ~Resource() { std::cout << "Resource zerstört\n"; }
    void use() { std::cout << "Resource genutzt\n"; }
};

int main() {
    std::shared_ptr<Resource> sp1 = std::make_shared<Resource>();
    std::cout << "use_count: " << sp1.use_count() << std::endl;
    {
        std::shared_ptr<Resource> sp2 = sp1;
        std::cout << "use_count: " << sp1.use_count() << std::endl;
        sp2->use();
    }
    std::cout << "use_count: " << sp1.use_count() << std::endl;
    sp1->use();
    return 0;
}
