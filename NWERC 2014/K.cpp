
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

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

int n, s, t;
map<int, int> p_b;

pii next(int ind, map<int, int>& b){
    int nextind = (ind + t) % s;
    auto mit = b.lower_bound(nextind);
    if (mit == b.end())
        return MP(b.begin()->first, s - nextind + b.begin()->first);
    return MP(mit->first, mit->first - nextind);
}

ll solve(int ind, map<int, int> b){
    ll time = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (b[ind] == 1)
            b.erase(ind);
        else
            b[ind]--;
        pii next_ = next(ind, b);
        time += next_.second;
        ind = next_.first;
    }
    return time + (ll)t * n;
}

ll gcd(ll a, ll b){
    if (b==0)
        return a;
    if (a < b)
        return gcd(b, a);
    return gcd(b, a % b);
}
void print_frac(ll m){
    ll g = gcd(s, m);
    cout << m / g << "/" << s / g << endl;
}
int main() {
    cin >> n >> s >> t;
    int maxind = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p_b[x]++;
        maxind = max(maxind, x);
    }
    int lastind = maxind - s;
    ll sm = 0, mi=-1, ma=-1;
    for (auto j: p_b) {
        ll cur = solve(j.first, p_b);
        ll dind = j.first - lastind;
        sm += cur * dind + dind * (dind - 1) / 2;
        lastind = j.first;
        mi = (mi == -1)?cur: min(mi, cur);
        ma = (ma == -1)?cur+dind-1: max(ma, cur + dind - 1);
    }
    cout << mi << endl;
    cout << ma << endl;
    print_frac(sm);
    return 0;
}
/*

2 2 10
0 0

2 2 10
1 1

1 1 5
0

7 10 10000000
0 0 0 0 0 0 0

7 10 10000000
0 0 0 0 0 0 1

 10 10 3
0 0 2 2 4 4 6 6 8 8

 9 10000000 1
0 7 2 3 4 5 6 1 8

 */