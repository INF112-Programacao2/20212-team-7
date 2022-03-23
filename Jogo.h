#ifndef INC_20212_TEAM_7_JOGO_H
#define INC_20212_TEAM_7_JOGO_H

#include <vector>

#include "Especial.h"
#include "Jogador.h"
#include "Deck.h"

class Jogo {
private:
    bool _jogo = false;
    int _qtd_jogadores;
    Deck _deck = Deck();

public:
    explicit Jogo(int qtd_jogadores);
    std::vector<Especial> pilha_cartas {Especial("AMARELO", 9, "")};
    std::vector<Jogador> jogadores;

    void print_pilha();
    void configura_jogo();
    void acao_jogador(Jogador &jogador);
    bool get_jogo() const;
    bool checa_cartas_validas(Jogador &jogador);
    static void validacao_input(const std::string& mensagem, int& input);
};

#endif
