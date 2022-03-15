#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "Jogo.h"
#include "Jogador.h"
#include "Especial.h"

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

    for (int i = 0; i < _qtd_jogadores; i++) {
        Jogador jogador = Jogador();
        jogadores.emplace_back(jogador);
        jogadores[i].draw_card(_deck.deck, 8);
    }

    _jogo = true;
}

void Jogo::acao_jogador(Jogador &jogador) {
    int index;
    std::string passar;

    system("clear");

    print_pilha();
    jogador.print_cartas();

    bool cartas_validas = checa_cartas_validas(jogador);

    if (cartas_validas) {
        std::cout << "É o seu turno, qual carta deseja jogar? (Informe o índice da carta)" << std::endl;
        std::cin >> index;

        if (index > 0) {
            Jogador::play_card(jogador.cartas, pilha_cartas, index);
        }
    } else {
        std::cout << "Não há cartas válidas para você jogar, digite qualquer coisa para comprar uma carta e passar o turno." << std::endl;
        std::cin >> passar;
        jogador.draw_card(_deck.deck, 1);
    }
}

bool Jogo::get_jogo() const {
    return this->_jogo;
}

bool Jogo::checa_cartas_validas(Jogador &jogador) {
    std::vector<Especial> cartas_jogador = jogador.cartas;
    bool carta_valida = false;

    for_each(cartas_jogador.begin(), cartas_jogador.end(), [this, &carta_valida](const Especial &n) {
        if (n.get_cor() == pilha_cartas.back().get_cor() or
            n.get_numero() == pilha_cartas.back().get_numero()) {

            carta_valida = true;
        }
    });

    return carta_valida;
}
