#ifndef INC_20212_TEAM_7_JOGADOR_H
#define INC_20212_TEAM_7_JOGADOR_H

#include <vector>

#include "Carta.h"

class Jogador {
private:
    bool _jogando = true;

public:
    std::vector<Carta> cartas {};
    explicit Jogador();
    void draw_card(std::vector<Carta> &deck, int quantidade);
    static void play_card(std::vector<Carta> &cartas_jogador, std::vector<Carta> &pilha_cartas, int index);
    void print_cartas();
};

#endif
