#include <iostream>
#include <time.h>

//Списки
//#include "..\Headers\list.h"
//Массив битов
//#include "..\Headers\boolarray.h"
//Массив символов
//#include "..\Headers\set.h"
//Машинное слово
#include "..\Headers\word.h"

//#define OS linux
#ifdef OS
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

int Set::N = 10, Set::cnt = 0;


int main()
{
    int mode;

    srand(time(0));

    do{
        CLS;
        std::cout << "Formula: E = (A | B) | (C & D)\n";
        std::cout << "----Menu----\n"  << "0 - Exit\n" << "1 - Calculate\n";
        std::cout << "Enter option: ";
        std::cin >> mode;
        std::cin.get();
        switch(mode){
            case 1:{
                Set A(1), B(1), C(1), D(1), E;
				unsigned long t1 = clock();
                for (int i = 0; i < 1000000; i++) E = (A | B) | (C & D);
				unsigned long t2 = clock();

                std::cout << "A = ";
                A.Show();
                std::cout << "B = ";
                B.Show();
                std::cout << "C = ";
                C.Show();
                std::cout << "D = ";
                D.Show();
                std::cout << "E = ";
                E.Show();
				std::cout << "Time: " << (float)(t2-t1)/ CLK_TCK << std::endl;
                std::cin.get();
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Enter correct variant!\n";
                std::cin.get();
                break;
        }
    }while(mode);
    return 0;
}