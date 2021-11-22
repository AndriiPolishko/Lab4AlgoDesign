#pragma once
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Genetic {
	int source, destination,n;
	vector<vector<int>> graph;
	
public:
	Genetic(int source,int destination,int n, vector<vector<int>> graph);
	vector<vector<int>> generateInitialPopulation();
	void printInitialPopulation(vector<vector<int>> initial_population);
};
