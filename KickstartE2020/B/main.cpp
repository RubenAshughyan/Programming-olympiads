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


void imp() {
    cout << "IMPOSSIBLE" << endl;
}

bool check(vc<int> v, int a, int b, int c) {
    dbCont(v);
    int aa = 0;
    int bb = 0;
    int cc = 0;
    for (int i = 0; i < v.size(); i++) {
        bool a_sees = true;
        for (int j = 0; j < i; j++) if (v[j] > v[i]) a_sees = false;

        bool b_sees = true;
        for (int j = i + 1; j < v.size(); j++) if (v[j] > v[i]) b_sees = false;

        aa += a_sees;
        bb += b_sees;
        cc += a_sees && b_sees;
    }

    return a == aa && b == bb && c == cc;


}

void test(int testIndex) {
    printf("Case #%d: ", testIndex);

    db(testIndex);
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int A = a;
    int B = b;
    int C = c;

    vc<int> v;
    int MX = n;

    loop(i, c) {
        v.PB(MX);
    }


    a -= c;
    b -= c;
    if (v.size() + a + b > n) {
        imp();
        return;
    }


    loop(xxx, b) v.PB(MX - 1);
    loop(xxx, a) v.insert(v.begin(), MX - 1);


    db("after this");
    dbCont(v);
    if (v.size() >= 2) {
        while (v.size() < n) {
            v.PB(1);
            swap(v[v.size() - 1], v[v.size() - 2]);
        }
    }


    if (v.size() != n || !check(v,A, B, C)) {
        imp();
        return;
    }

    for (int e : v) cout << e << ' ';
    cout << endl;

}

int main() {
    int t;
    cin >> t;
    loop(I, t) test(I + 1);
    return 0;
}


/*

3
4 1 3 1
4 4 4 3
5 3 3 2


 */



