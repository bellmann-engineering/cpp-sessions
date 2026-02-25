#include <iostream>
#include <memory>
#include <vector>

class Child;

class Parent {
public:
    std::vector<std::shared_ptr<Child>> children;
    ~Parent() { std::cout << "Parent destruktor\n"; }
    void addChild(const std::shared_ptr<Child>& child) {
        children.push_back(child);
    }
};

class Child {
public:
    std::weak_ptr<Parent> parent;   // weak_ptr verhindert Zyklus
    ~Child() { std::cout << "Child destruktor\n"; }
    void setParent(const std::shared_ptr<Parent>& p) {
        parent = p;
    }
    void useParent() {
        if (auto sp = parent.lock()) {
            std::cout << "Parent existiert noch\n";
        } else {
            std::cout << "Parent bereits gelöscht\n";
        }
    }
};

int main() {
    {
        auto parent = std::make_shared<Parent>();
        auto child = std::make_shared<Child>();

        parent->addChild(child);
        child->setParent(parent);

        std::cout << "use_count parent: " << parent.use_count() << std::endl;
        std::cout << "use_count child: " << child.use_count() << std::endl;
        child->useParent();
    }
    std::cout << "Ende von main\n";
    return 0;
}
