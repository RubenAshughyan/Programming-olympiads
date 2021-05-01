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


const int N = 500 * 1000 + 5;

int DEBUG = 1;

using namespace std;

vc<string> f(string s){
    vc<string> res;
    if(s.length() <= 16) {
        if(s != "0") {
            res.PB(s + '0');
        }
    }


    string nt = s;
    for(char& c: nt){
        if(c == '0') c = '1';
        else c = '0';
    }
    while(!nt.empty() && nt.front() == '0' && nt != "0"){
        nt = nt.substr(1);
    }
    res.PB(nt);
    return res;
}

void test(int testIndex){
    string s,t;
    cin >> s >> t;

    queue<string> q;
    map<string, int> d;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        string from = q.front(); q.pop();

        for(string to: f(from)){
            if(d.count(to) == 0){
                d[to] = d[from]+1;
                q.push(to);
            }
        }
    }

    string ans;
    if(d.count(t)){
        ans = to_string(d[t]);
    } else {
        ans = "IMPOSSIBLE";
    }

    printf("Case #%d: %s\n", testIndex, ans.c_str());
}

int main() {
//    dbCont(f("0"));

    int t;
    cin >> t;
    loop(I,t) test(I+1);
    return 0;
}


/*



 */
