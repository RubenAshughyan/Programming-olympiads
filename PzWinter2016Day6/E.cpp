//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
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

const ll MOD = 1000000007;
int k;


inline ll mul_n_1(ll x){
    return (x<<k) - x;
}
int num(int r, int nn){
    if (nn == 1)
        return 0;
    if (r >= (nn >> 1)){
        return (num(nn - r - 1, nn >> 1) << 1) + (r & 1);
    }
    else{
        return (num(r, nn >> 1) << 1) + (r & 1);
    }
}
ll n;
long long F(int l, int r) {
    if (r == l)
        return num(l, n);
    if ((l&1)==0){
        if (r&1){
            if ((((r - l) >> 1 ) & 1) == 0)
                return n - 1;
            return 0;
        }
        else{
            ll a;
            a = num(r, n);
            if ((((r - 1 - l) >> 1 ) & 1) ==0)
                return (n - 1) ^ a;
            return a;
        }
    }
    else{
        ll a = num(l, n);
        if (r & 1){
            return a + mul_n_1((r - l) >> 1);
        }
        else{
            return a + mul_n_1(((r - 1 - l) >> 1)) + num(r, n);
        }
    }
}

int main() {
//    for (int j = 0; j < 16; ++j) {
//        cout<<num(j, 16)<<endl;
//    }
    cin >> k;
    int m, l, r;
    cin >> m >> l >> r;
    int a, b, c;
    cin >> a >> b >> c;
    int h = 0;
    n = 1<<k;
    for (int i = 0; i < m; ++i) {
        h = ((l ^ r ^ h ^ F(l, r)) + c) % MOD;
        l = ((l ^ a ^ h) % (n + 1)) % n;
        r = ((r ^ b ^ h) % (n - l)) + l;
    }
    cout << h;
    return 0;
}