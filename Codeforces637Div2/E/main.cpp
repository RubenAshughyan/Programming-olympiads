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


const int N = 10 * 1000 + 5;

int DEBUG = 0;

using namespace std;

void test(int testIndex){

}

int n,m;
int p[N];
int dp[N];

int INF = 2e9+50;

int g,r;
int main() {
    scanf("%d%d",&n,&m);
    loop(i,m){
        scanf("%d",&p[i]);
    }
    sort(p,p+m);

    scanf("%d%d",&g,&r);
    loop(i,m) dp[i] = INF;

    dp[0] = -r;
    for(int i = 1; i < m; i++){
        for(int j = 0; j < i; j++){

            // i->j;
            if(p[i] - p[j] <= g && ((p[i] - p[j]) & 1) == (g & 1)){
                dp[i] = min(
                        dp[i],
                        dp[j] + r + g);

                if(i == m-1 && p[i] - p[j] <= g){
                    dp[i] = min(
                            dp[i],
                            dp[j] + r + (p[i] - p[j])
                            );
                }
            }

        }
    }

//    loop(i,m){
//        cout << dp[i] << ' ';
//    } cout << endl;

    int ans = dp[m-1];
    if(ans == INF) ans = -1;
    cout <<ans << endl;

    return 0;
}


/*
15 5
0 3 7 14 15
11 1

 */



