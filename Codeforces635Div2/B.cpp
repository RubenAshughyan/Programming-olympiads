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
#define SQ(j) ((j)*(j))
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

const int N = 200 * 1000 + 5;





ll X[N], Y[N], Z[N];
int xN, yN, zN;

ll MX = 3*1e18+3;
ll f1(int xi, int yi){

    ll ans = MX;
    loop(zi, zN){
        ll x = X[xi];
        ll y = Y[yi];
        ll z = Z[zi];

        ll cur = SQ(x-y) + SQ(y-z) + SQ(x-z);
        ans = min(ans, cur);
    }
    return ans;
}

void test() {
    cin >> xN >> yN >> zN;
    loop(i, xN) cin >> X[i];
    loop(i, yN) cin >> Y[i];
    loop(i, zN) cin >> Z[i];

    sort(X, X+xN);
    sort(Y, Y+yN);
    sort(Z, Z+zN);

    ll ans = MX;
    for (int xi = 0; xi < xN; xi++) {
        db(xi);
        int l = 0, r = yN - 1;
        int A, B;
        while (l + 5 < r) {
            A = l + (r - l) / 3;
            B = r - (r - l) / 3;
            if(f1(xi,A) < f1(xi,B)){
                r = B;
            } else {
                l = A;
            }
        }

        int best_yi = l;
        for(int i = l; i <= r; i++){
            if(f1(xi, best_yi) > f1(xi,i)){
                best_yi = i;
            }
        }


        db(best_yi);
        db(f1(xi, best_yi));
        ans = min(ans, f1(xi, best_yi));
        db(ans);

    }

    db(ans);
    cout << ans << endl;
}

int main() {

//    test();
    int t;
    cin >> t;
    loop(i, t) test();


    return 0;
}


/*
2 2 3
7 8
6 3
3 1 4



 8 8
7 5
1 7
6 1
3 7
8 3
2 1
4 5

 */



