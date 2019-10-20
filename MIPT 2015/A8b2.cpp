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
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 5000+5;

int a[N];
int n;
vc<int> g[N];

int dp[N][N];

int subtreeSize[N];
void dfsSubtreeSize(int v, int par){
    vc<int> childs;
    for(int to : g[v]){
        if(to != par){
            childs.push_back(to);
        }
    }

    if(childs.size() == 0) {
        subtreeSize[v] = 1;
        return;
    }
    for(int to: g[v]){
        if(to != par){
            dfsSubtreeSize(to,v);
            subtreeSize[v] += subtreeSize[to];
        }
    }
}

void dfs(int v, int par){
//    printf("v par, %d %d\n",v,par);

    vc<int> childs;
    for(int to : g[v]){
        if(to != par){
            childs.push_back(to);
        }
    }

    for(int ch : childs){
        dfs(ch, v);
    }

    if(childs.empty()) {
        loop(sum,N) {
            dp[v][sum] = 1e6;
        }
        loop(sum,2){
            dp[v][sum] = abs(a[v] - sum);
        }
    } else if(childs.size() == 1){
        int ch = childs.front();
        loop(sum, N){
            dp[v][sum] = dp[ch][sum] + abs(a[v] - sum);
        }
    } else {
        loop(sum,subtreeSize[v]+1){
            int c1 = childs[0], c2 = childs[1];
            int best = 1e8;
            for(int i = 0; i <= sum; i++){
                if(i <= subtreeSize[c1] && sum-i <= subtreeSize[c2]) {
                    int val = dp[c1][i] + dp[c2][sum - i] + abs(a[v] - sum);
                    best = min(best, val);
                }
            }

            dp[v][sum] = best;
        }
    }
}

int main(){
    scanf("%d",&n);
    loop(i,n) scanf("%d",&a[i]);

    loop(i,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsSubtreeSize(0, -1);

    dfs(0, -1);

    int ans = 1e9;
    loop(sum, subtreeSize[0]+1) {
        ans = min(ans, dp[0][sum]);
    }
    printf("%d\n",ans);

    return 0;
}


/*

 2
 1 0
 1 2

 5
 5 1 3 0 1
 1 2
 1 3
 3 4
 3 5


 */