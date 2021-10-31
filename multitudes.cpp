#include <iostream>
#include "list.h"

const int MulSize = 10;

int main()
{
    list *A = new list();
    list *B = new list();
    list *C = new list();
    for(int i = 0; i < MulSize/2; i++){
        char El;
        std::cin >> El;
        A->append(El);
    }
    A->show();
    std::cout << std::endl << "--------------------------" << std::endl;

    system("pause");
    return 0;
}