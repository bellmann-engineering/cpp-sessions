# Übung: Zyklische Abhängigkeit erkennen und vermeiden

Modellieren Sie folgende Klassen:

* `ChatRoom` besitzt mehrere `User`
* `User` kennt seinen `ChatRoom`

---

## Teil 1 - Fehler provozieren

Setzen Sie **beide Richtungen mit `std::shared_ptr`** um:

```cpp
class User {
    std::string name_;
    std::shared_ptr<ChatRoom> room_;  // bewusst so
};

class ChatRoom {
    std::string name_;
    std::vector<std::shared_ptr<User>> users_;
};
```

### Aufgabe

* Erzeugen Sie:

  * einen `ChatRoom`
  * zwei `User`
* Verknüpfen Sie beide Richtungen:

  * Raum -> User
  * User -> Raum

### Beobachtung

Fügen Sie Destruktor-Ausgaben ein.

👉 **Frage:**
Warum werden die Objekte am Ende nicht zerstört?

---

## Teil 2 - Korrektur

Ändern Sie nur diese eine Stelle:

```cpp
class User {
    std::string name_;
    std::weak_ptr<ChatRoom> room_;  // statt shared_ptr
};
```
