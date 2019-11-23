#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;

void solveV(ll a, ll b) {
    if (a == b) {
        cout << "0 / 1" << endl;
        return;
    }
    if (a > b){
        swap(a, b);
    }
    ll mi = a * b + 1;
    for (int i = 0; i < b; ++i) {
        // k / a <= i / b <  k + 1 / a
        // k+1 / a - i / b
        ll k = i * a / b + 1;
        mi = min((k * b - i * a), mi);
    }
    // (1 / b) - (mi / (2 * a * b) )
    ll num = 2 * a - mi;
    ll denum = 2 * a * b;
    ll g = __gcd(num, denum);
    cout << num / g << " / " << denum / g << endl;
}

void solve(ll a, ll b) {

    if (a == b) {
        cout << "0 / 1" << endl;
        return;
    }
    if (a > b) {
        swap(a, b);
    }
    ll k = (b - 1) / a;
    // (1 / a - k/b)/2
    ll num = b - a * k;
    ll denum = a * b * 2;
    ll g = __gcd(a, b);
    num /= g;
    denum /= g;
    // 1 / b  - num / denum
    ll num1 = denum - b * num;
    ll denum1 = b * denum;
    ll g1 = __gcd(num1, denum1);
    num1 /= g1;
    denum1 /= g1;
    cout << num1 << " / " << denum1 << endl;

}

int main() {
    int a, b;
    cin >> a >> b;
    solveV(a, b);
    return 0;
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            solve(i, j);
        }
    }
    return 0;
}
/*
2
2147483649 1
*/