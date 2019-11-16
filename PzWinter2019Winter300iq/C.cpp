//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

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
#define dbl long double
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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

ll DEBUG = 1;
const int N = 300 * 1000 + 123;
const int INF = 2000 * 1000 * 1000 + 123456;

// 14:38
ll n, k;
ll p[N], q[N];
pair<ll, ll> a[N], b[N];
int id[N];

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
        a[i] = MP(p[i], -n + i);
        id[n - i] = p[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &q[i]);
        b[i] = MP(q[i], -n + i + 1);
    }
    sort(a, a + n);
    sort(b, b + n);
    k = (n * 1ll * (n - 1) / 2 - k);
    for (int i = 1; i <= n; i++) {
        int to_r = n - id[i];
        if (to_r < k) {
            k -= to_r;
            a[id[i] - 1].y = n;
        }
        else {
            int st = id[i];
            sort(b + st, b + n, [](auto a, auto b) {return a.y < b.y; });
            a[id[i] - 1].y = -b[n - k].y;
            k = 0;
            break;
        }
    }
    assert(k == 0);
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i].y << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i].y << " ";
    }
    cout << endl;
    return 0;
}

/*

5 3
17 18 17 30 35

8 5
4 1 3 7 4 8 1 2

8 4
4 1 3 7 4 8 1 2
 */