#ifndef INC_20212_TEAM_7_JOGO_H
#define INC_20212_TEAM_7_JOGO_H

#include <vector>

#include "Carta.h"
#include "Jogador.h"
#include "Deck.h"

class Jogo {
private:
    bool _jogo = false;
    int _qtd_jogadores;
    Deck _deck = Deck();

public:
    explicit Jogo(int qtd_jogadores);
    std::vector<Carta> pilha_cartas {Carta("AMARELO", 9)};
    std::vector<Jogador> jogadores;

    void print_pilha();
    void configura_jogo();
    void acao_jogador(Jogador &jogador);
    bool get_jogo() const;
};

#endif
