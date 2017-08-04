#include "render.h"

#include "game_object.h"
#include "position.h"
#include "texture.h"

Render::Render(Terminal terminal) : Render(terminal, 0, 0) {}

Render::Render(Terminal terminal, int x, int y) {
    initVector(terminal.width, terminal.height);

    this->terminal = terminal;
    this->x = x;
    this->y = y;
}

void Render::initVector(int width, int height) {
    this->width = width;
    this->height = height;

    visibleMap.reserve(height);
    for (int i=0; i<height; i++){
        visibleMap[i].reserve(width);
        for (int j=0; j<width; j++){
            visibleMap[i][j] = nullptr;
        }
    }
}

void Render::setWidth(int width) {
    initVector(width, this->height);
}

void Render::setHeight(int height) {
    initVector(this->width, height);
}

void Render::render(const list<GameObject*>& objects){
    //Выполняем цикл для каждого объекта в комнате, добавляя его указатель на массив символом консоли
    for (auto it = objects.begin(); it != objects.end(); ++it){
        //Делаем 2 разименовывания, вначале преобразуем итератор к типу данных, которые он содержит, потом разименовываем сам тип данных
        Position* position = static_cast<Position*> ((*it)->getComponent("position"));
        Texture* texture = static_cast<Texture*> ((*it)->getComponent("texture"));

        //Если объект имеет текстуру и находится в области видимости (сам объект или часть его текстуры),
        //то помещаем указатель на него в массив, а точнее во все ячейки где находится его текстура
        if (texture != nullptr &&
            position->x + texture->texture_w >= x && position->x < x+width &&
            position->y + texture->texture_h >= y && position->y < y+height){
                for (int i = position->x; i < position->x+texture->texture_w; i++){
                    for (int j = position->y; j < position->y+texture->texture_h; j++){
                        if (i-x > 0 && j-y > 0) visibleMap[j-y][i-x] = (*it);
                    }
                }
        }
    }

    //Отрисовка текстур
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (visibleMap[i][j] == nullptr){
                (*terminal.out) << ' '; //Заменить на background комнаты
                continue;
            }


            Texture* texture = static_cast<Texture*> (visibleMap[i][j]->getComponent("texture"));
            Position* position = static_cast<Position*> (visibleMap[i][j]->getComponent("position"));
            int xArr = x+j - position->x;
            int yArr = y+i - position->y;

            (*terminal.out) << texture->texture[yArr][xArr];
        }
        (*terminal.out) << endl;
    }
}
