#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
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

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
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

const int N = 1000 * 1000 + 5;


using namespace std;


int n,k;
int col[N];
int e[N];
ll a,b,c;
vc<int> g[N];
int used[N];
int which_comp[N];
vc<vc<int>> comps;

void dfs(int v, int cur_comp){
    used[v]= 1;
    comps[cur_comp].PB(v);
    which_comp[v] = cur_comp;
    for(int to : g[v]){
        if(!used[to] && col[to] == 0){
            dfs(to, cur_comp);
        }
    }
}

ll c2(ll x){
    return ((x)*(x-1)) / 2;
}

void test(int testIndex) {
    cin >> n >> k;
    string s;
    cin >> s;
    loop(i,n) col[i] = s[i] == '#';

    for(int i = 2; i <= k+1; i++){
        cin >> e[i];
    }
    cin >> a >> b >> c;
    for(int i = k+1+1; i <= n; i++){
        e[i] = (a*e[i-2] + b*e[i-1] + c) % (i-1) + 1;
    }

    // clear
    comps.clear();
    loop(i,n) g[i].clear();
    for(int i = 1; i<= n; i++){
        int u = i-1;
        int v = e[i]-1;
        g[u].PB(v);
        g[v].PB(u);
    }

    loop(i,n) used[i] = 0;

    int cur_comp = 0;

    loop(i,n){
        if(!used[i] && col[i] == 0){
            comps.PB(vc<int>());
            dfs(i, cur_comp);
            cur_comp++;
        }
    }

    ll best = 0;
    ll ways = 0;
    if(comps.size() == 1){
        ll sz = comps.size();
        best = c2(sz);
        ways = (sz-1)*(sz-1);
    } else {
        vc<int> sizes;
        for(auto &comp: comps){
            sizes.PB(comp.size());
        }

        sort(all(sizes));
        reverse(all(sizes));

        ll cur_best = 0;
        for(ll sz: sizes) cur_best+= c2(sz);

        best = cur_best - c2(sizes[0]) - c2(sizes[0]) + c2(sizes[0] + sizes[1]);

        // ways
        if(sizes[0] == sizes[1]){
            int cnt = count(all(sizes), sizes[0]);

            ways = c2(cnt) * 2 * sizes[0];
        } else if(sizes.size() >= 3 && sizes[1] == sizes[2]){
            int cnt = count(all(sizes), sizes[1]);

            ways = cnt * (sizes[0] + sizes[1]);
        } else {
            ways =
        }
    }

    printf("Case #%d: %lld %lld\n", best, ways);

}

int main() {

    int t;
    cin>> t;
    loop(i,t) test(i+1);
    return 0;
}


/*




 */



