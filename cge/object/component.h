#pragma once

#include <string>

using namespace std;

//Полностью абстрактный класс (интерфейс), от которого наследуются все компоненты
class Component {
public:
    virtual void update() = 0;//Вызывается каждый ход для обновления состояния компонента
    virtual Component* copy() = 0;//Вызывается при копирование компонента, возвращает указатель на свою копию
    virtual string getType() = 0;//Возвращает тип компонента (строка в нижнем регистре совпадающая с названием класса)
};

