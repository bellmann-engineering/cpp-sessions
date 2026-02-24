#include <iostream>
#include <cstdint>

// Einfache Klasse, die einen Sensor abstrahiert
class Sensor {
private:
    int m_id;
    volatile uint32_t* m_register;  // simulierter Hardware-Register

public:
    Sensor(int id, volatile uint32_t* reg) : m_id(id), m_register(reg) {
        std::cout << "Sensor " << m_id << " initialisiert an Adresse "
                  << static_cast<const void*>(m_register) << std::endl;
    }

    int read() const {
        return *m_register & 0xFF;  // simulierten Wert lesen
    }
};

int main() {
    volatile uint32_t fake_hw = 42;
    Sensor tempSensor(1, &fake_hw);
    std::cout << "Messwert: " << tempSensor.read() << std::endl;
    return 0;
}
