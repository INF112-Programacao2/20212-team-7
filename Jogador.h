#ifndef INC_20212_TEAM_7_JOGADOR_H
#define INC_20212_TEAM_7_JOGADOR_H

#include <vector>

#include "Carta.h"

class Jogador {
private:
    bool _jogando = true;
    std::vector<Carta> _cartas {};

public:
    explicit Jogador();
    void draw_card(std::vector<Carta> &deck, int quantidade);
    void print_cartas();
};

#endif
