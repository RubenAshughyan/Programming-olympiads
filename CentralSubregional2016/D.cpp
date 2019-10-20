#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second

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

const int N = 100*1000+5;

ll dp[N];
const int MOD = 1000*1000*1000+7;

int main() {

    string s;
    cin >> s;


    int n = s.length();


    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1];


            if (s[i - 1] == 'N' && s[i] == 'W') {
                dp[i] += (i-2 >= 0) ? dp[i - 2] : 1;
            }
            if (s[i - 1] == 'N' && s[i] == 'E') {
                dp[i] += (i-2 >= 0) ? dp[i - 2] : 1;
            }
            if (s[i - 1] == 'S' && s[i] == 'E') {
                dp[i] += (i-2 >= 0) ? dp[i - 2] : 1;
            }
            if (s[i - 1] == 'S' && s[i] == 'W') {
                dp[i] += (i-2 >= 0) ? dp[i - 2] : 1;
            }

        dp[i] %= MOD;

//        cout << dp[i] << ' ';
    }
//    cout << endl;

    cout << dp[n-1] << endl;

    return 0;
}
/*

NEWS
EWNS
*/