#include <utility>
#include <iostream>

#include "Computador.h"
#include "Jogo.h"

void Computador::play_card(std::vector<Especial> &cartas_jogador, std::vector<Especial> &pilha_cartas, int index) {
    std::vector<std::string> cores = {"AMARELO", "VERMELHO", "VERDE", "AZUL"};
    std::string passar;

    if (cartas_jogador[index].get_numero() >= 10) {
        std::cout << get_nome() << " irá jogar a carta ";
        Jogo::out_colorido(cartas_jogador[index].get_acao_especial() + ' ' + cartas_jogador[index].get_cor(), cartas_jogador[index].get_cor());
        std::cout << std::endl;
    } else {
        std::cout << get_nome() << " irá jogar a carta ";
        Jogo::out_colorido(std::to_string(cartas_jogador[index].get_numero()) + ' ' + cartas_jogador[index].get_cor(), cartas_jogador[index].get_cor());
        std::cout << std::endl;
    }

    if (cartas_jogador[index].get_cor() == "CURINGA") {
        cartas_jogador[index].set_cor(cores[Jogo::inteiro_aleatorio(0, 3)]);
        std::cout << get_nome() << " escolheu a cor: ";
        Jogo::out_colorido(cartas_jogador[index].get_cor(), cartas_jogador[index].get_cor());
        std::cout << std::endl;
    }

    std::cout << "Digite qualquer coisa para prosseguir o jogo." << std::endl;
    std::cin >> passar;

    pilha_cartas.push_back(cartas_jogador[index]);
    cartas_jogador.erase(cartas_jogador.begin() + index);

}

Computador::Computador(int turno, std::string nome) : Jogador(turno, std::move(nome)) {
}
