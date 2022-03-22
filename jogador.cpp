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

    std::for_each(cartas.begin(), cartas.end(), [](Especial n) {

        if (n.get_cor() == "AMARELO") {
            std::cout << "\033[;33m" << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << "\033[0m" << " | ";
        }

        if (n.get_cor() == "VERMELHO") {
            std::cout << "\033[;31m" << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << "\033[0m" << " | ";
        }

        if (n.get_cor() == "VERDE") {
            std::cout << "\033[;32m" << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << "\033[0m" << " | ";
        }

        if (n.get_cor() == "AZUL") {
            std::cout << "\033[;34m" << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << "\033[0m" << " | ";
        }

        if (n.get_cor() == "CURINGA") {
            std::cout << "\033[;30m" << n.get_numero() << ' ' << n.get_acao_especial() << ' ' << n.get_cor() << "\033[0m" << " | ";
        }

    });
    std::cout << std::endl << std::endl;
}

/*
 * Verifica se a carta escolhida pelo jogador com índice começando pelo 1 é da mesma cor ou mesmo número.
 * Caso seja, retira a carta do vetor com as cartas do jogador e joga na pilha de cartas.
 *
 * Também verifica se a carta é curinga, ou seja, vale para jogar em qualquer momento.
 */
void Jogador::play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index) {
    bool carta_valida = false;
    index--;

    while (!carta_valida) {
        if (cartas_jogador.size() > index) {
            if (cartas_jogador[index].get_cor() == pilha_cartas.back().get_cor() or
                cartas_jogador[index].get_numero() == pilha_cartas.back().get_numero() or
                cartas_jogador[index].get_cor() == "CURINGA") {

                if (cartas_jogador[index].get_cor() == "CURINGA") {
                    Jogador::curinga(cartas_jogador[index]);
                }

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

/*
 * Realiza as ações especiais descritas na carta que sejam realizadas no turno do próximo jogador.
 */
void Jogador::acao_especial(const std::string& nome_acao, Jogador& jogador, std::vector<Especial>& deck, Especial& carta) {
    std::string passar;
    std::string cor;

    if (nome_acao == "BLOQUEIO") {
        std::cout << jogador.get_nome() << " foi bloqueado! Digite qualquer coisa para passar o turno." << std::endl;
        std::cin >> passar;
    }

    if (nome_acao == "+2") {
        std::cout << jogador.get_nome() << ", digite qualquer coisa para comprar 2 cartas e passar o turno." << std::endl;
        std::cin >> passar;

        jogador.draw_card(deck, 2);
    }

    if (nome_acao == "+4") {
        std::cout << jogador.get_nome() << ", digite qualquer coisa para comprar 4 cartas e passar o turno." << std::endl;
        std::cin >> passar;

        jogador.draw_card(deck, 4);
    }
}

/*
 * Ao ser jogada, o jogador imediatamente precisa escolher uma cor para ser jogada pelo próximo jogador, o que substitiu
 * a propriedade cor da carta de "CURINGA" para a cor escolhida. Na escolha da cor, também há uma verificação de que ela seja válida.
 */
void Jogador::curinga(Especial& carta) {
    std::string cor;
    bool cor_valida = false;
    std::vector<std::string> cores = {"AMARELO", "VERMELHO", "VERDE", "AZUL"};

    std::cout << "Escolha uma cor para o próximo jogador: Amarelo, Vermelho, Verde ou Azul?" << std::endl;
    std::cin >> cor;
    std::transform(cor.begin(), cor.end(), cor.begin(), ::toupper);

    while (!cor_valida) {
        std::for_each(cores.begin(), cores.end(), [&cor, &cor_valida](const std::string& n) {
            if (cor == n) {
                cor_valida = true;
            }
        });
        if (!cor_valida) {
            std::cout << cor << " não é uma cor válida, escolha uma dessas cores: Amarelo, Vermelho, Verde ou  Azul?" << std::endl;
            std::cin >> cor;
            std::transform(cor.begin(), cor.end(), cor.begin(), ::toupper);
        }
    }

    carta.set_cor(cor);
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

