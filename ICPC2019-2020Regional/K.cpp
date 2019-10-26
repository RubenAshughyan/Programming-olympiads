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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define x			first
#define y			second
#define PB			push_back
#define vc			vector
#define MP			make_pair
#define dbCont(x)	cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;
#define db(x)		cout << #x << ": " << x << endl;
#define all(x)		(x).begin(), (x).end()
#define sz(x)		(int)(x).size()
template<class K, class V> ostream& operator << (ostream& out, pair<K, V>& elem) { out << "{" << elem.first << "," << elem.second << "}"; return out; }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 1005;
const int Q = 100 * 1000 + 5;

map<char, pii> cords;

int n, m;
char grid[N][N];
vector<pii> letters;
int upLeft[N][N];
set<int> hor, ver;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", (grid[i] + 1));
		for(int j = 1; j <= m; j++) {
			if (grid[i][j] != '.') {
				cords[grid[i][j]] = MP(i, j);
				letters.PB(MP(i, j));
				hor.insert(i);
				ver.insert(j);
			}
		}
	}
	ver.insert(0);
	ver.insert(m + 1);
	hor.insert(0);
	hor.insert(n + 1);
}

void print() {
	//cout << string(10, '-') << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}


void fillRect(int hr, int vr, int h, int w) {
	if (h < 1 || w < 1) return;
	vector<pii> tmpL;
	for (auto lett : letters) {
		if (hr <= lett.x && lett.x < hr + h && 
			vr <= lett.y && lett.y < vr + w) {
			tmpL.PB(lett);
		}
	}
	sort(all(tmpL));
	vector<vector<pii>> complects;
	int i = 0; 
	while (i < sz(tmpL)) {
		int j = i;
		complects.PB(vector<pii>());
		while (j < sz(tmpL) && tmpL[i].x == tmpL[j].x) {
			complects.back().PB(tmpL[j]);
			j++;
		}
		i = j;
	}
	vector<int> rw;
	for (auto complect : complects) {
		int j = vr, i = complect[0].x;
		while (j < complect[0].y) {
			grid[i][j] = tolower(grid[i][complect[0].y]);
			j++;
		}
		while (j < vr + w) {
			if (grid[i][j] != '.') { j++; continue; }
			grid[i][j] = tolower(grid[i][j - 1]);
			j++;
		}
		rw.PB(i);
	}
	for (int i = hr; i < rw[0]; i++) {
		for (int j = vr; j < vr + w; j++) {
			grid[i][j] = tolower(grid[rw[0]][j]);
		}
	}
	i = rw[0] + 1;
	while (i < hr + h) {
		if (grid[i][vr] != '.') { i++; continue; }
		for (int j = vr; j < vr + w; j++) {
			grid[i][j] = tolower(grid[i - 1][j]);
		}
		i++;
	}
}

void solve() {
	for (int i = 0; i < sz(letters); i++) {
		if (grid[letters[i].x][letters[i].y] == 'A') {
			if (i != 0) {
				swap(letters[i], letters[0]);
			}
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			upLeft[i][j] = (grid[i][j] != '.') + upLeft[i - 1][j] + upLeft[i][j - 1] - upLeft[i - 1][j - 1];

		}
	}

	vector<int> hr(all(hor));
	vector<int> vr(all(ver));
	int ai = cords['A'].x, aj = cords['A'].y;
	int h1, h2, v1, v2;
	vector<int> ans;
	int bestS = 0;
	for (int i = 0; i < sz(hr); i++) {
		for (int j = i + 1; j < sz(hr); j++) {
			if (!(hr[i] < ai && ai < hr[j])) continue;
			for (int k = 0; k < sz(vr); k++) {
				for (int l = k + 1; l < sz(vr); l++) {
					if (!(vr[k] < aj && aj < vr[l])) continue;
					h1 = hr[i];
					h2 = hr[j] - 1;
					v1 = vr[k];
					v2 = vr[l] - 1;
					int pntsInside = upLeft[h2][v2] - upLeft[h2][v1] - upLeft[h1][v2] + upLeft[h1][v1];
					if (pntsInside == 1) {
						if ((h2 - h1) * (v2 - v1) > bestS) {
							bestS = (h2 - h1) * (v2 - v1);
							ans = { h1 + 1, h2 + 1, v1 + 1, v2 + 1 };
						}
					}
				}
			}
		}
	}
	//cout << bestS << endl;
	h1 = ans[0];
	h2 = ans[1];
	v1 = ans[2];
	v2 = ans[3];
	for (int i = h1; i < h2; i++) {
		for (int j = v1; j < v2; j++) {
			if (grid[i][j] != 'A')
				grid[i][j] = 'a';
		}
	}
	h1--;
	v1--;
	h2--;
	v2--;
	//print();
	fillRect(1, 1, h1, v2);
	//print();
	fillRect(h1 + 1, 1, n - h1, v1);
	//print();
	fillRect(h2 + 1, v1 + 1, n - h2, m - v1);
	//print();
	fillRect(1, v2 + 1, h2, m - v2);
	print();
}

int main() {
	input();
	solve();
	return 0;
}

/*

6 8
......X.
.F......
...A....
........
.....P..
..L.....


6 8
.F....X.
........
...A..P.
........
..L.....
........

3 3
...
.Z.
..A

1 1
A


1 4
ABCD

*/