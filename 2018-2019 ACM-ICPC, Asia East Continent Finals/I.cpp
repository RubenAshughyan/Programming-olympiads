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


const int N = 102;
const int MOD = 1000 * 1000 * 1000 + 7;

ll dp[N][N * N];
ll a[N], b[N], c[N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k = n * (n + 1) / 2 + 1; k >= 0; --k) {
                if (dp[j][k] == -1) continue;
                ll tmp = dp[j][k];
                dp[j + 1][k + i] = max(tmp + a[i], dp[j + 1][k + i]);

                dp[j][k] = max(tmp + b[i] * (k - j * i), dp[j][k]);
                dp[j][k] = max(tmp + c[i] * j, dp[j][k]);
            }
        }
    }
    ll mx = -1;
    for (int j = n; j >= 0; --j) {
        for (int k = n * (n + 1) / 2 + 1; k >= 0; --k) {
            mx = max(mx, dp[j][k]);
        }
    }
    cout << mx << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
11101110011011101010
11100100111011101110
11100110001010101110
11001110111011001110
01101110101011101000
11101110111011100110
01100010111011001110
11101100101001101110
10101110010011001110
11101110011011101010

 */