#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>
//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define pb push_back
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
#define db(x) if(DEBUG){cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

const int DEBUG = 1;

using namespace std;

const int N = 3 * 1000 * 1000 + 6;



void test(){
    ll x,y;
    cin >> x >> y;

    if(y == 0){
        cout << "Yes" << endl;
        return;
    }

    while( y%2 == 0) y/=2;

//    db(x);
//    db(y);

    string ys = "";
    bool flag = false;
    for(int i = 31; i >= 0; i--){
        if(flag){
            ys.push_back( ((y>>i)&1) + '0');
        } else if( ((y>>i)&1) ) {
            flag = true;
            ys.push_back( ((y>>i)&1) + '0');
        }
    }
//    db(x);
//    db(y);


    string xs = "";
    for(int i = 31; i >= 0; i--){
        xs.push_back( ((x>>i)&1) + '0');
    }

//    db(xs);
//    db(ys);

    if(xs.find(ys) != string::npos){
        cout << "Yes" << endl;
    }     else {
        cout << "No" << endl;
    }

}

int main(){
    int t;
    cin >> t;
    loop(i,t) test();
    return 0;
}
/*
2
2147483649 1
*/