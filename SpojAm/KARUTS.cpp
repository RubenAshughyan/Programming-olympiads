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
#define length first
#define time second
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


const int N = 20 * 1000 + 5;

int DEBUG = 0;

using namespace std;


vc<pii > g[4];

int a = 0;
int b = 1;
int c = 2;
int d = 3;
vc<int> globV(4);

void tryFrom(int v) {
    auto A = globV;


    vc<int> res;

    res.PB((v >> 1) & 1);
    res.PB((v >> 0) & 1);

    db(v);

    while (A[0] + A[1] + A[2] + A[3] > 0) {
//        cout << endl;
        dbCont(A);
        db(v);

        int whichCanInc = -1;
        int to;
        for(auto p: g[v]){
            if(A[p.first] > 0 && (whichCanInc == -1 || A[whichCanInc] < A[p.first])){
                whichCanInc = p.first;
                to = p.second;
                break;
            }
        }

        db(whichCanInc);
        if(whichCanInc == -1) return;

        res.PB(to&1);
        A[whichCanInc]--;
        v = to;
    }

    for(int e: res){
        cout << e;
    }
    cout << endl;
    exit(0);
}

int main() {

    // graph
    g[0b00] = {{a, 0b00},{b, 0b01}};
    g[0b01] = {{b, 0b10},{c, 0b11}};
    g[0b10] = {{b, 0b00},{c, 0b01}};
    g[0b11] = {{d, 0b11},{c, 0b10}};


    loop(i, 4) cin >> globV[i];

    dbCont(globV);

    tryFrom(0);
    tryFrom(1);
    tryFrom(2);
    tryFrom(3);

    cout << "IMPOSSIBLE" << endl;


    return 0;
}


/*


4 2
1 2 7 2
2 4 4 6
2 3 4 3


 */



