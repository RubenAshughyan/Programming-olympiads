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


using namespace std;

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}


const int N = 1000 * 1000 + 5;

int DEBUG = 0;

using namespace std;


char buf[N];

ll PR = 31;
ll MOD = 1000*1000*1000+7;

ll PRPOW[N];

ll bin_exp(ll base, ll exp){
    if(exp == 0) return 1;

    ll h = bin_exp(base, exp/2);

    h = (h*1ll*h)%MOD;
    if(exp & 1){
        h = (h*base)%MOD;
    }
    return h;
}

ll inv(ll x){
    return bin_exp(x, MOD-2);
}


vc<ll> getH(string s){
    int n = s.length();
    vc<ll> h(n,0);
    ll pp = 1;
    loop(i,n){
        h[i] = i-1 >= 0 ? h[i-1] : 0;

        (h[i] += pp*(s[i]-'a'+1)) %= MOD;
        (pp *= PR) %= MOD;
    }
    return h;
}

string palPref(string s){
    string ans = "";
    int n = s.length();
//
//    string cur = "";
//    for(char c : s){
//        cur.PB(c);
//        string revC = cur;
//        reverse(all(revC));
//        if(cur == revC) {
//            ans = cur;
//        }
//    }

    vc<ll> h1 = getH(s);

    string srev = s;
    reverse(all(srev));

    vc<ll> h2 = getH(srev);
    reverse(all(h2));

    dbCont(h1);
    dbCont(h2);

    int best = 0;
    for(int i = 1; i < n; i++){
        int len = i+1;



        int r ;
        if(len & 1){//odd
            r = len/2+1;
        } else {
            r = len/2;
        }

        int l = r-1;
        if(len&1) l--;

        ll hash1 = h1[l];


        ll hash2 = (h2[r] -  (i+1 < n ? h2[i+1] : 0) + MOD) % MOD;
        db(r);
        db(h2[r]);
        db(h2[i+1]);
        (hash2 *= PRPOW[n-i-1]) %= MOD;

        db(i);
        db(hash1);
        db(hash2);
        db(i);
        if(hash1 == hash2) {
            best = i;
        }
    }

    for(int i = 0; i <= best; i++){
        ans.PB(s[i]);
    }

    return ans;
}

string s;



void test(){
    scanf("%s",buf);
    s = buf;
    int n = s.length();

    int l = 0;
    int r = n-1;

    string X="";
    while(l+1 < r-1 && s[l] == s[r]) {
        X.PB(s[l]);
        l++;
        r--;
    }

    int len = r-l+1;
    if(len <= 1){
        cout << s << endl;
        return;
    }


    // mej@ ka
    string mej = "";
    for(int i = l; i <= r; i++) mej.PB(s[i]);


    string s1 = palPref(mej);

    reverse(all(mej));

    string s2 = palPref(mej);

    if(s2.length() > s1.length()) s1 = s2;


    db("");
    db(s1);
    string ans = X + s1;
    reverse(all(X));
    ans += X;
    cout << ans << endl;
}

int main() {

    // precalc
    ll PRINV = inv(PR);
    PRPOW[0] = 1;
    for(int i = 1; i < N; i++){
        (PRPOW[i] = PRPOW[i-1]*PRINV) %= MOD;
    }
    //////////////



//    string ans = palPref("cdfdcec");
//    db(ans);
//    exit(0);

    int t;
    cin >> t;
    loop(i,t) test();



    return 0;
}


/*





 */



