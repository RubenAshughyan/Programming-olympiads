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


const int N = 1000 * 1000 + 7;
const int M = 10 + 3;
const int MOD = 1000 * 1000 * 1000 + 7;


int n,m;
int a[2*N];
string s;
ll ans = -1;
int w[N];
vector<ll> ca;
vector<ll> cw;

void func() {
    int ln = cw.size();
    for(int i = 0; i < ln; i++) {
        cw.PB(cw[i]);
    }
    for(int i = 1; i < cw.size(); i++) {
        cw[i] += cw[i - 1];
    }
    set<pll> st;
    for(int i = 0; i <ln; i++) {
        st.insert({cw[i], i});
    }
    vector<ll> minn;
    for(int i = ln; i < cw.size(); i++) {
        vc<int> asd;
        for(auto p: st)
            asd.PB(p.first);
        auto it = st.begin();
        if (i == ln){
            minn.PB(it->first);
        }
        else
            minn.PB(it->first - 2 * cw[i-ln-1]);
        st.erase(it);
        st.insert({cw[i], i});
    }

    for(int i = 0; i < ca.size(); i++) {
        if (minn[i % ln] > 0) {
            continue;
        }
        if (cw[ln] >= 0 && ca[i] + minn[i % ln] > 0) {
            continue;
        }
        if (cw[ln] >= 0) {
            ans = 0;
            return;
        }
        ans = min(ans, abs((ca[i] + minn[i % ln]) / cw[ln]));
    }
}


void func2() {
    int ln = cw.size();
    for(int i = 0; i < ln; i++) {
        cw.PB(cw[i]);
    }
    for(int i = 1; i < cw.size(); i++) {
        cw[i] += cw[i - 1];
    }
    for(int i = 0; i < ca.size(); i++) {
        a[ca[i]] -= (ans / ln) * cw[ln];
        a[ca[i]] -= cw[(ans%ln+i)] - cw[i%ln];
    }
}


int main() {
    scanf("%d",&n);
    loop(i,n) scanf("%d",a+i);
    scanf("%d",&m);
    cin >> s;
    loop(i,m) w[i] = (s[i] == 'W' ? 1 : -1);


    in gc = __gcd(n, m);
    for(int i = 0; i < gc; i++) {
        ca.clear();
        cw.clear();
        ca.PB(a[i]);
        cw.PB(w[i]);
        for(int j = (i + n) % m; j != i; j = (j + n) % m) {
            cw.PB(w[j]);
        }
        for (int j = (i+m)%n; j != i; j=(m+j)%n) {
            ca.PB(a[j]);
        }
        func();
    }
    if (ans == -1) {
        cout << -1 << endl;
        return 0;
    }
    db(ans);
    for(int i = 0; i < gc; i++) {
        ca.clear();
        cw.clear();
        ca.PB(a[i]);
        cw.PB(w[i]);
        for(int j = (i + n) % m; j != i; j = (j + n) % m) {
            cw.PB(w[j]);
        }
        for (int j = (i+m)%n; j != i; j=(m+j)%n) {
            ca.PB(j);
        }

        func2();
    }
    ll ret = ans * n;
    for (int k = 0; k < 2 * n; ++k) {
        a[k%n] += w[k%n];
        ret++;
        if (a[k%n] == 0)
        {
            cout << ret;
            return 0;
        }
    }

    return 0;
}
/*
4
2 3 2 1
3
WPP
*/