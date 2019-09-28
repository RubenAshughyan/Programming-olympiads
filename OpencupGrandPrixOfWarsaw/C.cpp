#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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


int n;

int ask(int i, int j) {
    if (i <= 0 || j <= 0 || i > n || j > n)
        return -1;
    cout << "? " << i << " " << j << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

void say(pii mx) {
    cout << "! " << mx.first << " " << mx.second << endl;
    fflush(stdout);
    exit(0);
}

int main() {
//    freopen("in.txt", "r", stdin);

    cin >> n;
    int l = 1, r = n, d = 1, u = n;
    pii maxind = {1, (n + 1) / 2};
    while (l < r - 2 || d < u - 2) {
        if (r - l >= u - d) {
            int m = (r + l) / 2;
            int maxi = -1;
            int maxx = -1;
            for (int j = maxind.second; j != m;) {
                int x = ask(maxind.first, j);
                if (x > maxx) {
                    maxx = x;
                    maxi = -j;
                }
                if (j > m)
                    j--;
                else
                    j++;
            }
            for (int i = d; i <= u; ++i) {
                int x = ask(m, i);
                if (x > maxx) {
                    maxx = x;
                    maxi = i;
                }
            }
            if (maxi < 0) {
                if (maxind.first > m)
                    l = m;
                else
                    r = m;
                maxind = {maxind.first, -maxi};
            } else {
                int left = ask(m - 1, maxi), lu = ask(m - 1, maxi + 1), ld = ask(m - 1, maxi - 1);
                int right = ask(m + 1, maxi), ru = ask(m + 1, maxi + 1), rd = ask(m + 1, maxi - 1);
                int maxval = max(max(left, right), max(max(lu, ru), max(ld, rd)));
                if (maxval == left) {
                    r = m;
                    maxind = {m - 1, maxi};
                }
                if (maxval == right) {
                    l = m;
                    maxind = {m + 1, maxi};
                }
                if (maxval == lu) {
                    r = m;
                    maxind = {m - 1, maxi + 1};
                }
                if (maxval == ru) {
                    l = m;
                    maxind = {m + 1, maxi + 1};
                }
                if (maxval == ld) {
                    r = m;
                    maxind = {m - 1, maxi - 1};
                }
                if (maxval == rd) {
                    l = m;
                    maxind = {m - 1, maxi - 1};
                }
            }
        } else {
            int m = (u + d) / 2;

            int maxi = -1;
            int maxx = -1;
            for (int j = maxind.first; j != m;) {
                int x = ask(j, maxind.second);
                if (x > maxx) {
                    maxx = x;
                    maxi = -j;
                }
                if (j > m)
                    j--;
                else
                    j++;
            }
            for (int i = l; i <= r; ++i) {
                int x = ask(i, m);
                if (x > maxx) {
                    maxx = x;
                    maxi = i;
                }
            }
            if (maxi < 0) {
                if (maxind.first > m)
                    d = m;
                else
                    u = m;
                maxind = {-maxi, maxind.second};
            } else {
                int up = ask(maxi, m + 1), ur = ask(maxi + 1, m + 1), ul = ask(maxi - 1, m + 1);
                int down = ask(maxi, m - 1), dr = ask(maxi + 1, m - 1), dl = ask(maxi - 1, m - 1);
                int maxval = max(max(up, down), max(max(ur, dr), max(ul, dl)));
                if (maxval == up) {
                    maxind = {maxi, m + 1};
                    d = m;
                }
                if (maxval == down) {
                    u = m;
                    maxind = {maxi, m - 1};
                }
                if (maxval == ur) {
                    d = m;
                    maxind = {maxi + 1, m + 1};
                }
                if (maxval == ul) {
                    d = m;
                    maxind = {maxi - 1, m + 1};
                }
                if (maxval == dr) {
                    u = m;
                    maxind = {maxi + 1, m - 1};
                }
                if (maxval == dl) {
                    u = m;
                    maxind = {maxi - 1, m - 1};
                }
            }
        }
    }
    pii maxi;
    int maxx = -1;
    for (int j = d; j <= u; ++j) {
        for (int i = l; i <= r; ++i) {
            int x = ask(i, j);
            if (x > maxx) {
                maxx = x;
                maxi = {i, j};
            }
        }
    }
    say(maxi);
    return 0;
}
/*
 *

3 6
1 2 3
get 1
get 3
shuffle 1 2
shuffle 2 3
get 1
get 3



*/