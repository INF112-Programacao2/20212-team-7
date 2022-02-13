#include <iostream>
#include <algorithm>

#include "Deck.h"
#include "Carta.h"

void Deck::fill_deck() {
    for (int i = 0; i <= 9; i++) {
        deck.emplace_back(Carta(1, i));
        deck.emplace_back(Carta(2, i));
        deck.emplace_back(Carta(3, i));
        deck.emplace_back(Carta(4, i));
    }
}

void Deck::print_deck() {
    std::for_each(deck.begin(), deck.end(), [](const Carta n) { std::cout << n.get_number() << ' ';});
};