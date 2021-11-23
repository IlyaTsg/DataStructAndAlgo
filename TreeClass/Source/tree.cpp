#include <iostream>
#include <time.h>
#include "../Headers/tree.h"

int main()
{
	srand(time(0));
    tree NewTree;
    NewTree.MakeTree(0);
    NewTree.OutTree();
	std::cout << std::endl;
	NewTree.SubTreeHeight(1, 0);
	std::cout << "\nHeight " << NewTree.GetSubHeight() << std::endl;
    system("pause");
    return 0;
}