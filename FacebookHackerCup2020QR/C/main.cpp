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


int DEBUG = 1;

const int N = 1000 * 1000 + 5;


using namespace std;




void test(int testIndex) {

    map<ll, vc<ll>> heights;

    int n;
    cin >> n;

    loop(i,n){
        ll pos, height;
        cin >> pos >> height;
        heights[pos].PB(height);
    }


    map<ll,ll> L;

    for(auto [pos, curHeights]: heights){

        for(ll curH: curHeights){

            // aj
            if (!L.count(pos+curH)) {
                L[pos + curH] = pos;
            } else {
                L[pos + curH] = min(L[pos + curH], pos);
            }

            if(L.count(pos)){
                L[pos + curH] = min(L[pos + curH], L[pos]);
            }

            // dzax
            if (!L.count(pos)) {
                L[pos] = pos-curH;
            } else {
                L[pos] = min(L[pos], pos-curH);
            }
            if(L.count(pos-curH)){
                L[pos] = min(L[pos], L[pos-curH]);
            }



        }
    }

//    dbCont(L);

    ll ans = 0;
    for(auto [r,l]: L){
        ans = max(ans, r-l);
    }

    printf("Case #%d: %lld\n", testIndex, ans);

}

int main() {

    int t;
    cin>> t;
    loop(i,t) test(i+1);
    return 0;
}


/*




 */



