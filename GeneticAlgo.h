#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

class Genetic {
	int source, destination,n;
	vector<vector<int>> graph;

	vector<vector<int>> selectBestHromosomsToReproduce(vector<vector<int>> population);

	int lenghtOfPath(vector<int> path);
	void printPath(vector<int> path);

	vector<int> getPointsOfIntersection(vector<vector<int>> parents);//function that returns points of insertion
	int randPointOfIntersect(vector<int> points_of_intsection);//function that randomly choose point of insertion 
	vector<vector<int>> crossover(vector<vector<int>> parents, int point_of_intersection);
	
	vector<vector<int>> crossoverForOptions(vector<vector<int>> population);

	vector<vector<int>> crossoverForTournament(vector<vector<int>> population);

	vector<int> selectRandomHromosom(vector<vector<int>> population);
	vector<int> selectOneBestHromosom(vector<vector<int>> population);


public:
	Genetic(int source,int destination,int n, vector<vector<int>> graph);//DONE

	

	vector<vector<int>> generateInitialPopulation();//DONE

	void printInitialPopulation(vector<vector<int>> initial_population);//DONE

	void writeInitialPopulationToTheFile(vector<vector<int>> initial_population);//DONE

	vector<vector<int>> readInitialPopulationFromTheFile();//DONE

	void sortPathes(vector<vector<int>>& initial_population);

	void geneticAlgo(vector<vector<int>> &population);
};
