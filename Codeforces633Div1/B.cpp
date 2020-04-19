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


ll d,m;
int I;

vc<ll> memo(100,-1);

ll solve(int i){
//    db(i);
    if(memo[i] != -1) return memo[i];

    if(i == 0) return memo[i] = 1;
    ll thisCnt;
    if(i == I){
        thisCnt = 1 + (d ^ (1ll << i));
    } else {
        thisCnt = (1ll << i);
    }

//    db(thisCnt);

    thisCnt %= m;

    ll ans = 0;

    for(int ni = i-1; ni >= 0; ni--){
        ans += thisCnt * solve(ni);
        ans %= m;
    }
    ans += thisCnt;
    ans %+ m;
    return memo[i] = ans;
}

void test(){
    loop(i,100) memo[i] = -1;

    cin >> d >> m;


    I = -1; // most sig bit
    loop(i,60){
        if((d >> i) & 1){
            I = i;
        }
    }


//    db(I);
    ll ans = 0;
    for(int i = 0; i <= I; i++){
        ans += solve(i);
        ans %= m;
    }


//    for(int i = 0; i <= I; i++){
//        cout << i << ' ' << memo[i] << endl;
//    }
//
//

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t) {
        test();
    }
    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

 5
1 1 1 1 1
1 1 1 1 1



 */



