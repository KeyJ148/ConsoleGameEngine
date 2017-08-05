#include "position.h"

Position::Position() : Position(0, 0) {}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::Position(const Position& position) {
    x = position.x;
    y = position.y;
}

Position* Position::copy() {
    return new Position(*this);
}

inline int Position::update() { return 0;}