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

long long dp[27][10005][2];
long long ndp[27][10005][2]={};

int main() {
//    freopen("dictionary.in", "r", stdin);
//    freopen("dictionary.out", "w", stdout);
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; ++i) {
        string si;
        cin >> si;
        s.insert(si);
    }
    int ind = 0;

    for (int j = 1; j <= 80; ++j) {
        ind = 0;
        for (string si:s) {
            ind++;
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