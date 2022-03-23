#include <iostream>
#include <stdexcept>
#include <limits>

#include "Jogo.h"

int main() {
    int qtd_jogadores;

    /*
     * Uso do while em quanto o "cin" não conseguir ler o input do usuário e que seja entre 2 e 4.
     */
    while (std::cout << "Quantos jogadores vão participar da partida? (2-4)\n" and !(std::cin >> qtd_jogadores)
           or qtd_jogadores < 2 or qtd_jogadores > 4) {
        std::cin.clear(); // limpa o input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore o erro para gerar um novo input
        std::cout << "Tente novamente com um valor válido." << std::endl;
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

