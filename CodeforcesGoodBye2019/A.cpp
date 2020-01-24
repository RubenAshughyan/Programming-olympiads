#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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


const int N = 2000 + 5;

int DEBUG = 1;

using namespace std;

int n;
ll x[N],y[N];

map<ll,vc<pii>> mp;

ll d(int i, int j){
    return SQ(x[i]-x[j]) + SQ(y[i]-y[j]);
}

map<int, vc<int>> g;
int color[N];

// 0/1 group
int ans[N];

void dfs(const int v, int col){
    if(color[v] != -1 && color[v] != col){
        assert(false);
    }
    if(color[v] == col) return;

    color[v] = col;
    for(int to: g[v]){
        dfs(to, col^1);
    }

}

int main() {
    loop(i,N){
        color[i] = -1;
        ans[i] = -1;
    }

   cin >> n;
   loop(i,n){
       cin >> x[i] >> y[i];
   }

   loop(i,n){
       loop(j,n){
           if(i < j){
               mp[d(i,j)].PB({i,j});
           }
       }
   }



   // for all distances
   for(auto pr : mp){
       ll dist = pr.first;
       auto v = pr.second;

       // make graph
       g.clear();
       set<int> vertices;
       for(auto pr1: v){
           int v1 = pr1.first;
           int v2 = pr1.second;

           vertices.insert(v1);
           vertices.insert(v2);

           g[v1].push_back(v2);
           g[v2].push_back(v1);
       }

//       dbCont(vertices);
       // porci tarber

       // pti bipartite lini
       for(int v: vertices) {
           if(color[v] == -1) {
               dfs(v, 0);
           }
       }

       for(int v : vertices){
           ans[v] = color[v];
       }

   }


   int count0 = 0;
   vc<int> res;
   loop(i,n){
       if(color[i] == 0){
           res.PB(i);
       }
   }

   cout << res.size() << endl;

   for(int e: res)
       cout << e + 1 << ' ';
    return 0;
}

/*


 */