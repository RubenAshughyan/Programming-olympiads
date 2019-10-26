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
const int N = 5000 + 5;

int n;
const int di = 103993;
const int pi_2 = -5992555;
vector<double> sns;
 
int main() {
	cin >> n;
	int start = pi_2;
	vector<long double> d;
	for (size_t i = 0; i < n; i++)
	{
		cout << start << endl;
		start += di;
	}
	return 0;
}

/*

1
0 0 5

2
3 3 3
6 6 2


*/