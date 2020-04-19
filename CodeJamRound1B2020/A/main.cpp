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

int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};
string IMP = "IMPOSSIBLE";

map<pll, int> used;
map<pll, string> memo;
string solve(ll x, ll y){
    if(memo.count({x,y})) return memo[{x,y}];


    if(used[{x,y}]) return IMP;
    used[{x,y}] = 1;




    db(x);
    db(y);
    // base
    if(x == 0 && y == 0) return "";

    loop(d,4){
        ll nx = x - dx[d];
        ll ny = y - dy[d];
        if(abs(nx)%2==0 && abs(ny)%2 == 0 ){
            db(d);
            string s = solve(nx/2,ny/2);
            if(s != IMP) {
                return memo[{x,y}] = to_string(d)+s;
            }
        }
    }

    return memo[{x,y}] = IMP;
}

void test(int testIndex){
    used.clear();


    ll x,y;
    cin >> x >> y;

    string s = solve(x,y);

    string res = "";
    string S = "NESW";

    if(s != IMP) {
        for (char c : s) {
            int d = c - '0';
            res += S[d];
        }
    } else {
        res = IMP;
    }
    printf("Case #%d: %s\n", testIndex, res.c_str());
}

int main() {
    int t;
    cin >> t;
    loop(I,t) test(I+1);
    return 0;
}


/*


 4
2 3
-2 -3
3 0
-1 1



 */



