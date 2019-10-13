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

const int N = 500+5;

int n,m;
int a[N][N];

void no(){
    cout << -1 << endl;
    exit(0);
}

int main() {
    cin >>  n >> m;
    loop(i,n){
        string s;
        cin >> s;
        loop(j,m){
            a[i][j] = s[j]- '0';
        }
    }

    if(n % 2 == 1 & m % 2 == 1 && a[n/2][m/2]!= 8)no();


    int ans = 0;
    loop(i,n){
        loop(j,m){
            int x = a[i][j];
            int y = a[n-i-1][m-j-1];


            if(x == 6){
                if(y == 6) ans++;
                if(y == 7) no();
                if(y == 8) no();
                if(y == 9) {}
            } else if(x == 7){
                if(y == 6) no();
                if(y == 7) ans++;
                if(y == 8) no();
                if(y == 9) no();
            } else if(x == 8){
                if(y == 6) no();
                if(y == 7) no();
                if(y == 8) {};
                if(y == 9) no();
            } else if(x == 9){
                if(y == 6) {};
                if(y == 7) no();
                if(y == 8) no();
                if(y == 9) ans++;
            }
        }
    }
    cout << ans/2 << endl;


    return 0;
}


/*
2 3
676
679

 3 3
888
888
888


 1 1
7



*/