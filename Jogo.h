#ifndef INC_20212_TEAM_7_JOGO_H
#define INC_20212_TEAM_7_JOGO_H

#include <vector>

#include "Especial.h"
#include "Jogador.h"
#include "Computador.h"
#include "Deck.h"

class Jogo {
private:
    bool _jogo = false;
    int _qtd_total;
    int _qtd_jogadores;
    int _qtd_computadores;
    Deck _deck = Deck();

public:
    explicit Jogo(int qtd_total, int qtd_jogadores, int qtd_computadores);
    std::vector<Especial> pilha_cartas {Especial("AMARELO", 9, "")};
    std::vector<Jogador> jogadores;
    std::vector<Computador> computadores;

    void print_pilha();
    void configura_jogo();
    void acao_jogador(Jogador &jogador);
    void acao_computador(Computador &computador);
    std::vector<int> indexes_validos(Computador &computador);
    bool get_jogo() const;
    bool checa_cartas_validas(Jogador &jogador);
    static void validacao_input(const std::string& mensagem, int& input);
    static int inteiro_aleatorio(int min, int max);
    static void out_colorido(const std::string& carta, const std::string& cor);
};

#endif
