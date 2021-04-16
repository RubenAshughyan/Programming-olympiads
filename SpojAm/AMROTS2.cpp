//#pragma GCC optimize "-O1"
//#pragma GCC optimize "-O2"
//#pragma GCC optimize "-O3"

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

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
#define length first
#define time second
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


const int N = 300 + 5;

int DEBUG = 0;

using namespace std;

char buf[N];
typedef bitset<N> BS;


vc<vc<int>> getTemple(int n,int m){
    vc<vc<int>> a(n, vc<int> (m));

    loop(i,n){
        scanf("%s",buf);
        loop(j,m){
            a[i][j] = buf[j] == '#';
        }
    }
    return a;
}

vc<vc<int>> rotate(vc<vc<int>> a){
    int n = a.size();
    int m = a[0].size();

    vc<vc<int>> b(m, vc<int>(n));

    loop(i,n){
        loop(j,m){
            b[j][n-i-1] = a[i][j];
        }
    }
    return b;
}

int n,m;
vc<vc<int>> field;
vc<BS> fieldBitsets;

int ans = 1e9;


void pr(vc<vc<int>> a){
    loop(i,a.size()){
        loop(j,a[i].size()){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

int solve(vc<vc<int>> &a){
//    cout <<"\n\nsolve" << endl;
//    pr(a);
//    pr(field);

    int n1 = a.size();
    int m1 = a[0].size();
    if(n1 > n || m1 > m) return 1e9;

    vc<BS> aBitsets;
    loop(i,n1){
        BS b;
        loop(j,m1){
            b[j] = a[i][j];
        }
        aBitsets.PB(b);
    }

    int curAns = ans;
    for(int i = 0; i+n1-1 < n; i++){
        for(int j = 0; j+m1-1 < m; j++){
            db(i);
            db(j);
            // upper right corner at field[i][j]
            int curPosAns = 0;
            for(int k = 0; k < n1; k++){
                BS& fieldBitset = fieldBitsets[i+k];
                BS& aBitset = aBitsets[k];


                curPosAns += ((aBitset<<j)&fieldBitset).count();
                if(curPosAns > curAns){
                    curPosAns = 1e9;
                    break;
                }
            }

            db(curAns);
            curAns = min(curAns, curPosAns);
        }
    }

    db(curAns);
    return curAns;
}



int main() {
    scanf("%d%d",&n,&m);
    field = getTemple(n,m);

    loop(i,n){
        BS b;
        loop(j,m){
            b[j] = field[i][j];
        }
        fieldBitsets.PB(b);
    }


    int n1,m1;
    scanf("%d%d",&n1,&m1);

    vc<vc<int>> a = getTemple(n1,m1);

    loop(i,4){
        ans = min(ans, solve(a));
        a = rotate(a);
    }

    // mirror
    loop(i,n1){
        loop(j,m1/2){
            swap(a[i][j], a[i][m1-j-1]);
        }
    }

    loop(i,4){
        ans = min(ans, solve(a));
        a = rotate(a);
    }

    printf("%d\n",ans);

    return 0;
}


/*


 5 5
####.
####.
####.
####.
.....
2 3
##..
##..

5 5
####.
####.
####.
####.
.....
5 5
#....
#....
#....
#....
#####


10 20
#.###.#.###.########
#.###........###.###
.##.#........##.#.##
#.#####..##..###.###
#.###..#.#.#.#.#..##
#.#.#.#...##..######
#####...#.....#.#.##
#.###.#..#....##.###
#.#.###.#.#.####.##.
#####.#.###.###.##..
8 8
###..###
########
###..###
.#....#.
.#....#.
###..###
########
###..###

 */



