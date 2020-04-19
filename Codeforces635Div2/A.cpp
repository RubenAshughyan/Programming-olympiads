#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


int DEBUG = 0;

using namespace std;

const int N = 300 * 1000 + 5;


ll n, k, a, b;
vector<ll> g[N];
vector<ll> A;
bool visited[N] = {false};

void dfs(int node, int lvl) {
    ll counter = 0;
    if (visited[node]) return;
    visited[node] = 1;

    for (auto child: g[node]) {
        if (!visited[child]) {
            counter++;
            dfs(child, lvl + 1);
        }
    }
    if (!counter) {
        A.push_back(lvl + 1);
    }
}

int main() {
    cin >> n >> k;
    loop(i, n - 1) {
        cin >> a >> b;
        g[b].PB(a);
        g[a].PB(b);

    }
    dfs(1, 0);
    sort(all(A));
    vector<ll> cp;
    for (auto elem: A) cp.push_back(elem);

    while (k) {
        sort(cp.begin(), cp.end());
        for (int i = cp.size() - 1; i >= 0; i--) {
            k--;
            cp[i]--;
            if (k < 1) break;
        }
    }
    sort(cp.begin(), cp.end());
    //for (auto elem: cp) cout << elem << " ";cout << endl;
    ll s = 0;
    for (int i = A.size(); i >= 0; i--) {
        s += cp[i] * (A[i] - cp[i]);
    }
    if (k > cp.size()) s -= cp.size() * (k - cp.size());

    return 0*printf(""%max(s, (ll) 0) << endl;;
}


/*

7
100 3 4
189 3 4
64 2 3
63 2 3
30 27 7
10 9 1
69117 21 2



 */



