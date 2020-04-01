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


const int N = 300 * 1000 + 5;

int DEBUG = 1;

using namespace std;


int parent[N];

int getPar(int v) {
    if (parent[v] == v) return v;
    return parent[v] = getPar(parent[v]);
}

void unite(int u, int v) {
    u = getPar(u);
    v = getPar(v);
    if (u == v) return;

    if (rand() % 2) swap(u, v);

    parent[u] = v;
}

void test(int k) {

    vc<vc<int>> v = {
            {((1 << 18) - 1), ((1 << 18) - 1), k},
            {k,               (1 << 17),       k},
            {0,               k,               k},
    };

    auto dp = v;
    loop(i,3){
        loop(j,3){
            if(i +j == 0) continue;

            int up = i-1 >=0 ? dp[i-1][j]&v[i][j] : 0;
            int left = j-1 >=0 ? dp[i][j-1]&v[i][j] :0;
            dp[i][j] = max(up,left);
        }
    }

//    assert(dp[2][2]


//
    cout << 3 << ' ' << 3 << endl;
    loop(i, 3) {
        loop(j, 3) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int k;
    cin >> k;
    test(k);

    return 0;
}


/*

3
4
1 3 4 2
1 2 2 3
5
2 3 4 5 1
1 2 3 4 5
8
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4



 */



