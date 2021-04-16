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


const int N = 1000 * 1000 + 5;

int DEBUG = 1;

using namespace std;

int n,q;
vc<ll> a;
vc<ll> ps;
set<ll> ans;

void f(int l, int r){
    if(DEBUG){
        cout << endl;
        cout << l << ' ' <<r <<endl;
    }
    ll sum = ps[r] - ((l-1) >= 0 ? ps[l-1] : 0);
    db(sum);
    ans.insert(sum);

    if(l == r)
        return;

    ll mx = a[r];
    ll mn = a[l];

    dbl midd = (0.0 + mx + mn) / 2.0;

    ll mid = floor(midd+0.0000001);
    db(mid);

    auto it = upper_bound(a.begin()+l, a.begin()+r+1, mid);
    int m = (it-a.begin());
    db(m);
    if(m != l && m != r+1){
        f(l,m-1);
        f(m,r);
    }
}

void test() {
    cin >> n >> q;
    a.resize(n);
    ans.clear();
    loop(i,n){
        scanf("%lld", &a[i]);
    }
    sort(all(a));




    ps = a;
    for(int i = 1; i < n; i++){
        ps[i] += ps[i-1];
    }


    f(0,n-1);



    dbCont(ans);
    loop(i,q){
        ll e;
        scanf("%lld",&e);
        if(ans.count(e)){
            printf("Yes\n");
        } else {
            printf("No\n");

        }
    }
}

int main() {

    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*

 1
 5 5
1 2 3 4 5
1
8
9
12
6


 1
 5 5
3 1 3 1 3
1
2
3
9
11

2
5 5
1 2 3 4 5
1
8
9
12
6
5 5
3 1 3 1 3
1
2
3
9
11


 */



