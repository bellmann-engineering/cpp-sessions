#include <iostream>
#include <vector>
#include <ranges>

struct SensorReading {
    int id;
    float value;
};

int main() {
    std::vector<SensorReading> data = {
        {1, 3.5f}, {2, -1.0f}, {3, 4.2f}, {4, 2.0f},
        {5, 0.0f}, {6, 5.1f}, {7, -2.0f}, {8, 1.5f},
        {9, 6.0f}, {10, 3.8f}, {11, -0.5f}, {12, 2.9f}
    };

    auto view = data
        | std::views::filter([](const auto& r) { return r.value > 0; })
        | std::views::transform([](const auto& r) { return r.value * 2; })
        | std::views::take(10);

    std::vector<float> result;
    for (auto val : view) {
        result.push_back(val);
    }

    for (float v : result) {
        std::cout << v << " ";
    }
    std::cout << "\n";
    return 0;
}
