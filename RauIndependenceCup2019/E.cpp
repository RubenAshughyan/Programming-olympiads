#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define msk first
#define cnt second

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

const int N = 100 * 1000 + 123;

int n, k, l;

char buf[20];

int getDec(string s) {
    reverse(all(s));
    int res = 0;
    int p2 = 1;
    for (char c : s) {
        if (c == '1') {
            res += p2;
        }
        p2 *= 2;
    }
    return res;
}

int val[N];
vc<int> g[N];

vc<int> goodFor[256];

int ones(int x) {
    int res = 0;
    loop(i, 32) {
        res += ((x >> i) & 1);
    }
    return res;
}

vc<pii> dp[N];
int dp_direct[N][256];

ll ans = 0;

void dfs(int v, int par) {

    // Find children
    vc<int> childs;
    for (int to : g[v]) {
        if (to != par) {
            childs.push_back(to);
        }
    }

    dp_direct[v][val[v]]++;
    if(ones(val[v]) >= l) ans++;

    // Base case
    if (childs.empty()) {

    }
    else {
        // Solve children
        for (int to : childs) {
            dfs(to, v);
        }

        // Sum all children dps
        vc<int> s(256, 0);

        for (int to: childs) {
            for(pii pr: dp[to]){
                s[pr.msk] += pr.cnt;
                dp_direct[v][pr.msk | val[v]] += pr.cnt;
            }
        }

        ll passingRoot = 0;
        if(childs.size() >= 2) {
            for (int to: childs) {
                for(pii pr: dp[to]){
                    for (int msk2: goodFor[pr.msk | val[v]]) {
                        passingRoot += pr.cnt * (s[msk2] - dp_direct[to][msk2]);
                    }
                }
            }
        }


        ll chain = 0;
        loop(msk, 256) {
            if (ones(msk) >= l) {
                chain += dp_direct[v][msk];
            }
        }
        if(ones(val[v]) >= l) chain--;



//        cout << endl;
//        db(passingRoot);
//        db(chain);
        ans += passingRoot / 2 + chain;
    }



    loop(i, 256){
        if(dp_direct[v][i]){
            dp[v].push_back({i, dp_direct[v][i]});
        }
    }

//    db(v);
//    db(val[v]);
//    dbCont(dp_direct[v]);
//    for(auto pr : dp[v]) printf("%d %d, ", pr.first, pr.second); cout << endl;

}

int main() {
    scanf("%d%d%d", &n, &k, &l);
    loop(i, n) {
        scanf("%s", buf);
        string s = buf;
        val[i] = getDec(s);
    }

    loop(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    loop(msk1, 256) {
        loop(msk2, 256) {
            if (ones(msk1 | msk2) >= l) {
                goodFor[msk1].push_back(msk2);
            }
        }
    }

    dfs(0, -1);

    printf("%lld\n", ans);
    return 0;
}

/*



 6 3 2
111
111
111
111
111
111
1 2
3 2
3 4
4 5
4 6


6 3 2
100
001
110
010
000
010
1 2
3 2
3 4
4 5
4 6
*/