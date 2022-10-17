//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#ifndef PROG_PRACTICA1_TAULER_H
#define PROG_PRACTICA1_TAULER_H


#include "Bombeta.h"

class Tauler {
private:
    int columnes = 8;
    int files = 8;
    // TODO: Cambiar de array de 1D a array de 2D (contenidor[8][8])
    Bombeta contenidor[8][8];
    int moviments_x[8] = {2, 1, -2, -1, 2, -2, 1, -1};
    int moviments_y[8] = {1, 2, 1, 2, -1, -1, -2, -2};
    // TODO: Contador de cuantas bombillas hay encendidas, cada vez q se modifica una se tiene q actualizar
    int enceses;
public:
    Tauler();
    void visualitzar();
    Bombeta* getBombeta(int x, int y);
    void setBombeta(int x, int y, bool val);
    void toggleBombeta(int x, int y);
    void premerBombeta(int x, int y);
    // Metodo para encender n bombetas aleatoriamente (lo q hay en main, se tiene q hacer en un metodo)
    void encendre(int numBombetes);
    // Metodo para apagar todas las bombillas
    void apagar();
    // Metodo para contar cuantas bombillas hay encendidas
    int getBombetesEnceses();

    // Ningun metodo aqui puede tener "std::cin"
};


#endif //PROG_PRACTICA1_TAULER_H
