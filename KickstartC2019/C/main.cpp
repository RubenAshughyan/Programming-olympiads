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

const int N = 1000 + 5;
const int K = 1000 + 5;


ll dp0[N][K];

ll dp1[N][K];
ll INF = 1e14;


int k,n;
int a[K];
int x[K];

vc<int> g[N];

void test(int tt){
    loop(i,N){
        loop(j,K){
            dp0[i][j] = INF;
            dp1[i][j] = INF;
        }
    }

    cin >> n >> k;

    map<int,int> comp;

    loop(i,n){
        cin >> x[i];
    }

    set<int> st;
    loop(i,n){
        cin >> a[i];
        st.insert(a[i]);
    }


    int GI = 0;
    for(int e : st){
        comp[e] = GI++;
    }

    loop(i,N) g[i].clear();
    loop(i,n){
        g[comp[a[i]]].push_back(x[i]);
    }
    loop(i,n){
        sort(all(g[comp[a[i]]]));
    }

    n = GI;

    dp0[0][0] = 0;
    for(int i = 0; i < g[0].size(); i++){
        dp0[0][i+1] = 2*g[0][i];
    }

    // dynamic
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp0[i][j] = dp0[i-1][j];
            for(int l = 0; l < g[i].size(); l++){
                if(j-(l+1) >= 0) {
                    dp0[i][j] = min(dp0[i][j],
                                    dp0[i - 1][j - (l + 1)] + 2 * g[i][l]
                    );
                }
            }
        }
    }


    dp1[n-1][0] = 0;
    for(int i = 0; i < g[n-1].size(); i++){
        dp1[n-1][i+1] = 2*g[n-1][i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= k; j++){
            // dp0[i][j]
            dp1[i][j] = dp1[i+1][j];
            for(int l = 0; l < g[i].size(); l++){
                if(j-(l+1) >= 0) {
                    dp1[i][j] = min(dp1[i][j],
                                    dp1[i + 1][j - (l + 1)] + 2 * g[i][l]
                    );
                }
            }
        }
    }


    ll ans = INF;
    // merge
    for(int i = 0; i < n; i++){
        for(int take = 0; take <= g[i].size(); take++){

            for(int up = 0; up <= k; up++){
                int down = k-take - up;
                if(down < 0) continue;
                if(down && i == n-1) continue;
                if(up && i == 0) continue;
                ll cur = 0;

                if(i-1 >= 0){
                    cur += dp0[i-1][up];
                }
                if(take != 0) {
                    cur += g[i][take - 1];
                }
                if(i+1 < n) {
                    cur += dp1[i + 1][down];
                }
                ans = min(ans, cur);
            }
        }
    }


    printf("Case #%d: %lld\n",tt, ans);
}

int main() {
    int t;
    cin >> t;
    loop(tt,t){
        test(tt+1);
    }

    return 0;
}