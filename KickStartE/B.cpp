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

const int N = 1e9 + 1234;
const double EPS = 1e-7;

bool cmp(pii a, pii b){
    return a.first*b.second < a.second*b.first;
}

void f(ll total_c, vector<pii> dec_e, int a, int b){
    ll e = 0;
    if (b == 0 && total_c >= a){
        cout << "Y";
        return;
    }
    for (int i = 0; i < dec_e.size(); ++i) {
        if (e + dec_e[i].first >= b) {
            double f = 1.0 * (b - e) / dec_e[i].first;
            double dc = f * dec_e[i].second + a;
            if (total_c < dc - EPS)
                cout << "N";
            else
                cout << "Y";
            return;
        } else {
            ll c = dec_e[i].second;
            total_c -= c;
            e += dec_e[i].first;
        }
    }
    cout<<"N";
}

void test(int tt) {
    cout << "Case #" << tt << ": ";
    int d, s;
    cin >> d >> s;
    vector<pii> dec_e(s);
    ll total_c = 0;
    for (int i = 0; i < s; ++i) {
        int ci, ei;
        cin >> ci >> ei;
        total_c += ci;
        dec_e[i] = MP(ei, ci);
    }

    sort(all(dec_e), cmp);
    reverse(all(dec_e));

    for (int k = 0; k < d; ++k) {
        int a, b;
        cin >> a >> b;
        f(total_c, dec_e, a, b);
    }

    cout << endl;
}



int main() {

    int t;
    cin >> t;


    loop(i, t) {
        test(i + 1);
    }

    return 0;
}
