#include <iostream>
#include <algorithm>
#include <random>

#include "Deck.h"
#include "Carta.h"

void Deck::fill_deck() {
    for (int i = 0; i <= 9; i++) {
        deck.emplace_back(Carta("AMARELO", i));
        deck.emplace_back(Carta("VERMELHO", i));
        deck.emplace_back(Carta("VERDE", i));
        deck.emplace_back(Carta("AZUL", i));
    }
}

void Deck::print_deck() {
    std::for_each(deck.begin(), deck.end(), [](const Carta& n) { std::cout << n.get_numero() << ' ' << n.get_cor() << ' ';});
}

void Deck::shuffle_deck() {
    std::random_device random;
    std::mt19937 gen{random()};

    std::shuffle(deck.begin(), deck.end(), gen);
}

unsigned long Deck::get_deck_size() const {
    return deck.size();
}