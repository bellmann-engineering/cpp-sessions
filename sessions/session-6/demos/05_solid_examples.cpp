#include <iostream>
#include <vector>
#include <memory>

// ---- Schlechtes Beispiel (SRP verletzt) ----
class BadSensor {
    int readHardware() { /* ... */ return 42; }
    double computeAverage(const std::vector<int>& data) { /* ... */ return 0.0; }
    void log(const std::string& msg) { std::cout << msg << "\n"; }
public:
    void run() {
        auto val = readHardware();
        // ... speichern ...
        log("Sensor gelesen");
    }
};

// ---- Bessere Aufteilung nach SRP ----
class SensorReader {
public:
    int read() { /* Hardwarezugriff */ return 42; }
};

class SensorProcessor {
public:
    double process(const std::vector<int>& data) { /* Berechnung */ return 0.0; }
};

class SensorLogger {
public:
    void log(const std::string& msg) { std::cout << msg << "\n"; }
};

// ---- OCP-Beispiel ----
class Sensor {
public:
    virtual float read() = 0;
    virtual ~Sensor() = default;
};

class TempSensor : public Sensor {
public:
    float read() override { return 22.5; }
};

class PressureSensor : public Sensor {
public:
    float read() override { return 1013.0; }
};

void process(Sensor& s) {
    std::cout << "Wert: " << s.read() << "\n";
}

int main() {
    TempSensor ts;
    PressureSensor ps;
    process(ts);
    process(ps);
    return 0;
}
