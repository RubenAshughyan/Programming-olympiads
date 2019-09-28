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
#define dbl  long double
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
const int N = 200 * 1000 + 5;


int n,m;

vc<int> g[N];


vc<dbl> ds;
dbl asdfasdf(vc<dbl> &dists, int start=0){
    if (start + 1 == dists.size()){
        return (3 * dists[start] / 4 + (dists[0] + 2) / 4) + 1;
    }
    return (3 * dists[start] / 4 + asdfasdf(dists, start+1) / 4) + 1;
}
dbl calc(vc<int>& nei){
    vc<dbl> filterd;
    for(int e : nei){
        if(ds[e] < 1e16){
            filterd.PB(ds[e]);
        }
    }
    sort(all(filterd));
    while(filterd[0]+1 < filterd.back()){
        filterd.pop_back();
    }
    return asdfasdf(filterd);
}

int MAX = 1;
vc<int> used(N+123, 0);

int main(){
    cin >> n >> m;
    loop(i,m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    ds = vc<dbl>(n, 1e17);
    ds[n-1] = 0;

    //dijkstra n-1
    set<pair<dbl, int>> st;
    st.insert({ds[n-1], n-1});
    while(!st.empty()){
        int from = st.begin()->second;
        st.erase(st.begin());

        for(int to : g[from]){
            if (used[to] > MAX) {
                continue;
            }
            used[to]++;

//            db(to);
            dbl cur = calc(g[to]);
            if(ds[to] > cur){
                st.erase({ds[to], to});
                ds[to] = cur;
                st.insert({ds[to], to});
            }
        }
    }


    printf("%.12Lf\n", ds[0]);
    return 0;
}