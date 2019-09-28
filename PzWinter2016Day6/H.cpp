#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;

// Graph
set<int> g[N];

// DSU
int parent[N];
int sz[N];

void make_set(int i) {
    parent[i] = i;
    sz[i] = 1;
}

int getPar(int v) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void unite(int u, int v) {
    g[u].insert(v);
    g[v].insert(u);

    u = getPar(u);
    v = getPar(v);
    if (u == v) return;

    if (sz[u] > sz[v]) {
        swap(u, v);
    }

    parent[u] = v;
    sz[v] += sz[u];
}
/////////////////////////////////////

int remap[N];

int getRemap(int v) {
    if (remap[v] == v) {
        return v;
    }
    return remap[v] = getRemap(remap[v]);
}

int GI;
int n;

queue<pii> q[2];
vc<int> comps[2];
vc<pii > edges[2];


void disconnect(int u, int v) {
    g[u].erase(v);
    g[v].erase(u);

    // parallel bfs
    loop(i, 2) {
        comps[i].clear();
        edges[i].clear();
        while (!q[i].empty()) q[i].pop();
    }
    q[0].push({u,-1});
    q[1].push({v,-1});


    int qi = 0;
    while (!q[qi].empty()) {
        int from = q[qi].front().first;
        int par = q[qi].front().second;


        bool added = false;
        for (int to: g[from]) {
            if (to != par) {
                edges[qi].push_back({from, to});
                q[qi].push({to,from});
                g[from].erase(to);
                added = true;
                break;
            }
        }

        if(!added) {
            comps[qi].push_back(from);
            q[qi].pop();
            if(q[qi].empty()) break;
        }

        qi ^= 1;
    }


    // qi finished => is smaller
    vc<int> comp = comps[qi];
    for (int e: comp) {
        make_set(GI);
        remap[e] = GI;
        GI++;
    }

    loop(i, 2){
        for(auto p : edges[i]){
            g[getRemap(p.first)].insert(getRemap(p.second));
        }
    }
    for (auto edge : edges[qi]) {
        unite(getRemap(edge.first), getRemap(edge.second));
    }

}

bool areConnected(int u, int v) {
    return getPar(u) == getPar(v);
}


int main() {
    loop(i, N) remap[i] = i;

    scanf("%d",&n);


    loop(i, n) {
        make_set(i);
    }
    GI = n;

    char s[20];
    while (1) {
        int u, v;
        scanf("%s",s);

        if (s[0] == 'E') return 0;

        scanf("%d%d",&u, &v);

        u--, v--;

        u = getRemap(u);
        v = getRemap(v);

        if (s[0] == 'C') {
            unite(u, v);
        } else if (s[0] == 'D') {
            disconnect(u, v);
        } else if (s[0] == 'T') {
            printf(areConnected(u, v) ? "YES\n" : "NO\n");
            fflush(stdout);
        }
    }
    return 0;
}


/*

 4
 T 1 2
 T 1 3
 T 1 4
 T 2 3
 T 2 4
 T 3 4

 C 2 3

 T 1 2
 T 1 3
 T 1 4
 T 2 3
 T 2 4
 T 3 4

 C 1 2

 T 1 2
 T 1 3
 T 1 4
 T 2 3
 T 2 4
 T 3 4

 D 1 2


 T 1 2
 T 1 3
 T 1 4
 T 2 3
 T 2 4
 T 3 4










 3
C 1 2
C 2 3
T 1 2
D 2 3
D 1 2
T 1 2
E





*/