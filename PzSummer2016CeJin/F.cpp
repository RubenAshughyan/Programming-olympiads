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


const int N = 1000*1000+7;
int n, c;

void calc(double t, double v){
    printf("%.10lf\n", sqrt(2. * c * t + v * v));
}
int main() {
    cin >> n >> c;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int vv, xx, dd;
        cin >> vv >> xx >> dd;
        v.push_back(vv);
    }
    sort(all(v));
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int t, k;
        cin >> t >> k;
        calc(t, v[k-1]);
    }

    return 0;
}
