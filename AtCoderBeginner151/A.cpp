#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second
//
//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pdd pair<dbl,dbl>
#define sz(xxx) ((int)(xxx.size()))
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

using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}

// 4:13

int DEBUG = 0;

using namespace std;

const int N = 100 * 1000 + 5;
const ll MOD = 1000 * 1000 * 1000 + 7;



ll det(pdd a, pdd b, pdd c) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

bool cw(pdd a, pdd b, pdd c) {
    return det(a, b, c) >= 0;
}

bool ccw(pdd a, pdd b, pdd c) {
    return det(a, b, c) <= 0;
}

int n;

vc<pdd> v;

/////
void lineFromPoints(pdd P, pdd Q, dbl &a,
                    dbl &b, dbl &c)
{
    a = Q.y - P.y;
    b = P.x - Q.x;
    c = a*(P.x)+ b*(P.y);
}

// Function which converts the input line to its
// perpendicular bisector. It also inputs the points
// whose mid-point lies on the bisector
void perpendicularBisectorFromLine(pdd P, pdd Q,
                                   dbl &a, dbl &b, dbl &c)
{
    pdd mid_point = make_pair((P.x + Q.x)/2,
                              (P.y + Q.y)/2);

    // c = -bx + ay
    c = -b*(mid_point.x) + a*(mid_point.y);

    dbl temp = a;
    a = -b;
    b = temp;
}

// Returns the intersection point of two lines
pdd lineLineIntersection(dbl a1, dbl b1, dbl c1,
                         dbl a2, dbl b2, dbl c2)
{
    dbl determinant = a1*b2 - a2*b1;
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(1e9, 1e9);
    }

    else
    {
        dbl x = (b2*c1 - b1*c2)/determinant;
        dbl y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

pdd findCircumCenter(pdd P, pdd Q, pdd R)
{
    // Line PQ is represented as ax + by = c
    dbl a, b, c;
    lineFromPoints(P, Q, a, b, c);

    // Line QR is represented as ex + fy = g
    dbl e, f, g;
    lineFromPoints(Q, R, e, f, g);

    // Converting lines PQ and QR to perpendicular
    // vbisectors. After this, L = ax + by = c
    // M = ex + fy = g
    perpendicularBisectorFromLine(P, Q, a, b, c);
    perpendicularBisectorFromLine(Q, R, e, f, g);

    // The point of intersection of L and M gives
    // the circumcenter
    pdd circumcenter =
            lineLineIntersection(a, b, c, e, f, g);

    return circumcenter;
//    if (circumcenter.x == 1e9 &&
//        circumcenter.y == 1e9)
//    {
//        cout << "The two perpendicular bisectors "
//                "found come parallel" << endl;
//        cout << "Thus, the given points do not form "
//                "a triangle and are collinear" << endl;
//    }
//
//    else
//    {
//        cout << "The circumcenter of the triangle PQR is: ";
//        cout << "(" << circumcenter.x << ", "
//             << circumcenter.y  << ")" << endl;
//    }
}

dbl dist2(pdd a, pdd b){
    return SQ(a.x-b.x) + SQ(a.y-b.y);
}
dbl EPS = 1e-6;
int main() {
    cin >> n;

    loop(i,n){
        pdd p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }

    dbl ans = 1e9;

    // same line
    bool sameLine = true;
    for(int i = 2; i < n; i++) {
        if(abs(det(v[0], v[1], v[i])) > EPS){
            sameLine = false;
        }
    }
    if(sameLine){

        ans = 0;
        loop(i,n) loop(j,n) ans = max(ans, dist2(v[i], v[j]));
        ans = sqrtl(ans)/2;
    } else {


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    db(i);
                    db(j);
                    db(k);
                    if (abs(det(v[i], v[j], v[k])) > EPS ) {
                        // check

                        pdd c = findCircumCenter(v[i], v[j], v[k]);

                        dbl rad = dist2(c, v[i]);
                        db(c);

                        bool containsAll = true;
                        for (auto p : v) {
                            if (dist2(c, p) > rad + EPS) {
                                containsAll = false;
                            }
                        }

                        if (containsAll) {
                            ans = min(ans, rad);
                        }

                    }
                }
            }
        }

        ans = sqrtl(ans);

    }

    printf("%.15Lf\n" ,ans);

    return 0;
}

/*

7
1 0 0 5 0 0 2

 */