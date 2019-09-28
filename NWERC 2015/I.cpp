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


int main(){
    string s;
    cin >> s;
    ll x=0, y=0;
    cout<<s.length()<<" ";
    for (int i = 0; i < s.size(); ++i) {
        int z = s[i] - '0';
        x <<=1;
        y <<=1;
        if (z&1)
            x++;
        if (z&2)
            y++;

    }
    cout<<x<<" " << y<<endl;
    return 0;
}


/*
5
58 89 205 20 198
 */