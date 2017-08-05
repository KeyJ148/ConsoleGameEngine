#pragma once

#include <set>
#include <cycle/render.h>

#include "listener.h"

using namespace std;

class Cycle {
public:
    static Cycle* getInstance();
    Cycle();
    ~Cycle();
    void init(Render*);
    int start();
    void addListener(Listener*);
    void removeListener(Listener*);
private:
    set<Listener*>* listeners;
    Render* render;
    static Cycle* instance;
};