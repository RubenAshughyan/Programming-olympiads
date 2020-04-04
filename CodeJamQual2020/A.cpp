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


void test(int TEST_NUM){
    int n;
    cin >> n;
    vc<vc<int>> v(n, vc<int> (n));
    loop(i,n){
        loop(j,n){
            cin>>v[i][j];
        }
    }

    int trace = 0;
    loop(i,n) trace += v[i][i];


    int rowBad = 0;
    loop(i,n){
        set<int> st;
        loop(j,n) st.insert(v[i][j]);
        rowBad += st.size() < n;
    }

    int colBad = 0;
    loop(j,n){
        set<int> st;
        loop(i,n) st.insert(v[i][j]);
        colBad += st.size() < n;
    }

    printf("Case #%d: %d %d %d\n",TEST_NUM, trace, rowBad, colBad);
}




int main() {
    int t;
    cin >> t;
    loop(i,t) test(i+1);



    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

 5
1 1 1 1 1
1 1 1 1 1



 */



