#include <iostream>
#include <time.h>
#include "Graph.h"

int main()
{
    srand(time(0));
    Graph NewGraph(0);
    NewGraph.GraphOut();
    NewGraph.Floyd();
    NewGraph.MinimalGraphOut();
    system("pause");
    return 0;
}