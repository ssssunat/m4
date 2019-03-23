/*Дано невзвешенное дерево. Расстоянием между двумя вершинами будем называть количество ребер в пути, соединяющем эти две вершины. 
Для каждой вершины определите сумму расстояний до всех остальных вершин. Время работы должно быть O(n).*/

#include<iostream>
#include<vector>

struct Vertex {
	int Kol = 0;
	int Sum = 0;
	Vertex *Parent = NULL;
};

int main()
{
	int n;
	std::cin >> n;

	std::vector<Vertex*>d(n);

	for (int i = 0; i < n; i++) {
		d[i] = new Vertex;
	}

	int a, b;

	for (int i = 1; i < n; ++i){

		std::cin >> a >> b;
		d[b]->Parent = d[a];
	}

	for (int i = n - 1; i > 0; i--){

		d[i]->Parent->Kol += d[i]->Kol + 1;
		d[i]->Parent->Sum += d[i]->Sum + d[i]->Kol + 1;

	}

	std::cout << d[0]->Sum << std::endl;

	for (int i = 1; i < n; i++){

		d[i]->Sum = d[i]->Parent->Sum - 2 * d[i]->Kol - 2 + n;
		std::cout << d[i]->Sum << std::endl;
	}

	return 0;

}
