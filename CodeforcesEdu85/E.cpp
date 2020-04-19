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
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
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


const int N = 1000 * 1000 + 50;
const int INF = 1e9;
int DEBUG = 0;

using namespace std;


int dt[N];

int t[4*N];
int lazy[4*N];

void push(int v, int l, int r) {
    if (l != r) {
        lazy[2*v+1] += lazy[v];
        lazy[2*v+2] += lazy[v];
    }
    t[v] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        lazy[v] = 0;
        t[v] = dt[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid + 1, r);

        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
}

int get_max(int v, int l, int r, int ql, int qr) {
    if (lazy[v] > 0) {
        push(v, l, r);
    }

    // total
    if (ql <= l && r <= qr) {
        return t[v];
    }

    // no overlap
    if (ql > r || l > qr) {
        return -INF;
    }

    int mid = (l + r) / 2;
    return max(
            get_max(2 * v + 1, l, mid, ql, qr),
            get_max(2 * v + 2, mid + 1, r, ql, qr)
    );
}

void update(int v, int l, int r, int ql, int qr, int add) {
    if (lazy[v] > 0) {
        push(v, l, r);
    }

    // total overlap
    if (ql <= l && r <= qr) {
        lazy[v] += add;
        push(v, l, r);
        return;
    }

    // no overlap
    if (ql > r || l > qr) {
        return;
    }


    int mid = (l + r) / 2;
    update(2 * v + 1, l, mid, ql, qr, add);
    update(2 * v + 2, mid + 1, r, ql, qr, add);

    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

int n, m, p;

vc<pii > cleanUP(vc<pii > a) {
    map<int, vc<int>> mp;
    for (auto p : a) {
        mp[p.first].PB(p.second);
    }

    vc<pii > b;
    for (auto p : mp) {
        b.PB({p.first, *min_element(all(p.second))});
    }
    return b;
}

// value, cost
vc<pii > a;
vc<pii > b;

vc<pair<pii, int>> monsters;

void print(){
    if(!DEBUG) return;

    loop(i,100) {
        cout << get_max(0,0,N-1, i,i) << ' ';
    }
    cout << endl;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);


    loop(i, n) {
        int value, cost;
        scanf("%d%d", &value, &cost);
        a.PB({value, cost});
    }
    loop(i, m) {
        int value, cost;
        scanf("%d%d", &value, &cost);
        b.PB({value, cost});
    }

    a = cleanUP(a);
    b = cleanUP(b);

    dbCont(a);
    dbCont(b);



    // fill data
    loop(i, N) dt[i] = -INF;
    for (int i = b.size() - 1; i >= 0; i--) {
        db(b[i]);
        for (int j = b[i].first; j >= 0 && (i - 1 < 0 || j > b[i - 1].first); j--) {
            dt[j] = -b[i].second;
        }
    }

    build(0, 0, N - 1);

    db("built")

    print();

    // monsters
    loop(i, p) {
        int x, y, cost;
        scanf("%d%d%d", &x, &y, &cost);
        x++;
        y++;
        monsters.PB({{x, y}, cost});
    }
    sort(all(monsters));


    dbCont(monsters);


    // can kill first
    bool can = false;
    for(auto mons: monsters) {
        if(a.back().first >= mons.first.first && b.back().first >= mons.first.second){
            can = true;
        }
    }
    if(!can) {
        cout << -(a.front().second + b.front().second) << endl;
        return 0;
    }

    // for all a's
    int mi = 0;

    int ans = -INF;
    for (auto p: a) {
        int curX = p.first;
        int curACost = p.second;
        db("");
        db(curX);
        db(curACost);

        while (mi < monsters.size() && monsters[mi].first.first <= curX) {

            // add monster[mi] to structure
            db(monsters[mi]);
            update(0, 0, N - 1, monsters[mi].first.second, N - 1, monsters[mi].second);

            mi++;
        }


        // ask for max
        int mx = get_max(0, 0, N - 1, 0, N - 1);

        db(mx);

        ans = max(ans, mx - curACost);
    }

    cout << ans << endl;


    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

2 3 3
2 3
4 7
2 4
3 2
5 11
1 2 4
2 1 6
3 4 6



 */



