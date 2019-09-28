
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

const double dinf = 1e18;

int r, s, m, d, n;
vector<int> brands;
vector<vector<int>> ingreds;
set<pii> incomp;

int main() {
    cin >> r >> s >> m >> d >> n;
    brands.resize(r);
    for(int i = 0; i < r; i++)
        cin >> brands[i];

    ingreds.resize(s + m + d);
    for(int i = 0; i < s + m + d; i++) {
        int sz;
        cin >> sz;
        ingreds[i].resize(sz);
        for(int j = 0; j < sz; j++) {
            cin >> ingreds[i][j];
            ingreds[i][j]--;
        }
    }

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u > v)
            swap(u, v);
        incomp.insert(MP(u, v));
    }

    int ing[1005];
    ll ans = 0;
    double dans;
    for(int i = 0; i < s; i++) {
        for(int j = s; j < s + m; j++) {
            for(int k = s + m; k < s + m + d; k++) {
                if (incomp.find(MP(i, j)) != incomp.end() ||
                    incomp.find(MP(j, k)) != incomp.end() ||
                    incomp.find(MP(i, k)) != incomp.end())
                    continue;
                memset(ing, 0, sizeof(ing));

                for(auto b : ingreds[i])
                    ing[b] = 1;
                for(auto b : ingreds[j])
                    ing[b] = 1;
                for(auto b : ingreds[k])
                    ing[b] = 1;
                ll tmpAns = 1;
                double dtans = 1;
                for(int b = 0; b < r; b++) {
                    //db(b);
                    //db(ing[b]);
                    if (ing[b]) {
                        tmpAns *= brands[b];
                        dtans *= brands[b];
                    }

                    if (dtans > dinf)
                    {
                        cout << "too many\n";
                        return 0;
                    }
                }
                ans += tmpAns;
                dans += dtans;
            }
        }
    }
    if (dans > dinf || ans > 1000000000000000000ll) {
        cout << "too many\n";
        return 0;
    }
    cout << ans << endl;

    return 0;
}
/*
3 4
1 5
6 3
14 6

3 5
1 5
6 3
14 6

5 10
1 2
2 6
3 9
15 6
17 7
 */