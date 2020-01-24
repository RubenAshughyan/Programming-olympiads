#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;

void testmia() {
    vc<int> xs;
    int val = 0;
    for (int i = 0; i < 64; ++i) {
        int x;
        cin >> x;
        xs.push_back(x);
        if (x)
            val ^= i;
    }
    int y;
    cin >> y;
    val ^= y - 1;
    for (int j = 0; j < 8; ++j) {
        for (int k = 0; k < 8; ++k) {
            int i = k + j * 8;
            if (k)
                cout << " ";
            if (i != val) {
                cout << xs[i];
            } else {
                cout << 1 - xs[i];
            }
        }
        cout << endl;
    }
    cout << "---" << endl;
}

void testdanilla() {
    int val = 0;
    for (int i = 0; i < 64; ++i) {
        int x;
        cin >> x;
        if (x)
            val ^= i;
    }
    string q;
    cin >> q;
    cout << val + 1 << endl;
}

int main() {
    string s;
    cin >> s;

    int t;
    cin >> t;
    loop(i, t) {
        if (s == "Mia")
            testmia();
        else
            testdanilla();
    }
    return 0;
}
/*
Danilla
2
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
---
0 1 1 0 1 0 0 1
1 0 0 1 0 1 1 0
1 0 0 1 0 1 1 0
0 1 1 0 1 0 1 1
0 1 1 0 1 0 0 1
1 0 0 1 0 1 1 0
1 0 0 1 0 1 1 0
0 1 1 0 1 0 0 1
---
*/