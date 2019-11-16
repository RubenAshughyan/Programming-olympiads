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

ll DEBUG = 1;
const int N = 200 * 1000 + 123;
const int INF = 2000 * 1000 * 1000 + 123456;

int dp[N], n, k, w[2 * N];
vector<int> indices;
int mn[4 * N], lz[4 * N];

void push_down(int v) {
    lz[(v << 1)] = min(lz[(v << 1)], lz[v]);
    lz[(v << 1) | 1] = min(lz[(v << 1) | 1], lz[v]);
    mn[(v << 1)] = min(mn[(v << 1)], lz[(v << 1)]);
    mn[(v << 1) | 1] = min(mn[(v << 1) | 1], lz[(v << 1) | 1]);
    lz[v] = INF;
}

void buildPrec(int v, int l, int r) {
    indices.PB(v);
    if (l == r - 1) return;
    int m = (l + r) >> 1;
    buildPrec((v << 1), l, m);
    buildPrec((v << 1) | 1, m, r);
}

void build() {
    for(int id : indices) {
        mn[id] = lz[id] = INF;
        if (!(id & (id - 1))) mn[id] = -INF;
    }
}

int find_id(int bound) {
    int v = 1, l = 0, r = n + 1, m;
    while(l != r - 1) {
        if (lz[v] != INF) push_down(v);
        m = (r + l) >> 1;
        if (mn[(v << 1) | 1] <= bound)  { v = (v << 1) | 1; l = m; }
        else                            { v = (v << 1); r = m; }
    }
    return l;
}

int fenw[N];

void find_min(int l) {
    int ans = INF;
    while(l) {
        ans = min(fenw[l], ans);
        l -= l & (-l);
    }
}

void update(int id, int val) {
    int v = 1, l = 0, r = n + 1, m, lc;
    while(r > id) {
        mn[v] = min(mn[v], val);
        m = (l + r) >> 1;
        if (m >= id) { v = (v << 1); r = m; continue; }
        lc = (v << 1);
        lz[lc] = min(lz[lc], val);
        mn[lc] = min(mn[lc], lz[lc]);
        v = lc + 1;
        l = m;
    }
    mn[v] = min(mn[v], val);
    lz[v] = min(lz[v], val);
}

bool dynamic(int sBound) {
    build();
    update(2, w[0]);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int id = find_id(sBound - w[i]);
        update(id + 2, w[i]);
        dp[i] = id + 1;
    }

    for(int i = 0; i < n; i++) {
        if (dp[i] >= k && w[i] + w[0] <= sBound) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    int min_id = 0;
    loop(i, n) {
        scanf("%d", &w[i]);
        if (w[i] < w[min_id]) min_id = i;
    }
    buildPrec(1, 0, n + 1);
    for(int i = 0; i < min_id; i++) w[n + i] = w[i];
    for(int i = 0; i < n; i++) w[i] = w[i + min_id];

    int l = 2* *min_element(w,w+n)-1, r = 2* *max_element(w,w+n)+1;
    while (l < r - 1) {
        int m = 1ll * (r + l) / 2;
        if (dynamic(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    printf("%d", r);
    return 0;
}

/*

5 3
17 18 17 30 35

8 5
4 1 3 7 4 8 1 2

8 4
4 1 3 7 4 8 1 2
 */
