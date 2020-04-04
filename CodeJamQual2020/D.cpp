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

int SIMUL = 0;
int n;
vc<int> s;

int asked = 0;
int get(int i) {
    asked++;



    if(SIMUL) {
        // change
        if(asked > 1 && asked % 10 == 1) {
            int r = rand() % 4;
            if (r == 0) {
                loop(i, n) s[i] ^= 1;
            } else if (r == 1) {
                cout << "rev" << endl;
                reverse(all(s));
            } else if (r == 2) {
                loop(i, n) s[i] ^= 1;
                reverse(all(s));
            }
        }

        cout << "get " << i << endl;
        return s[i];
    } else {
        cout << i + 1 << endl;
        fflush(stdout);
        int val;
        cin >> val;
        return val;
    }
}

void say(vc<int> v){


    assert(asked <= 150);
    for(int e: v) cout << e;
    cout << endl;



    if(SIMUL){
        db(asked);
        if(v == s) {
            cout << "lava ziz halala!" << endl;
        } else {
            cout << "hop!" << endl;
            dbCont(v);
            dbCont(s);
            exit(0);
        }
    } else {
        string res;
        cin >> res;
        assert(res == "Y");
    }
}

int f(int i) {
    return n - i - 1;
}

void test() {
    if(SIMUL) {
        s.resize(n);
        loop(i, n)s[i] = rand() % 2;
    } else {

    }
    dbCont(s);

    asked = 0;
    vc<int> x(n/2, -1);
    vc<int> y(n/2, -1);
    vc<int> indices[2];

    vc<int> first(2, -1);
    loop(i, 5) {
        int a = get(i);
        int b = get(f(i));
        x[i] = a;
        y[i] = b;
        indices[a ^ b].PB(i);
        if (first[a ^ b] == -1) first[a ^ b] = i;
    }

    for (int i = 5; i < n/2; i++) {
        int j = min(i + 4 - 1, n / 2 - 1);
        db(i);
        db(j);
        vc<int> changed(2, -1);
        loop(d, 2) {
            if (first[d] != -1) {
                changed[d] = get(first[d]) ^ x[first[d]];
            } else {
                get(0);
            }
        }

        dbCont(changed);
        dbCont(s);
        for (int k = i; k <= j; k++) {
            int a = get(k);
            int b = get(f(k));
            db(a);
            db(b);
            int X = a^b;

            if (changed[a ^ b] != -1) {
                a ^= changed[X];
                b ^= changed[X];
            }

            x[k] = a;
            y[k] = b;
            indices[a^b].PB(k);
            if (first[a ^ b] == -1) first[a ^ b] = k;
        }

        i = j;
    }

    if(SIMUL){
        dbCont(indices[0]);
        dbCont(indices[1]);
        dbCont(x);
        dbCont(y);
    }

    while(asked % 10 != 0) get(0);

    vc<int> changed(2, 0);
    loop(d,2){
        if(first[d] != -1) {
            changed[d] = get(first[d])^x[first[d]];
        }
    }

    if(SIMUL) {
        dbCont(changed);
    }
//    changed[0] = changed[1] = 1;

    vc<int> ans(n, -1);
    loop(d,2) {
        for (int i: indices[d]) {
            ans[i] = x[i] ^ changed[d];
            ans[f(i)] = y[i] ^ changed[d];
        }
    }

    say(ans);
}


int main() {
    int t;
    if(SIMUL) {
        t = 1000; n = 100;
    } else {
        cin >> t >> n;
    }
    loop(i, t) test();


    return 0;
}


/*



 */



