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
const int N = 500 + 5;

int n;

int x[N][N];

int g[N][N];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			x[i][j] = s[j] - '0';
		}
	}


	for (int len = 1; len <= n; len++) {
		for (int a = 0; a+len < n; a++) {
			int s = 0;
			for (int k = a; k < a + len; k++) {
				if (!g[a][k])
					continue;
				(s += x[k][a + len]) %= 10;
			}

			if (s % 10 != x[a][a + len]) {
				g[a][a + len] = 1;
			}
		}

	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j];
		}
		cout << endl;
	}
	return 0;
}

/*

2
00
00

2
01
00

3
012
001
000

3
011
001
000

5
01113
00012
00001
00001
00000


*/