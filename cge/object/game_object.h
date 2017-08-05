#pragma once

#include <list>
#include <string>

using namespace std;

class Component;

class GameObject {
private:
    list<Component*>* components;//Указатель на список, который хранит указатели на компоненты
public:
    GameObject();
    GameObject(const GameObject&);
    ~GameObject();

    int update();
    void addComponent(Component*);
    bool removeComponent(string);
    bool findComponent(string);
    Component* getComponent(string);
};
