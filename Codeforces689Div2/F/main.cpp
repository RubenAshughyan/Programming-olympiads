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

int DEBUG = 1;

using namespace std;

int n;
vc<int> v;

void doit(char c){
    loop(i,n){
        cout << v[i];
        if(i!= n-1) cout << c;
    }
    cout << endl;
}


bool eq(string a, string b){
    sort(all(a));
    sort(all(b));
    return a == b;
}


int main() {
    cin >> n;
    v.resize(n);
    loop(i,n) scanf("%d",&v[i]);

    string s;
    cin >> s;

    if(s.length() == 1){
        doit(s[0]);
        return 0;
    }

    if(eq(s, "+-")){
        doit('+');
        return 0;
    }

    if(eq(s, "*-")){
        doit('+');
        return 0;
    }

    if(eq(s, "*+")){
        cout << v[0];
        for(int i = 1; i < n; i++){
            int a = v[i-1];
            int b = v[i];

            char ch;

            if(a == 0 || b == 0){
                ch = '+';
            }
            else {
                // none is 0

                if(a == 1 || b == 1){
                    ch = '+';
                } else {
                    ch = '*';
                }
            }
            cout << ch <<v[i];

        }
        cout << endl;
        return 0;
    }



    return 0;
}


/*

 1
 5 5
1 2 3 4 5
1
8
9
12
6


 1
 5 5
3 1 3 1 3
1
2
3
9
11

2
5 5
1 2 3 4 5
1
8
9
12
6
5 5
3 1 3 1 3
1
2
3
9
11


 */



