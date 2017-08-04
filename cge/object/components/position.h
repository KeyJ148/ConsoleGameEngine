#pragma once

#include <string>

#include "component.h"

using namespace std;

class Position : public Component{
public:
    int x, y;
    int width, height;

    Position();
    Position(int, int);
    Position(int, int, int, int);
    Position(const Position&);
    void update();
    Position* copy();
    string getType();
};

