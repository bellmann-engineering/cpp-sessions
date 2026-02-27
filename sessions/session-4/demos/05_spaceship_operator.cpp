#include <iostream>
#include <compare>

// in g++ mit -std=c++20 flag komplieren

struct Point {
    int x, y;
    // Automatische Generierung aller Vergleichsoperatoren
    auto operator<=>(const Point&) const = default;
};

struct CaseInsensitiveString {
    std::string s;

    std::weak_ordering operator<=>(const CaseInsensitiveString& other) const {
        // Einfache Groß-/Kleinschreibung ignorieren (nur Beispiel)
        std::string lower1, lower2;
        for (char ch : s) lower1 += std::tolower(ch);
        for (char ch : other.s) lower2 += std::tolower(ch);
        if (lower1 < lower2) return std::weak_ordering::less;
        if (lower1 > lower2) return std::weak_ordering::greater;
        return std::weak_ordering::equivalent;
    }

    bool operator==(const CaseInsensitiveString& other) const {
        return (*this <=> other) == 0;
    }
};

int main() {
    Point p1{1,2}, p2{1,3};
    std::cout << std::boolalpha;
    std::cout << "p1 < p2 : " << (p1 < p2) << '\n';
    std::cout << "p1 == p1: " << (p1 == p1) << '\n';
    std::cout << "p1 != p2: " << (p1 != p2) << '\n';

    CaseInsensitiveString cis1{"Hello"}, cis2{"hello"};
    std::cout << "cis1 == cis2: " << (cis1 == cis2) << '\n';
    std::cout << "cis1 < cis2 : " << (cis1 < cis2) << '\n';

    return 0;
}
