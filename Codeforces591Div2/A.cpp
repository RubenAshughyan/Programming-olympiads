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
const int N = 300 * 1000 + 5;
const int M = N * 64 + 555;

int GI = 0;


int main(){
    int t;
    cin >> t;
    loop(i,t){
        ll e;
        cin >> e;

        ll ans;
        if(e < 4){
            ans = 4-e;
        } else if(e % 2 == 1){
            ans = 1;
        } else {
            ans = 0;
        }
        cout << ans << endl;
    }
}
/*
3 0
0 1 2

 3 2
0 1 2

 3 3
0 1 2

 7 4
11 5 5 8 3 1 3


 8 5
 13 12 8 20 21 2 4 1

 13 523452
 1234 4123435 412341 51341 413245 523454 1324132 54515 4 412345 5123451 51451 1234123



 3 0
 0 0 0
*/