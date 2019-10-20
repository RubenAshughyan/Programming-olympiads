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


const int N = 1000*1000+5;

int n;
ll x[N], c[N],t[N];
ll dp[N];

int main(){
    scanf("%d",&n);
    loop(i,n) {
        scanf("%lld%lld%lld", &x[i], &c[i], &t[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            dp[i] = max(dp[i], dp[j] + c[j]*abs(x[i]-x[j])+t[i]);
        }
    }
    cout << *max_element(dp,dp+n) << endl;
    return 0;
}


/*

4
5 10 2
0 1 10
15 3 14
17 2 3

 1
709 50 8

 */