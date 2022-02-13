#ifndef INC_20212_TEAM_7_CARTA_H
#define INC_20212_TEAM_7_CARTA_H

class Carta {
private:
    int _color;
    int _number;

public:
    Carta(int color, int number);
    int get_color() const;
    int get_number() const;
};

#endif
