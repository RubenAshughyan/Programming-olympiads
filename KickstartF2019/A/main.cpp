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

const int N = 100 + 5;
const int INF = 1e9;

int n,k;
ll dp[N][N][N];


void test(int tt) {
    loop(i,N){
        loop(j,N){
            loop(l,N){
                dp[i][j][l] = INF;
            }
        }
    }

    cin >> n >> k;
    vc<int> a(n);
    set<int> st;
    loop(i,n) {
        cin >> a[i];
        st.insert(a[i]);
    }

    vc<int> nums(all(st));

    loop(j, nums.size()) {
        if(nums[j] != a[0]) {
            dp[0][0][j] = 1;
        } else {
            dp[0][0][j] = 0;
        }
    }


    // dp
    for(int i = 1; i < n; i++){
        for(int ck = 0; ck <= k; ck++){
            for(int j = 0; j < nums.size(); j++){
                for(int pj = 0; pj < nums.size(); pj++) {
                    // naxordnela j
                    if(j != pj && ck == 0) continue;

                    int pk = (j != pj) ? ck-1 : ck;
                    dp[i][ck][j] = min(
                            dp[i][ck][j],
                            dp[i - 1][pk][pj] + (a[i] != nums[j] ? 1 : 0)
                    );
                }
            }
        }
    }

    ll ans = 1e12;
    for(int ck = 0; ck <= k; ck++){
        for(int j = 0; j < nums.size(); j++){
            ans = min(ans, dp[n-1][ck][j]);
        }
    }


    printf("Case #%d: %lld\n", tt, ans);
}


int main() {
//    freopen("in.txt", "r", stdin);
//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt, t) {
        test(tt + 1);
    }

    return 0;
}