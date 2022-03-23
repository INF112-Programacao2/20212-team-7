#include <iostream>
#include <stdexcept>
#include <limits>

#include "Jogo.h"

int main() {
    int qtd_jogadores = 0;

    while (qtd_jogadores < 2 or qtd_jogadores > 4) {
        Jogo::validacao_input("Quantos jogadores vão participar da partida? (2-4)", qtd_jogadores);
    }

    Jogo jogo = Jogo(qtd_jogadores);

    jogo.configura_jogo();

    while (jogo.get_jogo()) {
        for (int i = 0; i < qtd_jogadores; i++) {
            jogo.acao_jogador(jogo.jogadores[i]);
        }
    }

    return 0;
}

