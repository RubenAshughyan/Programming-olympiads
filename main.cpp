//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
//#define v first
//#define y second
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

const int N = 100+30;

//2:27
int T,P;
int E[N],D[N],S[N];

int memo[N][N][N];

int solve(int i, int j, int energy){

    if(i == T) return 0;
    if(j == P) return 0;
    if(memo[i][j][energy] != -1) return memo[i][j][energy];


    int ans = 0;

    //solve that
    if(energy >= D[j]) {
        ans = max(ans, S[j] + solve(i, j+1, energy-D[j]));
    }

    // move to next
    ans = max(ans, solve(i,j+1, energy));

    // radeli
    ans = max(ans, solve(i+1, j, E[i+1]));

    return memo[i][j][energy] = ans;
}

int main() {

    return 0;
}


/*


 4
2250 2250
126 126
1 6
6 8


 */


