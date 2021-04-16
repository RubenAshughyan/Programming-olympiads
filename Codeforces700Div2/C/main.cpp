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
#define dbl long double
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

int n;
map<int,int> mp;
int f(int k){
    if(k == 0) return 1e9;
    if(k == n+1) return 1e9;

//    return n+1-k;


    if(mp.count(k)) return mp[k];

    cout << "? " << k << endl;
    fflush(stdout);

    int ans;
    cin >> ans;
    return mp[k] = ans;
}
void say(int x){
    cout << "! " << x << endl;
    exit(0);
}
int main() {

    cin >> n;

    int l = 1, r = n;

    while(l < r){
        int a1 = l + (r-l)/3;
        int a2 = r - (r-l)/3;

        if(f(a1-1) > f(a1) && f(a1) < f(a1+1))
            say(a1);
        if(f(a2-1) > f(a2) && f(a2) < f(a2+1))
            say(a2);

        bool d1 = f(a1-1) > f(a1);
        bool d2 = f(a2-1) > f(a2);

        if(d1 && d2){
            l = a2;
        } else if(d1 && !d2){
            l = a1;
            r = a2;
        } else if(!d1 && d2){
            r = a1;
        } else if(!d1 && !d2){
            r = a1;
        }
    }

    return 0;
}


/*


4
4 3
4 3 2 1
1 0.3
3 1
4 0.6
5 3
4 2 1 3 5
3 0.8
4 0.6
5 0.3
6 5
1 3 2 4 5 6
4 0.9
5 0.3
2 0.4
6 0.7
3 0.5
4 2
1 2 3 4
2 0.5
4 0.1

5 4 3 2 1
 */



