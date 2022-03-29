#include <string>
#include <utility>

#include "Carta.h"
#include "Especial.h"

Especial::Especial(std::string color, int number, std::string acao_especial = ""):
    Carta(std::move(color), number), _acao_especial(std::move(acao_especial)) {}

std::string Especial::get_acao_especial() {
    return this->_acao_especial;
}

bool Especial::get_acao_realizada() const {
    return this->_acao_realizada;
}

void Especial::set_acao_realizada(bool acao_realizada) {
    _acao_realizada = acao_realizada;
}
