
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

const int N = 500 + 10;
const int C = 10000 + 10;

int dp[N][C];
int n, c;

vc<pair<pii,int>> v;

int prev_i[N][C];
int prev_j[N][C];

int down[N];
int maint[N];

///////
bool cmp(pair<pii,int> a, pair<pii,int> b){
    if(a.first.first != b.first.first){
        return a.first.second - a.first.first < b.first.second - b.first.first;
    }
    return a.first.second < b.first.second;
}

int main() {
    loop(i,N){
        loop(j,N){
            prev_i[i][j] = -1;
            prev_j[i][j] = -1;
        }
    }

    cin >> n >> c;

    loop(i, n) {
        pii p;
        cin >> p.first >> p.second;

        v.push_back(make_pair(p,i));
    }

    // sort
    for(int i = 0; i < n; i++){
        for(int j = 0; j + 1 < n; j++){
            if(!cmp(v[j], v[j+1])){
                swap(v[j], v[j+1]);
            }
        }
    }
//    reverse(all(v));
    loop(i,n){
        down[i] = v[i].first.first;
        maint[i] = v[i].first.second;
    }

    // first
    for (int j = 0; j <= c; j++) {
        if (down[0] <= c && maint[0] <= j) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }


    //dp
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            prev_i[i][j] = i-1;
            prev_j[i][j] = j;

            if (j - 1 >= 0){
                if(dp[i][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i][j - 1];
                    prev_i[i][j] = i;
                    prev_j[i][j] = j-1;
                }
            }

            //
            int id = min(c - down[i], min(j - maint[i], c - maint[i]));
            if (id >= 0) {
                if (dp[i][j] < 1 + dp[i - 1][id]) {
                    dp[i][j] = 1 + dp[i - 1][id];
                    prev_i[i][j] = i-1;
                    prev_j[i][j] = id;
                }
            }

        }
    }

//    loop(i,n){
//        loop(j,c+1){
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    cout << "Prev" << endl;
//    loop(i,n){
//        loop(j,c+1){
//            printf("[%d %d] ", prev_i[i][j], prev_j[i][j]);
//        }
//        cout << endl;
//    }
//

    int i = n-1;
    int j = c;

    vc<int> ans;
    while(dp[i][j] != 0){
        if(prev_i[i][j] == -1 || dp[i][j] != dp[prev_i[i][j]][prev_j[i][j]]){
            ans.push_back(i);
        }

        pii p = {prev_i[i][j], prev_j[i][j]};
        i = p.first;
        j = p.second;
        if(i == -1) break;
//        db(i);
//        db(j);
    }

    reverse(all(ans));


    cout << dp[n - 1][c] << endl;

    for(int e : ans){
        cout << v[e].second + 1<< ' ';
    }
    return 0;

}
/*
2 100
99 1
1 99


2 100
500 1
1 500


6 4
2 1



*/