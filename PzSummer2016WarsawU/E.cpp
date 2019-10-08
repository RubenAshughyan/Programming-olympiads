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


const int N = 100 * 1000 + 70;
const int M = 10 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;


int n, m, k;
string s, t;

int L[M][N][M];
int R[M][N][M];

int solve(const int l, const int r) {
//    printf("\nl, r %d %d\n", l,r );


    // base case
    if (l == r) {
        if (t.length() == 1 && s[l] == t[0]) return 1;
        return 0;
    }

    int mid = (l + r) / 2;

    // calc L
    //zero
    for(int pi = 1; pi < m; pi++) {
        for (int i = l; i <= mid; i++) for (int len = 0; len <= m; len++) L[pi][i][len] = 0;

        for (int i = mid; i >= l; i--) {
            L[pi][i][1] = (i + 1 <= mid ? L[pi][i + 1][1] : 0) + (s[i] == t[pi]);
        }
        for (int i = mid; i >= l; i--) {
            for (int len = 2; len <= m - 1; len++) {
                L[pi][i][len] = (i + 1 <= mid ? L[pi][i + 1][len] : 0);
                if (i+1 <= mid && s[i] == t[pi-len+1]) {
                    (L[pi][i][len] += L[pi][i + 1][len - 1]) %= MOD;
                }
            }
        }
    }

    // calc R
    for (int si = 0; si < m; si++) {
        // zero
        for(int i = mid+1; i <= r; i++) for(int len = 0; len <= m; len++) R[si][i][len] = 0;

        // fill len = 1
        for (int i = mid + 1; i <= r; i++) {
            R[si][i][1] = (i - 1 >= mid+1 ? R[si][i - 1][1] : 0) + (s[i] == t[si]);
        }
        for (int i = mid + 1; i <= r; i++) {
            for (int len = 2; len <= m; len++) {
                R[si][i][len] = (i - 1 >= mid+1 ? R[si][i - 1][len] : 0);
                if (i-1 >= mid+1 && si + len - 1 < m && s[i] == t[si + len - 1]) {
                    (R[si][i][len] += R[si][i - 1][len - 1]) %= MOD;
                }
            }
        }
    }

    // merge
    int ans = 0;
    for (int i = l; i <= mid; i++) {
        if (s[i] == t[0]) {
            int mr = min(k + i - 1, r);
            if (mid + 1 <= mr) {
                for (int left = 0; left <= m - 2; left++) {

                    // left product
                    int p1 = (i + 1 <= mid ? L[left][i + 1][left] : 0);
                    if(left == 0) p1 = 1;

                    // right product
                    int right = m-left-1;
                    int p2 = R[m-1 -right+1][mr][right];


                    int prod = (p1*1ll*p2) % MOD;
                    (ans += prod) %= MOD;
                }
            }
        }
    }

    (ans += solve(l,mid)) %= MOD;
    (ans += solve(mid+1, r)) %= MOD;
    return ans;
}


ll dp[N][M];

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;


    if(t.length() == 1){
        cout << 0 << endl;
        return 0;
    }

    // Fill len = 1
    for (int i = 0; i < n; i++) {
        dp[i][1] = (i - 1 >= 0 ? dp[i - 1][1] : 0) + (s[i] == t[0]);
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

    int slv = solve(0, n - 1);
    
    int ans = (total - slv + MOD) % MOD;
    cout << ans << endl;
    return 0;
}