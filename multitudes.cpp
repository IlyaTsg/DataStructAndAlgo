#include <iostream>
#include "list.h"
#include "boolarray.h"

const int MulSize = 10;

int main()
{
    // Тест списков
    unsigned short word = 0x3D;
    list A(word), B("24323"), C("17546212"), D("875634");

    std::cout << "A: ";
    A.show();
    std::cout << "B: ";
    B.show();
    std::cout << "C: ";
    C.show();
    std::cout << "D: ";
    D.show();

    list E = (A | B)|(C&D);
    std::cout << "E: ";
    E.show();
    std::cout << std::endl;

    // Тест булевых массивов
    BoolArray Aa(word), Ba("24323"), Ca("17546212"), Da("875634");

    std::cout << "A: ";
    Aa.show();
    std::cout << "B: ";
    Ba.show();
    std::cout << "C: ";
    Ca.show();
    std::cout << "D: ";
    Da.show();

    BoolArray Ea = (Aa | Ba)|(Ca&Da);
    std::cout << "E: ";
    Ea.show();

    system("pause");
    return 0;
}