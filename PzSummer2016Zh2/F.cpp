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


const int MAXN = 1000*100+7;
const int MOD = 1000*1000*1000 + 7;

vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

set<int> cuts;
void IS_CUTPOINT(int v){
    cuts.insert(v);
}

int n,m;
ll w[MAXN];

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}

ll pr[MAXN];
ll suf[MAXN];

ll prodMinus(int v){
    ll left = 1;
    if(v != 0) left = pr[v-1];


    ll right = 1;
    if(v != n-1) right = suf[v+1];
//    db(left);
//    db(right);

    return (left*right) % MOD;
}

void test() {
    cin >> n >> m;
    cuts.clear();

    loop(i,n){
        g[i].clear();
        used[i] = false;
        fup[i] = 0;
        tin[i] = 0;
    }

    ll sum = 0;
    loop(i,n){
        cin >> w[i];
        sum += w[i];
    }

    pr[0] = w[0];
    for(int i = 1; i < n; i++){
        pr[i] = pr[i-1] * w[i];
        pr[i] %= MOD;
    }
    suf[n-1] = w[n-1];
    for(int i = n-2; i >= 0; i--){
        suf[i] = suf[i+1]*w[i];
        suf[i] %= MOD;
    }

    loop(i,n){
//        db(pr[i]);
//        db(suf[i]);
    }

    loop(i,m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }




    timer = 0;
    int c = 0;
    for (int i=0; i<n; ++i) {
        if (!used[i]) {
            c++;
            dfs(i);
        }
        used[i] = false;
    }


    ll ans = 0;
//    db(c);
    if(c == 1){
        loop(v,n){
            ll cur ;
            if(cuts.count(v)){
                cur = (sum - w[v] + MOD) % MOD;
            } else {
//                cout << "prod" << endl;
                cur = prodMinus(v);
            }
//            db(cur);
            ans += (v+1)*cur;
            ans %= MOD;
        }

    }
    else if (c == 2){
        loop(v,n){
            ll cur ;
            if(g[v].size() == 0){
                cur = prodMinus(v);
            } else {
                cur = (sum - w[v] + MOD) % MOD;
            }
            ans += (v+1)*cur;
            ans %= MOD;
        }
    } else {
        loop(v,n){
            ll cur ;
            cur = (sum - w[v] + MOD) % MOD;
            ans += (v+1)*cur;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}


int main() {
    int t;
    cin >> t;
    loop(i,t){
        test();
    }

    return 0;
}

/*
1
3 0
1 2 3



 */