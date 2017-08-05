#pragma once

//Полностью абстрактный класс (интерфейс), от которого наследуются все слушатели для Cycle
class Listener{
public:
    virtual void start() = 0;
    virtual void updateStart() = 0;
    virtual void updateEnd() = 0;
    virtual void renderStart() = 0;
    virtual void renderEnd() = 0;
    virtual void end(int) = 0;
};