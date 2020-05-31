#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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
#define x first
#define y second
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


const int N = 100 + 5;

int DEBUG = 0;

using namespace std;

int n;
int x[N];
int y[N];

ll det(pll a, pll b, pll c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}


ll R = 423151;
int gcov(int i, int j, int dx, int dy){


    pll p1 = MP(x[i],y[i]);
    pll p2 = MP(x[j],y[j]);
    pll p3 = MP(p1.x + R*dx, p1.y + R*dy);

    return det(p1,p2,p3) == 0;
}

map<pii, vc<int>> neighs[N];

ll gcd(ll a, ll b){
    if (b==0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}

pll normal(pll d){
    ll g = gcd(abs(d.x) ,abs(d.y));
    d.x /= g;
    d.y /= g;

    if(d.x < 0){
        d.x *= -1;
        d.y *= -1;
    }

    if(d.x == 0 && d.y == -1){
        d.x *= -1;
        d.y *= -1;
    }
    return d;
}

map<pll, int> usedDir;

int solveDir(pii d){
    if(usedDir[d]) return 0;
    usedDir[d] = 1;

    vc<int> used(n,0);


    vc<int> sizes;

    loop(i,n){
        if(used[i]) continue;

        used[i] = 1;
        int curSize = 1;

        for(int j : neighs[i][d]){
            if(!used[j]){
                used[j] = 1;
                curSize++;
            }
        }
        sizes.PB(curSize);
    }


    sort(all(sizes));
    dbCont(sizes);

    int ans = 0;

    // not 1
    vc<int> odds;
    vc<int> evens;

    int c1 = 0;
    for(int c : sizes){
        if(c == 1) c1++;

        if( (c&1) && c != 1){
            odds.PB(c);
        }
        if((c&1) == 0){
            evens.PB(c);
        }
    }


    while(odds.size() >= 2) {
        int o1 = odds.back(); odds.pop_back();
        int o2 = odds.back(); odds.pop_back();

        ans += o2 + 1;

        evens.PB(o1-1);
    }

    for(int ev: evens) ans += ev;

    if(odds.empty()){
        ans += min(c1,2);
        return ans;
    }

    ans += odds.front() + (c1 > 0);

    return ans;
}

void test(int testIndex){
    cin >> n;
    loop(i,n){
        cin >> x[i] >> y[i];
    }

    loop(i,N) neighs[i].clear();
    usedDir.clear();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int dx = x[j]-x[i];
            int dy = y[j]-y[i];


            pii nrm = normal(MP(dx,dy));


            neighs[i][nrm].PB(j);
            neighs[j][nrm].PB(i);
        }
    }

    int ans = 0;
    loop(i,n){
        for(int j = i+1; j < n; j++){

            int dx = x[j]-x[i];
            int dy = y[j]-y[i];
            pii nrm = normal(MP(dx,dy));


            ans = max(ans, solveDir(nrm));
        }
    }

    if(n == 1) ans = 1;

    printf("Case #%d: %d\n", testIndex, ans);
}

int main() {
    int t;
    cin >> t;
    loop(I,t) test(I+1);
    return 0;
}


/*


5
2
0 0
5 5
3
0 0
5 5
5 0
5
0 0
5 5
5 0
3 2
2 4
7
0 0
1 1
2 1
3 1
8 2
11 2
14 2
1
-1000000000 1000000000




 */



