#include <iostream>

#include "Jogo.h"

using namespace std;

int main() {
    int qtd_jogadores;

    cout << "Quanto jogadores vão participar da partida? (2-4)" << endl;
    cin >> qtd_jogadores;
    Jogo jogo = Jogo(qtd_jogadores);

    jogo.configura_jogo();

    while (jogo.get_jogo()) {
        for (int i = 0; i < qtd_jogadores; i++) {
            jogo.acao_jogador(jogo.jogadores[i]);
        }
    }

    return 0;
}

