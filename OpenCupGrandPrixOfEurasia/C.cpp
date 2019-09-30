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

void test() {
    vector<int> n(7);
    for (int i = 0; i < 7; ++i) {
        cin >> n[i];
    }
    int d;
    cin >> d;
    vector<int> ans;
    ans.push_back(d);
    while (d--) {
        if (n[d] < n[ans.back()])
            ans.push_back(d);
    }
    reverse(all(ans));
    for (int j = 0; j < ans.size(); ++j) {
        cout << ans[j] << " ";
    }
    cout << endl;
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        test();
    }
    return 0;
}