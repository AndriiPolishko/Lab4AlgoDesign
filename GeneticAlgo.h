#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Genetic {
	int source, destination,n;
	vector<vector<int>> graph;
	vector<int> fitnessEvaluation();
	
public:
	Genetic(int source,int destination,int n, vector<vector<int>> graph);
	vector<vector<int>> generateInitialPopulation();
	void printInitialPopulation(vector<vector<int>> initial_population);
	void writeInitialPopulationToTheFile(vector<vector<int>> initial_population);
	vector<vector<int>> readInitialPopulationFromTheFile();
};
