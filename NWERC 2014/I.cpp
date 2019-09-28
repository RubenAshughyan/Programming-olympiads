
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

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int N = 14;

const ll MOD = 10000000007;
ll n, L;

ll d[N][N];

map<int,set<int>> can[N][N];


void f(vc<int> &perm, int msk){
    msk = ~msk;
    msk &= ((1 << n) - 1);

    ll first7 = 0;
    loop(i, 6-1) {
        first7 += d[perm[i]][perm[i + 1]];
    }

    ll need = 0;
    loop(s, 6) {
        loop(e, 6) {
            if (s == e) continue;

            need = L - (first7 + d[perm[5]][s] + d[e][perm[0]]);

            if (need >= 0 && can[s][e][msk].count(need%MOD)) {
                cout << "possible" << endl;
                exit(0);
            }
        }
    }
}

int getOnes(int x) {
    int res = 0;
    loop(i, 32) {
        res += ((x >> i) & 1);
    }
    return res;
}


int main() {

    cin >> n >> L;
    loop(i, n) loop(j, n) cin >> d[i][j];

//    n = 11;
//    L = 22;
//    loop(i,n){
//        loop(j,n){
//            d[i][j] = 1;
//        }
//    }
//    loop(i,n) d[i][i] = 0;

    if (n <= 10) {
        vc<int> p;
        loop(i, n) p.push_back(i);
        do {
            ll curL = 0;
            loop(i, n) {
                curL += d[p[i]][p[(i + 1) % n]];
            }

            if (curL == L) {
                cout << "possible" << endl;
                exit(0);
            }

        } while (next_permutation(all(p)));

        cout << "impossible" << endl;
        exit(0);
    }

    ////////////////////////////////////////////////////

    // generate all n-7 subsets
    for (int msk = 0; msk < (1 << n); msk++) {
        int ones = getOnes(msk);

        if (ones != n-8) continue;

        vc<int> subset;
        loop(i, n) {
            if ((msk >> i) & 1) {
                subset.push_back(i);
            }
        }

//        db(msk);

//        dbCont(subset);
        do {
            int curLen = 0;
            loop(j, (int)subset.size() - 1) {
                curLen += d[subset[j]][subset[j + 1]];
            }
            can[subset.front()][subset.back()][msk].insert(curLen % MOD);
        } while (next_permutation(all(subset)));
//        cout << "done" << endl;
    }


//    cout << "generate" << endl;

    for (int msk = 0; msk < (1 << n); msk++) {
        int ones = getOnes(msk);
        if (msk&1==0)
            continue;
        if (ones != 8) continue;

        vc<int> subset;
        loop(i, n) {
            if ((msk >> i) & 1) {
                subset.push_back(i);
            }
        }

//        db(msk);

//        dbCont(subset);
        do {
            if(subset.front() != 0) break;

            f(subset, msk);
        } while (next_permutation(all(subset)));
//        cout << "done" << endl;
    }

    cout << "impossible";


    return 0;
}
/*
2 2
0 1
1 0


4 10
0 3 2 1
3 0 1 3
2 1 0 2
1 3 2 0


 3 5
0 1 2
1 0 3
2 3 0



 */