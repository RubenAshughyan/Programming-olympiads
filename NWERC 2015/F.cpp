#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define x first
//#define y second

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

const dbl R = 6370;
//const dbl R = 1.0;

const dbl EPS = 1e-7;
const int INF = 1e9;

dbl PI = acos(-1.0);

dbl toRad(dbl ang) {
    return ang * PI / 180.0;
}

dbl toDeg(dbl rad) {
    return rad * 180.0 / PI;
}

bool eq(dbl a, dbl b) {
    return abs(a - b) < EPS;
}

struct pnt {
    dbl x, y, z;

    pnt() {}

    pnt(dbl x, dbl y, dbl z) : x(x), y(y), z(z) {}

    pnt(dbl fi, dbl lb) {
        fi = toRad(fi);
        lb = toRad(lb);
        z = sin(fi);
        x = cos(lb) * cos(fi);
        y = sin(lb) * cos(fi);
    }

    dbl norm() {
        return sqrt(SQ(x) + SQ(y) + SQ(z));
    }

    dbl dist(pnt b) {
        return pnt(x - b.x, y - b.y, z - b.z).norm();
    }

    pnt cross(pnt b) {
        return pnt(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }

    dbl dot(pnt b) {
        return x * b.x + y * b.y + z * b.z;
    }

    dbl arcDist(pnt b) {
        dbl cosine = dot(b) / (norm() * b.norm());
        dbl angle = acos(cosine);
        return angle;
    }

    bool belongsToArc(pnt p1, pnt p2) {
        return
                eq(
                        arcDist(p1) + arcDist(p2),
                        p1.arcDist(p2)
                );
    }

    bool operator<(const pnt &b) const {
        return MP(x, MP(y, z)) < MP(b.x, MP(b.y, b.z));

    }

    void print() {
        cout << x << ' ' << y << ' ' << z << endl;
    }
};


struct plane0 {
    dbl a, b, c;

    plane0() {}

    plane0(pnt p1, pnt p2) {
        pnt cross = p1.cross(p2);
        a = cross.x;
        b = cross.y;
        c = cross.z;
    }
};

pnt readPoint() {
    dbl fi, lb;
    cin >> fi >> lb;

    return pnt(fi, lb);
}

typedef vc<pnt> polygon;

vc<polygon> polygons;

int gauss(vector<vector<dbl> > a, vector<dbl> &ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

bool areIntersecting(pnt v1, pnt v2, pnt u1, pnt u2, pnt &inter) {

    plane0 p1(v1, v2);
    plane0 p2(u1, u2);


    // if planes coincide
    vc<vc<dbl>> A = {
            {p1.a, p1.b, p1.c, 0},
            {p2.a, p2.b, p2.c, 100},
    };
    vc<dbl> ans;
    if (gauss(A, ans) == 0) {
        return false;
    }

    // else intersect
    A = {
            {p1.a, p1.b, p1.c, 0},
            {p2.a, p2.b, p2.c, 0},
            {1,    1,    1,    70},
    };
    ans.clear();

    int cnt = gauss(A, ans);
//    assert(cnt != 0);
//    dbCont(ans);
    inter.x = ans[0];
    inter.y = ans[1];
    inter.z = ans[2];

    dbl nr = inter.norm();
    inter.x /= nr;
    inter.y /= nr;
    inter.z /= nr;

    // check that belongs to both arcs
    if (
            inter.belongsToArc(v1, v2) &&
            inter.belongsToArc(u1, u2)) {
        return true;
    }

    inter.x *= -1;
    inter.y *= -1;
    inter.z *= -1;
    if (
            inter.belongsToArc(v1, v2) &&
            inter.belongsToArc(u1, u2)) {
        return true;
    }
    return false;
}

vc<pnt> getIntersections(pnt a, pnt b) {
    vc<pair<dbl, pnt>> resWithDist;
    for (polygon pol: polygons) {
        loop(i, pol.size()) {
            pnt inter;
            if (areIntersecting(a, b, pol[i], pol[(i + 1) % pol.size()], inter)) {
//                cout << "intersect" << endl;
                resWithDist.push_back({a.arcDist(inter), inter});
            }
        }
    }

    sort(all(resWithDist));
    vc<pnt> res;
    for (auto p : resWithDist) {
        res.push_back(p.second);
    }
    return res;
}

int main() {
//    freopen("in.txt", "r", stdin);

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

    vc<pnt> route;
    int m;
    cin >> m;
    loop(i, m) {
        route.push_back(readPoint());
    }


    dbl lenLand = 0;
    dbl lenOcean = 0;
    int isLand = 1;

//    cout << "Route : ";
//    for (auto p : route) {
//        p.print();
//    }
//    cout << "--------------" << endl;

    pnt cur = route.front();
    for (int i = 1; i < route.size(); i++) {
        pnt nxt = route[i];
        vc<pnt> intersections = getIntersections(cur, nxt);


        for (pnt inter: intersections) {
            dbl curLen = cur.arcDist(inter);
            if (isLand) lenLand += curLen;
            else lenOcean += curLen;
            isLand ^= 1;

            cur = inter;
        }
        // go to nxt
        dbl curLen = cur.arcDist(nxt);
        if (isLand) lenLand += curLen;
        else lenOcean += curLen;
        cur = nxt;


    }

    lenLand *= R;
    lenOcean *= R;

//    db(lenLand);
//    db(lenOcean);

    dbl total = lenLand + lenOcean;
    dbl perc = lenOcean / total * 100.0;
    printf("%.10Lf %.10Lf\n", total, perc);

    return 0;
}


/*
1
4 -45 0 45 0 45 90 -45 90
5 0 180 0 359 0 160 0 170 0 180


 */

