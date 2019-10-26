#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<iterator>
#include<iterator>
#include<cassert>
#include<bitset>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PB			push_back
#define MP			make_pair
#define dbCont(x)	cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;
#define db(x)		cout << #x << ": " << x << endl;
#define all(x)		(x).begin(), (x).end()
#define sz(x)		(int)(x).size()
template<class K, class V> ostream& operator << (ostream& out, pair<K, V>& elem) { out << "{" << elem.first << "," << elem.second << "}"; return out; }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 200 * 1000 + 5;

int n, m;

vector<vector<int>> gp;
vi c;

void input() {
	cin >> n >> m;
	gp.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		gp[u].PB(v);
		gp[v].PB(u);
	}
	for (int i = 0; i < m; i++) {
		int cc;
		cin >> cc;
		cc--;
		c.PB(cc);
	}
	if (m == 1) {
		cout << "YES" << endl;
		cout << c[0] + 1 << endl;
		exit(0);
	}
}

vector<int> path;
bool visited[N];
bool ed = false;
int midp = -1;

void bfsFindMid() {
	vector<int> dist(n, 0), prev(n, -1);
	queue<int> q;
	q.push(c[0]);
	prev[c[0]] = c[0];
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : gp[u]) {
			if (prev[v] == -1) {
				prev[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	int dst = c[0];
	for (int cc : c) {
		if (dist[dst] < dist[cc]) {
			dst = cc;
		}
	}

	vector<int> path;
	while (dst != c[0]) {
		path.PB(dst);
		dst = prev[dst];
	}
	path.PB(dst);
	reverse(all(path));
	if (sz(path) & 1) {
		midp = path[sz(path) / 2];
	}
}

void solve() {
	bfsFindMid();
	if (midp == -1) {
		cout << "NO" << endl;
	}
	else {
		vector<int> dist(n, 0);
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		visited[midp] = true;
		queue<int> q;
		q.push(midp);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			
			for (int u : gp[v]) {
				if (!visited[u]) {
					visited[u] = true;
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}

		for (int i = 0; i < sz(c) - 1; i++) {
			if (dist[c[i]] != dist[c[i + 1]]) {
				cout << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl << midp + 1 << endl;
	}
}

int main() {
	input();
	solve();

	return 0;
}

/*
6 3
1 2
2 3
3 4
4 5
4 6
1 5 6


2 2
1 2
1 2


*/