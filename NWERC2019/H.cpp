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
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int DEBUG = 0;

const int N = 100 * 1000 + 8;

struct ST {
    //find min
    int l, r;
    ll mn, mx;
};

ST tree[4 * N];

void build(vector<ll> &hi_ig, int l, int r, int v = 1) {
    tree[v].l = l;
    tree[v].r = r;
    if (r - l == 1) {
        tree[v].mn = tree[v].mx = hi_ig[l];
        return;
    }
    int m = (l + r) / 2;
    build(hi_ig, l, m, 2 * v);
    build(hi_ig, m, r, 2 * v + 1);
    tree[v].mn = min(tree[v * 2].mn, tree[v * 2 + 1].mn);
    tree[v].mx = max(tree[v * 2].mx, tree[v * 2 + 1].mx);
}

int query_min(ll q, int v = 1) {
    if (tree[v].l + 1 == tree[v].r)
        return tree[v].l;
    if (tree[v * 2].mn <= q)
        return query_min(q, 2 * v);
    return query_min(q, 2 * v + 1);
}

int query_max(ll q, int v = 1) {
    if (tree[v].l + 1 == tree[v].r)
        return tree[v].l;
    if (tree[v * 2 + 1].mx >= q)
        return query_max(q, 2 * v + 1);
    return query_max(q, 2 * v);
}

int get_int() {
    dbl x;
    cin >> x;
    return round(x * 10);
}

int main() {
    int n, k;
    cin >> n >> k;
    n++;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &h[i]);
    for (int j = 0; j < k; ++j) {
        ll g = get_int();
        db(g);
        vector<ll> hi_ig(n);
        for (int i = 0; i < n; ++i) {
            hi_ig[i] = h[i] - i * g;
        }
        dbCont(hi_ig);
        build(hi_ig, 0, n);
        dbl ans = 0;
        for (int i = 0; i < n; ++i) {
            int ql = query_min(hi_ig[i]);
            ans = max(ans, (dbl) i - ql);
            if (ql) {
                ll h1 = h[ql - 1];
                ll h2 = h[ql];
                ll h22 = h[i] - (i - ql) * g;
                ans = max(ans, (h22 - h2) / (dbl)(g - h2 + h1) + i - ql);
            }
            int qr = query_max(hi_ig[i]);
            ans = max(ans, (dbl) qr - i);
            if (qr != n - 1) {
                ll h1 = h[qr];
                ll h2 = h[qr + 1];
                ll h12 = h[i] + (qr - i) * g;
                ans = max(ans, (h1 - h12) / (dbl)(g - h2 + h1) + qr - i);
            }
        }
        if (ans == 0)
            cout << "impossible" << endl;
        else
            printf("%.10Lf\n", ans);
    }
    return 0;
}

/*

 8 3
0 0 10 30 60 45 75 65 30
2.0
3.1
-3.7


 2 3
0 30 30
3.0
2.0
-3.7


 */