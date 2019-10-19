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
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG){ cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int MOD = 998244353;
const int N = 300 * 1000 + 5;
const int M = N * 64 + 555;

int DEBUG = 0;

int n;
vc<int> v;

void test() {
    v.clear();

    set<int> st;
    map<int, int> mp;
    scanf("%d", &n);
    loop(i, n) {
        int e;
        scanf("%d", &e);

        if(v.empty() || v.back() != e) {
            v.push_back(e);
            st.insert(e);
        }
    }
    n = v.size();

    int GI = 0;
    for (int e : st) {
        mp[e] = GI++;
    }
    loop(i, n) v[i] = mp[v[i]];

    map<int, vc<int>> inds;
    loop(i, n) {
        inds[v[i]].push_back(i);
    }
    dbCont(v);
    set<int> removed;
    for (int i = 0; i < GI; i++) {
        if (inds[i].back() - inds[i].front() + 1 != inds[i].size()) {
            removed.insert(i);
        }
    }

    dbCont(removed);

    vc<int> nv;
    for(int e :v) if(!removed.count(e)) nv.push_back(e);

    dbCont(nv);

    int maxGood = 0;
    if(!nv.empty()) {
        int curGood = 1;
        for (int i = 1; i < nv.size(); i++) {
            if (nv[i] == nv[i - 1] + 1) {
                curGood++;
            } else {
                maxGood = max(maxGood, curGood);
                curGood = 1;
            }
        }
        maxGood = max(maxGood, curGood);
    }

    db(maxGood);

    int ans = removed.size() + nv.size() - maxGood;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }
}
/*
1
 8
100 200 100 200 100 200 100 100
10 2
15 3
107


 3 0
 0 0 0
*/