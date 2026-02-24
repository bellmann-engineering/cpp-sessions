# Übung 1: Gekapselte GPIO-Pin Klasse (mit optionalem RAII)

**Ziel:** Implementieren Sie eine Klasse `GpioPin`, die einen digitalen Ausgangspin kapselt.  
Die Klasse soll die Hardwarezugriffe kontrollieren und eine einfache Schnittstelle bieten.

## Hintergrund (Embedded‑Kontext)
In der Praxis besitzen viele Mikrocontroller separate **SET/CLR/TOGGLE‑Register**, um Bitoperationen atomar auszuführen.  
Diese Übung verwendet aus didaktischen Gründen ein vereinfachtes Modell: ein einzelnes Datenregister, in dem die Bits direkt gesetzt oder gelöscht werden.

## Aufgabenstellung

Ergänzen Sie die fehlenden Teile (markiert mit `// TODO`) im folgenden Code.  
Beachten Sie dabei:
- Verwenden Sie die Initialisierungsliste des Konstruktors.
- Die Methode `toggle()` soll den aktuellen Zustand lesen und umkehren – nutzen Sie hierfür die **XOR‑Verknüpfung** (`^=`), da sie oft hardwarenäher ist.
- Formulieren Sie **Vorbedingungen (preconditions)** für die Methoden, wo es sinnvoll ist (z.B. dass `m_port` nicht `nullptr` ist).
- **Optional (RAII‑Erweiterung):**  
  Lassen Sie den Konstruktor den Pin automatisch als Ausgang konfigurieren und den Destruktor den Pin in einen definierten Ruhezustand versetzen (z.B. High‑Z oder Aus).  
  *Hinweis:* Dies erfordert zusätzliche Register und ist hier nur als Denkanstoß gedacht – wenn Sie es umsetzen möchten, erweitern Sie die Klasse entsprechend.

```cpp
#include <cstdint>

/**
 * Klasse für einen GPIO-Ausgangspin.
 * Annahme: Das GPIO-Port-Register an der Adresse 'port' steuert den Ausgangspegel.
 * Das Bit für den Pin ist (1u << pin).
 */
class GpioPin {
private:
    volatile uint32_t* m_port;  // Zeiger auf das GPIO-Port-Register (darf nicht nullptr sein)
    uint8_t m_pin;               // Pinnummer (0-15)

public:
    // TODO: Konstruktor, der port und pin initialisiert (Precondition: port != nullptr)
    GpioPin(volatile uint32_t* port, uint8_t pin);

    // TODO: Destruktor (optional für RAII) – könnte den Pin zurücksetzen
    ~GpioPin();

    // TODO: Setzt den Pin auf HIGH (Bit setzen)
    void setHigh();

    // TODO: Setzt den Pin auf LOW (Bit löschen)
    void setLow();

    // TODO: Gibt den aktuellen Zustand zurück (true = HIGH, false = LOW)
    bool getState() const;

    // TODO: Toggelt den Pin (von HIGH zu LOW oder umgekehrt) – nutzen Sie XOR
    void toggle();
};

// ----- Testrahmen (dient zur Überprüfung) -----
int main() {
    volatile uint32_t fake_port = 0;   // simuliertes Hardware-Register
    GpioPin led(&fake_port, 5);        // Pin 5 an Port

    led.setHigh();                       // fake_port Bit 5 sollte 1 sein
    led.toggle();                        // jetzt 0
    led.setLow();                         // bleibt 0

    return 0;
}
