// Lösung zu Übung 2 – SOLID Refactoring

#include <iostream>
#include <vector>

// 1. Lesen der Hardware
class SensorReader {
public:
    int read() { /* Hardwarezugriff */ return 42; }
};

// 2. Berechnung
class DataProcessor {
public:
    double average(const std::vector<int>& data) {
        if (data.empty()) return 0.0;
        double sum = 0;
        for (int v : data) sum += v;
        return sum / data.size();
    }
};

// 3. Ausgabe
class Output {
public:
    void send(const std::string& report) {
        std::cout << report << "\n";
    }
};

// 4. Konfiguration
class Config {
public:
    void load() { /* EEPROM lesen */ }
    // ...
};

// Zusammenspiel über Komposition
class DeviceController {
    SensorReader reader;
    DataProcessor processor;
    Output output;
    Config config;
public:
    void run() {
        int val = reader.read();
        // ... speichern ...
        double avg = processor.average({val}); // vereinfacht
        output.send("Wert: " + std::to_string(val));
    }
};
