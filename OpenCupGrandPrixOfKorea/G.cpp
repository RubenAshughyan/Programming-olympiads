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

const int N = 300 * 1000 + 5;

int n, m, s, t;
vector< vector<pii> > gp;
vector< vector<int> > gpR;
vector<bool> visited;
vector<bool> reverseReachable;

bool isImpossible() {
    visited.assign(n, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto& [c, v] : gp[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return !visited[t];
}

void findReachables() {
    reverseReachable.assign(n, false);

    queue<int> q;
    q.push(t);
    reverseReachable[t] = true;


    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : gpR[u]) {
            if (!reverseReachable[v]) {
                q.push(v);
                reverseReachable[v] = true;
            }
        }
    }
}

vector<int> solution;

void dfs(int v) {
    if (visited[v]) {
        cout << "TOO LONG" << endl;
        exit(0);
    }
    if (v == t) {
        for(int c : solution) {
            cout << c << " ";
        }
        exit(0);
    }

    visited[v] = true;

    for(auto& [c, u] : gp[v]) {
        if (reverseReachable[u]) {
            solution.PB(c);
            dfs(u);
            return;
        }
    }

}

int main() {
    cin >> n >> m >> s >> t;
    s--;
    t--;
    gp.resize(n);
    gpR.resize(n);
    visited.resize(n);
    reverseReachable.resize(n);

    for(int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--;
        v--;
        gp[u].PB(MP(c, v));
        gpR[v].PB(u);
    }

    for(int i = 0; i < n; i++) {
        sort(all(gp[i]));
    }

    if (isImpossible()) {
        puts("IMPOSSIBLE");
        return 0;
    }

    findReachables();


    visited.assign(n, false);
    dfs(s);

    return 0;
}

/*



 
 */