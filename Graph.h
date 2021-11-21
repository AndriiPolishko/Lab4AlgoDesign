#pragma once
#include<vector>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
vector<vector<int>> createGraph(int n, string path) {

	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> visited(n, vector<int>(n));

	vector<int> degrees(n);

	srand(time(NULL));

	for(auto i = 0; i < n; i++) {
		for(auto j = 0; j < n; j++) {

			if (i == j)
				continue;

			int fill_or_not = rand() % 2 + 1;

			if(fill_or_not%2==0 && degrees[i]<10 && visited[j][i]!=-1) {
				visited[i][j] = -1;
				visited[j][i] = -1;
				degrees[i]++;
				graph[i][j] = rand() % 150 + 5;
				graph[j][i] = graph[i][j];

			}
		}
	}
	
	return graph;
}

void setGraphInFile(int n, string path, vector<vector<int>> graph) {

	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		exit(1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < n - 1)
				fout << graph[i][j] << " ";
			else
				fout << graph[i][j];
		}
		if (i < n - 1)
			fout << "\n";
	}
	fout.close();
}

vector<vector<int>> getGraphFromFile(int n, string path) {
	vector<vector<int>> graph(n,vector<int>(n));
	ifstream fin;
	string temp;
	fin.open(path);
	if (!fin.is_open())
		exit(1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			fin >> temp;
			graph[i][j] = stoi(temp);
		}
		getline(fin, temp);
	}
	fin.close();
	return graph;

}