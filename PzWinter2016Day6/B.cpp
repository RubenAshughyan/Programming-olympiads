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

int n,x;

set<int> L,R;

int main() {
    cin >> n >> x;

    loop(i,n){
        int X,  ty;
        cin >> X >> ty;
        // Left
        if(ty == 1){
            L.insert(X);
        } else {
            R.insert(X);
        }
    }
    R.insert(0);

//    dbCont(L);
//    dbCont(R);


    // left, right, left, right ...
    int ans = 0;
    int pos = x;
    while(1){
//        db(pos);

        // Left
        auto it = R.upper_bound(pos);
        it--;

        pos = *it;
//        db(pos);
        // menk chenq
        if(*it != 0){
            R.erase(it);
        } else {
            ans++;
        }

        // Right
        it = L.upper_bound(pos);

        // etuma anverj
        if(it == L.end()){
            // no generaor
            if(R.size() + L.size() == 1) {
                cout << ans << endl;
            }
                // alive generators
            else {
                cout << -1 << endl;
            }
            return 0;
        }
        // xpun het gali
        else {
            pos = *it;
            L.erase(it);
        }
    }

    return 0;
}

/*
2 3
1 1
2 1

 4 100
1 0
2 1
3 0
4 1

  6 100
1 0
 10 0
 20 0
30 1
40 0
50 1



 */