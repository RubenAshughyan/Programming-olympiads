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


using namespace std;

void test(int testIndex) {
   int n;
   cin >> n;

   string I,O;
   cin >> I >> O;

   vc<vc<int>> d(n, vc<int> (n, 0));
   loop(i,n) d[i][i] = 1;
   for(int i = 0; i +1 < n; i++){
       if(O[i] == 'Y' && I[i+1] == 'Y'){
           d[i][i+1] = 1;
       }
       if(I[i] == 'Y' && O[i+1] == 'Y'){
           d[i+1][i] = 1;
       }
   }

   loop(k,n){
       loop(i,n){
           loop(j,n){
                d[i][j] |= d[i][k] & d[k][j];
           }
       }
   }

   printf("Case #%d:\n", testIndex);
    loop(i,n){
        loop(j,n){
            cout << (d[i][j] ? 'Y' : 'N');
        }
        cout << endl;
    }
}

int main() {

    int t;
    cin>> t;
    loop(i,t) test(i+1);
    return 0;
}


/*




 */



