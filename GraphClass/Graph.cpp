#include <iostream>
#include <time.h>
#include "Graph.h"

int main()
{
    srand(time(0));
    Graph NewGraph;
    std::cout << "Initial: " << std::endl;
    NewGraph.GraphOut();
    NewGraph.Floyd();
    std::cout << "Result: " << std::endl;
    NewGraph.MinimalGraphOut();
    system("pause");
    return 0;
}