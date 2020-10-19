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


deque<int> get() {
    int n;
    cin >> n;

    deque<int> d;
    loop(i, n) {
        int e;
        cin >> e;
        d.push_back(e);
    }
    return d;
}

int main() {
    srand(time(NULL));
    deque<int> d1 = get();
    deque<int> d2 = get();


    int step = 0;

    // xaxumenq
    while (true) {
        step++;

        cout << "---------------------------------\n";
        db(step);
        dbCont(d1);
        dbCont(d2);


        if (d1.empty()) {
            cout << "Second wins!!!";
            return 0;
        }
        if (d2.empty()) {
            cout << "First wins!!!";
            return 0;
        }

        int c1 = d1.front();
        d1.pop_front();
        int c2 = d2.front();
        d2.pop_front();

        if (c1 > c2 || (c1 == c2 && rand() % 2 == 0)) {
            if (rand() % 2) swap(c1, c2);
            d1.push_back(c1);
            d1.push_back(c2);
        } else {
            if (rand() % 2) swap(c1, c2);
            d2.push_back(c1);
            d2.push_back(c2);
        }

    }

    return 0;
}


/*


15
14 12 9 13 6 11 12 11 8 11 13 13 6 10 12
21
14 6 14 7 10 8 9 12 9 6 7 10 11 8 14 9 8 10 7 13 7



2
3 7
2
4 6
 */



