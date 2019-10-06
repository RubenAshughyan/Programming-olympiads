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


const int N = 1000*1000+7;
const int MOD = 1000*1000*1000 + 7;

ll f(ll n){
    if (n == 0)
        return 0;
    return f(n / 10) + SQ(n%10);
}
void test(){
    ll a, b, k;
    cin >> k >> a >> b;
    if (a / (9 * 9 * 18) > k){
        cout << 0 << endl;
        return;
    }
    else {
        ll start = (a-1) / k * k + k, s=0;

        for (; start <= b; start+=k) {
            if (start > 9 * 9 * 18 * k)
                break;
            if (f(start) * k == start)
                s++;
        }
        cout << s << endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    loop(i,t){
        test();
    }

    return 0;
}