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
#define X first
#define Y second
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

ll A,B;

ll L = 1000*1000*1000;

ll rd() {
    ll r1 = rand();
    ll r2 = rand();
    ll r = (r1 << 32) ^ (r2);
    r = abs(r);
    return -L + r%(2*L+1);
}

char buf[50];
int askCnt;
string ask(ll x, ll y){
    askCnt++;
    if(askCnt > 300) assert(false);
    x = min(x, L);
    y = min(y, L);
    x = max(x, -L);
    y = max(y, -L);

    assert(-L <= x && x <= L);
    assert(-L <= y && y <= L);
    printf("%lld %lld\n",x,y);
    fflush(stdout);


    string s;
    cin >> s;
    if (s == "WRONG") exit(0);

    return s;
}


pll findEnd(pll F, pll d, bool &cent){
    ll l = 0, r = 2e9+3;

    while(l < r){
        ll mid = (l+r+1)/2;

        ll nx = F.X + mid*d.X;
        ll ny = F.Y + mid*d.Y;
        string resp = ask(nx,ny);
        if(resp == "CENTER"){
            cent = true;
            return F;
        }
        if(resp != "MISS"){
            l = mid;
        } else {
            r = mid-1;
        }
    }

    ll nx = F.X + l*d.X;
    ll ny = F.Y + l*d.Y;
    return MP(nx,ny);
}

void test(int testIndex){
    askCnt = 0;
    ll x = 0;
    ll y = 0;

    bool cent = false;
    while(1){
        string resp = ask(x,y);
        if(resp == "CENTER") return;

        if(resp == "HIT") break;

        x = rd();
        y = rd();
    }

    pll START = {x,y};

    pll U = findEnd(START, {0,+1}, cent); if(cent) return;

    pll U1 = findEnd(U, {+1,0}, cent); if(cent) return;
    pll U2 = findEnd(U, {-1,0}, cent); if(cent) return;
    pll D1 = findEnd(U1, {0,-1}, cent); if(cent) return;
    pll D2 = findEnd(U2, {0,-1}, cent); if(cent) return;

    ll X = (U1.X + U2.X + D1.X + D2.X) / 4;
    ll Y = (U1.Y + U2.Y + D1.Y + D2.Y) / 4;

    ask(X,Y);
}

int main() {
    int t;
    scanf("%d %lld %lld",&t,&A,&B);
    loop(I,t)  test(I+1);
    return 0;
}












