#pragma once

#include <vector>
#include <list>
#include <ostream>
#include <iostream>

#include "game_object.h"
#include "texture.h"
#include "io/terminal.h"

using namespace std;

class Room {
private:
    int width, height;
public:
    list<GameObject*>* objects;//Указатель на список, который хранит указатели на объекты
    Texture* background;
    Room(int, int, Texture*);
};
