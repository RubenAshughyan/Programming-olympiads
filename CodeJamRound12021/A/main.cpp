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

int n,k;

vc<pii> ranges;
vc<ll> v;


ll f(int ri){
    int l = ranges[ri].first;
    int r = ranges[ri].second;

    int length = r-l+1 - 2;
    if(length <= 0) return 0;

    // ezrayin
    if(l == 0 || r == k+1){
        return length;
    }

    return (length+1)/2;
}


ll f_single(int ri){
    int l = ranges[ri].first;
    int r = ranges[ri].second;

    int length = r-l+1 - 2;
    if(length <= 0) return 0;

    // ezrayin
    if(l == 0 || r == k+1){
        return length;
    }

    return length;
}

void test(int testIndex){
    ranges.clear();
    cin >> n >> k;


    set<int> st;
    loop(i,n){
        int e;
        cin >> e;
        st.insert(e);
    }
    v = vc<ll>(all(st));

    dbCont(v);

    for(int i = 0; i+1 < v.size(); i++){
        ranges.PB(MP(v[i], v[i+1]));
    }
    ranges.PB(MP(0,v.front()));
    ranges.PB(MP(v.back(), k+1));

    ll ans = 0;
    // for all pairs of ranges
    for(int i = 0; i < ranges.size(); i++){
        for(int j = i; j < ranges.size(); j++){
            ll curAns = 0;
            // diff ranges
            if(i != j){
                curAns = f(i) + f(j);
            } else {
                curAns = f_single(i);
            }
            ans = max(ans, curAns);

            db(ranges[i]);
            db(ranges[j]);
            db(curAns);

        }
    }

    dbl p = (ans+0.0) / (k);

    printf("Case #%d: %.10lf\n", testIndex, p);
}

int main() {
    int t;
    cin >> t;
    loop(I,t) test(I+1);
    return 0;
}


/*

4
3 10
1 3 7
4 10
4 1 7 3
4 3
1 2 3 2
4 4
1 2 4 2


 1
4 3
1 2 3 2

 */
