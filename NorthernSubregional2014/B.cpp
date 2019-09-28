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

const int N = 100*1000+5;

ll b,k, n, m;

pll a[N];
ll suffA[N];

pll c[N];
ll suffC[N];

int main(){
    cin >> b >> k >> n >> m;


    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    suffA[n] = a[n].first;
    for(int i = n - 1; i >= 1; i--){
        suffA[i] = suffA[i + 1] + a[i].first;
    }

    for(int i = 1; i <= m; i++){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + 1 + m);
    suffC[m] = c[m].first;
    for(int i = m - 1; i >= 1; i--){
        suffC[i] = suffC[i + 1] + c[i].first;
    }

    if(k >= m+n){
        cout << n << ' ' << m << endl;
        for(int i = 0; i < n; i++){
            cout <<i+1 << ' ';
        } cout << endl;
        for(int i = 0; i < m; i++){
            cout <<i+1 << ' ';
        } cout << endl;

        exit(0);
    }


        int k1,k2;
    ll best = 0;
    ll best_k1 = 0;
    ll best_k2 = 0;
    for(k1 = 0; k1 <= n; k1++){
        k2 = k-k1;
        if(min(k1,k2) < 0) continue;

        ll sumA = k1 > 0 ? suffA[n+1-k1] : 0;
        ll sumC = k2 > 0 ? suffC[m+1-k2] : 0;

        ll curAns = (b+sumA)*(100+sumC);
        if(curAns > best){
            best_k1 = k1;
            best_k2 = k2;
            best = curAns;
        }
    }

    cout << best_k1 << ' ' << best_k2 << endl;
    for(int i = n; i > n-best_k1; i--){
        cout << a[i].second << ' ';
    }
    cout << endl;
    for(int i = m; i > m-best_k2; i--){
        cout << c[i].second << ' ';
    }
    cout << endl;

    return 0;
}
/*
70 3 2 2
40 30
50 40

 1 2 3 4
6 6 5
8 10 7 9

*/