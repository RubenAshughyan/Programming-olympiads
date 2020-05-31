#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


const int N = 500 * 1000 + 5;

int DEBUG = 0;

using namespace std;

ll gcd(ll a, ll b){
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

ll lcm(ll a, ll b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

ll LCM;

ll solve(ll a, ll b, ll r) {
    if(a % b == 0 || b%a == 0) return 0;

    if( a > b) swap(a,b);

    ll x = b;
    ll y = LCM - b;


    ll ans = 0;
    ll fullBlocks = r / (x+y);

    ans += fullBlocks * y;

    ll md = r % (x+y);

    ans += max(0ll, md-x+1);
    return ans;

}


int a = 14;
int b = 16;
bool ok(ll x){
    return ((x%a)%b) != ((x%b)%a);
}

ll brute(ll a, ll b, ll l, ll r){
    ll ans = 0;
    for(ll x = l; x <= r; x++){
        ans += ((x%a)%b) != ((x%b)%a);
    }
    return ans;
}

void test(){
    ll a,b,q;
    cin >> a >> b >> q;

    LCM = lcm(a,b);

    loop(i,q){
        ll l, r;
        cin >> l >> r;


        ll ans = solve(a,b,r);
        if(l != 1) ans -= solve(a,b,l-1);


        db(ans);
        db(brute(a,b,l,r));
//        assert(ans == brute(a,b,l,r));
        cout << ans << ' ';
    }
    cout << endl;
}



int main() {


//    for(int i = 0; i <= 1000; i++){
//        cout << i << ' ' << ok(i) << endl;
//    }


    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*

 */



