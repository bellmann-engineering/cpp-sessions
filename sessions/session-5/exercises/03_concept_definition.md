# Übung 3: Concept definieren

**Ziel:** Definieren Sie ein Concept `Drawable`, das Typen beschreibt, die eine `draw()`-Methode besitzen.

## Aufgabenstellung

Ergänzen Sie das Concept `Drawable` und schreiben Sie eine Funktion `render`, die nur mit Typen arbeitet, die `Drawable` erfüllen. Testen Sie mit den Klassen `Circle` und `Square`.

```cpp
#include <iostream>
#include <concepts>

// TODO: Concept Drawable definieren
// Es soll verlangen, dass ein Ausdruck t.draw() gültig ist.
template<typename T>
concept Drawable = requires(T t) {
    // TODO: Ausdruck t.draw() muss gültig sein
    /* TODO */
};

// Nur für Drawable-Typen
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
    // render(nd); // sollte Fehler geben
    return 0;
}
