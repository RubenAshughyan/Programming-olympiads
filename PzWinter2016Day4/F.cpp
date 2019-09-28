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
const int INF = 1000000000;
const int MOD = 1000000007;


using namespace std;

int count1(int n) {
    return n ? count1(n & (n - 1)) + 1 : 0;
}

vector<int> childs(int k) {
    if (k == 0) {
        return vector<int>{0};
    }
    int one = k - (k & (k - 1));
    int next = k ^one;
    vector<int> r = childs(next);
    int l = r.size();
    for (int i = 0; i < l; ++i) {
        r.push_back(r[i] | one);
    }
    return r;
}

const int NUMONE = 11;
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < d; ++j) {
            v[i] *= 2;
            v[i] += s[j] - '0';
        }
    }
    vector<int> dp(1 << 16, 0);
    vector<int> m(1 << 16, 0);
    vector<int> keys;
    int smm = 0;
    for (int k = 0; k < (1 << 16); ++k) {
        if (count1(k) > NUMONE) {
            keys.push_back(k);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (count1(v[i]) > NUMONE) {
            int de = m[v[i]] + 1;
            for (auto p: keys) {
                if ((p & v[i]) == v[i]) {
                    (m[p] += de) %= MOD;
                }
            }
            smm += de;
            smm %= MOD;
        } else {
            vector<int> cs = childs(v[i]);
            int de = 1;
            for (int j = 0; j < cs.size(); ++j) {
                (de += dp[cs[j]]) %= MOD;
            }
            (dp[v[i]] += de)%=MOD;
            for (auto p : keys) {
                if ((p & v[i]) == v[i]) {
                    (m[p] += de) %= MOD;
                }
            }
        }
    }
    int ans = smm;
    for (int l = 0; l < dp.size(); ++l) {
        ans += dp[l];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
/*
3 16
0000000000000000
0000000000000000
1111111111111111

7

4 16
0000000000000000
0000000000000000
1001101101111111
1111111111111111

 15

5 16
0000000000000000
0000000000000000
1001101101110000
1001101111101111
1111111111111111

 23

3 2
00
00
11

7

4 2
00
00
10
11

15


5 2
00
00
01
10
11

23

4 3
110
100
011
101

5
 */