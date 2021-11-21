#include <iostream>
#include <iomanip>
#include "Graph.h"
int main()
{ 
    int n = 20;
    string path = "Graph.txt";
    //vector<vector<int>> graph = createGraph(n, path);
    //setGraphInFile(n, path, graph);
    vector<vector<int>> graph = getGraphFromFile(n, path);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << graph[i][j];
        cout << endl;
    }

}
