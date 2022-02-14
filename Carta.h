#ifndef INC_20212_TEAM_7_CARTA_H
#define INC_20212_TEAM_7_CARTA_H

#include <string>

class Carta {
private:
    std::string _color;
    int _number;

public:
    Carta(std::string color, int number);
    std::string get_color() const;
    int get_number() const;
};

#endif
