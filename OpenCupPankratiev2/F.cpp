#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;

int n, t;

ll d[N], w[N], p[N];

struct Tree {
    Tree(int index, ll j, ll w) {
        ind = index;
        joy = j;
        weithgt = w;
    }

    void add_parent(Tree *p) {
        p->children.insert(this);
        max_elem = max(joy, max_elem);
        this->parent = p;
        parent->max_elem = max(parent->max_elem, max_elem);
    }

    Tree *find_max() {
        if (max_elem == joy)
            return this;
        for (Tree *c: children) {
            if (c->max_elem == max_elem)
                return c->find_max();
        }
    }

    ll find_weight() {
        if (parent->ind == 0)
            return weithgt;
        return min(weithgt, parent->weithgt);
    }

    void sub(ll v) {
        weithgt -= v;
        if (ind==0)
            return;
        if (weithgt == 0) {
            parent->children.erase(this);
        }
        parent->sub(v);
    }

    Tree *parent;
    set<Tree*> children;
    ll joy, weithgt;
    ll max_elem = 0;
    int ind;
};

void test() {
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> p[i] >> w[i];
    }
    Tree root = Tree(0, 0, 1e10);
    vector<Tree *> vs;
    vs.push_back(&root);
    for (int j = 1; j <= n; ++j) {
        vs.push_back(new Tree(j, d[j], w[j]));
    }
    for (int k = 1; k <= n; ++k) {
        vs[k]->add_parent(vs[p[k]]);
    }
    ll ans = 0;
    db(root.max_elem);
    while (t) {
        db(t);

        // find max weight
        Tree *maxT = root.find_max();
        db(maxT->ind);
        ll w = maxT->find_weight();
        w = min(w, (ll) t);
        maxT->sub(w);
        ans += w * maxT->joy;
        t -= w;
    }

    cout << ans << endl;

}

int main() {
    test();
    return 0;
}
/*
9 6
30 0 4
40 9 2
80 8 3
20 9 2
10 4 3
70 5 8
90 2 4
50 0 6
60 1 3

*/