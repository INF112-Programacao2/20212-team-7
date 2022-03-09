#ifndef INC_20212_TEAM_7_ESPECIAL_H
#define INC_20212_TEAM_7_ESPECIAL_H

#include "Carta.h"

#include <string>

class Especial : public Carta {

private:
    std::string _acao_especial;
public:
    Especial(std::string color, int number, std::string acao_especial);
    std::string get_acao_especial();
};

#endif //INC_20212_TEAM_7_ESPECIAL_H
