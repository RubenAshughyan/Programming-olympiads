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

const int MOD = 998244353;
const int N = 250 * 1000 + 5;
const int M = 250 * 1000 + 5;

int n, m;
string grid[3005];

int dp[3005][3005];

int main() {
//    freopen("in.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    bool ok = false;

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m - 1; j++) {
            dp[i][j] = (i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0) - (i && j ? dp[i - 1][j - 1] : 0);
            if (grid[i + 1][j] == grid[i][j + 1]) {
                dp[i][j] += 1;
                if (i && j && dp[i - 1][j - 1])
                    ok = true;

                if ((j && grid[i + 1][j - 1] == grid[i][j]) || (i && grid[i - 1][j + 1] == grid[i][j]))
                    ok = true;
            }
        }

    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
/*
 *

3 6
1 2 3
get 1
get 3
shuffle 1 2
shuffle 2 3
get 1
get 3



*/