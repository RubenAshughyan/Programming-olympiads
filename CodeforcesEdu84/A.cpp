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


const int N = 300 * 1000 + 5;

int DEBUG = 0;

using namespace std;

int n;
int p[N];
int c[N];

void test(){
    scanf("%d",&n);
    loop(i,n){
        scanf("%d",&p[i]);
        p[i]--;
    }
    loop(i,n) scanf("%d",&c[i]);


    vc<int> used(n,0);
    int best = 1e7;

    for(int i = 0; i < n; i++){
        if(used[i]) continue;

        int v = i;
        used[v] = 1;

        db(v);
        vc<int> cycle;
        cycle.PB(v);
        while(!used[p[v]]){
            v = p[v];
            used[v] = 1;
            cycle.PB(v);
        }


        if(DEBUG) {
            loop(i, cycle.size()) cout << cycle[i] + 1 << ' ';
            cout << endl;
        }


        int len = cycle.size();
        set<int> divs;
        for(int j = 1; j <= len; j++){
            if(len % j == 0) divs.insert(j);
        }

        for(int d: divs){
            for(int start = 0; start < d; start++){
                vc<int> xx;
                loop(j,len/d) xx.PB( cycle[(start+ (j*d)) % len]);

                bool ok  = true;
                loop(j,xx.size()){
                    if(c[xx[j]] != c[xx[0]]) ok = false;
                }

                if(ok) {
                    best = min(best, d);
                }
            }
        }

    }
    cout << best << endl;
}

int main() {
    int t;
    scanf("%d",&t);
    loop(i,t){
        test();

    }




    return 0;
}


/*

3
4
1 3 4 2
1 2 2 3
5
2 3 4 5 1
1 2 3 4 5
8
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4



 */



