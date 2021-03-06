#pragma once

#include <vector>
#include <list>
#include <ostream>
#include <iostream>

#include "room.h"
#include "io/terminal.h"

using namespace std;

class GameObject;

class Render {
private:
    vector<vector<GameObject*>> visibleMap; //Вектор расположен в обратном порядке, т.е. "высота" векторов по "длина" элементов, обращение map[y][x]
    int width, height; //Размеры вектора
    void initVector(int, int);
public:
    int x, y; //Позиция камеры на карте (левого верхнего угла камеры)

    Render();
    Render(int, int);
    void setWidth(int);
    void setHeight(int);
    void render(Room* room);
};

