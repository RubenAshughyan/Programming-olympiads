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
#define x first
#define y second

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

void test(){
    set<int> ms;
    int h,n;
    cin >> h >> n;
    loop(i,n){
        int e;
        cin >> e;
        ms.insert(e);
    }

    ms.insert(0);


    int ans = 0;
    int cur = h;
    while(cur != 0){
//        db(cur);
        set<int>::iterator nxt;
        int next;
        if(!ms.count(cur-1)){
            nxt = ms.lower_bound(cur);
            nxt--;
            next = *nxt+1;
        } else {
            next = max(cur-2,0);
            if(!ms.count(next)) {
                ms.insert(next);
                ans++;
            }
        }

        cur = next;
        cur = max(cur,0);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t){
        test();
    }
    return 0;
}