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

void test() {
    ll n, m;
}

ll A, B, C, D;

ll f(ll z) {

    ll nA = max(A, z - C + 1);
    if (nA > B) return 0;

    ll my = max(B, z - nA + 1);
    if (my > C) return 0;

    //
    ll a1 = (C - my + 1);
    ll cnt = B - nA + 1;
    ll mx = C - B + 1;

    // an = a1 + n-1 < mx
    // n = mx - a1
    ll n = min(cnt, mx - a1);
    ll sum = (2 * a1 + n - 1) * n / 2;

    if (n + 1 <= cnt) {
        sum += (cnt - (n + 1) + 1) * mx;
    }

    return sum;
}

int main() {
    cin >> A >> B >> C >> D;


    ll ans = 0;
    for (ll z = C; z <= D; z++) {
        db("");
        db(z);

        ll cont = f(z);

        db(cont);
        ans += cont;
    }

//    int brute = 0;
//    for (int x = A; x <= B; x++) {
//        for (int y = B; y <= C; y++) {
//            for (int z = C; z <= D; z++) {
//                if(x+y > z) brute++;
//            }
//        }
//    }
//    cout << brute << endl;

    cout << ans << endl;

//    main();

    return 0;
}


/*

 */



