#include <iostream>
#include "Tauler.h"

void cambiarValor(int* a);

int main() {
    Tauler tauler;
    tauler.imprimir();
    //tauler.toggleBombeta(2, 2);
    tauler.selecBombeta(3, 3);
    tauler.imprimir();

    return 0;
}

void cambiarValor(int* a) {
    *a = 324;
}