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
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 100 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;


string s;
int n;

vc<int> prefixFunction() {
    vc<int> pf(n, 0);

    for (int i = 1; i < n; i++) {
        int pos;
        for (pos = pf[i - 1]; pos > 0; pos = pf[pos - 1]) {
            if (s[i] == s[pos]) {
                break;
            }
        }
        pf[i] = pos + (s[i] == s[pos]);
    }

    return pf;

}


void solve() {
    cin >> s;
    reverse(all(s));
    n = s.length();
    vc<int> pf = prefixFunction();
    dbl d = 0;
    for (int i = 0; i < pf.size(); ++i) {
        if (pf[i] == 0)
            d += 1.0 / (i + 1);
    }
    printf("%.15Lf\n", 1.0 / d);
}

int main() {

//
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
3
aba
aaaaaaaaaaa
abcd

 */