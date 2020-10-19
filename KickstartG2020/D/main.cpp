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
#define ld long double
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


void test(int testIndex) {
    int n;
    cin >> n;
    // 173 -> 32bit
    vector<long double> v(n);
    loop(i, n) cin >> v[i];
    ld score = 0;
    while (v.size() != 1) {
        n = v.size();
        vc<ld> new_v(n - 1);
        ld p_single = 1.0 / (n - 1);
        ld cur_score = 0;
        for (int i = 0; i < n-1; i++)
            cur_score += v[i] + v[i + 1];
        cur_score *= p_single;
        score += cur_score;
        loop(i, n - 1) {
            new_v[i] = 0;
            new_v[i] += (v[i] + v[i + 1]);
            new_v[i] += (n - 2 - i) * v[i];
            new_v[i] += (i) * v[i + 1];
            new_v[i] *= p_single;
        }
        v = new_v;
    }
    printf("Case #%d: %.12Lf\n", testIndex, score);
}

int main() {
    int t;
    cin >> t;
    loop(I, t) test(I + 1);
    return 0;
}


/*


 4
3
2 1 10
5
19 3 78 2 31
 3
2 1 10
5
19 3 78 2 31

2
3
2 1 10


 1
5
1 1 1 1 2

  1
5
4 5 6 7 8

1
10
1 2 3 4 5 6 7 8 9 10


My main interests are problem C (Combination Lock) and D (Merge Cards).

1. Did anybody solve C without using ternary search on the final target? I am sure there is a solution avoiding ternary/binary searches.

2. In problem D after some standard thinking it's fairly possible to come up with an `n^2` approach. Is it possible to solve the problem faster maybe `O(nlogn)` or even `O(n)`?

P.S.
Since the main goal of Kickstart round is to contribute to recruiting at Google, what do you think how much is the ranking threshold this time to be contacted by Google requiter? What do you think about that magic number?


 */



