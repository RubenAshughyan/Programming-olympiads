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
//#define a first
//#define d second
//
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

const int N = 3 * 100 * 1000 + 5;
const ll MOD = 1000 * 1000 * 1000 + 7;
int n;

struct node {
    ll a, b;

    node() : a(1), b(0) {}
    node(ll a, ll b) : a(a), b(b) {}
};

node t[4 * N];
int last_group = 0;

int ql,qr,offset;
void updateMult(int v, int l, int r) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        (t[v].a *= 2) %= MOD;
        (t[v].b *= 2) %= MOD;
        return;
    }
    int mid = (l + r) / 2;
    updateMult(2 * v + 1, l, mid);
    updateMult(2 * v + 2, mid + 1, r);
}

void updateAdd(int v, int l, int r) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        (t[v].b += offset) %= MOD;
        return;
    }
    int mid = (l + r) / 2;
    updateAdd(2 * v + 1, l, mid);
    updateAdd(2 * v + 2, mid + 1, r, ql, qr);
}

void push_down(node& parent, node& lc, node& rc) {
    (lc.a *= parent.a) %= MOD;
    (rc.a *= parent.a) %= MOD;
    (lc.b *= parent.a) %= MOD;
    (rc.b *= parent.a) %= MOD;
    (lc.b += parent.b) %= MOD;
    (rc.b += parent.b) %= MOD;
    parent = {1, 0};
}

pll query(int v, int l, int r, int pos) {
    if(l == r) return MP(t[v].a, t[v].b);

    int mid = (l + r) / 2;
    push_down(t[v], t[2 * v + 1], t[2 * v + 2]);
    if (pos <= mid) return query(2 * v + 1, l, mid, pos);
    else            return query(2 * v + 2, mid + 1, r, pos);
}

void setNewGroup(int v, int l, int r, int tp) {
    if (l == r) {
        if (tp == 0) {
            t[v] = {2, 1};
        }
        else {
            t[v] = {1, 0};
        }
        return;
    }
    int mid = (l + r) / 2;
    if (last_group <= mid)  setNewGroup(2 * v + 1, l, mid, tp);
    else                    setNewGroup(2 * v + 2, mid + 1, r, tp);
}

vector<set<pll>> operations;
vector<int> gid;

void query3(int pos) {
    int id = operations.size() - 1;
    while(id >= 0) {
        if (operations[id].empty()) {
            if (pos & 1) {
                cout << gid[id] << endl;
                return;
            }
            else {
                pos >>= 1;
                id--;
            }
        }
        else {
            ll alls = (--operations[id].end())->first;
            if (pos < alls) {
                ll pref = alls - pos;
                set<pll>& last_set = operations[id];

                auto it = last_set.upper_bound(MP(pref, -1));
                cout << it->second << endl;
                return;
            }
            else {
                pos -= alls;
                id--;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
//    set<pii> s {{1, 1}, {3, 3}, {5, 5}, {7, 4}, {10, 0}};
//    cout << s.upper_bound(MP(7, -1))->first << endl;
//    cout << s.upper_bound(MP(6, INT_MAX))->first << endl;



    scanf("%d", &n);
    setNewGroup(0, 0, N - 1, -1);
    loop(tt, n) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            last_group++;
            if (x == 0) {
                updateMult(0, 0, N - 1, 0, last_group - 1);
                operations.PB(set<pll>());
                gid.PB(last_group);
            }
            else {
                updateAdd(0, 0, N - 1, 0, last_group - 1, x);
                if (operations.empty() || operations.back().empty()) {
                    operations.PB(set<pll> {MP(x, last_group)});
                    gid.PB(-1);
                }
                else {
                    ll last = (--operations.back().end())->first;
                    operations.back().emplace(last + x, last_group);
                }

            }
            setNewGroup(0, 0, N - 1, x);
        } else if (op == 2) {
            int g;
            scanf("%d",&n);
            swap(g, x);
            pll p = query(0, 0, N - 1, g);

            ll a1 = p.second;
            ll d = p.first;
            ll ans = a1 + (x - 1) * d % MOD;
            printf("%lld\n", ans % MOD);
        } else if (op == 3) {
            query3(x);
        }
    }

    return 0;
}
