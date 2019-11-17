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
#define l first
#define r second

//#define ld long double
#define dbl long double
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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

const int DEBUG = 1;

int n,m;

vc<pii> shorer;
set<int> shpilkeq;
set<int> taza;

int get(pii shor){
    int res = 0;
    for(int shp: shpilkeq){
        if(shor.l <= shp && shp <= shor.r){
            res++;
        }
    }
    return res;
}

int main() {

    cin >> n;
    loop(i,n){
        int l,r;
        cin >> l >> r;
        shorer.push_back({l,r});
    }
    cin >> m;
    loop(i,m){
        int shp;
        cin >> shp;
        shpilkeq.insert(shp);
    }

    loop(si, n){
    pii shor = shorer[si];
        int qani_hat_uni = get(shor);
        if(qani_hat_uni >= 3){
            cout << "impossible" << endl;
            return 0;
        }

        //petka lracnel
        bool can_start_end = true;
        if(shpilkeq.count(shor.r)) can_start_end = false;
        else {
            shpilkeq.insert(shor.r);
            if(si+1 < n && get(shorer[si+1]) >= 3){
                can_start_end = false;
            }
            shpilkeq.erase(shor.r);
        }

        int endd = shor.r;
        if(!can_start_end) endd--;

        int need_to_put = 2 - qani_hat_uni;
        if(need_to_put) {
            for (int i = endd; i >= shor.l; i--) {
                // i-um chka
                if (!shpilkeq.count(i)) {
                    shpilkeq.insert(i);
                    taza.insert(i);
                    need_to_put--;
                    if (need_to_put == 0) break;
                }
            }
        }
    }

    cout << taza.size() << endl;
    for(int  e : taza){
        cout << e << ' ';
    }
    cout << endl;


    return 0;
}

/*
1
0 15
0

2
0 15
15 26
1
15

2
0 15
15 26
1
26


3
0 15
15 26
26 36
3
5 10 28

1
1 11
12
3 15 17 19 22 25 27 29 31 32 41 45


 7
1 10
10 20
 20 30
 31 40
 40 50
 50 60
 60 70
0
1 70
 */