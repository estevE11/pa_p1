//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#include "Tauler.h"
#include <iostream>

Tauler::Tauler() {
    for(int i = 0; i < this->w*this->h; i++) {
        this->bombetes[i] = *new Bombeta(false);
    }
}

void Tauler::imprimir() {
    /*

     * Utilitzem "wprintf" per poder imprimir en codificacio UTF-8.
     * La "L" devant de l'string significa que utilitza "chars" mes grans, es a dir en comptes d'utilitzar 8bits per caracter utilitza 16bits.
     * Aixi es poden representar tots els caracters de UTF-8.
     * L'inconvenient es que el nostre programa ocupara mes memoria

    */
    wprintf(L"  ");

    // filera de numeros
    for(int x = 0; x < this->w*2; x++) {
        if(x%2==0)
            wprintf(L" %d", x/2);
    }
    wprintf(L"\n");

    // Decoració
    wprintf(L"  ╔");
    for(int x = 0; x < this->w*2+1; x++) {
        wprintf(L"═");
    }
    wprintf(L"╗\n");

    // Codi per imprimir el tauler
    for(int y = 0; y < this->h; y++) {
        wprintf(L"%d ║ ", y);
        for(int x = 0; x < this->w; x++) {
            wprintf((this->getBombeta(x, y)->isActive() ? L"■" : L"-"));
            wprintf(L" ");
        }
        wprintf(L"║\n");
    }

    // Decoració
    wprintf(L"  ╚");
    for(int x = 0; x < this->w*2+1; x++) {
        wprintf(L"═");
    }
    wprintf(L"╝\n");
}

Bombeta* Tauler::getBombeta(int x, int y) {
    return &this->bombetes[x + y * this->w];
}

void Tauler::setBombeta(int x, int y, bool val) {
    this->getBombeta(x, y)->setActive(val);
}

void Tauler::toggleBombeta(int x, int y) {
    if(x < this->w && x >= 0 && y < this->h && y >= 0)
        this->getBombeta(x, y)->toggle();
}

void Tauler::selecBombeta(int x, int y) {
    this->toggleBombeta(x, y);
    for(int i = 0; i < sizeof(this->moviments_x)/sizeof(int); i++) {
        if(this->moviments_x[i] != 0)
            this->toggleBombeta(x+this->moviments_x[i], y+this->moviments_y[i]);
    }
}
