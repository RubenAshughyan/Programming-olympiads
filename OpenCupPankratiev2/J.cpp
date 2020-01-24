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


vc<ll> v;
ll L2 = 0;

bool can(int k){
    if(k == 1) return true;

    ll neededL2 = 0;
    neededL2 += v[k-1];
    neededL2 += v[k-2];
    for(int i = 0; i < k-2; i++){
        neededL2 += 2*v[i];
    }

    return neededL2 < L2;

}

int main(){
    int n;
    cin >> n;
    loop(i,n){
        ll a,b;
        cin >> a >> b;
        v.push_back(min(a,b));
    }
    cin >> L2;
    L2 *= 2;

    sort(all(v));

    int l = 1, r = n, mid;
    while(l < r){
        mid = (l+r+1)/2;
        if(can(mid)){
            l = mid;
        } else {
            r = mid-1;
        }
    }

    cout << l << endl;


    return 0;
}


/*
4
3 5
6 4
10 20
2 2
7


 3
1 1
1 1
1 1
2


*/