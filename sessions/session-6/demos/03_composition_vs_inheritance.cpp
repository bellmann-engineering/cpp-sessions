#include <iostream>
#include <memory>

// ---- Vererbungslösung ----
class Motor {
public:
    virtual void start() { std::cout << "Motor generisch\n"; }
    virtual ~Motor() = default;
};

class ElektroMotor : public Motor {
public:
    void start() override { std::cout << "Elektromotor sanft\n"; }
};

class FahrzeugVererbung : public Motor {
    // Fahrzeug ist ein Motor – oft falsch!
};

// ---- Kompositionslösung ----
class Fahrzeug {
    std::unique_ptr<Motor> motor_;
public:
    explicit Fahrzeug(std::unique_ptr<Motor> m) : motor_(std::move(m)) {}
    void starten() { if (motor_) motor_->start(); }
};

int main() {
    // Komposition flexibel:
    auto f1 = Fahrzeug(std::make_unique<ElektroMotor>());
    f1.starten();

    auto f2 = Fahrzeug(std::make_unique<Motor>());
    f2.starten();

    return 0;
}
