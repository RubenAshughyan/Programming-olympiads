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

using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}

int brute(int n) {
    vc<int> v;
    for (int i = 1; i <= n; i++) v.PB(i);

    vc<int> ans(n + 1, 1234);

    loop(msk, (1 << n)) {
        vc<int> subset;
        loop(i, n) {
            if ((msk >> i) & 1) {
                subset.PB(v[i]);
            }
        }

        int mgcd = 0;
        for (int i = 0; i < subset.size(); i++) {
            for (int j = i + 1; j < subset.size(); j++) {
                int g = gcd(subset[i], subset[j]);
                mgcd = max(mgcd, g);
            }
        }

        ans[subset.size()] = min(ans[subset.size()], mgcd);
    }

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}


const int N = 500 * 1000 + 6;

vc<int> divs[N + 5];

int main() {
    int n;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j * j <= N; j++) {
            if (i % j == 0) {
                divs[i].PB(j);
                if (j * j != i) {
                    divs[i].PB(i / j);
                }
            }
        }
        sort(all(divs[i]));
    }

//    for (int i = 2; i <= 200; i++) {
//        brute(i);
//    }

    cin >> n;

    vc<int> primes;
    vc<int> ans;

    vc<int> used(N,0);

    for (int i = 2; i <= n; i++) {
        if(divs[i].size() == 2){
            primes.PB(i);
            used[i] = 1;
            ans.PB(1);
        }
    }


    int need = 2;
    while(ans.size() != n){
        bool canStayNeed = true;
        int 

        if(maxUsed <= need){
            ans.PB(n);
        }
    }





    return 0;
}


/*


 */



