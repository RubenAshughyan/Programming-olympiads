#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


const int N = 2000 + 5;

int DEBUG = 0;

using namespace std;

int n;
ll s[N];

ll dp[N][N];

ll mx[N][N];
ll mn[N][N];

int main() {

    loop(i, N) loop(j, N) dp[i][j] = -1;

    cin >> n;
    loop(i, n) cin >> s[i];
    sort(s, s+n);

    // calc mx mn
    for (int i = 0; i < n; i++) {
        mx[i][i] = s[i];
        mn[i][i] = s[i];
        for (int j = i + 1; j < n; j++) {
            mx[i][j] = max(mx[i][j - 1], s[j]);
            mn[i][j] = min(mn[i][j - 1], s[j]);
        }
    }


    // 1 length
    loop(i, n) {
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;

            dp[i][j] = min(
                    dp[i + 1][j], dp[i][j - 1]
            ) + mx[i][j] - mn[i][j];
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}


/*




 */



