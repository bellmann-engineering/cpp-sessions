#include <iostream>
#include <compare>

class Version {
public:
    int major, minor, patch;

    Version(int ma, int mi, int pa) : major(ma), minor(mi), patch(pa) {}

    auto operator<=>(const Version& other) const = default;
};

int main() {
    Version v1{1,2,0};
    Version v2{1,3,0};
    Version v3{1,2,3};

    std::cout << std::boolalpha;
    std::cout << "v1 < v2 : " << (v1 < v2) << '\n';
    std::cout << "v1 == v3: " << (v1 == v3) << '\n';
    std::cout << "v1 <= v3: " << (v1 <= v3) << '\n';
    std::cout << "v2 > v3 : " << (v2 > v3) << '\n';

    return 0;
}
