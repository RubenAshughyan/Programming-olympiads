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
const int INF = 1000000000;


using namespace std;

vector<vector<int>> gp;
char graph[505][505];
bool vis[505];
int n, k;

void dfs(int v) {
    vis[v] = true;
    for (int i = 0; i < n; i++)
        if (!vis[i] && graph[v][i] == '1') {
            gp[v].PB(i);
            dfs(i);
        }
}

vector<int> solve(int v) {
    vector<int> res {v};

    for (int ch : gp[v]) {
        auto tmp = solve(ch);
        // db(ch);
        // dbCont(tmp);
        for (int i = (int)tmp.size() - 1; i >= 0; i--)
            res.PB(tmp[i]);
        // res.PB(tmp[0]);
    }
    return res;
}

int main() {
    cin >> n >> k;
    gp.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> graph[i];
    }

    dfs(0);
    for(int i = 0; i < n; i++) {
        //dbCont(gp[i]);
    }

    for (int i = 0; i < n; i++)
        vis[i] = false;

    auto ans = solve(0);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    cout << endl;


    return 0;
}

/*

10 3
0100000100
1010000000
0101001000
0010110000
0001000000
0001000000
0010000000
1000000011
0000000100
0000000100

*/