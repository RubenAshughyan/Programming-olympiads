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

int n, m;
set<int> g[N];
set<int> gR[N];
int indeg[N];

void dfsRandomPath(int v, vc<int> &path){
    path.push_back(v);

    vc<int> neight(all(g[v]));

    if(neight.empty()) return;

    int ind = rand()%(sz(neight));
    dfsRandomPath(neight[ind], path);
    return;
}

set<int> ans;
set<pll > st;

void jnji(int v){
    ans.insert(v);


    st.erase({indeg[v], v});
    // update childrens indeg
    for(int child: g[v]){
        st.erase({indeg[child], child});
        indeg[child]--;

        st.insert({indeg[child], child});
    }

    for(int verev: gR[v]){
        g[verev].erase(v);
    }
    g[v].clear();
}


void test() {


    scanf("%d%d", &n, &m);
    //clear
    loop(i, n) {
        g[i].clear();
        gR[i].clear();
    }


    loop(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if (g[u].count(v)) continue;

        indeg[v]++;

        g[u].insert(v);
        gR[v].insert(u);
    }


    // indeg, index
    st.clear();
    loop(v, n) {
        st.insert({indeg[v], v});
    }



    while(!st.empty()){
        int from = st.begin()->second;
        st.erase(st.begin());
        db(from+1);


        if(g[from].size() == 0) continue;
        if(g[from].size() == 1 && g[*g[from].begin()].size() == 0) continue;
        if(g[from].size() == 2 && g[*g[from].begin()].size() == 0 && g[*--g[from].end()].size() == 0) continue;


        vc<int> path;
        dfsRandomPath(from, path);

        if(path.size() <= 2) continue;

//        reverse(all(path));

        dbCont(path);

        // kent
        if(sz(path)%2 == 1){
            for(int i = 1; i < sz(path); i+=2){
                jnji(i);
            }
        } else {
            for(int i = 0; i < sz(path); i+=2){
                jnji(i);
            }
        }
    }



    printf("%d\n", sz(ans));
    for (int e : ans) {
        printf("%d ", e + 1);
    }
    printf("\n");

}

int main() {

    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}


/*
1
4 6
1 2
1 3
2 3
2 4
3 4
3 4

1
7 6
1 2
1 3
2 4
2 5
3 6
3 7


 1
 10 9
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 8
 8 9
 9 10


 1

 15 14
 1 12
 1 13
 12 4
 12 5
 13 6
 13 7
 4 8
 4 9
 5 10
 5 11
 6 2
 6 3
 7 14
 7 15

 */



