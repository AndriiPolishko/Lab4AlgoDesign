#include <iostream>
#include <iomanip>
#include "Graph.h"
int main()
{ 
    int n = 10;
    string path = "Graph.txt";
    //createGraph(n, path);
    vector<vector<int>> grapgh = getGraph(n, path);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << grapgh[i][j];
        cout << endl;
    }

}
