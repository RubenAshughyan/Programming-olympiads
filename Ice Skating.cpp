#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;
vector<pair<int, int>> points;

int index(pair<int, int> p) {
	for (int i = 0; i < points.size(); i++) 
		if (points[i].first == p.first && points[i].second == p.second)
			return i;
	
	return -1;
}

vector < vector<int> > g;
vector <int> used(100,0);



void bfs(int s) {
	//cout << "Comp:";
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		
		int from = q.front();
		q.pop();
		for (int i = 0; i < g[from].size(); i++) {
			int to = g[from][i];
			//If not used
			if (used[to] == 0) {
				used[to] = 1;
				//cout << to << ' ';
				q.push(to);
			}
		}
	}
	//cout << endl;
}

int test() {
	int n;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pair<int, int> p(x, y);
		points.push_back(p);
	}

	//Print points
	//for (int i = 0; i < points.size(); i++) {
		//printf("(%d,%d)\n", points[i].first, points[i].second);
	//}cout << endl;
	
	//Constructing the graph
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			/*If connected*/
			if (points[i].first == points[j].first || points[i].second == points[j].second) {
				int p1 = index(points[i]);
				int p2 = index(points[j]);
				//printf("Const %d is connected to %d\n", p1, p2);
				g[p1].push_back(p2);
			}
		}
	}
	
	//Printing the graph
	//for (int i = 0; i < n; i++) {
		//for (int j = 0; j < g[i].size(); j++) {
			//printf("%d is connected to %d\n", i, g[i][j]);
		//}
	//}

	//Solution
	int c = 0;
	for (int i = 0; i < n; i++) {
		//cout << endl;
		//Not used
		if (used[i] == 0) {
			bfs(i);
			c++;
		}
	}
	cout << c-1;
	return 0;
}

int main() {
	test();
}

