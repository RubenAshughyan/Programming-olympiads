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

int n,m,k;
vc<int> g[N];
vc<int> gR[N];
vc<int> p;
int d[N];

int main() {
    cin >> n >> m;
    loop(i,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].PB(v);
        gR[v].PB(u);
    }

    cin >> k;
    loop(i,k){
        int v;
        scanf("%d",&v);
        v--;
        p.PB(v);
    }



    int start = p.back();

    queue<int> q;
    loop(i,n) d[i] = -1;
    q.push(start);
    d[start] = 0;

    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int to : gR[from]){
            if(d[to] == -1){
                d[to] = d[from]+1;
                q.push(to);
            }
        }
    }
//
//    loop(i,n) {
//        cout << d[i] << ' ';
//    }
//    cout << endl;


    int sure =0 ;
    int maybe = 0;

    for(int i = 0; i+1 < k; i++){
        int u = p[i];
        int v = p[i+1];

        if(d[v] != d[u]-1) {
            sure++;
            continue;
        }

        //other
        bool otherIs = false;
        for(int other: g[u]){
            if(other != v)
                if(d[other] == d[u]-1) {
                    otherIs = true;
                }
        }

        if(otherIs) maybe++;

    }

    cout << sure << ' ' << sure + maybe << endl;



    return 0;
}


/*

5
3 7 9 7 8
5 2 5 7 5

 5
1 1 1 1 1
1 1 1 1 1



 */



