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
vc<int> g[N];

vc<int> col(22, 1);

vc<int> comb(vc<int> a, vc<int> b){
    for(int e: b){
        a.PB(e);
    }
    return a;
}

vc<int> f(int v){

    db(v);
    dbCont(g[v]);

    if(g[v].empty()) {
        db("empty");
        vc<int> emp;
        return emp;
    }

    int first_child = g[v][0];
    if(g[v].size() == 1){
        vc<int> ans;
        ans.PB(first_child);
        return comb(ans, f(first_child));
    }

    vc<int> res;
    if(g[v].size() >= 2) {
        g[v] = comb(g[first_child], g[v]);
        g[v].erase(find(all(g[v]), first_child));

        vc<int> cur = f(v);
        res = comb(res, cur);
        res.PB(g[v][0]);

        reverse(all(cur));
        res = comb(res, cur);
        return comb(res,f(v));
    }

}

int main() {
    cin >> n;
    loop(i,n-1){
        int v;
        cin >> v;
        g[v-1].PB(i+1);
    }



    vc<int> res = f(0);

    cout << res.size() << endl;
    for(int e : res){
        cout << e << ' ' ;
    }
    cout << endl;

    return 0;
}


/*


 4
1 1 1

 4
1 2 3

 6
1 1 2 2 2


 5
1 2 1 1


 5
1 1 2 3



 */



