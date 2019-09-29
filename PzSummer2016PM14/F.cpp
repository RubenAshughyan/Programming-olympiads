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
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 1000 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, k;

int c[N][4];

int T(int a, int b) {
    int ans = 0;
    if (a == b)
        return 1;
    // even
    if (((a + b) & 1) == 0) {
        ans++;
    }

    if (a > b) swap(a, b);

    if (1 <= 2 * a - b) {
        ans++;
    }
    if (2 * b - a <= n) {
        ans++;
    }
    return ans;
}

dbl dp[N][2];

dbl f[N][4];

int main() {
    cin >> n >> k;


    // precalc
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            c[a][T(a, b)]++;
        }
    }

    f[0][1] = 1;
    f[0][2] = 1;
    f[0][3] = 1;

    for (int kk = 1; kk <= k; kk++) {
        f[kk][1] = f[kk - 1][1] * (n - 1) / n;
        f[kk][2] = f[kk - 1][2] * (n - 2) / n;
        f[kk][3] = f[kk - 1][3] * (n - 3) / n;
    }

    loop(a, N) dp[a][0] = 0;
    int cur = 0;

    dbl prevans = 0;
    for (int kk = 2; kk < k; kk++) {
        cur ^= 1;
        int prev = cur ^1;
        for (int a = 1; a <= n; a++) {

            dp[a][cur] = c[a][0] * dp[a][prev];
            for (int t = 1; t <= 3; t++) {
                dp[a][cur] += c[a][t] * max(1 - f[kk - 1][t], dp[a][prev]);
            }
            dp[a][cur] /= n;
        }
        dbl curans = 0;
        for (int a = 1; a <= n; ++a) {
            curans += max(dp[a][cur], prevans);
        }
        curans /= n;
        prevans = curans;
    }
    printf("%.10Lf\n", prevans);
    return 0;
}
