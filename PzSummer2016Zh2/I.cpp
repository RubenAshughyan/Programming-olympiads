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

int n, m;

ll a[N];

void printFraction(ll A, ll B){
    if(A == 0) assert(false);

    ll g = __gcd(A, B);
    A /= g;
    B /= g;
    cout << A << '/' << B << endl;
}

void test(){
    cin >> n >> m;
    loop(i,n) a[i] = -1;
    loop(i,m){
        int x,y;
        cin >> x >> y;
        a[x-1] = y;
    }

    if(a[0] == -1)
        a[0] = 100;
    a[1] = a[1] == -1?a[0]:a[1];

    ll last = 0;
    for(int i = n-1; i >= 2; i--){
        if(a[i] == -1){
            a[i] = last;
        } else {
            last = a[i];
        }
    }

    ll sum = 0;
    loop(i,n) sum += a[i];

    printFraction(a[0]+a[1], sum);
}

int main() {
    int t;
    cin >> t;
    loop(i,t){
        test();
    }

    return 0;
}

/*
466


 4 3
 1 2
 2 1
 4 0
 */