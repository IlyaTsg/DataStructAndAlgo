#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

const int PSEUDO_INF = 999;
const int MAX_COUNT_VERTEX = 10;
const int MAX_WEIGHT = 10;

class Graph {
	private:
		std::vector<std::vector<int>> weights ; // Начальные веса рёбер
		std::vector<std::vector<int>> dist; // Минимальные расстояния между вершинами
		int matrix_size;

	public:
		Graph() : matrix_size(rand()%MAX_COUNT_VERTEX)
		{
			weights = std::vector<std::vector<int>>(matrix_size, std::vector<int>(matrix_size, 0));
			for (int i = 0; i < matrix_size; i++) {
				for (int j = i+1; j < matrix_size; j++) {
					int weight = rand() % MAX_WEIGHT;
					weights[i][j] = weights[j][i] = (weight == 0) ? PSEUDO_INF : weight; // Условимся, если вес ребра нулевой, то значит между рёбрами нет пути( кроме путей между самой в себя)
				}
			}
		}
		Graph(int) // Ввод матрицы весов с клавиатуры
		{
			int weight;
			std::cout << "Enter count of vertex: ";
			std::cin >> matrix_size;
			std::cout << "Enter matrix of weight: \n";
			for (int i = 0; i < matrix_size; i++) {
				std::vector<int> tmp_vec;
				for (int j = 0; j < matrix_size; j++) {
					std::cin >> weight;
					tmp_vec.push_back(weight);
				}
				weights.push_back(tmp_vec);
			}
		}
		void Floyd();
		void GraphOut();
		void MinimalGraphOut();
};

inline void Graph::Floyd() {
	dist = weights;
	for (int k = 0; k < matrix_size; k++) {
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		// Для задания по КиТГ
		std::cout << "Vertex " << (char)('A'+k) << std::endl;
		this->MinimalGraphOut();
		//
	}
}

inline void Graph::GraphOut() {
	std::cout << "    ";
	for (int i = 0; i < matrix_size; i++) std::cout << (char)('A' + i) << "  ";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size+1; i++) std::cout << "---";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) {
		std::cout << (char)('A' + i) << " | ";
		for (int j = 0; j < matrix_size; j++) {
			if(weights[i][j] == PSEUDO_INF) std::cout << "I" << "  ";
			else std::cout << weights[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

inline void Graph::MinimalGraphOut() {
	std::cout << "    ";
	for (int i = 0; i < matrix_size; i++) std::cout << (char)('A' + i) << "  ";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size+1; i++) std::cout << "---";
	std::cout << std::endl;
	for (int i = 0; i < matrix_size; i++) {
		std::cout << (char)('A' + i) << " | ";
		for (int j = 0; j < matrix_size; j++) {
			if(dist[i][j] == PSEUDO_INF) std::cout << "I" << "  ";
			else std::cout << dist[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
