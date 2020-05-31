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


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n;

map<ll, vc<ll>> mp;


ll INF = 1e12;


ll l,r;
map<ll,int> used;

void dfs(ll v){
    used[v] = 1;

    if(v >= INF-5) r++;
    else l++;

    for(ll to : mp[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}

int main() {


    set<ll> verts;

    cin >> n;
    loop(i,n){
        int x,y;
        cin >> x >> y;

        verts.insert(x);
        verts.insert(y+INF);


        mp[x].PB(y+INF);
        mp[y+INF].PB(x);

    }



    ll ans = 0;
    for(ll v: verts){
        if(!used[v]){
            l = 0;
            r = 0;

            dfs(v);
            ans += l*r;
        }

    }

    cout << ans << endl;


    return 0;
}


/*





 */



