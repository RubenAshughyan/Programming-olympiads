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
const int MOD = 1000 * 1000 * 1000 + 7;

int n;


vector<pll > v;
vector<pair<ll, int>> lines;

ll pr = 31;

ll keyy(pair<pll, pll > p) {
    ll ans = 0;
    ans += p.first.first * pr;
    ans %= MOD;
    ans += p.first.second * pr * pr;
    ans %= MOD;
    ans += p.second.first * pr * pr * pr;
    ans %= MOD;
    ans += p.second.second * pr * pr * pr * pr;
    ans %= MOD;
    return ans;
}

void add_line(pll a, pll b, int ac, int bc) {
    ll p1 = b.y - a.y;
    ll q1 = b.x - a.x;
    if (q1 != 0) {
        ll g1 = __gcd(abs(p1), abs(q1));
        p1 /= g1;
        q1 /= g1;
        if (q1 < 0) {
            q1 *= -1;
            p1 *= -1;
        }
    } else
        p1 = 0;
    ll p2 = -a.x;
    p2 *= (b.y - a.y);
    p2 += a.y;
    ll q2 = b.x - a.x;
    if (q2 != 0) {
        ll g2 = __gcd(abs(p2), abs(q2));
        p2 /= g2;
        q2 /= g2;
        if (q2 < 0) {
            q2 *= -1;
            p2 *= -1;
        }
    } else
        p2 = 0;
    lines.push_back(MP(keyy(MP(MP(p1, q1), MP(p2, q2))), ac*bc));
    lines.push_back(MP(keyy(MP(MP(p1, q1), MP(p2, q2))), ac*bc));
}

ll p2[1105];

ll f(int a) {
    return (p2[a] + MOD - a - 1) % MOD;
}

void test() {
    lines.clear();
    cin >> n;
    v = vector<pll >(n);
    map<pll, int> mp;
    loop(i, n)
        cin >> v[i].x >> v[i].y;
    for (int k = 0; k < n; ++k) {
        mp[v[k]]++;
    }
    for (auto p1: mp) {
        for( auto p2: mp) {
            add_line(p1.first, p2.first, p1.second, p2.second);
        }
    }
    ll ans = 0;
    for (auto p: mp){
        if (p.second > 2)
            (ans += MOD + p2[p.second] - 1 - (p.second * (p.second + 1) / 2) % MOD) %= MOD;
    }
    sort(all(lines));
    int cnt = lines[0].second;
    for (int i=1;i<=lines.size();i++) {
        if (i!=lines.size() && lines[i].first == lines[i-1].first){
            cnt += lines[i].second;
        } else{
            (ans += f(cnt)) %= MOD;
        }
//        db(p.first.first.first);
//        db(p.first.first.second);
//        db(p.first.second.first);
//        db(p.first.second.second);
//        dbCont(p.second);
    }
    cout << ans << endl;
}

int main() {
    loop(i, 1005) {
        p2[i] = i ? (p2[i - 1] * 2) % MOD : 1;
    }
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }

    return 0;
}

/*
3
3
1 1
1 1
1 1
3
0 0
0 1
1 0
1
0 0


 */