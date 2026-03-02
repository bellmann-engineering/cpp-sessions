# Übung 2: SOLID Refactoring

**Ziel:** Die folgende Klasse `DeviceController` verstößt gegen mehrere SOLID-Prinzipien. Zerlegen Sie sie in kleinere, verantwortungsgetrennte Klassen.

```cpp
class DeviceController {
public:
    void readSensor() {
        // Hardware-Lesecode
    }
    void computeAverage() {
        // Berechnung
    }
    void sendReport() {
        // UART-Ausgabe
    }
    void configure() {
        // Konfiguration aus EEPROM lesen
    }
};
