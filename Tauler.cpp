//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#include "Tauler.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
int random(int min, int max);

Tauler::Tauler() {
    for(int i = 0; i < this->columnes; i++) {
        for (int j = 0; j < this->files; ++j) {
            this->contenidor[i][j] = *new Bombeta(false);
        }
    }
}

void Tauler::visualitzar() {
    /*

     * Utilitzem "wprintf" per poder visualitzar en codificacio UTF-8.
     * La "L" devant de l'string significa que utilitza "chars" mes grans, es a dir en comptes d'utilitzar 8bits per caracter utilitza 16bits.
     * Aixi es poden representar tots els caracters de UTF-8.
     * L'inconvenient es que el nostre programa ocupara mes memoria

    */
    wprintf(L"  ");

    // filera de numeros
    for(int x = 0; x < this->columnes * 2; x++) {
        if(x%2==0)
            wprintf(L" %d", x/2);
    }
    wprintf(L"\n");

    // Decoració
    wprintf(L"  ╔");
    for(int x = 0; x < this->columnes * 2 + 1; x++) {
        wprintf(L"═");
    }
    wprintf(L"╗\n");

    // Codi per visualitzar el tauler
    for(int y = 0; y < this->files; y++) {
        wprintf(L"%d ║ ", y);
        for(int x = 0; x < this->columnes; x++) {
            wprintf((this->getBombeta(x, y)->isActive() ? L"■" : L"-"));
            wprintf(L" ");
        }
        wprintf(L"║\n");
    }

    // Decoració
    wprintf(L"  ╚");
    for(int x = 0; x < this->columnes * 2 + 1; x++) {
        wprintf(L"═");
    }
    wprintf(L"╝\n");
}

Bombeta* Tauler::getBombeta(int x, int y) {
    return &this->contenidor[x][y];
}

void Tauler::setBombeta(int x, int y, bool val) {
    this->getBombeta(x, y)->setActive(val);
}

void Tauler::toggleBombeta(int x, int y) {
    if(x < this->columnes && x >= 0 && y < this->files && y >= 0)
        this->getBombeta(x, y)->toggle();
}

void Tauler::premerBombeta(int x, int y) {
    this->toggleBombeta(x, y);
    for(int i = 0; i < sizeof(this->moviments_x)/sizeof(int); i++) {
        if(this->moviments_x[i] != 0)
            this->toggleBombeta(x+this->moviments_x[i], y+this->moviments_y[i]);
    }
}
void Tauler::encendre(int numBombetes) {
    int numx;
    int numy;
    int lim_inf = 0;
    int lim_sup = 7;

    for (int i = 0; i < numBombetes; ++i) {
        numx = random(lim_inf, lim_sup);
        numy = random(lim_inf, lim_sup);
        while(this->getBombeta(numx,numy)->isActive()) {
            numx = random(lim_inf, lim_sup);
            numy = random(lim_inf, lim_sup);
        }
        this->setBombeta(numx,numy, true);
    }
}

int random(int min, int max) {
    return rand() % (max + min + 1);
}

void Tauler::apagar() {
    for(int i = 0; i < this->columnes; i++) {
        for (int j = 0; j < this->files; ++j) {
            this->getBombeta(i,j)->setActive(false);
        }
    }
}

int Tauler::getBombetesEnceses() {
    int count = 0;
    for(int i = 0; i < this->columnes; i++) {
        for (int j = 0; j < this->files; ++j) {
            if(this->getBombeta(i, j)->isActive()) count++;
        }
    }
    this->enceses = count;
    return count;
}