#include <iostream>

class Demo {
private:
    int m_private = 1;
protected:
    int m_protected = 2;
public:
    int m_public = 3;

    Demo() {
        std::cout << "Demo-Konstruktor\n";
    }
    ~Demo() {
        std::cout << "Demo-Destruktor\n";
    }

    void show() {
        std::cout << "private: " << m_private
                  << ", protected: " << m_protected
                  << ", public: " << m_public << "\n";
    }
};

class Abgeleitet : public Demo {
public:
    void access() {
        // m_private nicht erreichbar (private)
        m_protected = 22;   // OK (protected)
        m_public = 33;       // OK (public)
    }
};

void funktion() {
    Demo lokal;                     // Konstruktor wird aufgerufen
    lokal.show();
    // Ende der Funktion → Destruktor für 'lokal'
}

int main() {
    std::cout << "=== Globale Lebensdauer ===\n";
    funktion();
    std::cout << "funktion() beendet, lokales Objekt wurde zerstört.\n";

    std::cout << "\n=== Vererbung und Sichtbarkeit ===\n";
    Abgeleitet obj;
    obj.access();
    obj.show();   // zeigt geänderte Werte

    return 0;
}
