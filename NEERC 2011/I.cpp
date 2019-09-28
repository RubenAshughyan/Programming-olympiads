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

const int N = 100005;

int conn[N];
int n, u, v;

int main() {
//    freopen("kingdom.in", "r", stdin);
//    freopen("kingdom.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        conn[u]++;
        conn[v]++;
    }

    vector<int> leafs;
    for(int i = 1; i <= n; i++)
        if (conn[i] == 1)
            leafs.PB(i);

    cout << (leafs.size() + 1) / 2 << endl;
    for(int i = 0; i < leafs.size(); i += 2)
        cout << leafs[i] << " " << leafs[i + 1] << endl;
    if (leafs.size() & 1) {
        cout << leafs[0] << " " << leafs.back() << endl;
    }

    return 0;
}

/*
5
1 2
2 3
3 4
3 5

 */