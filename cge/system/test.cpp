#include "test.h"

#include <iostream>
#include <algorithm>
#include <list>

#include "game_object.h"
#include "position.h"
#include "texture.h"
#include "io/render.h"
#include "io/terminal.h"

using namespace std;

bool testStart(bool print) {
    bool test_component_position = testComponentPosition();
    bool test_component_texture = testComponentTexture();
    bool test_component_text = testComponentText();
    bool test_game_object = testGameObject();
    bool test_room = testRoom();
    bool test_render = testRender(print);

    if (print){
        cout << "Tests: " << endl;
        cout << "[" << getAnswerText(test_component_position) << "]" << "Component position" << endl;
        cout << "[" << getAnswerText(test_component_texture) << "]" << "Component texture" << endl;
        cout << "[" << getAnswerText(test_component_text) << "]" << "Component text" << endl;
        cout << "[" << getAnswerText(test_game_object) << "]" << "Game object" << endl;
        cout << "[" << getAnswerText(test_room) << "]" << "Room" << endl;
        cout << "[" << getAnswerText(test_render) << "]" << "Render" << endl;
    }

    Terminal* terminal = new Terminal();
    terminal->getch();
    delete terminal;
}

string getAnswerText(bool result){
    return (result)? "OK" : "FAILED";
}

bool testComponentPosition(){
    Position* position1 = new Position();
    Position* position2 = new Position(*position1);
    Position* position3 = position1->copy();

    if (position1 == position2) return false;
    if (position1 == position3) return false;
    if (position2 == position3) return false;

    position1->update();
    delete position1;
    delete position2;
    delete position3;

    return true;
}

bool testComponentTexture(){
    Texture* texture1 = new Texture();
    Texture* texture2 = new Texture(*texture1);
    Texture* texture3 = texture1->copy();

    if (texture1 == texture2) return false;
    if (texture1 == texture3) return false;
    if (texture2 == texture3) return false;

    texture1->update();
    delete texture1;
    delete texture2;
    delete texture3;

    return true;
}

bool testComponentText(){
    return true;
}

bool testGameObject(){
    GameObject* object1 = new GameObject();
    GameObject* object2 = new GameObject(*object1);

    if (object1 == object2) return false;

    object1->update();
    delete object1;
    delete object2;
}

bool testRoom(){
    char** background = new char*[1];
    background[0] = " ";
    Texture* backtex = new Texture(background, 1, 1);
    Room* room = new Room(100, 100, backtex);

    if (room->objects->size() != 0) return false;
    delete[] background;
    delete backtex;
    delete room;

    return true;
}

bool testRender(bool print){
    Position* position = new Position(1, 1);

    char** tex = new char*[3];
    for (int i=0; i<3; i++)
        tex[i] = new char[6];

    tex[0] = "test_1";
    tex[1] = "test_2";
    tex[2] = "test_3";

    Texture* texture = new Texture(tex, 6, 3);

    GameObject* obj = new GameObject();
    obj->addComponent(texture);
    obj->addComponent(position);

    char** texMini = new char*[1];
    texMini[0] = "*";
    Texture* textureMini = new Texture(texMini, 1, 1);

    Position* up_left = new Position(0, 0);
    Position* up_right = new Position(79, 0);
    Position* down_right = new Position(79, 23);
    Position* down_left = new Position(0, 23);

    GameObject* up_left_o = new GameObject();
    up_left_o->addComponent(textureMini);
    up_left_o->addComponent(up_left);

    GameObject* up_right_o = new GameObject();
    up_right_o->addComponent(textureMini);
    up_right_o->addComponent(up_right);

    GameObject* down_right_o = new GameObject();
    down_right_o->addComponent(textureMini);
    down_right_o->addComponent(down_right);

    GameObject* down_left_o = new GameObject();
    down_left_o->addComponent(textureMini);
    down_left_o->addComponent(down_left);

    char** background = new char*[1];
    background[0] = " ";
    Texture* backtex = new Texture(background, 1, 1);
    Room* room = new Room(100, 100, backtex);
    room->objects->push_back(obj);
    room->objects->push_back(up_left_o);
    room->objects->push_back(up_right_o);
    room->objects->push_back(down_right_o);
    room->objects->push_back(down_left_o);

    Terminal* terminal = new Terminal();
    Render* render = new Render(*terminal);

    if (print) render->render(room);

    delete position;
    delete[] tex;
    delete texture;
    delete[] texMini;
    delete textureMini;
    delete obj;
    delete background;
    delete backtex;
    delete room;
    delete terminal;
    delete render;

    delete up_left;
    delete up_left_o;
    delete up_right;
    delete up_right_o;
    delete down_right;
    delete down_right_o;
    delete down_left;
    delete down_left_o;

    return true;
}