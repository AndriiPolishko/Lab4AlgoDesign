#include "GeneticAlgo.h"

const int INF = 2147483646;

Genetic::Genetic(int source, int destination, int n, vector<vector<int>> graph) {
	this->source = source;
	this->destination = destination;
	this->graph = graph;
	this->n = n;
}

vector<vector<int>> Genetic::generateInitialPopulation() {
	vector<vector<int>> results;
	queue<vector<int>> Q;
	vector<int> start;
	start.push_back(source);
	Q.push(start);
	vector<int> visited;
	while(!Q.empty()) {
		vector<int> path = Q.front();

		vector<int> temp_path;

		Q.pop();

		int src = path[path.size() - 1];
		visited.push_back(src);

		if(src==destination) {
			results.push_back(path);
			continue;
		}

		for(int j = 0; j < n; j++) {

			if(graph[src][j]!=0 && find(visited.begin(),visited.end(),j) == visited.end()) {
				temp_path = path;
				temp_path.push_back(j);
				Q.push(temp_path);
			}
		}

	}
	return results;
}

void Genetic::printInitialPopulation(vector<vector<int>> initial_population) {
	for (int i = 0; i < initial_population.size(); i++) {
		for (int j = 0; j < initial_population[i].size(); j++) {
			cout << initial_population[i][j] << " ";
		}
		cout << endl;
	}
}

void Genetic::writeInitialPopulationToTheFile(vector<vector<int>> initial_population) {
	ofstream fout;
	string file_path = "InitialPopulation.txt";
	fout.open(file_path);

	if(!fout.is_open()) {
		cout << "Can`t open the file " << file_path;
		exit(1);
	}

	for( int i = 0; i < initial_population.size(); i++) {
		for( int j = 0; j < initial_population[i].size(); j++) {
			fout<< initial_population[i][j] << " ";
		}
		fout <<';' << '\n';
	}
}

vector<vector<int>> Genetic::readInitialPopulationFromTheFile() {
	vector<vector<int>> initial_population;
	vector<int> gen;

	string temp;

	ifstream fin;
	string file_path = "InitialPopulation.txt";
	fin.open(file_path);

	if (!fin.is_open()) {
		cout << "Can`t open the file " << file_path;
		exit(1);
	}

	while(!fin.eof()) {
		for(int i = 0;i < n; i++) {
			fin >> temp;
			if(temp==";") {
				initial_population.push_back(gen);
				gen.clear();
				break;
			}
			gen.push_back(stoi(temp));
		}
	}

	return initial_population;
}