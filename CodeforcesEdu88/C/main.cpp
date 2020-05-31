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

int DEBUG = 1;

using namespace std;

ll h,c,t;

dbl f(ll k){

    dbl temp = k*c;
    temp+= (k+1)*h;
    temp /= (2*k+1);

    return abs( t - temp);
}

void test() {

    cin >> h >> c >> t;


    if(t == h){
        cout << 1 << endl;
        return;
    }


    if(t >= h){
        cout << 1 << endl;
        return;
    }

    // even
    if(c+h == 2*t){
        cout << 2 << endl;
        return;
    }


    if(2*t <= c+h){
        cout << 2 << endl;
        return;
    }



    // find >=



    ll k;
    if( (t-h) % (h+c-2*t) == 0){
        k = (t-h) / (h+c-2*t);
    } else {
        k = (t-h) / (h+c-2*t)+1;
    }

//    db(k);

    if(k-1 >= 0 && (2*k-1)*(k*h+ (k+1)*c) - t*(2*k-1) <= t*(2*k+1) - (2*k+1)*( (k-1)*h + k*c )  ){
        k--;
    }

    cout << 2*k+1<<endl;

}

int main() {
    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*


 1324

 200 100 151

 */



