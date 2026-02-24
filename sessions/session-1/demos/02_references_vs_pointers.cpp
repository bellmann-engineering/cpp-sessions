#include <iostream>

// Pointer-Version mit möglichem Fehler
void swap_ptr_bad(int* a, int* b) {
    int* temp = a;  // lokale Pointer vertauscht – falsch!
    a = b;
    b = temp;
}

// Korrekte Pointer-Version
void swap_ptr_good(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Referenz-Version (sicher)
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Original: x=" << x << ", y=" << y << std::endl;

    swap_ptr_bad(&x, &y);
    std::cout << "Nach swap_ptr_bad: x=" << x << ", y=" << y << std::endl;

    swap_ptr_good(&x, &y);
    std::cout << "Nach swap_ptr_good: x=" << x << ", y=" << y << std::endl;

    swap_ref(x, y);
    std::cout << "Nach swap_ref: x=" << x << ", y=" << y << std::endl;

    // Umbiegen eines Pointers
    int* ptr = &x;
    std::cout << "ptr zeigt auf x (" << *ptr << ")\n";
    ptr = &y;  // Umbiegen
    std::cout << "ptr zeigt jetzt auf y (" << *ptr << ")\n";
    return 0;
}
