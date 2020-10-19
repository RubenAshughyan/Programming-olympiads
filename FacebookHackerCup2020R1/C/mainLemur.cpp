///////////////////////////////     _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>
using namespace std;
const int N = 1000005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
int t;
int n, k;
vector <int> g[N];
int col[N], p[N];
int sum[N];
multiset <int> Q;
multiset <int>::iterator it;
void dfs(int v, int p) {
    sum[v] = col[v];
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        dfs(to, v);
        if (sum[v] != 0) {
            sum[v] += sum[to];
            if (sum[to] != 0) {
                Q.erase(Q.find(sum[to]));
                sum[to] = 0;
            }
        }
    }
    if (sum[v] != 0) {
        Q.insert(sum[v]);
    }
}
int mx1, mx2;
int cnt1, cnt2;
long long answ1, answ2;
int s1[N], s2[N];
void solve1(int v, int p) {
    s1[v] = (sum[v] == mx1);
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        solve1(to, v);
        ///
        s1[v] += s1[to];
        ///
        if (col[to] + col[v] < 2) {
            long long S1 = mx1 * 1ll * (cnt1 - s1[to]);
            long long S2 = mx1 * 1ll * s1[to];
            answ2 += S1 * S2;
        }
    }
}
void solve2(int v, int p) {
    s1[v] = (sum[v] == mx1);
    s2[v] = (sum[v] == mx2);
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        solve2(to, v);
        ///
        s1[v] += s1[to];
        s2[v] += s2[to];
        ///
        if (col[to] + col[v] < 2) {
            long long S1 = mx1 * 1ll * (cnt1 - s1[to]);
            long long S2 = mx2 * 1ll * s2[to];
            answ2 += S1 * S2;
            ///
            S1 = mx2 * 1ll * (cnt2 - s2[to]);
            S2 = mx1 * 1ll * s1[to];
            answ2 += S1 * S2;
        }
    }
}
void clean() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    while (!Q.empty()) {
        Q.erase(Q.begin());
    }
}
int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '*') {
                col[i] = 1;
            } else {
                col[i] = 0;
            }
        }
        for (int i = 2; i <= k + 1; i++) {
            scanf("%d", &p[i]);
            g[ p[i] ].push_back(i);
        }
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        for (int i = k + 2; i <= n; i++) {
            p[i] = p[i - 2] * 1ll * A % (i - 1);
            p[i] = (p[i] + 0ll + p[i - 1] * 1ll * B) % (i - 1);
            p[i] = (p[i] + 0ll + C) % (i - 1);
            p[i]++;
            g[ p[i] ].push_back(i);
        }
        dfs(1, -1);
        if ((int)Q.size() <= 1) {
            if ((int)Q.size() == 1) {
                answ1 = *Q.begin();
            } else {
                answ1 = 0;
            }
            answ1 = answ1 * (answ1 - 1) / 2;
            int s = 0;
            for (int i = 1; i <= n; i++) {
                s += col[i];
            }
            if (s) {
                answ2 = (s - 1) * 1ll * (s - 1) + (n - s) * 1ll * (n - 1);
            } else {
                answ2 = (n - 1) * 1ll * (n - 1);
            }
        } else {
            it = Q.end();
            --it;
            mx1 = *it;
            --it;
            mx2 = *it;
            answ2 = 0;
            cnt1 = cnt2 = 0;
            if (mx1 == mx2) {
                for (int i = 1; i <= n; i++) {
                    if (sum[i] == mx1) ++cnt1;
                }
                solve1(1, -1);
            } else {
                for (int i = 1; i <= n; i++) {
                    if (sum[i] == mx1) ++cnt1;
                    if (sum[i] == mx2) ++cnt2;
                }
                solve2(1, -1);
            }
            Q.erase(Q.find(mx1));
            Q.erase(Q.find(mx2));
            Q.insert(mx1 + mx2);
            answ1 = 0;
            for (it = Q.begin(); it != Q.end(); ++it) {
                answ1 += (*it) * 1ll * (*it - 1) / 2;
            }
        }
        printf("Case #%d: %lld %lld\n", test, answ1, answ2);
        clean();
    }
    return 0;
}