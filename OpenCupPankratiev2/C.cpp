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

int ask(int v) {
    cout << "? " << v << endl;
    int to;
    cin >> to;
    return to;
}


int n, m;

int par[N];

int find(int v) {
    if (par[v] == v) {
        return v;
    }
    return par[v] = find(par[v]);
}

int comps;
void unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (u == v) return;

    if (rand() % 2) swap(u, v);
    par[v] = u;
    comps--;
}

void test() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) par[i] = i;

    comps = n;
    vc<int> vs;
    for(int i = 1; i <= n; i++) vs.push_back(i);
    random_shuffle(all(vs));

    int spare = 0;
    for(int v : vs){
        while(spare){
            int u = ask(v);
            spare--;
            if (u != -1) {
                unite(u, v);
            } else {
                break;
            }
        }

        loop(i,2){
            int u = ask(v);
            if (u != -1) {
                unite(u, v);
            } else {
                spare++;
                break;
            }
        }


    }

//    db(comps);
    cout << (comps == 1 ? "+" : "-") << endl;


}

int main() {
    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}
/*


*/