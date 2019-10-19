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

const int N = 100*1000+5;

const int MOD = 1000*1000*1000+7;
long long a[N], n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int index = max_element(a, a + n) - a;
    long long aa = index;
    long long bb = accumulate(a, a + index, 0ll, [](long long x, long long y) { return x + y; });
    long long A = a[index] + n - 1;
    long long B = accumulate(a, a + n, 0ll, [](long long x, long long y) { return x + y; });
//    db(aa);
//    db(bb);
//    db(A);
//    db(B);
    cout << (ceil(max(k - bb + 0., 0.) / B) <= floor((k - aa + 0.) / A) && k >= aa ? "YES" : "KEK") << endl;

    return 0;
}
/*

NEWS
EWNS
*/