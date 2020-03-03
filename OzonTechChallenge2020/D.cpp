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


const int N = 1000 + 5;

int DEBUG = 0;

using namespace std;

int n;
vc<int> g[N];


set<int> active;
int par[N];
int farthest(int v){

    queue<int> q;
    vc<int> dist(n+5, -1);
    vc<int> used(n+5, 0);
    loop(i,N) par[i] = -1;

    dist[v] = 0;
    used[v] = 1;
    q.push(v);
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int to : g[from]) {
            if(!used[to] && active.count(to)) {
                used[to] = true;
                dist[to] = dist[from] + 1;
                par[to] = from;
                q.push(to);
            }
        }
    }

    int far = v;
    for(int u: active) {
        if(dist[far] < dist[u]) {
            far = u;
        }
    }
    return far;
}

int ask(int u, int v){
    cout << "? " << u << ' ' << v << endl;
    fflush(stdout);

    int w;
    cin >> w;
    return w;
}

void rem(int v, int p) {
    active.erase(v);

    for(int to : g[v]){
        if(to != p) {
            rem(to, v);
        }
    }
}

int main() {
    cin >> n;
    loop(i,n-1){
        int u,v;
        cin >> u >> v;

        g[u].PB(v);
        g[v].PB(u);
    }


    for(int i = 1; i <= n; i++) {
        active.insert(i);
    }

    while(true){
        if(active.size() == 1){
            cout << "! " << *active.begin() << endl;
            return 0;
        }


        int some = *active.begin();
        int v1 = farthest(some);
        int v2 = farthest(v1);

        db(v1);
        db(v2);

        vc<int> path;
        for(int v = v2; v != -1; v = par[v]) {
            db(v);
            path.push_back(v);
        }
        reverse(all(path));


        dbCont(path);
        int lca = ask(path.front(), path.back());
        db(lca);

        for(int i = 0; i < path.size(); i++){
            if(path[i] == lca){
                if(i+1 < path.size()) rem(path[i+1], lca);
                if(i-1 >= 0) rem(path[i-1], lca);
            }
        }

    }


    return 0;
}


/*

6
1 4
4 2
5 3
6 3
2 3



 */



