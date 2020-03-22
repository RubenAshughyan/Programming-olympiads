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

int DEBUG = 1;

using namespace std;

int n, k;
vc<ll> v;

bool check(ll maxDiff) {
    ll need = 0;
    for (int i = 0; i + 1 < n; i++) {
        ll d = v[i + 1] - v[i];
        if (d <= maxDiff) continue;

        if (d % maxDiff) {
            need += d / maxDiff;
        } else {
            need += d / maxDiff-1;
        }
    }

    return need <= k;
}

void test(int testIndex) {

    cin >> n >> k;
    v.clear();

    loop(i, n) {
        ll e;
        cin >> e;
        v.PB(e);
    }


    ll l = 1, r = 1e17;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("Case #%d: %lld\n", testIndex, l);
}

int main() {
    int t;
    cin >> t;
    loop(I, t) test(I + 1);
    return 0;
}


/*

214
2 5 9
10 10 10 10 10
10 10 10 10 10



 */



