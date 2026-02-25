#include <iostream>
#include <memory>
#include <utility>   // für std::move

class Sensor {
public:
    Sensor() { std::cout << "Sensor erstellt\n"; }
    ~Sensor() { std::cout << "Sensor zerstört\n"; }
    void read() { std::cout << "Messwert lesen\n"; }
};

std::unique_ptr<Sensor> createSensor() {
    return std::make_unique<Sensor>();
}

int main() {
    auto sensor = createSensor();
    sensor->read();
    // auto sensor2 = sensor; // Fehler: unique_ptr nicht kopierbar
    auto sensor2 = std::move(sensor);
    if (!sensor) std::cout << "sensor ist jetzt leer\n";
    sensor2->read();
    return 0;
}
