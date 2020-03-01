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
vc<int> a,b;

bool can(int mx){

    int aScore = 0;
    int bScore = 0;

    loop(i,n){
        if(a[i] == b[i]) continue;

        if(a[i] == 0){
            bScore+=1;
        } else {
            aScore += mx;
        }

    }
    return aScore > bScore;
}

int main() {
    cin >> n;
    loop(i,n){
        int e;
        cin >> e;
        a.PB(e);
    }

    loop(i,n){
        int e;
        cin >> e;
        b.PB(e);
    }

    for(int mx = 1; mx < 1e5; mx++){
        if(can(mx)){
            cout << mx << endl;
            return 0;
        }
    }

    cout << -1 << endl;


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



