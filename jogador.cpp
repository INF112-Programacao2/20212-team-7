#include <vector>
#include <algorithm>
#include <iostream>

#include "Jogador.h"
#include "Especial.h"

void Jogador::draw_card(std::vector<Especial> &deck, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        cartas.push_back(deck.back());
        deck.pop_back();
    }
}

void Jogador::print_cartas() {
    std::cout << "Suas cartas:" << std::endl;

    std::for_each(cartas.begin(), cartas.end(), [](const Especial& n) { std::cout << n.get_numero() << ' ' << n.get_cor() << " | ";});
    std::cout << std::endl << std::endl;
}

/*
 * Verifica se a carta escolhida pelo jogador com índice começando pelo 1 é da mesma cor ou mesmo número.
 * Caso seja, retira a carta do vetor com as cartas do jogador e joga na pilha de cartas.
 */
void Jogador::play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index) {
    bool carta_valida = false;
    index--;

    std::cout << cartas_jogador.size();
    while (!carta_valida) {
        if (cartas_jogador.size() > index) {
            if (cartas_jogador[index].get_cor() == pilha_cartas.back().get_cor() or
                cartas_jogador[index].get_numero() == pilha_cartas.back().get_numero()) {

                pilha_cartas.push_back(cartas_jogador[index]);
                cartas_jogador.erase(cartas_jogador.begin() + index);

                carta_valida = true;
            } else {
                std::cout << cartas_jogador[index].get_numero() << ' ' << cartas_jogador[index].get_cor() << " não é uma carta válida para jogar." << std::endl << std::endl;

                std::cout << "Selecione outra carta ou compre uma carta do deck." << std::endl;
                std::cin >> index;
                index--;
            }
        } else {
            std::cout << "Carta escolhida não existe, tente outro índice" << std::endl;
            std::cin >> index;
            index--;
        }
    }
}

Jogador::Jogador() = default;

