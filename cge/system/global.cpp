#include <cycle/render.h>
#include "global.h"

int Global::os;
int Global::print_test;
Room* Global::room;
Render* Global::render;
Terminal* Global::terminal;

void Global::clear() {
    delete room;
    delete render;
    delete terminal;
}