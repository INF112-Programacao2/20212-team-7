#include <iostream>
#include <stdexcept>
#include <limits>

#include "Jogo.h"

int main() {
    int qtd_total = 0;
    int qtd_jogadores = -1;
    int qtd_computadores;

    while (qtd_total < 2 or qtd_total > 4) {
        Jogo::validacao_input("Quantos jogadores no total vão participar da partida? (2-4)", qtd_total);
    }

    while (qtd_jogadores < 0 or qtd_jogadores > qtd_total) {
        Jogo::validacao_input("Quanto jogadores humanos vão participar da partida?", qtd_jogadores);
    }

    qtd_computadores = qtd_total - qtd_jogadores;

    Jogo jogo = Jogo(qtd_total, qtd_jogadores, qtd_computadores);

    jogo.configura_jogo();

    while (jogo.get_jogo()) {
        for (int i = 0; i < qtd_jogadores; i++) {
            jogo.acao_jogador(jogo.jogadores[i]);
        }
        for (int i = 0; i < qtd_computadores; i++) {
            jogo.acao_computador(jogo.computadores[i]);
        }
    }

    return 0;
}

