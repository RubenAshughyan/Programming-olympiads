#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<iterator>
#include<iterator>
#include<cassert>
#include<cmath>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll unsigned long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
#define i first
#define j second

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
#define db(x) if(DEBUG) {cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

template<class K, class V>
ostream &operator<<(ostream &out, pair<K, V> &elem) {
    out << "{" << elem.first << "," << elem.second << "}";
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int DEBUG = 0;

// oper, k
vc<pair<char, ll>> ans;

ll x, y;
vc<ll> v;

void pluss(ll add){
    if(add == 0) return;

    x += add;
    ans.push_back({'+', add/9});

}

void removeOne(){
    string X = to_string(x);
//    assert(X[0] == '1');

    if(X == "1"){
        x = 0;
    } else {
        x = stoull(X.substr(1));
    }
    ans.push_back({'-', 1});
}

int main() {

    v.push_back(1);

    while (v.size() != 17) {
        v.push_back(10 * v.back() + 1);
    }
    reverse(all(v));
dbCont(v);
    cin >> x >> y;

    ll X = 11111111111111;
    // 14

    ll need = ((X-x)/9)*9;
    pluss(need);
    while(1){
        string curX = to_string(x);
        if(curX[0] != '1') break;

        removeOne();
    }


    ll YYY = y;
    y %= 9;
    ll verjum = (YYY-y);
    ll start = x;

    // make x -> 0

    if(DEBUG) {
        for(ll e : v){
            cout << e << ' ' << e%9 << endl;
        }
    }

    for(ll s1: v){
        if(s1%9 == x%9){
            // make x -> s1
            assert(s1 > x);////////////////////////
            pluss(s1-x);
            break;
        }
    }

    // jnjel 1
    int len = to_string(x).length();
    loop(i,len){
        removeOne();
    }
//    assert(x == 0);
    // x = 0

    int added = 0;
    while(y % 9 != 0){
        string Y = to_string(y);
        Y = "1" + Y;
        y = stoull(Y);
        added++;
    }

    pluss(y);

    // x = 111116

    // remove 1s
    while(x > 9){
        removeOne();
    }

    pluss(YYY - (YYY)%9);

    cout << "Stable" << endl;
    cout << ans.size() << endl;
    for(auto p: ans){
        cout << p.first << ' ' << p.second << endl;
//        assert(p.second != 0);
    }

//    // simulate
//    for (auto p : ans) {
//        assert(start <= (ll) 1e18);
//        if (p.first == '+') {
//            start += p.second * 9;
//        } else {
//            loop(i, p.second) {
//                string S = to_string(start);
//                if (S == "1") {
//                    start = 0;
//                } else {
//                    S = S.substr(1);
//                    start = stoull(S);
//                }
//            }
//        }
//        db(start);
//        assert(start <= (ll) 1e18);
//    }
//
//    assert(start == YYY);
//    main();

    return 0;
}

/*

1
0 0 5

2
3 3 3
6 6 2


*/