//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#include "Bombeta.h"

Bombeta::Bombeta() {
    this->active = false;
}

Bombeta::Bombeta(bool active) {
    this->active = active;
}

bool Bombeta::isActive() {
    return this->active;
}

void Bombeta::setActive(bool active) {
    this->active = active;
}

void Bombeta::toggle() {
    this->active = !this->active;
}
