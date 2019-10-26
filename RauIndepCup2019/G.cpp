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


ll n,p;
map<ll,ll> mp;

bool can(ll k){
	if(k == 0) return true;

	ll sum = 0;
	for(auto pr: mp){
		ll have = pr.second;
		have = min(have, k);

		sum += have;
	}
	return sum / k >= p; 
}

int main() {
	cin >> n >> p;


	for(int i = 0; i < n; i++){
		ll e;
		cin >> e;
		mp[e]++;
	}

	ll l = 0, r = 1e8, mid;
	while(l < r){
		ll mid = (l+r+1)/2;
		if(can(mid)){
			l = mid;
		} else {
			r = mid-1;
		}
	}

	cout << l << endl;

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