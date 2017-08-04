#include <algorithm>

#include "io/terminal.h"
#include "global.h"
#include "test.h"

int loader(int os, bool print_test){
    Global::os = os;
    Global::print_test = print_test;
    testStart(Global::print_test);

    return 0;
}

int main(int argc, char* argv[]) {
    int os = Global::WINDOWS;
    bool print_test = false;
    if (argc > 1){
        string os_string = argv[1];
        transform(os_string.begin(), os_string.end(), os_string.begin(), ::tolower);
        if (os_string == "windows") os = Global::WINDOWS;
        if (os_string == "linux") os = Global::LINUX;
    }

    if (argc > 2){
        string pt_string = argv[2];
        transform(pt_string.begin(), pt_string.end(), pt_string.begin(), ::tolower);
        if (pt_string == "t" || pt_string == "true") print_test = true;
    }

    return loader(os, print_test);
}