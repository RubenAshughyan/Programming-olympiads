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
#define pdd pair<dbl, dbl>
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


int n, m, k;
vc<pdd > P;
const dbl EPS = 1e-8;

dbl dist(pdd a, pdd b) {
    return sqrt(SQ(a.x - b.x) + SQ(a.y - b.y));
}

dbl dotProd(pdd a, pdd b) {
    return a.x * b.x + a.y * b.y;
}

pdd pointSub(pdd a, pdd b) {
    return {a.x - b.x, a.y - b.y};
}

dbl normVec(pdd a) {
    return dist(a, {0, 0});
}

bool eq(dbl a, dbl b){
    return abs(a-b) < EPS;
}

bool isParal(int i, int j) {
    pdd p1 = pointSub(P[(i + 1) % n], P[i]);
    pdd p2 = pointSub(P[(j + 1) % n], P[j]);
    if (p1.x == 0) {
        return p2.x == 0;
    }
    if (p2.x == 0) {
        return p1.x == 0;
    }
    if (p1.y == 0) {
        return p2.y == 0;
    }
    if (p2.y == 0) {
        return p1.y == 0;
    }
    return eq(p2.x * p1.y , p1.x * p2.y);
}

pair<dbl, dbl> pointToSeg(pdd p, pdd a, pdd b) {
    dbl d = dist(a, b);
    dbl proj = dotProd(pointSub(p, a), pointSub(b, a)) / d;
    if (proj > d-EPS) {
        return {1e12, dist(p, b)};
    }
    if (proj < EPS) {
        return {1e12, dist(p, a)};
    }
//    db(dist(p, a));
//    db(proj);
    d = sqrt(SQ(dist(p, a)) - SQ(proj));
    return {d, d};
}

int main() {
    cin >> n >> m >> k;
    loop(i, n) {
        pdd p;
        cin >> p.x >> p.y;
        P.push_back(p);
    }

    int det = m + k - n;
    set<int> mk{m, k};

    if (det == 2) {
        dbl minDist = 1e12;
        loop(i, n) {
            for (int add = 2; add <= n - 2; add++) {
                if (mk.count(1 + add)) {
                    int j = (i + add) % n;
                    minDist = min(minDist, dist(P[i], P[j]));
                }
            }
        }
        printf("%.3Lf\n", minDist);
        return 0;
    }

    if (det == 3) {
        dbl minDist = 1e12;
        dbl badMinDist = 1e12;
        loop(i, n) {
            for (int add = 1; add <= n - 2; add++) {
                if (mk.count(2 + add)) {
                    int j = (i + add) % n;
                    pair<dbl, dbl> curDist = pointToSeg(P[i], P[j], P[(j + 1) % n]); //pair<good, bad>
                    minDist = min(minDist, curDist.first);
                    badMinDist = min(badMinDist, curDist.second);
                }
            }
        }
        minDist = min(minDist, badMinDist);
        if (minDist > badMinDist+EPS) {
            cout << -1 << endl;
            return 0;
        }

        printf("%.3Lf\n", minDist);
        return 0;
    }

    if (det == 4) {
        dbl minDist = 1e12;
        dbl badMinDist = 1e12;
        pair<dbl, dbl> curDist;
        loop(i, n) {
            for (int add = 1; add <= n - 1; add++) {
                if (mk.count(add + 2)) {
                    int j = (i + add) % n;
                    bool p = isParal(i, j);
                    curDist = pointToSeg(P[i], P[j], P[(j + 1) % n]); //pair<good, bad>
                    badMinDist = min(badMinDist, curDist.second);
                    if (p)
                        minDist = min(minDist, curDist.first);
                    curDist = pointToSeg(P[(i + 1) % n], P[j], P[(j + 1) % n]); //pair<good, bad>
                    badMinDist = min(badMinDist, curDist.second);
                    if (p)
                        minDist = min(minDist, curDist.first);
                    curDist = pointToSeg(P[j], P[i], P[(i + 1) % n]); //pair<good, bad>
                    badMinDist = min(badMinDist, curDist.second);
                    if (p)
                        minDist = min(minDist, curDist.first);
                    curDist = pointToSeg(P[(j + 1) % n], P[i], P[(i + 1) % n]); //pair<good, bad>
                    badMinDist = min(badMinDist, curDist.second);
                    if (p)
                        minDist = min(minDist, curDist.first);
                }
            }
        }
        if (minDist > badMinDist+EPS) {
//            cout << -1 << endl;
//            return 0;
        }
        minDist = min(badMinDist, minDist);
        printf("%.3Lf\n", minDist);
        return 0;
    }

    cout << -1 << endl;
    return 0;
}



/*
4 4 4
0 0
1 1
2 1
1 0

 4 4 3
 0 0
 0 1
 1 1
 1 0
 */