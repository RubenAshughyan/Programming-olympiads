#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;


const int N = 100 * 1000 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;



int n,m;
int c[N];
int cnt[2];
int other_neigh[2];
vc<int> g[N];

int main() {
    cin >> n >> m;
    loop(i,n){
        cin >> c[i];
        cnt[c[i]]++;
    }

    loop(i,m){
        int u,v;
        cin >> u >> v;
        u--,v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    loop(v,n){
        bool ok = false;
        for(int to: g[v]){
            if(c[to] != c[v]){
                ok = true;
            }
        }
        if(ok){
            other_neigh[c[v]]++;
        }
    }

    //calc
    loop(v,n){

//        db(v);

        int oc = 1-c[v];
//        db(other_neigh[oc]);

        bool has_other = false;
        for(int to: g[v]){
            if(c[to] != c[v]) has_other = true;
        }

        ll curAns =  cnt[c[v]]-1;
        if(has_other){
            curAns += cnt[1^c[v]]*2;
            for(int to : g[v]) if(c[to] != c[v]) curAns--;
        } else {
            curAns += other_neigh[oc]*2 + 3*(cnt[oc] -  other_neigh[oc]);
        }

        cout << curAns << ' ';
    }
    return 0;
}

/*
3 2
1 0 0
1 2
1 3


5 3
1 0 1 0 1
 1 2
2 3
4 5

 6 4
 1 1 1 1 0 0
 1 2
 2 3
 3 4
 4 5


 */