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

int main() {
    int n;
    cin >> n;

    int g = 0;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            cout << i << n/i << endl;
            return 0;
        }
        if(g == 2) break;
    }

    cout << endl;
    return 0;
}


/*
 * Here is the list
 * of the most important features
 * that you might heard of so I
 * would like to ask about the
 * single response variables that
 * can ever be considered for the
 * future generations in terms of
 * people's overall general lives.
 * Mostly I can't agree to the
 * desired behavior sp lets never
 * forget if in case of fire the
 * basements of buildings add a
 * slight discrepancy conserning
 * the unvaluable need to flush
 * midst the evenings flow never
 * asking why.
 */



