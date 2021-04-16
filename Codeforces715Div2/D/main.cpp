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

int n;

vc<string> s(3);
void test() {
    cin >> n;
    loop(i,3) cin >> s[i];

    vc<vc<int>> cnt(3, vc<int>(2,0));
    loop(i,3){
        loop(j,2*n){
            cnt[i][s[i][j]-'0']++;
        }
    }

    int i,j;
    loop(I,3){
        loop(J,3){
            if(I!=J){
                if( (cnt[I][0] <= cnt[I][1]) ==(cnt[J][0] <= cnt[J][1])){
                    i = I;
                    j = J;
                }
            }
        }
    }




    int few;
    if(cnt[i][0] <= cnt[i][1]) few = 0;
    else few = 1;

    int many = few^1;

    // is has more of Many
    if(cnt[i][many] < cnt[j][many]) swap(i,j);


    db(i);
    db(j);
    db(few);

    vc<int> manyPosJ;
    manyPosJ.PB(-1);
    loop(k,2*n) {
        if(s[j][k]-'0' == many){
            manyPosJ.PB(k);
        }
    }
    manyPosJ.PB(2*n);

    vc<int> fewCnts;
    for(int k = 0; k+1 < manyPosJ.size(); k++){
        fewCnts.PB(manyPosJ[k+1] - manyPosJ[k]-1);
    }

    string res = "";
    int fewI = 0;
    if(fewCnts.size()) {
        loop(xxx, fewCnts[0]) res.PB('0' + few);
        fewI++;
    }

    loop(k, 2*n){
        res.PB(s[i][k]);

        if(s[i][k] == '0'+many){
            if(fewI < fewCnts.size()){
                loop(xxx, fewCnts[fewI]) res.PB('0'+few);
                fewI++;
            }
        }
    }

    cout << res << endl;
}

int main() {

    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*




 */



