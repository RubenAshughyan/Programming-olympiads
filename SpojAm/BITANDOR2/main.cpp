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


int DEBUG = 0;

using namespace std;

const int N = 500 * 1000 + 555;
const int LOGN = 31;

int n, k;
int a[N];


inline int dist(int l, int r) {
    if (l > r) r += n;
    return r - l + 1;
}

int nxt[N];


int dp[N][LOGN];
int sor = 0;

vc<vc<int>> memo(LOGN, vc<int> (N,-1));

int nxt_len(int bt, int i){
    if(memo[bt][i] != -1) return memo[bt][i];

    if( (a[i] >> bt) & 1) return 0;

    int ni = i+1;if(ni >= n) ni = 0;

    return memo[bt][i] = 1 + nxt_len(bt, ni);
}

inline bool can(int pref) {
    if ((sor & pref) != pref) return false;

    // calc next
    loop(i, n) {
        int add =0;
        loop(bt,LOGN){
            if((pref >> bt) & 1){
                add = max(add, nxt_len(bt,i));
            }
        }

        (nxt[i] = i + add);
        if(nxt[i] >= n) nxt[i]-=n;
    }

    // calc bin lift
    loop(i, n) dp[i][0] = dist(i, nxt[i]);

    int h;
    for (int lg = 1; lg < LOGN; lg++) {
        loop(i, n) {
            h = (i + dp[i][lg - 1]);if(h >= n) h-= n;
            dp[i][lg] = dp[i][lg - 1] + dp[h][lg - 1];
            dp[i][lg] = min(dp[i][lg], n+1);
        }
    }

    // for each i check
    loop(i, n) {

        int len = 0;
        int needK = k;
        int v = i;
        for (int lg = LOGN - 1; lg >= 0; lg--) {
            if (needK >= (1 << lg)) {

                len += dp[v][lg];
                if (len > n) break;

                v = (v + dp[v][lg]);
                if(v >= n) v-=n;
                needK -= (1 << lg);
            }
        }

        if (len <= n) return true;
    }

    return false;
}

int main() {

    scanf("%d%d",&n,&k);
    loop(i, n) {
        scanf("%d",&a[i]);
        sor = sor | a[i];
    }

    int pref = 0;
    for (int bit = LOGN - 1; bit >= 0; bit--) {

        // set cur bit
        pref ^= (1 << bit);
        if (!can(pref)) {
            pref ^= (1 << bit);
        }
    }

    printf("%d\n",pref);

    return 0;
}


/*

5 5
2 2 2 2 3

 Մուտք.
4 2
2 3 4 1
Ելք.
3
Մուտք.
6 3
2 2 2 4 4 4
Ելք.
4

 */



