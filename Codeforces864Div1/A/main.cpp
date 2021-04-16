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


int n, m;
vc<vc<int>> x;
vc<vc<pii>> ans;


void f(vc<pii > a) {

    for (auto p: a) {
        int i = p.first;
        int j = p.second;
        x[i][j] ^= 1;

    }

    ans.PB(a);
}

void doit(int i, int j) {

    db(i);
    db(j);
    if(DEBUG){
        cout << "DOIT" << endl;
        loop(i,n){
            loop(j,m){
                cout << x[i][j];
            }
            cout << endl;
        }
    }

    deque<pii > v;
    v.PB({i, j});
    v.PB({i, j + 1});
    v.PB({i + 1, j + 1});
    v.PB({i + 1, j});

    while (x[v[0].first][v[0].second] != 1) {
        v.PB(v[0]);
        v.pop_front();
    }

    f({
              v[0],
              v[1],
              v[2]
      });

    f({
              v[0],
              v[3],
              v[1]
      });

    f({
              v[0],
              v[3],
              v[2]
      });


}

bool ins(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}
void test() {
    ans.clear();

    cin >> n >> m;

    x = vc<vc<int>>(n, vc<int>(m));
    loop(i, n) {
        string s;
        cin >> s;
        loop(j, m) {
            x[i][j] = s[j] == '1';
        }
    }



    // 11
    db("hor");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            if (x[i][j] && x[i][j + 1]) {
                int I = i == n - 1 ? i - 1 : i + 1;
                f({
                          {i, j},
                          {I, j},
                          {I, j + 1}
                  });
                f({
                          {i, j + 1},
                          {I, j},
                          {I, j + 1}
                  });
            }
        }
    }


    // 1
    // 1
    db("ver");
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i][j] && x[i + 1][j]) {
                int J = j == m - 1 ? j - 1 : j + 1;
                f({
                          {i,     j},
                          {i,     J},
                          {i + 1, J}
                  });
                f({
                          {i + 1, j},
                          {i,     J},
                          {i + 1, J}
                  });
            }
        }
    }


    // single 1s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i][j] == 1) {
                // down, right
                if (ins(i + 1, j + 1)) {
                    db("down, right");
                    doit(i, j);
                    continue;
                }

                // down, left
                if (ins(i+1, j - 1)) {
                    db("down, left");

                    doit(i, j - 1);
                    continue;
                }

                // up, right
                if (ins(i - 1, j + 1)) {
                    db("up, right");

                    doit(i - 1, j);
                    continue;
                }

                // up, left
                if (ins(i - 1, j - 1)) {
                    db("up, left");

                    doit(i - 1, j - 1);
                    continue;
                }
            }

        }
    }


    if(DEBUG){
        cout << "XXXXXX" << endl;
        loop(i,n){
            loop(j,m){
                cout << x[i][j];
            }
            cout << endl;
        }
    }

    cout << ans.size() << endl;
    for(auto p: ans){
        for(auto pr: p){
            cout << pr.first+1 << ' '  << pr.second+1 << ' ';
        }
        cout << endl;
    }
}

int main() {


    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}


/*


 1
 2 3
011
101

 1
 3 3
 111
 111
 111

5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101



 */



