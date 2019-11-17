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

const int DEBUG = 1;
const int N = 500 * 1000 + 8;
const int INF = 1000 * 1000 * 1000;

struct dat {
    int cn[2][2];
}t[4 * N];

ll n, c, r, s[N];

void merge(int v) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int l = 0; l < 2; l++) {
                t[v].cn[i][j] = min(t[v].cn[i][j], t[(v << 1)].cn[i][l] + t[(v << 1) | 1].cn[l ^ 1][j]);
            }
        }
    }
}

void prec(int v, int ls, int rs) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            t[v].cn[i][j] = min(t[(v << 1)].cn[i][j] + rs, t[(v << 1) | 1].cn[i][j] + ls);
        }
    }
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v].cn[0][0] = t[v].cn[1][1] = 0;
        t[v].cn[0][1] = t[v].cn[1][0] = INF;
        return;
    }
    int m = (l + r) / 2;
    build((v << 1), l, m);
    build((v << 1) | 1, m, r);
    prec(v, m - l, r - m);
    merge(v);
}

void update(int v, int l, int r, int pos) {
    if (l == r - 1) {
        t[v].cn[1][0] = t[v].cn[0][1] = INF;
        if (s[pos] > 0) {
            t[v].cn[0][0] = INF;
            t[v].cn[1][1] = 0;
        }
        else if (s[pos] < 0) {
            t[v].cn[0][0] = 0;
            t[v].cn[1][1] = INF;
        }
        else {
            t[v].cn[0][0] = t[v].cn[1][1] = INF;
        }
        return;
    }
    int m = (l + r) / 2;
    if (pos < m) {
        update((v << 1), l, m, pos);
    }
    else {
        update((v << 1) | 1, m, r, pos);
    }
    prec(v, m - l, r - m);
    merge(v);
}

ll current_ans() {
    ll ans = INF;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ans = min(ans, (ll)t[1].cn[i][j]);
        }
    }
    return ans;
}


int main() {
    cin >> n >> c >> r;
    set<ll> abss;
    set<pair<ll, int>> values;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
        abss.insert(abs(s[i]) + 1);
        values.emplace(abs(s[i]), i);
    }

    build(1, 0, n);
    ll bestans = c * (*abss.rbegin());
    auto iter = values.rbegin();
//    cout << "For " << (*abss.rbegin()) << " you must delete " << current_ans() << endl;

    for(auto it = abss.rbegin(); it != abss.rend(); ) {
        while(iter != values.rend() && iter->first == *it - 1) {
            update(1, 0, n, iter->second);
//            db(iter->second);
            iter++;
        }
        it++;
//        cout << "For " << *it << " you must delete " << current_ans() << endl;
        if (it != abss.rend()) {
            bestans = min(bestans, current_ans() * r + c * (*it));
        }
        else {
            bestans = min(bestans, current_ans() * r);
        }
    }

    cout << bestans << endl;
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