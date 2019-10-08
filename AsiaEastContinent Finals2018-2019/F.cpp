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
#define dbl  long double
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


const int N = 100 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

dbl sx, sy, sz, tx, ty, tz, ox, oy, oz, r;

void solve() {
    cin >> ox >> oy >> oz >> r;
    cin >> sx >> sy >> sz >> tx >> ty >> tz;

    dbl d1, d2, dst, ang1, ang2, angw;
    d1 = sqrtl(SQ(sx - ox) + SQ(sy - oy) + SQ(sz - oz));
    d2 = sqrtl(SQ(tx - ox) + SQ(ty - oy) + SQ(tz - oz));
    dst = sqrtl(SQ(tx - sx) + SQ(ty - sy) + SQ(tz - sz));
    angw = acosl((SQ(d1) + SQ(d2) - SQ(dst)) / (2 * d1 * d2));
    ang1 = acosl(r / d1);
    ang2 = acosl(r / d2);
    if (ang1 + ang2 >= angw) {
        printf("%.10Lf\n", dst);
    }
    else {
        dbl sh1 = sqrtl(SQ(d1) - SQ(r)),
            sh2 = sqrtl(SQ(d2) - SQ(r));
        printf("%.10Lf\n", sh1 + sh2 + r * (angw - ang1 - ang2));
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
3 2
1 0 0
1 2
1 3


5 3
1 0 1 0 1
 1 2
2 3
4 5

 6 4
 1 1 1 1 0 0
 1 2
 2 3
 3 4
 4 5


 */