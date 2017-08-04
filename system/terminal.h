#pragma once

#include <iostream>
#include "termios.h"

using namespace std;

class Terminal{
private:
    termios old, now;
    int os;
    void initTermios();
    void resetTermios();
public:
    int width, height;
    ostream* out = &cout; //Поток для вывода
    Terminal();
    Terminal(int);
    Terminal(int, int);
    Terminal(int, int, int);
    enum {WINDOWS, LINUX};
    char getch();
    void clear();
};


