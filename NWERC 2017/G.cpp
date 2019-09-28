
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

const int N = 5000;

dbl PI = acos(-1.0);

struct pnt {
    dbl x;
    dbl y;

    pnt() {}

    pnt(dbl x, dbl y) : x(x), y(y) {

    }

};

vc<pnt> getPoints(int k, dbl r) {

    vc<pnt> res;

    loop(i, k) {

        //rotate by angle
        pnt new_P;
        new_P.x = r * cosl((2 * PI * i) / k);
        new_P.y = r * sinl((2 * PI * i) / k);
        res.push_back(new_P);
    }
    return res;
}


dbl EPS = 1e-10;

bool eq(dbl a, dbl b) {
    return abs(a - b) < EPS;
}

int sign(pnt a, pnt b, pnt c) {
    dbl det = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    if (eq(det, 0)) return 0;
    if (det < 0) return -1;
    return +1;
}


bool isInsideTriangle(pnt a, pnt b, pnt c, pnt p) {
    if (sign(a, b, c) * sign(a, b, p) < 0) return false;
    if (sign(a, c, b) * sign(a, c, p) < 0) return false;
    if (sign(b, c, a) * sign(b, c, p) < 0) return false;
    return true;
    return
            (sign(a, b, p) * sign(b, c, p)) >= 0 &&
            (sign(b, c, p) * sign(c, a, p)) >= 0;

}

bool isPointInside(vc<pnt> pol, pnt p) {
    if (pol.size() == 3) {
        return isInsideTriangle(pol[0], pol[1], pol[2], p);
    }

    bool ins = false;
    for (int i = 0; i < pol.size(); i++) {
        ins |= isInsideTriangle(pol[i], pol[(i + 1) % pol.size()], pnt(0, 0), p);
    }
    return ins;
}

int n;
vc<pnt> points;

void pr(pnt p) {
    cout << p.x << ' ' << p.y << endl;
}

bool allInside(dbl r, int k) {
    bool res = true;
    for (pnt p : points) {
        res &= isPointInside(getPoints(k, r), p);
    }
    return res;
}

bool anyInside(dbl r, int k) {
    bool res = false;
    for (pnt p : points) {
        res |= isPointInside(getPoints(k, r), p);
    }
    return res;
}

int main() {
//    for (int k = 3; k <= 8; k++) {
//        auto res = getPoints(k, 1.0);
//        for (auto p : res) {
//            pr(p);
//        }
//        cout << endl;
//
//    }
//

    cin >> n;
    loop(i, n) {
        pnt p;
        cin >> p.x >> p.y;

        points.push_back(p);
    }

    dbl ans = 0;

//    for(dbl r = 0; r < 100; r += 0.1){
//        cout << r << ' ' << allInside(r, 3) << endl;
//        cout << r << ' ' << allInside(r, 4) << endl;
//        cout << r << ' ' << allInside(r, 5) << endl;
//        cout << r << ' ' << allInside(r, 6) << endl;
//        cout << r << ' ' << allInside(r, 7) << endl;
//        cout << r << ' ' << allInside(r, 8) << endl << endl;
//    }
//    return 0;


    int ITER = 100;
    int best_k = -1;
    dbl RB = 1e9;
    for (int k = 3; k <= 8; k++) {
//        db(k);

        dbl l = 0, r = RB, mid;
        loop(iter, ITER) {
            mid = (l + r) / 2;
            if (allInside(mid, k))
                r = mid;
            else
                l = mid;

        }


        dbl LEFT = l;
//        db(LEFT);

        l = 0, r = RB;
        loop(iter, ITER) {
            mid = (l + r) / 2;
            if (anyInside(mid, k))
                r = mid;
            else
                l = mid;

        }

        dbl RIGHT = l;
//        db(RIGHT);


        dbl curRatio = RIGHT / LEFT;
        curRatio *= curRatio;

        if (curRatio > ans) {
            best_k = k;
            ans = max(ans, curRatio);

        }
    }


    printf("%d %.10Lf", best_k, ans);


}
/*

9
-4 -1
-4 6
-3 -6
-3 4
0 -4
2 -3
2 3
5 1
7 0

 4
1 0
0 1
-1 0
0 -1

*/