
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

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int N = 100 * 1000 + 5;

int n;

vc<int> g[N];

int GI ;

pair<pair<int, bool>, pair<int, bool>> ans[N];

void dfs(int v, int par){
    for(int to : g[v]){
        if(to != par){
            if (!ans[v].first.second) {
                ans[to].first = {ans[v].first.first, true};
                ans[v].first.second = true;
                if (g[to].size() != 1) {
                    ans[to].second.first = GI++;
                    ans[to].second.second = false;
                } else {
                    ans[to].second = ans[v].second;
                    ans[to].second.second = true;
                    ans[v].second.second = true;
                }
            }
            else{
                ans[to].first = ans[v].second;
                ans[to].first.second = ans[v].second.second = true;
                ans[to].second.first = GI++;
                ans[to].second.second = false;
            }
            dfs(to,v);
        }
    }
}

int main() {
    cin >> n;
    loop(i,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].PB(v);
        g[v].PB(u);
    }


    ans[0] = {{1, false}, {2, false}};
    GI = 3;
    dfs(0,-1);

    loop(i,n){
        cout << ans[i].first.first << ' ' << ans[i].second.first << endl;
    }

    return 0;
}
/*

14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
7 11
7 12
7 13
7 14


 4711 815
666 4711
4711 42
815 7
47 666
666 54
23 42
7 2
7 1
7 3
23 4
42 5
23 6
42 8
 */