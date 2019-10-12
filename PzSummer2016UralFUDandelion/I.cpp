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


int n;
vc<pll > points;

bool cmp(pll a, pll b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(pll a, pll b, pll c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pll a, pll b, pll c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pll > &a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp);
    pll p1 = a[0], p2 = a.back();
    vector<pll > up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < a.size(); ++i) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (size_t i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (size_t i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
}

ll dist(pll &A, pll &B) {
    return SQ(A.x - B.x) + SQ(A.y - B.y);
}

bool check(pll a, pll b){

    pll o = {(a.x+b.x)/2, (a.y+b.y)/2};

    ll R = dist(o, a);

    int sum = 0;
    for(auto p : points){
        if(dist(p,o) <= R){
            sum++;
        }
    }
    return sum == n;
}

map<pll, int> indexOf;

int main() {
    scanf("%d", &n);
    loop(i, n) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        x *= 2;
        y *= 2;

        indexOf[{x,y}] = points.size()+1;

        points.push_back({x,y});
    }

    convex_hull(points);

    n = points.size();

//    db(n);

    map<int, vc<int>> farthest;

    loop(i, n) {
        pll curPoint = points[i];
        ll l = 1, r = n - 1;
        while (r - l >= 5) {
            ll A = l + (r - l) / 3;
            ll B = r - (r - l) / 3;
            pll pA = points[(i + A) % n];
            pll pB = points[(i + B) % n];
            if (dist(curPoint, pA) < dist(curPoint, pB)) {
                l = A;
            } else {
                r = B;
            }
        }

        ll maxDist = 0;
        for (int j = l; j <= r; j++) {
            ll curDist = dist(curPoint, points[(i + j) % n]);
            maxDist = max(maxDist, curDist);
        }
        for (int j = l; j <= r; j++) {
            ll curDist = dist(curPoint, points[(i + j) % n]);
            if (curDist == maxDist) {
                farthest[i].push_back((i + j) % n);
            }
        }
    }

    ll maxDist = 0;
    loop(i,n){
        for(int j : farthest[i]){
            ll curDist = dist(points[i], points[j]);
            maxDist = max(maxDist, curDist);
        }
    }

//    db(maxDist);

    vc<pii> sax;
    loop(i,n){
        for(int j : farthest[i]){
            ll curDist = dist(points[i], points[j]);
            if(curDist == maxDist && i < j){
                sax.push_back({i,j});
            }
        }
    }



    if(!check(points[sax[0].first],points[sax[0].second])){
        cout << 0 << endl;
    } else {
        cout << sax.size() << endl;
        for(auto p : sax){
            cout << indexOf[points[p.first]] << ' ' << indexOf[points[p.second]] << endl;
        }
    }

    return 0;
}
/*
4
0 0
1 0
0 1
1 1

3
0 0
0 10
5 8
*/