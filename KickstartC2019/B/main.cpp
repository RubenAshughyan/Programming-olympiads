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

const int N = 300+50;

int a[N][N];
vc<int> mn;
vc<int> mx;
int n,m,k;


int f(){
    vc<int> b = mn;
    loop(i,mx.size()){
        if(mx[i] - mn[i] <= k){
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }

    int ans = 0;

    int cur = 0;

    for(int i =0 ; i < b.size(); i++){
        if(b[i] == 1){
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 0;
        }
    }
    return ans;
}

void test(int t){


    cin >> n >> m >> k;
    loop(i,n){
        loop(j,m){
            cin >> a[i][j];
        }
    }

    mn.resize(n);
    mx.resize(n);


    int ans = 0;
    for(int l = 0; l < m; l++){
        loop(i,n) mn[i] = a[i][l];
        loop(i,n) mx[i] = a[i][l];

        for(int r = l; r < m; r++){
            int len = r-l+1;
            loop(i,n){
                mn[i] = min(mn[i], a[i][r]);
                mx[i] = max(mx[i], a[i][r]);
            }

            ans = max(ans, f()*len);
        }
    }

    printf("Case #%d: %d\n",t, ans);
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