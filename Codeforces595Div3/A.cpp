#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int MOD = 998244353;
const int N = 300 * 1000 + 5;
const int M = N * 64 + 555;

int GI = 0;

vc<int> v;
int n;

map<int,int> used;


void test() {
    v.clear();
    used.clear();

    cin >> n;
    loop(i, n) {
        int e;
        cin >> e;
        e--;
        v.push_back(e);
    }

    map<int,int> ans;

    loop(i, n){
        int c = i;
        int step = 1;
        while(!used[c]){
            used[c] = 1;

            ans[c] = step;
            c = v[c];
            step++;
            
        }
    }

    loop(i,n) cout << ans[i] << ' '; cout << endl;
}

int main() {

    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}
