#include <iostream>

// C-artiger enum (implizite Konvertierungen, Namenskonflikte)
enum Color { RED, GREEN, BLUE };
enum TrafficLight { RED, YELLOW, GREEN };  // Fehler: RED, GREEN doppelt!

// C++11 enum class
enum class State : uint8_t { IDLE, RUNNING, ERROR };
enum class ErrorCode : uint8_t { NONE, TIMEOUT, OVERFLOW };

void printState(State s) {
    switch (s) {
        case State::IDLE: std::cout << "Idle\n"; break;
        case State::RUNNING: std::cout << "Running\n"; break;
        case State::ERROR: std::cout << "Error\n"; break;
    }
}

int main() {
    // Color col = 2;         // C-enum: erlaubt, aber unsicher
    // State s = 1;           // enum class: Fehler! (keine implizite Konvertierung)
    State s = State::RUNNING;
    printState(s);
    // if (s == ErrorCode::NONE) {} // Fehler: verschiedene Typen
    return 0;
}
