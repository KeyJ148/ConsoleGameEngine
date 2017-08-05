#include "room.h"

Room::Room(int width, int height, Texture* texture) {
    this->width = width;
    this->height = height;
    this->background = texture;
    objects = new list<GameObject*>;
}

int Room::update() {
    for (GameObject* object : *objects){
        int result = object->update();
        if (result != 0) return result;
    }

    return 0;
}