#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
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

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define ind first
#define area second
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


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


const int N = 1000 * 1000 + 5;

int DEBUG = 0;
using namespace std;

ll n, k, w;
ll l[N];
ll al, bl, cl, dl;
ll h[N];
ll ah, bh, ch, dh;
ll MOD = 1000 * 1000 * 1000 + 7;

void test(int testIndex) {

    if(DEBUG){
        cout << endl;
        cout << endl;
    }
    cin >> n >> k >> w;
    loop(i, k) cin >> l[i];
    cin >> al >> bl >> cl >> dl;

    loop(i, k) cin >> h[i];
    cin >> ah >> bh >> ch >> dh;


    for (int i = k; i < n; i++) {
        l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
        h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
    }

    if(DEBUG) {
        loop(i, n) cout << l[i] << ' ';
        cout << endl;
        loop(i, n) cout << h[i] << ' ';
        cout << endl;
    }
    // ind, area
    stack<pll > st;
    st.push(MP(0,  2 * (w + h[0])));


    vc<ll> ps = {st.top().area};

    for(int i = 1; i < n; i++){
        db(i);
        ll curP;

        // if ankax
        if(l[i] > l[st.top().ind] + w){
            if(DEBUG)cout << "ankax" << endl;
            curP = st.top().area + 2 * (w + h[i]);
            while(!st.empty()) st.pop();
        }
        // ijnuma
        else if (h[i] <= h[st.top().ind]) {
            if(DEBUG)cout << "ijnuma" << endl;
            curP = st.top().area;
            curP += 2*(h[i]+w);
            curP -= 2* (l[st.top().ind]+w - l[i]);
            curP -= 2* h[i];
        }
        //helnuma
        else {
            if(DEBUG)cout << "helnuma" << endl;

            // sax hatvoxner@ rad baci verjinic
            auto last = st.top();
            while(!st.empty() && l[st.top().ind] + w > l[i] && h[st.top().ind] < h[i]){
                last = st.top();
                st.pop();
            }
            if(st.empty() || l[st.top().ind] + w < l[i]) {
                st.push(last);
            }

            db(st.size());

            curP = st.top().area;
            db(curP);
            curP += 2*(h[i]+w);
            db(curP);
            curP -= 2* (l[st.top().ind]+w - l[i]);
            db(curP);
            curP -= 2* min(h[st.top().ind], h[i]);
            db(curP);
        }

        ps.push_back(curP);
        st.push({i, curP});
    }


    dbCont(ps);

    assert(is_sorted(all(ps)));

    ll ans = 1;
    for(ll e : ps){
        ans *= e;
        ans %= MOD;
    }

    printf("Case #%d: %lld\n", testIndex, ans);
}

int main() {

    int t;
    cin >> t;
    loop(i, t) test(i + 1);
    return 0;
}


/*




 */



