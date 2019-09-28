
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

const int N = 2000 + 5;
const int INF = 1000 * 1000 * 1000 + 5;
const int D = 20 + 5;

int klor(int t) {
    if (t % 10 < 5) return t - t % 10;
    return t + 10 - t % 10;
}

int a[N];
int ps[N];

int memo[N][N][D];
int dp[N][D];

int solve(int l, int r, int d) {
//    db(l);
//    db(r);
//    db(d);
    if (memo[l][r][d] != -1) return memo[l][r][d];

    if (d == 0) {
//        db(klor(ps[r]-ps[l-1]));
        return klor(ps[r] - ps[l - 1]);
    }

    if (l == r) {
//        db( klor(a[l]));
        return klor(a[l]);
    }

    int ans = solve(l, r, d - 1);
    for (int mid = l; mid <= r - 1; mid++) {
        for (int cutLeft = 0; cutLeft <= d - 1; cutLeft++) {

            int curAns =
                    solve(l, mid, cutLeft) +
                    solve(mid + 1, r, d - 1 - cutLeft);

            ans = min(ans, curAns);
        }
    }
    return memo[l][r][d] = ans;
}

int main() {
    int n, d;


//    loop(i,N) loop(j,N) loop(k,D) memo[i][j][k] = -1;

    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ps[0] = 0;
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }


    loop(i, N) loop(k, D) dp[i][k] = INF;
    for (int i = 0; i <= d; i++) {
        dp[1][i] = klor(a[1]);
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = klor(ps[i]);
        for (int cd = 1; cd <= d; cd++){
            for(int j = 1; j <= i; j++){
                dp[i][cd] = min(dp[i][cd], dp[j][cd-1] + klor(ps[i]- ps[j]));
            }
        }
    }


    int ans = dp[n][d];
    cout << ans << endl;
    return 0;
}
/*

 5 1
13 21 55 60 42

2 1
14 14

5 4
13 21 54 60 42

3 2
13 21 55

 5 2
1 1 1 1 1
 */