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


const int N = 1000;

int DEBUG = 1;

using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}


int solve(int n) {

    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }
    if(n == 3){
        return 1;
    }


    if(n % 2 == 1) return 1;

    //
    int nn = n;
    int evenPart = 1;
    while(nn % 2 == 0){
        nn /= 2;
        evenPart *= 2;
    }
//    db(evenPart);
    // power of two
//    db(nn);
    if(nn == 1){
        return 0;
    }

    // 2,2
    if(evenPart >= 4){
        return 1;
    }


    // 2, odds
    return !isPrime(nn);
}

void test() {

    int n;
    cin >> n;

    string f[] = {"Ashishgup", "FastestFinger"};

    cout <<  f[1-solve(n)] << endl;
}


int wins[N];

int main() {

//    cout << solve(12);
//    exit(0);

//    wins[1] = 0;
//    wins[2] = 1;
//    for(int i = 3; i < N; i++){
//        if(!wins[i-1]) {
//            wins[i] = true;
//        } else {
//            wins[i] = false;
//            for(int d = 3; d <= i; d++){
//                if(i%d == 0 && d%2==1){
//                    if(!wins[i/d]){
//                        wins[i] = true;
//                        break;
//                    }
//                }
//            }
//        }
//    }

//    // check
//    for(int i = 1; i < N; i++){
//        if(solve(i) != wins[i]){
//            db(i);
//            cout << "HOP" << endl;
//            exit(0);
//        }
//    }


    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}


/*




 */



