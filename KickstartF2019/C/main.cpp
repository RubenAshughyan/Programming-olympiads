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

const int N = 100 * 1000 + 123;

int n;
ll w[N];
vc<int> g[N];

int par[N];

void dfsPar(int v, int p) {
    par[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfsPar(to, v);
        }
    }
}

bool cmp(pll a, pll b){
    return a.first-a.second < b.first-b.second;
}

map<int, map<int, map<int,ll>>> memo;

ll solve(int v, int light, int ignore_root) {
//    db(v);
//    db(light);
//    db(ignore_root);
    ll ans = 0;

    if(memo[v][light].count(ignore_root)){
        ans = memo[v][light][ignore_root];
    }else if(par[v] != -1 && g[v].size() == 1){
        if(ignore_root) ans = 0;
        else if(!light) ans = 0;
        else ans = w[v];
    } else if (light) {
        ans = ignore_root ? 0 : w[v];

        for (int ch : g[v]) {
            if (ch != par[v]) {
                ans += max(
                        solve(ch, 0, 1),
                        solve(ch, 1, 1)
                );
                ans += w[ch];
            }
        }
    } else {

        // dont light v
        vc<pll > ch_ans;
        for (int ch : g[v]) {
            if (ch != par[v]) {
                ch_ans.push_back({
                                         solve(ch, 0, 0),
                                         solve(ch, 1, 0)
                                 });
//                cout << "vals" << ch_ans.front().first << ' ' << ch_ans.front().second << endl;

            }
        }


        ll sum_children_not_light = 0;
        for (pll e: ch_ans) sum_children_not_light += e.first;

        ll light_is_chere_child = ignore_root ? 0 : w[v];
        bool light_guaranteed = false;
        for (pll e : ch_ans) {
            if (e.second >= e.first) {
                light_guaranteed = true;
            }
            light_is_chere_child += max(e.first, e.second);
        }
        if (!light_guaranteed) {
            sort(all(ch_ans), cmp);
            light_is_chere_child -= ch_ans.front().first;
            light_is_chere_child += ch_ans.front().second;
        }

        ans = max(sum_children_not_light, light_is_chere_child);
    }
//    db(ans);
    return memo[v][light][ignore_root] = ans;
}

void test(int tt) {

    cin >> n;

    // clear
    memo.clear();
    loop(i,n){
        g[i].clear();
    }

    loop(i, n) cin >> w[i];
    loop(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsPar(0, -1);


    ll ans =
            max(
                    solve(0, 0, 0),
                    solve(0, 1, 0)
            );

    printf("Case #%d: %lld\n", tt, ans);
}


int main() {
//    freopen("in.txt", "r", stdin);

//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt, t) {
        test(tt + 1);
    }

    return 0;
}