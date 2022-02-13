#include <iostream>

#include "Carta.h"
#include "Deck.h"

using namespace std;

int main() {

    Deck deck = Deck();
    deck.fill_deck();
    deck.print_deck();

    return 0;
}

