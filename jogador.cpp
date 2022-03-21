#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Jogador.h"
#include "Especial.h"

void Jogador::draw_card(std::vector<Especial> &deck, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        cartas.push_back(deck.back());
        deck.pop_back();
    }
}

void Jogador::print_cartas() {
    std::cout << "Suas cartas: (" << cartas.size() <<  " cartas)" << std::endl;

    std::for_each(cartas.begin(), cartas.end(), [](Especial n) { std::cout << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << " | ";});
    std::cout << std::endl << std::endl;
}

/*
 * Verifica se a carta escolhida pelo jogador com índice começando pelo 1 é da mesma cor ou mesmo número.
 * Caso seja, retira a carta do vetor com as cartas do jogador e joga na pilha de cartas.
 */
void Jogador::play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index) {
    bool carta_valida = false;
    index--;

    while (!carta_valida) {
        if (cartas_jogador.size() > index) {
            if (cartas_jogador[index].get_cor() == pilha_cartas.back().get_cor() or
                cartas_jogador[index].get_numero() == pilha_cartas.back().get_numero()) {

                pilha_cartas.push_back(cartas_jogador[index]);
                cartas_jogador.erase(cartas_jogador.begin() + index);

                carta_valida = true;
            } else {
                std::cout << cartas_jogador[index].get_numero() << ' ' << cartas_jogador[index].get_cor() << " não é uma carta válida para jogar." << std::endl << std::endl;

                std::cout << "Selecione outra carta." << std::endl;
                std::cin >> index;
                index--;
            }
        } else {
            std::cout << "Carta escolhida não existe, tente outro índice." << std::endl;
            std::cin >> index;
            index--;
        }
    }
}

void Jogador::acao_especial(const std::string& nome_acao, Jogador& jogador, std::vector<Especial>& deck) {
    std::string passar;

    if (nome_acao == "BLOQUEIO") {
        std::cout << jogador.get_nome() << " foi bloqueado! Digite qualquer coisa para passar o turno." << std::endl;
        std::cin >> passar;
    }

    if (nome_acao == "+2") {
        std::cout << jogador.get_nome() << ", digite qualquer coisa para comprar 2 cartas e passar o turno." << std::endl;
        std::cin >> passar;

        jogador.draw_card(deck, 2);
    }
}

Jogador::Jogador(int turno, std::string nome) {
    _turno = turno;
    _nome = std::move(nome);
}

int Jogador::get_turno() const {
    return this->_turno;
}

void Jogador::set_turno(int turno) {
    _turno = turno;
}

std::string Jogador::get_nome() {
    return this->_nome;
}

