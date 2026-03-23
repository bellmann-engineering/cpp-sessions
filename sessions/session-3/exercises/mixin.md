## Übung: Mixin für Feature-Kombinationen

## 📦 Ausgangssituation

Gegeben ist eine einfache Klasse:

```cpp
class Task {
public:
    void execute() {
        std::cout << "Task running..." << std::endl;
    }
};
```

---

## 🔧 Aufgabe 1: Logging-Mixin

Erstellen Sie ein Mixin `LoggingMixin<T>`:

* erbt von `T`
* überschreibt `execute()`
* gibt vorher und nachher Logs aus:

  * `[LOG] start`
  * `[LOG] end`

---

## 🔧 Aufgabe 2: Timing-Mixin

Erstellen Sie ein weiteres Mixin `TimingMixin<T>`:

* misst die Laufzeit von `execute()`
* gibt die Dauer in Millisekunden aus:

  * `[TIME] 12 ms`

---

## 🔧 Aufgabe 3: Kombination

Kombinieren Sie beide Mixins:

```cpp
LoggingMixin<TimingMixin<Task>> t;
t.execute();
```

---

## 📌 Erwartetes Verhalten (Reihenfolge beachten!)

```text
[LOG] start
Task running...
[TIME] X ms
[LOG] end
```


