#pragma once

#include "map/room.h"
#include "render.h"

class Global {

public:
    static int os;
    static int print_test;
    static Room* room;
    static Render* render;
    static Terminal* terminal;
    enum OS {WINDOWS, LINUX};

    static void clear();
};