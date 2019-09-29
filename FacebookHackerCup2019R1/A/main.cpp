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

const int N = 50+5;
const int M = 1000+5;
const ll INF = 1e16;


int n,m;
vc<ll> x,y,z;

ll d[N][N];

void test(int t){

    cin >> n >> m;

    x.resize(m);
    y.resize(m);
    z.resize(m);

    loop(i,n){
        loop(j,n){
            d[i][j] = INF;
        }
    }
    loop(i,m){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;

        d[x[i]][y[i]] = z[i];
        d[y[i]][x[i]] = z[i];
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(
                        d[i][j],
                        d[i][k] + d[k][j]
                        );
            }
        }
    }

    bool ok = true;
    loop(i,m){
        if(d[x[i]][y[i]] != INF) {
//            db(d[x[i]][y[i]] );
//            db(z[i]);
            ok &= d[x[i]][y[i]] == z[i];
        }
    }

    if(!ok){
        printf("Case #%d: Impossible\n",t);
    } else {
        printf("Case #%d: %d\n",t,m);
        loop(i,m) {
            printf("%d %d %d\n",x[i]+1, y[i]+1,z[i]);
        }
    }


//    printf("Case #%d: %c\n",t,ans);
}

int main() {
//    test(0);
//    exit(0);
freopen("/home/ruben/Downloads/graphs_as_a_service.txt","r",stdin);
freopen("answers.txt","w",stdout);
    int t;
    cin >> t;
    loop(tt,t){
        test(tt+1);
    }

    return 0;
}