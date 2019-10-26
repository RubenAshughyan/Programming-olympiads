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
const int N = 200 * 1000 + 5;
const int Q = 100 * 1000 + 5;


int n, q;
int a[N];

vc<int> memo(1000 * 1000 + 5, -1);
vc<int> ps;
int mx;


int solve(int t) {
	int &memoVal = memo[t];
	if (memoVal != -1) return memoVal;
	if (t < mx) return -1;

	int steps = 0;
	
	vc<int>::iterator cur = ps.begin();

	while (cur != ps.end()) {
		steps++;

		auto it = upper_bound(all(ps), t + *cur);
		if (it == ps.end()) break;
		
		cur = it - 1;
	}

	memoVal = steps;
	memo[t] = steps;
	return steps;
}

int main() {
	scanf("%d", &n);

	mx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}

	ps.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);

		int ans = solve(t);
		//db(ans);

		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("Impossible\n");
	}
	return 0;


}

/*

6
4 2 3 1 3 4
8
10 2 5 4 6 7 8 8


*/