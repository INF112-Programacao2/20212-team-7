#ifndef INC_20212_TEAM_7_ESPECIAL_H
#define INC_20212_TEAM_7_ESPECIAL_H

#include "Carta.h"

#include <string>

class Especial : public Carta {

private:
    std::string _acao_especial;
    bool _acao_realizada = false;
public:
    Especial(std::string color, int number, std::string acao_especial);
    std::string get_acao_especial();
    bool get_acao_realizada() const;
    void set_acao_realizada(bool acao_realizada);
};

#endif //INC_20212_TEAM_7_ESPECIAL_H
