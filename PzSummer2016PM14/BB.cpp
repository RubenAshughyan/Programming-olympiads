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
#define X first
#define Y second

//#define ld long double
#define dbl long double
#define pll pair<long long,long long>
#define pdd pair<dbl,dbl>
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


const int N = 1000 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, k;
dbl myX = 0.2, myY = 99.6;

int BS = 28;

bool ask(vc<pdd > points) {
    //////////////////////////////////////////////
//    loop(i, points.size() - 1) {
//        pdd a = points[i];
//        pdd b = points[i + 1];
//
//        int D = 20000;
//        loop(j, D + 1) {
//            pdd c = {a.X + (b.X - a.X) * j / D, a.Y + (b.Y - a.Y) * j / D};
//
//            dbl dist = SQ(myX - c.X) + SQ(myY - c.Y);
//            if (dist <= 1) return true;
//        }
//
//    }
//    return false;
    //////////////////////////////////////////////


    cout << points.size();
    for (auto p: points) {
        printf(" %.10Lf %.10Lf", p.X, p.Y);
    }
    cout << endl;
    fflush(stdout);

    int response;
    cin >> response;
    return response;
}

bool checkHorizontal(dbl down, dbl up) {
//    if(min(down, up)-1 > myY || max(down,up)+1 < myY ) {
//        return false;
//    }
//    return true;

    vc<pdd > v;

    dbl x = 0;
    loop(i, 50) {
        v.push_back({x, down});
        v.push_back({x + 2, down});
        v.push_back({x + 2, up});
        x += 2.0;
    }
//    v.push_back({100, down});

    return ask(v);
}
dbl otherY, cX, cY;

bool checkVertical(dbl l, dbl r) {
    if (l > r)
        swap(l, r);
    vc<pdd > v;

    v.push_back({0, otherY});
    v.push_back({l, otherY});
    v.push_back({l, cY});
    v.push_back({r, cY});
    v.push_back({r, otherY});
    v.push_back({100, otherY});
    return ask(v);
}

pdd solve() {

    dbl down = 0, up = 100, mid;

    bool reverse = false;

    if (ask(vc<pdd >{{0,   0},
                     {100, 0}})) {
        up = 0;
        down = 2;
        reverse = true;
    }

    loop(iter, BS) {
        mid = (down + up) / 2;
//        db(down);
//        db(mid);
        if (checkHorizontal(mid, down)) {
//            cout << "up" << endl;
            up = mid;
        } else {
//            cout << "down" << endl;
            down = mid;
        }
    }


    cY = down + 1;
    if (reverse) {
        cY = down - 1;
    }
//    db(cY);


    //////////////////////////////////////////////////
    // center's Y is known
    dbl l = 0, r = 100;


    otherY = 100;
    if (cY > 50) {
        otherY = 0;
    }
    reverse = false;

    if (ask(vc<pdd >{{0,   cY},
                     {0,   otherY},
                     {100, otherY}})) {
        reverse = true;
        l = 2;
        r = 0;
    }

    loop(iter, BS) {
        mid = (l + r) / 2;
        if (checkVertical(l, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cX = l + 1;
    if (reverse) {
        cX = l - 1;
    }

    return {cX, cY};
//    printf("0 %.10Lf %.10Lf\n", cX, cY);

}


int main() {
    pdd c = solve();
    printf("0 %.10Lf %.10Lf\n", c.X, c.Y);
    return 0;


//    myX = (rand() % 100000) / 1000.0;
//    myY = (rand() % 100000) / 1000.0;
    myX = 89.3540000000;
    myY = 16.4480000000;


    pdd p = solve();
    cout << "-----------------------------------------------" << endl;
    printf("pahel %.10Lf %.10Lf\n", myX, myY);
    printf("found %.10Lf %.10Lf\n", p.X, p.Y);
    if (abs(myX - p.X) > 1e-6 || abs(myY - p.Y) > 1e-6) {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        exit(0);
    }

    main();
}


/*
pahel 89.3540000000 16.4480000000
found 89.3540183306 16.4541015625

 */