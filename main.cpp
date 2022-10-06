#include <iostream>

void cambiarValor(int* a);

int main() {
    int a = 10;
    int *b = &a;
    *b = 11;

    cambiarValor(&a);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}

void cambiarValor(int* a) {
    *a = 324;
}