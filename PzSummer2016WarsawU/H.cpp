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
//#define i first
//#define j second

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


const int N = 500 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

struct Node {
    ll total, dsum, mini, last_upd, maxi;
    int count;
    bool cut;
} t[4 * N + N / 2];

ll a[N];
int n, m;

void merge(Node &to, Node &left, Node &right) {
    to.total = left.total + right.total;
    to.count = left.count + right.count;
    to.dsum = left.dsum + right.dsum;
    to.mini = left.mini;
    to.maxi = right.maxi;
    to.last_upd = left.last_upd;
    to.cut = false;
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v].total = t[v].mini = t[v].maxi = 0;
        t[v].dsum = a[l];
        t[v].last_upd = 0;
        t[v].count = 1;
        t[v].cut = false;
        return;
    }
    int m = ((l + r) >> 1);
    build((v << 1), l, m);
    build((v << 1) + 1, m, r);
    merge(t[v], t[(v << 1)], t[(v << 1) + 1]);
    t[v].cut = false;
}

void pushCutDown(int v) {
    t[(v << 1) + 1].last_upd = t[(v << 1)].last_upd = t[v].last_upd;
    t[(v << 1)].cut = true;
    t[(v << 1) + 1].cut = true;
    t[(v << 1)].total = t[(v << 1)].count * t[v].mini;
    t[(v << 1) + 1].total = t[(v << 1) + 1].count * t[v].mini;
    t[(v << 1)].maxi = t[(v << 1) + 1].maxi = t[(v << 1)].mini = t[(v << 1) + 1].mini = t[v].mini;
}

void updateSingle(int v, ll minik, ll maxik, ll d) {
    if (t[v].cut) {
        assert(t[v].mini == t[v].maxi);
        pushCutDown(v);
        t[v].cut = false;
    }
    t[v].total += t[v].dsum * (d - t[v].last_upd);
    t[v].mini += minik * (d - t[v].last_upd);
    t[v].maxi += maxik * (d - t[v].last_upd);
    t[v].last_upd = d;
}

ll query(int v, int l, int r, ll d, ll h) {
    if (t[v].count == 0)
        return 0;
    updateSingle(v, a[l], a[r - 1], d);
    if (t[v].maxi < h)
        return 0;
    if (t[v].mini >= h) {
        t[v].last_upd = d;
        t[v].cut = true;
        t[v].mini = h;
        t[v].maxi = h;
        ll result = t[v].total - h * t[v].count;
        t[v].total = h * t[v].count;
        return result;
    } else {
        int m = ((r + l) >> 1);
        ll res = query((v << 1), l, m, d, h) +
                 query((v << 1) + 1, m, r, d, h);
        merge(t[v], t[(v << 1)], t[(v << 1) + 1]);
        return res;
    }
}


void test() {
//    cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
//        cin >> a[i];
        scanf("%lld", &a[i]);

    }
    sort(a, a + n);
    build(1, 0, n);

    for (int j = 0; j < m; ++j) {
        ll d, h;
//        cin >> d >> h;
        scanf("%lld%lld", &d, &h);

        printf("%lld\n",  query(1, 0, n, d, h));
    }
}

int main() {
    int t = 1;
    // cin >> t;
    loop(i, t) {
        test();
    }

    return 0;
}
/*
4 4
1 2 4 3
1 1
2 2
3 0
4 4

16 3
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 1 1
 3 2
 4 8

 */