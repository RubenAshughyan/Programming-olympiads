#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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

#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define pos first
#define health second
//
//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pdd pair<dbl,dbl>
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


int DEBUG = 1;

using namespace std;

const ll INF = 1e12;
const int N = 2 * 100 * 1000 + 123;

ll n, d, a;

vc<pll > mons;

// tree
ll lazy[4 * N];
ll t[4 * N];


void build(int v, int l, int r) {
    if (l == r) {
        t[v] = mons[l].health;
        lazy[v] = 0;
    } else {
        int mid = (l + r) / 2;

        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid + 1, r);

        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

void push(int v, int l, int r){
    if(l != r){
        lazy[2*v+1] += lazy[v];
        lazy[2*v+2] += lazy[v];
    }
    t[v] += lazy[v];
    lazy[v] = 0;
}

ll getMin(int v, int l, int r, int ql, int qr) {
    if (lazy[v] != 0) {
        push(v, l, r);
    }

    // no overlap
    if (l > qr || ql > r) return INF;

    // total
    if (ql <= l && r <= qr) return t[v];

    // partial
    int mid = (l + r) / 2;

    return min(
            getMin(2 * v + 1, l, mid, ql, qr),
            getMin(2 * v + 2, mid + 1, r, ql, qr)
    );
}

void addRange(int v, int l, int r, int ql, int qr, ll val) {
    if (lazy[v] != 0) {
        push(v, l, r);
    }

    // no overlap
    if (l > qr || ql > r) return;

    // total
    if (ql <= l && r <= qr) {
        lazy[v] += val;
//        push(v, l, r);
        return;
    }

    // partial
    int mid = (l + r) / 2;
    addRange(2 * v + 1, l, mid, ql, qr, val);
    addRange(2 * v + 2, mid + 1, r, ql, qr, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}


int main() {
    cin >> n >> d >> a;
    loop(i, n) {
        ll pos, h;
        cin >> pos >> h;
        mons.push_back({pos, h});
    }

    sort(all(mons));

    build(0, 0, n - 1);

    ll ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){

        ll healt = getMin(0,0,n-1, i,i);


//        db(healt);

//        db(a);
        if(healt <= 0) continue;

        ll need = healt/a;
        if(healt%a != 0) need++;


//        db(need);


        while(j+1 < n && mons[j+1].pos - mons[i].pos <= 2*d) {
            j++;
        }

        addRange(0, 0, n - 1, i, j, need * -a);
        ans += need;
    }


    cout << ans << endl;
    return 0;
}
