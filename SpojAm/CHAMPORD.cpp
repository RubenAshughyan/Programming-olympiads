//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
#define length first
#define time second
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


const int N = 20 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n, k;
vc<vc<pair<int, pii>>> G;

vc<vc<pair<int, dbl>>> g;


dbl dpDown[N];
dbl dp[N];

void dfs(int v, int p) {
    dpDown[v] = 0;
    for (auto pr : g[v]) {
        int to = pr.first;
        if (to != p) {
            dfs(to, v);
        }
    }

    // Aggregate results
    vc<dbl> childValues = {0};
    for (auto pr : g[v]) {
        int to = pr.first;
        dbl val = pr.second;
        if (to != p) {
            childValues.PB(dpDown[to] + val);
        }
    }
    dpDown[v] = *max_element(all(childValues));

    sort(all(childValues));
    reverse(all(childValues));
    if (childValues.size() == 0) {
        dp[v] = 0;
    } else if (childValues.size() == 1) {
        dp[v] = childValues.front();
    } else {
        dp[v] = childValues[0] + childValues[1];
    }
}

bool can(dbl x) {

    // Make new g
    g.clear();
    g.resize(n);
    loop(from, n) {
        for (auto pr: G[from]) {
            int to = pr.first;
            int length = pr.second.length;
            int time = pr.second.time;

            g[from].PB({to, x * time - length});
        }
    }

    // get dp
    dfs(0, -1);

    dbl maxPathSum = 0;
    loop(v,n){
        maxPathSum = max(maxPathSum, dp[v]);
    }
    return maxPathSum > 0;
}

int main() {
    scanf("%d%d", &n, &k);
    G.resize(n);

    loop(i, n-1) {
        int u, v, l, t;
        scanf("%d%d%d%d", &u, &v, &l, &t);
        u--, v--;

        G[u].PB({v, {l, t}});
        G[v].PB({u, {l, t}});
    }

    dbl l = 0, r = 1e12;
    loop(ITER, 300) {

        double mid = (l + r) / 2;
        if (can(mid)) {
            r = mid;
        } else {
            l = mid;
        }

    }

    printf("%.10lf", l);


    return 0;
}


/*


4 2
1 2 7 2
2 4 4 6
2 3 4 3


 */



