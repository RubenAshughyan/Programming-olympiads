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


string S = "NESW";
int indexOf(char c){
    loop(i,4){
        if(S[i] == c) return i;
    }
    assert(false);
}

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

set<pii> used;
map<pair<pii, int>, pii> mp;


pii f(int i, int j, int d){
    int ti = i+di[d];
    int tj = j+dj[d];


    // Not used
    if(used.count({ti,tj}) == 0){
        return mp[MP(MP(i,j),d)] = {ti,tj};
    }

    pii nxt;

    if(mp.count(MP(MP(i,j),d)) ){
        nxt = mp[MP(MP(i,j),d)];
    } else {
        nxt = {ti,tj};
    }

    return mp[{{i,j},d}] = f(nxt.first, nxt.second, d);
}


int main() {
//    test(0);
//    exit(0);
    int t;
    cin >> t;
    loop(tt,t){
        test(tt+1);
    }

    return 0;
}