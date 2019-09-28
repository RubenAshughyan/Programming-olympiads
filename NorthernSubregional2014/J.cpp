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
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
#define loop1(xxx, yyy) for(int xxx = 1; xxx <= yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
//#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

ll sx, sy, fx, fy, v;
ll n, k;

vector<pair<int, pll> > wws;

int main() {
    cin >> sx >> sy >> fx >> fy;
    cin >> n >> k >> v;
    ll total_wx = 0, total_wy = 0;
    for (int i = 0; i < n; ++i) {
        ll t, wx, wy;
        cin >> t >> wx >> wy;
        wws.push_back(MP(t, MP(wx, wy)));
        if (i){
            total_wx += (t - wws[i-1].first) * wws[i-1].second.first;
            total_wy += (t - wws[i-1].first) * wws[i-1].second.second;
        }
    }
    total_wx += (k - wws[wws.size()-1].first) * wws[wws.size()-1].second.first;
    total_wy += (k - wws[wws.size()-1].first) * wws[wws.size()-1].second.second;
    ll ddx = fx - sx - total_wx;
    ll ddy = fy - sy - total_wy;
    if (ddx * ddx + ddy * ddy > k * k * v * v){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    dbl dx = ((dbl)(ddx % k)) / (dbl)k + (ddx / k), dy = ((dbl)(ddy % k)) / (dbl)k + (ddy / k);
    dbl x = sx, y = sy;
    int ind = 0;
    for (int j = 0; j < k; ++j) {
        if (ind != wws.size() - 1 && wws[ind + 1].first == j)
            ind++;
        x += dx;
        y += dy;
        x += wws[ind].second.first;
        y += wws[ind].second.second;
//        cout << x << " " << y << endl;
        printf("%.15Lf %.15Lf\n", x,y);
    }
    return 0;
}
