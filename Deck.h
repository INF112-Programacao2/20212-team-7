#ifndef INC_20212_TEAM_7_DECK_H
#define INC_20212_TEAM_7_DECK_H

#include <vector>

#include "Especial.h"

class Deck {
public:
    void fill_deck();
    void shuffle_deck();
    void print_deck();
    unsigned long get_deck_size() const;

    std::vector<Especial> deck;
};

#endif
