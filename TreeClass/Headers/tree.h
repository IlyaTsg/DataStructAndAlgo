#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

class tree{
    private:
        std::vector<char> vertices; // Вектор всех вершин в дереве [A, B(левый сын A), C(левый сын B), 0(правый пустой сын B), D(правый сын А), 0(левый сын D), E(правый сын D)]
        int power; // Количество непустых вершин
        int maxdepth, offset; // Максимальная глубина, смещение
        int NumOfVertex = 0; // Переменная для обхода дерева
		int RightSubTree;//Индекс корня правого поддерева
		int TreeHeight = 1;//Высота правого поддерева
		

        void clrscr();
        void OutVertex();
    public:
        tree() : power(0), maxdepth(0), offset(40){ }
		~tree() 
		{
			if (SCREEN) {
				for (int i = 0; i < maxdepth; i++) delete SCREEN[i];
				delete SCREEN;
			}
		}
        char **SCREEN;
        void MakeTree(int depth); // Изначально запускается для корня(глубина = 0) MakeTree(0)
        void PutVertex(int r, int c); //Поставить вершину в нужное место экрана
        void OutTree(); // Вывод дерева
		void SubTreeHeight(int depth, int index);
		int GetSubHeight() { return TreeHeight; }
};

inline void tree::MakeTree(int depth) // depth - глубина вершины
{
    char tag = 'a' + power;
    int CreateVertex = (depth < rand()%6 + 1) && (tag <= 'z');
    if(CreateVertex){
        vertices.push_back(tag); // Создаём сам элемент
        power++;
        MakeTree(depth + 1); // Создаём левого сына
        MakeTree(depth + 1); // Создаём правого сына
    }
	else vertices.push_back('!'); depth++; // Если пустая вершина, то в ней !

    maxdepth = std::max(depth, maxdepth);
    if(tag == 'a' && maxdepth){ // Выделяем память под экран, после создания дерева
        SCREEN = new char* [maxdepth];
        for(int i = 0; i < maxdepth; ++i){
            SCREEN[i] = new char[80];
        }
    }
}

inline void tree::clrscr()
{
    for(int i = 0; i < maxdepth; i++){
        memset(SCREEN[i], ' ', 80);
    }
}

inline void tree::PutVertex(int r, int c)
{
    if(r && c && (c<80)) SCREEN[r-1][c-1] = vertices[NumOfVertex]; // Поставить вершину в нужное место
	NumOfVertex++;

    if((r < maxdepth ) && NumOfVertex < vertices.size()){
        if(vertices[NumOfVertex] != '!') PutVertex(r+1, c - (offset>>r)); // Если левый не пустой, то ставим его в нужное место
		else NumOfVertex++; // Если пустая, то переходим к след.
		if (r == 1) RightSubTree = NumOfVertex;
        if(vertices[NumOfVertex] != '!') PutVertex(r+1, c + (offset>>r)); // Если левый не пустой, то ставим его в нужное место
		else NumOfVertex++; // Если пустая, то переходим к след.
    }
}

inline void tree::OutTree()
{
    clrscr();
    PutVertex(1, offset);
    for(int i = 0; i < maxdepth; i++){
        SCREEN[i][79] = 0;
        std::cout << std::endl << std::endl << SCREEN[i];
    }
    std::cout << std::endl;
	for (auto x : vertices) std::cout << x;
	std::cout << std::endl << RightSubTree;

}

inline void tree::SubTreeHeight(int depth, int index)
{
	if (vertices[RightSubTree] != '!')
	{
		if (TreeHeight < depth) TreeHeight = depth;
		index = RightSubTree++;

		if (vertices[RightSubTree] != '!') SubTreeHeight(depth + 1, index); // Если левый не пустой, то ставим его в нужное место
		else RightSubTree++; // Если пустая, то переходим к след.
		if (vertices[index] != '!') std::cout << vertices[index];
		if (vertices[RightSubTree] != '!') SubTreeHeight(depth + 1, index); // Если левый не пустой, то ставим его в нужное место
		else RightSubTree++; // Если пустая, то переходим к след.
	}
	else TreeHeight = 0;
}