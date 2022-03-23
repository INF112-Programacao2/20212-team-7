#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "Deck.h"
#include "Especial.h"

void Deck::fill_deck() {
    std::vector<std::string> acoes {"BLOQUEIO", "REVERTE", "+2"};

    for (int j = 0; j < 2; j++) {
        int i_especiais = 10;
        for (int i = 0; i <= 9; i++) {
            deck.emplace_back(Especial("AMARELO", i, ""));
            deck.emplace_back(Especial("VERMELHO", i, ""));
            deck.emplace_back(Especial("VERDE", i, ""));
            deck.emplace_back(Especial("AZUL", i, ""));
        }

        for_each(acoes.begin(), acoes.end(), [this, &i_especiais](std::string &s) {
            deck.emplace_back(Especial("AMARELO", i_especiais, s));
            deck.emplace_back(Especial("VERMELHO", i_especiais, s));
            deck.emplace_back(Especial("VERDE", i_especiais, s));
            deck.emplace_back(Especial("AZUL", i_especiais, s));
            i_especiais++;
        });
    }

    for (int i = 0; i < 2; i++) {
        deck.emplace_back(Especial("CURINGA", 14, ""));
        deck.emplace_back(Especial("CURINGA", 15, "+4"));
    }
}

void Deck::print_deck() {
    std::for_each(deck.begin(), deck.end(), [](Especial& n) { std::cout << n.get_numero() << n.get_acao_especial() << ' ' << ' ' << n.get_cor() << ' ';});
}

void Deck::shuffle_deck() {
    std::random_device random;
    std::mt19937 gen{random()};

    std::shuffle(deck.begin(), deck.end(), gen);
}

unsigned long Deck::get_deck_size() const {
    return deck.size();
}

void Deck::primeira_carta(std::vector<Especial> &pilha) {
    pilha.push_back(deck.back());
    deck.pop_back();
}
