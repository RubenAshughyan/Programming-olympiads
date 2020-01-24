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
#define x first
#define y second

//#define ld long double
#define dbl long double
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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int DEBUG = 1;

int n, k;


// C[i] -> C(n - 1 - i, k - 1) / C(n, k)
dbl C[505];
dbl s[505];

int main() {
    scanf("%d%d", &n, &k);
    C[0] = (k + 0.) / n;
    for(int i = 1; i <= n; i++) {
        C[i] = C[i - 1] * (n - k - i + 1) / (n - i);
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        dbl ans = 0;
        for(int j = 0; j <= n - k; j++) {
            ans += C[j] * s[(i - j + n) % n];
        }
        printf("%.10Lf ", ans);
    }
    return 0;
}