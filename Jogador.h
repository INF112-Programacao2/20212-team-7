#ifndef INC_20212_TEAM_7_JOGADOR_H
#define INC_20212_TEAM_7_JOGADOR_H

#include <vector>

#include "Especial.h"
#include "Jogador.h"

class Jogador {
private:
    bool _jogando = true;
    std::string _nome;
    int _turno;

public:
    std::vector<Especial> cartas {};
    Jogador(int turno, std::string nome);
    int get_turno() const;
    void set_turno(int turno);
    std::string get_nome();
    void draw_card(std::vector<Especial> &deck, int quantidade);
    static void play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index);
    static void acao_especial(const std::string& nome_acao, Jogador& jogador, std::vector<Especial> &deck, Especial& carta);
    static void curinga(Especial& carta);
    void print_cartas();
};

#endif
