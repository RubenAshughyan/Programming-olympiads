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

void test() {

    ll n;
    cin >> n;
    set<ll> divs;

    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            divs.insert(i);
            divs.insert(n/i);
        }
    }
    divs.erase(n)
            ;
    vc<ll> d(all(divs));

    sort(all(d));
    reverse(all(d));


    ll sum = 0;
    bool ok = false;
    for(ll x : d){
        sum +=x;
        if(sum == n){
            ok = 1;
        }
    }
    if(ok){
        cout << "Semiperfect" << endl;
    } else {
        cout << "NOT Semiperfect" << endl;
    }
    // 1 2 3 6

}

int main() {

    int t;
    cin >> t;
    loop(i,t) test();


    return 0;
}


/*
4
3
6
32
228

 */



