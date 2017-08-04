#include "test.h"

#include <iostream>
#include <algorithm>
#include <list>

#include "game_object.h"
#include "position.h"
#include "texture.h"
#include "render.h"
#include "terminal.h"

using namespace std;

void test(){
    Terminal* terminal = new Terminal();

    cout << "Привет!" << endl;
    cout << "Введите x и y позицию: ";

    int x, y;
    //cin >> x >> y;
    GameObject obj;
    Position* pos = new Position(5, 10, 10, 3);
    Texture* texture = new Texture();
    obj.addComponent(pos);
    obj.addComponent(texture);

    cout << "find position: " << obj.findComponent("position") << endl;
    Position* posReturned = static_cast<Position*>(obj.getComponent("position"));
    cout << "x,y: " << posReturned->x << " " << posReturned->y << endl;
    cout << "w,h: " << posReturned->width << " " << posReturned->height << endl;
    cout << "remove position: " << obj.removeComponent("position") << endl;
    cout << "find position: " << obj.findComponent("position") << endl;

    cout << "find texture: " << obj.findComponent("texture") << endl;
    Texture* textureReturned = static_cast<Texture*>(obj.getComponent("texture"));
    cout << "w,h: " << textureReturned->texture_w << " " << textureReturned->texture_h << endl;
    cout << "texture: " << textureReturned->texture[0][0] << endl;
    cout << "remove texture: " << obj.removeComponent("texture") << endl;
    cout << "find texture: " << obj.findComponent("texture") << endl;

    char** tex = new char*[3];
    for (int i=0; i<3; i++)
        tex[i] = new char[10];

    tex[0] = "1234567890";
    tex[1] = "qwertyuiop";
    tex[2] = "asdfghjklz";


    Texture* textureBig = new Texture(tex, 10, 3);
    Render* render = new Render(*terminal);

    GameObject* o = new GameObject();
    o->addComponent(textureBig);
    o->addComponent(posReturned);

    char** background = new char*[1];
    background[0] = " ";
    Texture* backtex = new Texture(background, 1, 1);
    Room* room = new Room(100, 100, backtex);
    room->objects->push_back(o);

    (*terminal->out) << "terminal test" << endl;
    cout << "start render" << endl;
    render->render(room);
    cout << "end" << endl;
    cout << "enter line" << endl;
    string s = terminal->getLine();
    cout << "string: " << s << endl;

    terminal->getch();
    for (int i=0; i<10; i++){
        terminal->getch();
        terminal->clear();
        cout << "Игра" << endl;
    }

    cout << "start fps test" << endl;
    terminal->getch();
    for (int i=0; i<10000; i++){
        terminal->clear();
        render->render(room);
        terminal->getch();
    }

    terminal->getch();
}