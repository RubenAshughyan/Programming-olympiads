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
//#define length first
//#define time second
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



int main() {
    int n,m;
    cin >> n >> m;

    string sn = to_string(n);

    for(int i = 0; i < sn.length(); i++){
        for(int j = i+1; j+1 < sn.length();  j++){
            string A = sn.substr(0,i+1);
            string B = sn.substr(i+1,(j-i));
            string C = sn.substr(j+1);


            if(stoi(A) + stoi(B) + stoi(C) == m){
                cout << A << '+' << B << '+' << C << endl;
            }
        }
    }



    return 0;
}


/*

12479 68

8845 97



 */



