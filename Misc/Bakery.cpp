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
	int n, m, k;
	scanf_s("%d %d %d", &n, &m, &k);
		
	vector < vector< pair< int,int > > > g(n);

	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		scanf_s("%d %d %d", &v1, &v2, &w);
		pair<int,int> p1(v1-1, w);
		pair<int,int> p2(v2-1, w);
		g[v1-1].push_back(p2);
		g[v2-1].push_back(p1);
	}

	vector<int> cities;
	vector<int> status(n,0);

	for (int i = 0; i < k; i++) {
		int city;
		scanf_s("%d", &city);
		cities.push_back(city-1);
		status[city-1] = 1;
	}

	//Printing the graph
	/*for (int i = 0; i < g.size(); i++) 
		for (int j = 0; j < g[i].size(); j++)
			printf("%d is connected to %d with weight %d\n", i, g[i][j].first, g[i][j].second);
	
	for (int i = 0; i < status.size(); i++) {
		printf("%d ", status[i]);
	}*/

	int res = INT_MAX;
	for (int i = 0; i < cities.size(); i++) {
		int from = cities[i];
		for (int j = 0; j < g[from].size(); j++) {
			int to = g[from][j].first;
			int weight = g[from][j].second;
			if (status[to] != status[from]) {
				res = min(res, weight);
			}
		}
	}
	res = res == INT_MAX ? -1 : res;
	printf("%d\n", res);
}
