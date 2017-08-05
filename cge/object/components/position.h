#pragma once

#include <string>

#include "component.h"

using namespace std;

class Position : public Component{
public:
    int x, y;

    Position();
    Position(int, int);
    Position(const Position&);
    int update();
    Position* copy();
};

