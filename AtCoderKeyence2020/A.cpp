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
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define x first
#define y second
//
//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pdd pair<dbl,dbl>
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

using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}

// 4:13

int DEBUG = 0;

using namespace std;

const int N = 100 * 1000 + 5;
const ll MOD = 1000 * 1000 * 1000 + 7;


int n;
vc<pll > v;

bool by_r(pll a, pll b) {
    swap(a.first, a.second);
    swap(b.first, b.second);
    return a < b;
}

int main() {

    cin >> n;
    loop(i, n) {
        ll x, d;
        cin >> x >> d;


        ll l = x - d;
        ll r = x + d;

        v.PB({l, r});
    }

    sort(all(v), by_r);


    int ans = 0;
    ll R = -1e14;
    for (int i = 0; i < n; ++i) {
        if (R <= v[i].first) {
            R = v[i].first;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

/*



 */