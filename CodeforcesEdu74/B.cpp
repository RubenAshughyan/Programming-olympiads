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
vc<ll> x;
ll n,R;

bool can(ll k){
    vc<ll> v = x;
    set<ll> st;
    while(st.size() != k && v.size()){
        st.insert(v.back());
        v.pop_back();
    }
    return v.back()-k*R <= 0;
}

void test(){
   cin >> n >> R;

   x.clear();

   set<ll> st;
   loop(i,n){
       ll e;
       cin >> e;
       st.insert(e);
   }

   n = st.size();
   for(int e: st) x.push_back(e);

   ll l  = 1, r = n, mid;
    while(l < r){
        mid = (l+r)/2;
        if(can(mid)){
            r = mid;
        } else {
            l = mid+1;
        }
    }

    cout << l << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t){
        test();
    }
    return 0;
}