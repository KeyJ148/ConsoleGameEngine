#include "position.h"

Position::Position() : Position(0, 0) {}

Position::Position(int x, int y) : Position(x, y, 1, 1) {}

Position::Position(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Position::Position(const Position& position) {
    x = position.x;
    y = position.y;
    width = position.width;
    height = position.height;
}

Position* Position::copy() {
    return new Position(*this);
}

inline int Position::update() { return 0;}

string Position::getType() {
    return "position";
}