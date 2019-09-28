
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

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

ll n, m;
const ll N = 100*1000 * 5 + 5555;
ll memo[N];

vc<pair<ll,char>> parents[N];
char state[N];

ll f(ll v){
    if(memo[v] != -1) return memo[v];

    // base
    if(parents[v].empty()){
        return v != 1 ? 0 : n;
    }

    ll ans = 0;
    for(auto p: parents[v]){
        ll par = p.first;

        char dir = p.second;

        ans += f(par)/2;
        if(f(par) % 2 == 1 && dir == state[par]){
            ans ++;
        }
    }
    return memo[v] = ans;
}

char change(char c){
    if(c == 'L') return 'R';
    if(c == 'R') return 'L';
    assert(false);
}

int main() {
    loop(i,N) memo[i] = -1;

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;

        int l,r;
        cin >> l >> r;
        char c = s.front();

        state[i] = c;
        if (l)
            parents[l].push_back({i, 'L'});
        if (r)
            parents[r].push_back({i, 'R'});
    }

    for(int i = 1; i <= m; i++){
//        db(f(i));
    }

    for(int i = 1; i <= m; i++){
        char ans = state[i];

        if(f(i) & 1){
            ans = change(ans);
        }
        cout << ans;
    }
    cout << endl;

    return 0;
}
/*

 5 3
L 2 3
R 0 3
L 0 0

 */