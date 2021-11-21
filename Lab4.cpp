#include <iostream>
#include <iomanip>
#include "Graph.h"
int main()
{ 
    int n = 10;
    string path = "Graph.txt";
    //vector<vector<int>> grapgh = createGraph(n, path);
    //setGraphInFile(n, path, grapgh);
    vector<vector<int>> grapgh = getGraphFromFile(n, path);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << grapgh[i][j];
        cout << endl;
    }

}
