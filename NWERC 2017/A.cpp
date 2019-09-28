
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

vector<int> v;
vector<int> s;

int n;

int main(){
    cin >> n;

    v.resize(n);
    s.resize(n);
    loop(i,n){
        int e;
        cin >> e;
        v[i] = e;
        s[i] = e;
    }

    sort(all(s));

    set<int> q;
    q.insert(s[0]);
    for (int k = 1; k < n; ++k) {
        if (s[k] == s[k-1])
            continue;
        q.insert(s[k]);
    }
    map<int, int> m;
    for (int j = 0; j < n; ++j) {
        m[s[j]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        q.lower_bound(v[i])
    }
    return 0;
}