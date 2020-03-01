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
    int n;
    cin >> n;

    vc<ll> a(n);
    loop(i,n) cin>> a[i];


    vc<ll> t(n);
    loop(i,n) cin>> t[i];

    map<ll, multiset<ll>*> mp;
    map<ll, ll> mpSum;

    loop(i,n) {
        if(!mp.count(a[i])){
            mp[a[i]] = new multiset<ll>;
        }
        mpSum[a[i]] += t[i];
        mp[a[i]]->insert(t[i]);
    }


    ll ans = 0;

//    cout << 123 << endl;

    while(!mp.empty()) {

        db("");
//        for(auto pr: mp){
//            cout << pr.first << ": ";
//            dbCont(*pr.second);
//        }

        // take begin
        ll mn = mp.begin()->first;

        db(mn);

        if(mp[mn]->empty() || mp[mn]->size() == 1) {
            mp.erase(mn);
            mpSum.erase(mn);
            continue;
        }

        ll cost = mpSum[mn] - *(--mp[mn]->end());
        db(cost);

        ans += cost;

        mpSum[mn] -= *(--mp[mn]->end());
        mp[mn]->erase(--mp[mn]->end());

        if(!mp.count(mn+1)){
            mp[mn+1] = new multiset<ll>;
        }

        for(ll e : *mp[mn+1]) {
            mp[mn]->insert(e);
            mpSum[mn] += e;
        }



        mp[mn+1] = mp[mn];
        mpSum[mn+1] = mpSum[mn];

        mp.erase(mn);
    }

    cout << ans << endl;
}

int main() {

    int t;
//    cin >> t;
t = 1;
    loop(i, t) test();

    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

 5
1 1 1 1 1
1 1 1 1 1



 */



