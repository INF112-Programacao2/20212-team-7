#include <algorithm>
#include <iostream>

#include "Jogo.h"
#include "Jogador.h"
#include "Computador.h"

int main() {
    int qtd_total = 0;
    int qtd_jogadores = -1;
    int qtd_computadores;
    int turno_atual = 0;

    while (qtd_total < 2 or qtd_total > 4) {
        Jogo::validacao_input("Quantos jogadores no total vão participar da partida? (2-4)", qtd_total);
    }

    while (qtd_jogadores < 0 or qtd_jogadores > qtd_total) {
        Jogo::validacao_input("Quanto jogadores humanos vão participar da partida?", qtd_jogadores);
    }

    qtd_computadores = qtd_total - qtd_jogadores;

    Jogo jogo = Jogo(qtd_total, qtd_jogadores, qtd_computadores);

    jogo.configura_jogo();

    /*
     * Verifica o jogador (ou computador) que possui o mesmo turno da variável 'turno_atual' que é modificada no final
     * de todos os turnos.
     */
    while (jogo.get_jogo()) {
        std::for_each(jogo.jogadores.begin(), jogo.jogadores.end(), [&turno_atual, &jogo](Jogador& j) {
            if (jogo.get_jogo() and j.get_turno() == turno_atual) {
                jogo.acao_jogador(j);
            }
        });

        std::for_each(jogo.computadores.begin(), jogo.computadores.end(), [&turno_atual, &jogo](Computador& c) {
            if (jogo.get_jogo() and c.get_turno() == turno_atual) {
                jogo.acao_computador(c);
            }
        });

        /*
         * Dependendo do valor de reverso, a direção dos turnos é mudado.
         * Caso negativo (padrão), o turno aumenta, caso positivo, o turno diminui.
         */
        if (!jogo.get_reverso()) {
            if (turno_atual < qtd_total) {
                turno_atual++;
            } else {
                turno_atual = 0;
            }
        } else {
            if (turno_atual > 0) {
                turno_atual--;
            } else {
                turno_atual = qtd_total-1;
            }
        }

        std::cout << "turno atual: " << turno_atual << std::endl;
    }

    return 0;
}

