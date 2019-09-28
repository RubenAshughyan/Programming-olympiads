#include <iostream>
#include <queue>

using namespace std;


struct configuration {
	int a[4];
	int to_int() {
		return 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
	}
};

void find_path(int start, int end, int parents[])
{
	if ((start == end) || (end == -1))
		printf("\n%d", start);
	else {
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}



int test() {
	configuration initial, fina;
	int n_forb,  forbidden[10000];;
	cin >> initial.a[0] >> initial.a[1] >> initial.a[2] >> initial.a[3];
	cin >> fina.a[0] >> fina.a[1] >> fina.a[2] >> fina.a[3];
	cin >> n_forb;
	if(initial.to_int() == fina.to_int()){
	    return 0; 
	}
	for (int i = 0; i < 10000; i++)forbidden[i] = false;
	for (int i = 0; i < n_forb; i++) {
		configuration entry;
		cin >> entry.a[0] >> entry.a[1] >> entry.a[2] >> entry.a[3];
		forbidden[entry.to_int()] = true;
	}
	queue<configuration> q;
	bool discovered[10000];
	int parent[10000];
	int d[10000];
	for (int i = 0; i < 10000; i++) {
		discovered[i] = false;
		d[i] = -1;
		parent[i] = 0;
	}
	q.push(initial);
	discovered[initial.to_int()] = true;
	parent[initial.to_int()] = -1;
	d[initial.to_int()] = 0;
	while (!q.empty()) {
		configuration from = q.front();
		q.pop();
// 		discovered[from.to_int()] == true;
		// Getting the adjacent ones
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 1; j++) {
				int k = 2 * j - 1;
				configuration to = from;
				to.a[i] += k;
				if (to.a[i] == 10) to.a[i] = 0;
				if (to.a[i] == -1) to.a[i] = 9;
				
				if (!discovered[to.to_int()] && to.to_int() >= 0) {
					if (!forbidden[to.to_int()]) {
						q.push(to);
						discovered[to.to_int()] = true;
						parent[to.to_int()] = from.to_int();
						d[to.to_int()] = d[from.to_int()] + 1;
						if (to.to_int() == fina.to_int()) {
							//find_path(initial.to_int(), fina.to_int(), parent);
							return d[to.to_int()];
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cout << test() << endl;
}

/*
2
8 0 5 6
6 5 0 8
5
8 0 5 7
8 0 4 7
5 5 0 8
7 5 0 8
6 4 0 8

0 0 0 0
5 3 1 7
8
0 0 0 1
0 0 0 9
0 0 1 0
0 0 9 0
0 1 0 0
0 9 0 0
1 0 0 0
9 0 0 0

*/
