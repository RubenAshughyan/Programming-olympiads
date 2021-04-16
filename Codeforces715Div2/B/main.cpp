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

void test() {

    int n;
    string s;
    cin >> n >> s;

    int t = 0,m=0;
    for(char c : s){
        if(c == 'T') t++;
        if(c == 'M') m++;
    }

    if(2*m != t){
        cout << "NO" << endl;
        return;
    }


    int curT = 0;
    int curM = 0;
    loop(i,n){
        if(s[i] == 'T') curT++;
        if(s[i] == 'M') curM++;


        if(s[i] == 'M' && curT < curM){
            cout << "NO" << endl;return;
        }
    }

    curT = curM = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'T') curT++;
        if(s[i] == 'M') curM++;


        if(s[i] == 'M' && curT < curM){
            cout << "NO" << endl;return;
        }
    }

        cout << "YES" << endl;return;


//    set<int> ts,ms;
//    loop(i,n){
//        if(s[i] == 'T') ts.insert(i);
//        else ms.insert(i);
//    }
//
//    while(!ts.empty()){
//
//        int curT = *ts.begin();
//        ts.erase(ts.begin());
//
//        auto curM = ms.upper_bound(curT);
//        if(curM == ms.end()){
//            cout << "NO" << endl;return;
//        }
//        ms.erase(curM);
//
//        auto nextT = ts.upper_bound(*curM);
//        if(nextT == ts.end()){
//            cout << "NO" << endl;return;
//        }
//        ts.erase(nextT);
//
////        db(curT);
////        db(*curM);
////        db(*nextT);
//    }
//
//    cout << "YES" << endl;return;


}

int main() {

    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*




 */



