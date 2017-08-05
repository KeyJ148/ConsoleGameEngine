#include "system/global.h"
#include "cycle.h"

Cycle* Cycle::instance = nullptr;

Cycle* Cycle::getInstance() {
    if (Cycle::instance == nullptr) Cycle::instance = new Cycle();
    return Cycle::instance;
}

Cycle::Cycle() {
    this->listeners = new set<Listener*>;
}

Cycle::~Cycle() {
    delete listeners;
}

void Cycle::init(Render* render){
    this->render = render;
}

int Cycle::start() {
    for (Listener* listener : *listeners) listener->start();

    int result;
    while (true) {

        for (Listener* listener : *listeners) listener->updateStart();
        result = Global::room->update();
        if (result != 0) break;
        for (Listener* listener : *listeners) listener->updateEnd();

        for (Listener* listener : *listeners) listener->renderStart();
        render->render(Global::room);
        for (Listener* listener : *listeners) listener->renderEnd();
    }

    for (Listener* listener : *listeners) listener->end(result);

    //-1 используется для выхода из цикла, но при успешном завершение программы
    if (result == -1) result = 0;
    return result;
}

void Cycle::addListener(Listener* listener) {
    listeners->insert(listener);
}

void Cycle::removeListener(Listener* listener) {
    listeners->erase(listener);
}