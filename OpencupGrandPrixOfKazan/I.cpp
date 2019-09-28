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
const int DEBUG = 0;
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG){cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

int AUTOMAT = 1;
/////////////////////////////////////////////////////
int U = 1;

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 200 * 1000 + 55;


int n;

set<int> g[N];
int sz[N];
int parent[N];
set<int> candidates;

void dfsPrecalc(int v, int par) {
    sz[v] = 1;
    parent[v] = par;

    for (int to : g[v]) {
        if (to != parent[v]) {
            dfsPrecalc(to, v);
            sz[v] += sz[to];
        }
    }
}

void dfsRemoveCandidates(int v) {
    candidates.erase(v);
    for (int to : g[v]) {
        if (to != parent[v]) {
            dfsRemoveCandidates(to);
        }
    }
}

void dfsFillCandidates(int v) {
    db(v);
    candidates.insert(v);
    for (int to : g[v]) {
        if (to != parent[v]) {
            dfsFillCandidates(to);
        }
    }
}

int dfsAutomat(int v, vc<int> vs, int x, int from) {
    if (v == x) return 1;
    if (find(all(vs), v) != vs.end()) return 0;

    for (int to: g[v]) {
        if (to != from) {
            int curStatus = dfsAutomat(to, vs, x, v);
            if (curStatus != -1) return curStatus;
        }
    }
    return -1;
}

bool askAutomat(vc<int> vs, int x) {
    return dfsAutomat(U, vs, x, -1);
}


int ASK = 0;

bool ask(vc<int> vs, int x) {

    ASK++;
    if (ASK > 4 * ceil(log2(n))) {
        while (1) {
        }
    }
    if (AUTOMAT) {
        return askAutomat(vs, x);
    }

    cout << "? " << vs.size() << " " << x;
    for (int e: vs) cout << " " << e;
    cout << endl;
    fflush(stdout);

    int res;
    cin >> res;
    return res == 1;
}

vc<int> subVector(vc<int> &v, int l, int r) {
    vc<int> res;
    for (int i = l; i <= r; i++) {
        res.push_back(v[i]);
    }
    return res;
}

void generateGraph() {
    loop(i, N) g[i].clear();

    for (int i = 2; i <= n; i++) {
        int p = (rand() % (i - 1)) + 1;
        g[i].insert(p);
        g[p].insert(i);
        printf("%d %d\n", i, p);
    }
}

int solve() {
    ASK = 0;
    candidates.clear();
    if (AUTOMAT) {
        n = 10;
        generateGraph();
//        U = rand() % n + 1;
        U = 7;
        cout << "U " << U << endl;
//        freopen("in.txt", "r", stdin);
    } else {
        cin >> n;
        loop(i, n - 1) {
            int u, v;
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        candidates.insert(i);
    }

    // calc subtree sizes, parents
    dfsPrecalc(1, -1);
    int x = 1;
    while (candidates.size() > 2) {
//        cout << endl;
        dbCont(candidates);
        for (int c: candidates) db(sz[c]);

        // find such node sz >= 0.33*n
        bool found=true;
        while (found) {
            found = false;
            for (int v: g[x]) {
                if (v == parent[x])
                    continue;
                if (2 * sz[v] >= candidates.size()) {
                    x = v;
                    found = true;
                    break;
                }
            }
        }
        db(x);
        assert(x != -1);

        // kaxel x_ic
        dfsPrecalc(x, -1);

        vc<int> vs(all(g[x]));
        auto it = find(all(vs), parent[x]);
        if (it != vs.end()) vs.erase(it);

        dbCont(vs);
        bool isXCloser = ask(vs, x);


        // if x is closer then we remove all the children of x, not x
        if (isXCloser) {
            for (int ch: g[x]) {
                dfsRemoveCandidates(ch);
            }
            g[x].clear();

            // update sizes
            dfsPrecalc(x, -1);
        }
            // else the answer is in one of the children
        else {
            // we should binary search in which child the answer is

            vc<int> children(all(g[x]));
            int l = 0, r = children.size() - 1, mid;
            while (l < r) {

                mid = (l + r) / 2;
                vc<int> left_part = subVector(children, l, mid);
                vc<int> right_part = subVector(children, mid + 1, r);
                dbCont(left_part);
                dbCont(right_part);
                if (ask(left_part, x)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            assert(l == r);
            int child_containing = children[l];


            candidates.clear();
            g[child_containing].erase(x);
            dfsFillCandidates(child_containing);
        }
        dbCont(candidates);
    }


    if (candidates.size() == 1) {
        cout << "! ";
        cout << *candidates.begin() << endl;
    } else {
        vc<int> vectorCandidates(all(candidates));
        if (ask(subVector(vectorCandidates, 0, 0), vectorCandidates[1])) {
            cout << "! ";
            cout << vectorCandidates[1] << endl;
        } else {
            cout << "! ";
            cout << vectorCandidates[0] << endl;
        }
    }

    return 0;
}


int main() {
    loop(iter, 100) {
        solve();
    }
    return 0;
}
/*



*/