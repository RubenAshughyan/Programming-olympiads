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


const int N = 14+4;

int DEBUG = 1;

using namespace std;


int n;
int p[N][N];

ll ans[1<<N];
ll memo[1<<14+4][14];

int _needMsk;

ll solve(int freeMsk, int last){
    if(memo[freeMsk][last] != -1) {
        return memo[freeMsk][last];
    }

    int busy = n;
    loop(i,n) busy -= ((freeMsk>>i)&1);
    if(busy == n) return memo[freeMsk][last]=1;


    // choose next
    int relation = (_needMsk>>(busy-1))&1;
    ll ans = 0;
    loop(nxt, n){
        if((freeMsk >> nxt) & 1) {
            if(p[last][nxt] == relation){
                ans += solve(freeMsk^(1<<nxt), nxt);
            }
        }
    }
    return memo[freeMsk][last] = ans;
}

int main() {
//    cin >> n;
//    loop(i,n){
//        string s;
//        cin >> s;
//        loop(j,n) p[i][j] = (s[j]=='1');
//    }

    n = 14;
    loop(i,n){
        for(int j = i; j < n; j++){
            p[i][j] = p[j][i] = rand()%9==0;
        }
    }

    int full = (1<<n)-1;
    for(int needMsk = 0; needMsk < (1 << (n - 1)); needMsk++){
        _needMsk = needMsk;
        loop(i, (1<<n)){
            loop(j,n){
                memo[i][j] = -1;
            }
        }


        // brute first
        loop(f, n){
            ll cur = solve(full^(1<<f), f  );
            ans[_needMsk] += cur;
//            if(cur < 0){
//                db(cur);
//                db((full^(1<<f)));
//                db(f);
//                exit(0);
//            }
        }

    }


    loop(i, (1 << (n - 1))) {
        printf("%lld ", ans[i]);
    }
    cout << endl;

    return 0;
}


/*





 */



