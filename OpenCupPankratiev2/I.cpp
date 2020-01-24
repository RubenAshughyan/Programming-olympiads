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

string s, t;

int main(){
    cin >> t >> s;

    int par = 0, j = 0;
    for(int i = 0; i < s.size(); i++) {
        if (j == t.size())
            break;
//        db(s[i]);
//        db(t[j]);

        if (s[i] == t[j] && par == i % 2) {
            par ^= 1;
            j++;
        }
    }
    if (j == t.size() && (s.size() - t.size()) % 2 == 0) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
/*
2
2147483649 1
*/