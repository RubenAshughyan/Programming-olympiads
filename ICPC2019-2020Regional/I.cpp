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

#define PB			push_back
#define vc			vector
#define MP			make_pair
#define dbCont(x)	cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;
#define db(x)		cout << #x << ": " << x << endl;
#define all(x)		(x).begin(), (x).end()
#define sz(x)		(int)(x).size()
template<class K, class V> ostream& operator << (ostream& out, pair<K, V>& elem) { out << "{" << elem.first << "," << elem.second << "}"; return out; }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 500 + 5;

int n;

vc<pll> ps;

ll INF = 1e12;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y, z;
		cin >> x >> y >> z;

		ps.emplace_back(x, y - z);
		ps.emplace_back(x, y + z);
		ps.emplace_back(x + z, y);
		ps.emplace_back(x - z, y);
	}


	ll min_x = +INF;
	ll min_y = +INF;

	ll max_x = -INF;
	ll max_y = -INF;

	for (auto p : ps) {
		ll x = p.first;
		ll y = p.second;

		min_x = min(min_x, x);
		min_y = min(min_y, y);

		max_x = max(max_x, x);
		max_y = max(max_y, y);
	}

	ll dx = max_x - min_x;
	ll dy = max_y - min_y;

	ll h = max(dx, dy) + 1;
	h /= 2;

	printf("%lld %lld %lld\n", (min_x+max_x)/2, (min_y + max_y) / 2, h);


	return 0;
}

/*

1
0 0 5

2
3 3 3
6 6 2


*/