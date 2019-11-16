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
#define dbl long double
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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

ll DEBUG = 1;
const int N = 1000 * 100 + 123;
int n,m;

vc<int> g[N];

vc<int> comp;
int used[N];
void dfs(int v){
    used[v] = 1;
    comp.push_back(v);
    for(int to: g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    loop(i,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;

        g[v].PB(u);
        g[u].PB(v);
    }


    int ans = 0;
    loop(v,n){
        if(!used[v]){
            comp.clear();
            dfs(v);

            int gag = comp.size();
            int kox = 0;
            for(int vv: comp) kox += g[vv].size();
            kox /= 2;

            ans += kox - (gag-1);
        }
    }
    printf("%d",ans);
    return 0;
}

 /*
5 3
3 5
5 1
1 3
*/
