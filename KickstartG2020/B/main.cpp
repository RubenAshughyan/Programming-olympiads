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

int DEBUG = 1;

using namespace std;

ll maxSubArraySum(vc<ll> a)
{
    ll size = a.size();
    ll max_so_far = 1e-17, max_ending_here = 0;

    for (ll i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void test(int testIndex){
    int n;
    cin >> n;

    vc<vc<ll>> v(n, vc<ll> (n,0));
    loop(i,n){
        loop(j,n){
            cin >> v[i][j];
        }
    }

    map<int,vc<ll>> diags;
    loop(i,n){
        loop(j,n){
            diags[i-j].PB(v[i][j]);
        }
    }

    ll ans=0;
    for(auto pr: diags){
        ans = max(ans, maxSubArraySum(pr.second));
    }




    printf("Case #%d: %lld\n", testIndex, ans);
}

int main() {
    int t;
    cin >> t;
    loop(I,t)  test(I+1);
    return 0;
}


/*

4
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))



 */



