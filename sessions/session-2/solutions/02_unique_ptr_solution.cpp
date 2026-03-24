#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Sensor {
public:
    Sensor(std::string name) : name_(name) {
        std::cout << "Sensor " << name_ << " erstellt\n";
    }

    ~Sensor() {
        std::cout << "Sensor " << name_ << " zerstört\n";
    }

    void read() const {
        std::cout << "Lese Daten von " << name_ << "\n";
    }

private:
    std::string name_;
};

class Device {
public:
    // Ownership des Sensors wird übernommen
    Device(std::unique_ptr<Sensor> sensor) : sensor_(std::move(sensor)) {}

    void readSensor() const {
        if (sensor_) {
            sensor_->read();
        } else {
            std::cout << "Kein Sensor vorhanden\n";
        }
    }

    void replaceSensor(std::unique_ptr<Sensor> newSensor) {
        sensor_ = std::move(newSensor); // alter Sensor wird automatisch freigegeben
    }

private:
    std::unique_ptr<Sensor> sensor_;
};

std::unique_ptr<Sensor> createSensor(const std::string& name) {
    return std::make_unique<Sensor>(name);
}

int main() {
    std::cout << "=== 1-3: Device mit Sensor aus Factory ===\n";
    auto s1 = createSensor("Temp-1");
    Device d1(std::move(s1));

    d1.readSensor();

    if (!s1) {
        std::cout << "s1 ist nach std::move leer\n";
    }

    std::cout << "\n=== 4: Mehrere Devices im Vector ===\n";
    std::vector<std::unique_ptr<Device>> devices;

    devices.push_back(std::make_unique<Device>(createSensor("Temp-2")));
    devices.push_back(std::make_unique<Device>(createSensor("Temp-3")));
    devices.push_back(std::make_unique<Device>(nullptr)); // Bonus A: Device ohne Sensor

    for (const auto& device : devices) {
        device->readSensor();
    }

    std::cout << "\n=== 5: Transfer zwischen Containern ===\n";
    std::vector<std::unique_ptr<Device>> backupDevices;

    backupDevices.push_back(std::move(devices.back()));
    devices.pop_back();

    std::cout << "devices.size(): " << devices.size() << "\n";
    std::cout << "backupDevices.size(): " << backupDevices.size() << "\n";

    std::cout << "\n=== Bonus B: Sensor austauschen ===\n";
    backupDevices[0]->readSensor();
    backupDevices[0]->replaceSensor(createSensor("Ersatzsensor"));
    backupDevices[0]->readSensor();

    std::cout << "\n=== 6: Fehleranalyse ===\n";
    std::unique_ptr<Sensor> sx1 = createSensor("Temp-X");

    // Fehler:
    // std::unique_ptr<Sensor> sx2 = sx1;
    // unique_ptr darf nicht kopiert werden, weil es genau einen Besitzer geben soll.

    // Korrekt:
    std::unique_ptr<Sensor> sx2 = std::move(sx1);

    if (!sx1) {
        std::cout << "sx1 ist nach std::move leer\n";
    }
    if (sx2) {
        sx2->read();
    }

    std::cout << "\n=== Programmende ===\n";
    return 0;
}