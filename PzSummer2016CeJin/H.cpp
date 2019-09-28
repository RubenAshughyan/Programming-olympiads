//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
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


const ll N = 1000 * 100 + 7;

struct node {
    ll mn, mx, sum, lazy;
} t[4 * N];

ostream &operator<<(ostream &out, node &d) {
    out << d.mn << " " << d.mx << " " << d.lazy << " " << d.sum;
    return out;
}

void inline merge(node &to, node &a, node &b) {
    to.mn = min(a.mn, b.mn);
    to.mx = max(a.mx, b.mx);
    to.sum = a.sum + b.sum;
    to.lazy = 0;
}

void inline push_down(int v, int szl, int szr) {
    int v1 = (v<<1);
    if (t[v].mn == t[v].mx) {
        t[v1].mn = t[v1 + 1].mn = t[v1].mx = t[v1 + 1].mx = t[v].mx;
        t[v1].lazy = t[v1 + 1].lazy = 0;
        t[v1].sum = szl * t[v].mn;
        t[v1 + 1].sum = szr * t[v].mn;
        return;
    } else {
        t[v1].mn += t[v].lazy;
        t[v1].mx += t[v].lazy;
        t[v1 + 1].mn += t[v].lazy;
        t[v1 + 1].mx += t[v].lazy;
        t[v1].lazy += t[v].lazy;
        t[v1].sum += (szl * t[v].lazy);
        t[v1 + 1].sum += (szr * t[v].lazy);
        t[v1 + 1].lazy += t[v].lazy;
        t[v].lazy = 0;
    }
}

ll a[N];

void printTree(int v, int l, int r) {
    if (l == r - 1) {
        db(v);
        db(t[v]);
        return;
    }

    int m = ((l + r) >> 1);
    printTree((v << 1), l, m);
    printTree((v << 1) + 1, m, r);
    db(v);
    db(t[v]);
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v].mn = t[v].mx = t[v].sum = a[l];
        t[v].lazy = 0;
//        db(v);
//        db(t[v]);
        return;
    }

    int m = (l + r) >> 1;
    build((v << 1), l, m);
    build((v << 1) + 1, m, r);
    merge(t[v], t[(v << 1)], t[(v << 1) + 1]);
//    db(v);
//    db(t[v]);
}

ll memoSqrt[N];

ll getSqrt(ll &n) {
    if (n < N) {
        if (memoSqrt[n] != 0) return memoSqrt[n];
        return memoSqrt[n] = (ll) sqrtl(n);
    }

    return (ll) sqrtl(n);
}

int ql, qr;


void queryAdd(int v, int l, int r, ll x) {
    if (l >= qr || r <= ql)
        return;
    if (ql <= l && r <= qr) {
        t[v].mn += x;
        t[v].mx += x;
        t[v].lazy += x;
        t[v].sum += (r - l) * x;
        return;
    }

    ll m = (l + r) / 2;
    push_down(v, (m - l), (r - m));
    queryAdd((v << 1), l, m, x);
    queryAdd((v << 1) + 1, m, r, x);
    merge(t[v], t[(v << 1)], t[(v << 1) + 1]);
}

void querySqrt(int v, int l, int r) {
    if (l >= qr || r <= ql)
        return;
    if (ql <= l && r <= qr) {
        if (getSqrt(t[v].mn) == getSqrt(t[v].mx)) {
            t[v].mn = t[v].mx = getSqrt(t[v].mn);
            t[v].lazy = 0;
            t[v].sum = (r - l) * t[v].mn;
            return;
        }
        else if (t[v].mx == t[v].mn + 1) {
            queryAdd(v, l, r, -t[v].mn + getSqrt(t[v].mn));
            return;
        }
    }

    int m = (l + r) >> 1;
    push_down(v, (m - l), (r - m));
    querySqrt((v << 1), l, m);
    querySqrt((v << 1) + 1, m, r);
    merge(t[v], t[(v << 1)], t[(v << 1) + 1]);
}


ll querySum(int v, int l, int r) {
    if (l >= qr || r <= ql)
        return 0;
    if (ql <= l && r <= qr) {
        return t[v].sum;
    }

    int m = (l + r) >> 1;
    push_down(v, (m - l), (r - m));
    return querySum((v << 1), l, m) + querySum((v << 1) + 1, m, r);
}

int n, q;

int main() {
//    freopen("in.txt","r",stdin);


//    cin >> n >> q;
    scanf("%d%d", &n, &q);

//    assert(n < 100000 || q < 100000);

    for (int i = 0; i < n; i++) {
//        cin >> a[i];
        scanf("%d", a + i);

    }
    build(1, 0, n);
//    printTree(1, 0, n);

    int tp, l, r, x;
    clock_t start = clock();
    for (ll i = 0; i < q; i++) {
//        cin >> tp;
        scanf("%d", &tp);
        if (tp == 1) {
//            cin >> l >> r >> x;
            scanf("%d%d%d", &l, &r, &x);

            ql = l - 1;
            qr = r;
            queryAdd(1, 0, n, x);
        } else if (tp == 2) {
//            cin >> l >> r;
            scanf("%d%d", &l, &r);

            ql = l - 1;
            qr = r;
            querySqrt(1, 0, n);
        } else {
//            cin >> l >> r;
            scanf("%d%d", &l, &r);

            ql = l - 1;
            qr = r;
            printf("%lld\n", querySum(1, 0, n));
        }
//        printTree(1, 0, n);
    }
//     cerr << "Time elapsed: " << (clock() - start + 0.0) / CLOCKS_PER_SEC << endl;
    return 0;
}


/*

5 5
1 2 3 4 5
1 3 5 2
2 1 4
3 2 4
2 3 5
3 1 5
 */