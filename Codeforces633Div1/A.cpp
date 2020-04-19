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

using namespace std;

const int N = 100 * 1000 + 5;

void test(){
    int n,m;
    cin >> n >> m;

    vc<string> col(n);
    loop(i,n) cin >> col[i];

    vc<string> x(n);
    loop(i,n) cin >> x[i];

    // mx
    int black = 0;
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j+1 < m; j++){
            if(x[i][j] == 'R' && x[i][j+1] == 'L'){

                int J = j;
                int br = 0;
                while(true){
                    if(col[i][J] == '0'){
                        br = 1;
                        break;
                    }

                    J--;
                    if(J < 0) break;
                    if(x[i][J] != 'R') break;
                }

                J = j+1;
                int bl = 0;
                while(true){
                    if(col[i][J] == '0'){
                        bl = 1;
                        break;
                    }

                    J++;
                    if(J >= m) break;
                    if(x[i][J] != 'L') break;
                }

                db(i);
                db(j);
                db(br);
                db(bl);
                mx+=2;
                black+= br + bl;
            }
        }
    }
    for(int i = 0; i+1 < n; i++){
        for(int j = 0; j < m; j++){
            if(x[i][j] == 'D' && x[i+1][j] == 'U'){

                int I = i;
                int bd = 0;
                while(true){
                    if(col[I][j] == '0'){
                        bd = 1;
                        break;
                    }

                    I--;
                    if(I < 0 ) break;
                    if(x[I][j] != 'D') break;
                }

                I = i+1;
                int bu = 0;
                while(true){
                    if(col[I][j] == '0'){
                        bu = 1;
                        break;
                    }

                    I++;
                    if(I >= n) break;
                    if(x[I][j] != 'U') break;
                }

                db(i);
                db(j);
                db(bd);
                db(bu);
                mx+=2;
                black += bd+bu;
            }
        }
    }

    cout << mx << ' ' << black<< endl;
}

int main() {

    int t;
    cin >> t;
    loop(tt,t){
       test();
    }



    return 0;
}


/*

3

3 3
001
101
110
RLL
DLD
ULL



 */



