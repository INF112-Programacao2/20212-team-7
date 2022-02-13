#ifndef INC_20212_TEAM_7_DECK_H
#define INC_20212_TEAM_7_DECK_H

#include <vector>

#include "Carta.h"

class Deck {
private:
    std::vector<Carta> deck;
public:
    void fill_deck();
    void print_deck();
};

#endif
