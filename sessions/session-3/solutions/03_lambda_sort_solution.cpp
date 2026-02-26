#include <algorithm>
#include <array>
#include <iostream>

struct SensorData { int id; float value; uint32_t timestamp; };

int main() {
    std::array<SensorData, 5> data = {{
        {3, 2.5f, 1000}, {1, 9.1f, 2000}, {4, 1.2f, 1500},
        {2, 5.5f, 3000}, {5, 3.8f, 2500}
    }};

    std::sort(data.begin(), data.end(),
              [](const SensorData& a, const SensorData& b) {
                  return a.id < b.id;
              });

    std::sort(data.begin(), data.end(),
              [](const SensorData& a, const SensorData& b) {
                  return a.value > b.value;
              });

    std::sort(data.begin(), data.end(),
              [](const SensorData& a, const SensorData& b) {
                  return a.timestamp < b.timestamp;
              });

    for (const auto& d : data) {
        std::cout << d.id << " " << d.value << " " << d.timestamp << std::endl;
    }
    return 0;
}
