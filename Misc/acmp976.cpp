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

const int N = 500 + 3;

map<pair<pii, pii >, int> memo;

vc<int> divs[N*N];

int solve(int n, int sum, int prod, int last) {
    pair<pii, pii > key = {{n,    sum},
                           {prod, last}};

//    db(n);
//    db(sum);
//    db(prod);
//    db(last);

    // base case
    if (n == 0) {
        if (sum == 0 && prod == 1) return 1;
        return 0;
    }

    if(abs(sum-prod) > N) return 0;


    if (memo.count(key)) {
        return memo[key];
    }

    int ans = 0;
    for (int cur: divs[prod]) {
        if (cur >= last) {
            if (sum - cur < 0) break;

            ans += solve(n - 1, sum - cur, prod / cur, cur);

        }
    }
    return memo[key] = ans;
}

int solve(int n) {

    int ans = 0;
    for (int sumProd = 1; sumProd < N * N; sumProd++) {
        ans += solve(n, sumProd, sumProd, 1);
    }
    return ans;
}

int main() {
    for (int i = 1; i < N * N; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divs[i].push_back(j);
                if (j * j != i)
                    divs[i].push_back(i / j);
            }
        }

        sort(all(divs[i]));
    }


    for(int n = 2; n <= 500; n++){
        cout << solve(n) << ',' << endl;
    }
    return 0;
}


// 1 1 1 1 1 1 1 2 2 3 4 5