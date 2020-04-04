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


int n, m;
vc<int> l;

int main() {
    cin >> n >> m;;

    ll sum = 0;
    loop(i, m) {
        int e;
        cin >> e;
        l.PB(e);
        sum += e;
    }

    if(sum < n) {
        cout << -1 << endl;
        return 0;
    }

    ll avel = sum-n;

    vc<ll> pos(m);
    pos[0] = 0;
    ll x = 0;
    for(int i = 1; i < m; i++){
        x += l[i-1];
        pos[i] = x;
    }

    vc<ll> goBack(m,0);
    for(int i = 1; i < m; i++){
        int canMax = min((ll)l[i-1]-1, avel);

        avel -= canMax;
        goBack[i] = canMax;
    }

    for(int i = 1; i < m; i++){
        goBack[i] += goBack[i-1];
    }

    bool bad = false;
    for(int i = 1; i < m; i++){
        pos[i] -= goBack[i];
        if(pos[i] + l[i]-1 >= n){
            bad = true;
        }
    }

    if(bad) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < m; i++) {
            cout << pos[i] + 1 << ' ';
        }
        cout << endl;
    }



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



