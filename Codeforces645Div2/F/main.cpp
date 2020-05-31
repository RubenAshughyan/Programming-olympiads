#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:256000000")

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

int n;

vc<ll> a, ra, b;
int pCount = 0;

string ans = "";

void f(int d = 0) {

    db(d);
    dbCont(b);
    dbCont(ra);

    if(d >= 500*1000) {
        assert(n == 2);
    }

    if (b == a) {
        return;
    }
    if (b == ra) {
        ans.PB('R');
        return;
    }


    // increasing
    bool increasing = true;
    for (int i = 0; i + 1 < n; i++) {
        increasing = increasing && (b[i] < b[i + 1]);
    }

    if (increasing) {
        // krchati
        for (int i = n-1; i-1 >= 0; i--) {
            b[i] -= b[i - 1];
        }
        ans.PB('P');
        f(d + 1);
        return;
    }


    bool decreasing = true;
    for (int i = 0; i + 1 < n; i++) {
        decreasing = decreasing && (b[i] > b[i + 1]);
    }
    if (decreasing) {
        reverse(all(b));
        ans.PB('R');
        f(d + 1);
        return;
    }


    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

int main() {
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);

    loop(i, n) {
        scanf("%lld", &a[i]);
    }
    loop(i, n) {
        scanf("%lld", &b[i]);
    }

    if (n == 1) {
        if (a == b) {
            cout << "SMALL" << endl;
            cout << 0 << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        return 0;
    }

    ra = a;
    reverse(all(ra));

    f();

    int p = 0;
    for (char c : ans) p += c == 'P';
    if (p > 200 * 1000) {
        cout << "BIG" << endl;
        cout << p << endl;
    } else {

        reverse(all(ans));

        cout << "SMALL" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    return 0;
}


/*


 2
1 1
3000 1


 3
 1 1 1
 1 3 5

 */



