# 🧩 Übung: Ressourcenverwaltung in einem Monitoring-System

Sie entwickeln ein kleines System zur Verwaltung von Geräten (z. B. Sensoren).
Die Objekte sollen **exklusive Ownership** besitzen und sauber verwaltet werden.

---

## 🔧 Gegeben

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Sensor {
public:
    Sensor(std::string name) : name_(name) {
        std::cout << "Sensor " << name_ << " erstellt\n";
    }

    ~Sensor() {
        std::cout << "Sensor " << name_ << " zerstört\n";
    }

    void read() const {
        std::cout << "Lese Daten von " << name_ << "\n";
    }

private:
    std::string name_;
};
```

---

## 📌 Aufgabenstellung

### 1. Device-Klasse mit exklusiver Ownership

Erstellen Sie eine Klasse `Device`, die genau **einen Sensor besitzt**.

**Anforderungen:**

* Verwendung von `std::unique_ptr<Sensor>`
* Konstruktor übernimmt Ownership eines Sensors
* Methode `readSensor()`, die den Sensor nutzt

---

### 2. Factory-Funktion

Implementieren Sie eine Funktion:

```cpp
std::unique_ptr<Sensor> createSensor(const std::string& name);
```

**Ziel:**

* Erzeugung über `std::make_unique`
* Kein direktes `new`

---

### 3. Übergabe von Ownership

Erstellen Sie ein `Device`-Objekt mit einem Sensor aus der Factory.

**Wichtig:**

* Ownership muss korrekt per `std::move` übergeben werden
* Nach der Übergabe darf der ursprüngliche Pointer nicht mehr verwendet werden

---

### 4. Verwaltung mehrerer Devices

Erstellen Sie einen `std::vector<std::unique_ptr<Device>>`.

**Anforderungen:**

* Mehrere Devices hinzufügen
* Jedes Device besitzt seinen eigenen Sensor
* Alle Sensoren auslesen (Iteration)

---

### 5. Transfer zwischen Containern

Verschieben Sie ein `Device` von einem Vektor in einen anderen.

**Ziel:**

* Kein Kopieren
* Verwendung von `std::move`

---

### 6. Fehleranalyse

Erklären Sie, warum folgender Code nicht funktioniert:

```cpp
std::unique_ptr<Sensor> s1 = createSensor("Temp");
std::unique_ptr<Sensor> s2 = s1;
```

Und korrigieren Sie ihn.

---

## 🎯 Bonus (für Fortgeschrittene)

Erweitern Sie das System:

### A) Optionaler Sensor

Ein `Device` kann auch **keinen Sensor** haben.

* Wie prüfen Sie das sauber?
* Wie vermeiden Sie Abstürze?

---

### B) Austausch eines Sensors

Fügen Sie eine Methode hinzu:

```cpp
void replaceSensor(std::unique_ptr<Sensor> newSensor);
```

**Ziel:**

* Alter Sensor wird automatisch freigegeben
* Ownership wird korrekt übernommen


