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

    //TODO: pedir cuantas bombillas quiere que esten encendidas al principio
    //TODO: encender X numero de bombillas con posicion aleatoria
    //TODO: perdir el maximo numero de tiradas

    for(int i = 0; i < 5; i++) {
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