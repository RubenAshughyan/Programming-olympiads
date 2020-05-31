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

int n;
int a[N];

int solve(vc<int> v, int mx){

    db(mx);
    dbCont(v);

    v.insert(v.begin(),0);



    int k = v.size()-1;




    vc<int> ps(k+1);
    ps[0] = 0;
    for(int i = 1; i <= k; i++){
        ps[i] = ps[i-1] + v[i];
    }

    auto pref_min = ps;
    for(int i = 1; i <= k; i++){
        pref_min[i] = min(pref_min[i-1], ps[i]);
    }

    auto suff_max = ps;
    for(int i = k-1; i >= 1; i--){
        suff_max[i] = max(suff_max[i+1], ps[i]);
    }


    dbCont(ps);
    dbCont(pref_min);
    dbCont(suff_max);

    int ans = 0;
    for(int i = 1; i <= k; i++){
        if(v[i] == mx){
            db(i);
            int cur = suff_max[i] - pref_min[i-1] - mx;
            ans = max(ans, cur);
        }
    }

    return ans;
}

int f(int mx){


    vc<int> cur;


    int ans = 0;
    loop(i,n){
        if(a[i] > mx){
            ans = max(ans,solve(cur, mx));
            cur.clear();
        } else {
            cur.PB(a[i]);
        }
    }
    ans = max(ans,solve(cur, mx));
    return ans;
}

int main() {
    cin >> n;

    set<int >st;
    loop(i,n) {

        cin >> a[i];
        st.insert(a[i]);
    }


    int ans = 0;
    for(int mx : st){
        ans = max(ans, f(mx));
    }


    cout << ans << endl;
    return 0;
}


/*

 */



