#include "room.h"

Room::Room(int width, int height, Texture* texture) {
    this->width = width;
    this->height = height;
    this->background = texture;
    objects = new list<GameObject*>;
}