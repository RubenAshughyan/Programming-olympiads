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

int DEBUG = 0;

using namespace std;


void test() {
    int n;
    cin >> n;

    n *= 2;


    vc<int> v(n);

    vc<int> odds;
    vc<int> evens;
    loop(i, n) {
        scanf("%d", &v[i]);
        if (v[i] & 1) odds.PB(i+1);
        else evens.PB(i+1);
    }


    int cnt = 0;
    for(int i = 0; i+1 < odds.size(); i+=2){
        if(cnt == n/2-1) break;
        cout << odds[i] << ' ' << odds[i+1] << endl;
        cnt++;
        if(cnt == n/2-1) break;
    }

    for(int i = 0; i+1 < evens.size(); i+=2){
        if(cnt == n/2-1) break;
        cout << evens[i] << ' ' << evens[i+1] << endl;
        cnt++;
        if(cnt == n/2-1) break;
    }
//    cout << "--------\n";
}

int main() {
    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}


/*




 */



