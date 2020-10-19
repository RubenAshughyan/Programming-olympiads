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

int DEBUG = 1;

const int N = 1000 * 1000 + 5;


int n,m;
int c[N];

void test(int testIndex) {
    cin >> n >> m;
    loop(i,n){
        cin >> c[i];
    }


    int cur = m;
    int i = 0;
    bool can = true;
    ll ans = 0;
    while(true){
        if(i == n-1) break;

        if(cur > 0) {
            i++;
            continue;
        }

        if(c[i] == 0) {
            can = false;
            break;
        }
        ans += c[i];
    }

    if(!can) ans = -1;

    printf("Case #%d: %lld\n", testIndex, ans);
}

int main() {

    int t;
    cin>> t;
    loop(i,t) test(i+1);
    return 0;
}


/*




 */



