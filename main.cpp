#include <iostream>
#include "Tauler.h"
#include <fcntl.h>
#include <io.h>

void cambiarValor(int* a);

bool isNumber(char *str);

int main() {
    // Cambiem el codificador del text de la consola a UTF-16 per poder mostrar
    // caracters unicode y poder fer el joc millor esteticament
    _setmode(_fileno(stdout), _O_U16TEXT);

    Tauler tauler;

    for(int i = 0; i < 5; i++) {
        tauler.imprimir();
        int x_str;
        int y_str;
        bool b = std::isdigit(x_str);
        printf("%c%d", x_str,b);
        wprintf(L"Coordenada X: ");
        std::cin >> x_str;
        wprintf(L"Coordenada Y: ");
        std::cin >> y_str;
        tauler.selecBombeta(x_str, y_str);
    }

    return 0;
}