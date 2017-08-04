#pragma once

#include <iostream>
#include <termios.h>

using namespace std;

class Terminal{
private:
    termios old, now;
    void initTermios();
    void resetTermios();
public:
    int width, height;
    ostream* out = &cout; //Поток для вывода
    Terminal();
    Terminal(int, int);
    char getch();
    string getLine();
    void clear();
};


