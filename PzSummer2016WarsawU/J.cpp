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


const int N = 2 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
ll A, B;
vc<pii > points;

pll frac(ll a, ll b) {
    if (b == 0)
        return {1, 0};
    if (a == 0)
        return {0, 1};
    if (b < 0) {
        a = -a;
        b = -b;
    }
    ll g = __gcd(abs(a), abs(b));
    return {a / g, b / g};
}

pll perpendicular(pll ln) {
    return frac(-ln.second, ln.first);
}

pll line(pii p1, pii p2) {
    return frac(p2.second - p1.second, p2.first - p1.first);
}

long double dist(pii p1, pii p2) {
    dbl dx = p1.first - p2.first;
    dbl dy = p1.second - p2.second;
    return sqrt(SQ(dx) + SQ(dy));
}

const long double EPS = 1e-6;
bool check(pii p, pii p2, pii p3) {
    long double s = dist(p, p2) * dist(p, p3) / 2;
    return (A - EPS <= s && s <= B + EPS);
}

int main() {
    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        points.emplace_back(xx, yy);
    }
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        map<pll, vc<int>> mp;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            auto ln = line(points[i], points[j]);
            mp[ln].push_back(j);
        }
        for (auto p: mp) {
            for (int elem:mp[perpendicular(p.first)]) {
                for (int elem2: p.second)
                    if(check(points[i], points[elem2], points[elem])){
                        s++;
                    }
            }
        }
    }
    cout << s / 2 << endl;
    return 0;
}
/*
7 5 25
0 0
2 0
0 2
10 0
0 10
3 3
3 -3
 */