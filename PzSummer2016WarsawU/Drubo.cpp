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


const int N = 200 * 1000 + 7;

int n,m,d;
set<int> g[N];

set<int> comp;
int used[N];
void dfs(int v){
    used[v] = 1;
    comp.insert(v);
    for(int to : g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].insert(u);
        g[u].insert(v);
    }


    set<pii> st;
    loop(v,n){
        st.insert({g[v].size(), v});
    }

    while(!st.empty() && st.begin()->first < d){
        int v = st.begin()->second;
        st.erase(st.begin());

        for(int to : g[v]){
            st.erase({g[to].size(), to});
            g[to].erase(v);

            st.insert({g[to].size(), to});
        }
        g[v].clear();
    }

    set<int> answer;
    loop(v,n){
        if(!used[v]){

            comp.clear();
            dfs(v);

            if(answer.size() < comp.size()) answer = comp;

        }
    }

    bool ok = true;
    for(int v : answer){
        ok &= g[v].size() >= d;
    }


    if(ok) {
        cout << answer.size() << endl;
        for (int e: answer) cout << e + 1 << ' ';
    } else {
        cout << "NIE" << endl;
    }

}