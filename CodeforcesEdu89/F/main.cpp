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

int n,m;
vc<int> a,b;

map<int,int> last;

const int MOD = 998244353;

int main() {
    scanf("%d%d",&n,&m);
    a.resize(n);
    b.resize(m);

    loop(i,n) scanf("%d",&a[i]);
    loop(i,m) scanf("%d",&b[i]);

    for(int e : a){
        if(e < b[0]){
            cout << 0 << endl;
            return 0;
        }
    }

    set<int> aSet(all(a));
    for(int e : b) {
        if (!aSet.count(e)) {
            cout << 0 << endl;
            return 0;
        }
    }

    loop(i, n) last[a[i]] = i;


    // last should e increasing
    for(int j = 0; j+1 < m; j++){
        if(last[b[j]] < last[b[j+1]]) {
            // lave
        } else {
            cout << 0 << endl;
            return 0;
        }
    }

    // doit
    ll ans = 1;
    for(int j = 0; j+1 < m; j++) {
        int i1 = last[b[j]];
        int i2 = last[b[j+1]];

        ll cur = 0;


        vc<int> x;
        for(int i = i1; i <= i2; i++) x.PB(a[i]);

        int len = x.size();


        auto pref = x;
        for(int i = 1; i < len; i++){
            pref[i] = min(pref[i-1], x[i]);
        }

        auto suff = x;
        for(int i = len-2; i >= 0; i--){
            suff[i] = min(suff[i+1], x[i]);
        }

        dbCont(x);
        for(int i = 0; i+1 < len; i++){
            if(pref[i] == a[i1] && suff[i+1] == a[i2]){
                cur++;
            }
        }

        db(i1);
        db(i2);
        db(cur);
        ans *= cur;
        ans %= MOD;
    }
    cout << ans << endl;


    return 0;
}
