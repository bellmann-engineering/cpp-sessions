# Übung 2: Referenzen vs. Pointer – Swap-Funktionen analysieren und korrigieren

**Ziel:** Verstehen, warum Referenzen sicherer sind, und typische Fehler bei Pointern erkennen.

## Aufgabenstellung

Gegeben sind drei Implementierungen einer Swap-Funktion.  
Eine der Implementierungen ist **logisch fehlerhaft** (sie vertauscht nur lokale Zeiger, nicht die Werte).  
Eine weitere ist **korrekt, aber unsicher** (sie setzt voraus, dass die Zeiger gültig sind, ohne dies zu prüfen).  
Die dritte ist **sicher und korrekt**.

Analysieren Sie den Code, beantworten Sie die Zusatzfragen und ergänzen Sie die fehlenden Teile.

```cpp
#include <iostream>

// Version A
void swap_ptr_A(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
}

// Version B
void swap_ptr_B(int* a, int* b) {
    // TODO: Fügen Sie eine sinnvolle Vorbedingung (Precondition) ein
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Version C
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;

    std::cout << "Vor Swap: x = " << x << ", y = " << y << std::endl;

    // TODO: Testen Sie jede Funktion (kommentieren Sie die Aufrufe nacheinander ein)
    // swap_ptr_A(&x, &y);
    // swap_ptr_B(&x, &y);
    // swap_ref(x, y);

    std::cout << "Nach Swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
