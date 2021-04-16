//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
//#define v first
//#define y second
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

int DEBUG = 0;

using namespace std;

const int N = 100 + 30;
const ll MOD = 1000 * 1000 * 1000 + 7;


void test() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int i = 0;
    string ans;
    while (i < s.length()) {
        // single char
        if (isalpha(s[i])) {
            ans.PB(s[i]);
            i++;
        } else {
            // scan number
            string numString = "";
            while (i < s.length() && '0' <= s[i] && s[i] <= '9') {
                numString.PB(s[i]);
                i++;
            }

            if (numString.length() >= 8) {
                cout << "unfeasible" << endl;
                return;
            }

            char c = s[i++];

            int cnt = stoi(numString);
            loop(xxx,cnt) ans.PB(c);
        }
    }

    if(ans.length() > k){
        cout << "unfeasible" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    int t;
    cin >> t;
    loop(i, t) {
        test();
    }
    return 0;
}


/*


 4
2250 2250
126 126
1 6
6 8


 */



