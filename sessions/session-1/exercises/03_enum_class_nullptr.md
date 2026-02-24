
---

## 📄 `exercises/03_enum_class_nullptr.md`

```markdown
# Übung 3: enum class und nullptr – Typsichere Hardware-Konfiguration

**Ziel:** Anwendung von `enum class` und `nullptr` zur Erhöhung der Typsicherheit in einer embedded‑typischen Konfigurationsroutine.

## Ausgangssituation (C‑Stil)

Die folgende Funktion initialisiert einen SPI‑Controller und verwendet dazu Makros und `NULL`.  
Dieser Stil ist fehleranfällig, da z.B. falsche Integer‑Werte übergeben werden können.

```c
#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1

void SPI_Init(volatile uint32_t* baseAddr, int mode, int bitOrder) {
    if (baseAddr == NULL) {
        baseAddr = (volatile uint32_t*)0x40013000;   // Standardadresse
    }
    // Hardware-Register setzen ...
}
