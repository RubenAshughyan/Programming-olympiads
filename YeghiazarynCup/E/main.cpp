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

int n,L,W;

// compress TIME


map<int,int> comp;
map<int,int> decomp;


struct item {
    int t,s,w,i;

    bool operator < (const item &that) const {
        return MP(s,MP(t,w)) < MP(that.s,MP(that.t,that.w));
    }
};


pll t[N];
void update(int v, int l, int r, int pos, int val){
    if(l == r) {
        t[v] = MP()
    }
}


vector<item> v;
dbl ans[N];


int main() {
    scanf("%d%d%d",&n,&L,&W);

    set<int> times;
    loop(i,n){
        item it;
        it.i = i;

        scanf("%d%d%d",&it.t, &it.s, &it.w);
        times.insert(it.t);
        v.PB(it);
    }

    // compress time
    int GI = 0;
    for(int e : times){
        comp[e] = GI;
        decomp[GI]=e;
        e++;
    }

    loop(i,n){
        v[i].t = comp[v[i].t];
    }

    // sort by speed
    sort(all(v));


    // time,index
    set<pll> st;

    // go over cars on speed
    for(item car: v){

        update(0,0,N-1, car.t, car.w);

        st.insert(MP(car.t, car.i));
    }


    return 0;
}


/*





 */



