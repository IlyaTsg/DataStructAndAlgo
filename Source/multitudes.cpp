#include <iostream>
#include <time.h>
#include "..\Headers\list.h"
#include "..\Headers\boolarray.h"
#include "..\Headers\set.h"
#include "..\Headers\word.h"

//#define OS linux
#ifdef OS
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

int Set::N = 10, Set::cnt = 0;
int Word::N = 10, Word::cnt = 0;
int BoolArray::UniSize = 10;
int list::UniSize = 10;

int main()
{
    int mode;

    srand(time(0));

    do{
        CLS;
        std::cout << "Formula: E = (A | B) | (C & D)\n";
        std::cout << "----Menu----\n" << "1 - Array\n" << "2 - Linear list\n" << "3 - Boolean array\n" << "4 - Machine word\n" << "0 - Exit\n";
        std::cout << "Enter mode: ";
        std::cin >> mode;
        std::cin.get();
        switch(mode){
            case 1:{
                Set Aarray('A'), Barray('B'), Carray('C'), Darray('D'), Earray;
				unsigned long t1 = clock();
                for (int i = 0; i < 1000000; i++) Earray = (Aarray | Barray) | (Carray & Darray);
				unsigned long t2 = clock();

                std::cout << "A = ";
                Aarray.Show();
                std::cout << "B = ";
                Barray.Show();
                std::cout << "C = ";
                Carray.Show();
                std::cout << "D = ";
                Darray.Show();
                std::cout << "E = ";
                Earray.Show();
				std::cout << "Time: " << (float)(t2-t1)/ CLK_TCK << std::endl;
                std::cin.get();
                break;
            }
			case 2: {
				list Alist, Blist, Clist, Dlist, Elist;
				Alist.Generate();
                Blist.Generate();
                Clist.Generate();
                Dlist.Generate();
                unsigned long t1 = clock();
                for (int i = 0; i < 1000000; i++) Elist = (Alist | Blist) | (Clist & Dlist);
				unsigned long t2 = clock();
                std::cout << "A = ";
                Alist.show();
                std::cout << "B = ";
                Blist.show();
                std::cout << "C = ";
                Clist.show();
                std::cout << "D = ";
                Dlist.show();
                std::cout << "E = ";
                Elist.show();
				std::cout << "Time: " << (float)(t2-t1)/ CLK_TCK << std::endl;
                std::cin.get();
				break;
			}
            case 3:{
                BoolArray Aboolarray, Bboolarray, Cboolarray, Dboolarray, Eboolarray;
				Aboolarray.Generate();
                Bboolarray.Generate();
                Cboolarray.Generate();
                Dboolarray.Generate();
                unsigned long t1 = clock();
                for (int i = 0; i < 1000000; i++) Eboolarray = (Aboolarray | Bboolarray) | (Cboolarray & Dboolarray);
				unsigned long t2 = clock();
                std::cout << "A = ";
                Aboolarray.show();
                std::cout << "B = ";
                Bboolarray.show();
                std::cout << "C = ";
                Cboolarray.show();
                std::cout << "D = ";
                Dboolarray.show();
                std::cout << "E = ";
                Eboolarray.show();
				std::cout << "Time: " << (float)(t2-t1)/ CLK_TCK << std::endl;
                std::cin.get();
                break;
            }
            case 4:{
                Word Aword('A'), Bword('B'), Cword('C'), Dword('D'), Eword;
				unsigned long t1 = clock();
                for (int i = 0; i < 1000000; i++) Eword = (Aword | Bword) | (Cword & Dword);
				unsigned long t2 = clock();

                std::cout << "A = ";
                Aword.Show();
                std::cout << "B = ";
                Bword.Show();
                std::cout << "C = ";
                Cword.Show();
                std::cout << "D = ";
                Dword.Show();
                std::cout << "E = ";
                Eword.Show();
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