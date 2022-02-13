#include "Carta.h"

Carta::Carta(int color, int number) {
    _color = color;
    _number = number;
}

int Carta::get_color() const {
    return this->_color;
}

int Carta::get_number() const {
    return this->_number;
}

