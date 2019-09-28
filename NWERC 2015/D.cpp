
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


ll n, r, p;

dbl EPS = 1e-6;

ll f(ll n, ll k) {
    if (n == 1) return 0;

    if (k == 0) return r + p * (n - 1);

    ll m = floor(pow(n, 1.0 / (k + 1)) + EPS);

    return min(f((n + m - 1) / m, k - 1) + p * (m - 1), f((n + m) / (m + 1), k - 1) + p * m) + r;
}

int main() {
    cin >> n >> r >> p;

    ll ans = 1e18;
    for(int i = 0; i < 20; i++){
        ans = min(
                ans,
                f(n,i)
                );
    }
    cout << ans << endl;

    return 0;
}