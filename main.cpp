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

        for (int i = 0; i < numtir; i++) {
            tauler.imprimir();
            int x;
            int y;
            //Comprobar que las coordenadas estan entre [0, 7]
            wprintf(L"Coordenada X: ");
            std::cin >> x;
            while (x < 0 || x > 7) {
                wprintf(L"Les cordenades han d'estar entre 0 i 7");
                wprintf(L"Coordenada X: ");
                std::cin >> x;
            }
            wprintf(L"Coordenada Y: ");
            std::cin >> y;
            while (y < 0 || y > 7) {
                wprintf(L"Les cordenades han d'estar entre 0 i 7\n");
                wprintf(L"Coordenada Y: ");
                std::cin >> y;
            }
            tauler.selecBombeta(x, y);
            historial_tirades[i] = tauler.getOnBombetes();
        }
        tauler.imprimir();
        wprintf(L"Ja no tens mes tirades. El joc ha acabat\n");
        // Una vez acabada la partida informar de cuantas bombillas estaban encendida i apagadas despues de cada tirada
        for (int i = 0; i < numtir; i++) {
            wprintf(L"Tirada %d: %d enceses i %d apagades\n", i + 1, historial_tirades[i], 64 - historial_tirades[i]);
        }
        delete[] historial_tirades;
        // Preguntar si quiere jugar otra vez
        // SI> Vuelves al principio, pides toda la informacion
        // NO> Cierras el programa
        wprintf(L"Vols tornar a jugar?(n o N per acabar)\n");
        char respuesta;
        std::cin >> respuesta;
        if(respuesta == 'n' || respuesta == 'N') {
            jugar = false;
        }
        tauler.offAll();
    }

    return 0;
}
