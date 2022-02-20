#include <iostream>

#include "Jogo.h"

using namespace std;

int main() {
    int qtd_jogadores = 1;

    cout << "Quanto jogadores vão participar da partida? (2-4)" << endl;

    Jogo jogo = Jogo(qtd_jogadores);

    jogo.configura_jogo();

    while (jogo.get_jogo()) {
        jogo.acao_jogador(jogo.jogadores[0]);
    }

    return 0;
}

