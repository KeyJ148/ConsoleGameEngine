#include "terminal.h"

Terminal::Terminal() : Terminal(WINDOWS){}

Terminal::Terminal(int os) : Terminal(os, 80, 25) {}

Terminal::Terminal(int width, int height) : Terminal(WINDOWS, width, height){}

Terminal::Terminal(int os, int width, int height) {
    this->os = os;
    this->width = width;
    this->height = height;
}

//Настройка терминала
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
    initTermios();
    char ch = getchar();
    resetTermios();

    return ch;
}

//Очистить консоль
void Terminal::clear(){
    switch (os){
        case WINDOWS: system("cls"); break;
        case LINUX: system("clear"); break;
    }
}