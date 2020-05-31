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



int main() {
    int n,s;

    cin >> n>> s;


    vc<int> v;
    loop(i,n-1) v.PB(1);
    v.PB(s - (n-1));

    int k = s/2;

    vc<int> ka(s+5,0);

    ka[0] = 1;
    bool ok = true;

    int curSum = 0;
    loop(i,n){
        curSum += v[i];
        if(curSum-k >= 0 && ka[curSum - k]) ok = false;
        if(curSum-(s-k) >= 0 && ka[curSum - (s-k)]) ok = false;

        ka[curSum] = 1;
    }

    if(!ok) {
        cout<< "NO" << endl;
    } else {
        cout<< "YES" << endl;
        loop(i,n) printf("%d ",v[i]);
        printf("\n");
        cout << k << endl;
    }


    return 0;
}


/*

 */



