#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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


const int N = 300 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dist[N];
void dfsDist(int v, int par = -1, int curDist = 0){
    dist[v] = curDist;
    for(int to : g[v]){
        if(to != par){
            dfsDist(to, v, curDist+1);
        }
    }
}

int d(int a, int b){
    return dist[a] + dist[b] - dist[lca(a,b)];
}

int k;

bool inter1(int a, int x, int )

bool inter(int a, int x, int b, int y) {
    return
        inter1(a, lca(a,x), b, lca(b,y) ) ||
        inter1(x, lca(a,x), b, lca(b,y) ) ||
        inter1(a, lca(a,x), y, lca(b,y) ) ||
        inter1(x, lca(a,x), y, lca(b,y) );
}

bool can(int a, int b, int x, int y){
    if(d(a,y) < d(a,x)) return false;
    if(d(b,y) < d(b,y)) return false;

    // intersect
    if (inter(a,x, y,b) ) return false;
}

int main() {

    cin >> n;
    tin.resize (n),  tout.resize (n),  up.resize (n);
    g.resize(n);

    loop(i,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;

        g[u].PB(v);
        g[v].PB(u);
    }

    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);


    ///
    dfsDist(0);

    int q;
    cin >> q;

    loop(i,q){
        int x,y,a,b;
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        x--;
        y--;
        a--;
        b--;


        if(d(a,b) == k){
            cout << "YES" << endl;
            continue;
        }


        // try a x y b
        if(can(a,b,x,y) || can(b,a,x,y) ){
            cout << "YES" << endl;
            continue;
        } else {
            cout << "NO" << endl;
        }
    }

}








