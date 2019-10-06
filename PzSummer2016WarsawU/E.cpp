#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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


const int N = 100 * 1000 + 7;
const int M = 10 + 3;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m, k;
string s, t;

int pl[N][M];
int pr[N][M];

int solve(int l, int r) {
    // base case
    if (l == r) {
        if (t.size() == 1 && s[l] == t[0]) return 1;
        return 0;
    }


    int mid = (l + r) / 2;

    //pl
    for(int len = 0; len <= m; len++) pl[l][len] = 0;
    for(int i = l; i <= mid; i++){
        pl[i][1] = (i-1 >= l ? pl[i-1][1] : 0) + (t[1] == s[i]);
    }

    for (int i = l + 1; i <= mid; i++) {
        for (int len = 2; len <= m - 1; len++) {
            pl[i][len] = pl[i - 1][len];
            if (s[i] == t[len]) {
                (pl[i][len] += pl[i - 1][len - 1]) %= MOD;
            }
        }
    }


    // pr
    for(int len = 0; len <= m; len++) pr[r][len] = 0;
    for(int i = r; i >= mid+1; i--){
        pr[i][1] = (i+1 <= r ? pr[i+1][1] : 0) + (s[i] == t.back());
    }

    for (int i = r - 1; i >= mid + 1; i--) {
        for (int len = 2; len <= m; len++) {
            pr[i][len] = pl[i + 1][len];
            if (s[i] == t[m - len]) {
                (pr[i][len] += pr[i + 1][len - 1]) %= MOD;
            }
        }
    }


    //merge
    int ans = 0;
    for (int i = l; i <= mid; i++) {
        if (s[i] == t.front()) {
            int ri = i + k - 1;
            if (mid + 1 <= ri && ri <= r) {

                for (int left = 0; left <= m - 2; left++) {
                    int leftPart;
                    if (i + 1 <= mid) {
                        leftPart = pl[i + 1][left];
                    } else if (left == 0) {
                        leftPart = 1;
                    } else {
                        leftPart = 0;
                    }

                    int rightPart;
                    if (mid + 1 < ri) {
                        rightPart = pr[ri][m - 1 - left];
                    } else {
                        rightPart = 0;
                    }

                    ans += (leftPart * 1ll * rightPart) % MOD;
                    ans %= MOD;
                }
            }
        }
    }


    (ans += solve(l, mid)) %= MOD;
    (ans += solve(mid + 1, r)) %= MOD;
    return ans;
}


int dp[N][M];

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;


    if(t.length() == 1){
        // TODO
    }

    for(int i = 0; i < n; i++){
        dp[i][1] = (i-1 >= 0 ? dp[i-1][1] : 0) + (t[0] == s[i]);
    }


    for (int i = 1; i < n; i++) {
        for (int len = 2; len <= m; len++) {
            dp[i][len] = dp[i - 1][len];
            if (s[i] == t[len - 1]) {
                (dp[i][len] += dp[i - 1][len - 1]) %= MOD;
            }
        }
    }
    int total = dp[n - 1][m];

    int solveInverse = solve(0, n - 1);

    db(total);
    db(solveInverse);

    int answer = (total - solveInverse + MOD) % MOD;

    cout << answer << endl;
    return 0;
}
/*
13 3 5
longlonghotel
lol


 10 2 44
 kkkkakakpk
 ak

*/