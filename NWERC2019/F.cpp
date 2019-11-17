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

using namespace std;
//#define printf(...) (0)
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}
ostream& operator << (ostream& out, pii& elem) { out << "{ " << elem.x << " " << elem.y << " }"; return out; }




const int DEBUG = 1;

int n, m, d;
map<int, int> nums;
vector<vector<pii>> gp;


int main() {
    scanf("%d", &n);
    gp.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &d);
            if (nums.find(d) == nums.end()) {
                ;
            }
            else {
                gp[i].emplace_back(nums[d], d);
                gp[nums[d]].emplace_back(i, d);
            }
            nums[d] = i;
        }
    }
//    for(int i = 0; i < n; i++) {
//        dbCont(gp[i]);
//    }

    vector<bool> visited(n, false);
    vector<pair<pii, int>> edges;
    queue<int> q;
    int cnt = 0;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cnt++;
        for(auto& nxt : gp[v]) {
            int u = nxt.first;
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                edges.PB(MP(MP(v + 1, u + 1), nxt.second));
            }
        }
    }
    if (cnt != n) {
        cout << "impossible" << endl;
        return 0;
    }
    else {
        for(auto& edge : edges) {
            printf("%d %d %d\n", edge.x.x, edge.x.y, edge.y);
        }
    }
    return 0;
}