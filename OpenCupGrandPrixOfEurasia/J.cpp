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

int n;

set<string> sax;
map<string,int> mp;

vc<set<string>> Gstring;
vc<vc<int>> G;

bool can(vc<int> &perm){
    int last = -1;

    auto g = G;

    for(int i : perm){
        auto it = lower_bound(all(g[i]), last);
        if(it == g[i].end()) return false;

        last = *it;
    }

    return true;

}

int main() {

    cin >> n;
    Gstring.resize(n);
    G.resize(n);

    loop(i,n){
        int k;
        cin >> k;
        loop(jj,k){
            string e;
            cin >> e;
            sax.insert(e);
            Gstring[i].insert(e);
        }
    }

    int GI = 0;
    for(string e :sax){
        mp[e] = GI++;
    }


    loop(i,n){
        for(string s: Gstring[i]){
            G[i].push_back(mp[s]);
        }
    }


    // check ran perms
    dbl startTime = clock();
    vc<int> perm;
    loop(i,n) perm.push_back(i);



    while(true){
        dbl passed = (clock()- startTime) / CLOCKS_PER_SEC;
        if(passed >= 5.94){
            cout << "YES" << endl;
            return 0;
        }


        random_shuffle(all(perm));
        if(!can(perm)){
            cout << "NO" << endl;
            for(int e: perm) cout << e+1 << ' ';
            cout << endl;
            return 0;
        }
    }

    return 0;
}
/*
3
1
teamname
2
vanechka
ivan
4
albatross
teddybear
vitalya
pythonists


 2
2
geometrylovers
epsiszero
1
speedcoderz
 */