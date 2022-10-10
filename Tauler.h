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
    Bombeta bombetes[8*8];
    int moviments_x[8] = {1, 0, 0, 0, 0, 0, 0, 0};
    int moviments_y[8] = {1, 0, 0, 0, 0, 0, 0, 0};
public:
    Tauler();
    void imprimir();
    Bombeta* getBombeta(int x, int y);
    void setBombeta(int x, int y, bool val);
    void toggleBombeta(int x, int y);
    void selecBombeta(int x, int y);


};


#endif //PROG_PRACTICA1_TAULER_H
