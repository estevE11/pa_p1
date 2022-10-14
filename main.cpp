#include <iostream>
#include "Tauler.h"
#include <fcntl.h>
#include <io.h>

int main() {
    // Cambiem el codificador del text de la consola a UTF-16 per poder mostrar
    // caracters unicode y poder fer el joc millor esteticament
    // Aixo fara que haguem d'utilitzar obligatoriament "wprintf" per imprimir
    // ja que ni el "std::cout" ni el "printf" funcionaran
    _setmode(_fileno(stdout), _O_U16TEXT);

    int numbom;
    int numtir;
    Tauler tauler;
    bool jugar = true;

    while(jugar) {
        //pedir cuantas bombillas quiere que esten encendidas al principio [1, 64]
        wprintf(L"Cuantas bombillas desea que esten encendidas?");
        std::cin >> numbom;
        //encender X numero de bombillas con posicion aleatoria
        tauler.onRandomBombeta(numbom);
        //perdir el maximo numero de tiradas
        wprintf(L"Numero de tiradas?");
        std::cin >> numtir;
        //Crear array con tamaño n (n = numero de tiradas)
        int* historial_tirades = new int[numtir];

    //TODO: Crear array con tamaño n (n = numero de tiradas)

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
