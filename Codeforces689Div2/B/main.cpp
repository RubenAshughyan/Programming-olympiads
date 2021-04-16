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

int DEBUG = 1;

using namespace std;

int n,m;

bool ins(int i, int j) {
    return
            0 <= i && i < n &&
            0 <= j && j < m;
}


void test() {
    cin >> n >> m;
    vc<string> v(n);
    loop(i,n) cin >> v[i];

    vc<vc<int>> ps;
    loop(i,n){
        vc<int> p(m);
        for(int j =0 ; j < m; j++){
            p[j] = (j-1>=0 ? p[j-1]:0) + (v[i][j] == '*');
        }
        ps.PB(p);
    }

    int ans = 0;
    loop(I,n){
        loop(J,m){
            if(v[I][J] == '*'){
                ans++;

                int d = 1;
                int i = I+1;
                while(i < n){
                    // check next row
                    bool ok = true;
                    if(!ins(i, J-d) || !ins(i, J+d)){
                        ok = false;
                    }

                    if(!ok) break;


                    int sum = ps[i][J+d] - ((J-d-1 >= 0) ? ps[i][J-d-1] : 0);
//                    dbCont(ps[i]);
//                    db(sum);
                    if(sum != (J+d - (J-d)+1)) ok = false;
//                    for(int k = J-d; k <= J+d; k++) {
//                        if(v[i][k] != '*') ok = false;
//                    }

                    if(ok){
                        ans++;
                        i++;
                        d++;
                    }
                    else break;
                }
            }

        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t) test();

    return 0;
}


/*




 */



