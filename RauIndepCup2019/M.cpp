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
const int N = 500 * 1000 + 123;

struct node {
	int nxt[2];
	int ends;
	int count;

	node(){
		nxt[0] = nxt[1] = -1;
		ends = count = 0;
	}
};

node t[N];
int sz = 1;

void add(string& s){
	int v = 0;
	for(char ch : s){
		int d = ch-'0';
		t[v].count++;

		int next_v = t[v].nxt[d];
		if(next_v == -1){
			next_v = sz;
			t[v].nxt[d] = sz; 
			sz++;
		}

		v = next_v;
	}
	t[v].count++;
	t[v].ends ++;
}

int query(string& s){
	int v = 0;
	int ans = 0;
	for(char ch : s){
		int d = ch - '0';

		int next_v = t[v].nxt[d];
		if(next_v == -1){
			return ans;// + t[v].count;
		}

		v = next_v;
		ans += t[v].ends;
	}
	return ans + t[v].count - t[v].ends;
}

int n,m;
int main() {

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		add(s);
	}

	for(int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << query(s) << endl;
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