# Übung: C-Code analysieren und Probleme identifizieren

**Ziel:** In realistischeren C-Codeausschnitten mögliche Fehlerquellen und Wartbarkeitsprobleme erkennen und überlegen, wie moderne C++-Konzepte diese vermeiden können.

---

## Aufgabe

Analyiseren Sie die folgenden Codebeispiele.

1. Beschreiben Sie, welche möglichen Probleme Sie erkennen.
2. Erklären Sie, unter welchen Umständen diese Probleme auftreten können.
3. Überlegen Sie, welche Sprachmittel oder Konzepte aus modernem C++ helfen würden.

---

## Beispiel 1

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* build_message(const char* user)
{
    char* buffer = malloc(128);

    strcpy(buffer, "Hello ");
    strcat(buffer, user);

    return buffer;
}

int main()
{
    char* msg = build_message("Alice");

    printf("%s\n", msg);

    return 0;
}
````

---

## Beispiel 2

```c
#include <stdio.h>

typedef struct
{
    int id;
    char name[32];
} User;

User* find_user(User* users, int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (users[i].id == id)
            return &users[i];
    }

    return NULL;
}

int main()
{
    User users[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Carol"}
    };

    User* u = find_user(users, 3, 2);

    if (u)
        printf("%s\n", u->name);
}
```

---

## Beispiel 3

```c
#include <stdio.h>

int read_config_value()
{
    FILE* f = fopen("config.txt", "r");

    int value = 0;

    if (f)
        fscanf(f, "%d", &value);

    return value;
}
```

---

## Beispiel 4

```c
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

void append(Node* head, int v)
{
    Node* n = malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;

    while (head->next)
        head = head->next;

    head->next = n;
}
```

---

## Diskussion

* Welche Probleme könnten in diesen Beispielen in größeren Systemen auftreten?
* Welche Änderungen würden Sie vornehmen, um den Code robuster zu machen?
* Welche Konzepte aus modernem C++ würden diese Probleme strukturell vermeiden?
