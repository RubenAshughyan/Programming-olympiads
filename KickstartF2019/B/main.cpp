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

const int N = 300 + 50;


ll n, s;
map<vc<int>, int> mp;

void test(int t) {
    mp.clear();

    cin >> n >> s;

    vc<vc<int>> sax;
    loop(i, n) {
        int k;
        cin >> k;
        vc<int> v;
        loop(j, k) {
            int e;
            cin >> e;
            v.push_back(e);
        }

        sort(all(v));
        mp[v]++;
        sax.push_back(v);
    }

    ll ans = n*(n-1);
    for(auto v: sax){
        int sz=v.size();
        loop(msk, (1<<sz)){
            vc<int> subset;
            loop(j,sz){
                if((msk >> j) & 1){
                    subset.push_back(v[j]);
                }
            }
            ans -= mp[subset];
        }
        ans++;
    }

    printf("Case #%d: %lld\n", t, ans);
}

int main() {
//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt, t) {
        test(tt + 1);
    }

    return 0;
}