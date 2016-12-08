#include<iostream>
#include<queue>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<short> cat(n);
	vector<int> fear(n, 0);
	for (int i = 0; i < n; i++)
		cin >> cat[i];

	vector<vector<int>> g(n);
	//Reading graph
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	//Printing the graph
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < g[i].size(); j++) {
	//		printf("%d is connected to %d with  \n", i, g[i][j]);
	//	}
	//}

	

	//BFS
	int s = 0;
	fear[s] = cat[s];
	queue<int> q;
	//Print cat
	//for (int i = 0; i < cat.size(); i++) printf("%d ", cat[i]); cout << endl << endl;


	vector<short> used(n, 0);
	q.push(s);
	used[s] = 1;
	int rest = 0;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 0; i < g[from].size(); i++) {
			int to = g[from][i];
			if (used[to] == 0) {
				used[to] = 1;
				fear[to] = (fear[from] + cat[to]);
				if (cat[to] == 0)fear[to] = 0;
				//printf("Visiting from %d to %d where the fear is %d\n", from, to, fear[to]);

				//for (int i = 0; i < fear.size(); i++) printf("%d ", fear[i]); cout << endl << endl;
				
				if(fear[to] <= m)
					q.push(to);

				
				if (g[to].size() == 1 && fear[to] <= m)
					rest++;
			}
		}
	}



	cout << rest;

	return 0;
}


/*
5 2 
1 0 0 0 1
1 5
3 1
2 5
4 5

7 3
1 1 1 1 1 1 1
1 2
1 3
2 4
2 5
3 6
7 3

7 2
0 1 0 1 1 1 0
1 2
2 3
3 4
4 5
5 6
6 7

*/
