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

#define all(j) j.begin(), j.end()
#define db(x) cout << #x << ": " << x << endl;
#define dbCont(x) cout << #x << ": "; for(auto xxx : x) cout << xxx << ' '; cout << endl;

#define ll long long

using namespace std;
const int N = 100005;
int n;
ll dpl[N], dpr[N], mhl[N], mhr[N], a[N];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mhl[0] = a[0];
	for(int i = 1; i < n; i++) {
		dpl[i] = dpl[i - 1];
		if (a[i] <= mhl[i - 1]) {
			mhl[i] = mhl[i - 1] + 1;
			dpl[i] += (mhl[i] - a[i]);
		}
		else {
			mhl[i] = a[i];
		}
	}
	mhr[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		dpr[i] = dpr[i + 1];
		if (a[i] <= mhr[i + 1]) {
			mhr[i] = mhr[i + 1] + 1;
			dpr[i] += (mhr[i] - a[i]);
		}
		else {
			mhr[i] = a[i];
		}
	}
	ll ans = 1000000000000000000ll;
	for(int i = 0; i < n - 1; i++) {
		if (mhl[i] == mhr[i + 1]) {
			ans = min(ans, dpl[i] + dpr[i + 1] + 1);
		}
		else {
			ans = min(ans, dpl[i] + dpr[i + 1]);
		}
	}
	cout << min(ans, min(dpl[n - 1], dpr[0])) << endl;
	return 0;
}


/*
6 3
1 2 1 2 3 4

14 3
3 4 1 1 1 2 3 1 2 1 1  5 6 7

8 5
1 1 2 2 3 3 4 4


*/