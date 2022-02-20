#include <vector>
#include <algorithm>
#include <iostream>

#include "Jogador.h"
#include "Carta.h"

void Jogador::draw_card(std::vector<Carta> &deck, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        cartas.push_back(deck.back());
        deck.pop_back();
    }
}

void Jogador::print_cartas() {
    std::for_each(cartas.begin(), cartas.end(), [](const Carta& n) { std::cout << n.get_number() << ' ' << n.get_color() << ' ';});
    std::cout << std::endl;
}

void Jogador::play_card(std::vector<Carta> &cartas_jogador, std::vector<Carta> &pilha_cartas, int index) {
    index--;

    if (cartas_jogador[index].get_color() == pilha_cartas.back().get_color() or
        cartas_jogador[index].get_number() == pilha_cartas.back().get_number()) {

        pilha_cartas.push_back(cartas_jogador[index]);
        cartas_jogador.erase(cartas_jogador.begin() + index);

    } else {
        std::cout << "Carta não é válida para jogar" << std::endl;
    }
}

Jogador::Jogador() = default;

