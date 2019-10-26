#include<bits/stdc++.h>

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

const int N = 100 * 1000 + 5;


ll a[N];
int vat[N];
int m, n, q;
ll cnt[N];


void test(int tt) {
    loop(i, N) {
        a[i] = 0;
        cnt[i] = 0;
        vat[i] = 0;
    }

    cin >> n >> m >> q;
    loop(i, m) {
        int e;
        cin >> e;
        vat[e] = 1;
    }
    loop(i, q) {
        int e;
        cin >> e;
        cnt[e]++;
    }

    for (int r = 1; r <= n; r++) {
        if (cnt[r]) {
            for (int i = r; i <= n; i += r) {
                if (!vat[i])
                    a[i] += cnt[r];
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }


    printf("Case #%d: %lld\n", tt, sum);
}


int main() {
//    freopen("in.txt", "r", stdin);
//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt, t) {
        test(tt + 1);
    }

    return 0;
}
/*
3
11 1 2
8
2 3
11 11 11
1 2 3 4 5 6 7 8 9 10 11
1 2 3 4 5 6 7 8 9 10 11
1000 6 1
4 8 15 16 23 42
1
*/