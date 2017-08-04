#include <terminal.h>
#include <algorithm>

#include "global.h"
#include "test.h"

int loader(int os){
    Global::os = os;
    test();
}

int main(int argc, char* argv[]) {
    int os = Global::WINDOWS;
    if (argc > 1){
        string os_string = argv[1];
        transform(os_string.begin(), os_string.end(), os_string.begin(), ::tolower);
        if (os_string == "windows") os = Global::WINDOWS;
        if (os_string == "linux") os = Global::LINUX;
    }

    return loader(os);
}