#ifndef INC_20212_TEAM_7_COMPUTADOR_H
#define INC_20212_TEAM_7_COMPUTADOR_H

#include "Jogador.h"

class Computador : public Jogador {
public:
    Computador(int i, std::string basicString);

    void play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index) override;
};

#endif
