#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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

const int N = 300 * 1000 + 5;

using namespace std;


int main() {
    int a, b;
    int c, d;

    cin >> a >> b;
    cin >> c >> d;

    int x1 = a + c;
    int x2 = b + d;

    if (abs(x1 - x2) > 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (b < a && c) {
        cout << "NO" << endl;
        return 0;
    }
    if (c < d && b) {
        cout << "NO" << endl;
        return 0;
    }

    int sum = a + c + b + d;
    vc<int> ans(sum);

    if (x1 >= x2) {
        for (int j = 0; j < a; ++j) ans[2 * j] = 0;
        for (int j = 0; j < c; ++j) ans[2 * j + 2 * a] = 2;

        for (int j = 0; j < b; ++j) ans[2 * j + 1] = 1;
        for (int j = 0; j < d; ++j) ans[2 * j + 1 + 2 * b] = 3;
    }
    if (x2 >= x1) {
        for (int j = 0; j < b; ++j) ans[2 * j] = 1;
        for (int j = 0; j < d; ++j) ans[2 * j + 2 * b] = 3;

        for (int j = 0; j < a; ++j) ans[2 * j + 1] = 0;
        for (int j = 0; j < c; ++j) ans[2 * j + 1 + 2 * a] = 2;
    }
    for (int i = 1; i < ans.size(); ++i)
        if (abs(ans[i] - ans[i - 1]) != 1) {
            cout << "NO" << endl;
            return 0;
        }


    cout << "YES\n";
    loop(i, ans.size()) cout << ans[i] << " ";
}