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


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n,a,r,m;

vc<ll> h;

ll f(ll H){
    if(H >= h.back()) {
        ll sum = 0;
        loop(i,n){
            sum += H-h[i];
        }
        return sum*a;
    }

    // hatuma

    ll verev = 0;
    ll nerqevArat = 0;

    loop(i,n){
        if(h[i] < H){
            nerqevArat += H-h[i];
        } else if(h[i] > H){
            verev += h[i]-H;
        }
    }

    ll moveCount = min(verev, nerqevArat);
    verev -= moveCount;
    nerqevArat -= moveCount;

    ll ans = moveCount * m;

    if(verev > 0){
        ans += verev*r;
    }
    if(nerqevArat > 0){
        ans += nerqevArat*a;
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d",&n,&a,&r,&m);

    m = min(m, a+r);

    h.resize(n);
    loop(i,n){
        scanf("%lld",&h[i]);
    }
    sort(all(h));


    ll l = 0, r = 1e9+2;



//    r = 100;
    while(l+5 < r){
        ll A1 = l + (r-l)/3;
        ll A2 = r - (r-l)/3;

        if(f(A1) < f(A2)) {
            r = A2;
        } else {
            l = A1;
        }
    }

    ll ans = l;
    for(ll i = l; i <= r; i++){
        if(f(ans) > f(i)){
            ans = i;
        }
    }

    cout << f(ans) << endl;



    return 0;
}


/*

 */



