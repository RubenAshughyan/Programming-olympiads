#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

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

template<class K, class V> ostream& operator << (ostream& out, pair<K, V>& elem) { out << "{" << elem.first << "," << elem.second << "}"; return out; }


const int N = 300 * 1000 + 5;

int DEBUG = 0;

using namespace std;



string narmaliz(string s){
    string rs = s;reverse(all(rs));
    return min(s,rs);
}

void test() {
    int n;
    scanf("%d",&n);


    vc<string> v;
    vc<string> orig_v;

    loop(i,n){
        string s;
        cin >> s;

        orig_v.push_back(s);

        v.push_back(narmaliz(s));
    }

    dbCont(orig_v);
    dbCont(v);

    map<string, int> mp;
    for(string s : v) mp[s]++;

    for(auto p : mp) if(p.second >= 3) {
        cout << -1 << endl;
        return;
    }


    ////////////
    vc<int> rev(n,0);


    map<string, int> orig_mp;
    for(string s : orig_v) orig_mp[s]++;

    vc<int> ans;
    loop(i,n){
        string s = orig_v[i];
        if(orig_mp[s] == 2){
            orig_mp[s] = -1;

            rev[i] = 1;
            reverse(all(orig_v[i]));
        }
    }


    dbCont(rev);
    // reversed some
    vc<int> free[2];

    for(int i = 0; i < n; i++){
        string s = orig_v[i];
        if(s.front() != s.back()){
            if(mp[narmaliz(s)] != 2){
                free[s.front()-'0'].push_back(i);
            }
        }
    }



    while(abs(sz(free[0]) - sz(free[1])) > 1){
        int x;
        if(sz(free[0]) > sz(free[1])){
            x = free[0].back();
            free[0].pop_back();
            free[1].push_back(x);
        } else {
            x = free[1].back();
            free[1].pop_back();
            free[0].push_back(x);
        }

        rev[x] = 1;
        reverse(all(orig_v[x]));
    }

    int cnt = 0;
    for(string s: orig_v){
        if(s.back() != s.front()) cnt++;
    }

    if(cnt == 0){
        cout << -1 << endl;
        return;
    }

    loop(i,n) if(rev[i]) ans.push_back(i);

    cout << ans.size() << endl;
    for(int e: ans){
        cout<< e+1 << ' ';
    }
    cout << endl;

}

int main() {


    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}








