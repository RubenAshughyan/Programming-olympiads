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

int n;
vc<ll> v;
ll k;
ll X,A;
ll Y,B;

bool can(int I){
    vc<ll> x;
    for(int i =0 ; i <= I; i++) x.push_back(v[i]);

    vc<ll> cont(x.size(), 0);
    for(int i = A-1; i < cont.size(); i += A){
        cont[i] += X;
    }
    for(int i = B-1; i < cont.size(); i += B){
        cont[i] += Y;
    }

    ll curCont = 0;

    sort(all(cont));
    reverse(all(cont));


//    dbCont(cont);
    loop(i, cont.size()){
        curCont += cont[i] * x[i] / 100ll;
    }

//    db(curCont);
    return curCont >= k;
}

void test() {
    cin >> n;
    v.clear();
    loop(i, n) {
        ll e;
        cin >> e;
        v.push_back(e);
    }
    cin >> X >> A;
    cin >> Y >> B;
    cin >> k;

    sort(all(v));
    reverse(all(v));

    int l = 0, r = n-1;
//    for(int i = 0; i < n; i++){
//        db(can(i));
//    }
//    return;
    while(l < r){
        int mid = (l+r)/2;
        if(can(mid)){
            r = mid;
        } else {
            l = mid+1;
        }
    }

    if(can(l)){
        cout << l+1 << endl;
    } else {
        cout << -1 << endl;
    }


}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }
}
/*
1
 8
100 200 100 200 100 200 100 100
10 2
15 3
107


 3 0
 0 0 0
*/