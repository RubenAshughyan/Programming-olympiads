#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 1000 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;



void test() {
    int n, m;
    cin >> n >> m;


    ll s1 = 0;
    loop(i, n) {
        ll e;
        cin >> e;
        s1 += e;
    }


    ll s2 = 0;
    loop(i, m) {
        ll e;
        cin >> e;
        s2 += e;
    }

    if (n <= m) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }

    return 0;
}

/*
2
3 2
1 1 1
2 2
1 1
4
3


 */