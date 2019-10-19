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

const int MOD = 998244353;
const int N = 500 * 1000 + 5;

vc<pll> g[N];
int n,k;
ll memo[N][2];

ll solve(int v, int chosen, int par){
    if(memo[v][chosen] != -1){
        return memo[v][chosen];
    }

    vc<pll> childs;
    for(pll pr : g[v]){
        int to = pr.first;
        ll w = pr.second;
        if(to != par){
            childs.push_back({w,to});
        }
    }

    sort(all(childs));

}

void test()
{
    cin >> n >> k;

    set<pair<ll, pii>> st;

    loop(i,n-1) {
        int u, v, w;
//        cin >> u >> v >> w;
scanf("%d%d%d",&u,&v,&w);
        u--,v--;

        st.insert({-w, {u,v}});
    }


    vc<int> deg(n,0);

    ll ans = 0;
    while(!st.empty()){
        int w = -st.begin()->first;
        int v = st.begin()->second.first;
        int u = st.begin()->second.second;
        st.erase(st.begin());


        if(deg[v] < k && deg[u] < k){
            deg[v]++;
            deg[u]++;
            ans += w;

        }

    }


    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }
}
/*
1
 8
100 200 100 200 100 200 100 100
10 2
15 3
107


 3 0
 0 0 0
*/