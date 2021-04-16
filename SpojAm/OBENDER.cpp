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


int DEBUG = 0;

using namespace std;

const int N = 1000 * 1000 + 5;

bool ins(int i, int j) {
    return
            0 <= i && i < 8 &&
            0 <= j && j < 8;
}

int howManyAttack(vc<string> v) {



    int ans = 0;

    int I = -1;
    int J = -1;
    loop(i, 8) loop(j, 8) if (v[i][j] == 'Q') {
                I = i;
                J = j;
            }



    if (I == -1) return -1;

    db(I);
    db(J);

    for (int di = -1; di <= +1; di++) {
        for (int dj = -1; dj <= +1; dj++) {
            if (di == 0 && dj == 0) continue;

            int cI = I + di;
            int cJ = J + dj;
            while (ins(cI, cJ)) {

                if (v[cI][cJ] == 'b' ) ans++;
                if (v[cI][cJ] != '.') break;

                cI += di;
                cJ += dj;
            }

        }
    }
    db(ans);
    return ans;
}


int main() {

    vc<string> v;
    loop(i, 8) {
        string s;
        cin >> s;
        v.PB(s);
    }


    int ans = 0;
    loop(i,8){
        loop(j,8){
            if(v[i][j] == '.'){
                v[i][j] = 'Q';
                if(howManyAttack(v) == 0){
                    ans++;
                }
                v[i][j] = '.';
            }
        }
    }

    cout << ans << endl;

    return 0;
}


/*
...b....
..bb.b..
........
...b....
...w....
........
.ww.....
....w...

 */



