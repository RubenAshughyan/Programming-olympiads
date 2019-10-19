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


int n, k;
vector<vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

vc<pii > A, T;

map<pii, vc<string>> saxA;
map<pii, vc<string>> saxT;


pii get(string s) {
    int l = 0;
    for (int i = 0; i < 3; i++) l += s[i] - '0';

    int r = 0;
    for (int i = 3; i < 6; i++) r += s[i] - '0';
    return {l, r};
}

bool can(pii p1, pii p2) {
    return p1.first == p2.second || p1.second == p2.first;
}

int main() {
    cin >> n >> k;

    loop(i, n) {
        string s;
        cin >> s;
        pii p = get(s);
        A.push_back(p);
        saxA[p].push_back(s);
    }
    loop(i, k) {
        string s;
        cin >> s;
        pii p = get(s);
        T.push_back(p);
        saxT[p].push_back(s);
    }

    mt.assign(k, -1);
    g.resize(n);

    loop(i, n) {
        loop(j, k) {
            if (can(A[i], T[j])) {
                g[i].push_back(j);
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

    vc<pii > ans;
    for (int i = 0; i < k; ++i) {
        if (mt[i] != -1) {
            ans.push_back({mt[i], i});
        }
    }

//    for(auto p : ans){
//        cout << p.first << ' ' << p.second << endl;
//    }

    cout << ans.size() << endl;
    for (auto p : ans) {
        pii a = A[p.first];
        pii t = T[p.second];

//        cout << a.first << ' ' << a.second << endl;
//        cout << t.first << ' ' << t.second << endl;

        string AA = saxA[a].back();
        saxA[a].pop_back();

        string TT = saxT[t].back();
        saxT[t].pop_back();


        string op;
        if (get(AA).first == get(TT).second) op = "AT";
        else op = "TA";


        if (op == "AT") {
            cout << op << ' ' << AA << ' ' << TT << endl;
        } else {
            cout << op << ' ' << TT << ' ' << AA << endl;

        }

    }

}



/*
2 3
000000 000000
000000 000000 000000



 2 2
123456 111222
141204 555000
 */