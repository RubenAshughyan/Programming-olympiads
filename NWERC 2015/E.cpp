
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
#define dbl  long double
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
//    db(v);
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


map<ll, ll> ind;
map<ll, ll> inver;
vc<vc<ll>> V;

int main() {
    cin >> n;
    set<ll> bolor;
    V.resize(n);

    vc<pii> input;

    loop(i, n) {
        ll a, b;
        cin >> a >> b;
        bolor.insert(a + b);
        bolor.insert(a * b);
        bolor.insert(a - b);
        input.PB({a,b});
        V[i].PB(a + b);
        V[i].PB(a * b);
        V[i].PB(a - b);
    }

    k = bolor.size();
    int GI = 0;

    for (ll e : bolor) {
        ind[e] = GI;
        inver[ind[e]] = e;

        GI++;
    }


//    cout << "input done" << endl;
    g.resize(n);
    loop(i, n) {
        for (ll e : V[i]) {
            g[i].push_back(ind[e]);
        }
    }


    mt.resize(1e5);
    used.resize(1e5);

    mt.assign(k, -1);
//    cout << "matching" << endl;

    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

//    cout << "matching deon" << endl;



    int x = 0;

    vc<pii> vv;
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1) {
//            printf("%d %d\n", mt[i], i);
            x++;
            vv.push_back({ mt[i], i});
        }

sort(all(vv));

//    db(x);
    if(x < n){
        cout << "impossible" << endl;
    } else {
        for(auto p : vv){
            ll a = input[p.first].first;
            ll b = input[p.first].second;
            if (a + b == inver[p.second]){
                cout<< a<< " + "<<b << " = " << a+b <<endl;
            }
            else if (a * b == inver[p.second]){
                cout<< a<< " * "<<b << " = " << a*b <<endl;
            }
            else if (a - b == inver[p.second]){
                cout<< a<< " - "<<b << " = " << a-b <<endl;
            } else {
                cout << "db"  << endl;
            }
        }
    }
    return 0;
}

/*
4
1 5
3 3
4 5
-1 -6
*/
