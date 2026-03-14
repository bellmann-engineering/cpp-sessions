# Beispiel: Swap mit Pointer und Referenzen

Dieses Beispiel zeigt zwei Möglichkeiten, zwei Werte zu vertauschen.

```cpp
void swap_ptr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
````

Aufruf:

```cpp
int x = 5;
int y = 10;

swap_ptr(&x, &y);
swap_ref(x, y);
```

Beide Varianten funktionieren.
Die Referenz-Version entspricht jedoch dem üblichen **C++-Stil**, weil kein Umgang mit Adressen (&) und Dereferenzierung (*) notwendig ist und damit eine ganze Klasse typischer Pointer-Fehler vermieden wird.

---

# Übung: Pointer vs. Referenzen - Funktion selbst formulieren

## Aufgabenstellung

Eine Funktion soll einen Kontostand um einen Bonus erhöhen.

Schreiben Sie dazu selbst:

* eine Variante mit Pointer
* eine Variante mit Pointer und Schutz gegen ungültige Übergabe
* eine Variante mit Referenz

Verwenden Sie die folgenden Anforderungen und ergänzen Sie den Code selbst.

```cpp
#include <iostream>

int main() {
    int account = 100;

    std::cout << "Vorher: " << account << std::endl;

    // Rufen Sie hier Ihre Pointer-Version auf

    std::cout << "Nach Pointer-Version: " << account << std::endl;

    // Setzen Sie den Wert wieder auf 100

    // Rufen Sie hier Ihre abgesicherte Pointer-Version auf

    std::cout << "Nach sicherer Pointer-Version: " << account << std::endl;

    // Setzen Sie den Wert wieder auf 100

    // Rufen Sie hier Ihre Referenz-Version auf

    std::cout << "Nach Referenz-Version: " << account << std::endl;

    return 0;
}
```

## Anforderungen

### 1. Pointer-Version

Schreiben Sie eine Funktion, die

* einen Pointer auf den Kontostand erhält
* einen Bonus erhält
* den Kontostand um den Bonus erhöht

### 2. Sichere Pointer-Version

Schreiben Sie eine zweite Funktion, die

* ebenfalls einen Pointer auf den Kontostand erhält
* zusätzlich prüft, ob der Pointer gültig ist
* nur dann den Wert verändert

### 3. Referenz-Version

Schreiben Sie eine dritte Funktion, die

* statt eines Pointers eine Referenz verwendet
* den Kontostand ebenfalls um den Bonus erhöht

## Arbeitsaufträge

1. Implementieren Sie die drei Funktionen.
2. Testen Sie alle drei Varianten in `main()`.
3. Ergänzen Sie zusätzlich einen Test, bei dem an die sichere Pointer-Version `nullptr` übergeben wird.

## Fragen

1. Warum braucht die Pointer-Version unter Umständen eine Prüfung?
2. Warum braucht die Referenz-Version keinen `nullptr`-Check?
3. Was ist beim Funktionsaufruf der Unterschied zwischen Pointer und Referenz?
4. Wann würden Sie Pointer trotzdem bewusst verwenden?


So ist es offener: Die Teilnehmer müssen die Funktionssignaturen selbst hinschreiben und nicht nur vorhandene Bodies ausfüllen.
```
