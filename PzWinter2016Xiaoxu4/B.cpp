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
#define dbl long double
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


const int N = 2000+5;
const int M = N/64 + 1;

int n;

struct bits{
    ll a[M];

    bits(){
        loop(i,M) a[i] = 0;
    }

    int get(int i){
        return (a[i >> 6] >> (i & 63)) & 1;
    }

    void flip(int i){
        a[i >> 6] ^= (1ll << (i&63));
    }

    void set(int i, int val){
        if(get(i) != val){
            flip(i);
        }
    }

    // Todo optimize
    vc<int> ones(){
        vc<int> res;
        loop(i,M){
            if(a[i]){
                ll x = a[i];
                while(x){
                    ll t = x & -x;
                    int r = __builtin_ctzl(x);
                    res.push_back(i * 64 + r);
                    x ^= t;
                }
            }
        }
        return res;
    }

    void selfOr(bits &b){
        loop(i,M){
            a[i] |= b.a[i];
        }
    }

    void selfAndNot(bits &b){
        loop(i,M){
            a[i] &= ~b.a[i];
        }
    }
};

ll ans = 0;
bits g[N];

void bfs(int start){
    // db(start);

    bits q;
    bits used;

    q.set(start, 1);
    used.set(start, 1);

    int curDepth = 1;

    while(!q.ones().empty()){
 
        vc<int> froms = q.ones();
        // db(q.ones().size());
        // dbCont(froms);
        for(int from : froms){
            q.selfOr(g[from]);
            used.set(from, 1);
        }

        q.selfAndNot(used);

        ans += q.ones().size() * 1ll * curDepth * curDepth;

        curDepth++;
    }

    int explored = used.ones().size();

    ans += (n-explored) *1ll* n*n;
}

int main(){
    cin >> n;
    loop(i,n){
        string s;
        cin >> s;
        loop(j, n){
            if(s[j] == '1'){
                g[i].set(j, 1);
            }
        }
    }
    // n = 2000;
    // loop(i,n){
    //     loop(j,n){
    //         g[i].set(j, 1);
    //     }
    // }
    // loop(j,n){
    //     g[j].set(j, 0);
    // }


    loop(i,n){
        bfs(i);
    }

    cout << ans << endl;

    return 0;
}


/*
3
010
001
100

2
10
01

*/