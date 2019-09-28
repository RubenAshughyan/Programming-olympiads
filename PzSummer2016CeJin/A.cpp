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


const int N = 1000*1000+7;

int n,m;
vc<int> a;
vc<int> b;



bool test(){
    a.clear();
    b.clear();

    cin >> n >> m;
    loop(i,n){
        int e;
        cin >> e;
        a.push_back(e);
    }
    loop(i,n){
        int e;
        cin >> e;
        b.push_back(e);
    }


//    dbCont(multiset<int>(all(a)));
//    dbCont(multiset<int>(all(b)));
    if(multiset<int>(all(a)) != multiset<int>(all(b))) {
        loop(i,m) {
            int e;
            cin >> e >> e;
        }
        return false;
    }

    map<int,vc<int>> mp;
    loop(i,n){
        mp[b[i]].push_back(i);
    }
    for(auto &p: mp){
        reverse(all(p.second));
    }

    vc<int> c;
    loop(i,n){
        c.push_back(mp[a[i]].back());
        mp[a[i]].pop_back();
    }


    // c
    loop(i,m){
        int l,r;
        cin >> l >> r;
        l--,r--;

        sort(c.begin()+l, c.begin()+r+1);
    }


    bool ok = true;
    loop(i,n){
        ok &= c[i] == i;
    }
    return ok;
}

int main() {
//        freopen("in.txt","r",stdin);


    int t;
    cin >> t;
    loop(i,t) cout << (test() ? "Yes" : "No") << endl;
    return 0;
}
