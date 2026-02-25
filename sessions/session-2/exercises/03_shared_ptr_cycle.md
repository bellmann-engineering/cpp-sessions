
### `exercises/03_shared_ptr_cycle.md`
```markdown
# Übung 3: Zyklische Abhängigkeiten mit shared_ptr vermeiden

**Ziel:** Verstehen, warum zyklische Referenzen mit `shared_ptr` zu Speicherlecks führen und wie `weak_ptr` das verhindert.

## Aufgabenstellung

Gegeben sind zwei Klassen `Parent` und `Child`, die gegenseitig aufeinander verweisen. Die aktuelle Implementierung verwendet `shared_ptr` für beide Richtungen – das führt zu einem Zyklus.

Analysieren Sie den Code, korrigieren Sie ihn durch Einsatz von `weak_ptr` und beantworten Sie die Zusatzfragen.

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Child; // Vorwärtsdeklaration

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
    // TODO: Hier ist das Problem – shared_ptr erzeugt einen Zyklus
    std::shared_ptr<Parent> parent;
    ~Child() { std::cout << "Child destruktor\n"; }
    void setParent(const std::shared_ptr<Parent>& p) {
        parent = p;
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
    } // Hier werden Destruktoren erwartet, aber aufgrund des Zyklus nicht aufgerufen

    std::cout << "Ende von main\n";
    return 0;
}
