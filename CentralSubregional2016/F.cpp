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


int n, m;
vector<pii> ls, gr;

const int N = 1000+5;
int par[N];

int findSet(int v){
    if(par[v] == v)
        return v;
    return par[v] = findSet(par[v]);
}

void unite(int v, int u){
    v = findSet(v);
    u = findSet(u);
    if(v == u) return;
    if(rand()%2) swap(u,v);

    par[u] = v;
}

vc<pii> vec;

set<int> small, big;

set<int> intersect1(){
    set<int> res;
    for(int e : small){
        if(big.count(e)){
            res.insert(e);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;

    loop(i,n) {
        par[i] = i;
    }

    for(int i = 0; i < m; i++) {
        char op;
        int u, v;
        cin >> u >> op >> v;
        u--,v--;


        if (op == '=') {
            unite(u,v);
        }
        else {
            if (op == '>') swap(u,v);

            // <
            vec.push_back({u,v});
        }
    }
    for (int j = 0; j < vec.size(); ++j) {
        int u = vec[j].first;
        int v = vec[j].second;
        small.insert(findSet(u));
        big.insert(findSet(v));
    }
    set<int> inter = intersect1();
    vc<char> ans(n,'?');
    for(int x : inter){
        ans[x] = 'R';
    }
    for(pii p: vec){
        int u = findSet(p.first);
        int v = findSet(p.second);
        if(ans[v] == 'R') ans[u] = 'B';
        if(ans[u] == 'R') ans[v] = 'W';
    }
    loop(i,n) cout << ans[findSet(i)]; cout << endl;

    return 0;
}
/*
3
2
1<3
1>2

*/