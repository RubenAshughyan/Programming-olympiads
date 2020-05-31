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


const int N = 200 * 1000 + 5;

int DEBUG = 1;

using namespace std;

int n,m;
vc<int> g[2][N];

int color[N];
bool dfsCycle(int v, int gi){
//    db(v);
    if(color[v] == 1)
        return true;
    color[v] = 1;
    for(int to : g[gi][v]){
        if(color[to] != 2){
            if(dfsCycle(to, gi)){
                return true;
            }
        }
    }
    color[v] = 2;
    return false;
}

int used[2][N];
void taracvi(int v, int gi){
    if(used[gi][v]) return;
    used[gi][v] = 1;
    for(int to: g[gi][v]) {
        taracvi(to, gi);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    loop(i,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[0][v].PB(u);
        g[1][u].PB(v);
    }


    loop(i,n){
        if(color[i] == 0 && dfsCycle(i,0)){
            cout << -1 << endl;
            return 0;
        }
    }

    string s = "";
int A = 0;
    loop(v,n){
        if(used[0][v] || used[1][v]){
            s.PB('E');
        } else {
            s.PB('A');
            A++;
        }

        taracvi(v, 0);
        taracvi(v, 1);
    }

    cout <<  A << endl;
    cout << s << endl;

    return 0;
}


/*

 */



