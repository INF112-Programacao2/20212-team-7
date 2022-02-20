#include <algorithm>
#include <iostream>
#include "Jogo.h"

void Jogo::print_pilha() {
    std::for_each(pilha_cartas.begin(), pilha_cartas.end(), [](const Carta& n) { std::cout << n.get_number() << ' ' << n.get_color() << ' ';});
    std::cout << std::endl;
}