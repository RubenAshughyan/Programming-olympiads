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
#define i first
#define j second

//#define ld long double
#define dbl  double
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

struct pnt {
    dbl x, y;

    bool operator <(const pnt &that) const {
        return MP(x,y) < MP(that.x,that.y);
    }

    pnt() {}

    pnt(dbl x, dbl y) : x(x), y(y) {};
};

struct line {
    dbl a, b, c;

    line() {}

    line(pnt P, pnt Q) {
        a = Q.y - P.y;
        b = P.x - Q.x;
        c = a * (P.x) + b * (P.y);
    }
};

const dbl EPS = 1e-9;

dbl det(dbl a, dbl b, dbl c, dbl d) {
    return a * d - b * c;
}

bool intersect(line m, line n, pnt &res) {
    dbl zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
           && abs(det(m.a, m.c, n.a, n.c)) < EPS
           && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

vc<pnt> points;

dbl eq(dbl a, dbl b) {
    return abs(a - b) < EPS;
}

bool eq(pnt a, pnt b) {
    return
            eq(a.x, b.x) &&
            eq(a.y, b.y);
}

struct state {
    int last_seen;
    int i;

    bool operator<(const state &that) const {
        return MP(last_seen, i) < MP(that.last_seen, that.i);
    }

    void pr() {
        printf("(%lf.2 %.lf.2) ls: %d\n", points[i].x, points[i].y, last_seen);
    }

    state() {}

    state(int i, int last_seen) : i(i), last_seen(last_seen) {}
};


int f[4][4];

queue<state> q;
map<state, int> used;
map<state, int> dist;

int gic(int a, int b, int c) {
    return min(a, c) <= b+EPS && b <= max(a, c)+EPS;
}

int gic(pnt a, pnt b, pnt c) {
    dbl det = (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
    if (det != 0) return false;

    return
            gic(a.x, b.x, c.x) &&
            gic(a.y, b.y, c.y);
}

vc<state> get_neighbors(state from) {
    vc<state> res;

    for(int pi = 0; pi < points.size(); pi++){
            state to(pi, from.last_seen);

            vc<int> meet;
            loop(i,4){
                loop(j,4){
                    if (gic(points[from.i], pnt(i,j), points[pi])) {
                        meet.push_back(f[i][j]);
                    }
                }
            }

            sort(all(meet));
            for (int met: meet) {
                if (to.last_seen + 1 == met) {
                    to.last_seen++;
                }
            }

            res.push_back(to);
        }

    return res;
}

int main() {
    vc<pnt> points16;
    loop(i, 4) {
        loop(j, 4) {
            points16.push_back(pnt(i, j));
        }
    }


    for (pnt p1: points16) {
        for (pnt p2: points16) {
            if (!eq(p1, p2)) {
                for (pnt p3: points16) {
                    for (pnt p4: points16) {
                        if(!eq(p3,p4)){
                            pnt inter;
                            if(intersect(
                                    line(p1,p2),
                                    line(p3,p4),
                                    inter
                                    )){
                                points.push_back(inter);
                            }
                        }
                    }
                }
            }
        }
    }

    set<pnt> points_set(all(points));
    points.clear();
    for(pnt p : points_set){
        if(points.empty() || !eq(points.back(), p)){
            points.push_back(p);
        }
    }


//    db(points.size());
//    for(auto p: points){
//        cout << p.x << ' ' << p.y << endl;
//    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> f[i][j];
        }
    }

    loop(pi, points.size()) {

        int last_seen = 0;
        if (eq(points[pi], pnt(0,0))) last_seen = 1;

        state s(pi, last_seen);
        q.push(s);
        used[s] = true;
        dist[s] = 0;
    }

    state from;
    int nodes = 0;
    while (!q.empty()) {
        from = q.front();
        q.pop();

//        cout << endl;
//        from.pr();
//        db(dist[from]);

        if (from.last_seen == 16) {
            break;
        }

        for (state to:get_neighbors(from)) {
            if (!used[to]) {
                used[to] = true;
                dist[to] = dist[from] + 1;
//                db(dist[to]);
                q.push(to);
                nodes++;
            }
        }
    }
//    db(nodes);

//    db(from.last_seen);
    cout << dist[from]-1 << endl;
}

/*

1 2 3 4
10 11 12 5
9 16 6 13
8 7 15 14

 1 2 3 4
8 9 10 11
7 15 16 12
6 14 13 5
*/