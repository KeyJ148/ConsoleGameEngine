#include <iostream>

#include "game_object.h"
#include "component.h"

GameObject::GameObject() {
    this->position = nullptr;
    this->texture = nullptr;
}

GameObject::GameObject(const GameObject& gameObject) : GameObject() {
    //Перебираем в цикле все компоненты у объекта, который надо копировать
    //На основе каждого компонента через конструктор копирования класса Component создаем копию компонента
    //В результате копирования мы получили указатель на копию, разименовываем и добавляем в список своих компонентов
    if (gameObject.position != nullptr) position = gameObject.position->copy();
    if (gameObject.texture != nullptr) texture = gameObject.texture->copy();
}

GameObject::~GameObject() {
    if (position != nullptr) delete position;
    if (texture != nullptr) delete texture;
}

int GameObject::update() {
    int result;

    if (position != nullptr) result = position->update();
    if (result != 0) return result;

    if (texture != nullptr) result = texture->update();
    if (result != 0) return result;

    return 0;
}