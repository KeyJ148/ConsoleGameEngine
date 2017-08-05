#include "game_object.h"

#include "component.h"

GameObject::GameObject() {
    components = new list<Component*>;
}

GameObject::GameObject(const GameObject& gameObject) : GameObject() {
    //Перебираем в цикле все компоненты у объекта, который надо копировать
    //На основе каждого компонента через конструктор копирования класса Component создаем копию компонента
    //В результате копирования мы получили указатель на копию, разименовываем и добавляем в список своих компонентов
    for (list<Component*>::iterator it = gameObject.components->begin(); it != gameObject.components->end(); ++it){
        Component* copy = (*it)->copy();
        components->push_back(copy);
    }
}

GameObject::~GameObject() {
    delete components; //Удаляем список
}

int GameObject::update() {
    for (list<Component*>::iterator it = components->begin(); it != components->end(); ++it){
        //Делаем 2 разименовывания, вначале преобразуем итератор к типу данных, которые он содержит, потом разименовываем сам тип данных
        int result = (*it)->update();
        if (result != 0) return result;
    }

    return 0;
}

void GameObject::addComponent(Component* component) {
    if (!findComponent(component->getType()))
        components->push_back(component);
}

//Возвращает true в случае успешного удаления компонента
bool GameObject::removeComponent(string type) {
    for (list<Component*>::iterator it = components->begin(); it != components->end(); ++it){
        if ((*it)->getType() == type){
            components->erase(it);
            return true;
        }
    }

    return false;
}

bool GameObject::findComponent(string type) {
    for (list<Component*>::iterator it = components->begin(); it != components->end(); ++it){
        if ((*it)->getType() == type) return true;
    }

    return false;
}

Component* GameObject::getComponent(string type) {
    if (!findComponent(type)) return nullptr;

    for (list<Component*>::iterator it = components->begin(); it != components->end(); ++it){
        if ((*it)->getType() == type) return (*it);
    }
}