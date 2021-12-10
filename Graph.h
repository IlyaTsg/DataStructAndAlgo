#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

const int PSEUDO_INF = INT_MAX;

class Graph {
	private:
		std::vector<std::vector<int>> weights ;//Матрица весов
		std::vector<std::vector<int>> dist;//Матрица кратчайших расстояний
		//std::vector<bool> visited;//Обработанные вершины
		int matrix_size = matrix_size;

	public:
		//void GetDist();
		//bool NegEdges();
		//void Dijkstra();
		void Floyd();
		void MakeGraph();
		void GraphOut();
		void GraphOut1();//изменить

};

//inline void Graph::GetDist() {
//	bool IsPos = NegEdges();
//	if (IsPos) dist = Dijkstra();
//}
//
//inline bool Graph::NegEdges() {
//	bool IsPos = true;
//	for (int i = 0; i < matrix_size && IsPos; i++)  {
//		for (int j = 0; j < weights[i].size() && IsPos; j++) {
//			if (weights[i][j] < 0) IsPos = false;
//		}
//	}
//}

//inline std::vector<std::vector<int>> Graph::Dijkstra() {
//	std::vector<bool> visited(matrix_size, false);
//	bool HasNotVisited = true;
//	dist = weights;
//	for (int i = 0; i < matrix_size && HasNotVisited; i++) {
//		int min = weights[i][0];
//		for (int j = 1; j < weights[i].size() && HasNotVisited; j++) {
//			min = std::min(min, weights[i][j]);
//		}
//		visited[i] = true;
//		for (int k = 0; k < visited.size() && HasNotVisited; k++) HasNotVisited &= visited[k];
//	}
//
//
//}

inline void Graph::Floyd() {
	dist = weights;
	for (int k = 0; k < matrix_size; k++) {
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				dist[i][j] = std::min(dist[i][j], weights[i][k] + dist[k][j]);
			}
		}
	}
}

void Graph::MakeGraph() {
	matrix_size = rand() % 4;//Ограничение для удобства
	weights = std::vector<std::vector<int>>(matrix_size, std::vector<int>(matrix_size, 0));
	for (int i = 0; i < matrix_size; i++) {
		for (int j = i+1; j < matrix_size; j++) {
			weights[i][j] = weights[j][i] =  rand() % 10;//Ограничение для удобства
		}
	}
}

inline void Graph::GraphOut() {
	std::cout << "    ";
	for (int i = 0; i < matrix_size; i++) std::cout << (char)('A' + i) << "  ";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) std::cout << "---";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) {
		std::cout << (char)('A' + i) << " | ";
		for (int j = 0; j < matrix_size; j++) {
			std::cout << weights[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}
inline void Graph::GraphOut1() {
	std::cout << "    ";
	for (int i = 0; i < matrix_size; i++) std::cout << (char)('A' + i) << "  ";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) std::cout << "---";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) {
		std::cout << (char)('A' + i) << " | ";
		for (int j = 0; j < matrix_size; j++) {
			std::cout << dist[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}
