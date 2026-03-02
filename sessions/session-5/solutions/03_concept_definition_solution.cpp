#include <iostream>
#include <concepts>

template<typename T>
concept Drawable = requires(T t) {
    t.draw();
};

void render(const Drawable auto& obj) {
    obj.draw();
}

class Circle {
public:
    void draw() const { std::cout << "Circle\n"; }
};

class Square {
public:
    void draw() const { std::cout << "Square\n"; }
};

class NotDrawable {};

int main() {
    Circle c;
    Square s;
    render(c);
    render(s);

    // NotDrawable nd;
    // render(nd); // Fehler, wie gewünscht
    return 0;
}
