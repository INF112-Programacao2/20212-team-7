#include <string>
#include <utility>

#include "Carta.h"

Carta::Carta(std::string color, int number) {
    _color = std::move(color);
    _number = number;
}

std::string Carta::get_cor() const {
    return this->_color;
}

int Carta::get_numero() const {
    return this->_number;
}

