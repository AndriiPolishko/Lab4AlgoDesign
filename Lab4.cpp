#include <iostream>
#include "Graph.h"
#include "Constants.h"
#include "GeneticAlgo.h"
int main()
{ 
    int n = VERTECIES;
    string path = "Graph.txt";

    /*vector<vector<int>> graph = createGraph(n, path);
    setGraphInFile(n, path, graph);*/ //uncoment this if want to generate a new graph

    vector<vector<int>> graph = getGraphFromFile(n, path);
    //printTheGraph(graph);

    int source = SOURCE;
    int destination = DESTINATION;

    Genetic test(source, destination, n, graph);//contructor: Genetic(int source,int destination,int n, vector<vector<int>> graph)
    
    //vector<vector<int>> initial_population = test.generateInitialPopulation();
    //test.writeInitialPopulationToTheFile(initial_population);

    vector<vector<int>> initial_population = test.readInitialPopulationFromTheFile();
    test.printInitialPopulation(initial_population);
   
}