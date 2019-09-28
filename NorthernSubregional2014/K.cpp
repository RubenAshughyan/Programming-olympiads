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

const ll mod = 1000000007;

int n, t;
ll dp[250 * 1000 + 5];
ll pdp[250 * 1000 + 5];
ll DP[255][255], tDP[255][255];
int q[1005], x[1005];

int main() {
    cin >> n >> t;

    for(int i = 0; i < n; i++)
        cin >> q[i] >> x[i];


    int base = 0;
    for(int i = 0; i < n; i++) {

        // DP[j][k] - j-rd pahin erazum a u arden k-rd angam
        // tDP[j][k] = DP[0][k] + DP[1][k] + ... DP[j][k]
        loop(j,255) loop(k,255) DP[j][k] = tDP[j][k] = 0;

        for(int j = 0; j < q[i]; j++) {
            if (q[i] - x[i] != 0) {
                if (min(base - 1, j + base - t - 1) >= 0)
                    DP[j][1] = pdp[min(base - 1, j + base - t - 1)];
                else
                    DP[j][1] = 1;
            }
            (tDP[j][1] = (j ? tDP[j - 1][1] : 0) + DP[j][1]) %= mod;
            (dp[base + j] += DP[j][1]) %= mod;
            for(int k = 2; k <= min(j + 1, q[i] - x[i]); k++) {
                DP[j][k] = (j - t - 1 >= 0 ? tDP[j - t - 1][k - 1] : 0);
//                for(int p = 0; p <= j - t - 1; p++)
//                    DP[j][k] += DP[p][k - 1];
                (tDP[j][k] = (j ? tDP[j - 1][k] : 0) + DP[j][k]) %= mod;
                (dp[base + j] += DP[j][k]) %= mod;
            }
            // dp[base + j] %= mod;
            pdp[base + j] = (base + j - 1 >= 0 ? pdp[base + j - 1] : 1) + dp[base + j];
            pdp[base + j] %= mod;
            // cout << base + j << " " << pdp[base + j] << " " << dp[base + j] << endl;
        }

//        cout << "---------------------------------" << endl;
//        for(int j = 0; j < q[i]; j++, cout << endl)
//            for(int k = 1; k <= j + 1; k++)
//                cout << DP[j][k] << " ";
//        cout << "---------------------------------" << endl;
        base += q[i];
    }
    cout << pdp[base - 1]%mod << endl;
    return 0;
}
/*
3 1
4 3
2 2
2 1
*/