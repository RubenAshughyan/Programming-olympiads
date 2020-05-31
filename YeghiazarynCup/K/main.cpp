#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
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
//
//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define pii pair<int,int>
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


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;

ll Ax,Ay,Vax,Vay;
ll Bx,By,Vbx,Vby;
ll T;

void lineFromPoints(pdd P, pdd Q, dbl &a, dbl &b, dbl &c)
{
     a = Q.second - P.second;
     b = P.first - Q.first;
     c = -(a*(P.first) + b*(P.second));

//    if(b<0)
//    {
//        cout << "The line passing through points P and Q is: "
//             << a << "x " << b << "y = " << c << endl;
//    }
//    else
//    {
//        cout << "The line passing through points P and Q is: "
//             << a << "x + " << b << "y = " << c << endl;
//    }
}

dbl EPS = 1e-8;

dbl dist(pdd a, pdd b) {
    return sqrt(SQ(a.x - b.x) + SQ(a.y - b.y));
}

ll vx, vy;



void doit(pdd ket) {
    dbl d = dist(MP(Bx,By), ket);
    dbl t = d / dist(MP(0,0), MP(vx,vy));



    if(t < -EPS || t > T+EPS){
        cout << -1 << endl;
        exit(0);
    }


    pdd hand = MP(Bx+t*vx, By+t*vy);

    // iroq handipum en
    if(dist(hand, MP(0,0)) < 2+EPS){
        printf("%.10Lf\n", t);
    } else {
        cout << -1 << endl;
    }

    exit(0);
}
int main() {
    cin >> T;
    cin >>  Ax >> Ay >> Vax >>Vay;
    cin >>  Bx >> By >> Vbx >>Vby;

    Bx -= Ax;
    By -= Ay;

    Vbx -= Vax;
    Vby -= Vay;

    vx = Vbx;
    vy = Vby;

    if(SQ(Bx) + SQ(By) <= 4){
        cout << 0 << endl;
        exit(0);
    }

    db(vx);
    db(vy);
    if(vx == 0 && vy == 0){
        if(SQ(Bx) + SQ(By) <= 4){
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    dbl a,b,c;
    lineFromPoints(MP(Bx,By), MP(Bx+vx, By+vy), a,b,c);

    dbl r = 2;

    dbl x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS) {
        db("no point");
        cout << -1 << endl;
    }else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        db("one point");

        doit(MP(x0,y0));
    }
    else {
        db("two point");


        dbl d = r*r - c*c/(a*a+b*b);
        dbl mult = sqrt (d / (a*a+b*b));
        dbl ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
//        puts ("2 points");


        pdd p1 = MP(ax,ay);
        pdd p2 = MP(bx,by);

        pdd B = MP(Bx,By);

        pdd ket = p1;
        if(dist(p2,B) < dist(p1,B)){
            ket = p2;
        }

        doit(ket);

    }



    return 0;
}


/*

5
2 0 0 1
0 7 0 -1


 2
0 0 1 1
8 8 -1 -1


 2
-3 -1 2 3
4 2 -1 2



 */




