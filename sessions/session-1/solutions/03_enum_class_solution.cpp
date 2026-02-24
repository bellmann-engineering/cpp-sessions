#include <cstdint>

enum class SpiMode : uint8_t { MODE0, MODE1, MODE2, MODE3 };
enum class BitOrder : uint8_t { MSB_FIRST, LSB_FIRST };

void Spi_init(volatile uint32_t* baseAddr, SpiMode mode, BitOrder bitOrder) {
    if (baseAddr == nullptr) {
        baseAddr = reinterpret_cast<volatile uint32_t*>(0x40013000);
    }
    // Platzhalter für Hardware-Konfiguration
    // *baseAddr = static_cast<uint32_t>(mode) | (static_cast<uint32_t>(bitOrder) << 2);
}

int main() {
    Spi_init(nullptr, SpiMode::MODE0, BitOrder::MSB_FIRST);
    Spi_init(reinterpret_cast<volatile uint32_t*>(0x40014000),
             SpiMode::MODE3, BitOrder::LSB_FIRST);

    // Die folgenden Zeilen kompilieren nicht – Typsicherheit!
    // Spi_init(nullptr, 0, 1);
    // Spi_init(nullptr, SpiMode::MODE0, 42);

    return 0;
}
