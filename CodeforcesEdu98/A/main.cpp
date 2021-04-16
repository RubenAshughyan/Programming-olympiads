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


const int N = 1000 * 1000 + 5;

int DEBUG = 0;

using namespace std;

vc<ll> memo(N, -1);

const ll MOD= 998244353;


ll bin_exp(ll base, ll exp){
    if(exp == 0) return 1;

    ll h = bin_exp(base, exp/2);

    h = (h*1ll*h)%MOD;
    if(exp & 1){
        h = (h*base)%MOD;
    }
    return h;
}

ll inv(ll x){
    return bin_exp(x, MOD-2);
}

ll solve(ll n) {
//    db(n);
    if (memo[n] != - 1) return memo[n];

    if(n == 0) return 1;

    ll ans = 0;

    for(int first = 1; 2*first-1 <= n; first++){
        ans += inv(bin_exp(2, 2*first-1)) * solve(n- (2*first-1));
//        ans += solve(n- (2*first-1));
        ans %= MOD;
    }

    return memo[n] = ans;
}

int main() {

    ll n;
    cin >> n;

    vc<ll> fibs = {0,1};
    while (fibs.size() <= n){
        ll nxt = fibs.back() +  fibs[fibs.size()-2];
        nxt %= MOD;
        fibs.push_back(nxt);
    }

    db(fibs.back());
    ll fans = fibs.back()*inv(bin_exp(2, n));
    fans%= MOD;

    cout << fans << endl;

//    cout << solve(n);


//    main();
    return 0;
}


/*

3
3
3 2 2
4
2 2 3 2
3
0 3 0


 */



