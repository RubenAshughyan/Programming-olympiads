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


const int N = 1000 + 5;

int DEBUG = 0;

using namespace std;

void test() {
    int n,x;
    cin >> n >> x;
    x--;

    vc<int> g[N];
    loop(i,n-1){
        int u,v;
        cin >> u >> v;

        u--,v--;
        g[u].PB(v);
        g[v].PB(u);
    }

    string S[2] = {"Ayush", "Ashish"};

    if(g[x].size() <= 1){
        cout << S[0] << endl;
        return ;
    }

    if( (n-3) % 2 == 1){
        cout << S[0] << endl;
    } else {
        cout << S[1] << endl;
    }



}

int main() {
    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*

 1234
 4 1
 1 2
 1 3
 2 4

 */



