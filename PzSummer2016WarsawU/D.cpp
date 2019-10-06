#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
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
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 1000 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;


vector<int> order;
vector<set<int>> components;
vector<set<int>> graph;
vector<set<int>> graphR;
int tin[200005], tout[200005];
bool visited[200005];
int which_comp[200005];
int timer = 0;
int n, m, d;

void dfs(int v) {
    tin[v] = timer++;
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    tout[v] = timer++;
    order.PB(v);
}

void dfsRev(int v) {
    which_comp[v] = components.size();
    components.back().insert(v);
    visited[v] = true;
    for (int u : graphR[v]) {
        if (!visited[u]) {
            dfsRev(u);
        }
    }
}

void divideIntoComponents() {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(all(order));
    memset(visited, false, sizeof(visited));
    for (int v : order) {
        if (!visited[v]) {
            components.PB(set<int>());
            dfsRev(v);
        }
    }
}

int main() {
    cin >> n >> m >> d;
    graph.resize(n);
    graphR.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        graph[v].insert(u);
        graphR[u].insert(v);
    }

//    for(int v = 0; v < n; v++) {
//        if (graph[v].size() + graphR[v].size() < d) {
//            for(int u : graph[v]) {
//                graphR[u].erase(v);
//            }
//            graph[v].clear();
//        }
//    }

    divideIntoComponents();

    for (int v = 0; v < n; v++) {
        vector<int> to_del;
        for (int u : graph[v]) {
            if (which_comp[u] != which_comp[v]) {
                to_del.PB(u);
            }
        }
        for (int u : to_del) {
            graph[v].erase(u);
            graphR[u].erase(v);
        }
    }

    for (auto& comp: components) {
        vector<int> to_del;
        for (int v : comp) {
            if (graph[v].size() + graphR[v].size() < d) {
                to_del.PB(v);
            }
        }

        for(int v : to_del) {
            for(int u : graphR[v]) {
                graph[u].erase(v);
            }
            for(int u : graph[v]) {
                graphR[u].erase(v);
            }
            graph[v].clear();
            graphR[v].clear();
            comp.erase(v);
        }
    }
    return 0;
}