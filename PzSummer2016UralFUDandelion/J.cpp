#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second

//#define ld long double
#define dbl long double
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

const int N = 2 * 100 * 1000 + 5;

int n, m;

struct neigh {
    int v, id;
    int len;
    int lum;

    neigh(int v, int id, int len, int lum) : v(v), id(id), len(len), lum(lum) {

    }

    neigh() {}
};

vc<neigh> g[N];
int start, finish;

struct edge {
    int id, from, to, lum;
    ll min_dist;

    edge(int id, int from, int to, int lum) : id(id), from(from), to(to), min_dist(LONG_LONG_MAX), lum(lum) {}
};

int indx = 0;
vc<edge> edges;

void add_edge(int v, int u, int len, int lum) {
    g[v].emplace_back(u, indx, len, lum);
    g[u].emplace_back(v, indx + 1, len, lum);
    edges.emplace_back(indx, v, u, lum);
    edges.emplace_back(indx + 1, u, v, lum);
    indx += 2;
}

ostream& operator << (ostream& out, pll& elem) {
    out << "{" << elem.first << ", (" << edges[elem.second].from << ", " << edges[elem.second].to << ")" << "}";
    return out;
}

int previous[1000000];

bool used[1000000];

int main() {
    scanf("%d%d", &n, &m);
    // clear
    memset(previous, -1, sizeof(previous));
    loop(i, m) {
        int u, v, lum, len;
        scanf("%d%d%d%d", &u, &v, &len, &lum);
        u--, v--;

        add_edge(u, v, len, lum);
        if (u == 1)
            add_edge(u, v + n, len, lum);
        else if (v == 1)
            add_edge(u + n, v, len, lum);
        else
            add_edge(u + n, v + n, len, lum);
    }

//    for(int i = 0; i < edges.size(); i++) {
//        db(edges[i].id);
//        db(edges[i].from);
//        db(edges[i].to);
//    }

    start = 0;
    finish = n;
    priority_queue<pair<ll, int>> st;

    for(int i = 0; i < g[start].size(); i++) {
        edges[g[start][i].id].min_dist = g[start][i].len;
        st.emplace(-g[start][i].len, g[start][i].id);
    }


    int id, to_id, i, nd;
    ll dst;
    while(!st.empty()) {
        id = st.top().second;
        dst = -st.top().first;
        // dbCont(st);
        st.pop();

        if(edges[id].to == finish) break;

        if (edges[id].min_dist != dst)
            continue;
        used[id] = true;
        nd = edges[id].to;

        for(i = 0; i < g[nd].size(); i++) {
            to_id = g[nd][i].id;
            if (!used[to_id] && edges[to_id].lum >= edges[id].lum && edges[id].min_dist + g[nd][i].len < edges[to_id].min_dist) {
                edges[to_id].min_dist = edges[id].min_dist + g[nd][i].len;
                previous[to_id] = id;
                st.emplace(-edges[to_id].min_dist, to_id);
            }
        }
    }

    ll ans = LONG_LONG_MAX;
    int ind = -1;
    for(i = 0; i < edges.size(); i++) {
        if (edges[i].to == finish) {
            if (edges[i].min_dist < ans) {
                ind = i;
                ans = edges[i].min_dist;
            }
        }
    }
    printf("%lld\n", ans);
    stack<int> indices;
    while(true) {
        indices.push(ind);
        if (edges[ind].from == 0) break;
        ind = previous[ind];
    }
    while(!indices.empty()) {
        int idd = indices.top();
        printf("%d ", idd / 4 + 1);
        indices.pop();
    }
    cout << endl;
//
//    // dijk
//    // dist, vertex, prev, ind
//    set<pair<pll, pll>> st;
//    st.insert({{0, 0}, {-1, -1}});
//    while(!st.empty()){
//        int from = st.begin()->first.second;
//        int prev = st.begin()->second.first;
//        int ind = st.begin()->second.second;
//
//        for(auto nei: g[from]){
//            int v = nei.v;
//            int lum = nei.lum;
//            int len = nei.len;
//
//
//        }
//    }




    return 0;
}


/*
3 3
1 2 5 1
1 3 4 2
2 3 6 9
 */