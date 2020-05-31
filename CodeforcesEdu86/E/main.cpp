#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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


const int N = 200 * 1000 + 300;

int DEBUG = 1;

using namespace std;

ll fct[N];
int MOD = 998244353;

ll binpow(ll n, ll k) {
    if (k == 1)
        return n;
    if (k == 0)
        return 1;
    ll a = binpow(n, k / 2);
    a *= a;
    a %= MOD;
    if (k % 2 == 1)
        a *= n;
    a %= MOD;
    return a;
}


ll binv(ll n) {
    return binpow(n, MOD - 2);
}

void precalc() {
    fct[0] = 1;
    for (int l = 1; l < N; ++l) {
        fct[l] = ((ll) fct[l - 1] * l) % MOD;
    }
}

ll C(ll n, ll k) {
    if (k < 0 || k > n)
        return 0;

//    db(fct[n]);
    return ((ll) fct[n] * binv(fct[k]) % MOD) * binv(fct[n - k]) % MOD;
}


int main() {
    precalc();

    ll n,k;
    cin >> n >> k;

    if(k == 0){
        cout << fct[n] << endl;
        return 0;
    }

    ll distinct = n-k;
    if(distinct <= 0){
        cout << 0 << endl;
        return 0;
    }

    db(distinct);
    db(n);

    db(C(n,distinct));

    ll ans = (C(n,distinct)* fct[distinct]) % MOD;

    cout << (2*ans)%MOD << endl;


    return 0;
}


/*
15 5
0 3 7 14 15
11 1

 */



