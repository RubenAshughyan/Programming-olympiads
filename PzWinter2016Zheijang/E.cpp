#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second

//#define ld long double
#define dbl long double
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

const int MAXN = 1000+5;
const int MOD = 1e9 + 7;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    bool operator < (const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    bool operator == (const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    void reduce() {
        int g = __gcd(abs(x), abs(y));
        if (g) x /= g, y /= g;
    }
} points[MAXN], curPoints[MAXN];

int p2[MAXN], n;

void update(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void test() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p2[i] = 2 * p2[i - 1] % MOD;
    }
    sort(points, points + n);
    int ret = 0;

    // Calc starting from i
    loop(i,n){
        int GI = 0, cnt = 0;

        // cnt is how many are equal to ith point
        for (int j = i + 1; j < n; ++j) {
            if (points[j] == points[i]) ++cnt;
            else curPoints[GI++] = points[j] - points[i];
        }
        loop(j, GI) curPoints[j].reduce();
        sort(curPoints, curPoints + GI);
//        db(p2[cnt] - 1);
        // If we choose i-th point, there are cnt other points 2^cnt - 1 (no empty)
        update(ret, p2[cnt] - 1);

        for (int x = 0, y; x < GI; x = y) {
            for (y = x; y < GI && curPoints[x] == curPoints[y]; ++y);
            // now 2^cnt (because empty is allowed )
            update(ret, 1ll * p2[cnt] * (p2[y - x] - 1) % MOD);
        }
    }
    printf("%d\n", ret);
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
3
7
1 1
1 1
1 1
1 1
1 1
1 1
1 1

3
0 0
0 1
1 0
1
0 0

*/