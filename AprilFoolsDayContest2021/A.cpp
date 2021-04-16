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

int main() {

    int count = 0;

    for (int a1 = 0; a1 <= 2; a1++){
        for (int a2 = 0; a2 <= 2; a2++){
            for (int a3 = 0; a3 <= 2; a3++){
                if(a1+a2+a3 <= 6) {
                    cout << a1 << a2 << a3 << endl;
                }
//                for (int a4 = 0; a4 <= 3; a4++){
//                    for (int a5 = 0; a5 <= 3; a5++){
//                        if(a1 + a2 + a3 == a4 + a5){
//                            cout << a1 << a2 << a3 << a4 << a5 << endl;
//                            count++;
//                        }
//                    }
//                }
            }
        }
    }

//    cout << count << endl;

    return 0;
}


/*


a - 1 0 0 1 0

b - 1 0 0

c - 2 0 0 1 1
d - 2 1 0 1 2
e - 1 1 0 1 1
f - 2 1 0 2 1


o - 1 1 1 2 1


r - 1 2 1 3 1
z - 1 1 2 2 2

 */



