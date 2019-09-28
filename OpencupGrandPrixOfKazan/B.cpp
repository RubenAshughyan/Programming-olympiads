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

const int MOD = 998244353;
const int N = 300 * 1000 + 5;
const int M = N * 64 + 555;

int GI = 0;

struct node {
    int next[2];

    node() {
        next[0] = next[1] = -1;
    }
};

int sz[M];
node t[M];
vc<ll> stubid_bor;

void insert(ll val) {
    //stubid_bor.push_back(val);
    //return;

    int v = 0;
    loop(i, 64) {
        sz[v]++;
        int bit = ((val >> (63 - i)) & 1);
        if (t[v].next[bit] == -1) {
            t[v].next[bit] = GI++;
        }
        v = t[v].next[bit];
    }
    sz[v]++;
}

int getSize(int v) {
    if (v == -1) return 0;
    return sz[v];
}

// count how many numbers^b >= x
int query(ll b, ll x) {
    ///////////////////////////////
//    int ans = 0;
//    for (ll e : stubid_bor) {
//        if ((e ^ b) >= x)
//            ans++;
//    }
//    return ans;
    ///////////////////////////////

    int v = 0;
    int answer = 0;
    loop(i, 64) {
        int bitX = ((x >> (63 - i)) & 1);
        int bitB = ((b >> (63 - i)) & 1);

        if (bitX == 0) {
            answer += getSize(t[v].next[bitB ^ 1]);
            v = t[v].next[bitB];
        } else {
            v = t[v].next[bitB ^ 1];
        }

        if (v == -1)
            break;
    }
    answer += getSize(v);

    return answer;
}

void make_bor(vc<ll> list) {
    //stubid_bor.clear();
    // clear previous
    int i = 0;
    while (sz[i]) {
        sz[i] = 0;
        t[i] = node();
        i++;
    }

    GI = 1;

    // fill new numbers
    for (ll e: list) {
        insert(e);
    }
}

int n;
ll a[N], x;
vector<ll> lower, middle, upper;

int brute() {
    int ans = 0;
    loop(msk, (1 << n)) {
        vc<ll> subset;
        loop(i, n) {
            if ((msk >> i) & 1)
                subset.push_back(a[i]);
        }
        if(subset.empty()) continue;

        bool ok = true;
        for (ll &e : subset) {
            for (ll &r: subset) {
                if (&e != &r) {
                    ok &= ((e ^ r) >= x);
                }
            }
        }
        ans += ok;
    }

    return ans;
}

int main() {
    cin >> n >> x;
    loop(i, n) {
        cin >> a[i];
    }

//    db(brute());

    if (x == 0) {
        ll ans = 1;
        for(int i = 0; i < n; i++)
            (ans *= 2) %= MOD;
        (ans += (MOD - 1)) %= MOD;
        cout << ans << endl;
        return 0;
    }


    ll low = 1;
    while (low <= x) {
        low <<= 1;
    }
    ll upp = low;
    low >>= 1;
    ll mask = ~(upp - 1);



    // Divide into < low // >= upp // others

    loop(i, n) {
        ll elem = a[i];
        if (elem < low) lower.PB(elem);
        else if (elem >= upp) upper.PB(elem);
        else middle.PB(elem);
    }

//    dbCont(lower);
//    dbCont(middle);
//    dbCont(upper);

    sort(all(upper));

    make_bor(lower);

    ll pair_count = 0;
    for (ll &elem : middle)
        pair_count += query(elem, x);
    //db(pair_count);
    ll non_greater_cnt = pair_count + lower.size() + middle.size() + 1;

    ll greater_answer = 1;
    int i = 0;
    while (i < upper.size()) {
        int j = i;
        ll high = (upper[i] & mask);
        make_bor(vector<ll>());
        ll tmp_ans = 0;

        while (j < upper.size() && (upper[j] & mask) == high) {
            if (upper[j] & low)
                tmp_ans += query((upper[j] & (upp - 1)), x);
            else
                insert((upper[j] & (upp - 1)));
            j++;
        }
        tmp_ans += j - i;
        //db(tmp_ans);
        greater_answer = (greater_answer * (1 + tmp_ans)) % MOD;
        i = j;
    }

    cout << (non_greater_cnt * greater_answer - 1) % MOD << endl;


    return 0;
}
/*
3 0
0 1 2

 3 2
0 1 2

 3 3
0 1 2

 7 4
11 5 5 8 3 1 3


 8 5
 13 12 8 20 21 2 4 1

 13 523452
 1234 4123435 412341 51341 413245 523454 1324132 54515 4 412345 5123451 51451 1234123



 3 0
 0 0 0
*/