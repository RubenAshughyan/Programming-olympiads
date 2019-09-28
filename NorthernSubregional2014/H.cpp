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
#define loop1(xxx, yyy) for(int xxx = 1; xxx <= yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
//#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


struct pnt {
    ll x, y, z;

    bool operator==(const pnt &that) {
        return
                x == that.x &&
                y == that.y &&
                z == that.z;
    }

    pnt() {}

    void print() {
        cout << x << ' ' << y << ' ' << z << endl;
    }

    pnt(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

typedef vc<pnt> triangle;

const int N = 2000 + 123;

int n;
pnt A, B;
vc<triangle> ts;

vc<pll > g[N];

triangle makeTr(pnt a, pnt b, pnt c) {
    triangle t(3);
    t[0] = a;
    t[1] = b;
    t[2] = c;
    return t;
}

ll det(pnt a, pnt b, pnt c) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

bool cw(pnt a, pnt b, pnt c) {
    return det(a, b, c) >= 0;
}

bool ccw(pnt a, pnt b, pnt c) {
    return det(a, b, c) <= 0;
}

bool isInsideTriangle(pnt a, pnt b, pnt c, pnt p) {
    return
            (cw(a, b, p) && cw(b, c, p) && cw(c, a, p)) ||
            (ccw(a, b, p) && ccw(b, c, p) && ccw(c, a, p));
}

int findTr(pnt p) {
    loop(i, ts.size()) {
        triangle t = ts[i];
        if (isInsideTriangle(t[0], t[1], t[2], p)) {
            return i;
        }
    }
    assert(false);
}

bool isConnected(triangle a, triangle b, ll &weight) {
    vc<pnt> intersection;
    for (pnt pa : a) {
        bool containsB = false;
        for (pnt pb: b) {
            if (pa == pb) {
                containsB = true;
            }
        }

        if (containsB) {
            intersection.push_back(pa);
        }
    }


    bool areConnected = intersection.size() == 2;
    if (areConnected) {
        weight = min(intersection[0].z, intersection[1].z);
    }
    return areConnected;
}

pnt transition(triangle a, triangle b) {
    vc<pnt> intersection;
    for (pnt pa : a) {
        bool containsB = false;
        for (pnt pb: b) {
            if (pa == pb) {
                containsB = true;
            }
        }

        if (containsB) {
            intersection.push_back(pa);
        }
    }

    if (intersection[0].z > intersection[1].z)
        swap(intersection[0], intersection[1]);
    return intersection[0];
}

int main() {
//    freopen("in.txt","r",stdin);

    cin >> n;
    loop(i, n) {
        pnt a, b, c;
        cin >> a.x >> a.y >> a.z;
        cin >> b.x >> b.y >> b.z;
        cin >> c.x >> c.y >> c.z;

        ts.push_back(makeTr(a,b,c));

    }

    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;


    int ai = findTr(A);
    int bi = findTr(B);

    // makeGraph
    loop(i, n) {
        loop(j, n) {
            if (i != j) {
                ll weight;
                if (isConnected(ts[i], ts[j], weight)) {
                    g[i].push_back({j, weight});
                }
            }
        }
    }


    //dijkstras
    set<pll > st;
    vc<ll> used(n, false);
    vc<ll> d(n, 1e12);
    vc<ll> par(n, -1);

    st.insert({A.z, ai});
    used[ai] = true;
    d[ai] = 0;

    while (!st.empty()) {
        int from = st.begin()->second;
        ll curCost = st.begin()->first;

        if (from == bi) {
            break;
        }

        st.erase(st.begin());

        // relaxes
        for (pll p: g[from]) {
            int to = p.first;
            ll weight = p.second;
            if (!used[to]) {
                if (max(weight, curCost) < d[to]) {
                    st.erase({d[to], to});
                    par[to] = from;
                    d[to] = max(weight, curCost);
                    st.insert({d[to], to});
                }
            }
        }
    }


    vc<triangle> path;

    for (int v = bi; v != -1; v = par[v]) {
        path.push_back(ts[v]);
    }
    reverse(all(path));


    vc<pnt> answer;
    answer.push_back(A);
    for (int i = 0; i + 1 < path.size(); i++) {
        answer.push_back(transition(path[i], path[i + 1]));
    }
    answer.push_back(B);


    vc<pnt> newAns;
    for(pnt p : answer){
        if(newAns.empty() || !(newAns.back() == p)){
            newAns.push_back(p);
        }
    }

    answer = newAns;

    cout << answer.size() << endl;
    for(pnt p : answer){
        p.print();
    }

    return 0;
}

/*
8
1000000 0 0 1000000 1000000 150000 600000 600000 400000
0 1000000 0 600000 600000 400000 600000 1000000 300000
0 1000000 0 400000 300000 150000 600000 600000 400000
400000 0 200000 1000000 0 0 400000 300000 150000
400000 300000 150000 1000000 0 0 600000 600000 400000
600000 600000 400000 1000000 1000000 150000 600000 1000000 300000
0 0 0 400000 0 200000 400000 300000 150000
0 1000000 0 0 0 0 400000 300000 150000
100000 700000 37500
900000 400000 137500

*/