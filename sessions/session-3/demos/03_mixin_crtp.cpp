#include <iostream>

template <typename Derived>
class SensorBase {
public:
    void read() {
        static_cast<Derived*>(this)->readImpl();
    }
};

class TempSensor : public SensorBase<TempSensor> {
public:
    void readImpl() {
        std::cout << "Temperatur lesen\n";
    }
};

int main() {
    TempSensor ts;
    ts.read();
    return 0;
}
