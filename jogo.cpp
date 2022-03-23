#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "Jogo.h"
#include "Jogador.h"
#include "Computador.h"
#include "Especial.h"

Jogo::Jogo(int qtd_total, int qtd_jogadores, int qtd_computadores) {
    _qtd_total = qtd_total;
    _qtd_jogadores = qtd_jogadores;
    _qtd_computadores = qtd_computadores;
}

void Jogo::print_pilha() {
    std::cout << "Última carta jogada:" << std::endl;

    if (pilha_cartas.back().get_numero() >= 10) {
        Jogo::out_colorido(pilha_cartas.back().get_acao_especial() + ' ' + pilha_cartas.back().get_cor(), pilha_cartas.back().get_cor());
    } else {
        Jogo::out_colorido(std::to_string(pilha_cartas.back().get_numero()) + ' ' + pilha_cartas.back().get_cor(), pilha_cartas.back().get_cor());
    }

    std::cout << std::endl << std::endl;
}

/*
 * Configura o jogo criando o deck e embaralhando-o, criando os jogadores e comprando as cartas iniciais para cada um.
 */
void Jogo::configura_jogo() {
    _deck.fill_deck();
    _deck.shuffle_deck();

    for (int i = 0; i < _qtd_jogadores; i++) {
        std::string nome = "Jogador ";
        nome += std::to_string(i+1);

        Jogador jogador = Jogador(i, nome);
        jogadores.emplace_back(jogador);
        jogadores[i].draw_card(_deck.deck, 8);
    }

    for (int i = 0; i < _qtd_computadores; i++) {
        std::string nome = "Computador ";
        nome += std::to_string(i+1);

        Computador computador = Computador(i, nome);
        computadores.emplace_back(computador);
        computadores[i].draw_card(_deck.deck, 8);
    }

    _deck.primeira_carta(pilha_cartas);
    _jogo = true;
}

void Jogo::acao_jogador(Jogador &jogador) {
    int index;
    std::string uno;
    std::string passar;

    if (_deck.deck.empty()) {
        _deck.fill_deck();
    }

    system("clear");

    print_pilha();
    jogador.print_cartas();



    bool carta_valida = checa_cartas_validas(jogador);

    /*
     * Verifica se a última carta jogada possui alguma ação especial e se ela só foi realizada, para evitar ações infinitas.
     */
    if (!pilha_cartas.back().get_acao_especial().empty() and !pilha_cartas.back().get_acao_realizada()) {
        Jogador::acao_especial(pilha_cartas.back().get_acao_especial(), jogador, _deck.deck, pilha_cartas.back());
        pilha_cartas.back().set_acao_realizada(true);
    }

    /*
     * Quando o jogador possui apenas uma carta e ela é válida, será conferido primeiro se o jogador digitará "uno",
     * caso positivo, ele pode jogar sua última carta e ganhar.
     */
    else if (carta_valida and jogador.cartas.size() == 1) {
        std::cout << jogador.get_nome() << ", é o seu turno, qual carta deseja jogar? (Informe o índice da carta)" << std::endl;
        std::cin >> uno;

        std::transform(uno.begin(), uno.end(), uno.begin(), ::toupper);
        if (uno == "UNO") {
            Jogo::validacao_input(jogador.get_nome() + " lembrou de gritar UNO e está livre para jogar sua carta.", index);

            jogador.play_card(jogador.cartas, pilha_cartas, index);
        } else {
            std::cout << jogador.get_nome() << " esqueceu de gritar UNO e portanto deve comprar 1 carta e digitar qualquer coisa para passar o turno." << std::endl;
            std::cin >> passar;
            jogador.draw_card(_deck.deck, 1);
        }

    } else if (carta_valida) {
        Jogo::validacao_input(jogador.get_nome() + ", é o seu turno, qual carta deseja jogar? (Informe o índice da carta)", index);

        jogador.play_card(jogador.cartas, pilha_cartas, index);
    } else {
        std::cout << jogador.get_nome() << ", é o seu turno, mas não há cartas válidas para você jogar, digite qualquer coisa para comprar uma carta e passar o turno." << std::endl;
        std::cin >> passar;
        jogador.draw_card(_deck.deck, 1);
    }

    if (jogador.cartas.empty()) {
        std::cout << jogador.get_nome() << " venceu o jogo, parabéns!" << std::endl;
        _jogo = false;
    }
}

void Jogo::acao_computador(Computador &computador) {
    int index;
    std::string passar;

    if (_deck.deck.empty()) {
        _deck.fill_deck();
    }

    system("clear");

    print_pilha();
    computador.print_cartas();

    std::vector<int> i_validos = indexes_validos(computador);

    if (!pilha_cartas.back().get_acao_especial().empty() and !pilha_cartas.back().get_acao_realizada()) {
        Jogador::acao_especial(pilha_cartas.back().get_acao_especial(), computador, _deck.deck, pilha_cartas.back());
        pilha_cartas.back().set_acao_realizada(true);
    } else if (!i_validos.empty() and computador.cartas.size() == 1) {
        int numero_aleatorio = inteiro_aleatorio(0, 10);

        if (numero_aleatorio >= 3) {
            std::cout << computador.get_nome() << " gritou UNO e jogará sua última carta." << std::endl;
            computador.play_card(computador.cartas, pilha_cartas, i_validos[0]);
        } else {
            std::cout << computador.get_nome() << " esqueceu de gritar UNO e comprará 1 carta e passar o turno." << std::endl;
            computador.draw_card(_deck.deck, 1);
        }
    } else if (!i_validos.empty()) {
        index = i_validos[inteiro_aleatorio(0, i_validos.size()-1)];
        computador.play_card(computador.cartas, pilha_cartas, index);
    } else {
        std::cout << computador.get_nome() << " não possui cartas válidas para jogar, logo comprará 1 carta e passará o turno." << std::endl;
        std::cout << "Digite qualquer coisa para prosseguir." << std::endl;
        std::cin >> passar;
        computador.draw_card(_deck.deck, 1);
    }

    if (computador.cartas.empty()) {
        std::cout << computador.get_nome() << " venceu o jogo, parabéns!" << std::endl;
        _jogo = false;
    }
}

bool Jogo::get_jogo() const {
    return this->_jogo;
}

/*
 * Utiliza o algoritmo for_each para iterar sobre todas as cartas na mão do jogador e verificar se existe ao menos
 * uma carta válida para ser jogada.
 */
bool Jogo::checa_cartas_validas(Jogador &jogador) {
    std::vector<Especial> cartas_jogador = jogador.cartas;
    bool carta_valida = false;

    for_each(cartas_jogador.begin(), cartas_jogador.end(), [this, &carta_valida](const Especial &n) {
        if (n.get_cor() == pilha_cartas.back().get_cor() or
            n.get_numero() == pilha_cartas.back().get_numero() or
            n.get_cor() == "CURINGA") {

            carta_valida = true;
        }
    });

    return carta_valida;
}

std::vector<int> Jogo::indexes_validos(Computador &computador) {
    std::vector<int> i_validos{};
    std::vector<Especial> c = computador.cartas;

    for (int i = 0; i < c.size(); i++) {
        if (c[i].get_cor() == pilha_cartas.back().get_cor() or
            c[i].get_numero() == pilha_cartas.back().get_numero() or
            c[i].get_cor() == "CURINGA") {

            i_validos.push_back(i);
        }
    }

    return i_validos;
}

/*
 * Uso do while em quanto o "cin" não conseguir ler o input do usuário.
 */
void Jogo::validacao_input(const std::string& mensagem, int& input) {
    while (std::cout << mensagem << std::endl and !(std::cin >> input)) {
        std::cin.clear(); // limpa o input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore o erro para gerar um novo input
        std::cout << "Tente novamente com um valor válido." << std::endl;
    }
}

int Jogo::inteiro_aleatorio(int min, int max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);

    int random_int = distr(eng);
    return random_int;
}

void Jogo::out_colorido(const std::string& carta, const std::string& cor) {
    if (cor == "AMARELO") {
        std::cout << "\033[;33m" << carta << "\033[0m";
    }

    if (cor == "VERMELHO") {
        std::cout << "\033[;31m" << carta << "\033[0m";
    }

    if (cor == "VERDE") {
        std::cout << "\033[;32m" << carta << "\033[0m";
    }

    if (cor == "AZUL") {
        std::cout << "\033[;34m" << carta << "\033[0m";
    }

    if (cor == "CURINGA") {
        std::cout << "\033[;30m" << carta << "\033[0m";
    }
}
