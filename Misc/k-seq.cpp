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

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;





    map<string, int> mp;

    // substrings
    int n = s.length() - k + 1;
    vc<string> v;
    for(int i = 0; i+k-1 < s.length(); i++){
        string t = s.substr(i,k);

        mp[t]++;
//        v.push_back(t);
    }

    n = 11111;
//    vc<string> v;
    vc<int> p;
    loop(i, s.length()) p.push_back(i);
    loop(iter, n) {
        random_shuffle(all(p));
        vc<int> poses;
        loop(j, k) {
            int i = p[j];
            poses.push_back(i);
        }
        sort(all(poses));
        string t = "";
        for (int i : poses) {
            t.push_back(s[i]);
        }
        mp[t]++;
//        v.push_back(t);
    }


//    dbCont(v);
    bool ok = false;
    for (auto pr: mp) {
        if (pr.second >= n*0.47) {
            ok = true;
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;


}