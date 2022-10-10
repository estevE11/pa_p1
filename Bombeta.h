//
// Created by Roger Esteve Sanchez on 6/10/22.
//

#ifndef PROG_PRACTICA1_BOMBETA_H
#define PROG_PRACTICA1_BOMBETA_H


class Bombeta {
private:
    int active;
public:
    Bombeta();
    Bombeta(bool active);
    bool isActive();
    void setActive(bool active);
    void toggle();
};


#endif //PROG_PRACTICA1_BOMBETA_H
