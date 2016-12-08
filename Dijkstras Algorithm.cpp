/*
  Дан ориентированный взвешенный граф. Для него вам необходимо найти кратчайшее расстояние от вершины S до вершины F.

Входные данные
В первой строке входного файла INPUT.TXT записаны три числа: N, S и F (1 ≤ N ≤ 100; 1 ≤ S, F ≤ N), где N - количество вершин графа. В следующих N строках записаны по N чисел - матрица смежности графа, где число в i-ой строке j-ом столбце соответствует ребру из i в j: -1 означает отсутствие ребра между вершинами, а любое неотрицательное целое число (от 0 до 100) - наличие ребра данного веса. На главной диагонали матрицы всегда записаны нули.

Выходные данные
В выходной файл OUTPUT.TXT необходимо вывести искомое расстояние или -1, если пути между указанными вершинами не существует.

Пример
№	INPUT.TXT	
1	3 2 1
0 1 1
4 0 1
2 1 0

OUTPUT.TXT
3
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector < vector<pair<int, int>> > g;

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	//printf("The goal is to find distance of %d and %d\n", s, f);

	vector < vector< pair< int, int > > > g(n);
	//Reading
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int w;
			cin >> w;
			pair<int, int> p(j, w);
			if (w != -1)g[i].push_back(p);
		}
	}

	//Printing the graph

	//for (int i = 0; i < g.size(); i++)
		//for (int j = 0; j < g[i].size(); j++)
			//printf("%d is connected to %d with weight %d\n", i, g[i][j].first, g[i][j].second);



	//Needed arrays
	vector<int> used(n, 0);
	vector<int> d(n, INT_MAX);
	d[s] = 0;
	//Dujkstras' n iterations
	for (int i = 0; i < n; i++) {
		//Finding not used vertex with minimal d[v]
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (used[j] == 0 && (v == -1 || d[j] < d[v]))
				v = j;
		}
		// Termination statement
		if (d[v] == INT_MAX)break;

		used[v] = 1;

		for (int j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first;
			int w = g[v][j].second;
			d[to] = min(d[to], d[v] + w);
		}

	/*	for (int a = 0; a < d.size(); a++)
			cout << d[a] << ' ';
		cout << endl;*/

	}
	int dist = d[f] == INT_MAX ? -1 : d[f];
	cout << dist;
}


