#pragma once

#include <list>
#include <string>

#include "object/components/position.h"
#include "object/components/texture.h"

using namespace std;

class Component;

class GameObject {
public:
    GameObject();
    GameObject(const GameObject&);
    ~GameObject();
    int update();

    Position* position;
    Texture* texture;
};
