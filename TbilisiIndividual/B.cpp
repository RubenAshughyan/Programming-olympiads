
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<iterator>
#include<iterator>
#include<cassert>
#include<cmath>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)

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
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


using namespace std;

bool check1(ll x1, ll x2, ll x3, ll x4) {
    return !(max(x1, x2) >= min(x3, x4) && max(x3, x4) >= min(x1, x2));
}

dbl INF_EPS = 1e-9;


struct PNT {
    ll x, y;

    PNT() {}

    PNT(ll x, ll y) : x(x), y(y) {}

    dbl c_product(PNT b) {
        return x * 1.0L * b.y - y * 1.0l * b.x;
    }

    PNT operator*(int k) {
        return PNT(x * k, y * k);
    }

    PNT operator-(const PNT &b) {
        return PNT(x - b.x, y - b.y);
    }

    PNT operator+(const PNT &b) {
        return PNT(x + b.x, y + b.y);
    }

};



bool on_diff_sides(PNT A, PNT B, PNT C, PNT D) {
    if (check1(A.x, B.x, C.x, D.x) || check1(A.y, B.y, C.y, D.y))
        return false;

    return
            (((B - A).c_product(C - A) >= -INF_EPS && (B - A).c_product(D - A) <= INF_EPS) ||
             ((B - A).c_product(C - A) <= INF_EPS && (B - A).c_product(D - A) >= -INF_EPS))
            && ((((D - C).c_product(B - C)) <= INF_EPS && (D - C).c_product(A - C) >= -INF_EPS) ||
                (((D - C).c_product(B - C)) >= -INF_EPS && (D - C).c_product(A - C) <= INF_EPS));
}

ll MAX = 222222222;

int main() {
    int n;
    cin >> n;
    PNT point1;
    PNT point2;
    PNT point3;
    PNT point4;
    PNT dir;
    loop(i, n) {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &point1.x, &point1.y, &point2.x, &point2.y, &point3.x,
              &point3.y, &point4.x, &point4.y, &dir.x,
              &dir.y);

        bool pred = on_diff_sides(point1, point1 + dir * MAX, point3, point4) ||
                    on_diff_sides(point1, point2, point3, point3 - dir * MAX) ||
                    on_diff_sides(point2, point2 + dir * MAX, point3, point4) ||
                    on_diff_sides(point1, point2, point4, point4 - dir * MAX);
        if (!pred) {
            printf("No\n");
        } else
            printf("Yes\n");

    }
    return 0;
}

/*
 *
2
0 2 1 1 2 2 3 1 1 1
0 2 1 1 2 2 3 1 -1 -1
0 2 1 1 2 2 3 1 1 10
0 2 1 1 2 2 3 1 1 11
0 2 1 1 2 2 3 1 1 12
0 2 1 1 2 2 3 1 -1 -1
 */