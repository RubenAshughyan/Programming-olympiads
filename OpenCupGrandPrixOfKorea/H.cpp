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

const int N = 250 * 1000 + 5;
int n;
vector<int> a, b;

int solve1() {
    double mid = (n + 1) / 2.;
    int ans = 0, bind, aind;
    for (bind = 0, aind = 0; aind < n && bind < n;) {
        if (a[aind] < mid && b[bind] < mid) {
            aind++;
            continue;
        }
        if (a[aind] > mid && b[bind] < mid) {
            ans += abs(aind - bind);
            aind++;
            bind++;
            continue;
        }
        if (2 * b[bind] == n + 1) {
            bind++;
            continue;
        }
        if (2 * a[aind] == n + 1) {
            aind++;
            continue;
        }
        if (b[bind] > mid) {
            bind++;
            continue;
        }
        assert(false);
    }
    return ans;
}

int solve2() {
    double mid = (n + 1) / 2.;
    int ans = 0, bind, aind;
    for (bind = 0, aind = 0; aind < n && bind < n;) {
        if (a[aind] < mid && b[bind] <= mid) {
            aind++;
            continue;
        }
        if (a[aind] >= mid && b[bind] <= mid) {
            ans += abs(aind - bind);
            aind++;
            bind++;
            continue;
        }
        if (b[bind] > mid) {
            bind++;
            continue;
        }
        assert(false);
    }
    return ans;
}

int main() {
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
//    db(solve1());
//    db(solve2());
    cout << min(solve1(), solve2()) << endl;
    return 0;
}

/*
3
1 2 3
1 2 3

 4
3 4 1 2
3 2 4 1
 */