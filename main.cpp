#include <iostream>
#include "Tauler.h"
#include <fcntl.h>
#include <io.h>
#include <time.h>
#include <stdlib.h>

void cambiarValor(int* a);

bool isNumber(char *str);

int main() {
    // Cambiem el codificador del text de la consola a UTF-16 per poder mostrar
    // caracters unicode y poder fer el joc millor esteticament
    _setmode(_fileno(stdout), _O_U16TEXT);

    int numbom;
    srand(time(NULL));
    int numx;
    int numy;
    int lim_inf = 0;
    int lim_sup = 7;
    int numtir;
    Tauler tauler;

    //TODO: pedir cuantas bombillas quiere que esten encendidas al principio [1, 64]
    wprintf(L"Cuantas bombillas desea que esten encendidas?");
    std::cin >> numbom;
    //TODO: encender X numero de bombillas con posicion aleatoria
    for (int i = 0; i < numbom; ++i) {
        numx = lim_inf + rand() % (lim_sup+1 - lim_inf);
        numy = lim_inf + rand() % (lim_sup+1 - lim_inf);
        tauler.toggleBombeta(numx,numy);
    }
    //TODO: perdir el maximo numero de tiradas
    wprintf(L"Numero de tiradas?");
    std::cin >> numtir;
    for(int i = 0; i < numtir; i++) {
        tauler.imprimir();
        int x_str;
        int y_str;
        wprintf(L"Coordenada X: ");
        std::cin >> x_str;
        wprintf(L"Coordenada Y: ");
        std::cin >> y_str;
        //TODO: comprobar que las coordenadas estan entre [0, 7]
        tauler.selecBombeta(x_str, y_str);
    }

    //TODO: una vez acabada la partida informar de cuantas bombillas estaban encendida i apagadas despues de cada tirada
    //TODO: preguntar si quiere jugar otra vez
    // SI> Vuelves al principio, pides toda la informacion
    // NO> Cierras el programa

    return 0;
}