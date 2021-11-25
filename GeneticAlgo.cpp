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
	srand(time(NULL));//TEST MEYBE DELETE
	
	while(!Q.empty()) {
		if (results.size() >= 100)
			break;
		vector<int> path = Q.front();

		vector<int> temp_path;

		Q.pop();

		int src = path[path.size() - 1];
		visited.push_back(src);

		int rnd = rand() % 20 + 1;

		if(src==destination && path.size()>=7 && rnd%20==0) {
			results.push_back(path);
			continue;
		}

		for(int j = 0; j < n; j++) {

			if(graph[src][j]!=0 && find(path.begin(), path.end(),j) == path.end()) {
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
		cout << "Path lenght - " << lenghtOfPath(initial_population[i])<<": ";
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

int Genetic::lenghtOfPath(vector<int> path) {
	int lenght = 0;
	for(int i = 0; i < path.size()-2; i++) {
		lenght += graph[path[i]][path[i + 1]];
	}
	return lenght;
}

void Genetic::sortPathes(vector<vector<int>> &initial_population) {
	sort(initial_population.begin(), initial_population.end(),
		[this](const std::vector<int> a, const std::vector<int> b)
		{return lenghtOfPath(a) > lenghtOfPath(b);
		});
}

//vector<int> Genetic::fitnessEvaluation(vector<vector<int>> population) {
//	vector<int> fitness;
//	vector<int> current_gen;
//	int distance = 0;
//	for( int gen = 0; gen < population.size(); gen++) {
//		for( int i = 0; i < population[gen].size()-1; i++) {
//			distance += graph[ population[ gen ][ i ] ][ population[ gen ][ i+1 ] ];
//		}
//		fitness.push_back(distance);
//		distance = 0;
//	}
//	return fitness;
//}

vector<vector<int>> Genetic::selectBestHromosomsToReproduce(vector<vector<int>> population) {
	vector<vector<int>> best_hromosoms;
	best_hromosoms.push_back(population[population.size() - 1]);
	best_hromosoms.push_back(population[population.size() - 2]);
	return best_hromosoms;
}

vector<int> Genetic::getPointsOfIntersection(vector<vector<int>> parents) {
	vector<int> parent1 = parents[0];
	vector<int> parent2 = parents[1];
	
	vector<int> points_of_intersect;

	for( int i = 0; i < parent1.size(); i++) {
		for( int j = 0; j < parent2.size(); j++) {
			if (parent1[i] == parent2[j])
				points_of_intersect.push_back(parent1[i]);
		}
	}
	return points_of_intersect;
}

int Genetic::randPointOfIntersect(vector<int> points_of_intsection) {
	srand(time(NULL));
	for(int i = 0; i < points_of_intsection.size(); i++) {
		int random = rand() % 3 + 1;
		if(random%2 == 0) 
			return points_of_intsection[i];
	}
}

vector<vector<int>> Genetic::crossover(vector<vector<int>> parents, int point_of_intersection) {


	vector<vector<int>> result;

	/// filling up first offspring
	vector<int>  offspring1;

	vector<int> parent1 = parents[0], parent2 = parents[1];

	int  position1 = find(parent1.begin(), parent1.end(), point_of_intersection) - parent1.begin();
	int  position2 = find(parent2.begin(), parent2.end(), point_of_intersection) - parent2.begin();

	vector<int>::const_iterator first_half1;
	vector<int>::const_iterator first_half2;

	vector<int>::const_iterator second_half1;
	vector<int>::const_iterator second_half2;

	first_half1 = parent1.begin() + 0;
	first_half2 = parent1.begin() + position1;
	vector<int> first_half(first_half1, first_half2);
		
	second_half1 = parent2.begin() + position2;
	second_half2 = parent2.begin() + parent2.size();
	vector<int> second_half(second_half1, second_half2);

	offspring1.insert(offspring1.end(), first_half.begin(), first_half.end());
	offspring1.insert(offspring1.end(), second_half.begin(), second_half.end());

	result.push_back(offspring1);
	////////////////////////////////////////////////////////////////////////////////////////////
	/// filling up second offspring
	vector<int> offspring2;

	first_half1 = parent2.begin() + 0;
	first_half2 = parent2.begin() + position2;
	vector<int> first_halff(first_half1, first_half2);

	second_half1 = parent1.begin() + position1;
	second_half2 = parent1.begin() + parent1.size();
	vector<int> second_halff(second_half1, second_half2);

	offspring2.insert(offspring2.end(), first_halff.begin(), first_halff.end());
	offspring2.insert(offspring2.end(), second_halff.begin(), second_halff.end());

	result.push_back(offspring2);

	return result;
}

void Genetic::printPath(vector<int> path) {
	for(int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
}

void Genetic::geneticAlgo(vector<vector<int>>& population) {
	sortPathes(population);
	cout << "Lenght of first best path :" << lenghtOfPath(population[population.size() - 1])
		<<" ; The first best path :";
	printPath(population[population.size() - 1]);
	cout<<endl; 

	cout << endl << "Population before : " << endl;
	printInitialPopulation(population);

	int choice;

	cout << "If you want to use TOURNAMENT selection press - 1, if you want to use OPTION selection press 2 : ";
	cin >> choice;
	
	switch (choice)
	{
	case 1:
		for (int iteration = 0; iteration < 1000; iteration++) {
			vector<vector<int>> offspring = crossoverForTournament(population);
			if (lenghtOfPath(population[0]) > lenghtOfPath(offspring[0]))
				population[0] = offspring[0];
			if (lenghtOfPath(population[1]) > lenghtOfPath(offspring[1]))
				population[1] = offspring[1];
			sortPathes(population);
		}
		cout << endl << "Population after : " << endl;
		printInitialPopulation(population);

		cout << "Lenght of last best path :" << lenghtOfPath(population[population.size() - 1])
			<< " ; The last best path :";
		printPath(population[population.size() - 1]);
		break;
	case 2:
		for (int iteration = 0; iteration < 1000; iteration++) {
			vector<vector<int>> offspring = crossoverForOptions(population);
			if (lenghtOfPath(population[0]) > lenghtOfPath(offspring[0]))
				population[0] = offspring[0];
			if (lenghtOfPath(population[1]) > lenghtOfPath(offspring[1]))
				population[1] = offspring[1];
			sortPathes(population);
		}
		cout << endl << "Population after : " << endl;
		printInitialPopulation(population);

		cout << "Lenght of last best path :" << lenghtOfPath(population[population.size() - 1])
			<< " ; The last best path :";
		printPath(population[population.size() - 1]);
		break;
	default:
		cout << "You entered unreserved number";
		break;
	}
	

	
}

vector<int> Genetic::selectRandomHromosom(vector<vector<int>> population) {
	srand(time(NULL));
	int max = (population.size() - 1);
	int rnd = rand() %max;
	return population[rnd];
}

vector<int> Genetic::selectOneBestHromosom(vector<vector<int>> population) {
	return population[population.size() - 1];
}

vector<vector<int>> Genetic::crossoverForOptions(vector<vector<int>> population) {
	vector<int> points_of_intersection;
	vector<int> best_hromosom = selectOneBestHromosom(population);
	vector<int> rand_hromosom = selectRandomHromosom(population);
	vector<vector<int>> parents;
	parents.push_back(best_hromosom);
	parents.push_back(rand_hromosom);
	points_of_intersection = getPointsOfIntersection(parents);
	int counter = 0;
	while(points_of_intersection.size() <= 2) {
		rand_hromosom = selectRandomHromosom(parents);
		parents[1] = rand_hromosom;
		points_of_intersection = getPointsOfIntersection(parents);
		counter++;
		if(counter == 1000) {
			cout << "No pathes with intersection";
			exit(1);
		}
	}
	int point_of_intersection;
	point_of_intersection = randPointOfIntersect(points_of_intersection);
	while(point_of_intersection == source || point_of_intersection ==destination) {
		point_of_intersection = randPointOfIntersect(points_of_intersection);
	}

	return crossover(parents, point_of_intersection);
	
}

vector<vector<int>> Genetic::crossoverForTournament(vector<vector<int>> population) {
	vector<int> points_of_intersection;
	vector<vector<int>> best_hromosoms = selectBestHromosomsToReproduce(population);
	points_of_intersection = getPointsOfIntersection(best_hromosoms);
	int counter = population.size() - 3;
	while(points_of_intersection.size()==0) {
		
		best_hromosoms[1] = population[counter];
		points_of_intersection = getPointsOfIntersection(best_hromosoms);
		if (counter == 0) {
			cout << "No pathes with intersection";
			exit(1);
		}
		counter--;
	}
	int point_of_intersection = randPointOfIntersect(points_of_intersection);

	return crossover(best_hromosoms, point_of_intersection);
}