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

ll A1X, A1Y, A2X, A2Y;
ll B1X, B1Y, B2X, B2Y;

ll h,w;

bool check(ll AX, ll AY, ll BX, ll BY){
    ll A = BX-AX;
    ll B = BY-AY;

//    if(A > B) swap(A,B);

    return w <= A && h <= B;
}

int main() {
    cin >> A1X >> A1Y >> A2X >> A2Y;
    cin >> B1X >> B1Y >> B2X >> B2Y;
    cin >> w >> h;
//    if(h > w) swap(h,w);

//    db(check(A1X, B2Y, A2X, A2Y));
//    db(check(B2X, A1Y, A2X, A2Y));
//    db(check(A1X, A1Y, A2X, B1Y));
//    db(check(A1X, A1Y, B1X, A2Y));

    if (
            check(A1X, B2Y, A2X, A2Y) ||
            check(B2X, A1Y, A2X, A2Y) ||
            check(A1X, A1Y, A2X, B1Y) ||
            check(A1X, A1Y, B1X, A2Y)

            ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

        return 0;
}
/*
1 1 11 8
2 3 8 6
3 2

 1 1 11 8
2 3 8 6
4 3

*/