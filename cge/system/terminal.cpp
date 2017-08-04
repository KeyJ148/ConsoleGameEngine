#include "terminal.h"

#include "global.h"

Terminal::Terminal() : Terminal(80, 25){}

Terminal::Terminal(int width, int height) {
    this->width = width;
    this->height = height;
    initTermios();
}

//Настройка терминала, отключает буффер ввода
void Terminal::initTermios() {
    tcgetattr(0, &old); //Сохранить старые настройки терминала
    now = old; //Создать новые настройки на основе старых
    now.c_lflag &= ~ICANON; //Отключить буферизированный ввод/вывод
    now.c_lflag &= ~ECHO; //Отключить echo режим
    tcsetattr(0, TCSANOW, &now); //Применить новые настройки
}

//Вернуть старые настройки терминала
void Terminal::resetTermios() {
    tcsetattr(0, TCSANOW, &old);
}

//Считать 1 символ из консоли не выводя его
char Terminal::getch() {
    return getchar();
}

string Terminal::getLine(){
    resetTermios();
    string s;
    getline(cin, s);
    initTermios();
    return s;
}

//Очистить консоль
void Terminal::clear(){
    switch (Global::os){
        case Global::WINDOWS: system("cls"); break;
        case Global::LINUX: system("clear"); break;
    }
}