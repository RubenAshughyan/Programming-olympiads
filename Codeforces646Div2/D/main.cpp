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

int n, k;

vc<int> makeV(int l, int r) {
    vc<int> v;
    for (int i = l; i <= r; i++)
        v.PB(i);
    return v;
}

int ask(vc<int> subs){
    cout << "? " << subs.size() << ' ';
    for(int e : subs) cout << e << ' ';
    cout << endl;

    fflush(stdout);

    int resp;
    cin >> resp;
    return resp;
}


vc<int> comp(vc<int> v){

    set<int> st(all(v));

    vc<int> ans;
    for(int i = 1; i <= n; i++){
        if(!st.count(i)){
            ans.PB(i);
        }
    }

    return ans;
}

void test() {
    cin >> n >> k;

    vc<vc<int>> subsets(k);

    loop(i, k) {
        int s;
        cin >> s;

        vc<int> curS(s);
        loop(j, s) {
            cin >> curS[j];
        }
        sort(all(curS));

        subsets[i] = curS;
    }


    // all max
    vc<int> allIndexes = makeV(1, n);

    int M = ask(allIndexes);


    int l = 1, r = n;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        auto asked = makeV(1, mid);
        if (ask(asked) >= M) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }


    // a[l] = M
    // belongs somewhere
    int si = -1;
    loop(i, k) {
        // ka
        if (find(all(subsets[i]), l) != subsets[i].end()) {
            si = i;
        }
    }

    vc<int> ans(k);

    // chka, sax nuynna
    if (si == -1) {
        loop(i, k) ans[i] = M;
    } else {

        loop(i, k) {
            if (i != si) {
                ans[i] = M;
            }
        }

        ans[si] = ask(comp(subsets[si]));
    }


    // print
    cout << "! ";
    loop(i, k) cout << ans[i] << ' ';
    cout << endl;

    fflush(stdout);
    string resp;
    cin >> resp;
    assert(resp == "Correct");
}

int main() {
    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}


/*

 1
4 1
2 2 4

 */



