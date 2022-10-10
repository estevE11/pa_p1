#include <iostream>
#include "Tauler.h"
#include <fcntl.h>
#include <io.h>

void cambiarValor(int* a);

int main() {
    // Cambiem el codificador del text de la consola a UTF-16 per poder mostrar
    // caracters unicode y poder fer el joc millor esteticament
    _setmode(_fileno(stdout), _O_U16TEXT);

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