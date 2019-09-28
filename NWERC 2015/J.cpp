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
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
#define loop1(xxx, yyy) for(int xxx = 1; xxx <= yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
//#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

map<int,int> decode;

int main(){
    int n;
    cin >> n;


    for(int x = 0; x <= 255; x++) {
        int nx = x % 128;

        int key = x ^ (nx << 1);
        decode[key] = x;
    }
    loop(i,n){
        int e;
        cin >> e;
        cout << decode[e] << " ";
    }
    cout << endl;

    return 0;
}


/*
5
58 89 205 20 198
 */