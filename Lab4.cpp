#include <iostream>
#include "Graph.h"
int main()
{ 
    int n = 20;
    string path = "Graph.txt";
    //vector<vector<int>> graph = createGraph(n, path);
    //setGraphInFile(n, path, graph);
    vector<vector<int>> graph = getGraphFromFile(n, path);
    printTheGraph(graph);

}
