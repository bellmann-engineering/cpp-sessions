# Übung 1: GPIO-Pin Klasse

**Ziel:** Implementieren Sie eine Klasse `GpioPin`, die einen digitalen Ausgangspin kapselt. Die Klasse soll Hardwarezugriffe kontrollieren und eine einfache Schnittstelle bieten.

**Aufgabe:**  
Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.

```cpp
#include <cstdint>

/**
 * Klasse für einen GPIO-Ausgangspin.
 * Annahme: Das GPIO-Port-Register an der Adresse 'port' steuert den Ausgangspegel.
 * Das Bit für den Pin ist (1 << pin).
 */
class GpioPin {
private:
    volatile uint32_t* m_port;  // Zeiger auf das GPIO-Port-Register
    uint8_t m_pin;               // Pinnummer (0-15)

public:
    // TODO: Konstruktor, der port und pin initialisiert
    GpioPin(volatile uint32_t* port, uint8_t pin) {
        // ...
    }

    // TODO: Setzt den Pin auf HIGH (Bit setzen)
    void setHigh() {
        // *m_port |= (1 << m_pin);
    }

    // TODO: Setzt den Pin auf LOW (Bit löschen)
    void setLow() {
        // *m_port &= ~(1 << m_pin);
    }

    // TODO: Gibt den aktuellen Zustand zurück (true = HIGH, false = LOW)
    bool getState() const {
        // return (*m_port >> m_pin) & 1;
    }

    // TODO: Toggelt den Pin (von HIGH zu LOW oder umgekehrt)
    void toggle() {
        // ...
    }
};

// ----- Testcode (zum Ausprobieren) -----
int main() {
    // Simulierte Hardware-Adresse (globale Variable als Register-Ersatz)
    volatile uint32_t fake_port = 0;

    GpioPin led(&fake_port, 5);   // Pin 5 an Port

    led.setHigh();                 // Erwartet: fake_port Bit 5 = 1
    led.toggle();                  // Jetzt Bit 5 = 0
    led.setLow();                  // Bleibt 0

    return 0;
}
