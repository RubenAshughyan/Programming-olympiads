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
#define db(x)if(DEBUG){ cout << #x << " = " << x << endl;}
#define dbCont(x) if(DEBUG) {cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;}

using namespace std;

ll DEBUG = 0;
const ll N = 500*1000 +123;
const ll MOD= 1000*1000*1000+7;

ll n,m;
vc<ll> g[N];
ll w[N];
ll par[N];
vc<char> used;

ll which_comp[N];
ll compValue[N];
ll ans[N];


// for articulation points
ll subtreeProd[N];
ll isCutpoint[N];
ll tin[N];
ll fup[N];
ll timer = 0;

ll dfs(ll v, ll c, ll p){
//    cout << "dfs  " << v+1 << endl;
    used[v] = 1;
    which_comp[v] = c;
    par[v] = p;

    ll prod = w[v];
    tin[v] = fup[v] = timer++;

    ll children = 0;
    for(ll to : g[v]){
        if(to == p) continue;

        if(used[to]){
            fup[v] = min(fup[v], tin[to]);
        } else {
            ll curProduct = dfs(to, c, v) % MOD;
            children++;
            (prod *= curProduct) %= MOD;
            fup[v] = min(fup[v], fup[to]);

            if(fup[to] >= tin[v] && p != -1){
                isCutpoint[v] = 1;
            }
        }
    }

    if(p == -1 && children >= 2){
        isCutpoint[v] = 1;
    }

    return subtreeProd[v] = prod;
}


ll bin_exp(ll base, ll exp){
    if(exp == 0) return 1;

    ll h = bin_exp(base, exp/2);

    h = (h*1ll*h)%MOD;
    if(exp & 1){
        h = (h*base)%MOD;
    }
    return h;
}

ll inv(ll x){
    return bin_exp(x, MOD-2);
}

void input(){
//    scanf("%lld%lld", &n, &m);
cin >> n >> m;

    // clear comtainers
    loop(i,n){
        g[i].clear();
        par[i] = 0;
        used.clear();

        which_comp[i] = 0;
        compValue[i] = 0;
        ans[i] = 0;
        subtreeProd[i] = 0;
        isCutpoint[i] = 0;
        tin[i] = 0;
        fup[i] = 0;
    }

    loop(i, n) cin >> w[i];
    loop(i, m) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

ll solve(bool fromInput=true) {
    if(fromInput) {

        input();
    }

    loop(i,n) {
        isCutpoint[i] = 0;
    }
    timer = 0;
    used.resize(n);
    loop(i, n) used[i] = 0;

    ll c = 0;

    ll total = 0;
    loop(v, n) {
        if (!used[v]) {

            db(v);
            ll curProduct = dfs(v, c, -1) % MOD;
            db(curProduct);
            (total += curProduct) %= MOD;
            compValue[c] = curProduct;

            c++;
        }
    }

    db(total);

    //debug cutpoints
    if(DEBUG) {
        cout << "cutPoints: ";
        loop(i, n) {
            if (isCutpoint[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    // calc ans
    db("calcans");
    for (ll v = 0; v < n; v++) {
        if(DEBUG) cout << endl;
        v++;db(v);v--;
        db(isCutpoint[v]);
        if (!isCutpoint[v]) {
            ll totalWithoutThisComp = total;

            totalWithoutThisComp += (MOD - compValue[which_comp[v]]);
            totalWithoutThisComp %= MOD;
            db(totalWithoutThisComp);


            ll curCompValue = compValue[which_comp[v]] * inv(w[v]);
            curCompValue %= MOD;
            if(g[v].empty()) curCompValue = 0;

            db(compValue[which_comp[v]]);
            db(w[v]);
            db(curCompValue);

            (totalWithoutThisComp += curCompValue) %= MOD;
            ans[v] = totalWithoutThisComp;
        } else {
            ll thisRemAnswer = total;
            thisRemAnswer += (MOD - compValue[which_comp[v]]);
            thisRemAnswer %= MOD;
            db(thisRemAnswer);

            for(ll to : g[v]){
                if(par[to] != v) continue;

                if(fup[to] >= tin[v]){
                    db(to+1);
                    thisRemAnswer += subtreeProd[to];
                    db(subtreeProd[to]);
                    thisRemAnswer %= MOD;
                }
            }


            if(par[v] != -1) {
                ll upper = compValue[which_comp[v]];
                (upper *= inv(w[v])) %= MOD;
                for(ll to : g[v]){
//                    if(to == par[v]) continue;
                    if(par[to] != v) continue;


                    if(fup[to] >= tin[v]) {
                        upper *= inv(subtreeProd[to]);
                        upper %= MOD;
                    }
                }

                db(upper);
                (thisRemAnswer += upper) %= MOD;
            }
            db(thisRemAnswer);

            ans[v] = thisRemAnswer;
        }


        db(ans[v]);
    }

    // debug
    if(DEBUG) {
        loop(i, n) {
            cout << i+1 << ' ' << ans[i] << endl;
        }
    }

    ll res = 0;
    loop(i,n){
        res += ans[i]*(i+1);
        res %= MOD;
    }
    return res;
}

set<pii> edges;

void generate(){
    n = rand()%100+2;
    m = rand()%  ( (n)*(n-1)/2 );
    loop(i,n) w[i] = rand()+1;

    edges.clear();
    loop(i,n) g[i].clear();

    while(edges.size() < m){
        ll u = rand()%n;
        ll v = rand()%n;
        if(u==v)continue;
        if(u > v) swap(u,v);
        edges.insert({u,v});
    }

    for(auto p: edges){
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
}

void dfs(ll v, ll rem, vc<ll> &used, ll &curProd){
    (curProd *= w[v]) %= MOD;
    used[v] = 1;
    for(ll to: g[v]){
        if(to != rem && !used[to]){
            dfs(to,rem,used, curProd);
        }
    }
}

ll brute(){

    vc<ll> ans(n);
    loop(rem, n){
        ll curSum = 0;

        vc<ll> used(n,0);
        loop(v,n){
            if(!used[v] && v != rem){
                ll curProd = 1;
                dfs(v, rem, used, curProd);
//                cout<< "curProduct " << curProd << endl;
                (curSum += curProd) %= MOD;
            }
        }
        ans[rem] = curSum;
    }
    ll res = 0;
    loop(i,n){
        res += ans[i]*(i+1);
        res %= MOD;
    }
    return res;
}

void print() {
    cout << n << ' ' << m << endl;
    loop(i, n) cout << w[i] << ' '; cout<< endl;
    for (auto p: edges) {
        cout << p.first+1 <<  ' ' << p.second+1 << endl;
    }
}

void stress(){
    loop(i,1000000){
        cout << i << "------------------------------------" << endl;
        generate();

        ll solveAns = solve(false);
        cout << "solveAns " << solveAns << endl;
        ll bruteAns = brute();
        cout << "bruteAns " << bruteAns << endl;

        if(solveAns != bruteAns){
            print();

            exit(0);
        } else {
            cout << "OK" << endl;
        }


    }

}

int main(){
    DEBUG = 0;

    stress();
    exit(0);


//    if(DEBUG) {
//        freopen("in.txt", "r", stdin);
//    }

    ll t;
    cin >> t;
    loop(i,t) {
        cout << solve() << endl;
    }
    return 0;
}

 /*
1
3 2
1 2 3
1 2
2 3


6+7+1*2*4*5
*/
