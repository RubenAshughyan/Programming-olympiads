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


const int N = 1000+7;
const int MOD = 1000*1000*1000 + 7;

int n;

int a[N];
int b[N];
int sa[N]; // one
int sb[N]; // zero

void solve(int z, int o){
    int i = 1, j = 1;
    while (i * 2 < n + 3 &&  j * 2 < n + 3){
        if (i<j){
            i=j;
            continue;
        }
        if (sa[i] - sa[j - 1] >= o && sa[i] - sa[j] <= o && sb[i+1] - sb[j] >= z && sb[i] - sb[j] <= z){
            cout<<"1";
            return;
        }
        if (sa[i] - sa[j - 1] < o){
            i++;
            continue;
        }
        if (sa[i] - sa[j] > o){
            j++;
            continue;
        }
        if (sb[i+1] - sb[j] < z){
            i++;
            continue;
        }
        if (sb[i] - sb[j] > z){
            j++;
            continue;
        }
    }
    i = 1, j = 1;
    while (i * 2 < n + 3 &&  j * 2 < n + 3){
        if (i<j){
            i=j;
            continue;
        }
        if (sa[i+1] - sa[j] >= o && sa[i+1] - sa[j+1] <= o && sb[i] - sb[j-1] >= z && sb[i-1] - sb[j-1] <= z){
            cout<<"1";
            return;
        }
        if (sa[i+1] - sa[j] < o){
            i++;
            continue;
        }
        if (sa[i+1] - sa[j+1] > o){
            j++;
            continue;
        }
        if (sb[i] - sb[j-1] < z){
            i++;
            continue;
        }
        if (sb[i-1] - sb[j-1] > z){
            j++;
            continue;
        }
    }
    cout<<"0";
}
void test(){
    for (int i = 0; i < N; ++i) {
        a[i] = 0;
        b[i] = 0;
        sa[i] = 0;
        sb[i] = 0;
    }
    int m;
    cin >> n >> m;
    for (int j = 0; j < n; ++j) {
        if (j & 1)
            cin >> a[j>>1];
        else
            cin >> b[j>>1];
    }
    for (int i = 0; i < (n+1)/2; ++i) {
        sa[i+1] = sa[i] + a[i];
        sb[i+1] = sb[i] + b[i];
    }


    for (int k = 0; k < m; ++k) {
        int z, o;
        cin >> z >> o;
        solve(z, o);
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    loop(i,t){
        test();
    }

    return 0;
}

/*
3
2 3
3 4
3 0
3 4
1 2
3 4
1 2 3
5 1
4 2
1 3
3 2
12 10
2 1 1 2 3 4 1 4 1 1 2 7
2 1
2 2
2 3
2 4
2 5
4 1
4 2
4 3
4 4
4 5

 */