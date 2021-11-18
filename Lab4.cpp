#include <iostream>
#include <iomanip>
#include "Graph.h"
int main()
{ 
    int n = 10;
    vector<vector<int>> grapgh = createGraph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << grapgh[i][j];
        cout << endl;
    }

}
