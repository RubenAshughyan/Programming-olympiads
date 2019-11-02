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
#define i first
#define j second

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

const int N = 100 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int fct[N], ifct[N];


int binpow(int n, int k) {
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


int binv(int n) {
    return binpow(n, MOD - 2);
}

void precalc() {
    fct[0] = 1;
    for (int l = 1; l < N; ++l) {
        fct[l] = ((ll) fct[l - 1] * l) % MOD;
        ifct[l] = binv(fct[l]);
    }
}

int C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return ((ll) fct[n] * ifct[k] % MOD) * ifct[n - k] % MOD;
}

int n, k;
vector<int> a, b;

int numpath(int a1, int b1) {
    return C(n - 1 + b1 - a1, n - 1);
}

int calc_simple() {
    ll ans = 1;
    for (int l = 0; l < k; ++l) {
        (ans *= numpath(a[l], b[l])) %= MOD;
    }
    return ans;
}

int calc_inc_exc(int first) {
    ll ans = 1;
    for (int l = first + 1; l < k; ++l) {

    }
}

void solve() {
    cin >> n >> k;
    a = vector<int>(k);
    b = vector<int>(k);
    for (int l = 0; l < k; ++l) {
        cin >> a[l];
    }
    for (int l = 0; l < k; ++l) {
        cin >> b[l];
    }
    sort(all(a));
    sort(all(b));
    ll s = calc_simple();
    ll p = 1;
    for (int m = 0; m + 1 < k; ++m) {
        (s += p * calc_inc_exc(m)) %= MOD;
        (p *= numpath(a[m], b[m])) %= MOD;
    }
    cout << s;
}

int main() {
    precalc();
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k) {
        solve();
    }

    return 0;
}
/*
C 6 3 = 20
C 5 3 = 10
C 7 3 = 35
C 8 3 = 56


*/