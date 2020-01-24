#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <cassert>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ch first
#define range second
//
//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define sz(xxx) ((int)(xxx.size()))
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}



const ll INF = INT_MAX;

const int N = 200*1000+5;

int n;
int a[N], b[N], l[N], r[N];

void precalc() {
    a[0] = INF;
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; i++) {
        while (a[st.top()] < a[i]) st.pop();
        l[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    a[n + 1] = INF;
    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
        {
            while (a[st.top()] < a[i]) st.pop();
            r[i] = st.top();
            st.push(i);
        }
    }
}

void solve() {

    precalc();
    for (int i = 1; i <= n; i++)
        cout << l[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
    for (int i = 1; i <= n; i++) {
        int u = l[i] + 1;
        int v = r[i] - 1;
        int range = v - u + 1;
        if (range == a[i]) b[a[i]] = 1;
        else b[a[i]] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        cin >> n;
        loop(i, n)cin >> a[i + 1];
        solve();
        loop(i, n) {
            printf("%d", b[i + 1]);
        }
        printf("\n");
    }

    return 0;
}