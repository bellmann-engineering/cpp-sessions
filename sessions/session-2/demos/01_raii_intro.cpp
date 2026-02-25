#include <iostream>
#include <cstdint>

class GpioPin {
private:
    volatile uint32_t* m_port;
    uint8_t m_pin;
public:
    GpioPin(volatile uint32_t* port, uint8_t pin) : m_port(port), m_pin(pin) {
        *m_port |= (1u << m_pin);
        std::cout << "GPIO-Pin " << (int)m_pin << " aktiviert\n";
    }
    ~GpioPin() {
        *m_port &= ~(1u << m_pin);
        std::cout << "GPIO-Pin " << (int)m_pin << " deaktiviert\n";
    }
    void toggle() {
        *m_port ^= (1u << m_pin);
    }
};

int main() {
    volatile uint32_t fake_port = 0;
    {
        GpioPin led(&fake_port, 5);
        led.toggle();
    }
    std::cout << "fake_port: " << fake_port << std::endl;
    return 0;
}
