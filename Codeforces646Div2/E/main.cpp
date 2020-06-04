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


const int N = 500 * 1000 + 5;

int DEBUG = 1;

using namespace std;

int n;

int a[N], b[N], c[N];

vc<int> g[N];

void dfsFixCosts(int v, int par = -1){
    if(par != -1) {
        a[v] = min(a[v], a[par]);
    }
    for(int to: g[v]){
        if(to != par){
            dfsFixCosts(to, v);
        }
    }
}


//
ll ans = 0;
pii dfs(int v, int par){

    pii res = MP(0,0);

    if(b[v] == 0 && c[v] == 1) res.first++;
    if(b[v] == 1 && c[v] == 0) res.second++;

    for(int to : g[v]){
        if(to != par){

            pii x = dfs(to, v);



            res.first += x.first;
            res.second += x.second;
        }
    }


    int curChoose = min(res.first, res.second);
    ans += 2LL * curChoose*a[v];

    res.first -= curChoose;
    res.second -= curChoose;

    return res;
}
int main() {
    scanf("%d", &n);
    loop(i, n) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    loop(i, n - 1) {
        int u, v;
        scanf("%d%d",&u,&v);
        u--,v--;

        g[u].PB(v);
        g[v].PB(u);

    }

    // fix costs
    dfsFixCosts(0, -1);


    // solve
    pii res = dfs(0,-1);

//    db(res);

    if(res == MP(0,0)){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;

}


/*

 */



