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

int DEBUG = 1;
const int N = 1000 * 1000 + 5;
const int INF = 1e9;


using namespace std;


void test(int testIndex) {
    string s;
    cin >> s;
    int n = s.length();

    vc<vc<int>> d(26, vc<int>(26, INF));
    loop(i, 26) d[i][i] = 0;

    int m;
    cin >> m;
    loop(cc, m) {
        string t;
        cin >> t;
        int from = t[0] - 'A';
        int to = t[1] - 'A';
        d[from][to] = 1;
    }
    loop(k, 26) {
        loop(i, 26) {
            loop(j, 26) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }



    int ans = -1;
    for (int l = 0; l < 26 ; l++) {
        int curAns = 0;
        bool can = true;
        for (char ch : s) {
            int c = ch-'A';
            if(d[c][l] == INF) {
                can = false;
                break;
            }

            curAns += d[c][l];
        }

        if(can && (ans == -1 || ans > curAns)) {
            ans = curAns;
        }


    }


    printf("Case #%d: ", testIndex);

    cout << ans << endl;
}

int main() {

    int t;
    cin >> t;
    loop(i, t) test(i + 1);
    return 0;
}


/*




 */



