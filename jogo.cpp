#include <algorithm>
#include <iostream>

#include "Jogo.h"
#include "Deck.h"
#include "Jogador.h"

Jogo::Jogo(int qtd_jogadores) {
    _qtd_jogadores = qtd_jogadores;
}

void Jogo::print_pilha() {
    std::cout << "Última carta jogada:" << std::endl;

    std::cout << pilha_cartas.back().get_numero() << ' ' << pilha_cartas.back().get_cor() << std::endl << std::endl;
}

/*
 * Configura o jogo criando o deck e embaralhando-o, criando os jogadores e comprando as cartas iniciais para cada um.
 */
void Jogo::configura_jogo() {
    _deck.fill_deck();
    _deck.shuffle_deck();

    Jogador jogador = Jogador();
    jogadores.emplace_back(jogador);

    jogadores[0].draw_card(_deck.deck, 8);

    _jogo = true;
}

void Jogo::acao_jogador(Jogador &jogador) {
    int index;

    system("clear");

    print_pilha();
    jogador.print_cartas();

    std::cout << "É o seu turno, qual carta deseja jogar? (Informe o índice da carta)" << std::endl;
    std::cin >> index;

    if (index > 0) {
        Jogador::play_card(jogador.cartas, pilha_cartas, index);
    } else {
        jogador.draw_card(_deck.deck, 1);
    }
}

bool Jogo::get_jogo() const {
    return this->_jogo;
}
