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

const dbl PI = acos(-1.0);

dbl EPS = 1e-9;

bool eq(dbl a, dbl b) {
    return abs(a - b) < EPS;
}

struct pnt {
    dbl x, y;


    static dbl det(pnt p1, pnt p2, pnt p3) {
        return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    }

    static dbl area2(pnt p1, pnt p2, pnt p3) {
        return abs(det(p1, p2, p3));
    }

    static bool ccw(pnt a, pnt b, pnt c) {
        return det(a, b, c) > EPS;
    }

    static bool cw(pnt a, pnt b, pnt c) {
        return det(a, b, c) < -EPS;
    }

    pnt(dbl _x, dbl _y) : x(_x), y(_y) {}

    pnt() {}

    dbl norm() {
        return sqrt(x * x + y * y);
    }

    pnt normalized() {
        pnt A = *this;
        dbl no = A.norm();
        if (eq(no, 0.0)) return A;
        A.x /= no;
        A.y /= no;
        return A;
    }

    pnt rotated(dbl a) {
        pnt A(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
        return A;
    }

    pnt operator+(const pnt &b) const {
        return pnt(x + b.x, y + b.y);
    }

    pnt operator-(const pnt &b) {
        return pnt(x - b.x, y - b.y);
    }

    pnt operator*(const dbl k) {
        return pnt(x * k, y * k);
    }

    dbl dist_to_line(pnt a, pnt b) {
        if (!ccw(a, b, *this) && !cw(a, b, *this))
            return 0.0;
        dbl h = area2(*this, a, b) / (b - a).norm();
        return h;
    }

    pnt proj(pnt a, pnt b) {
        if (!ccw(a, b, *this) && !cw(a, b, *this))
            return *this;
        dbl h = dist_to_line(a, b);
        pnt perp(-(b - a).y, (b - a).x);
        perp = perp.normalized();
        pnt ans1 = *this + perp * h;
        if (!ccw(a, b, ans1) && !cw(a, b, ans1)) {
            return ans1;
        }
        return *this + perp * (-h);
    }

    void pr() {
        printf("[%.2Lf, %.2Lf]", x, y);
    }
};

dbl a, b;

bool check(pnt p1, pnt p2, pnt p3) {


    // suppose p2,p3 are on b (base)
    pnt pr = p1.proj(p2, p3);

    bool ok1 =
            (p1 - pr).norm() < a + EPS &&
            max((p2 - pr).norm(), (p3 - pr).norm()) < b + EPS;


    // suppose p2,p3 are on a
    pr = p1.proj(p2, p3);

    bool ok2 =
            max(
                    (p2 - pr).norm(),
                    (p3 - pr).norm()
            ) < a + EPS &&

            (pr - p1).norm() < b + EPS &&

            !eq(
                    (pr - p3).norm() +
                    (pr - p2).norm(),

                    (p3 - p2).norm()

                    );


    return ok1 || ok2;
}

void test() {
    pnt p1, p2, p3;

    cin >> a >> b;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

//    db(abs(pnt::det(p1, p2, p3)));
    if (abs(pnt::det(p1, p2, p3)) < EPS) {
        dbl maxLen = 0;

        maxLen = max(maxLen, (p1 - p2).norm());
        maxLen = max(maxLen, (p1 - p3).norm());
        maxLen = max(maxLen, (p2 - p3).norm());

//        db(maxLen);

        if (maxLen < max(a, 2*b) + EPS) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    // no on same line
    if (
            check(p1, p2, p3) ||
            check(p2, p1, p3) ||
            check(p3, p1, p2)
            ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    int n;
    cin >> n;
    loop(i, n) {
        test();
    }
    return 0;
}

/*
1000


12 4
1 5
4 1
9 7

2 1
1 1
5 1
3 3

12 4
1 5
4 1
9 7

2 1
1 1
5 1
3 3

1 6
0 1
1 0
3 3


100 100
2 1
3 0
50 50

100 0
1 3
2 4
70 72


 100 100
 0 0
 1 1
 2 2



 */