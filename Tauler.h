//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#ifndef PROG_PRACTICA1_TAULER_H
#define PROG_PRACTICA1_TAULER_H


#include "Bombeta.h"

class Tauler {
public:
    Tauler();
    void imprimir();

private:
    int w = 8;
    int h = 8;
    Bombeta bombetes[8*8];
    int moviments_x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int moviments_y[8] = {1, 2, 3, 4, 5, 6, 7, 8};

};


#endif //PROG_PRACTICA1_TAULER_H
