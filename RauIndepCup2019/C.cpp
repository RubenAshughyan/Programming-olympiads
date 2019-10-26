#include <iostream>
 #include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>

#define all(j) j.begin(), j.end()
#define db(x) cout << #x << ": " << x << endl;
#define dbCont(x) cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;

#define ll long long

using namespace std;
const int N = 500 * 1000 + 123;

const ll max_right = 1000 * 1000 * 1000;
const ll max_left = -1000 * 1000 * 1000;

int n;
ll cur_pos;

bool ask(ll to){
	if (to > max_right)
		to = max_right;
	if (to < max_left)
		to = max_left;
	ll delta = (to - cur_pos);
	cout << delta << endl;
	fflush(stdout);
	string s;
	cin >> s >> cur_pos;
	if (s == "Yes")
		return true;
	return false;
}


int main() {
	cur_pos = 0;
	cin >> n;
	
	int ans = 0;
	while (n--){
		ll pos = cur_pos;
		ll delta = 1;
		ll sign = (rand() % 2) * 2 - 1;
		while (true){
			if (ask(pos + delta * sign))
				break;
			sign *= -1;
			delta <<= 1;
		}
	}
	return 0;
}


/*
4 5
010
1
100
110
0
1
01
01001
11

*/
