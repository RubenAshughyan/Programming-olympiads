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
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define sz(jjj) ((int) jjj.size())
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

const int N = 500 * 1000;


ll a[N], b[N];
int n, h;


vc<vc<int>> sax;
int len;

void gen(vc<int> &cur) {
    if (cur.size() == len) {
        sax.push_back(cur);
    } else {
        loop(i, 3) {
            cur.push_back(i);
            gen(cur);
            cur.pop_back();
        }
    }
}

vc<pll > rgt;

vc<ll> t[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
//        db(rgt[l].second);
        t[v].push_back(rgt[l].second);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid + 1, r);
    merge(all(t[2 * v + 1]), all(t[2 * v + 2]), back_inserter(t[v]));
}

int get(int v, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        return t[v].end() - lower_bound(all(t[v]), val);
    }

    // no overlap
    if (ql > r || l > qr) return 0;

    int mid = (l + r) / 2;
    return
            get(2 * v + 1, l, mid, ql, qr, val) +
            get(2 * v + 2, mid + 1, r, ql, qr, val);
}

void test(int tt) {
    rgt.clear();
    loop(i,N) t[i].clear();

    cin >> n >> h;
    loop(i, n) cin >> a[i];
    loop(i, n) cin >> b[i];


    len = n / 2;
    sax.clear();
    vc<int> XXX;
    gen(XXX);


    vc<pll > left;
    for (vc<int> msk : sax) {
//        dbCont(msk);
        ll A = 0, B = 0;
        loop(i, n / 2) {
            if (msk[i] == 0) A += a[i];
            if (msk[i] == 1) B += b[i];
            if (msk[i] == 2) B += b[i], A += a[i];
        }
        left.push_back({A, B});
    }


    len = n - n / 2;
    sax.clear();
    XXX.clear();
    gen(XXX);

    rgt.clear();
    for (vc<int> msk : sax) {
        ll A = 0, B = 0;
        loop(i, msk.size()) {
            if (msk[i] == 0) A += a[n / 2 + i];
            if (msk[i] == 1) B += b[n / 2 + i];
            if (msk[i] == 2) B += b[n / 2 + i], A += a[n / 2 + i];
        }
        rgt.push_back({A, B});
    }



    sort(all(rgt));

    build(0, 0, sz(rgt) - 1);
//    for(auto p : rgt){
//        cout << p.first << ' ' << p.second << endl;
//    }

    ll res = 0;
    for(auto lp: left){
        ll aH = lp.first;
        ll bH = lp.second;



        ll aNeed = max(0ll,h-aH);
        ll bNeed = max(0ll,h-bH);

//        db(aNeed);
//        db(bNeed);

        int ql = lower_bound(all(rgt), MP(aNeed, -1ll)) - rgt.begin();
//db(ql);
        int ans = get(0,0, sz(rgt)-1, ql, sz(rgt)-1, bNeed);
//        db(ans);
        res += ans;
    }

    printf("Case #%d: %lld\n", tt, res);
}


int main() {
//    freopen("in.txt", "r", stdin);
//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt, t) {
        test(tt + 1);
    }

    return 0;
}
/*
2
1 3
10
10

2 5
2 2
10 30
*/