#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
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
const int N = 200 * 1000;

//int n, m;
//
//vector<vector<int>> gp;
//vi c;
//
//void input() {
//	cin >> n >> m;
//	gp.resize(n);
//	for (int i = 0; i < n - 1; i++) {
//		int u, v;
//		cin >> u >> v;
//		u--;
//		v--;
//		gp[u].PB(v);
//		gp[v].PB(u);
//	}
//	for (int i = 0; i < m; i++) {
//		int cc;
//		cin >> cc;
//		c.PB(cc);
//	}
//	if (m == 1) {
//		cout << c[0] << endl;
//		exit(0);
//	}
//}
//
//vector<int> path;
//bool visited[N];
//bool ed = false;
//
//void dfs(int v) {
//	if (v == c[1]) {
//		ed = true;
//		return;
//	}
//	for (int u : gp[v]) {
//		if (!visited[u]) {
//			
//		}
//		
//	}
//}
//
//void solve() {
//	
//}

int n;
unordered_map<int, int> mp;

int a[N];
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		//cin >> a[i];
		scanf("%d", &a[i]);
	}
	mp.clear();
	mp[a[0]]++;
	
	ll ans = 0;
	for (int j = 1; j < n; j++) {

		for (int k = j + 1; k < n; k++) {
			int ai =- ( a[k] - 2 * a[j]);
			ans += mp[ai];
		}
		mp[a[j]]++;
	}
	//db(ans);
	printf("%lld\n", ans);
}

int main() {
	// input();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}

/*
4
5
1 2 1 2 1
3
30 20 10
5
1 2 2 3 4
9
3 1 4 1 5 9 2 6 5


*/