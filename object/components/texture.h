#pragma once

#include <string>

#include "component.h"

using namespace std;

class Texture : public Component{
public:
    char** texture;//Массив расположен в обратном порядке, т.е. "высота" векторов по "длина" элементов, обращение tex[y][x]
    int texture_w, texture_h;//Размеры двумерного массива

    Texture();
    Texture(char**, int, int);//Указатель на двумерный массив и его размеры
    Texture(const Texture&);
    ~Texture();
    void update(long);
    Texture* copy();
    string getType();
};