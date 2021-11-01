#include <iostream>
#include "list.h"

const int MulSize = 10;

int main()
{
    unsigned short word = 0x3D;
    list A(word), B("24323"), C("17546212"), D("875634");
    std::cout << "A: ";
    A.show();
    std::cout << std::endl;
    list E = (A | B)|(C&D);
    std::cout << "E: ";
    E.show();
    std::cout << std::endl;
    system("pause");
    return 0;
}