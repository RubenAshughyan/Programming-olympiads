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

const int N = 1000 * 1000 + 5;

int n;
vc<ll> v;

int main() {
    scanf("%d",&n);

    map<ll,ll> cnt;
    loop(i,n){
        ll e;
        scanf("%lld",&e);
        v.PB(e);
        cnt[e]++;
    }

    sort(all(v));


    ll ans = 0;
    ll eq = 0;
    for(auto p: cnt){
        ll l2 = p.first;


        ll lWays = (cnt[l2] * (cnt[l2]-1)) / 2;

        eq += (cnt[l2]* (cnt[l2]-1) * (cnt[l2]-2)) / (1*2*3);

        // base < 2*l2
        ll baseCnt = lower_bound(all(v), 2*l2) - v.begin() - cnt[l2];

//        cout << "\n\n" << endl;
        db(l2);
        db(eq);
        db(lWays);
        db(baseCnt);
        ans += lWays*baseCnt;
    }

    db(ans);
    db(eq);
    cout << ans+eq << endl;

    return 0;
}


/*
......qQ
.......b
........
........
........
........
........
........


 */



