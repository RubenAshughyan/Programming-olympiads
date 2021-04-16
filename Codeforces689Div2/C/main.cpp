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
#define dbl long double
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


const int N = 1000 * 1000 + 5;

int DEBUG = 1;

using namespace std;

void test() {
    int n,m;
    cin >> n >> m;
    vc<int> v(n);
    loop(i,n) cin >> v[i];

    vc<int> r(m);
    vc<dbl> p(m);
    loop(i,m) {
        cin >> r[i] >> p[i];
    }


    int goodSuff = 0;
    int need = n;
    for(int i = n-1; i >= 0; i--){
        if(v[i] == need){
            goodSuff++;
            need--;
        } else {
            break;
        }
    }

    int bad = n-goodSuff;

//    db(bad);
    dbl ans = 1.0;
    loop(i,m){
        if(r[i] >= bad) ans *= (1.0-p[i]);
    }
//    cout << ans;
    ans = 1.0-ans;

    if(bad == 0) ans = 1.0;
                         printf("%.10Lf\n", ans);

}

int main() {

    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*


4
4 3
4 3 2 1
1 0.3
3 1
4 0.6
5 3
4 2 1 3 5
3 0.8
4 0.6
5 0.3
6 5
1 3 2 4 5 6
4 0.9
5 0.3
2 0.4
6 0.7
3 0.5
4 2
1 2 3 4
2 0.5
4 0.1



 */



