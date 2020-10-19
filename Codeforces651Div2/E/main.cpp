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

int DEBUG = 0;

using namespace std;

int n;
string s,t;
int main() {
    cin >> n;

    cin >> s >> t;

    vc<int> cs(2,0);
    vc<int> ct(2,0);

    for(char c  :s) cs[c-'0']++;
    for(char c  :t) ct[c-'0']++;

    if(cs != ct) {
        cout << -1 << endl;
        return 0;
    }



    string ns = "";
    loop(i,n){
        if(s[i] != t[i]){
            ns.PB(s[i]);
        }
    }

    s = ns;
    n = s.length();


    vc<int>zero,one;
    loop(i,n){
        if(s[i] == '0') zero.PB(i);
        if(s[i] == '1') one.PB(i);
    }

    int ans = 0;
    loop(i,zero.size()){
        ans = max(ans, abs(zero[i]-one[i]));
    }

    cout << ans << endl;

    return 0;
}


/*




 */



