#include <iostream>
#include "Graph.h"
#include "Constants.h"
#include "GeneticAlgo.h"
int main()
{ 
    int n = VERTECIES;
    string path = "Graph.txt";

    /*vector<vector<int>> graph = createGraph(n, path);
    setGraphInFile(n, path, graph);*/

    vector<vector<int>> graph = getGraphFromFile(n, path);
    //printTheGraph(graph);

    int source = 0, destination = 4;
    Genetic test(source, destination, n, graph);//contructor: Genetic(int source,int destination,int n, vector<vector<int>> graph)
    vector<vector<int>> initial_population = test.generateInitialPopulation();
    test.printInitialPopulation(initial_population);
}