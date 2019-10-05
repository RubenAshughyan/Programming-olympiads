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


const int N = (1 << 16) + 5;

typedef bitset<N+1> BS;


int n;
vc<int> input[9];

vc<pii > a, b, c;

vc<BS> A, B, C;

ll solve(int I, int J, int K) {
//    loop(i, n) {
//        a[input[I][i]] = {input[J][i], input[I][i]};
//        b[input[I][i]] = {input[K][i], input[I][i]};
//    }

//    orig_a = a;
//    orig_b = b;


//    for(auto p:orig_a) cout << p.first << ' '; cout << endl;
//    for(auto p:orig_b) cout << p.first << ' '; cout << endl;

    A.clear();
    B.clear();
    C.clear();

    loop(i,n){
        a[i] = {input[I][i], i};
        b[i] = {input[J][i], i};
        c[i] = {input[K][i], i};
    }

    A.push_back(BS());
    B.push_back(BS());
    C.push_back(BS());


    sort(all(a));
    for (auto p: a) {
        int index = p.second;
        A.push_back(A.back());
        A.back()[index] = 1;
    }

    sort(all(b));
    for (auto p: b) {
        int index = p.second;
        B.push_back(B.back());
        B.back()[index] = 1;
    }

    sort(all(c));
    for (auto p: c) {
        int index = p.second;
        C.push_back(C.back());
        C.back()[index] = 1;
    }


    ll ans = 0;
    loop(j, n) {
        int add = (A[input[I][j]] & B[input[J][j]] & C[input[K][j]]).count();

        db(add);
        ans += add;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    loop(i, 9) {
        loop(j, n) {
            int e;
            scanf("%d", &e);
            e--;
            input[i].push_back(e);
        }
    }

    int I, J, K;
    ll bestAns = 1e17;


    solve(3-1,7-1,8-1);
    exit(0);


    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            for (int k = j + 1; k < 9; k++) {
                ll curAns = solve(i, j, k);

                cout << endl;
                printf("%d %d %d\n", i + 1, j + 1, k + 1);
                db(curAns);
                if (curAns < bestAns) {
                    bestAns = curAns;
                    I = i;
                    J = j;
                    K = k;
                }
            }
        }
    }

    printf("%d %d %d\n", I + 1, J + 1, K + 1);
    return 0;
}

/*

 7
1 2 3 4 5 6 7
1 2 4 5 3 7 6
1 3 2 5 7 6 4
1 2 3 4 5 7 6
1 2 3 4 5 6 7
2 1 3 4 5 6 7
7 1 2 3 4 5 6
5 4 1 3 6 7 2
1 2 4 5 3 6 7

7
1 3 2 5 7 6 4
7 1 2 3 4 5 6
5 4 1 3 6 7 2


 1 2
 1 3
 1 6
 3 6
 5 6

 */