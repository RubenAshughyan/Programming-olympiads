
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

int n, m;

struct point {
    dbl x, y, z;
};

dbl R = 6370;

typedef vc<point> polygon;
vc<polygon> polygons;

dbl PI = acos(-1);

dbl toRad(dbl ang) {
    return 2 * PI * ang / 360.0;
}

point pointFromPolar(int t, int l) {
    point p;

    dbl T = toRad(t);
    dbl L = toRad(l);

    p.x = R * cos(T);
    p.y = R * sin(T);
    p.z = R * sin(L);
    return p;
}

point readPoint() {
    int t, l;
    cin >> t >> l;

    return pointFromPolar(t, l);
}

dbl distEuclid(point a, point b) {
    return
            sqrt(
                    SQ(a.x - b.x) +
                    SQ(a.y - b.y) +
                    SQ(a.z - b.z)
            );
}

dbl dist(point a, point b) {
    dbl d = distEuclid(a, b);

    dbl ang = 2 * asin(d / (2 * R));
    return R * ang;
}

bool solveForTwo(dbl a1, dbl b1, dbl c1, dbl a2, dbl b2, dbl c2, dbl& x, dbl& y) {
    dbl det = a1 * b2 - b1 * a2;
    if (det == 0)
        return false;
    x = (c1 * b2 - c2 * b1) / det;
    y = (a1 * c2 - a2 * c1) / det;
    return true;
}

vector<dbl> getSolution(vector<vector<dbl>> sys) {
    vector<dbl> res(3, 0);
    for(int i = 0; i < 3; i++)
        if (sys[0][i] == 0 && sys[1][i] == 0)
        {
            res[i] = 1;
            return res;
        }

    dbl x, y;
    if (solveForTwo(sys[0][1], sys[0][2], sys[0][3],
                sys[1][1], sys[1][2], sys[1][3],
                x, y)) {
        res[0] = 1;
        res[1] = x;
        res[2] = y;
        return res;
    }
    if (solveForTwo(sys[0][0], sys[0][2], sys[0][3],
                    sys[1][0], sys[1][2], sys[1][3],
                    x, y)) {
        res[1] = 1;
        res[0] = x;
        res[2] = y;
        return res;
    }
    if (solveForTwo(sys[0][0], sys[0][1], sys[0][3],
                    sys[1][0], sys[1][1], sys[1][3],
                    x, y)) {
        res[0] = x;
        res[1] = y;
        res[2] = 1;
        return res;
    }
}

point getNormalToSurf(point a, point b) {


}

// Vahagn implemented this
bool areIntersecting(point a, point b, point c, point d, point &intersection) {

}

// returns points of intersection sorted on distance to a
vc<point> getIntersections(point a, point b) {
    vc<pair<dbl, point>> intersectionsWithDist;

    for (polygon pol: polygons) {
        loop(i, pol.size()) {
            point p1 = pol[i];
            point p2 = pol[(i + 1) % pol.size()];

            point intersection;
            if (areIntersecting(a, b, p1, p2, intersection)) {
                intersectionsWithDist.push_back({dist(a, intersection), intersection});
            }
        }
    }

    vc<point> intersections;
    for (auto pr : intersectionsWithDist) {
        intersections.push_back(pr.second);
    }
    return intersections;
}


int main() {
    cin >> n;
    loop(i, n) {
        int k;
        cin >> k;
        polygon p;

        loop(j, k) {
            p.push_back(readPoint());
        }
        polygons.push_back(p);
    }

    vc<point> points;

    cin >> m;
    loop(i, m) {
        points.push_back(readPoint());
    }


    dbl length_ocean = 0;
    dbl length_land = 0;
    int on_land = 1;

    point cur = points.front();

    for (int i = 1; i < points.size(); i++) {
        point nxt = points[i];

        // all intersections the plane meets from cur to nxt
        vc<point> intersections = getIntersections(cur, nxt);

        for (point intersection: intersections) {
            if (on_land) {
                length_land += dist(cur, intersection);
                cur = intersection;
            } else {
                length_ocean += dist(cur, intersection);
                cur = intersection;
            }
            on_land ^= 1;
        }
    }

    dbl total = length_land + length_ocean;

    printf("%.10Lf %.10Lf\n", total, length_ocean / total * 100.0);

    return 0;
}
