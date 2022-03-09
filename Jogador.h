#ifndef INC_20212_TEAM_7_JOGADOR_H
#define INC_20212_TEAM_7_JOGADOR_H

#include <vector>

#include "Especial.h"

class Jogador {
private:
    bool _jogando = true;

public:
    std::vector<Especial> cartas {};
    explicit Jogador();
    void draw_card(std::vector<Especial> &deck, int quantidade);
    static void play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index);
    void print_cartas();
};

#endif
