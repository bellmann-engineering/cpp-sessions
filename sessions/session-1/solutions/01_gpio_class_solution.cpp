
---

## 🔧 `solutions/01_gpio_class_solution.cpp`

```cpp
#include <cstdint>
#include <cassert>

class GpioPin {
private:
    volatile uint32_t* m_port;
    uint8_t m_pin;

public:
    // Konstruktor mit Precondition
    GpioPin(volatile uint32_t* port, uint8_t pin) : m_port(port), m_pin(pin) {
        assert(port != nullptr);
        // Optional: Pin als Ausgang konfigurieren (vereinfacht)
        // *m_port |= (1u << (m_pin + 16)); // fiktives Richtungsregister
    }

    // Optionaler RAII-Destruktor – Pin zurücksetzen
    ~GpioPin() {
        // Pin in definierten Ruhezustand versetzen (z.B. Eingang, Pull-up aus)
        // *m_port &= ~(1u << m_pin);
        // *m_port &= ~(1u << (m_pin + 16));
    }

    void setHigh() {
        *m_port |= (1u << m_pin);
    }

    void setLow() {
        *m_port &= ~(1u << m_pin);
    }

    bool getState() const {
        return (*m_port >> m_pin) & 1u;
    }

    void toggle() {
        // XOR ist hardwarenah und oft effizienter
        *m_port ^= (1u << m_pin);
    }
};

int main() {
    volatile uint32_t fake_port = 0;
    GpioPin led(&fake_port, 5);
    led.setHigh();
    led.toggle();
    led.setLow();
    return 0;
}
