// Build: g++ -std=c++20 06_concepts_intro.cpp

#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>

// Concept für integrale Typen
template<typename T>
concept Integral = std::is_integral_v<T>;

// Concept für einen Sensor mit read()-Methode
template<typename T>
concept Sensor = requires(T s) {
    { s.read() } -> std::same_as<int>;
};

// Nur für integrale Typen
Integral auto max(Integral auto a, Integral auto b) {
    return (a > b) ? a : b;
}

// Ein einfacher Sensor
struct TempSensor {
    int read() { return 22; }
};

// Ein Nicht-Sensor
struct NotSensor {};

void processSensor(Sensor auto& s) {
    std::cout << "Sensorwert: " << s.read() << "\n";
}

int main() {
    std::cout << max(10, 20) << "\n";
    // std::cout << max(3.14, 2.71); // Fehler: double nicht integral

    TempSensor ts;
    processSensor(ts);
    // NotSensor ns; processSensor(ns); // Fehler: NotSensor erfüllt Sensor nicht
    return 0;
}
