#pragma once
#include<vector>
#include <fstream>
#include <ctime>
using namespace std;
vector<vector<int>> createGraph(int n) {
	vector<vector<int>> graph(n, vector<int>(n));
	vector<int> degrees(n);
	srand(time(NULL));
	ofstream fout;
	fout.open("Graph.txt");
	for(auto i = 0; i < n; i++) {
		for(auto j = 0; j < n; j++) {

			if (i == j) {
				fout << graph[i][j] << " ";
				continue;
			}

			//int fill_or_not = rand() % 2 + 1;

			if(degrees[i]<10 && graph[j][i]==0) {
				degrees[i]++;
				graph[i][j] = rand() % 150 + 5;
				graph[j][i] = graph[i][j];
			}
			fout << graph[i][j] << " ";
		}
		fout << "\n";
	}
	return graph;
}
