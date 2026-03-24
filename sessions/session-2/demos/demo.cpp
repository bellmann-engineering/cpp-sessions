int* a;

//a = (int*)malloc(sizeof(int));
a = new int;

*a = 5;

delete a;


auto p1 = std::make_unique<int>(42);
auto p2 = std::move(p1);

if (p1 == nullptr) {
    std::cout << "p1 ist leer\n";
}