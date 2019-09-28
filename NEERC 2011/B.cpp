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

const int N = 100005;

int n, m, ln;

void bin(int k, bool nall = false) {
    vector<int> v;
    while (k) {
        v.push_back(k % 2);
        k /= 2;
    }
    while (v.size() < ln - nall)
        v.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[v.size() - 1 - i];
    }
    cout << endl;
}

int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);

    cin >> m;
    n = 1;
    ln = 0;
    while (n < m){
        n *= 2;
        ln++;
    }
    for (int i = 0; i < m; ++i) {
        if (i < n - m)
            bin(i, true);
        else {
            bin(((i - n + m) / 2 + (n - m)) * 2 + (m - i) % 2);
        }
    }
    return 0;
}

/*
5
1 2
2 3
3 4
3 5

 */