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
#define y0 ngacaleiebinvoaeu
#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

int n;

vc<pll> points;

dbl PI = acosl(-1);

dbl getV(dbl alp){
    dbl dx = points.back().x - points.front().x;
    dbl dy = points.back().y - points.front().y;
    dbl v = dx/cosl(alp) * sqrtl(5/ (dx*tanl(alp) - dy));
    return v;
}

const dbl EPS = 0.0000001;
bool upper(dbl A, dbl B, pii p){
    dbl x = p.x - points.front().x;
    dbl val = A*x*x + B*x;
    return val > (p.y - points.front().y - EPS);
}

bool hatv(pii p1, dbl A, dbl B){
    return !upper(A,B, p1);
}

bool check(dbl alp){
    dbl dx = points.back().x - points.front().x;
    dbl dy = points.back().y - points.front().y;

    if(dx * tanl(alp) <= dy){
        return false;
    }

    dbl v = getV(alp);

    // stugel chhatvel
    bool ok = true;
    dbl A = -5.0 / (SQ(v*cosl(alp)) );
    dbl B =  tanl(alp);
    for(int i = 0;  i < points.size(); i++){
        // TODO
        if(hatv(points[i], A,B)){
            ok = false;
            break;
        }
    }

    return ok;
}
dbl findAlp(int j){
    dbl x1 = points[j].x - points[0].x;
    dbl x2 = points.back().x - points[0].x;
    dbl y1 = points[j].y - points[0].y;
    dbl y2 = points.back().y - points[0].y;
    return atanl(y1 * x2 / x1 / (x2 - x1) - y2 * x1 / x2 / (x2 - x1));
}
int main() {
    cin >> n;
    loop(i,n){
        pii p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    dbl dx = points.back().x - points.front().x;
    dbl dy = points.back().y - points.front().y;
    dbl lla = atanl(dy /dx);
    dbl l, r = PI/2;
    l = (r + lla) / 2;
    dbl ansv = getV(l);
    for (int j = 1; j < points.size() - 1; ++j) {
        dbl alp = findAlp(j);
        if (alp > l)
            ansv = max(ansv, getV(alp));
    }
    assert (0 <= ansv && ansv <= 1e18);
    printf("%.10Lf\n",ansv);
    return 0;
}

/*
6
1 2
4 4
5 0
6 3
8 4
11 2


 3
0 0
1 3
5 2

 2
 0 0
 10 0

*/