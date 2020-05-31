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
//#include <random>
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


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;




ll gcd(ll a, ll b){
    if (b==0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}
int f(vc<int> &v){
//    return 0;
    int md = v[0];
    for(int i = 0; i < v.size(); i++){
        md = gcd(md, v[i]);
    }
    return md;
}

bool good(vc<int> v){
//    sort(all(v));
//
//    int md = f(v);
//    do {
//
//        if(f(v) != md) return false;
//
//    }while(next_permutation(all(v)));


    bool ok = true;
    for(int i = 1; i < v.size(); i++){
        if(v[i] % v[0] != 0) return false;
    }
    return true;




    return true;
}

void gen(vc<int> &v){
//    if(v.size() == k){
//        if(good(v)){
//            dbCont(v);
//        }
//    } else {
//        for(int i = 1; i<= n; i++) {
//            if(v.empty() || v.back() < i) {
//                v.PB(i);
//                gen(v);
//                v.pop_back();
//            }
//        }
//    }
}

ll fct[N];
int MOD = 998244353 ;

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

    ll n,k;
    cin >> n >> k;


    precalc();


//    vc<int> v;
//    gen(v);


    ll ans = 0;
    for(int mn = 1; mn <= n; mn++){

        int divs = n/mn;
        divs--;


        db(mn);
        db(divs);



        ans += C(divs, k-1);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}


/*

 */



