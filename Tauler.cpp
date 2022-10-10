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
    // Decoració
    std::cout << "+";
    for(int x = 0; x < this->w*2; x++) {
        std::cout << "=";
    }
    std::cout << "+" << std::endl;

    // Codi per imprimir el tauler
    for(int y = 0; y < this->h; y++) {
        std::cout << "|";
        for(int x = 0; x < this->w; x++) {
            std::cout << (this->getBombeta(x, y)->isActive() ? "O" : "-");
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }

    // Decoració
    std::cout << "+";
    for(int x = 0; x < this->w*2; x++) {
        std::cout << "=";
    }
    std::cout << "+" << std::endl;
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
