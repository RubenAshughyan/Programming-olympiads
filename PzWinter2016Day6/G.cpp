#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"


#include<bits/stdc++.h>
#include<unordered_map>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 0;

using namespace std;

const ll N = 1000*1005;
const ll maxn = 1e12 + 5;

multiset<ll> st;
ll values[N];
unordered_map<ll, ll> sg;

void update(ll v, ll l, ll r, ll pos, ll val) {
    db(v);

    if (l == r - 1) {
        sg[v] += val;
        return;
    }
    ll m = (l + r) / 2;
    if (pos < m)    update(2 * v, l, m, pos, val);
    else            update(2 * v + 1, m, r, pos, val);
    sg[v] = sg[2 * v] + sg[2 * v + 1];
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (l >= qr || ql >= r)
        return 0;
    if (l >= ql && r <= qr) {
        return sg[v];
    }
    ll m = (l + r) / 2;
    return get(2 * v, l, m, ql, qr) + get(2 * v + 1, m, r, ql, qr);
}

int main(){
    ll n, m;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> values[i];
        update(1, 0, maxn, values[i], values[i]);
        st.insert(values[i]);
    }
    cin >> m;
    if (n == 1) {
        cout << 1 << endl;
        while(m--) {
            ll k, nval;
            cin >> k >> nval;
            cout << 1 << endl;
        }
        exit(0);
    }



    //////////////////////////////////////////////
    multiset<ll>::iterator x = st.begin();
    ll ans = 1;
    if (*(++x) == *st.begin()) {
        ans++;
    }
    x = st.lower_bound(*st.begin() + 1);

    dbCont(st);
    //exit(0);
    if (x != st.end())
        while(true) {
            db(*x);

            ll curSum = get(1, 0, maxn, 0, *x);
            db(curSum);
            if (curSum > *st.rbegin()){
                break;
            }
            if (*x >= curSum)
                ans++;
            x = st.lower_bound(curSum + *x);
            if (x == st.end())
                break;
        }
    cout << ans << endl;
    //////////////////////////////////////////////



    while(m--) {
        ll k, nval;
        cin >> k >> nval;
        k--;
        db(k);
        db(nval);

        update(1, 0, maxn, values[k], -values[k]);
        st.erase(st.find(values[k]));
        values[k] = nval;


        update(1, 0, maxn, values[k], values[k]);
        st.insert(values[k]);
        x = st.begin();
        ans = 1;
        if (*(++x) == *st.begin()) {
            ans++;
        }
        x = st.lower_bound(*st.begin() + 1);

        dbCont(st);
        //exit(0);
        if (x != st.end())
            while(true) {
                db(*x);

                ll curSum = get(1, 0, maxn, 0, *x);
                db(curSum);
                if (curSum > *st.rbegin()){
                    break;
                }
                if (*x >= curSum)
                    ans++;
                x = st.lower_bound(curSum + *x);
                if (x == st.end())
                    break;
            }
        cout << ans << endl;
    }
    return 0;
}

/*





3
2 1 3
3
1 3
2 7
3 5


 7
2 14 14 15 5 2 5
5
5 2
4 12
5 4
3 10
7 9

1
1
 2
 1 2
 1 1000000000000000



*/