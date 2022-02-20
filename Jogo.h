#ifndef INC_20212_TEAM_7_JOGO_H
#define INC_20212_TEAM_7_JOGO_H

#include <vector>

#include "Carta.h"

class Jogo {
private:
    bool jogo = false;
    int jogadores;

public:
    std::vector<Carta> pilha_cartas {Carta("AMARELO", 9)};
    void print_pilha();
};

#endif
