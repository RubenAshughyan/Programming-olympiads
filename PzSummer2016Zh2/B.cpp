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


const int N = 1000*1000+7;
const int MOD = 1000*1000*1000 + 7;

int n;
string op;

ll w[N];
ll p[N];

ll oper(ll a, ll b){
    if(op == "AND") return a&b;
    if(op == "OR") return a|b;
    if(op == "XOR") return a^b;
    assert(false);
}


vc<ll> memo(N, -1);
ll f(int c){

    if(memo[c] != -1) return memo[c];
    if(c == 0) return 0;

    ll ans = oper(w[c], w[p[c]]) + f(p[c]);
    ans %= MOD;
    return memo[c] = ans;
}
void solveve(){
    vector<vector<int> > ps(n, vector<int>(17, -1));
    vector<ll> anss(n);
    for (int i = 0; i < n; ++i) {
        if (i) {
            for (int j = 0; j < 17; ++j) {
                ps[i][j] = ps[p[i]][j];
            }
        }
        ll mx = 0;
        for (int k = 0; k < 17; ++k) {
            if (ps[i][k] != -1)
                mx = max(mx, (w[i] & w[ps[i][k]]) + anss[ps[i][k]]);
        }
        anss[i] = mx;
        for (int j = 0; j < 17; ++j) {
            if (w[i] & (1<<j))
                ps[i][j] = i;
        }
    }
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        (ans += (anss[l] + w[l]) % MOD * (l+1)) %= MOD;
    }
    cout << ans << endl;
}
void test(){
    cin >> n >> op;
    loop(i,n) memo[i] = -1;
    loop(i,n) cin >> w[i];
    loop(i,n-1){
        int v = i+1;
        int par;
        cin >> par;
        par--;
        p[v] = par;
    }

    if (op == "AND"){
        solveve();
        return;
    }
    ll ans = 0;
    loop(i,n){
//        db(f(i));
        ans += (i + 1) * (f(i) + w[i]);
        ans %= MOD;
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
100
2 AND
5 5
1

5 AND
5 4 3 2 1
1 2 2 4
5 XOR
5 4 3 2 1
1 2 2 4
5 OR
5 4 3 2 1
1 2 2 4


3
5 AND
5 4 3 2 1
1 2 2 4
5 XOR
5 4 3 2 1
1 2 2 4
5 OR
5 4 3 2 1
1 2 2 4

 */