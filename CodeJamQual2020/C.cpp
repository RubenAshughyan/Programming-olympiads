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

int n;
int l[N];
int r[N];
int col[N];

bool inter(int i, int j){
    bool free = l[i] >= r[j] || l[j] >= r[i];
    return !free;
}

bool dfs(int v, int c){
    if(col[v] != -1){
        return col[v] == c;
    }
    col[v] = c;

    bool ok = true;
    loop(to, n){
        if(to != v && inter(v,to)){
            ok &= dfs(to, c^1);
            if(!ok) break;
        }
    }
    return ok;
}
void test(int TEST_NUM){

    cin >> n;

    loop(i,n){
        cin >> l[i] >> r[i];
        col[i] = -1;
    }

    bool ok = true;
    loop(i,n) {
        if(col[i] == -1) {
            ok &= dfs(i, 0);
        }
    }

    string res;
    if(!ok) {
        res = "IMPOSSIBLE";
    } else {
        string S = "CJ";
        loop(i, n) res.PB(S[col[i]]);
    }
    printf("Case #%d: %s\n",TEST_NUM, res.c_str());
}




int main() {
    int t;
    cin >> t;
    loop(i,t) test(i+1);



    return 0;
}


/*



 */



