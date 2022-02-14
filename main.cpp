#include <iostream>

#include "Deck.h"
#include "Jogador.h"

using namespace std;

int main() {

    Deck deck = Deck();
    deck.fill_deck();
    deck.shuffle_deck();

    deck.print_deck();
    cout << endl << deck.get_deck_size() << endl;

    Jogador jogador = Jogador();
    jogador.draw_card(deck.deck, 8);

    cout << endl;
    jogador.print_cartas();

    cout << deck.get_deck_size() << endl;
    return 0;
}

