#include <vector>
#include <algorithm>
#include <iostream>

#include "Jogador.h"
#include "Carta.h"

void Jogador::draw_card(std::vector<Carta> &deck, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        _cartas.push_back(deck.back());
        deck.pop_back();
    }
}

void Jogador::print_cartas() {
    std::for_each(_cartas.begin(), _cartas.end(), [](const Carta& n) { std::cout << n.get_number() << ' ' << n.get_color() << ' ';});
    std::cout << std::endl;
}

Jogador::Jogador() = default;

