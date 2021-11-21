#include <iostream>
#include "Graph.h"

int main()
{ 
    int n = VERTECIES;
    string path = "Graph.txt";
    vector<vector<int>> graph = createGraph(n, path);
    setGraphInFile(n, path, graph);
    //vector<vector<int>> graph = getGraphFromFile(n, path);
    printTheGraph(graph);

    int source, destination;

}
