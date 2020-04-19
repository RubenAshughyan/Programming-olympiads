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


int DEBUG = 0;

using namespace std;

const int N = 1000 * 1000 + 5;

vector<int> t;
int n;

void init(int nn) {
    n = nn;
    t.assign(n, 0);
}

int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += t[r];
    return result;
}

void inc(int i, int delta) {
    for (; i < n; i = (i | (i + 1)))
        t[i] += delta;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}


map<ll,ll> compress;
map<ll,ll> decomp;

int getI(int s){


    db(s);
    int l = 0, r = n-1,mid;

    while(l < r){
        mid = (l+r)/2;
        if(sum(0, mid) >= s){
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
    cin >> n;

    init(n);

    vc<ll> v(n);
    set<ll> st;
    loop(i,n){
        ll e;
        scanf("%lld",&e);
        v[i] = e;
        st.insert(e);
    }

    int GI = 0;
    for(ll e : st){
        compress[e] = GI;
        decomp[GI] = e;

        GI++;
    }


    ll ans = 0;
    loop(i,n){
        // add

        inc(compress[v[i]], +1);

//        cout << endl;
//        loop(j,n) cout << sum(j,j) << ' '; cout << endl;


        // kent hat
        if( (i+1) % 2 == 1){
            int sum = (i+1+1)/2;

            int ind = getI(sum);

            db(ind);
            ans += 2*decomp[ind];
            db(decomp[ind]);
        } else {

            int sum = (i+1)/2;

            int i1 = getI(sum);
            int i2 = getI(sum+1);

            ans += (decomp[i1] + decomp[i2]);

            db((decomp[i1] + decomp[i2]));

        }

    }
    cout<< ans/2.0 << endl;



    return 0;
}

/*
......qQ
.......b
........
........
........
........
........
........


 */



