
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

ll f(ll a, ll b, ll c){
    return a * a + b * b + c * c + 7 * min(a,min( b, c));
}
void solve(){
    int aa, bb, cc, d;
    cin >> aa >> bb >> cc >> d;
    int a = max(aa, max(bb, cc)), c=min(aa, min(bb, cc));
    int b = aa + bb + cc - a - c;
    ll mx = f(a + d, b, c);
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (i + j <= d)
                mx = max(mx, f(a + i, b + j, c + d - i - j));
        }
    }
    cout << mx << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}
