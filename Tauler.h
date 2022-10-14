//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#ifndef PROG_PRACTICA1_TAULER_H
#define PROG_PRACTICA1_TAULER_H


#include "Bombeta.h"

class Tauler {
private:
    int w = 8;
    int h = 8;
    // TODO: Cambiar de array de 1D a array de 2D (bombetes[8][8])
    Bombeta bombetes[8][8];
    int moviments_x[8] = {2, 1, -2, -1, 2, -2, 1, -1};
    int moviments_y[8] = {1, 2, 1, 2, -1, -1, -2, -2};
    // TODO: Contador de cuantas bombillas hay encendidas, cada vez q se modifica una se tiene q actualizar
public:
    Tauler();
    void imprimir();
    Bombeta* getBombeta(int x, int y);
    void setBombeta(int x, int y, bool val);
    void toggleBombeta(int x, int y);
    void selecBombeta(int x, int y);
    // TODO: Metodo para encender n bombetas aleatoriamente (lo q hay en main, se tiene q hacer en un metodo)
    void onRandomBombeta(int numBombetes);
    // TODO: Metodo para apagar todas las bombillas
    void offAll();
    // Ningun metodo aqui puede tener "std::cin"

};


#endif //PROG_PRACTICA1_TAULER_H
