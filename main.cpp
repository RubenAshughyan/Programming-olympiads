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

int n = 5;

int sign(int e){
    return e > 0;
}

set<vc<int>> ans;

void gen(vc<vc<int>> v){
//    cout << endl;
//    for(auto x : v){
//        dbCont(x);
//    }


    if(v.size() == 1){
        vc<int> cur_ans;
        for(auto e : v[0]) cur_ans.PB(sign(e));
        ans.insert(cur_ans);
    }


    for(int i = 0; i+1 < v.size();i++){
        // i , i+1
        vc<vc<int>> new_v;
        for(int j = 0; j < i; j++){
            new_v.PB(v[j]);
        }

        vc<int> new_merged;
        for(int j = i; j <= i+1; j++){
            for(int e : v[j]) {
                new_merged.PB(-e);
            }
        }
        new_v.PB(new_merged);

        for(int j = i+2; j < v.size(); j++){
            new_v.PB(v[j]);
        }

        gen(new_v);
    }
}
void solve() {
    int n;
    cin >> n;
    vc<ll> v(n);
    loop(i,n) cin >> v[i];


    if(n == 2){
        cout << -(v[0]+v[1]) << endl;
        exit(0);
    }

    if(n == 3){
        cout << max(-v[0]+v[1]+v[2],+v[0]+v[1]-v[2]) << endl;
        exit(0);
    }

    int start = -1;
    if(n%3 == 1) start = 1;
    if(n%3 == 2) start = 0;
    if(n%3 == 0) start = 2;

    vc<int> x;
    for(int i = start; i <= n; i+=3){
        x.PB(i);
    }

    sort(all(v));
    reverse(all(v));

    for(int i = 1; i < n; i++){
        v[i] += v[i-1];
    }

    ll ans = 1e-17;
    for(int e : x){
        ll cans = (e-1>=0?v[e-1]:0) - (v.back() - (e-1>=0?v[e-1]:0));
        ans = max(ans, cans);
    }
    cout << ans;
}

int main() {

//    solve();
//    return 0;

    vc<vc<int>> v;
    for(int i = 1; i <= n; i++){
        v.push_back(vc<int>(1,i));
    }

    gen(v);


    map<int, vc<vc<int>>> mp;

    db(ans.size());
    for(auto c: ans){
        int sum = 0;
        for(int e : c) sum+=e;
        mp[sum].PB(c);
    }

    for(auto p : mp){
        for(auto vec: p.second){
            dbCont(vec);
        }
    }



    return 0;
}


/*



 */



