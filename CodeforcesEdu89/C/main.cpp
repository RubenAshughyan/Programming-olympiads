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


const int N = 30 + 5;

int DEBUG = 1;

using namespace std;

int f[N][N];
int n, m;

void test() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }

    map<int, vc<int>> mp;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if((n+m-1)%2 == 1 && (i+j-1) == ((n+m-1)+1)/2) continue;

            if(2*(i+j-1) <= m+n-1) {
                mp[i+j].PB(f[i][j]);
            }

            else {
                mp[(n - i + 1) + (m - j + 1)].PB(f[i][j]);
            }

        }
    }


    int ans = 0;
    for(auto p : mp){
        auto v = p.second;


//        dbCont(v);
        int z = 0;
        for(int e : v) z+= e==0;

        ans += min(z, sz(v)-z);
    }
    cout << ans << endl;

}

int main() {


    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}


/*


4
2 2
1 1
0 1
2 3
1 1 0
1 0 0
3 7
1 0 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 0 1
3 5
1 0 1 0 0
1 1 1 1 0
0 0 1 0 0

 */



