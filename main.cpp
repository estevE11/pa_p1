#include <iostream>
#include "Tauler.h"
#include <fcntl.h>
#include <io.h>

static int demanarInt(const std::string&, int min, int max);
static bool tornarJugar(Tauler* tauler);

int main() {
    // Cambiem el codificador del text de la consola a UTF-16 per poder mostrar
    // caracters unicode y poder fer el joc millor esteticament
    // Aixo fara que haguem d'utilitzar obligatoriament "wprintf" per visualitzar
    // ja que ni el "std::cout" ni el "printf" funcionaran
    _setmode(_fileno(stdout), _O_U16TEXT);

    Tauler tauler;
    bool jugar = true;

    while(jugar) {
        // Demanar cuantes contenidor vol l'usuari que estiguin enceses al principi [1, 64]
        int numbom = demanarInt("Quantes contenidor vols que estigun enceses?", 1, 64);

        // Encendre N numero de contenidor aleatoriament posicionades
        tauler.encendre(numbom);

        // Demanar el nombre de tirades
        // Hem decidit posar 500 per tenir un límit
        int numtir = demanarInt("Numero de tirades?", 1, 500);

        // Crear un array amb mida (n = numero de tirades)
        int* historial_tirades = new int[numtir];

        for (int i = 0; i < numtir; i++) {
            tauler.visualitzar();
            int x;
            int y;
            // Demanar les coordenades X i Y
            x = demanarInt("Coordenada X?", 0, 7);
            y = demanarInt("Coordenada Y?", 0, 7);

            tauler.premerBombeta(x, y);
            historial_tirades[i] = tauler.getBombetesEnceses();
        }
        tauler.visualitzar();
        wprintf(L"Ja no tens mes tirades. El joc ha acabat\n");

        // Un cop acabada la partida imprimim quantes contenidor estaben enceses a cada ronda
        for (int i = 0; i < numtir; i++) {
            wprintf(L"Tirada %d: %d enceses i %d apagades\n", i + 1, historial_tirades[i], 64 - historial_tirades[i]);
        }

        // Deixem lliure la memoria que ocupava l'array d'historial de tirades
        delete[] historial_tirades;

        jugar = tornarJugar(&tauler);
    }

    return 0;
}

static bool tornarJugar(Tauler* tauler) {
    // Preguntar si vol tornar a jugar, si el jugador introdueix n o N acaba.
    wprintf(L"Vols tornar a jugar? (n o N per acabar)\n");
    char respuesta;
    std::cin >> respuesta;
    if(respuesta == 'n' || respuesta == 'N') {
        return false;
    }
    tauler->apagar();
    return true;
}

// Funció que demana un int a l'usuari amb la pregunta que se li passi com a argument
// i que s'encarrega de demanar el valor a l'usuari fins que aquest estigui
// dins dels limits que se li passen per parametre.
static int demanarInt(const std::string& pregunta, int min, int max) {
    wprintf(L"%s: [%d, %d]", pregunta.c_str(), min, max);
    int val;
    std::cin >> val;
    while (val < min || val > max) {
        wprintf(L"El valor ha d'estar entre 0 i 7");
        wprintf(L"%s: [%d, %d]", pregunta.c_str(), min, max);
        std::cin >> val;
    }
    return val;
}
